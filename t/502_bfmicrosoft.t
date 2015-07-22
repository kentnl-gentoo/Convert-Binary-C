################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2005/05/23 15:31:21 +0100 $
# $Revision: 1 $
# $Source: /t/502_bfmicrosoft.t $
#
################################################################################
#
# Copyright (c) 2002-2005 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
#
################################################################################

use Test;
use Convert::Binary::C @ARGV;

$^W = 1;

BEGIN { plan tests => 9031 }

$BIN = $] < 5.006 ? '%x' : '%08b';

# TODO: only as long as we're implementing bitfields
$SIG{__WARN__} = sub { $_[0] =~ /Bitfields are unsupported/ or print STDERR $_[0] };

my @compiler = (
  {
    'name' => 'MSWin32/cl_pack01',
    'config' => {
      'Define' => [
        'PACK_PAREN=1'
      ],
      'LongSize' => 4,
      'IntSize' => 4,
      'ByteOrder' => 'LittleEndian',
      'ShortSize' => 2,
      'DoubleSize' => 8,
      'CharSize' => 1,
      'PointerSize' => 4,
      'EnumSize' => 4,
      'FloatSize' => 4,
      'Alignment' => 1,
      'LongLongSize' => 8,
      'LongDoubleSize' => 8,
      'HasCPPComments' => 1,
      'Bitfields' => {
        'Engine' => 'Microsoft'
      },
      'CompoundAlignment' => 1
    }
  },
  {
    'name' => 'MSWin32/cl_pack02',
    'config' => {
      'Define' => [
        'PACK_PAREN=1'
      ],
      'LongSize' => 4,
      'IntSize' => 4,
      'ByteOrder' => 'LittleEndian',
      'ShortSize' => 2,
      'DoubleSize' => 8,
      'CharSize' => 1,
      'PointerSize' => 4,
      'EnumSize' => 4,
      'FloatSize' => 4,
      'Alignment' => 2,
      'LongLongSize' => 8,
      'LongDoubleSize' => 8,
      'HasCPPComments' => 1,
      'Bitfields' => {
        'Engine' => 'Microsoft'
      },
      'CompoundAlignment' => 1
    }
  },
  {
    'name' => 'MSWin32/cl_pack04',
    'config' => {
      'Define' => [
        'PACK_PAREN=1'
      ],
      'LongSize' => 4,
      'IntSize' => 4,
      'ByteOrder' => 'LittleEndian',
      'ShortSize' => 2,
      'DoubleSize' => 8,
      'CharSize' => 1,
      'PointerSize' => 4,
      'EnumSize' => 4,
      'FloatSize' => 4,
      'Alignment' => 4,
      'LongLongSize' => 8,
      'LongDoubleSize' => 8,
      'HasCPPComments' => 1,
      'Bitfields' => {
        'Engine' => 'Microsoft'
      },
      'CompoundAlignment' => 1
    }
  },
  {
    'name' => 'MSWin32/cl_plain',
    'config' => {
      'Define' => [
        'PACK_PAREN=1'
      ],
      'LongSize' => 4,
      'IntSize' => 4,
      'ByteOrder' => 'LittleEndian',
      'ShortSize' => 2,
      'DoubleSize' => 8,
      'CharSize' => 1,
      'PointerSize' => 4,
      'EnumSize' => 4,
      'FloatSize' => 4,
      'Alignment' => 8,
      'LongLongSize' => 8,
      'LongDoubleSize' => 8,
      'HasCPPComments' => 1,
      'Bitfields' => {
        'Engine' => 'Microsoft'
      },
      'CompoundAlignment' => 1
    }
  }
);


my @c = eval { map { Convert::Binary::C->new(Bitfields => {Engine => 'Generic'},
                                             EnumType  => 'String',
                                             %{$_->{config}}) } @compiler };
ok($@, '', "failed to create Convert::Binary::C objects");

sub debug
{
  $ENV{CBC_TEST_DEBUG} or return;
  my $out = join '', @_;
  $out =~ s/[\r\n]+$//;
  $out =~ s/^/# /gm;
  print "$out\n";
}

sub showbits
{
  join ' ', map { sprintf $BIN, $_ } unpack "C*", shift;
}

sub get_data
{
  my $want = shift || 'list';
  my $term = shift || '[-=]';
  local $_;
  my @lines;
  while (<DATA>) {
    if (/^($term)$/) {
      $term = $1;
      last;
    }
    push @lines, $_
  }
  if ($want eq 'list') {
    chomp @lines;
    return $term, @lines;
  }
  return $term, join('', @lines);
}

sub reccmp
{
  my($ref, $val) = @_;

  unless (defined $ref and defined $val) {
    return defined($ref) == defined($val);
  }

  ref $ref or return $ref eq $val;

  if (ref $ref eq 'ARRAY') {
    @$ref == @$val or return 0;
    for (0..$#$ref) {
      reccmp($ref->[$_], $val->[$_]) or return 0;
    }
  }
  elsif (ref $ref eq 'HASH') {
    @{[keys %$ref]} == @{[keys %$val]} or return 0;
    for (keys %$ref) {
      reccmp($ref->{$_}, $val->{$_}) or return 0;
    }
  }
  else { return 0 }

  return 1;
}

while (1) {
  my(undef, $code) = get_data('block');
  last if $code !~ /\S/;
  debug("Code:\n$code");
  eval { $_->clean->parse($code) for @c };
  ok($@, '', "failed to parse code:\n$code\n");
  ok(scalar $c[0]->compound_names, 1);
  my($type) = $c[0]->compound_names;
  while (1) {
    my($term, $init, @packed) = get_data;
    debug("Init: $init");
    my $data = eval $init;
    my $succ = 0;
    for (@packed) { $_ = pack "H*", $_ }
    for my $i (0 .. $#packed) {
      debug("Compiler: [$i] $compiler[$i]{name}");
      $c[$i]->sizeof($type) == length($packed[$i]) and $succ++;

      my $p = $c[$i]->pack($type, $data);
      if ($p eq $packed[$i]) {
        $succ++;
      }
      else {
        my $ccc = $code;
        $ccc =~ s/^/# /mg;
        print "# [$i] $compiler[$i]{name}\n$ccc# data = $init\n";
        printf "# expected: %s\n", showbits($packed[$i]);
        printf "#      got: %s\n", showbits($p);
      }

      my $u = $c[$i]->unpack($type, $packed[$i]);
      if (reccmp($data, $u)) {
        $succ++;
      }
      else {
        my $ccc = $code;
        $ccc =~ s/^/# /mg;
        print "# [$i] $compiler[$i]{name}\n$ccc# data = $init\n";
        eval { require Data::Dumper };
        unless ($@) {
          my $dd = Data::Dumper->Dump([$data, $u], [qw(*expected *got)]);
          $dd =~ s/^/# /mg;
          print $dd;
        }
      }
    }
    ok($succ, 3*@packed);
    last if $term eq '=';
  }
}

__DATA__
struct basic {
  unsigned int a:9;
};
-
{a=>509}
fd010000
fd010000
fd010000
fd010000
-
{a=>352}
60010000
60010000
60010000
60010000
-
{a=>349}
5d010000
5d010000
5d010000
5d010000
-
{a=>398}
8e010000
8e010000
8e010000
8e010000
-
{a=>453}
c5010000
c5010000
c5010000
c5010000
=
struct basic {
  unsigned int a:9;
  unsigned int b:2;
};
-
{a=>228,b=>3}
e4060000
e4060000
e4060000
e4060000
-
{a=>163,b=>0}
a3000000
a3000000
a3000000
a3000000
-
{a=>333,b=>3}
4d070000
4d070000
4d070000
4d070000
-
{a=>495,b=>3}
ef070000
ef070000
ef070000
ef070000
-
{a=>193,b=>3}
c1060000
c1060000
c1060000
c1060000
=
struct basic {
  unsigned int a:9;
  unsigned int b:2;
  unsigned int  :3;
};
-
{a=>115,b=>1}
73020000
73020000
73020000
73020000
-
{a=>283,b=>0}
1b010000
1b010000
1b010000
1b010000
-
{a=>12,b=>1}
0c020000
0c020000
0c020000
0c020000
-
{a=>417,b=>3}
a1070000
a1070000
a1070000
a1070000
-
{a=>129,b=>2}
81040000
81040000
81040000
81040000
=
struct basic {
  unsigned int a:9;
  unsigned int b:2;
  unsigned int  :3;
  unsigned int c:2;
};
-
{c=>1,a=>473,b=>1}
d9430000
d9430000
d9430000
d9430000
-
{c=>2,a=>149,b=>2}
95840000
95840000
95840000
95840000
-
{c=>3,a=>227,b=>2}
e3c40000
e3c40000
e3c40000
e3c40000
-
{c=>0,a=>114,b=>0}
72000000
72000000
72000000
72000000
-
{c=>2,a=>83,b=>3}
53860000
53860000
53860000
53860000
=
struct basic {
  unsigned int a:9;
  unsigned int b:2;
  unsigned int  :3;
  unsigned int c:2;
  unsigned int d;
};
-
{c=>0,a=>134,b=>3,d=>231}
86060000e7000000
86060000e7000000
86060000e7000000
86060000e7000000
-
{c=>0,a=>60,b=>0,d=>10}
3c0000000a000000
3c0000000a000000
3c0000000a000000
3c0000000a000000
-
{c=>2,a=>170,b=>2,d=>252}
aa840000fc000000
aa840000fc000000
aa840000fc000000
aa840000fc000000
-
{c=>3,a=>53,b=>1,d=>248}
35c20000f8000000
35c20000f8000000
35c20000f8000000
35c20000f8000000
-
{c=>3,a=>74,b=>3,d=>85}
4ac6000055000000
4ac6000055000000
4ac6000055000000
4ac6000055000000
=
struct basic {
  char a;
  unsigned int b:9;
};
-
{a=>95,b=>334}
5f4e010000
5f004e010000
5f0000004e010000
5f0000004e010000
-
{a=>43,b=>139}
2b8b000000
2b008b000000
2b0000008b000000
2b0000008b000000
-
{a=>103,b=>500}
67f4010000
6700f4010000
67000000f4010000
67000000f4010000
-
{a=>-82,b=>491}
aeeb010000
ae00eb010000
ae000000eb010000
ae000000eb010000
-
{a=>-81,b=>456}
afc8010000
af00c8010000
af000000c8010000
af000000c8010000
=
struct basic {
  char a;
  unsigned int b:9;
  unsigned int c:2;
};
-
{c=>1,a=>62,b=>455}
3ec7030000
3e00c7030000
3e000000c7030000
3e000000c7030000
-
{c=>0,a=>-46,b=>32}
d220000000
d20020000000
d200000020000000
d200000020000000
-
{c=>0,a=>55,b=>501}
37f5010000
3700f5010000
37000000f5010000
37000000f5010000
-
{c=>3,a=>72,b=>97}
4861060000
480061060000
4800000061060000
4800000061060000
-
{c=>3,a=>91,b=>180}
5bb4060000
5b00b4060000
5b000000b4060000
5b000000b4060000
=
struct basic {
  char a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
};
-
{c=>1,a=>-64,b=>1}
c001020000
c00001020000
c000000001020000
c000000001020000
-
{c=>3,a=>43,b=>409}
2b99070000
2b0099070000
2b00000099070000
2b00000099070000
-
{c=>1,a=>-30,b=>413}
e29d030000
e2009d030000
e20000009d030000
e20000009d030000
-
{c=>3,a=>107,b=>399}
6b8f070000
6b008f070000
6b0000008f070000
6b0000008f070000
-
{c=>2,a=>-59,b=>474}
c5da050000
c500da050000
c5000000da050000
c5000000da050000
=
struct basic {
  char a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
  unsigned int d:2;
};
-
{c=>0,a=>-60,b=>352,d=>2}
c460810000
c40060810000
c400000060810000
c400000060810000
-
{c=>1,a=>89,b=>103,d=>2}
5967820000
590067820000
5900000067820000
5900000067820000
-
{c=>0,a=>31,b=>136,d=>2}
1f88800000
1f0088800000
1f00000088800000
1f00000088800000
-
{c=>0,a=>-103,b=>343,d=>0}
9957010000
990057010000
9900000057010000
9900000057010000
-
{c=>2,a=>-102,b=>358,d=>0}
9a66050000
9a0066050000
9a00000066050000
9a00000066050000
=
struct basic {
  char a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
  unsigned int d:2;
  unsigned int e;
};
-
{e=>205,c=>0,a=>57,b=>85,d=>3}
3955c00000cd000000
390055c00000cd000000
3900000055c00000cd000000
3900000055c00000cd000000
-
{e=>218,c=>2,a=>-89,b=>129,d=>1}
a781440000da000000
a70081440000da000000
a700000081440000da000000
a700000081440000da000000
-
{e=>90,c=>3,a=>105,b=>77,d=>1}
694d4600005a000000
69004d4600005a000000
690000004d4600005a000000
690000004d4600005a000000
-
{e=>82,c=>3,a=>89,b=>507,d=>0}
59fb07000052000000
5900fb07000052000000
59000000fb07000052000000
59000000fb07000052000000
-
{e=>10,c=>1,a=>-7,b=>126,d=>0}
f97e0200000a000000
f9007e0200000a000000
f90000007e0200000a000000
f90000007e0200000a000000
=
struct basic {
  short a;
  unsigned int b:9;
};
-
{a=>44,b=>211}
2c00d3000000
2c00d3000000
2c000000d3000000
2c000000d3000000
-
{a=>106,b=>55}
6a0037000000
6a0037000000
6a00000037000000
6a00000037000000
-
{a=>-99,b=>100}
9dff64000000
9dff64000000
9dff000064000000
9dff000064000000
-
{a=>-25,b=>17}
e7ff11000000
e7ff11000000
e7ff000011000000
e7ff000011000000
-
{a=>-60,b=>31}
c4ff1f000000
c4ff1f000000
c4ff00001f000000
c4ff00001f000000
=
struct basic {
  short a;
  unsigned int b:9;
  unsigned int c:2;
};
-
{c=>0,a=>-3,b=>65}
fdff41000000
fdff41000000
fdff000041000000
fdff000041000000
-
{c=>3,a=>127,b=>141}
7f008d060000
7f008d060000
7f0000008d060000
7f0000008d060000
-
{c=>1,a=>-53,b=>123}
cbff7b020000
cbff7b020000
cbff00007b020000
cbff00007b020000
-
{c=>3,a=>-110,b=>69}
92ff45060000
92ff45060000
92ff000045060000
92ff000045060000
-
{c=>1,a=>-63,b=>183}
c1ffb7020000
c1ffb7020000
c1ff0000b7020000
c1ff0000b7020000
=
struct basic {
  short a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
};
-
{c=>1,a=>-32,b=>280}
e0ff18030000
e0ff18030000
e0ff000018030000
e0ff000018030000
-
{c=>0,a=>-76,b=>473}
b4ffd9010000
b4ffd9010000
b4ff0000d9010000
b4ff0000d9010000
-
{c=>2,a=>-60,b=>271}
c4ff0f050000
c4ff0f050000
c4ff00000f050000
c4ff00000f050000
-
{c=>1,a=>72,b=>50}
480032020000
480032020000
4800000032020000
4800000032020000
-
{c=>1,a=>-97,b=>440}
9fffb8030000
9fffb8030000
9fff0000b8030000
9fff0000b8030000
=
struct basic {
  short a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
  unsigned int d:2;
};
-
{c=>3,a=>-78,b=>286,d=>1}
b2ff1e470000
b2ff1e470000
b2ff00001e470000
b2ff00001e470000
-
{c=>2,a=>-105,b=>330,d=>3}
97ff4ac50000
97ff4ac50000
97ff00004ac50000
97ff00004ac50000
-
{c=>0,a=>73,b=>33,d=>1}
490021400000
490021400000
4900000021400000
4900000021400000
-
{c=>0,a=>-67,b=>463,d=>2}
bdffcf810000
bdffcf810000
bdff0000cf810000
bdff0000cf810000
-
{c=>0,a=>87,b=>452,d=>2}
5700c4810000
5700c4810000
57000000c4810000
57000000c4810000
=
struct basic {
  short a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
  unsigned int d:2;
  unsigned int e;
};
-
{e=>78,c=>2,a=>-39,b=>178,d=>3}
d9ffb2c400004e000000
d9ffb2c400004e000000
d9ff0000b2c400004e000000
d9ff0000b2c400004e000000
-
{e=>4,c=>2,a=>51,b=>65,d=>2}
33004184000004000000
33004184000004000000
330000004184000004000000
330000004184000004000000
-
{e=>225,c=>1,a=>-16,b=>99,d=>1}
f0ff63420000e1000000
f0ff63420000e1000000
f0ff000063420000e1000000
f0ff000063420000e1000000
-
{e=>23,c=>0,a=>-1,b=>254,d=>0}
fffffe00000017000000
fffffe00000017000000
ffff0000fe00000017000000
ffff0000fe00000017000000
-
{e=>75,c=>0,a=>7,b=>128,d=>1}
0700804000004b000000
0700804000004b000000
07000000804000004b000000
07000000804000004b000000
=
struct basic {
  int a;
  unsigned int b:9;
};
-
{a=>26,b=>294}
1a00000026010000
1a00000026010000
1a00000026010000
1a00000026010000
-
{a=>120,b=>54}
7800000036000000
7800000036000000
7800000036000000
7800000036000000
-
{a=>-16,b=>377}
f0ffffff79010000
f0ffffff79010000
f0ffffff79010000
f0ffffff79010000
-
{a=>38,b=>179}
26000000b3000000
26000000b3000000
26000000b3000000
26000000b3000000
-
{a=>116,b=>289}
7400000021010000
7400000021010000
7400000021010000
7400000021010000
=
struct basic {
  int a;
  unsigned int b:9;
  unsigned int c:2;
};
-
{c=>1,a=>49,b=>430}
31000000ae030000
31000000ae030000
31000000ae030000
31000000ae030000
-
{c=>3,a=>118,b=>459}
76000000cb070000
76000000cb070000
76000000cb070000
76000000cb070000
-
{c=>0,a=>1,b=>148}
0100000094000000
0100000094000000
0100000094000000
0100000094000000
-
{c=>0,a=>-80,b=>164}
b0ffffffa4000000
b0ffffffa4000000
b0ffffffa4000000
b0ffffffa4000000
-
{c=>3,a=>-5,b=>38}
fbffffff26060000
fbffffff26060000
fbffffff26060000
fbffffff26060000
=
struct basic {
  int a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
};
-
{c=>0,a=>73,b=>253}
49000000fd000000
49000000fd000000
49000000fd000000
49000000fd000000
-
{c=>3,a=>91,b=>302}
5b0000002e070000
5b0000002e070000
5b0000002e070000
5b0000002e070000
-
{c=>3,a=>30,b=>58}
1e0000003a060000
1e0000003a060000
1e0000003a060000
1e0000003a060000
-
{c=>0,a=>-109,b=>436}
93ffffffb4010000
93ffffffb4010000
93ffffffb4010000
93ffffffb4010000
-
{c=>3,a=>-89,b=>300}
a7ffffff2c070000
a7ffffff2c070000
a7ffffff2c070000
a7ffffff2c070000
=
struct basic {
  int a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
  unsigned int d:2;
};
-
{c=>2,a=>-81,b=>332,d=>0}
afffffff4c050000
afffffff4c050000
afffffff4c050000
afffffff4c050000
-
{c=>0,a=>-118,b=>311,d=>3}
8affffff37c10000
8affffff37c10000
8affffff37c10000
8affffff37c10000
-
{c=>2,a=>93,b=>362,d=>1}
5d0000006a450000
5d0000006a450000
5d0000006a450000
5d0000006a450000
-
{c=>0,a=>122,b=>370,d=>0}
7a00000072010000
7a00000072010000
7a00000072010000
7a00000072010000
-
{c=>2,a=>87,b=>107,d=>2}
570000006b840000
570000006b840000
570000006b840000
570000006b840000
=
struct basic {
  int a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
  unsigned int d:2;
  unsigned int e;
};
-
{e=>246,c=>1,a=>109,b=>275,d=>1}
6d00000013430000f6000000
6d00000013430000f6000000
6d00000013430000f6000000
6d00000013430000f6000000
-
{e=>120,c=>3,a=>80,b=>215,d=>2}
50000000d786000078000000
50000000d786000078000000
50000000d786000078000000
50000000d786000078000000
-
{e=>236,c=>0,a=>88,b=>484,d=>2}
58000000e4810000ec000000
58000000e4810000ec000000
58000000e4810000ec000000
58000000e4810000ec000000
-
{e=>9,c=>1,a=>-20,b=>117,d=>2}
ecffffff7582000009000000
ecffffff7582000009000000
ecffffff7582000009000000
ecffffff7582000009000000
-
{e=>135,c=>3,a=>126,b=>333,d=>1}
7e0000004d47000087000000
7e0000004d47000087000000
7e0000004d47000087000000
7e0000004d47000087000000
=
struct basic {
  long a;
  unsigned int b:9;
};
-
{a=>-90,b=>99}
a6ffffff63000000
a6ffffff63000000
a6ffffff63000000
a6ffffff63000000
-
{a=>18,b=>50}
1200000032000000
1200000032000000
1200000032000000
1200000032000000
-
{a=>-120,b=>264}
88ffffff08010000
88ffffff08010000
88ffffff08010000
88ffffff08010000
-
{a=>23,b=>32}
1700000020000000
1700000020000000
1700000020000000
1700000020000000
-
{a=>42,b=>321}
2a00000041010000
2a00000041010000
2a00000041010000
2a00000041010000
=
struct basic {
  long a;
  unsigned int b:9;
  unsigned int c:2;
};
-
{c=>3,a=>37,b=>303}
250000002f070000
250000002f070000
250000002f070000
250000002f070000
-
{c=>3,a=>-87,b=>458}
a9ffffffca070000
a9ffffffca070000
a9ffffffca070000
a9ffffffca070000
-
{c=>3,a=>-86,b=>453}
aaffffffc5070000
aaffffffc5070000
aaffffffc5070000
aaffffffc5070000
-
{c=>0,a=>96,b=>71}
6000000047000000
6000000047000000
6000000047000000
6000000047000000
-
{c=>0,a=>-46,b=>254}
d2fffffffe000000
d2fffffffe000000
d2fffffffe000000
d2fffffffe000000
=
struct basic {
  long a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
};
-
{c=>1,a=>-123,b=>56}
85ffffff38020000
85ffffff38020000
85ffffff38020000
85ffffff38020000
-
{c=>1,a=>-36,b=>276}
dcffffff14030000
dcffffff14030000
dcffffff14030000
dcffffff14030000
-
{c=>2,a=>26,b=>453}
1a000000c5050000
1a000000c5050000
1a000000c5050000
1a000000c5050000
-
{c=>0,a=>95,b=>479}
5f000000df010000
5f000000df010000
5f000000df010000
5f000000df010000
-
{c=>1,a=>28,b=>16}
1c00000010020000
1c00000010020000
1c00000010020000
1c00000010020000
=
struct basic {
  long a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
  unsigned int d:2;
};
-
{c=>3,a=>-75,b=>292,d=>0}
b5ffffff24070000
b5ffffff24070000
b5ffffff24070000
b5ffffff24070000
-
{c=>0,a=>24,b=>330,d=>0}
180000004a010000
180000004a010000
180000004a010000
180000004a010000
-
{c=>3,a=>2,b=>332,d=>1}
020000004c470000
020000004c470000
020000004c470000
020000004c470000
-
{c=>2,a=>74,b=>257,d=>1}
4a00000001450000
4a00000001450000
4a00000001450000
4a00000001450000
-
{c=>2,a=>106,b=>208,d=>3}
6a000000d0c40000
6a000000d0c40000
6a000000d0c40000
6a000000d0c40000
=
struct basic {
  long a;
  unsigned int b:9;
  unsigned int c:2;
  unsigned int  :3;
  unsigned int d:2;
  unsigned int e;
};
-
{e=>118,c=>0,a=>26,b=>490,d=>2}
1a000000ea81000076000000
1a000000ea81000076000000
1a000000ea81000076000000
1a000000ea81000076000000
-
{e=>200,c=>0,a=>6,b=>418,d=>1}
06000000a2410000c8000000
06000000a2410000c8000000
06000000a2410000c8000000
06000000a2410000c8000000
-
{e=>40,c=>1,a=>41,b=>444,d=>2}
29000000bc83000028000000
29000000bc83000028000000
29000000bc83000028000000
29000000bc83000028000000
-
{e=>154,c=>0,a=>0,b=>88,d=>3}
0000000058c000009a000000
0000000058c000009a000000
0000000058c000009a000000
0000000058c000009a000000
-
{e=>163,c=>3,a=>-5,b=>393,d=>0}
fbffffff89070000a3000000
fbffffff89070000a3000000
fbffffff89070000a3000000
fbffffff89070000a3000000
=
struct uchar {
  unsigned char  a:1;
};
-
{a=>0}
00
00
00
00
-
{a=>0}
00
00
00
00
-
{a=>0}
00
00
00
00
-
{a=>1}
01
01
01
01
-
{a=>1}
01
01
01
01
=
struct uchar {
  unsigned char  a:1;
  unsigned char  b:1;
};
-
{a=>1,b=>0}
01
01
01
01
-
{a=>1,b=>1}
03
03
03
03
-
{a=>0,b=>0}
00
00
00
00
-
{a=>1,b=>1}
03
03
03
03
-
{a=>0,b=>1}
02
02
02
02
=
struct uchar {
  unsigned char  a:1;
  unsigned char  b:1;
  unsigned char  c:1;
};
-
{c=>1,a=>1,b=>1}
07
07
07
07
-
{c=>1,a=>0,b=>0}
04
04
04
04
-
{c=>0,a=>0,b=>0}
00
00
00
00
-
{c=>1,a=>1,b=>1}
07
07
07
07
-
{c=>1,a=>1,b=>0}
05
05
05
05
=
struct uchar {
  unsigned char  a:1;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
};
-
{c=>1,a=>0,b=>1,d=>1}
0e
0e
0e
0e
-
{c=>0,a=>1,b=>0,d=>0}
01
01
01
01
-
{c=>0,a=>0,b=>1,d=>1}
0a
0a
0a
0a
-
{c=>1,a=>0,b=>0,d=>1}
0c
0c
0c
0c
-
{c=>0,a=>1,b=>0,d=>0}
01
01
01
01
=
struct uchar {
  unsigned char  a:1;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
  unsigned int   e;
};
-
{e=>111,c=>1,a=>1,b=>1,d=>1}
0f6f000000
0f006f000000
0f0000006f000000
0f0000006f000000
-
{e=>24,c=>0,a=>0,b=>1,d=>0}
0218000000
020018000000
0200000018000000
0200000018000000
-
{e=>185,c=>0,a=>0,b=>1,d=>0}
02b9000000
0200b9000000
02000000b9000000
02000000b9000000
-
{e=>229,c=>1,a=>0,b=>1,d=>1}
0ee5000000
0e00e5000000
0e000000e5000000
0e000000e5000000
-
{e=>255,c=>0,a=>1,b=>0,d=>1}
09ff000000
0900ff000000
09000000ff000000
09000000ff000000
=
struct uchar {
  char a;
  unsigned char  b:1;
};
-
{a=>-120,b=>1}
8801
8801
8801
8801
-
{a=>70,b=>0}
4600
4600
4600
4600
-
{a=>81,b=>0}
5100
5100
5100
5100
-
{a=>56,b=>1}
3801
3801
3801
3801
-
{a=>126,b=>0}
7e00
7e00
7e00
7e00
=
struct uchar {
  char a;
  unsigned char  b:1;
  unsigned char  c:1;
};
-
{c=>1,a=>16,b=>1}
1003
1003
1003
1003
-
{c=>0,a=>90,b=>1}
5a01
5a01
5a01
5a01
-
{c=>0,a=>-85,b=>0}
ab00
ab00
ab00
ab00
-
{c=>0,a=>74,b=>1}
4a01
4a01
4a01
4a01
-
{c=>0,a=>-127,b=>0}
8100
8100
8100
8100
=
struct uchar {
  char a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
};
-
{c=>1,a=>-84,b=>0,d=>1}
ac06
ac06
ac06
ac06
-
{c=>1,a=>-93,b=>1,d=>0}
a303
a303
a303
a303
-
{c=>1,a=>-94,b=>1,d=>1}
a207
a207
a207
a207
-
{c=>1,a=>116,b=>0,d=>0}
7402
7402
7402
7402
-
{c=>1,a=>92,b=>0,d=>1}
5c06
5c06
5c06
5c06
=
struct uchar {
  char a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
  unsigned char  e:1;
};
-
{e=>1,c=>0,a=>-104,b=>1,d=>0}
9809
9809
9809
9809
-
{e=>0,c=>1,a=>-94,b=>0,d=>0}
a202
a202
a202
a202
-
{e=>0,c=>0,a=>113,b=>1,d=>0}
7101
7101
7101
7101
-
{e=>1,c=>0,a=>25,b=>1,d=>1}
190d
190d
190d
190d
-
{e=>0,c=>0,a=>-21,b=>1,d=>1}
eb05
eb05
eb05
eb05
=
struct uchar {
  char a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
  unsigned char  e:1;
  unsigned int   f;
};
-
{e=>1,c=>1,a=>58,b=>1,d=>0,f=>7}
3a0b07000000
3a0b07000000
3a0b000007000000
3a0b000007000000
-
{e=>0,c=>0,a=>9,b=>0,d=>1,f=>220}
0904dc000000
0904dc000000
09040000dc000000
09040000dc000000
-
{e=>0,c=>1,a=>123,b=>1,d=>0,f=>59}
7b033b000000
7b033b000000
7b0300003b000000
7b0300003b000000
-
{e=>0,c=>1,a=>-113,b=>1,d=>1,f=>172}
8f07ac000000
8f07ac000000
8f070000ac000000
8f070000ac000000
-
{e=>0,c=>1,a=>75,b=>0,d=>1,f=>175}
4b06af000000
4b06af000000
4b060000af000000
4b060000af000000
=
struct uchar {
  short a;
  unsigned char  b:1;
};
-
{a=>-46,b=>1}
d2ff01
d2ff0100
d2ff0100
d2ff0100
-
{a=>32,b=>1}
200001
20000100
20000100
20000100
-
{a=>-26,b=>0}
e6ff00
e6ff0000
e6ff0000
e6ff0000
-
{a=>122,b=>0}
7a0000
7a000000
7a000000
7a000000
-
{a=>-51,b=>0}
cdff00
cdff0000
cdff0000
cdff0000
=
struct uchar {
  short a;
  unsigned char  b:1;
  unsigned char  c:1;
};
-
{c=>1,a=>14,b=>0}
0e0002
0e000200
0e000200
0e000200
-
{c=>1,a=>-41,b=>0}
d7ff02
d7ff0200
d7ff0200
d7ff0200
-
{c=>1,a=>-93,b=>1}
a3ff03
a3ff0300
a3ff0300
a3ff0300
-
{c=>0,a=>-76,b=>1}
b4ff01
b4ff0100
b4ff0100
b4ff0100
-
{c=>0,a=>-111,b=>0}
91ff00
91ff0000
91ff0000
91ff0000
=
struct uchar {
  short a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
};
-
{c=>0,a=>7,b=>1,d=>0}
070001
07000100
07000100
07000100
-
{c=>0,a=>64,b=>0,d=>0}
400000
40000000
40000000
40000000
-
{c=>1,a=>7,b=>0,d=>0}
070002
07000200
07000200
07000200
-
{c=>1,a=>-72,b=>1,d=>1}
b8ff07
b8ff0700
b8ff0700
b8ff0700
-
{c=>1,a=>62,b=>0,d=>1}
3e0006
3e000600
3e000600
3e000600
=
struct uchar {
  short a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
  unsigned char  e:1;
};
-
{e=>0,c=>1,a=>-108,b=>1,d=>0}
94ff03
94ff0300
94ff0300
94ff0300
-
{e=>1,c=>0,a=>-125,b=>1,d=>0}
83ff09
83ff0900
83ff0900
83ff0900
-
{e=>0,c=>1,a=>52,b=>1,d=>0}
340003
34000300
34000300
34000300
-
{e=>0,c=>0,a=>-93,b=>0,d=>0}
a3ff00
a3ff0000
a3ff0000
a3ff0000
-
{e=>1,c=>0,a=>-128,b=>0,d=>1}
80ff0c
80ff0c00
80ff0c00
80ff0c00
=
struct uchar {
  short a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
  unsigned char  e:1;
  unsigned int   f;
};
-
{e=>0,c=>0,a=>72,b=>1,d=>1,f=>111}
4800056f000000
480005006f000000
480005006f000000
480005006f000000
-
{e=>0,c=>1,a=>-44,b=>0,d=>0,f=>40}
d4ff0228000000
d4ff020028000000
d4ff020028000000
d4ff020028000000
-
{e=>1,c=>1,a=>121,b=>1,d=>0,f=>41}
79000b29000000
79000b0029000000
79000b0029000000
79000b0029000000
-
{e=>0,c=>1,a=>-68,b=>1,d=>0,f=>136}
bcff0388000000
bcff030088000000
bcff030088000000
bcff030088000000
-
{e=>0,c=>0,a=>-73,b=>1,d=>0,f=>25}
b7ff0119000000
b7ff010019000000
b7ff010019000000
b7ff010019000000
=
struct uchar {
  int a;
  unsigned char  b:1;
};
-
{a=>-57,b=>0}
c7ffffff00
c7ffffff0000
c7ffffff00000000
c7ffffff00000000
-
{a=>-29,b=>0}
e3ffffff00
e3ffffff0000
e3ffffff00000000
e3ffffff00000000
-
{a=>-23,b=>0}
e9ffffff00
e9ffffff0000
e9ffffff00000000
e9ffffff00000000
-
{a=>-128,b=>1}
80ffffff01
80ffffff0100
80ffffff01000000
80ffffff01000000
-
{a=>-58,b=>0}
c6ffffff00
c6ffffff0000
c6ffffff00000000
c6ffffff00000000
=
struct uchar {
  int a;
  unsigned char  b:1;
  unsigned char  c:1;
};
-
{c=>1,a=>-78,b=>1}
b2ffffff03
b2ffffff0300
b2ffffff03000000
b2ffffff03000000
-
{c=>0,a=>-100,b=>1}
9cffffff01
9cffffff0100
9cffffff01000000
9cffffff01000000
-
{c=>0,a=>-27,b=>0}
e5ffffff00
e5ffffff0000
e5ffffff00000000
e5ffffff00000000
-
{c=>1,a=>-123,b=>1}
85ffffff03
85ffffff0300
85ffffff03000000
85ffffff03000000
-
{c=>0,a=>-84,b=>0}
acffffff00
acffffff0000
acffffff00000000
acffffff00000000
=
struct uchar {
  int a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
};
-
{c=>1,a=>82,b=>0,d=>0}
5200000002
520000000200
5200000002000000
5200000002000000
-
{c=>0,a=>20,b=>0,d=>1}
1400000004
140000000400
1400000004000000
1400000004000000
-
{c=>1,a=>95,b=>0,d=>0}
5f00000002
5f0000000200
5f00000002000000
5f00000002000000
-
{c=>0,a=>71,b=>0,d=>0}
4700000000
470000000000
4700000000000000
4700000000000000
-
{c=>1,a=>-38,b=>0,d=>0}
daffffff02
daffffff0200
daffffff02000000
daffffff02000000
=
struct uchar {
  int a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
  unsigned char  e:1;
};
-
{e=>0,c=>0,a=>-32,b=>1,d=>1}
e0ffffff05
e0ffffff0500
e0ffffff05000000
e0ffffff05000000
-
{e=>0,c=>1,a=>-34,b=>1,d=>1}
deffffff07
deffffff0700
deffffff07000000
deffffff07000000
-
{e=>1,c=>1,a=>70,b=>1,d=>1}
460000000f
460000000f00
460000000f000000
460000000f000000
-
{e=>0,c=>1,a=>127,b=>1,d=>1}
7f00000007
7f0000000700
7f00000007000000
7f00000007000000
-
{e=>1,c=>0,a=>54,b=>1,d=>1}
360000000d
360000000d00
360000000d000000
360000000d000000
=
struct uchar {
  int a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
  unsigned char  e:1;
  unsigned int   f;
};
-
{e=>0,c=>0,a=>-63,b=>1,d=>1,f=>112}
c1ffffff0570000000
c1ffffff050070000000
c1ffffff0500000070000000
c1ffffff0500000070000000
-
{e=>0,c=>1,a=>-107,b=>0,d=>0,f=>190}
95ffffff02be000000
95ffffff0200be000000
95ffffff02000000be000000
95ffffff02000000be000000
-
{e=>0,c=>0,a=>-47,b=>1,d=>1,f=>78}
d1ffffff054e000000
d1ffffff05004e000000
d1ffffff050000004e000000
d1ffffff050000004e000000
-
{e=>1,c=>0,a=>65,b=>1,d=>1,f=>14}
410000000d0e000000
410000000d000e000000
410000000d0000000e000000
410000000d0000000e000000
-
{e=>1,c=>0,a=>52,b=>0,d=>1,f=>169}
340000000ca9000000
340000000c00a9000000
340000000c000000a9000000
340000000c000000a9000000
=
struct uchar {
  long a;
  unsigned char  b:1;
};
-
{a=>118,b=>0}
7600000000
760000000000
7600000000000000
7600000000000000
-
{a=>-95,b=>1}
a1ffffff01
a1ffffff0100
a1ffffff01000000
a1ffffff01000000
-
{a=>38,b=>0}
2600000000
260000000000
2600000000000000
2600000000000000
-
{a=>50,b=>0}
3200000000
320000000000
3200000000000000
3200000000000000
-
{a=>81,b=>0}
5100000000
510000000000
5100000000000000
5100000000000000
=
struct uchar {
  long a;
  unsigned char  b:1;
  unsigned char  c:1;
};
-
{c=>0,a=>97,b=>0}
6100000000
610000000000
6100000000000000
6100000000000000
-
{c=>0,a=>-20,b=>0}
ecffffff00
ecffffff0000
ecffffff00000000
ecffffff00000000
-
{c=>0,a=>-81,b=>0}
afffffff00
afffffff0000
afffffff00000000
afffffff00000000
-
{c=>0,a=>75,b=>0}
4b00000000
4b0000000000
4b00000000000000
4b00000000000000
-
{c=>0,a=>-108,b=>1}
94ffffff01
94ffffff0100
94ffffff01000000
94ffffff01000000
=
struct uchar {
  long a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
};
-
{c=>1,a=>101,b=>1,d=>0}
6500000003
650000000300
6500000003000000
6500000003000000
-
{c=>0,a=>-71,b=>0,d=>1}
b9ffffff04
b9ffffff0400
b9ffffff04000000
b9ffffff04000000
-
{c=>1,a=>-61,b=>0,d=>1}
c3ffffff06
c3ffffff0600
c3ffffff06000000
c3ffffff06000000
-
{c=>1,a=>-98,b=>0,d=>1}
9effffff06
9effffff0600
9effffff06000000
9effffff06000000
-
{c=>0,a=>86,b=>0,d=>0}
5600000000
560000000000
5600000000000000
5600000000000000
=
struct uchar {
  long a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
  unsigned char  e:1;
};
-
{e=>0,c=>1,a=>-117,b=>1,d=>1}
8bffffff07
8bffffff0700
8bffffff07000000
8bffffff07000000
-
{e=>1,c=>0,a=>47,b=>1,d=>1}
2f0000000d
2f0000000d00
2f0000000d000000
2f0000000d000000
-
{e=>1,c=>1,a=>-116,b=>0,d=>0}
8cffffff0a
8cffffff0a00
8cffffff0a000000
8cffffff0a000000
-
{e=>1,c=>1,a=>-118,b=>0,d=>1}
8affffff0e
8affffff0e00
8affffff0e000000
8affffff0e000000
-
{e=>1,c=>1,a=>-38,b=>0,d=>1}
daffffff0e
daffffff0e00
daffffff0e000000
daffffff0e000000
=
struct uchar {
  long a;
  unsigned char  b:1;
  unsigned char  c:1;
  unsigned char  d:1;
  unsigned char  e:1;
  unsigned int   f;
};
-
{e=>0,c=>1,a=>-47,b=>0,d=>1,f=>41}
d1ffffff0629000000
d1ffffff060029000000
d1ffffff0600000029000000
d1ffffff0600000029000000
-
{e=>0,c=>1,a=>-89,b=>1,d=>0,f=>152}
a7ffffff0398000000
a7ffffff030098000000
a7ffffff0300000098000000
a7ffffff0300000098000000
-
{e=>1,c=>1,a=>114,b=>1,d=>1,f=>37}
720000000f25000000
720000000f0025000000
720000000f00000025000000
720000000f00000025000000
-
{e=>1,c=>1,a=>127,b=>1,d=>1,f=>22}
7f0000000f16000000
7f0000000f0016000000
7f0000000f00000016000000
7f0000000f00000016000000
-
{e=>0,c=>0,a=>-95,b=>1,d=>0,f=>125}
a1ffffff017d000000
a1ffffff01007d000000
a1ffffff010000007d000000
a1ffffff010000007d000000
=
struct ushort {
  unsigned short a:1;
};
-
{a=>1}
0100
0100
0100
0100
-
{a=>1}
0100
0100
0100
0100
-
{a=>0}
0000
0000
0000
0000
-
{a=>0}
0000
0000
0000
0000
-
{a=>0}
0000
0000
0000
0000
=
struct ushort {
  unsigned short a:1;
  unsigned short b:1;
};
-
{a=>1,b=>1}
0300
0300
0300
0300
-
{a=>0,b=>0}
0000
0000
0000
0000
-
{a=>1,b=>0}
0100
0100
0100
0100
-
{a=>0,b=>0}
0000
0000
0000
0000
-
{a=>0,b=>1}
0200
0200
0200
0200
=
struct ushort {
  unsigned short a:1;
  unsigned short b:1;
  unsigned short c:1;
};
-
{c=>1,a=>0,b=>1}
0600
0600
0600
0600
-
{c=>0,a=>1,b=>1}
0300
0300
0300
0300
-
{c=>1,a=>0,b=>1}
0600
0600
0600
0600
-
{c=>0,a=>0,b=>1}
0200
0200
0200
0200
-
{c=>1,a=>0,b=>1}
0600
0600
0600
0600
=
struct ushort {
  unsigned short a:1;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
};
-
{c=>0,a=>0,b=>0,d=>1}
0800
0800
0800
0800
-
{c=>1,a=>1,b=>1,d=>0}
0700
0700
0700
0700
-
{c=>1,a=>1,b=>1,d=>1}
0f00
0f00
0f00
0f00
-
{c=>1,a=>1,b=>0,d=>0}
0500
0500
0500
0500
-
{c=>1,a=>0,b=>0,d=>0}
0400
0400
0400
0400
=
struct ushort {
  unsigned short a:1;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
  unsigned int   e;
};
-
{e=>78,c=>1,a=>0,b=>0,d=>1}
0c004e000000
0c004e000000
0c0000004e000000
0c0000004e000000
-
{e=>118,c=>1,a=>1,b=>0,d=>0}
050076000000
050076000000
0500000076000000
0500000076000000
-
{e=>65,c=>0,a=>0,b=>1,d=>1}
0a0041000000
0a0041000000
0a00000041000000
0a00000041000000
-
{e=>216,c=>0,a=>0,b=>1,d=>1}
0a00d8000000
0a00d8000000
0a000000d8000000
0a000000d8000000
-
{e=>98,c=>0,a=>0,b=>1,d=>1}
0a0062000000
0a0062000000
0a00000062000000
0a00000062000000
=
struct ushort {
  char a;
  unsigned short b:1;
};
-
{a=>22,b=>1}
160100
16000100
16000100
16000100
-
{a=>-76,b=>0}
b40000
b4000000
b4000000
b4000000
-
{a=>101,b=>1}
650100
65000100
65000100
65000100
-
{a=>110,b=>0}
6e0000
6e000000
6e000000
6e000000
-
{a=>19,b=>1}
130100
13000100
13000100
13000100
=
struct ushort {
  char a;
  unsigned short b:1;
  unsigned short c:1;
};
-
{c=>0,a=>103,b=>1}
670100
67000100
67000100
67000100
-
{c=>1,a=>-109,b=>1}
930300
93000300
93000300
93000300
-
{c=>1,a=>-16,b=>0}
f00200
f0000200
f0000200
f0000200
-
{c=>1,a=>124,b=>1}
7c0300
7c000300
7c000300
7c000300
-
{c=>1,a=>109,b=>0}
6d0200
6d000200
6d000200
6d000200
=
struct ushort {
  char a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
};
-
{c=>0,a=>-25,b=>1,d=>0}
e70100
e7000100
e7000100
e7000100
-
{c=>1,a=>-79,b=>0,d=>0}
b10200
b1000200
b1000200
b1000200
-
{c=>1,a=>102,b=>0,d=>1}
660600
66000600
66000600
66000600
-
{c=>0,a=>125,b=>1,d=>1}
7d0500
7d000500
7d000500
7d000500
-
{c=>0,a=>5,b=>1,d=>1}
050500
05000500
05000500
05000500
=
struct ushort {
  char a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
  unsigned short e:1;
};
-
{e=>1,c=>0,a=>9,b=>1,d=>0}
090900
09000900
09000900
09000900
-
{e=>1,c=>0,a=>44,b=>1,d=>1}
2c0d00
2c000d00
2c000d00
2c000d00
-
{e=>0,c=>0,a=>44,b=>0,d=>0}
2c0000
2c000000
2c000000
2c000000
-
{e=>1,c=>1,a=>-13,b=>0,d=>1}
f30e00
f3000e00
f3000e00
f3000e00
-
{e=>0,c=>1,a=>-2,b=>0,d=>0}
fe0200
fe000200
fe000200
fe000200
=
struct ushort {
  char a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
  unsigned short e:1;
  unsigned int   f;
};
-
{e=>1,c=>1,a=>107,b=>1,d=>0,f=>112}
6b0b0070000000
6b000b0070000000
6b000b0070000000
6b000b0070000000
-
{e=>0,c=>1,a=>-68,b=>1,d=>1,f=>129}
bc070081000000
bc00070081000000
bc00070081000000
bc00070081000000
-
{e=>0,c=>0,a=>72,b=>1,d=>1,f=>226}
480500e2000000
48000500e2000000
48000500e2000000
48000500e2000000
-
{e=>0,c=>0,a=>-102,b=>0,d=>1,f=>147}
9a040093000000
9a00040093000000
9a00040093000000
9a00040093000000
-
{e=>1,c=>1,a=>-25,b=>1,d=>1,f=>7}
e70f0007000000
e7000f0007000000
e7000f0007000000
e7000f0007000000
=
struct ushort {
  short a;
  unsigned short b:1;
};
-
{a=>89,b=>1}
59000100
59000100
59000100
59000100
-
{a=>-24,b=>0}
e8ff0000
e8ff0000
e8ff0000
e8ff0000
-
{a=>53,b=>1}
35000100
35000100
35000100
35000100
-
{a=>60,b=>1}
3c000100
3c000100
3c000100
3c000100
-
{a=>-33,b=>1}
dfff0100
dfff0100
dfff0100
dfff0100
=
struct ushort {
  short a;
  unsigned short b:1;
  unsigned short c:1;
};
-
{c=>1,a=>-21,b=>0}
ebff0200
ebff0200
ebff0200
ebff0200
-
{c=>0,a=>65,b=>0}
41000000
41000000
41000000
41000000
-
{c=>0,a=>-82,b=>0}
aeff0000
aeff0000
aeff0000
aeff0000
-
{c=>1,a=>-45,b=>0}
d3ff0200
d3ff0200
d3ff0200
d3ff0200
-
{c=>1,a=>-105,b=>0}
97ff0200
97ff0200
97ff0200
97ff0200
=
struct ushort {
  short a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
};
-
{c=>0,a=>5,b=>1,d=>1}
05000500
05000500
05000500
05000500
-
{c=>1,a=>-68,b=>1,d=>0}
bcff0300
bcff0300
bcff0300
bcff0300
-
{c=>1,a=>-4,b=>0,d=>0}
fcff0200
fcff0200
fcff0200
fcff0200
-
{c=>1,a=>122,b=>1,d=>1}
7a000700
7a000700
7a000700
7a000700
-
{c=>1,a=>-64,b=>1,d=>0}
c0ff0300
c0ff0300
c0ff0300
c0ff0300
=
struct ushort {
  short a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
  unsigned short e:1;
};
-
{e=>1,c=>1,a=>96,b=>1,d=>1}
60000f00
60000f00
60000f00
60000f00
-
{e=>0,c=>0,a=>-110,b=>1,d=>0}
92ff0100
92ff0100
92ff0100
92ff0100
-
{e=>1,c=>1,a=>-47,b=>1,d=>0}
d1ff0b00
d1ff0b00
d1ff0b00
d1ff0b00
-
{e=>0,c=>1,a=>71,b=>1,d=>0}
47000300
47000300
47000300
47000300
-
{e=>1,c=>1,a=>-110,b=>1,d=>1}
92ff0f00
92ff0f00
92ff0f00
92ff0f00
=
struct ushort {
  short a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
  unsigned short e:1;
  unsigned int   f;
};
-
{e=>0,c=>1,a=>-77,b=>1,d=>0,f=>56}
b3ff030038000000
b3ff030038000000
b3ff030038000000
b3ff030038000000
-
{e=>0,c=>0,a=>108,b=>1,d=>1,f=>82}
6c00050052000000
6c00050052000000
6c00050052000000
6c00050052000000
-
{e=>0,c=>0,a=>4,b=>1,d=>1,f=>96}
0400050060000000
0400050060000000
0400050060000000
0400050060000000
-
{e=>0,c=>0,a=>93,b=>1,d=>1,f=>28}
5d0005001c000000
5d0005001c000000
5d0005001c000000
5d0005001c000000
-
{e=>1,c=>0,a=>40,b=>1,d=>1,f=>174}
28000d00ae000000
28000d00ae000000
28000d00ae000000
28000d00ae000000
=
struct ushort {
  int a;
  unsigned short b:1;
};
-
{a=>88,b=>1}
580000000100
580000000100
5800000001000000
5800000001000000
-
{a=>-118,b=>1}
8affffff0100
8affffff0100
8affffff01000000
8affffff01000000
-
{a=>122,b=>1}
7a0000000100
7a0000000100
7a00000001000000
7a00000001000000
-
{a=>-125,b=>0}
83ffffff0000
83ffffff0000
83ffffff00000000
83ffffff00000000
-
{a=>-83,b=>0}
adffffff0000
adffffff0000
adffffff00000000
adffffff00000000
=
struct ushort {
  int a;
  unsigned short b:1;
  unsigned short c:1;
};
-
{c=>0,a=>-73,b=>1}
b7ffffff0100
b7ffffff0100
b7ffffff01000000
b7ffffff01000000
-
{c=>1,a=>41,b=>0}
290000000200
290000000200
2900000002000000
2900000002000000
-
{c=>0,a=>-10,b=>0}
f6ffffff0000
f6ffffff0000
f6ffffff00000000
f6ffffff00000000
-
{c=>1,a=>46,b=>1}
2e0000000300
2e0000000300
2e00000003000000
2e00000003000000
-
{c=>0,a=>91,b=>1}
5b0000000100
5b0000000100
5b00000001000000
5b00000001000000
=
struct ushort {
  int a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
};
-
{c=>0,a=>62,b=>1,d=>1}
3e0000000500
3e0000000500
3e00000005000000
3e00000005000000
-
{c=>1,a=>-98,b=>1,d=>1}
9effffff0700
9effffff0700
9effffff07000000
9effffff07000000
-
{c=>0,a=>-94,b=>0,d=>0}
a2ffffff0000
a2ffffff0000
a2ffffff00000000
a2ffffff00000000
-
{c=>0,a=>36,b=>1,d=>0}
240000000100
240000000100
2400000001000000
2400000001000000
-
{c=>1,a=>-4,b=>0,d=>1}
fcffffff0600
fcffffff0600
fcffffff06000000
fcffffff06000000
=
struct ushort {
  int a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
  unsigned short e:1;
};
-
{e=>0,c=>0,a=>96,b=>0,d=>0}
600000000000
600000000000
6000000000000000
6000000000000000
-
{e=>1,c=>0,a=>127,b=>1,d=>0}
7f0000000900
7f0000000900
7f00000009000000
7f00000009000000
-
{e=>1,c=>0,a=>40,b=>0,d=>0}
280000000800
280000000800
2800000008000000
2800000008000000
-
{e=>1,c=>0,a=>96,b=>0,d=>1}
600000000c00
600000000c00
600000000c000000
600000000c000000
-
{e=>0,c=>0,a=>-42,b=>0,d=>1}
d6ffffff0400
d6ffffff0400
d6ffffff04000000
d6ffffff04000000
=
struct ushort {
  int a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
  unsigned short e:1;
  unsigned int   f;
};
-
{e=>0,c=>1,a=>15,b=>0,d=>0,f=>0}
0f000000020000000000
0f000000020000000000
0f0000000200000000000000
0f0000000200000000000000
-
{e=>1,c=>0,a=>-90,b=>1,d=>1,f=>104}
a6ffffff0d0068000000
a6ffffff0d0068000000
a6ffffff0d00000068000000
a6ffffff0d00000068000000
-
{e=>1,c=>0,a=>-53,b=>1,d=>0,f=>14}
cbffffff09000e000000
cbffffff09000e000000
cbffffff090000000e000000
cbffffff090000000e000000
-
{e=>0,c=>1,a=>41,b=>0,d=>1,f=>247}
290000000600f7000000
290000000600f7000000
2900000006000000f7000000
2900000006000000f7000000
-
{e=>1,c=>1,a=>-21,b=>0,d=>0,f=>111}
ebffffff0a006f000000
ebffffff0a006f000000
ebffffff0a0000006f000000
ebffffff0a0000006f000000
=
struct ushort {
  long a;
  unsigned short b:1;
};
-
{a=>-109,b=>0}
93ffffff0000
93ffffff0000
93ffffff00000000
93ffffff00000000
-
{a=>68,b=>1}
440000000100
440000000100
4400000001000000
4400000001000000
-
{a=>-127,b=>0}
81ffffff0000
81ffffff0000
81ffffff00000000
81ffffff00000000
-
{a=>-101,b=>1}
9bffffff0100
9bffffff0100
9bffffff01000000
9bffffff01000000
-
{a=>65,b=>1}
410000000100
410000000100
4100000001000000
4100000001000000
=
struct ushort {
  long a;
  unsigned short b:1;
  unsigned short c:1;
};
-
{c=>0,a=>-118,b=>0}
8affffff0000
8affffff0000
8affffff00000000
8affffff00000000
-
{c=>0,a=>98,b=>1}
620000000100
620000000100
6200000001000000
6200000001000000
-
{c=>0,a=>20,b=>0}
140000000000
140000000000
1400000000000000
1400000000000000
-
{c=>0,a=>-71,b=>0}
b9ffffff0000
b9ffffff0000
b9ffffff00000000
b9ffffff00000000
-
{c=>0,a=>-104,b=>1}
98ffffff0100
98ffffff0100
98ffffff01000000
98ffffff01000000
=
struct ushort {
  long a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
};
-
{c=>0,a=>31,b=>1,d=>1}
1f0000000500
1f0000000500
1f00000005000000
1f00000005000000
-
{c=>1,a=>105,b=>0,d=>1}
690000000600
690000000600
6900000006000000
6900000006000000
-
{c=>1,a=>-124,b=>1,d=>0}
84ffffff0300
84ffffff0300
84ffffff03000000
84ffffff03000000
-
{c=>1,a=>11,b=>1,d=>1}
0b0000000700
0b0000000700
0b00000007000000
0b00000007000000
-
{c=>1,a=>21,b=>0,d=>1}
150000000600
150000000600
1500000006000000
1500000006000000
=
struct ushort {
  long a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
  unsigned short e:1;
};
-
{e=>0,c=>0,a=>51,b=>0,d=>0}
330000000000
330000000000
3300000000000000
3300000000000000
-
{e=>1,c=>1,a=>16,b=>1,d=>1}
100000000f00
100000000f00
100000000f000000
100000000f000000
-
{e=>1,c=>1,a=>-30,b=>1,d=>1}
e2ffffff0f00
e2ffffff0f00
e2ffffff0f000000
e2ffffff0f000000
-
{e=>1,c=>0,a=>-27,b=>1,d=>0}
e5ffffff0900
e5ffffff0900
e5ffffff09000000
e5ffffff09000000
-
{e=>0,c=>0,a=>44,b=>1,d=>1}
2c0000000500
2c0000000500
2c00000005000000
2c00000005000000
=
struct ushort {
  long a;
  unsigned short b:1;
  unsigned short c:1;
  unsigned short d:1;
  unsigned short e:1;
  unsigned int   f;
};
-
{e=>0,c=>1,a=>-43,b=>1,d=>0,f=>98}
d5ffffff030062000000
d5ffffff030062000000
d5ffffff0300000062000000
d5ffffff0300000062000000
-
{e=>1,c=>0,a=>-40,b=>1,d=>1,f=>138}
d8ffffff0d008a000000
d8ffffff0d008a000000
d8ffffff0d0000008a000000
d8ffffff0d0000008a000000
-
{e=>1,c=>0,a=>14,b=>1,d=>1,f=>44}
0e0000000d002c000000
0e0000000d002c000000
0e0000000d0000002c000000
0e0000000d0000002c000000
-
{e=>1,c=>1,a=>-30,b=>1,d=>0,f=>32}
e2ffffff0b0020000000
e2ffffff0b0020000000
e2ffffff0b00000020000000
e2ffffff0b00000020000000
-
{e=>0,c=>1,a=>87,b=>0,d=>1,f=>216}
570000000600d8000000
570000000600d8000000
5700000006000000d8000000
5700000006000000d8000000
=
struct uint {
  unsigned int   a:1;
};
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>1}
01000000
01000000
01000000
01000000
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>1}
01000000
01000000
01000000
01000000
=
struct uint {
  unsigned int   a:1;
  unsigned int   b:1;
};
-
{a=>0,b=>1}
02000000
02000000
02000000
02000000
-
{a=>0,b=>0}
00000000
00000000
00000000
00000000
-
{a=>1,b=>0}
01000000
01000000
01000000
01000000
-
{a=>0,b=>1}
02000000
02000000
02000000
02000000
-
{a=>0,b=>0}
00000000
00000000
00000000
00000000
=
struct uint {
  unsigned int   a:1;
  unsigned int   b:1;
  unsigned int   c:1;
};
-
{c=>0,a=>0,b=>1}
02000000
02000000
02000000
02000000
-
{c=>1,a=>1,b=>0}
05000000
05000000
05000000
05000000
-
{c=>0,a=>1,b=>1}
03000000
03000000
03000000
03000000
-
{c=>1,a=>0,b=>0}
04000000
04000000
04000000
04000000
-
{c=>0,a=>0,b=>1}
02000000
02000000
02000000
02000000
=
struct uint {
  unsigned int   a:1;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
};
-
{c=>0,a=>1,b=>1,d=>0}
03000000
03000000
03000000
03000000
-
{c=>0,a=>0,b=>0,d=>0}
00000000
00000000
00000000
00000000
-
{c=>1,a=>0,b=>0,d=>1}
0c000000
0c000000
0c000000
0c000000
-
{c=>0,a=>0,b=>1,d=>0}
02000000
02000000
02000000
02000000
-
{c=>1,a=>0,b=>1,d=>0}
06000000
06000000
06000000
06000000
=
struct uint {
  unsigned int   a:1;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
  unsigned char  e;
};
-
{e=>191,c=>1,a=>1,b=>1,d=>1}
0f000000bf
0f000000bf00
0f000000bf000000
0f000000bf000000
-
{e=>169,c=>0,a=>1,b=>0,d=>0}
01000000a9
01000000a900
01000000a9000000
01000000a9000000
-
{e=>146,c=>0,a=>1,b=>1,d=>0}
0300000092
030000009200
0300000092000000
0300000092000000
-
{e=>101,c=>1,a=>1,b=>0,d=>0}
0500000065
050000006500
0500000065000000
0500000065000000
-
{e=>214,c=>0,a=>0,b=>1,d=>0}
02000000d6
02000000d600
02000000d6000000
02000000d6000000
=
struct uint {
  char a;
  unsigned int   b:1;
};
-
{a=>75,b=>1}
4b01000000
4b0001000000
4b00000001000000
4b00000001000000
-
{a=>-108,b=>1}
9401000000
940001000000
9400000001000000
9400000001000000
-
{a=>-66,b=>0}
be00000000
be0000000000
be00000000000000
be00000000000000
-
{a=>70,b=>0}
4600000000
460000000000
4600000000000000
4600000000000000
-
{a=>42,b=>0}
2a00000000
2a0000000000
2a00000000000000
2a00000000000000
=
struct uint {
  char a;
  unsigned int   b:1;
  unsigned int   c:1;
};
-
{c=>1,a=>-100,b=>1}
9c03000000
9c0003000000
9c00000003000000
9c00000003000000
-
{c=>1,a=>93,b=>0}
5d02000000
5d0002000000
5d00000002000000
5d00000002000000
-
{c=>1,a=>40,b=>0}
2802000000
280002000000
2800000002000000
2800000002000000
-
{c=>1,a=>-20,b=>1}
ec03000000
ec0003000000
ec00000003000000
ec00000003000000
-
{c=>1,a=>5,b=>0}
0502000000
050002000000
0500000002000000
0500000002000000
=
struct uint {
  char a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
};
-
{c=>0,a=>-26,b=>0,d=>0}
e600000000
e60000000000
e600000000000000
e600000000000000
-
{c=>0,a=>-121,b=>0,d=>0}
8700000000
870000000000
8700000000000000
8700000000000000
-
{c=>1,a=>2,b=>0,d=>1}
0206000000
020006000000
0200000006000000
0200000006000000
-
{c=>1,a=>-54,b=>1,d=>0}
ca03000000
ca0003000000
ca00000003000000
ca00000003000000
-
{c=>1,a=>79,b=>0,d=>0}
4f02000000
4f0002000000
4f00000002000000
4f00000002000000
=
struct uint {
  char a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
  unsigned int   e:1;
};
-
{e=>0,c=>1,a=>123,b=>0,d=>1}
7b06000000
7b0006000000
7b00000006000000
7b00000006000000
-
{e=>0,c=>0,a=>-85,b=>1,d=>0}
ab01000000
ab0001000000
ab00000001000000
ab00000001000000
-
{e=>0,c=>1,a=>108,b=>1,d=>0}
6c03000000
6c0003000000
6c00000003000000
6c00000003000000
-
{e=>0,c=>0,a=>5,b=>1,d=>0}
0501000000
050001000000
0500000001000000
0500000001000000
-
{e=>1,c=>0,a=>37,b=>0,d=>0}
2508000000
250008000000
2500000008000000
2500000008000000
=
struct uint {
  char a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
  unsigned int   e:1;
  unsigned char  f;
};
-
{e=>1,c=>1,a=>-3,b=>0,d=>0,f=>33}
fd0a00000021
fd000a0000002100
fd0000000a00000021000000
fd0000000a00000021000000
-
{e=>1,c=>0,a=>-54,b=>1,d=>1,f=>25}
ca0d00000019
ca000d0000001900
ca0000000d00000019000000
ca0000000d00000019000000
-
{e=>1,c=>1,a=>99,b=>0,d=>0,f=>1}
630a00000001
63000a0000000100
630000000a00000001000000
630000000a00000001000000
-
{e=>0,c=>0,a=>36,b=>0,d=>1,f=>171}
2404000000ab
240004000000ab00
2400000004000000ab000000
2400000004000000ab000000
-
{e=>0,c=>0,a=>-112,b=>0,d=>1,f=>44}
90040000002c
9000040000002c00
90000000040000002c000000
90000000040000002c000000
=
struct uint {
  short a;
  unsigned int   b:1;
};
-
{a=>17,b=>1}
110001000000
110001000000
1100000001000000
1100000001000000
-
{a=>-109,b=>0}
93ff00000000
93ff00000000
93ff000000000000
93ff000000000000
-
{a=>66,b=>1}
420001000000
420001000000
4200000001000000
4200000001000000
-
{a=>15,b=>0}
0f0000000000
0f0000000000
0f00000000000000
0f00000000000000
-
{a=>67,b=>1}
430001000000
430001000000
4300000001000000
4300000001000000
=
struct uint {
  short a;
  unsigned int   b:1;
  unsigned int   c:1;
};
-
{c=>1,a=>-17,b=>0}
efff02000000
efff02000000
efff000002000000
efff000002000000
-
{c=>0,a=>-96,b=>0}
a0ff00000000
a0ff00000000
a0ff000000000000
a0ff000000000000
-
{c=>0,a=>19,b=>0}
130000000000
130000000000
1300000000000000
1300000000000000
-
{c=>1,a=>-75,b=>1}
b5ff03000000
b5ff03000000
b5ff000003000000
b5ff000003000000
-
{c=>0,a=>-26,b=>1}
e6ff01000000
e6ff01000000
e6ff000001000000
e6ff000001000000
=
struct uint {
  short a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
};
-
{c=>0,a=>-128,b=>0,d=>1}
80ff04000000
80ff04000000
80ff000004000000
80ff000004000000
-
{c=>0,a=>6,b=>0,d=>1}
060004000000
060004000000
0600000004000000
0600000004000000
-
{c=>1,a=>-76,b=>1,d=>0}
b4ff03000000
b4ff03000000
b4ff000003000000
b4ff000003000000
-
{c=>0,a=>-60,b=>1,d=>0}
c4ff01000000
c4ff01000000
c4ff000001000000
c4ff000001000000
-
{c=>1,a=>-102,b=>1,d=>1}
9aff07000000
9aff07000000
9aff000007000000
9aff000007000000
=
struct uint {
  short a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
  unsigned int   e:1;
};
-
{e=>0,c=>0,a=>-11,b=>0,d=>1}
f5ff04000000
f5ff04000000
f5ff000004000000
f5ff000004000000
-
{e=>1,c=>0,a=>-23,b=>1,d=>1}
e9ff0d000000
e9ff0d000000
e9ff00000d000000
e9ff00000d000000
-
{e=>1,c=>1,a=>81,b=>0,d=>0}
51000a000000
51000a000000
510000000a000000
510000000a000000
-
{e=>0,c=>0,a=>16,b=>0,d=>0}
100000000000
100000000000
1000000000000000
1000000000000000
-
{e=>1,c=>1,a=>90,b=>1,d=>0}
5a000b000000
5a000b000000
5a0000000b000000
5a0000000b000000
=
struct uint {
  short a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
  unsigned int   e:1;
  unsigned char  f;
};
-
{e=>0,c=>1,a=>108,b=>0,d=>1,f=>91}
6c00060000005b
6c00060000005b00
6c000000060000005b000000
6c000000060000005b000000
-
{e=>0,c=>0,a=>113,b=>1,d=>0,f=>123}
7100010000007b
7100010000007b00
71000000010000007b000000
71000000010000007b000000
-
{e=>0,c=>0,a=>-118,b=>1,d=>1,f=>27}
8aff050000001b
8aff050000001b00
8aff0000050000001b000000
8aff0000050000001b000000
-
{e=>0,c=>0,a=>105,b=>1,d=>1,f=>227}
690005000000e3
690005000000e300
6900000005000000e3000000
6900000005000000e3000000
-
{e=>0,c=>1,a=>58,b=>0,d=>0,f=>37}
3a000200000025
3a00020000002500
3a0000000200000025000000
3a0000000200000025000000
=
struct uint {
  int a;
  unsigned int   b:1;
};
-
{a=>123,b=>0}
7b00000000000000
7b00000000000000
7b00000000000000
7b00000000000000
-
{a=>-82,b=>1}
aeffffff01000000
aeffffff01000000
aeffffff01000000
aeffffff01000000
-
{a=>-71,b=>0}
b9ffffff00000000
b9ffffff00000000
b9ffffff00000000
b9ffffff00000000
-
{a=>-16,b=>0}
f0ffffff00000000
f0ffffff00000000
f0ffffff00000000
f0ffffff00000000
-
{a=>82,b=>0}
5200000000000000
5200000000000000
5200000000000000
5200000000000000
=
struct uint {
  int a;
  unsigned int   b:1;
  unsigned int   c:1;
};
-
{c=>0,a=>-82,b=>1}
aeffffff01000000
aeffffff01000000
aeffffff01000000
aeffffff01000000
-
{c=>1,a=>76,b=>1}
4c00000003000000
4c00000003000000
4c00000003000000
4c00000003000000
-
{c=>0,a=>90,b=>1}
5a00000001000000
5a00000001000000
5a00000001000000
5a00000001000000
-
{c=>0,a=>-87,b=>1}
a9ffffff01000000
a9ffffff01000000
a9ffffff01000000
a9ffffff01000000
-
{c=>1,a=>-70,b=>0}
baffffff02000000
baffffff02000000
baffffff02000000
baffffff02000000
=
struct uint {
  int a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
};
-
{c=>0,a=>103,b=>1,d=>1}
6700000005000000
6700000005000000
6700000005000000
6700000005000000
-
{c=>0,a=>-102,b=>1,d=>0}
9affffff01000000
9affffff01000000
9affffff01000000
9affffff01000000
-
{c=>1,a=>8,b=>1,d=>1}
0800000007000000
0800000007000000
0800000007000000
0800000007000000
-
{c=>1,a=>24,b=>0,d=>1}
1800000006000000
1800000006000000
1800000006000000
1800000006000000
-
{c=>0,a=>-37,b=>1,d=>1}
dbffffff05000000
dbffffff05000000
dbffffff05000000
dbffffff05000000
=
struct uint {
  int a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
  unsigned int   e:1;
};
-
{e=>1,c=>1,a=>73,b=>0,d=>0}
490000000a000000
490000000a000000
490000000a000000
490000000a000000
-
{e=>0,c=>0,a=>-47,b=>1,d=>1}
d1ffffff05000000
d1ffffff05000000
d1ffffff05000000
d1ffffff05000000
-
{e=>1,c=>1,a=>105,b=>0,d=>1}
690000000e000000
690000000e000000
690000000e000000
690000000e000000
-
{e=>1,c=>0,a=>39,b=>1,d=>1}
270000000d000000
270000000d000000
270000000d000000
270000000d000000
-
{e=>0,c=>1,a=>-19,b=>0,d=>0}
edffffff02000000
edffffff02000000
edffffff02000000
edffffff02000000
=
struct uint {
  int a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
  unsigned int   e:1;
  unsigned char  f;
};
-
{e=>0,c=>1,a=>-13,b=>0,d=>0,f=>179}
f3ffffff02000000b3
f3ffffff02000000b300
f3ffffff02000000b3000000
f3ffffff02000000b3000000
-
{e=>0,c=>1,a=>-50,b=>0,d=>1,f=>86}
ceffffff0600000056
ceffffff060000005600
ceffffff0600000056000000
ceffffff0600000056000000
-
{e=>1,c=>1,a=>127,b=>0,d=>1,f=>197}
7f0000000e000000c5
7f0000000e000000c500
7f0000000e000000c5000000
7f0000000e000000c5000000
-
{e=>0,c=>1,a=>22,b=>0,d=>1,f=>205}
1600000006000000cd
1600000006000000cd00
1600000006000000cd000000
1600000006000000cd000000
-
{e=>1,c=>1,a=>-24,b=>1,d=>0,f=>208}
e8ffffff0b000000d0
e8ffffff0b000000d000
e8ffffff0b000000d0000000
e8ffffff0b000000d0000000
=
struct uint {
  long a;
  unsigned int   b:1;
};
-
{a=>125,b=>0}
7d00000000000000
7d00000000000000
7d00000000000000
7d00000000000000
-
{a=>76,b=>0}
4c00000000000000
4c00000000000000
4c00000000000000
4c00000000000000
-
{a=>118,b=>1}
7600000001000000
7600000001000000
7600000001000000
7600000001000000
-
{a=>39,b=>1}
2700000001000000
2700000001000000
2700000001000000
2700000001000000
-
{a=>117,b=>0}
7500000000000000
7500000000000000
7500000000000000
7500000000000000
=
struct uint {
  long a;
  unsigned int   b:1;
  unsigned int   c:1;
};
-
{c=>0,a=>96,b=>1}
6000000001000000
6000000001000000
6000000001000000
6000000001000000
-
{c=>0,a=>85,b=>0}
5500000000000000
5500000000000000
5500000000000000
5500000000000000
-
{c=>0,a=>-120,b=>1}
88ffffff01000000
88ffffff01000000
88ffffff01000000
88ffffff01000000
-
{c=>1,a=>46,b=>1}
2e00000003000000
2e00000003000000
2e00000003000000
2e00000003000000
-
{c=>1,a=>-15,b=>1}
f1ffffff03000000
f1ffffff03000000
f1ffffff03000000
f1ffffff03000000
=
struct uint {
  long a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
};
-
{c=>1,a=>86,b=>0,d=>0}
5600000002000000
5600000002000000
5600000002000000
5600000002000000
-
{c=>0,a=>-29,b=>1,d=>1}
e3ffffff05000000
e3ffffff05000000
e3ffffff05000000
e3ffffff05000000
-
{c=>0,a=>97,b=>1,d=>0}
6100000001000000
6100000001000000
6100000001000000
6100000001000000
-
{c=>1,a=>92,b=>1,d=>0}
5c00000003000000
5c00000003000000
5c00000003000000
5c00000003000000
-
{c=>1,a=>-52,b=>0,d=>1}
ccffffff06000000
ccffffff06000000
ccffffff06000000
ccffffff06000000
=
struct uint {
  long a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
  unsigned int   e:1;
};
-
{e=>1,c=>1,a=>46,b=>1,d=>0}
2e0000000b000000
2e0000000b000000
2e0000000b000000
2e0000000b000000
-
{e=>0,c=>1,a=>6,b=>0,d=>1}
0600000006000000
0600000006000000
0600000006000000
0600000006000000
-
{e=>0,c=>1,a=>-88,b=>1,d=>0}
a8ffffff03000000
a8ffffff03000000
a8ffffff03000000
a8ffffff03000000
-
{e=>1,c=>1,a=>61,b=>0,d=>0}
3d0000000a000000
3d0000000a000000
3d0000000a000000
3d0000000a000000
-
{e=>1,c=>1,a=>-91,b=>0,d=>1}
a5ffffff0e000000
a5ffffff0e000000
a5ffffff0e000000
a5ffffff0e000000
=
struct uint {
  long a;
  unsigned int   b:1;
  unsigned int   c:1;
  unsigned int   d:1;
  unsigned int   e:1;
  unsigned char  f;
};
-
{e=>1,c=>0,a=>0,b=>0,d=>0,f=>3}
000000000800000003
00000000080000000300
000000000800000003000000
000000000800000003000000
-
{e=>1,c=>0,a=>-78,b=>1,d=>0,f=>176}
b2ffffff09000000b0
b2ffffff09000000b000
b2ffffff09000000b0000000
b2ffffff09000000b0000000
-
{e=>0,c=>1,a=>-121,b=>1,d=>1,f=>153}
87ffffff0700000099
87ffffff070000009900
87ffffff0700000099000000
87ffffff0700000099000000
-
{e=>0,c=>1,a=>-50,b=>1,d=>0,f=>143}
ceffffff030000008f
ceffffff030000008f00
ceffffff030000008f000000
ceffffff030000008f000000
-
{e=>0,c=>1,a=>-106,b=>0,d=>0,f=>229}
96ffffff02000000e5
96ffffff02000000e500
96ffffff02000000e5000000
96ffffff02000000e5000000
=
struct ulong {
  unsigned long  a:1;
};
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>1}
01000000
01000000
01000000
01000000
-
{a=>0}
00000000
00000000
00000000
00000000
=
struct ulong {
  unsigned long  a:1;
  unsigned long  b:1;
};
-
{a=>0,b=>0}
00000000
00000000
00000000
00000000
-
{a=>1,b=>1}
03000000
03000000
03000000
03000000
-
{a=>1,b=>0}
01000000
01000000
01000000
01000000
-
{a=>1,b=>1}
03000000
03000000
03000000
03000000
-
{a=>0,b=>1}
02000000
02000000
02000000
02000000
=
struct ulong {
  unsigned long  a:1;
  unsigned long  b:1;
  unsigned long  c:1;
};
-
{c=>0,a=>0,b=>0}
00000000
00000000
00000000
00000000
-
{c=>0,a=>1,b=>1}
03000000
03000000
03000000
03000000
-
{c=>0,a=>0,b=>1}
02000000
02000000
02000000
02000000
-
{c=>1,a=>0,b=>1}
06000000
06000000
06000000
06000000
-
{c=>1,a=>0,b=>0}
04000000
04000000
04000000
04000000
=
struct ulong {
  unsigned long  a:1;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
};
-
{c=>1,a=>1,b=>1,d=>0}
07000000
07000000
07000000
07000000
-
{c=>1,a=>0,b=>0,d=>0}
04000000
04000000
04000000
04000000
-
{c=>0,a=>1,b=>1,d=>1}
0b000000
0b000000
0b000000
0b000000
-
{c=>0,a=>1,b=>0,d=>0}
01000000
01000000
01000000
01000000
-
{c=>1,a=>0,b=>1,d=>0}
06000000
06000000
06000000
06000000
=
struct ulong {
  unsigned long  a:1;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
  unsigned char  e;
};
-
{e=>171,c=>0,a=>1,b=>0,d=>0}
01000000ab
01000000ab00
01000000ab000000
01000000ab000000
-
{e=>112,c=>0,a=>0,b=>0,d=>0}
0000000070
000000007000
0000000070000000
0000000070000000
-
{e=>62,c=>0,a=>0,b=>0,d=>1}
080000003e
080000003e00
080000003e000000
080000003e000000
-
{e=>210,c=>0,a=>0,b=>1,d=>1}
0a000000d2
0a000000d200
0a000000d2000000
0a000000d2000000
-
{e=>159,c=>1,a=>0,b=>1,d=>1}
0e0000009f
0e0000009f00
0e0000009f000000
0e0000009f000000
=
struct ulong {
  char a;
  unsigned long  b:1;
};
-
{a=>-121,b=>1}
8701000000
870001000000
8700000001000000
8700000001000000
-
{a=>50,b=>1}
3201000000
320001000000
3200000001000000
3200000001000000
-
{a=>-89,b=>1}
a701000000
a70001000000
a700000001000000
a700000001000000
-
{a=>92,b=>0}
5c00000000
5c0000000000
5c00000000000000
5c00000000000000
-
{a=>-41,b=>0}
d700000000
d70000000000
d700000000000000
d700000000000000
=
struct ulong {
  char a;
  unsigned long  b:1;
  unsigned long  c:1;
};
-
{c=>1,a=>-46,b=>1}
d203000000
d20003000000
d200000003000000
d200000003000000
-
{c=>0,a=>-85,b=>0}
ab00000000
ab0000000000
ab00000000000000
ab00000000000000
-
{c=>0,a=>78,b=>0}
4e00000000
4e0000000000
4e00000000000000
4e00000000000000
-
{c=>0,a=>-50,b=>0}
ce00000000
ce0000000000
ce00000000000000
ce00000000000000
-
{c=>1,a=>-57,b=>1}
c703000000
c70003000000
c700000003000000
c700000003000000
=
struct ulong {
  char a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
};
-
{c=>0,a=>-7,b=>0,d=>1}
f904000000
f90004000000
f900000004000000
f900000004000000
-
{c=>0,a=>69,b=>0,d=>0}
4500000000
450000000000
4500000000000000
4500000000000000
-
{c=>1,a=>78,b=>1,d=>1}
4e07000000
4e0007000000
4e00000007000000
4e00000007000000
-
{c=>1,a=>19,b=>0,d=>0}
1302000000
130002000000
1300000002000000
1300000002000000
-
{c=>1,a=>-18,b=>1,d=>0}
ee03000000
ee0003000000
ee00000003000000
ee00000003000000
=
struct ulong {
  char a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
  unsigned long  e:1;
};
-
{e=>1,c=>0,a=>-82,b=>1,d=>1}
ae0d000000
ae000d000000
ae0000000d000000
ae0000000d000000
-
{e=>1,c=>1,a=>125,b=>0,d=>1}
7d0e000000
7d000e000000
7d0000000e000000
7d0000000e000000
-
{e=>1,c=>1,a=>-119,b=>0,d=>1}
890e000000
89000e000000
890000000e000000
890000000e000000
-
{e=>1,c=>1,a=>39,b=>0,d=>1}
270e000000
27000e000000
270000000e000000
270000000e000000
-
{e=>0,c=>1,a=>14,b=>0,d=>0}
0e02000000
0e0002000000
0e00000002000000
0e00000002000000
=
struct ulong {
  char a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
  unsigned long  e:1;
  unsigned char  f;
};
-
{e=>1,c=>0,a=>-3,b=>1,d=>0,f=>197}
fd09000000c5
fd0009000000c500
fd00000009000000c5000000
fd00000009000000c5000000
-
{e=>0,c=>1,a=>87,b=>0,d=>0,f=>225}
5702000000e1
570002000000e100
5700000002000000e1000000
5700000002000000e1000000
-
{e=>0,c=>1,a=>-120,b=>1,d=>1,f=>123}
88070000007b
8800070000007b00
88000000070000007b000000
88000000070000007b000000
-
{e=>1,c=>0,a=>-101,b=>0,d=>0,f=>120}
9b0800000078
9b00080000007800
9b0000000800000078000000
9b0000000800000078000000
-
{e=>1,c=>1,a=>13,b=>0,d=>1,f=>245}
0d0e000000f5
0d000e000000f500
0d0000000e000000f5000000
0d0000000e000000f5000000
=
struct ulong {
  short a;
  unsigned long  b:1;
};
-
{a=>-34,b=>1}
deff01000000
deff01000000
deff000001000000
deff000001000000
-
{a=>-97,b=>1}
9fff01000000
9fff01000000
9fff000001000000
9fff000001000000
-
{a=>125,b=>0}
7d0000000000
7d0000000000
7d00000000000000
7d00000000000000
-
{a=>-4,b=>1}
fcff01000000
fcff01000000
fcff000001000000
fcff000001000000
-
{a=>-46,b=>0}
d2ff00000000
d2ff00000000
d2ff000000000000
d2ff000000000000
=
struct ulong {
  short a;
  unsigned long  b:1;
  unsigned long  c:1;
};
-
{c=>0,a=>54,b=>1}
360001000000
360001000000
3600000001000000
3600000001000000
-
{c=>1,a=>25,b=>1}
190003000000
190003000000
1900000003000000
1900000003000000
-
{c=>1,a=>-112,b=>1}
90ff03000000
90ff03000000
90ff000003000000
90ff000003000000
-
{c=>0,a=>53,b=>1}
350001000000
350001000000
3500000001000000
3500000001000000
-
{c=>0,a=>-72,b=>0}
b8ff00000000
b8ff00000000
b8ff000000000000
b8ff000000000000
=
struct ulong {
  short a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
};
-
{c=>0,a=>-37,b=>0,d=>1}
dbff04000000
dbff04000000
dbff000004000000
dbff000004000000
-
{c=>1,a=>59,b=>0,d=>1}
3b0006000000
3b0006000000
3b00000006000000
3b00000006000000
-
{c=>1,a=>-10,b=>1,d=>1}
f6ff07000000
f6ff07000000
f6ff000007000000
f6ff000007000000
-
{c=>0,a=>-39,b=>1,d=>0}
d9ff01000000
d9ff01000000
d9ff000001000000
d9ff000001000000
-
{c=>0,a=>26,b=>0,d=>1}
1a0004000000
1a0004000000
1a00000004000000
1a00000004000000
=
struct ulong {
  short a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
  unsigned long  e:1;
};
-
{e=>1,c=>1,a=>77,b=>1,d=>0}
4d000b000000
4d000b000000
4d0000000b000000
4d0000000b000000
-
{e=>0,c=>0,a=>71,b=>1,d=>1}
470005000000
470005000000
4700000005000000
4700000005000000
-
{e=>1,c=>0,a=>12,b=>1,d=>0}
0c0009000000
0c0009000000
0c00000009000000
0c00000009000000
-
{e=>1,c=>1,a=>-120,b=>1,d=>1}
88ff0f000000
88ff0f000000
88ff00000f000000
88ff00000f000000
-
{e=>0,c=>0,a=>-106,b=>0,d=>1}
96ff04000000
96ff04000000
96ff000004000000
96ff000004000000
=
struct ulong {
  short a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
  unsigned long  e:1;
  unsigned char  f;
};
-
{e=>1,c=>1,a=>93,b=>1,d=>0,f=>203}
5d000b000000cb
5d000b000000cb00
5d0000000b000000cb000000
5d0000000b000000cb000000
-
{e=>1,c=>1,a=>-61,b=>1,d=>0,f=>222}
c3ff0b000000de
c3ff0b000000de00
c3ff00000b000000de000000
c3ff00000b000000de000000
-
{e=>0,c=>1,a=>-4,b=>0,d=>0,f=>177}
fcff02000000b1
fcff02000000b100
fcff000002000000b1000000
fcff000002000000b1000000
-
{e=>0,c=>1,a=>-34,b=>1,d=>1,f=>92}
deff070000005c
deff070000005c00
deff0000070000005c000000
deff0000070000005c000000
-
{e=>0,c=>1,a=>6,b=>0,d=>1,f=>117}
06000600000075
0600060000007500
060000000600000075000000
060000000600000075000000
=
struct ulong {
  int a;
  unsigned long  b:1;
};
-
{a=>20,b=>1}
1400000001000000
1400000001000000
1400000001000000
1400000001000000
-
{a=>-70,b=>1}
baffffff01000000
baffffff01000000
baffffff01000000
baffffff01000000
-
{a=>-124,b=>0}
84ffffff00000000
84ffffff00000000
84ffffff00000000
84ffffff00000000
-
{a=>-106,b=>0}
96ffffff00000000
96ffffff00000000
96ffffff00000000
96ffffff00000000
-
{a=>25,b=>1}
1900000001000000
1900000001000000
1900000001000000
1900000001000000
=
struct ulong {
  int a;
  unsigned long  b:1;
  unsigned long  c:1;
};
-
{c=>1,a=>42,b=>0}
2a00000002000000
2a00000002000000
2a00000002000000
2a00000002000000
-
{c=>1,a=>-120,b=>1}
88ffffff03000000
88ffffff03000000
88ffffff03000000
88ffffff03000000
-
{c=>1,a=>-122,b=>1}
86ffffff03000000
86ffffff03000000
86ffffff03000000
86ffffff03000000
-
{c=>0,a=>-34,b=>0}
deffffff00000000
deffffff00000000
deffffff00000000
deffffff00000000
-
{c=>0,a=>-40,b=>0}
d8ffffff00000000
d8ffffff00000000
d8ffffff00000000
d8ffffff00000000
=
struct ulong {
  int a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
};
-
{c=>0,a=>44,b=>1,d=>0}
2c00000001000000
2c00000001000000
2c00000001000000
2c00000001000000
-
{c=>1,a=>119,b=>1,d=>0}
7700000003000000
7700000003000000
7700000003000000
7700000003000000
-
{c=>1,a=>30,b=>1,d=>0}
1e00000003000000
1e00000003000000
1e00000003000000
1e00000003000000
-
{c=>0,a=>-76,b=>0,d=>0}
b4ffffff00000000
b4ffffff00000000
b4ffffff00000000
b4ffffff00000000
-
{c=>1,a=>71,b=>0,d=>1}
4700000006000000
4700000006000000
4700000006000000
4700000006000000
=
struct ulong {
  int a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
  unsigned long  e:1;
};
-
{e=>0,c=>0,a=>-96,b=>1,d=>0}
a0ffffff01000000
a0ffffff01000000
a0ffffff01000000
a0ffffff01000000
-
{e=>0,c=>0,a=>112,b=>1,d=>0}
7000000001000000
7000000001000000
7000000001000000
7000000001000000
-
{e=>1,c=>0,a=>-48,b=>1,d=>0}
d0ffffff09000000
d0ffffff09000000
d0ffffff09000000
d0ffffff09000000
-
{e=>0,c=>0,a=>101,b=>0,d=>0}
6500000000000000
6500000000000000
6500000000000000
6500000000000000
-
{e=>0,c=>0,a=>113,b=>1,d=>1}
7100000005000000
7100000005000000
7100000005000000
7100000005000000
=
struct ulong {
  int a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
  unsigned long  e:1;
  unsigned char  f;
};
-
{e=>1,c=>1,a=>53,b=>0,d=>1,f=>237}
350000000e000000ed
350000000e000000ed00
350000000e000000ed000000
350000000e000000ed000000
-
{e=>1,c=>0,a=>-64,b=>1,d=>0,f=>197}
c0ffffff09000000c5
c0ffffff09000000c500
c0ffffff09000000c5000000
c0ffffff09000000c5000000
-
{e=>0,c=>1,a=>-88,b=>1,d=>0,f=>178}
a8ffffff03000000b2
a8ffffff03000000b200
a8ffffff03000000b2000000
a8ffffff03000000b2000000
-
{e=>1,c=>1,a=>-104,b=>0,d=>1,f=>185}
98ffffff0e000000b9
98ffffff0e000000b900
98ffffff0e000000b9000000
98ffffff0e000000b9000000
-
{e=>1,c=>1,a=>121,b=>0,d=>1,f=>176}
790000000e000000b0
790000000e000000b000
790000000e000000b0000000
790000000e000000b0000000
=
struct ulong {
  long a;
  unsigned long  b:1;
};
-
{a=>123,b=>0}
7b00000000000000
7b00000000000000
7b00000000000000
7b00000000000000
-
{a=>-51,b=>1}
cdffffff01000000
cdffffff01000000
cdffffff01000000
cdffffff01000000
-
{a=>123,b=>0}
7b00000000000000
7b00000000000000
7b00000000000000
7b00000000000000
-
{a=>-16,b=>1}
f0ffffff01000000
f0ffffff01000000
f0ffffff01000000
f0ffffff01000000
-
{a=>-33,b=>1}
dfffffff01000000
dfffffff01000000
dfffffff01000000
dfffffff01000000
=
struct ulong {
  long a;
  unsigned long  b:1;
  unsigned long  c:1;
};
-
{c=>1,a=>65,b=>1}
4100000003000000
4100000003000000
4100000003000000
4100000003000000
-
{c=>1,a=>108,b=>0}
6c00000002000000
6c00000002000000
6c00000002000000
6c00000002000000
-
{c=>1,a=>-3,b=>1}
fdffffff03000000
fdffffff03000000
fdffffff03000000
fdffffff03000000
-
{c=>0,a=>48,b=>1}
3000000001000000
3000000001000000
3000000001000000
3000000001000000
-
{c=>0,a=>39,b=>0}
2700000000000000
2700000000000000
2700000000000000
2700000000000000
=
struct ulong {
  long a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
};
-
{c=>0,a=>-118,b=>0,d=>1}
8affffff04000000
8affffff04000000
8affffff04000000
8affffff04000000
-
{c=>1,a=>-68,b=>1,d=>1}
bcffffff07000000
bcffffff07000000
bcffffff07000000
bcffffff07000000
-
{c=>0,a=>-88,b=>1,d=>1}
a8ffffff05000000
a8ffffff05000000
a8ffffff05000000
a8ffffff05000000
-
{c=>0,a=>-79,b=>0,d=>1}
b1ffffff04000000
b1ffffff04000000
b1ffffff04000000
b1ffffff04000000
-
{c=>1,a=>-62,b=>0,d=>0}
c2ffffff02000000
c2ffffff02000000
c2ffffff02000000
c2ffffff02000000
=
struct ulong {
  long a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
  unsigned long  e:1;
};
-
{e=>1,c=>1,a=>-102,b=>1,d=>0}
9affffff0b000000
9affffff0b000000
9affffff0b000000
9affffff0b000000
-
{e=>1,c=>0,a=>-99,b=>1,d=>0}
9dffffff09000000
9dffffff09000000
9dffffff09000000
9dffffff09000000
-
{e=>0,c=>0,a=>3,b=>0,d=>0}
0300000000000000
0300000000000000
0300000000000000
0300000000000000
-
{e=>1,c=>0,a=>6,b=>1,d=>0}
0600000009000000
0600000009000000
0600000009000000
0600000009000000
-
{e=>0,c=>1,a=>105,b=>0,d=>0}
6900000002000000
6900000002000000
6900000002000000
6900000002000000
=
struct ulong {
  long a;
  unsigned long  b:1;
  unsigned long  c:1;
  unsigned long  d:1;
  unsigned long  e:1;
  unsigned char  f;
};
-
{e=>1,c=>0,a=>73,b=>1,d=>1,f=>147}
490000000d00000093
490000000d0000009300
490000000d00000093000000
490000000d00000093000000
-
{e=>0,c=>1,a=>9,b=>0,d=>0,f=>160}
0900000002000000a0
0900000002000000a000
0900000002000000a0000000
0900000002000000a0000000
-
{e=>0,c=>1,a=>78,b=>1,d=>1,f=>51}
4e0000000700000033
4e000000070000003300
4e0000000700000033000000
4e0000000700000033000000
-
{e=>1,c=>0,a=>96,b=>1,d=>1,f=>245}
600000000d000000f5
600000000d000000f500
600000000d000000f5000000
600000000d000000f5000000
-
{e=>0,c=>0,a=>101,b=>1,d=>1,f=>35}
650000000500000023
65000000050000002300
650000000500000023000000
650000000500000023000000
=
struct umixed {
  unsigned char  a:1;
};
-
{a=>0}
00
00
00
00
-
{a=>0}
00
00
00
00
-
{a=>0}
00
00
00
00
-
{a=>1}
01
01
01
01
-
{a=>1}
01
01
01
01
=
struct umixed {
  unsigned char  a:1;
  unsigned short b:1;
};
-
{a=>0,b=>0}
000000
00000000
00000000
00000000
-
{a=>0,b=>1}
000100
00000100
00000100
00000100
-
{a=>0,b=>0}
000000
00000000
00000000
00000000
-
{a=>0,b=>1}
000100
00000100
00000100
00000100
-
{a=>1,b=>0}
010000
01000000
01000000
01000000
=
struct umixed {
  unsigned char  a:1;
  unsigned short b:1;
  unsigned int   c:1;
};
-
{c=>0,a=>1,b=>1}
01010000000000
0100010000000000
0100010000000000
0100010000000000
-
{c=>1,a=>0,b=>0}
00000001000000
0000000001000000
0000000001000000
0000000001000000
-
{c=>1,a=>0,b=>1}
00010001000000
0000010001000000
0000010001000000
0000010001000000
-
{c=>0,a=>1,b=>1}
01010000000000
0100010000000000
0100010000000000
0100010000000000
-
{c=>0,a=>0,b=>0}
00000000000000
0000000000000000
0000000000000000
0000000000000000
=
struct umixed {
  unsigned char  a:1;
  unsigned short b:1;
  unsigned int   c:1;
  unsigned long  d:1;
};
-
{c=>1,a=>1,b=>0,d=>1}
01000003000000
0100000003000000
0100000003000000
0100000003000000
-
{c=>0,a=>0,b=>0,d=>1}
00000002000000
0000000002000000
0000000002000000
0000000002000000
-
{c=>1,a=>1,b=>0,d=>1}
01000003000000
0100000003000000
0100000003000000
0100000003000000
-
{c=>0,a=>0,b=>1,d=>0}
00010000000000
0000010000000000
0000010000000000
0000010000000000
-
{c=>0,a=>0,b=>1,d=>1}
00010002000000
0000010002000000
0000010002000000
0000010002000000
=
struct umixed {
  unsigned char  a:1;
  unsigned short b:1;
  unsigned int   c:1;
  unsigned long  d:1;
  unsigned char  e;
};
-
{e=>216,c=>0,a=>1,b=>0,d=>1}
01000002000000d8
0100000002000000d800
0100000002000000d8000000
0100000002000000d8000000
-
{e=>111,c=>0,a=>0,b=>1,d=>0}
000100000000006f
00000100000000006f00
00000100000000006f000000
00000100000000006f000000
-
{e=>156,c=>1,a=>0,b=>0,d=>0}
000000010000009c
00000000010000009c00
00000000010000009c000000
00000000010000009c000000
-
{e=>93,c=>0,a=>0,b=>1,d=>0}
000100000000005d
00000100000000005d00
00000100000000005d000000
00000100000000005d000000
-
{e=>187,c=>0,a=>0,b=>1,d=>0}
00010000000000bb
0000010000000000bb00
0000010000000000bb000000
0000010000000000bb000000
=
struct umixed {
  char a;
  unsigned char  b:1;
};
-
{a=>122,b=>0}
7a00
7a00
7a00
7a00
-
{a=>102,b=>0}
6600
6600
6600
6600
-
{a=>105,b=>0}
6900
6900
6900
6900
-
{a=>6,b=>1}
0601
0601
0601
0601
-
{a=>110,b=>0}
6e00
6e00
6e00
6e00
=
struct umixed {
  char a;
  unsigned char  b:1;
  unsigned short c:1;
};
-
{c=>0,a=>-64,b=>0}
c0000000
c0000000
c0000000
c0000000
-
{c=>0,a=>92,b=>1}
5c010000
5c010000
5c010000
5c010000
-
{c=>1,a=>-60,b=>1}
c4010100
c4010100
c4010100
c4010100
-
{c=>0,a=>0,b=>0}
00000000
00000000
00000000
00000000
-
{c=>0,a=>-90,b=>1}
a6010000
a6010000
a6010000
a6010000
=
struct umixed {
  char a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
};
-
{c=>1,a=>43,b=>0,d=>1}
2b00010001000000
2b00010001000000
2b00010001000000
2b00010001000000
-
{c=>0,a=>65,b=>1,d=>1}
4101000001000000
4101000001000000
4101000001000000
4101000001000000
-
{c=>1,a=>-28,b=>0,d=>1}
e400010001000000
e400010001000000
e400010001000000
e400010001000000
-
{c=>1,a=>-67,b=>1,d=>0}
bd01010000000000
bd01010000000000
bd01010000000000
bd01010000000000
-
{c=>1,a=>-56,b=>0,d=>1}
c800010001000000
c800010001000000
c800010001000000
c800010001000000
=
struct umixed {
  char a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
  unsigned long  e:1;
};
-
{e=>1,c=>1,a=>-36,b=>0,d=>0}
dc00010002000000
dc00010002000000
dc00010002000000
dc00010002000000
-
{e=>1,c=>1,a=>-40,b=>1,d=>1}
d801010003000000
d801010003000000
d801010003000000
d801010003000000
-
{e=>0,c=>1,a=>56,b=>0,d=>1}
3800010001000000
3800010001000000
3800010001000000
3800010001000000
-
{e=>0,c=>1,a=>18,b=>1,d=>0}
1201010000000000
1201010000000000
1201010000000000
1201010000000000
-
{e=>1,c=>0,a=>-68,b=>1,d=>0}
bc01000002000000
bc01000002000000
bc01000002000000
bc01000002000000
=
struct umixed {
  char a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
  unsigned long  e:1;
  unsigned char  f;
};
-
{e=>1,c=>1,a=>77,b=>0,d=>0,f=>112}
4d0001000200000070
4d000100020000007000
4d0001000200000070000000
4d0001000200000070000000
-
{e=>1,c=>0,a=>115,b=>0,d=>1,f=>9}
730000000300000009
73000000030000000900
730000000300000009000000
730000000300000009000000
-
{e=>0,c=>0,a=>-25,b=>0,d=>0,f=>91}
e7000000000000005b
e7000000000000005b00
e7000000000000005b000000
e7000000000000005b000000
-
{e=>0,c=>0,a=>-68,b=>1,d=>0,f=>5}
bc0100000000000005
bc010000000000000500
bc0100000000000005000000
bc0100000000000005000000
-
{e=>0,c=>1,a=>86,b=>0,d=>0,f=>30}
56000100000000001e
56000100000000001e00
56000100000000001e000000
56000100000000001e000000
=
struct umixed {
  short a;
  unsigned char  b:1;
};
-
{a=>49,b=>0}
310000
31000000
31000000
31000000
-
{a=>84,b=>1}
540001
54000100
54000100
54000100
-
{a=>-73,b=>0}
b7ff00
b7ff0000
b7ff0000
b7ff0000
-
{a=>92,b=>0}
5c0000
5c000000
5c000000
5c000000
-
{a=>76,b=>0}
4c0000
4c000000
4c000000
4c000000
=
struct umixed {
  short a;
  unsigned char  b:1;
  unsigned short c:1;
};
-
{c=>1,a=>-69,b=>0}
bbff000100
bbff00000100
bbff00000100
bbff00000100
-
{c=>1,a=>103,b=>0}
6700000100
670000000100
670000000100
670000000100
-
{c=>0,a=>-68,b=>0}
bcff000000
bcff00000000
bcff00000000
bcff00000000
-
{c=>0,a=>-31,b=>0}
e1ff000000
e1ff00000000
e1ff00000000
e1ff00000000
-
{c=>0,a=>87,b=>1}
5700010000
570001000000
570001000000
570001000000
=
struct umixed {
  short a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
};
-
{c=>0,a=>-26,b=>1,d=>0}
e6ff01000000000000
e6ff0100000000000000
e6ff01000000000000000000
e6ff01000000000000000000
-
{c=>1,a=>41,b=>0,d=>1}
290000010001000000
29000000010001000000
290000000100000001000000
290000000100000001000000
-
{c=>0,a=>47,b=>1,d=>1}
2f0001000001000000
2f000100000001000000
2f0001000000000001000000
2f0001000000000001000000
-
{c=>0,a=>-115,b=>0,d=>0}
8dff00000000000000
8dff0000000000000000
8dff00000000000000000000
8dff00000000000000000000
-
{c=>1,a=>16,b=>1,d=>0}
100001010000000000
10000100010000000000
100001000100000000000000
100001000100000000000000
=
struct umixed {
  short a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
  unsigned long  e:1;
};
-
{e=>1,c=>1,a=>-24,b=>0,d=>0}
e8ff00010002000000
e8ff0000010002000000
e8ff00000100000002000000
e8ff00000100000002000000
-
{e=>1,c=>1,a=>-4,b=>1,d=>0}
fcff01010002000000
fcff0100010002000000
fcff01000100000002000000
fcff01000100000002000000
-
{e=>0,c=>0,a=>-80,b=>1,d=>0}
b0ff01000000000000
b0ff0100000000000000
b0ff01000000000000000000
b0ff01000000000000000000
-
{e=>0,c=>0,a=>18,b=>1,d=>0}
120001000000000000
12000100000000000000
120001000000000000000000
120001000000000000000000
-
{e=>0,c=>0,a=>-46,b=>1,d=>0}
d2ff01000000000000
d2ff0100000000000000
d2ff01000000000000000000
d2ff01000000000000000000
=
struct umixed {
  short a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
  unsigned long  e:1;
  unsigned char  f;
};
-
{e=>1,c=>1,a=>5,b=>0,d=>0,f=>113}
05000001000200000071
050000000100020000007100
05000000010000000200000071000000
05000000010000000200000071000000
-
{e=>0,c=>0,a=>67,b=>1,d=>1,f=>126}
4300010000010000007e
430001000000010000007e00
4300010000000000010000007e000000
4300010000000000010000007e000000
-
{e=>0,c=>0,a=>49,b=>0,d=>1,f=>165}
310000000001000000a5
31000000000001000000a500
310000000000000001000000a5000000
310000000000000001000000a5000000
-
{e=>1,c=>0,a=>0,b=>0,d=>1,f=>40}
00000000000300000028
000000000000030000002800
00000000000000000300000028000000
00000000000000000300000028000000
-
{e=>0,c=>1,a=>66,b=>0,d=>1,f=>177}
420000010001000000b1
42000000010001000000b100
420000000100000001000000b1000000
420000000100000001000000b1000000
=
struct umixed {
  int a;
  unsigned char  b:1;
};
-
{a=>-94,b=>0}
a2ffffff00
a2ffffff0000
a2ffffff00000000
a2ffffff00000000
-
{a=>-14,b=>0}
f2ffffff00
f2ffffff0000
f2ffffff00000000
f2ffffff00000000
-
{a=>-40,b=>0}
d8ffffff00
d8ffffff0000
d8ffffff00000000
d8ffffff00000000
-
{a=>89,b=>0}
5900000000
590000000000
5900000000000000
5900000000000000
-
{a=>-2,b=>1}
feffffff01
feffffff0100
feffffff01000000
feffffff01000000
=
struct umixed {
  int a;
  unsigned char  b:1;
  unsigned short c:1;
};
-
{c=>0,a=>114,b=>1}
72000000010000
7200000001000000
7200000001000000
7200000001000000
-
{c=>1,a=>-68,b=>1}
bcffffff010100
bcffffff01000100
bcffffff01000100
bcffffff01000100
-
{c=>0,a=>60,b=>1}
3c000000010000
3c00000001000000
3c00000001000000
3c00000001000000
-
{c=>0,a=>-105,b=>1}
97ffffff010000
97ffffff01000000
97ffffff01000000
97ffffff01000000
-
{c=>1,a=>-90,b=>0}
a6ffffff000100
a6ffffff00000100
a6ffffff00000100
a6ffffff00000100
=
struct umixed {
  int a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
};
-
{c=>1,a=>44,b=>0,d=>1}
2c00000000010001000000
2c0000000000010001000000
2c0000000000010001000000
2c0000000000010001000000
-
{c=>1,a=>-90,b=>0,d=>0}
a6ffffff00010000000000
a6ffffff0000010000000000
a6ffffff0000010000000000
a6ffffff0000010000000000
-
{c=>1,a=>-11,b=>0,d=>0}
f5ffffff00010000000000
f5ffffff0000010000000000
f5ffffff0000010000000000
f5ffffff0000010000000000
-
{c=>1,a=>18,b=>1,d=>1}
1200000001010001000000
120000000100010001000000
120000000100010001000000
120000000100010001000000
-
{c=>0,a=>-25,b=>0,d=>0}
e7ffffff00000000000000
e7ffffff0000000000000000
e7ffffff0000000000000000
e7ffffff0000000000000000
=
struct umixed {
  int a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
  unsigned long  e:1;
};
-
{e=>0,c=>0,a=>-47,b=>1,d=>0}
d1ffffff01000000000000
d1ffffff0100000000000000
d1ffffff0100000000000000
d1ffffff0100000000000000
-
{e=>0,c=>1,a=>-12,b=>0,d=>1}
f4ffffff00010001000000
f4ffffff0000010001000000
f4ffffff0000010001000000
f4ffffff0000010001000000
-
{e=>1,c=>1,a=>-74,b=>1,d=>0}
b6ffffff01010002000000
b6ffffff0100010002000000
b6ffffff0100010002000000
b6ffffff0100010002000000
-
{e=>1,c=>1,a=>-49,b=>1,d=>0}
cfffffff01010002000000
cfffffff0100010002000000
cfffffff0100010002000000
cfffffff0100010002000000
-
{e=>1,c=>1,a=>61,b=>1,d=>0}
3d00000001010002000000
3d0000000100010002000000
3d0000000100010002000000
3d0000000100010002000000
=
struct umixed {
  int a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
  unsigned long  e:1;
  unsigned char  f;
};
-
{e=>1,c=>1,a=>-19,b=>0,d=>0,f=>112}
edffffff0001000200000070
edffffff00000100020000007000
edffffff000001000200000070000000
edffffff000001000200000070000000
-
{e=>1,c=>0,a=>-74,b=>1,d=>0,f=>149}
b6ffffff0100000200000095
b6ffffff01000000020000009500
b6ffffff010000000200000095000000
b6ffffff010000000200000095000000
-
{e=>0,c=>1,a=>-124,b=>1,d=>1,f=>78}
84ffffff010100010000004e
84ffffff01000100010000004e00
84ffffff01000100010000004e000000
84ffffff01000100010000004e000000
-
{e=>1,c=>0,a=>-25,b=>0,d=>0,f=>222}
e7ffffff00000002000000de
e7ffffff0000000002000000de00
e7ffffff0000000002000000de000000
e7ffffff0000000002000000de000000
-
{e=>0,c=>0,a=>127,b=>1,d=>0,f=>81}
7f0000000100000000000051
7f00000001000000000000005100
7f000000010000000000000051000000
7f000000010000000000000051000000
=
struct umixed {
  long a;
  unsigned char  b:1;
};
-
{a=>127,b=>0}
7f00000000
7f0000000000
7f00000000000000
7f00000000000000
-
{a=>66,b=>1}
4200000001
420000000100
4200000001000000
4200000001000000
-
{a=>13,b=>1}
0d00000001
0d0000000100
0d00000001000000
0d00000001000000
-
{a=>114,b=>0}
7200000000
720000000000
7200000000000000
7200000000000000
-
{a=>-73,b=>1}
b7ffffff01
b7ffffff0100
b7ffffff01000000
b7ffffff01000000
=
struct umixed {
  long a;
  unsigned char  b:1;
  unsigned short c:1;
};
-
{c=>1,a=>105,b=>0}
69000000000100
6900000000000100
6900000000000100
6900000000000100
-
{c=>1,a=>-8,b=>0}
f8ffffff000100
f8ffffff00000100
f8ffffff00000100
f8ffffff00000100
-
{c=>0,a=>5,b=>0}
05000000000000
0500000000000000
0500000000000000
0500000000000000
-
{c=>1,a=>-123,b=>0}
85ffffff000100
85ffffff00000100
85ffffff00000100
85ffffff00000100
-
{c=>1,a=>103,b=>1}
67000000010100
6700000001000100
6700000001000100
6700000001000100
=
struct umixed {
  long a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
};
-
{c=>1,a=>-17,b=>1,d=>0}
efffffff01010000000000
efffffff0100010000000000
efffffff0100010000000000
efffffff0100010000000000
-
{c=>1,a=>-127,b=>1,d=>0}
81ffffff01010000000000
81ffffff0100010000000000
81ffffff0100010000000000
81ffffff0100010000000000
-
{c=>1,a=>102,b=>1,d=>1}
6600000001010001000000
660000000100010001000000
660000000100010001000000
660000000100010001000000
-
{c=>1,a=>-88,b=>1,d=>1}
a8ffffff01010001000000
a8ffffff0100010001000000
a8ffffff0100010001000000
a8ffffff0100010001000000
-
{c=>1,a=>15,b=>1,d=>1}
0f00000001010001000000
0f0000000100010001000000
0f0000000100010001000000
0f0000000100010001000000
=
struct umixed {
  long a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
  unsigned long  e:1;
};
-
{e=>1,c=>1,a=>118,b=>1,d=>1}
7600000001010003000000
760000000100010003000000
760000000100010003000000
760000000100010003000000
-
{e=>1,c=>0,a=>-90,b=>0,d=>1}
a6ffffff00000003000000
a6ffffff0000000003000000
a6ffffff0000000003000000
a6ffffff0000000003000000
-
{e=>0,c=>0,a=>103,b=>0,d=>0}
6700000000000000000000
670000000000000000000000
670000000000000000000000
670000000000000000000000
-
{e=>0,c=>1,a=>-84,b=>0,d=>1}
acffffff00010001000000
acffffff0000010001000000
acffffff0000010001000000
acffffff0000010001000000
-
{e=>1,c=>1,a=>92,b=>0,d=>0}
5c00000000010002000000
5c0000000000010002000000
5c0000000000010002000000
5c0000000000010002000000
=
struct umixed {
  long a;
  unsigned char  b:1;
  unsigned short c:1;
  unsigned int   d:1;
  unsigned long  e:1;
  unsigned char  f;
};
-
{e=>1,c=>0,a=>51,b=>0,d=>0,f=>187}
3300000000000002000000bb
330000000000000002000000bb00
330000000000000002000000bb000000
330000000000000002000000bb000000
-
{e=>0,c=>1,a=>-115,b=>1,d=>1,f=>46}
8dffffff010100010000002e
8dffffff01000100010000002e00
8dffffff01000100010000002e000000
8dffffff01000100010000002e000000
-
{e=>1,c=>0,a=>105,b=>0,d=>0,f=>59}
69000000000000020000003b
6900000000000000020000003b00
6900000000000000020000003b000000
6900000000000000020000003b000000
-
{e=>1,c=>1,a=>-128,b=>0,d=>1,f=>86}
80ffffff0001000300000056
80ffffff00000100030000005600
80ffffff000001000300000056000000
80ffffff000001000300000056000000
-
{e=>1,c=>1,a=>24,b=>1,d=>1,f=>117}
180000000101000300000075
1800000001000100030000007500
18000000010001000300000075000000
18000000010001000300000075000000
=
struct smixed {
  signed char  a:1;
};
-
{a=>-1}
01
01
01
01
-
{a=>-1}
01
01
01
01
-
{a=>-1}
01
01
01
01
-
{a=>-1}
01
01
01
01
-
{a=>-1}
01
01
01
01
=
struct smixed {
  signed char  a:1;
  signed short b:1;
};
-
{a=>0,b=>0}
000000
00000000
00000000
00000000
-
{a=>-1,b=>0}
010000
01000000
01000000
01000000
-
{a=>0,b=>-1}
000100
00000100
00000100
00000100
-
{a=>0,b=>-1}
000100
00000100
00000100
00000100
-
{a=>0,b=>-1}
000100
00000100
00000100
00000100
=
struct smixed {
  signed char  a:1;
  signed short b:1;
  signed int   c:1;
};
-
{c=>0,a=>0,b=>-1}
00010000000000
0000010000000000
0000010000000000
0000010000000000
-
{c=>-1,a=>-1,b=>0}
01000001000000
0100000001000000
0100000001000000
0100000001000000
-
{c=>0,a=>0,b=>-1}
00010000000000
0000010000000000
0000010000000000
0000010000000000
-
{c=>-1,a=>0,b=>0}
00000001000000
0000000001000000
0000000001000000
0000000001000000
-
{c=>0,a=>0,b=>0}
00000000000000
0000000000000000
0000000000000000
0000000000000000
=
struct smixed {
  signed char  a:1;
  signed short b:1;
  signed int   c:1;
  signed long  d:1;
};
-
{c=>-1,a=>-1,b=>-1,d=>-1}
01010003000000
0100010003000000
0100010003000000
0100010003000000
-
{c=>0,a=>-1,b=>0,d=>0}
01000000000000
0100000000000000
0100000000000000
0100000000000000
-
{c=>-1,a=>0,b=>-1,d=>-1}
00010003000000
0000010003000000
0000010003000000
0000010003000000
-
{c=>-1,a=>-1,b=>0,d=>0}
01000001000000
0100000001000000
0100000001000000
0100000001000000
-
{c=>0,a=>-1,b=>0,d=>-1}
01000002000000
0100000002000000
0100000002000000
0100000002000000
=
struct smixed {
  signed char  a:1;
  signed short b:1;
  signed int   c:1;
  signed long  d:1;
  signed int   e;
};
-
{e=>-8,c=>0,a=>-1,b=>0,d=>-1}
01000002000000f8ffffff
0100000002000000f8ffffff
0100000002000000f8ffffff
0100000002000000f8ffffff
-
{e=>93,c=>-1,a=>0,b=>-1,d=>0}
000100010000005d000000
00000100010000005d000000
00000100010000005d000000
00000100010000005d000000
-
{e=>98,c=>-1,a=>-1,b=>-1,d=>-1}
0101000300000062000000
010001000300000062000000
010001000300000062000000
010001000300000062000000
-
{e=>-79,c=>0,a=>0,b=>-1,d=>-1}
00010002000000b1ffffff
0000010002000000b1ffffff
0000010002000000b1ffffff
0000010002000000b1ffffff
-
{e=>-60,c=>-1,a=>0,b=>0,d=>-1}
00000003000000c4ffffff
0000000003000000c4ffffff
0000000003000000c4ffffff
0000000003000000c4ffffff
=
struct smixed {
  char a;
  signed char  b:1;
};
-
{a=>28,b=>0}
1c00
1c00
1c00
1c00
-
{a=>-89,b=>-1}
a701
a701
a701
a701
-
{a=>52,b=>-1}
3401
3401
3401
3401
-
{a=>91,b=>0}
5b00
5b00
5b00
5b00
-
{a=>-106,b=>0}
9600
9600
9600
9600
=
struct smixed {
  char a;
  signed char  b:1;
  signed short c:1;
};
-
{c=>-1,a=>-38,b=>0}
da000100
da000100
da000100
da000100
-
{c=>0,a=>-57,b=>-1}
c7010000
c7010000
c7010000
c7010000
-
{c=>-1,a=>-94,b=>-1}
a2010100
a2010100
a2010100
a2010100
-
{c=>-1,a=>107,b=>-1}
6b010100
6b010100
6b010100
6b010100
-
{c=>0,a=>-95,b=>0}
a1000000
a1000000
a1000000
a1000000
=
struct smixed {
  char a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
};
-
{c=>0,a=>35,b=>-1,d=>0}
2301000000000000
2301000000000000
2301000000000000
2301000000000000
-
{c=>-1,a=>-97,b=>-1,d=>0}
9f01010000000000
9f01010000000000
9f01010000000000
9f01010000000000
-
{c=>0,a=>79,b=>-1,d=>-1}
4f01000001000000
4f01000001000000
4f01000001000000
4f01000001000000
-
{c=>0,a=>-2,b=>0,d=>-1}
fe00000001000000
fe00000001000000
fe00000001000000
fe00000001000000
-
{c=>-1,a=>52,b=>-1,d=>0}
3401010000000000
3401010000000000
3401010000000000
3401010000000000
=
struct smixed {
  char a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
  signed long  e:1;
};
-
{e=>0,c=>0,a=>63,b=>-1,d=>-1}
3f01000001000000
3f01000001000000
3f01000001000000
3f01000001000000
-
{e=>-1,c=>0,a=>105,b=>0,d=>-1}
6900000003000000
6900000003000000
6900000003000000
6900000003000000
-
{e=>0,c=>-1,a=>84,b=>0,d=>-1}
5400010001000000
5400010001000000
5400010001000000
5400010001000000
-
{e=>-1,c=>0,a=>40,b=>-1,d=>-1}
2801000003000000
2801000003000000
2801000003000000
2801000003000000
-
{e=>0,c=>0,a=>114,b=>-1,d=>0}
7201000000000000
7201000000000000
7201000000000000
7201000000000000
=
struct smixed {
  char a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
  signed long  e:1;
  signed int   f;
};
-
{e=>-1,c=>-1,a=>-50,b=>-1,d=>-1,f=>37}
ce0101000300000025000000
ce0101000300000025000000
ce0101000300000025000000
ce0101000300000025000000
-
{e=>-1,c=>-1,a=>-111,b=>-1,d=>-1,f=>-13}
9101010003000000f3ffffff
9101010003000000f3ffffff
9101010003000000f3ffffff
9101010003000000f3ffffff
-
{e=>0,c=>0,a=>-7,b=>0,d=>-1,f=>-107}
f90000000100000095ffffff
f90000000100000095ffffff
f90000000100000095ffffff
f90000000100000095ffffff
-
{e=>0,c=>-1,a=>8,b=>0,d=>-1,f=>-10}
0800010001000000f6ffffff
0800010001000000f6ffffff
0800010001000000f6ffffff
0800010001000000f6ffffff
-
{e=>-1,c=>-1,a=>-89,b=>0,d=>-1,f=>127}
a7000100030000007f000000
a7000100030000007f000000
a7000100030000007f000000
a7000100030000007f000000
=
struct smixed {
  short a;
  signed char  b:1;
};
-
{a=>-94,b=>-1}
a2ff01
a2ff0100
a2ff0100
a2ff0100
-
{a=>19,b=>-1}
130001
13000100
13000100
13000100
-
{a=>-68,b=>-1}
bcff01
bcff0100
bcff0100
bcff0100
-
{a=>-102,b=>-1}
9aff01
9aff0100
9aff0100
9aff0100
-
{a=>-111,b=>-1}
91ff01
91ff0100
91ff0100
91ff0100
=
struct smixed {
  short a;
  signed char  b:1;
  signed short c:1;
};
-
{c=>-1,a=>41,b=>0}
2900000100
290000000100
290000000100
290000000100
-
{c=>-1,a=>99,b=>0}
6300000100
630000000100
630000000100
630000000100
-
{c=>-1,a=>-58,b=>0}
c6ff000100
c6ff00000100
c6ff00000100
c6ff00000100
-
{c=>-1,a=>28,b=>0}
1c00000100
1c0000000100
1c0000000100
1c0000000100
-
{c=>-1,a=>-117,b=>0}
8bff000100
8bff00000100
8bff00000100
8bff00000100
=
struct smixed {
  short a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
};
-
{c=>-1,a=>114,b=>-1,d=>-1}
720001010001000000
72000100010001000000
720001000100000001000000
720001000100000001000000
-
{c=>0,a=>-58,b=>-1,d=>-1}
c6ff01000001000000
c6ff0100000001000000
c6ff01000000000001000000
c6ff01000000000001000000
-
{c=>-1,a=>15,b=>-1,d=>0}
0f0001010000000000
0f000100010000000000
0f0001000100000000000000
0f0001000100000000000000
-
{c=>0,a=>-98,b=>0,d=>0}
9eff00000000000000
9eff0000000000000000
9eff00000000000000000000
9eff00000000000000000000
-
{c=>-1,a=>26,b=>0,d=>0}
1a0000010000000000
1a000000010000000000
1a0000000100000000000000
1a0000000100000000000000
=
struct smixed {
  short a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
  signed long  e:1;
};
-
{e=>-1,c=>0,a=>-4,b=>0,d=>0}
fcff00000002000000
fcff0000000002000000
fcff00000000000002000000
fcff00000000000002000000
-
{e=>-1,c=>0,a=>6,b=>0,d=>-1}
060000000003000000
06000000000003000000
060000000000000003000000
060000000000000003000000
-
{e=>0,c=>-1,a=>40,b=>-1,d=>-1}
280001010001000000
28000100010001000000
280001000100000001000000
280001000100000001000000
-
{e=>-1,c=>0,a=>32,b=>-1,d=>0}
200001000002000000
20000100000002000000
200001000000000002000000
200001000000000002000000
-
{e=>0,c=>-1,a=>-119,b=>0,d=>-1}
89ff00010001000000
89ff0000010001000000
89ff00000100000001000000
89ff00000100000001000000
=
struct smixed {
  short a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
  signed long  e:1;
  signed int   f;
};
-
{e=>0,c=>0,a=>-8,b=>-1,d=>-1,f=>-2}
f8ff01000001000000feffffff
f8ff0100000001000000feffffff
f8ff01000000000001000000feffffff
f8ff01000000000001000000feffffff
-
{e=>-1,c=>0,a=>-61,b=>-1,d=>0,f=>-61}
c3ff01000002000000c3ffffff
c3ff0100000002000000c3ffffff
c3ff01000000000002000000c3ffffff
c3ff01000000000002000000c3ffffff
-
{e=>0,c=>0,a=>63,b=>-1,d=>-1,f=>-95}
3f0001000001000000a1ffffff
3f000100000001000000a1ffffff
3f0001000000000001000000a1ffffff
3f0001000000000001000000a1ffffff
-
{e=>0,c=>0,a=>60,b=>0,d=>0,f=>92}
3c00000000000000005c000000
3c0000000000000000005c000000
3c00000000000000000000005c000000
3c00000000000000000000005c000000
-
{e=>0,c=>-1,a=>-67,b=>0,d=>-1,f=>19}
bdff0001000100000013000000
bdff000001000100000013000000
bdff0000010000000100000013000000
bdff0000010000000100000013000000
=
struct smixed {
  int a;
  signed char  b:1;
};
-
{a=>95,b=>-1}
5f00000001
5f0000000100
5f00000001000000
5f00000001000000
-
{a=>50,b=>0}
3200000000
320000000000
3200000000000000
3200000000000000
-
{a=>-64,b=>-1}
c0ffffff01
c0ffffff0100
c0ffffff01000000
c0ffffff01000000
-
{a=>-33,b=>-1}
dfffffff01
dfffffff0100
dfffffff01000000
dfffffff01000000
-
{a=>-44,b=>-1}
d4ffffff01
d4ffffff0100
d4ffffff01000000
d4ffffff01000000
=
struct smixed {
  int a;
  signed char  b:1;
  signed short c:1;
};
-
{c=>0,a=>-115,b=>0}
8dffffff000000
8dffffff00000000
8dffffff00000000
8dffffff00000000
-
{c=>-1,a=>-6,b=>0}
faffffff000100
faffffff00000100
faffffff00000100
faffffff00000100
-
{c=>0,a=>40,b=>-1}
28000000010000
2800000001000000
2800000001000000
2800000001000000
-
{c=>-1,a=>-100,b=>-1}
9cffffff010100
9cffffff01000100
9cffffff01000100
9cffffff01000100
-
{c=>-1,a=>-26,b=>-1}
e6ffffff010100
e6ffffff01000100
e6ffffff01000100
e6ffffff01000100
=
struct smixed {
  int a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
};
-
{c=>0,a=>111,b=>-1,d=>0}
6f00000001000000000000
6f0000000100000000000000
6f0000000100000000000000
6f0000000100000000000000
-
{c=>-1,a=>-15,b=>-1,d=>0}
f1ffffff01010000000000
f1ffffff0100010000000000
f1ffffff0100010000000000
f1ffffff0100010000000000
-
{c=>-1,a=>27,b=>-1,d=>0}
1b00000001010000000000
1b0000000100010000000000
1b0000000100010000000000
1b0000000100010000000000
-
{c=>0,a=>95,b=>-1,d=>0}
5f00000001000000000000
5f0000000100000000000000
5f0000000100000000000000
5f0000000100000000000000
-
{c=>0,a=>40,b=>0,d=>0}
2800000000000000000000
280000000000000000000000
280000000000000000000000
280000000000000000000000
=
struct smixed {
  int a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
  signed long  e:1;
};
-
{e=>0,c=>0,a=>106,b=>0,d=>-1}
6a00000000000001000000
6a0000000000000001000000
6a0000000000000001000000
6a0000000000000001000000
-
{e=>0,c=>0,a=>-60,b=>-1,d=>-1}
c4ffffff01000001000000
c4ffffff0100000001000000
c4ffffff0100000001000000
c4ffffff0100000001000000
-
{e=>-1,c=>-1,a=>21,b=>0,d=>-1}
1500000000010003000000
150000000000010003000000
150000000000010003000000
150000000000010003000000
-
{e=>-1,c=>-1,a=>12,b=>0,d=>0}
0c00000000010002000000
0c0000000000010002000000
0c0000000000010002000000
0c0000000000010002000000
-
{e=>0,c=>-1,a=>-11,b=>-1,d=>-1}
f5ffffff01010001000000
f5ffffff0100010001000000
f5ffffff0100010001000000
f5ffffff0100010001000000
=
struct smixed {
  int a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
  signed long  e:1;
  signed int   f;
};
-
{e=>-1,c=>-1,a=>1,b=>-1,d=>-1,f=>-92}
0100000001010003000000a4ffffff
010000000100010003000000a4ffffff
010000000100010003000000a4ffffff
010000000100010003000000a4ffffff
-
{e=>-1,c=>-1,a=>-79,b=>0,d=>0,f=>47}
b1ffffff000100020000002f000000
b1ffffff00000100020000002f000000
b1ffffff00000100020000002f000000
b1ffffff00000100020000002f000000
-
{e=>-1,c=>-1,a=>81,b=>-1,d=>0,f=>-106}
510000000101000200000096ffffff
51000000010001000200000096ffffff
51000000010001000200000096ffffff
51000000010001000200000096ffffff
-
{e=>0,c=>0,a=>15,b=>0,d=>-1,f=>2}
0f0000000000000100000002000000
0f000000000000000100000002000000
0f000000000000000100000002000000
0f000000000000000100000002000000
-
{e=>0,c=>0,a=>91,b=>-1,d=>0,f=>98}
5b0000000100000000000062000000
5b000000010000000000000062000000
5b000000010000000000000062000000
5b000000010000000000000062000000
=
struct smixed {
  long a;
  signed char  b:1;
};
-
{a=>60,b=>-1}
3c00000001
3c0000000100
3c00000001000000
3c00000001000000
-
{a=>125,b=>-1}
7d00000001
7d0000000100
7d00000001000000
7d00000001000000
-
{a=>-23,b=>-1}
e9ffffff01
e9ffffff0100
e9ffffff01000000
e9ffffff01000000
-
{a=>-14,b=>-1}
f2ffffff01
f2ffffff0100
f2ffffff01000000
f2ffffff01000000
-
{a=>51,b=>0}
3300000000
330000000000
3300000000000000
3300000000000000
=
struct smixed {
  long a;
  signed char  b:1;
  signed short c:1;
};
-
{c=>-1,a=>-105,b=>-1}
97ffffff010100
97ffffff01000100
97ffffff01000100
97ffffff01000100
-
{c=>0,a=>31,b=>0}
1f000000000000
1f00000000000000
1f00000000000000
1f00000000000000
-
{c=>0,a=>43,b=>0}
2b000000000000
2b00000000000000
2b00000000000000
2b00000000000000
-
{c=>0,a=>-128,b=>0}
80ffffff000000
80ffffff00000000
80ffffff00000000
80ffffff00000000
-
{c=>-1,a=>101,b=>0}
65000000000100
6500000000000100
6500000000000100
6500000000000100
=
struct smixed {
  long a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
};
-
{c=>0,a=>18,b=>0,d=>-1}
1200000000000001000000
120000000000000001000000
120000000000000001000000
120000000000000001000000
-
{c=>-1,a=>-93,b=>-1,d=>0}
a3ffffff01010000000000
a3ffffff0100010000000000
a3ffffff0100010000000000
a3ffffff0100010000000000
-
{c=>-1,a=>-110,b=>-1,d=>-1}
92ffffff01010001000000
92ffffff0100010001000000
92ffffff0100010001000000
92ffffff0100010001000000
-
{c=>-1,a=>-52,b=>0,d=>-1}
ccffffff00010001000000
ccffffff0000010001000000
ccffffff0000010001000000
ccffffff0000010001000000
-
{c=>0,a=>120,b=>-1,d=>-1}
7800000001000001000000
780000000100000001000000
780000000100000001000000
780000000100000001000000
=
struct smixed {
  long a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
  signed long  e:1;
};
-
{e=>-1,c=>-1,a=>-121,b=>0,d=>-1}
87ffffff00010003000000
87ffffff0000010003000000
87ffffff0000010003000000
87ffffff0000010003000000
-
{e=>0,c=>0,a=>-86,b=>0,d=>-1}
aaffffff00000001000000
aaffffff0000000001000000
aaffffff0000000001000000
aaffffff0000000001000000
-
{e=>-1,c=>0,a=>115,b=>-1,d=>0}
7300000001000002000000
730000000100000002000000
730000000100000002000000
730000000100000002000000
-
{e=>-1,c=>-1,a=>26,b=>-1,d=>-1}
1a00000001010003000000
1a0000000100010003000000
1a0000000100010003000000
1a0000000100010003000000
-
{e=>-1,c=>-1,a=>-108,b=>-1,d=>-1}
94ffffff01010003000000
94ffffff0100010003000000
94ffffff0100010003000000
94ffffff0100010003000000
=
struct smixed {
  long a;
  signed char  b:1;
  signed short c:1;
  signed int   d:1;
  signed long  e:1;
  signed int   f;
};
-
{e=>-1,c=>-1,a=>26,b=>0,d=>-1,f=>-117}
1a000000000100030000008bffffff
1a00000000000100030000008bffffff
1a00000000000100030000008bffffff
1a00000000000100030000008bffffff
-
{e=>-1,c=>0,a=>-97,b=>0,d=>-1,f=>99}
9fffffff0000000300000063000000
9fffffff000000000300000063000000
9fffffff000000000300000063000000
9fffffff000000000300000063000000
-
{e=>0,c=>-1,a=>-23,b=>-1,d=>0,f=>63}
e9ffffff010100000000003f000000
e9ffffff01000100000000003f000000
e9ffffff01000100000000003f000000
e9ffffff01000100000000003f000000
-
{e=>0,c=>-1,a=>95,b=>0,d=>-1,f=>108}
5f000000000100010000006c000000
5f00000000000100010000006c000000
5f00000000000100010000006c000000
5f00000000000100010000006c000000
-
{e=>-1,c=>0,a=>-97,b=>0,d=>0,f=>86}
9fffffff0000000200000056000000
9fffffff000000000200000056000000
9fffffff000000000200000056000000
9fffffff000000000200000056000000
=
struct mixed {
  unsigned char  a:1;
};
-
{a=>1}
01
01
01
01
-
{a=>0}
00
00
00
00
-
{a=>0}
00
00
00
00
-
{a=>1}
01
01
01
01
-
{a=>0}
00
00
00
00
=
struct mixed {
  unsigned char  a:1;
  signed   char  b:1;
};
-
{a=>0,b=>-1}
02
02
02
02
-
{a=>1,b=>0}
01
01
01
01
-
{a=>0,b=>0}
00
00
00
00
-
{a=>1,b=>0}
01
01
01
01
-
{a=>1,b=>0}
01
01
01
01
=
struct mixed {
  unsigned char  a:1;
  signed   char  b:1;
  unsigned short c:1;
};
-
{c=>1,a=>0,b=>0}
000100
00000100
00000100
00000100
-
{c=>1,a=>1,b=>-1}
030100
03000100
03000100
03000100
-
{c=>1,a=>0,b=>0}
000100
00000100
00000100
00000100
-
{c=>1,a=>1,b=>-1}
030100
03000100
03000100
03000100
-
{c=>1,a=>0,b=>-1}
020100
02000100
02000100
02000100
=
struct mixed {
  unsigned char  a:1;
  signed   char  b:1;
  unsigned short c:1;
  signed   short d:1;
};
-
{c=>0,a=>1,b=>0,d=>-1}
010200
01000200
01000200
01000200
-
{c=>0,a=>1,b=>0,d=>-1}
010200
01000200
01000200
01000200
-
{c=>0,a=>1,b=>-1,d=>0}
030000
03000000
03000000
03000000
-
{c=>1,a=>1,b=>-1,d=>0}
030100
03000100
03000100
03000100
-
{c=>1,a=>0,b=>-1,d=>-1}
020300
02000300
02000300
02000300
=
struct mixed {
  unsigned char  a:1;
  signed   char  b:1;
  unsigned short c:1;
  signed   short d:1;
  unsigned int   e:1;
};
-
{e=>1,c=>1,a=>0,b=>-1,d=>-1}
02030001000000
0200030001000000
0200030001000000
0200030001000000
-
{e=>0,c=>1,a=>1,b=>-1,d=>-1}
03030000000000
0300030000000000
0300030000000000
0300030000000000
-
{e=>1,c=>1,a=>0,b=>0,d=>0}
00010001000000
0000010001000000
0000010001000000
0000010001000000
-
{e=>0,c=>1,a=>1,b=>0,d=>-1}
01030000000000
0100030000000000
0100030000000000
0100030000000000
-
{e=>0,c=>0,a=>1,b=>0,d=>-1}
01020000000000
0100020000000000
0100020000000000
0100020000000000
=
struct mixed {
  unsigned char  a:1;
  signed   char  b:1;
  unsigned short c:1;
  signed   short d:1;
  unsigned int   e:1;
  signed   int   f:1;
};
-
{e=>0,c=>0,a=>0,b=>0,d=>-1,f=>-1}
00020002000000
0000020002000000
0000020002000000
0000020002000000
-
{e=>0,c=>0,a=>1,b=>0,d=>-1,f=>-1}
01020002000000
0100020002000000
0100020002000000
0100020002000000
-
{e=>0,c=>1,a=>0,b=>-1,d=>-1,f=>-1}
02030002000000
0200030002000000
0200030002000000
0200030002000000
-
{e=>1,c=>0,a=>0,b=>-1,d=>-1,f=>0}
02020001000000
0200020001000000
0200020001000000
0200020001000000
-
{e=>0,c=>0,a=>0,b=>0,d=>0,f=>-1}
00000002000000
0000000002000000
0000000002000000
0000000002000000
=
struct mixed {
  unsigned char  a:1;
  signed   char  b:1;
  unsigned short c:1;
  signed   short d:1;
  unsigned int   e:1;
  signed   int   f:1;
  unsigned long  g:1;
};
-
{e=>0,c=>0,a=>0,g=>0,b=>-1,d=>0,f=>0}
02000000000000
0200000000000000
0200000000000000
0200000000000000
-
{e=>1,c=>0,a=>1,g=>0,b=>0,d=>-1,f=>-1}
01020003000000
0100020003000000
0100020003000000
0100020003000000
-
{e=>1,c=>0,a=>1,g=>1,b=>0,d=>0,f=>0}
01000005000000
0100000005000000
0100000005000000
0100000005000000
-
{e=>0,c=>0,a=>1,g=>0,b=>-1,d=>-1,f=>0}
03020000000000
0300020000000000
0300020000000000
0300020000000000
-
{e=>0,c=>1,a=>0,g=>1,b=>-1,d=>0,f=>0}
02010004000000
0200010004000000
0200010004000000
0200010004000000
=
struct mixed {
  unsigned char  a:1;
  signed   char  b:1;
  unsigned short c:1;
  signed   short d:1;
  unsigned int   e:1;
  signed   int   f:1;
  unsigned long  g:1;
  signed   long  h:1;
};
-
{e=>1,a=>1,d=>-1,c=>1,h=>0,b=>-1,g=>1,f=>-1}
03030007000000
0300030007000000
0300030007000000
0300030007000000
-
{e=>0,a=>0,d=>-1,c=>1,h=>0,b=>0,g=>0,f=>0}
00030000000000
0000030000000000
0000030000000000
0000030000000000
-
{e=>1,a=>0,d=>-1,c=>0,h=>-1,b=>0,g=>1,f=>0}
0002000d000000
000002000d000000
000002000d000000
000002000d000000
-
{e=>1,a=>0,d=>-1,c=>0,h=>-1,b=>0,g=>0,f=>0}
00020009000000
0000020009000000
0000020009000000
0000020009000000
-
{e=>1,a=>1,d=>0,c=>1,h=>0,b=>-1,g=>0,f=>0}
03010001000000
0300010001000000
0300010001000000
0300010001000000
=
struct mixed {
  unsigned char  a:1;
  signed   char  b:1;
  unsigned short c:1;
  signed   short d:1;
  unsigned int   e:1;
  signed   int   f:1;
  unsigned long  g:1;
  signed   long  h:1;
  unsigned char  i;
};
-
{e=>1,a=>0,d=>-1,c=>1,h=>-1,b=>-1,g=>0,f=>-1,i=>162}
0203000b000000a2
020003000b000000a200
020003000b000000a2000000
020003000b000000a2000000
-
{e=>1,a=>1,d=>0,c=>0,h=>0,b=>-1,g=>0,f=>0,i=>113}
0300000100000071
03000000010000007100
030000000100000071000000
030000000100000071000000
-
{e=>0,a=>1,d=>0,c=>1,h=>0,b=>0,g=>1,f=>-1,i=>177}
01010006000000b1
0100010006000000b100
0100010006000000b1000000
0100010006000000b1000000
-
{e=>0,a=>1,d=>-1,c=>1,h=>0,b=>0,g=>1,f=>-1,i=>254}
01030006000000fe
0100030006000000fe00
0100030006000000fe000000
0100030006000000fe000000
-
{e=>1,a=>0,d=>-1,c=>0,h=>0,b=>0,g=>0,f=>-1,i=>196}
00020003000000c4
0000020003000000c400
0000020003000000c4000000
0000020003000000c4000000
=
struct mixed {
  char a;
  unsigned char  b:1;
};
-
{a=>59,b=>1}
3b01
3b01
3b01
3b01
-
{a=>126,b=>1}
7e01
7e01
7e01
7e01
-
{a=>58,b=>1}
3a01
3a01
3a01
3a01
-
{a=>84,b=>0}
5400
5400
5400
5400
-
{a=>-59,b=>1}
c501
c501
c501
c501
=
struct mixed {
  char a;
  unsigned char  b:1;
  signed   char  c:1;
};
-
{c=>0,a=>-8,b=>1}
f801
f801
f801
f801
-
{c=>-1,a=>-61,b=>1}
c303
c303
c303
c303
-
{c=>0,a=>38,b=>0}
2600
2600
2600
2600
-
{c=>0,a=>103,b=>1}
6701
6701
6701
6701
-
{c=>0,a=>-74,b=>0}
b600
b600
b600
b600
=
struct mixed {
  char a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
};
-
{c=>-1,a=>-94,b=>0,d=>0}
a2020000
a2020000
a2020000
a2020000
-
{c=>0,a=>18,b=>1,d=>0}
12010000
12010000
12010000
12010000
-
{c=>0,a=>83,b=>1,d=>1}
53010100
53010100
53010100
53010100
-
{c=>-1,a=>41,b=>1,d=>1}
29030100
29030100
29030100
29030100
-
{c=>-1,a=>28,b=>0,d=>1}
1c020100
1c020100
1c020100
1c020100
=
struct mixed {
  char a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
};
-
{e=>0,c=>-1,a=>112,b=>1,d=>0}
70030000
70030000
70030000
70030000
-
{e=>-1,c=>0,a=>72,b=>1,d=>1}
48010300
48010300
48010300
48010300
-
{e=>-1,c=>0,a=>33,b=>0,d=>1}
21000300
21000300
21000300
21000300
-
{e=>-1,c=>-1,a=>57,b=>1,d=>0}
39030200
39030200
39030200
39030200
-
{e=>0,c=>0,a=>99,b=>1,d=>1}
63010100
63010100
63010100
63010100
=
struct mixed {
  char a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
};
-
{e=>0,c=>0,a=>-16,b=>0,d=>0,f=>1}
f000000001000000
f000000001000000
f000000001000000
f000000001000000
-
{e=>0,c=>0,a=>35,b=>0,d=>1,f=>1}
2300010001000000
2300010001000000
2300010001000000
2300010001000000
-
{e=>0,c=>-1,a=>24,b=>1,d=>0,f=>1}
1803000001000000
1803000001000000
1803000001000000
1803000001000000
-
{e=>-1,c=>0,a=>-56,b=>0,d=>1,f=>1}
c800030001000000
c800030001000000
c800030001000000
c800030001000000
-
{e=>0,c=>0,a=>-67,b=>1,d=>0,f=>0}
bd01000000000000
bd01000000000000
bd01000000000000
bd01000000000000
=
struct mixed {
  char a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
};
-
{e=>-1,c=>0,a=>-105,g=>0,b=>0,d=>0,f=>0}
9700020000000000
9700020000000000
9700020000000000
9700020000000000
-
{e=>0,c=>-1,a=>101,g=>-1,b=>0,d=>0,f=>0}
6502000002000000
6502000002000000
6502000002000000
6502000002000000
-
{e=>0,c=>0,a=>-86,g=>-1,b=>0,d=>1,f=>0}
aa00010002000000
aa00010002000000
aa00010002000000
aa00010002000000
-
{e=>0,c=>-1,a=>-47,g=>-1,b=>0,d=>0,f=>0}
d102000002000000
d102000002000000
d102000002000000
d102000002000000
-
{e=>0,c=>0,a=>117,g=>-1,b=>1,d=>0,f=>0}
7501000002000000
7501000002000000
7501000002000000
7501000002000000
=
struct mixed {
  char a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
};
-
{e=>-1,a=>77,d=>0,c=>0,h=>0,b=>1,g=>0,f=>1}
4d01020001000000
4d01020001000000
4d01020001000000
4d01020001000000
-
{e=>-1,a=>-38,d=>1,c=>-1,h=>1,b=>0,g=>0,f=>0}
da02030004000000
da02030004000000
da02030004000000
da02030004000000
-
{e=>-1,a=>-89,d=>0,c=>0,h=>1,b=>1,g=>-1,f=>1}
a701020007000000
a701020007000000
a701020007000000
a701020007000000
-
{e=>0,a=>-55,d=>1,c=>-1,h=>1,b=>1,g=>-1,f=>1}
c903010007000000
c903010007000000
c903010007000000
c903010007000000
-
{e=>0,a=>76,d=>0,c=>-1,h=>0,b=>0,g=>-1,f=>1}
4c02000003000000
4c02000003000000
4c02000003000000
4c02000003000000
=
struct mixed {
  char a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
  signed   long  i:1;
};
-
{e=>0,a=>51,d=>1,c=>0,h=>1,b=>1,g=>-1,f=>0,i=>-1}
330101000e000000
330101000e000000
330101000e000000
330101000e000000
-
{e=>0,a=>101,d=>0,c=>-1,h=>1,b=>0,g=>-1,f=>0,i=>-1}
650200000e000000
650200000e000000
650200000e000000
650200000e000000
-
{e=>0,a=>-74,d=>1,c=>-1,h=>0,b=>0,g=>0,f=>0,i=>0}
b602010000000000
b602010000000000
b602010000000000
b602010000000000
-
{e=>0,a=>124,d=>1,c=>-1,h=>0,b=>1,g=>0,f=>1,i=>-1}
7c03010009000000
7c03010009000000
7c03010009000000
7c03010009000000
-
{e=>-1,a=>24,d=>0,c=>-1,h=>0,b=>1,g=>0,f=>1,i=>0}
1803020001000000
1803020001000000
1803020001000000
1803020001000000
=
struct mixed {
  char a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
  signed   long  i:1;
  unsigned char  j;
};
-
{e=>-1,a=>-115,d=>0,j=>73,c=>-1,h=>1,b=>0,g=>0,f=>0,i=>-1}
8d0202000c00000049
8d0202000c0000004900
8d0202000c00000049000000
8d0202000c00000049000000
-
{e=>0,a=>112,d=>0,j=>186,c=>0,h=>1,b=>0,g=>0,f=>1,i=>0}
7000000005000000ba
7000000005000000ba00
7000000005000000ba000000
7000000005000000ba000000
-
{e=>0,a=>27,d=>0,j=>247,c=>-1,h=>1,b=>1,g=>0,f=>1,i=>0}
1b03000005000000f7
1b03000005000000f700
1b03000005000000f7000000
1b03000005000000f7000000
-
{e=>-1,a=>0,d=>1,j=>68,c=>-1,h=>1,b=>0,g=>0,f=>0,i=>0}
000203000400000044
00020300040000004400
000203000400000044000000
000203000400000044000000
-
{e=>-1,a=>116,d=>0,j=>30,c=>-1,h=>1,b=>0,g=>-1,f=>1,i=>0}
74020200070000001e
74020200070000001e00
74020200070000001e000000
74020200070000001e000000
=
struct mixed {
  short a;
  unsigned char  b:1;
};
-
{a=>43,b=>0}
2b0000
2b000000
2b000000
2b000000
-
{a=>-77,b=>0}
b3ff00
b3ff0000
b3ff0000
b3ff0000
-
{a=>-127,b=>0}
81ff00
81ff0000
81ff0000
81ff0000
-
{a=>-70,b=>0}
baff00
baff0000
baff0000
baff0000
-
{a=>-21,b=>0}
ebff00
ebff0000
ebff0000
ebff0000
=
struct mixed {
  short a;
  unsigned char  b:1;
  signed   char  c:1;
};
-
{c=>0,a=>1,b=>1}
010001
01000100
01000100
01000100
-
{c=>-1,a=>-65,b=>0}
bfff02
bfff0200
bfff0200
bfff0200
-
{c=>0,a=>-122,b=>0}
86ff00
86ff0000
86ff0000
86ff0000
-
{c=>-1,a=>-8,b=>1}
f8ff03
f8ff0300
f8ff0300
f8ff0300
-
{c=>-1,a=>50,b=>1}
320003
32000300
32000300
32000300
=
struct mixed {
  short a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
};
-
{c=>0,a=>24,b=>1,d=>1}
1800010100
180001000100
180001000100
180001000100
-
{c=>0,a=>-41,b=>0,d=>1}
d7ff000100
d7ff00000100
d7ff00000100
d7ff00000100
-
{c=>-1,a=>-82,b=>0,d=>0}
aeff020000
aeff02000000
aeff02000000
aeff02000000
-
{c=>0,a=>124,b=>1,d=>0}
7c00010000
7c0001000000
7c0001000000
7c0001000000
-
{c=>0,a=>-85,b=>0,d=>1}
abff000100
abff00000100
abff00000100
abff00000100
=
struct mixed {
  short a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
};
-
{e=>-1,c=>0,a=>92,b=>1,d=>0}
5c00010200
5c0001000200
5c0001000200
5c0001000200
-
{e=>0,c=>0,a=>104,b=>1,d=>0}
6800010000
680001000000
680001000000
680001000000
-
{e=>-1,c=>-1,a=>-96,b=>1,d=>0}
a0ff030200
a0ff03000200
a0ff03000200
a0ff03000200
-
{e=>0,c=>0,a=>-66,b=>0,d=>1}
beff000100
beff00000100
beff00000100
beff00000100
-
{e=>0,c=>0,a=>126,b=>0,d=>0}
7e00000000
7e0000000000
7e0000000000
7e0000000000
=
struct mixed {
  short a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
};
-
{e=>0,c=>0,a=>-15,b=>1,d=>1,f=>1}
f1ff01010001000000
f1ff0100010001000000
f1ff01000100000001000000
f1ff01000100000001000000
-
{e=>-1,c=>-1,a=>15,b=>0,d=>0,f=>1}
0f0002020001000000
0f000200020001000000
0f0002000200000001000000
0f0002000200000001000000
-
{e=>-1,c=>-1,a=>75,b=>1,d=>1,f=>1}
4b0003030001000000
4b000300030001000000
4b0003000300000001000000
4b0003000300000001000000
-
{e=>0,c=>0,a=>127,b=>0,d=>0,f=>1}
7f0000000001000000
7f000000000001000000
7f0000000000000001000000
7f0000000000000001000000
-
{e=>-1,c=>-1,a=>0,b=>0,d=>0,f=>0}
000002020000000000
00000200020000000000
000002000200000000000000
000002000200000000000000
=
struct mixed {
  short a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
};
-
{e=>-1,c=>0,a=>-96,g=>0,b=>0,d=>1,f=>0}
a0ff00030000000000
a0ff0000030000000000
a0ff00000300000000000000
a0ff00000300000000000000
-
{e=>-1,c=>-1,a=>-116,g=>-1,b=>0,d=>1,f=>1}
8cff02030003000000
8cff0200030003000000
8cff02000300000003000000
8cff02000300000003000000
-
{e=>0,c=>0,a=>16,g=>0,b=>1,d=>0,f=>1}
100001000001000000
10000100000001000000
100001000000000001000000
100001000000000001000000
-
{e=>-1,c=>0,a=>108,g=>-1,b=>1,d=>0,f=>1}
6c0001020003000000
6c000100020003000000
6c0001000200000003000000
6c0001000200000003000000
-
{e=>-1,c=>0,a=>89,g=>0,b=>1,d=>1,f=>0}
590001030000000000
59000100030000000000
590001000300000000000000
590001000300000000000000
=
struct mixed {
  short a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
};
-
{e=>0,a=>-94,d=>1,c=>0,h=>1,b=>0,g=>0,f=>0}
a2ff00010004000000
a2ff0000010004000000
a2ff00000100000004000000
a2ff00000100000004000000
-
{e=>-1,a=>-38,d=>1,c=>0,h=>0,b=>1,g=>-1,f=>1}
daff01030003000000
daff0100030003000000
daff01000300000003000000
daff01000300000003000000
-
{e=>0,a=>-42,d=>0,c=>0,h=>0,b=>0,g=>-1,f=>0}
d6ff00000002000000
d6ff0000000002000000
d6ff00000000000002000000
d6ff00000000000002000000
-
{e=>0,a=>-80,d=>0,c=>0,h=>1,b=>0,g=>0,f=>0}
b0ff00000004000000
b0ff0000000004000000
b0ff00000000000004000000
b0ff00000000000004000000
-
{e=>0,a=>-7,d=>0,c=>0,h=>1,b=>1,g=>0,f=>1}
f9ff01000005000000
f9ff0100000005000000
f9ff01000000000005000000
f9ff01000000000005000000
=
struct mixed {
  short a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
  signed   long  i:1;
};
-
{e=>-1,a=>106,d=>1,c=>-1,h=>0,b=>1,g=>0,f=>1,i=>0}
6a0003030001000000
6a000300030001000000
6a0003000300000001000000
6a0003000300000001000000
-
{e=>0,a=>10,d=>0,c=>0,h=>1,b=>0,g=>-1,f=>0,i=>-1}
0a000000000e000000
0a00000000000e000000
0a000000000000000e000000
0a000000000000000e000000
-
{e=>-1,a=>93,d=>1,c=>0,h=>0,b=>0,g=>0,f=>0,i=>0}
5d0000030000000000
5d000000030000000000
5d0000000300000000000000
5d0000000300000000000000
-
{e=>-1,a=>-24,d=>0,c=>0,h=>1,b=>1,g=>0,f=>1,i=>0}
e8ff01020005000000
e8ff0100020005000000
e8ff01000200000005000000
e8ff01000200000005000000
-
{e=>0,a=>-98,d=>0,c=>0,h=>1,b=>0,g=>-1,f=>1,i=>-1}
9eff0000000f000000
9eff000000000f000000
9eff0000000000000f000000
9eff0000000000000f000000
=
struct mixed {
  short a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
  signed   long  i:1;
  unsigned char  j;
};
-
{e=>-1,a=>-30,d=>0,j=>167,c=>0,h=>1,b=>1,g=>0,f=>0,i=>0}
e2ff01020004000000a7
e2ff0100020004000000a700
e2ff01000200000004000000a7000000
e2ff01000200000004000000a7000000
-
{e=>0,a=>34,d=>1,j=>13,c=>0,h=>1,b=>1,g=>0,f=>0,i=>-1}
22000101000c0000000d
2200010001000c0000000d00
22000100010000000c0000000d000000
22000100010000000c0000000d000000
-
{e=>-1,a=>-125,d=>0,j=>209,c=>0,h=>0,b=>0,g=>0,f=>0,i=>0}
83ff00020000000000d1
83ff0000020000000000d100
83ff00000200000000000000d1000000
83ff00000200000000000000d1000000
-
{e=>0,a=>57,d=>0,j=>197,c=>0,h=>0,b=>0,g=>-1,f=>1,i=>-1}
39000000000b000000c5
3900000000000b000000c500
39000000000000000b000000c5000000
39000000000000000b000000c5000000
-
{e=>-1,a=>101,d=>1,j=>141,c=>-1,h=>0,b=>1,g=>0,f=>1,i=>-1}
6500030300090000008d
650003000300090000008d00
6500030003000000090000008d000000
6500030003000000090000008d000000
=
struct mixed {
  int a;
  unsigned char  b:1;
};
-
{a=>59,b=>1}
3b00000001
3b0000000100
3b00000001000000
3b00000001000000
-
{a=>25,b=>0}
1900000000
190000000000
1900000000000000
1900000000000000
-
{a=>-69,b=>1}
bbffffff01
bbffffff0100
bbffffff01000000
bbffffff01000000
-
{a=>106,b=>0}
6a00000000
6a0000000000
6a00000000000000
6a00000000000000
-
{a=>112,b=>1}
7000000001
700000000100
7000000001000000
7000000001000000
=
struct mixed {
  int a;
  unsigned char  b:1;
  signed   char  c:1;
};
-
{c=>-1,a=>17,b=>0}
1100000002
110000000200
1100000002000000
1100000002000000
-
{c=>-1,a=>-75,b=>1}
b5ffffff03
b5ffffff0300
b5ffffff03000000
b5ffffff03000000
-
{c=>-1,a=>86,b=>0}
5600000002
560000000200
5600000002000000
5600000002000000
-
{c=>0,a=>-126,b=>1}
82ffffff01
82ffffff0100
82ffffff01000000
82ffffff01000000
-
{c=>-1,a=>49,b=>1}
3100000003
310000000300
3100000003000000
3100000003000000
=
struct mixed {
  int a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
};
-
{c=>-1,a=>-126,b=>0,d=>0}
82ffffff020000
82ffffff02000000
82ffffff02000000
82ffffff02000000
-
{c=>0,a=>-97,b=>0,d=>1}
9fffffff000100
9fffffff00000100
9fffffff00000100
9fffffff00000100
-
{c=>0,a=>25,b=>0,d=>0}
19000000000000
1900000000000000
1900000000000000
1900000000000000
-
{c=>0,a=>-28,b=>1,d=>1}
e4ffffff010100
e4ffffff01000100
e4ffffff01000100
e4ffffff01000100
-
{c=>-1,a=>112,b=>1,d=>0}
70000000030000
7000000003000000
7000000003000000
7000000003000000
=
struct mixed {
  int a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
};
-
{e=>0,c=>-1,a=>122,b=>0,d=>1}
7a000000020100
7a00000002000100
7a00000002000100
7a00000002000100
-
{e=>-1,c=>-1,a=>-41,b=>1,d=>0}
d7ffffff030200
d7ffffff03000200
d7ffffff03000200
d7ffffff03000200
-
{e=>-1,c=>-1,a=>67,b=>0,d=>0}
43000000020200
4300000002000200
4300000002000200
4300000002000200
-
{e=>0,c=>0,a=>-109,b=>0,d=>1}
93ffffff000100
93ffffff00000100
93ffffff00000100
93ffffff00000100
-
{e=>0,c=>0,a=>-80,b=>1,d=>0}
b0ffffff010000
b0ffffff01000000
b0ffffff01000000
b0ffffff01000000
=
struct mixed {
  int a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
};
-
{e=>0,c=>-1,a=>-35,b=>1,d=>0,f=>0}
ddffffff03000000000000
ddffffff0300000000000000
ddffffff0300000000000000
ddffffff0300000000000000
-
{e=>-1,c=>-1,a=>-61,b=>0,d=>0,f=>0}
c3ffffff02020000000000
c3ffffff0200020000000000
c3ffffff0200020000000000
c3ffffff0200020000000000
-
{e=>0,c=>0,a=>94,b=>0,d=>0,f=>1}
5e00000000000001000000
5e0000000000000001000000
5e0000000000000001000000
5e0000000000000001000000
-
{e=>0,c=>-1,a=>-17,b=>0,d=>0,f=>0}
efffffff02000000000000
efffffff0200000000000000
efffffff0200000000000000
efffffff0200000000000000
-
{e=>-1,c=>-1,a=>-4,b=>0,d=>1,f=>0}
fcffffff02030000000000
fcffffff0200030000000000
fcffffff0200030000000000
fcffffff0200030000000000
=
struct mixed {
  int a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
};
-
{e=>-1,c=>-1,a=>66,g=>0,b=>0,d=>0,f=>1}
4200000002020001000000
420000000200020001000000
420000000200020001000000
420000000200020001000000
-
{e=>0,c=>-1,a=>88,g=>-1,b=>0,d=>1,f=>1}
5800000002010003000000
580000000200010003000000
580000000200010003000000
580000000200010003000000
-
{e=>-1,c=>0,a=>22,g=>0,b=>0,d=>0,f=>0}
1600000000020000000000
160000000000020000000000
160000000000020000000000
160000000000020000000000
-
{e=>0,c=>-1,a=>54,g=>-1,b=>0,d=>0,f=>1}
3600000002000003000000
360000000200000003000000
360000000200000003000000
360000000200000003000000
-
{e=>-1,c=>-1,a=>98,g=>-1,b=>0,d=>0,f=>0}
6200000002020002000000
620000000200020002000000
620000000200020002000000
620000000200020002000000
=
struct mixed {
  int a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
};
-
{e=>-1,a=>-102,d=>1,c=>0,h=>0,b=>1,g=>-1,f=>0}
9affffff01030002000000
9affffff0100030002000000
9affffff0100030002000000
9affffff0100030002000000
-
{e=>-1,a=>84,d=>1,c=>0,h=>0,b=>0,g=>0,f=>0}
5400000000030000000000
540000000000030000000000
540000000000030000000000
540000000000030000000000
-
{e=>-1,a=>-63,d=>1,c=>-1,h=>0,b=>1,g=>0,f=>0}
c1ffffff03030000000000
c1ffffff0300030000000000
c1ffffff0300030000000000
c1ffffff0300030000000000
-
{e=>0,a=>-36,d=>0,c=>0,h=>0,b=>1,g=>-1,f=>1}
dcffffff01000003000000
dcffffff0100000003000000
dcffffff0100000003000000
dcffffff0100000003000000
-
{e=>0,a=>17,d=>0,c=>0,h=>0,b=>1,g=>-1,f=>0}
1100000001000002000000
110000000100000002000000
110000000100000002000000
110000000100000002000000
=
struct mixed {
  int a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
  signed   long  i:1;
};
-
{e=>0,a=>98,d=>1,c=>0,h=>1,b=>0,g=>-1,f=>0,i=>-1}
620000000001000e000000
62000000000001000e000000
62000000000001000e000000
62000000000001000e000000
-
{e=>0,a=>-97,d=>0,c=>-1,h=>0,b=>1,g=>0,f=>1,i=>-1}
9fffffff03000009000000
9fffffff0300000009000000
9fffffff0300000009000000
9fffffff0300000009000000
-
{e=>-1,a=>15,d=>1,c=>-1,h=>0,b=>0,g=>0,f=>1,i=>0}
0f00000002030001000000
0f0000000200030001000000
0f0000000200030001000000
0f0000000200030001000000
-
{e=>-1,a=>-3,d=>0,c=>-1,h=>0,b=>1,g=>0,f=>1,i=>0}
fdffffff03020001000000
fdffffff0300020001000000
fdffffff0300020001000000
fdffffff0300020001000000
-
{e=>0,a=>101,d=>1,c=>0,h=>0,b=>0,g=>-1,f=>1,i=>-1}
650000000001000b000000
65000000000001000b000000
65000000000001000b000000
65000000000001000b000000
=
struct mixed {
  int a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
  signed   long  i:1;
  unsigned char  j;
};
-
{e=>-1,a=>-121,d=>1,j=>162,c=>0,h=>1,b=>0,g=>-1,f=>0,i=>0}
87ffffff00030006000000a2
87ffffff0000030006000000a200
87ffffff0000030006000000a2000000
87ffffff0000030006000000a2000000
-
{e=>0,a=>-14,d=>1,j=>104,c=>-1,h=>0,b=>0,g=>0,f=>1,i=>-1}
f2ffffff0201000900000068
f2ffffff02000100090000006800
f2ffffff020001000900000068000000
f2ffffff020001000900000068000000
-
{e=>-1,a=>4,d=>0,j=>93,c=>-1,h=>0,b=>0,g=>0,f=>1,i=>0}
04000000020200010000005d
0400000002000200010000005d00
0400000002000200010000005d000000
0400000002000200010000005d000000
-
{e=>-1,a=>17,d=>0,j=>133,c=>0,h=>0,b=>1,g=>0,f=>0,i=>0}
110000000102000000000085
1100000001000200000000008500
11000000010002000000000085000000
11000000010002000000000085000000
-
{e=>0,a=>56,d=>0,j=>65,c=>-1,h=>0,b=>0,g=>-1,f=>0,i=>-1}
380000000200000a00000041
38000000020000000a0000004100
38000000020000000a00000041000000
38000000020000000a00000041000000
=
struct mixed {
  long a;
  unsigned char  b:1;
};
-
{a=>99,b=>1}
6300000001
630000000100
6300000001000000
6300000001000000
-
{a=>8,b=>0}
0800000000
080000000000
0800000000000000
0800000000000000
-
{a=>-122,b=>0}
86ffffff00
86ffffff0000
86ffffff00000000
86ffffff00000000
-
{a=>-2,b=>1}
feffffff01
feffffff0100
feffffff01000000
feffffff01000000
-
{a=>102,b=>0}
6600000000
660000000000
6600000000000000
6600000000000000
=
struct mixed {
  long a;
  unsigned char  b:1;
  signed   char  c:1;
};
-
{c=>-1,a=>96,b=>0}
6000000002
600000000200
6000000002000000
6000000002000000
-
{c=>-1,a=>59,b=>0}
3b00000002
3b0000000200
3b00000002000000
3b00000002000000
-
{c=>-1,a=>120,b=>1}
7800000003
780000000300
7800000003000000
7800000003000000
-
{c=>0,a=>-13,b=>1}
f3ffffff01
f3ffffff0100
f3ffffff01000000
f3ffffff01000000
-
{c=>0,a=>-28,b=>0}
e4ffffff00
e4ffffff0000
e4ffffff00000000
e4ffffff00000000
=
struct mixed {
  long a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
};
-
{c=>0,a=>109,b=>1,d=>0}
6d000000010000
6d00000001000000
6d00000001000000
6d00000001000000
-
{c=>0,a=>107,b=>0,d=>0}
6b000000000000
6b00000000000000
6b00000000000000
6b00000000000000
-
{c=>0,a=>28,b=>1,d=>1}
1c000000010100
1c00000001000100
1c00000001000100
1c00000001000100
-
{c=>0,a=>72,b=>0,d=>1}
48000000000100
4800000000000100
4800000000000100
4800000000000100
-
{c=>0,a=>-52,b=>0,d=>1}
ccffffff000100
ccffffff00000100
ccffffff00000100
ccffffff00000100
=
struct mixed {
  long a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
};
-
{e=>0,c=>0,a=>25,b=>0,d=>1}
19000000000100
1900000000000100
1900000000000100
1900000000000100
-
{e=>-1,c=>-1,a=>59,b=>1,d=>1}
3b000000030300
3b00000003000300
3b00000003000300
3b00000003000300
-
{e=>-1,c=>0,a=>124,b=>0,d=>1}
7c000000000300
7c00000000000300
7c00000000000300
7c00000000000300
-
{e=>-1,c=>0,a=>74,b=>0,d=>0}
4a000000000200
4a00000000000200
4a00000000000200
4a00000000000200
-
{e=>-1,c=>0,a=>-39,b=>0,d=>1}
d9ffffff000300
d9ffffff00000300
d9ffffff00000300
d9ffffff00000300
=
struct mixed {
  long a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
};
-
{e=>-1,c=>-1,a=>-33,b=>0,d=>0,f=>0}
dfffffff02020000000000
dfffffff0200020000000000
dfffffff0200020000000000
dfffffff0200020000000000
-
{e=>0,c=>0,a=>-57,b=>1,d=>0,f=>0}
c7ffffff01000000000000
c7ffffff0100000000000000
c7ffffff0100000000000000
c7ffffff0100000000000000
-
{e=>0,c=>-1,a=>-10,b=>0,d=>1,f=>0}
f6ffffff02010000000000
f6ffffff0200010000000000
f6ffffff0200010000000000
f6ffffff0200010000000000
-
{e=>0,c=>-1,a=>52,b=>0,d=>0,f=>1}
3400000002000001000000
340000000200000001000000
340000000200000001000000
340000000200000001000000
-
{e=>-1,c=>0,a=>127,b=>0,d=>0,f=>0}
7f00000000020000000000
7f0000000000020000000000
7f0000000000020000000000
7f0000000000020000000000
=
struct mixed {
  long a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
};
-
{e=>0,c=>-1,a=>-7,g=>0,b=>0,d=>0,f=>1}
f9ffffff02000001000000
f9ffffff0200000001000000
f9ffffff0200000001000000
f9ffffff0200000001000000
-
{e=>0,c=>0,a=>18,g=>-1,b=>1,d=>0,f=>1}
1200000001000003000000
120000000100000003000000
120000000100000003000000
120000000100000003000000
-
{e=>-1,c=>-1,a=>84,g=>0,b=>0,d=>1,f=>1}
5400000002030001000000
540000000200030001000000
540000000200030001000000
540000000200030001000000
-
{e=>0,c=>-1,a=>21,g=>0,b=>0,d=>1,f=>0}
1500000002010000000000
150000000200010000000000
150000000200010000000000
150000000200010000000000
-
{e=>-1,c=>-1,a=>-2,g=>-1,b=>1,d=>0,f=>1}
feffffff03020003000000
feffffff0300020003000000
feffffff0300020003000000
feffffff0300020003000000
=
struct mixed {
  long a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
};
-
{e=>-1,a=>11,d=>0,c=>0,h=>1,b=>1,g=>0,f=>1}
0b00000001020005000000
0b0000000100020005000000
0b0000000100020005000000
0b0000000100020005000000
-
{e=>0,a=>-17,d=>0,c=>0,h=>1,b=>0,g=>0,f=>0}
efffffff00000004000000
efffffff0000000004000000
efffffff0000000004000000
efffffff0000000004000000
-
{e=>-1,a=>2,d=>1,c=>-1,h=>0,b=>1,g=>0,f=>0}
0200000003030000000000
020000000300030000000000
020000000300030000000000
020000000300030000000000
-
{e=>0,a=>6,d=>1,c=>-1,h=>0,b=>1,g=>-1,f=>1}
0600000003010003000000
060000000300010003000000
060000000300010003000000
060000000300010003000000
-
{e=>0,a=>103,d=>0,c=>0,h=>0,b=>1,g=>-1,f=>0}
6700000001000002000000
670000000100000002000000
670000000100000002000000
670000000100000002000000
=
struct mixed {
  long a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
  signed   long  i:1;
};
-
{e=>-1,a=>-66,d=>0,c=>0,h=>0,b=>1,g=>0,f=>1,i=>-1}
beffffff01020009000000
beffffff0100020009000000
beffffff0100020009000000
beffffff0100020009000000
-
{e=>0,a=>-106,d=>0,c=>0,h=>1,b=>0,g=>-1,f=>0,i=>0}
96ffffff00000006000000
96ffffff0000000006000000
96ffffff0000000006000000
96ffffff0000000006000000
-
{e=>-1,a=>-86,d=>0,c=>0,h=>0,b=>1,g=>0,f=>0,i=>0}
aaffffff01020000000000
aaffffff0100020000000000
aaffffff0100020000000000
aaffffff0100020000000000
-
{e=>-1,a=>-98,d=>0,c=>0,h=>0,b=>0,g=>0,f=>1,i=>0}
9effffff00020001000000
9effffff0000020001000000
9effffff0000020001000000
9effffff0000020001000000
-
{e=>0,a=>40,d=>0,c=>0,h=>1,b=>1,g=>0,f=>1,i=>0}
2800000001000005000000
280000000100000005000000
280000000100000005000000
280000000100000005000000
=
struct mixed {
  long a;
  unsigned char  b:1;
  signed   char  c:1;
  unsigned short d:1;
  signed   short e:1;
  unsigned int   f:1;
  signed   int   g:1;
  unsigned long  h:1;
  signed   long  i:1;
  unsigned char  j;
};
-
{e=>-1,a=>-49,d=>1,j=>205,c=>0,h=>0,b=>1,g=>0,f=>1,i=>-1}
cfffffff01030009000000cd
cfffffff0100030009000000cd00
cfffffff0100030009000000cd000000
cfffffff0100030009000000cd000000
-
{e=>-1,a=>126,d=>0,j=>0,c=>-1,h=>1,b=>1,g=>-1,f=>0,i=>0}
7e0000000302000600000000
7e00000003000200060000000000
7e000000030002000600000000000000
7e000000030002000600000000000000
-
{e=>0,a=>-31,d=>0,j=>105,c=>-1,h=>0,b=>1,g=>0,f=>0,i=>-1}
e1ffffff0300000800000069
e1ffffff03000000080000006900
e1ffffff030000000800000069000000
e1ffffff030000000800000069000000
-
{e=>-1,a=>-1,d=>1,j=>21,c=>-1,h=>0,b=>1,g=>-1,f=>0,i=>0}
ffffffff0303000200000015
ffffffff03000300020000001500
ffffffff030003000200000015000000
ffffffff030003000200000015000000
-
{e=>-1,a=>99,d=>0,j=>132,c=>0,h=>0,b=>0,g=>0,f=>1,i=>0}
630000000002000100000084
6300000000000200010000008400
63000000000002000100000084000000
63000000000002000100000084000000
=
struct force_align1 {
  unsigned char a:1;
};
-
{a=>0}
00
00
00
00
-
{a=>1}
01
01
01
01
-
{a=>1}
01
01
01
01
-
{a=>1}
01
01
01
01
-
{a=>1}
01
01
01
01
=
struct force_align1 {
  unsigned char a:1;
  unsigned char b:1;
};
-
{a=>1,b=>1}
03
03
03
03
-
{a=>1,b=>1}
03
03
03
03
-
{a=>0,b=>1}
02
02
02
02
-
{a=>0,b=>1}
02
02
02
02
-
{a=>1,b=>1}
03
03
03
03
=
struct force_align1 {
  unsigned char a:1;
  unsigned char b:1;
  unsigned char  :0;
};
-
{a=>0,b=>0}
00
00
00
00
-
{a=>0,b=>1}
02
02
02
02
-
{a=>0,b=>0}
00
00
00
00
-
{a=>1,b=>1}
03
03
03
03
-
{a=>1,b=>0}
01
01
01
01
=
struct force_align1 {
  unsigned char a:1;
  unsigned char b:1;
  unsigned char  :0;
  unsigned char c:1;
};
-
{c=>1,a=>1,b=>0}
0101
0101
0101
0101
-
{c=>1,a=>1,b=>1}
0301
0301
0301
0301
-
{c=>0,a=>1,b=>1}
0300
0300
0300
0300
-
{c=>0,a=>0,b=>0}
0000
0000
0000
0000
-
{c=>0,a=>1,b=>0}
0100
0100
0100
0100
=
struct force_align1 {
  unsigned char a:1;
  unsigned char b:1;
  unsigned char  :0;
  unsigned char c:1;
  unsigned int  d;
};
-
{c=>0,a=>0,b=>1,d=>114}
020072000000
020072000000
0200000072000000
0200000072000000
-
{c=>0,a=>1,b=>0,d=>177}
0100b1000000
0100b1000000
01000000b1000000
01000000b1000000
-
{c=>1,a=>1,b=>1,d=>163}
0301a3000000
0301a3000000
03010000a3000000
03010000a3000000
-
{c=>0,a=>0,b=>1,d=>180}
0200b4000000
0200b4000000
02000000b4000000
02000000b4000000
-
{c=>0,a=>1,b=>0,d=>131}
010083000000
010083000000
0100000083000000
0100000083000000
=
struct force_align1 {
  char a;
  unsigned char b:1;
};
-
{a=>105,b=>1}
6901
6901
6901
6901
-
{a=>-17,b=>1}
ef01
ef01
ef01
ef01
-
{a=>-128,b=>1}
8001
8001
8001
8001
-
{a=>35,b=>0}
2300
2300
2300
2300
-
{a=>-120,b=>0}
8800
8800
8800
8800
=
struct force_align1 {
  char a;
  unsigned char b:1;
  unsigned char c:1;
};
-
{c=>0,a=>87,b=>0}
5700
5700
5700
5700
-
{c=>0,a=>12,b=>1}
0c01
0c01
0c01
0c01
-
{c=>0,a=>107,b=>0}
6b00
6b00
6b00
6b00
-
{c=>1,a=>-100,b=>0}
9c02
9c02
9c02
9c02
-
{c=>1,a=>-61,b=>0}
c302
c302
c302
c302
=
struct force_align1 {
  char a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
};
-
{c=>0,a=>-59,b=>0}
c500
c500
c500
c500
-
{c=>0,a=>-128,b=>0}
8000
8000
8000
8000
-
{c=>0,a=>-43,b=>1}
d501
d501
d501
d501
-
{c=>0,a=>55,b=>0}
3700
3700
3700
3700
-
{c=>0,a=>-27,b=>1}
e501
e501
e501
e501
=
struct force_align1 {
  char a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
  unsigned char d:1;
};
-
{c=>1,a=>-22,b=>1,d=>0}
ea0300
ea0300
ea0300
ea0300
-
{c=>1,a=>115,b=>1,d=>0}
730300
730300
730300
730300
-
{c=>1,a=>-2,b=>0,d=>0}
fe0200
fe0200
fe0200
fe0200
-
{c=>0,a=>-40,b=>1,d=>0}
d80100
d80100
d80100
d80100
-
{c=>1,a=>52,b=>0,d=>0}
340200
340200
340200
340200
=
struct force_align1 {
  char a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
  unsigned char d:1;
  unsigned int  e;
};
-
{e=>84,c=>0,a=>-2,b=>1,d=>1}
fe010154000000
fe01010054000000
fe01010054000000
fe01010054000000
-
{e=>26,c=>1,a=>-22,b=>0,d=>1}
ea02011a000000
ea0201001a000000
ea0201001a000000
ea0201001a000000
-
{e=>229,c=>0,a=>-4,b=>1,d=>0}
fc0100e5000000
fc010000e5000000
fc010000e5000000
fc010000e5000000
-
{e=>140,c=>0,a=>-121,b=>0,d=>1}
8700018c000000
870001008c000000
870001008c000000
870001008c000000
-
{e=>135,c=>0,a=>23,b=>0,d=>0}
17000087000000
1700000087000000
1700000087000000
1700000087000000
=
struct force_align1 {
  short a;
  unsigned char b:1;
};
-
{a=>108,b=>1}
6c0001
6c000100
6c000100
6c000100
-
{a=>-114,b=>0}
8eff00
8eff0000
8eff0000
8eff0000
-
{a=>64,b=>1}
400001
40000100
40000100
40000100
-
{a=>19,b=>1}
130001
13000100
13000100
13000100
-
{a=>-123,b=>0}
85ff00
85ff0000
85ff0000
85ff0000
=
struct force_align1 {
  short a;
  unsigned char b:1;
  unsigned char c:1;
};
-
{c=>0,a=>-11,b=>1}
f5ff01
f5ff0100
f5ff0100
f5ff0100
-
{c=>1,a=>90,b=>0}
5a0002
5a000200
5a000200
5a000200
-
{c=>0,a=>107,b=>0}
6b0000
6b000000
6b000000
6b000000
-
{c=>0,a=>-75,b=>1}
b5ff01
b5ff0100
b5ff0100
b5ff0100
-
{c=>1,a=>-80,b=>0}
b0ff02
b0ff0200
b0ff0200
b0ff0200
=
struct force_align1 {
  short a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
};
-
{c=>1,a=>105,b=>1}
690003
69000300
69000300
69000300
-
{c=>0,a=>49,b=>1}
310001
31000100
31000100
31000100
-
{c=>1,a=>37,b=>0}
250002
25000200
25000200
25000200
-
{c=>0,a=>-82,b=>0}
aeff00
aeff0000
aeff0000
aeff0000
-
{c=>1,a=>-88,b=>1}
a8ff03
a8ff0300
a8ff0300
a8ff0300
=
struct force_align1 {
  short a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
  unsigned char d:1;
};
-
{c=>0,a=>-121,b=>1,d=>0}
87ff0100
87ff0100
87ff0100
87ff0100
-
{c=>1,a=>80,b=>0,d=>1}
50000201
50000201
50000201
50000201
-
{c=>0,a=>-79,b=>1,d=>1}
b1ff0101
b1ff0101
b1ff0101
b1ff0101
-
{c=>0,a=>106,b=>1,d=>0}
6a000100
6a000100
6a000100
6a000100
-
{c=>1,a=>113,b=>0,d=>1}
71000201
71000201
71000201
71000201
=
struct force_align1 {
  short a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
  unsigned char d:1;
  unsigned int  e;
};
-
{e=>56,c=>0,a=>80,b=>0,d=>0}
5000000038000000
5000000038000000
5000000038000000
5000000038000000
-
{e=>189,c=>1,a=>6,b=>1,d=>1}
06000301bd000000
06000301bd000000
06000301bd000000
06000301bd000000
-
{e=>198,c=>1,a=>-106,b=>0,d=>0}
96ff0200c6000000
96ff0200c6000000
96ff0200c6000000
96ff0200c6000000
-
{e=>167,c=>1,a=>-17,b=>1,d=>0}
efff0300a7000000
efff0300a7000000
efff0300a7000000
efff0300a7000000
-
{e=>89,c=>0,a=>-78,b=>1,d=>0}
b2ff010059000000
b2ff010059000000
b2ff010059000000
b2ff010059000000
=
struct force_align1 {
  int a;
  unsigned char b:1;
};
-
{a=>19,b=>1}
1300000001
130000000100
1300000001000000
1300000001000000
-
{a=>79,b=>0}
4f00000000
4f0000000000
4f00000000000000
4f00000000000000
-
{a=>-101,b=>1}
9bffffff01
9bffffff0100
9bffffff01000000
9bffffff01000000
-
{a=>11,b=>1}
0b00000001
0b0000000100
0b00000001000000
0b00000001000000
-
{a=>79,b=>0}
4f00000000
4f0000000000
4f00000000000000
4f00000000000000
=
struct force_align1 {
  int a;
  unsigned char b:1;
  unsigned char c:1;
};
-
{c=>1,a=>-25,b=>0}
e7ffffff02
e7ffffff0200
e7ffffff02000000
e7ffffff02000000
-
{c=>1,a=>-98,b=>0}
9effffff02
9effffff0200
9effffff02000000
9effffff02000000
-
{c=>0,a=>-118,b=>0}
8affffff00
8affffff0000
8affffff00000000
8affffff00000000
-
{c=>1,a=>-46,b=>1}
d2ffffff03
d2ffffff0300
d2ffffff03000000
d2ffffff03000000
-
{c=>0,a=>92,b=>0}
5c00000000
5c0000000000
5c00000000000000
5c00000000000000
=
struct force_align1 {
  int a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
};
-
{c=>0,a=>27,b=>1}
1b00000001
1b0000000100
1b00000001000000
1b00000001000000
-
{c=>1,a=>71,b=>1}
4700000003
470000000300
4700000003000000
4700000003000000
-
{c=>0,a=>53,b=>0}
3500000000
350000000000
3500000000000000
3500000000000000
-
{c=>0,a=>-126,b=>1}
82ffffff01
82ffffff0100
82ffffff01000000
82ffffff01000000
-
{c=>0,a=>-59,b=>1}
c5ffffff01
c5ffffff0100
c5ffffff01000000
c5ffffff01000000
=
struct force_align1 {
  int a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
  unsigned char d:1;
};
-
{c=>1,a=>49,b=>1,d=>0}
310000000300
310000000300
3100000003000000
3100000003000000
-
{c=>1,a=>-97,b=>0,d=>0}
9fffffff0200
9fffffff0200
9fffffff02000000
9fffffff02000000
-
{c=>1,a=>114,b=>1,d=>1}
720000000301
720000000301
7200000003010000
7200000003010000
-
{c=>0,a=>-38,b=>1,d=>0}
daffffff0100
daffffff0100
daffffff01000000
daffffff01000000
-
{c=>0,a=>-74,b=>0,d=>0}
b6ffffff0000
b6ffffff0000
b6ffffff00000000
b6ffffff00000000
=
struct force_align1 {
  int a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
  unsigned char d:1;
  unsigned int  e;
};
-
{e=>174,c=>0,a=>102,b=>0,d=>1}
660000000001ae000000
660000000001ae000000
6600000000010000ae000000
6600000000010000ae000000
-
{e=>77,c=>1,a=>85,b=>0,d=>0}
5500000002004d000000
5500000002004d000000
55000000020000004d000000
55000000020000004d000000
-
{e=>97,c=>1,a=>-95,b=>0,d=>1}
a1ffffff020161000000
a1ffffff020161000000
a1ffffff0201000061000000
a1ffffff0201000061000000
-
{e=>21,c=>1,a=>-30,b=>0,d=>1}
e2ffffff020115000000
e2ffffff020115000000
e2ffffff0201000015000000
e2ffffff0201000015000000
-
{e=>169,c=>0,a=>-9,b=>1,d=>0}
f7ffffff0100a9000000
f7ffffff0100a9000000
f7ffffff01000000a9000000
f7ffffff01000000a9000000
=
struct force_align1 {
  long a;
  unsigned char b:1;
};
-
{a=>67,b=>0}
4300000000
430000000000
4300000000000000
4300000000000000
-
{a=>122,b=>0}
7a00000000
7a0000000000
7a00000000000000
7a00000000000000
-
{a=>104,b=>0}
6800000000
680000000000
6800000000000000
6800000000000000
-
{a=>-99,b=>0}
9dffffff00
9dffffff0000
9dffffff00000000
9dffffff00000000
-
{a=>-11,b=>1}
f5ffffff01
f5ffffff0100
f5ffffff01000000
f5ffffff01000000
=
struct force_align1 {
  long a;
  unsigned char b:1;
  unsigned char c:1;
};
-
{c=>1,a=>-95,b=>0}
a1ffffff02
a1ffffff0200
a1ffffff02000000
a1ffffff02000000
-
{c=>0,a=>74,b=>1}
4a00000001
4a0000000100
4a00000001000000
4a00000001000000
-
{c=>0,a=>31,b=>1}
1f00000001
1f0000000100
1f00000001000000
1f00000001000000
-
{c=>0,a=>-31,b=>1}
e1ffffff01
e1ffffff0100
e1ffffff01000000
e1ffffff01000000
-
{c=>0,a=>47,b=>1}
2f00000001
2f0000000100
2f00000001000000
2f00000001000000
=
struct force_align1 {
  long a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
};
-
{c=>1,a=>-52,b=>0}
ccffffff02
ccffffff0200
ccffffff02000000
ccffffff02000000
-
{c=>1,a=>9,b=>0}
0900000002
090000000200
0900000002000000
0900000002000000
-
{c=>1,a=>9,b=>1}
0900000003
090000000300
0900000003000000
0900000003000000
-
{c=>1,a=>32,b=>1}
2000000003
200000000300
2000000003000000
2000000003000000
-
{c=>1,a=>-30,b=>0}
e2ffffff02
e2ffffff0200
e2ffffff02000000
e2ffffff02000000
=
struct force_align1 {
  long a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
  unsigned char d:1;
};
-
{c=>1,a=>-45,b=>1,d=>0}
d3ffffff0300
d3ffffff0300
d3ffffff03000000
d3ffffff03000000
-
{c=>0,a=>44,b=>0,d=>0}
2c0000000000
2c0000000000
2c00000000000000
2c00000000000000
-
{c=>1,a=>88,b=>1,d=>1}
580000000301
580000000301
5800000003010000
5800000003010000
-
{c=>1,a=>99,b=>0,d=>0}
630000000200
630000000200
6300000002000000
6300000002000000
-
{c=>1,a=>94,b=>1,d=>0}
5e0000000300
5e0000000300
5e00000003000000
5e00000003000000
=
struct force_align1 {
  long a;
  unsigned char b:1;
  unsigned char c:1;
  unsigned char  :0;
  unsigned char d:1;
  unsigned int  e;
};
-
{e=>84,c=>1,a=>-57,b=>0,d=>1}
c7ffffff020154000000
c7ffffff020154000000
c7ffffff0201000054000000
c7ffffff0201000054000000
-
{e=>202,c=>0,a=>-67,b=>0,d=>1}
bdffffff0001ca000000
bdffffff0001ca000000
bdffffff00010000ca000000
bdffffff00010000ca000000
-
{e=>108,c=>0,a=>108,b=>1,d=>0}
6c00000001006c000000
6c00000001006c000000
6c000000010000006c000000
6c000000010000006c000000
-
{e=>5,c=>0,a=>51,b=>1,d=>0}
33000000010005000000
33000000010005000000
330000000100000005000000
330000000100000005000000
-
{e=>228,c=>0,a=>-15,b=>0,d=>0}
f1ffffff0000e4000000
f1ffffff0000e4000000
f1ffffff00000000e4000000
f1ffffff00000000e4000000
=
struct force_align2 {
  unsigned char  a:2;
};
-
{a=>2}
02
02
02
02
-
{a=>0}
00
00
00
00
-
{a=>0}
00
00
00
00
-
{a=>3}
03
03
03
03
-
{a=>3}
03
03
03
03
=
struct force_align2 {
  unsigned char  a:2;
  unsigned char  b:2;
};
-
{a=>0,b=>3}
0c
0c
0c
0c
-
{a=>0,b=>1}
04
04
04
04
-
{a=>2,b=>3}
0e
0e
0e
0e
-
{a=>2,b=>1}
06
06
06
06
-
{a=>3,b=>3}
0f
0f
0f
0f
=
struct force_align2 {
  unsigned char  a:2;
  unsigned char  b:2;
  unsigned char   :0;
};
-
{a=>0,b=>0}
00
00
00
00
-
{a=>0,b=>1}
04
04
04
04
-
{a=>1,b=>3}
0d
0d
0d
0d
-
{a=>2,b=>0}
02
02
02
02
-
{a=>0,b=>2}
08
08
08
08
=
struct force_align2 {
  unsigned char  a:2;
  unsigned char  b:2;
  unsigned char   :0;
  unsigned char  c:2;
};
-
{c=>1,a=>1,b=>3}
0d01
0d01
0d01
0d01
-
{c=>2,a=>2,b=>1}
0602
0602
0602
0602
-
{c=>1,a=>2,b=>0}
0201
0201
0201
0201
-
{c=>2,a=>3,b=>3}
0f02
0f02
0f02
0f02
-
{c=>0,a=>1,b=>3}
0d00
0d00
0d00
0d00
=
struct force_align2 {
  unsigned char  a:2;
  unsigned char  b:2;
  unsigned char   :0;
  unsigned char  c:2;
  unsigned short d;
};
-
{c=>0,a=>1,b=>0,d=>112}
01007000
01007000
01007000
01007000
-
{c=>0,a=>3,b=>3,d=>128}
0f008000
0f008000
0f008000
0f008000
-
{c=>1,a=>2,b=>0,d=>190}
0201be00
0201be00
0201be00
0201be00
-
{c=>0,a=>3,b=>2,d=>63}
0b003f00
0b003f00
0b003f00
0b003f00
-
{c=>2,a=>2,b=>2,d=>241}
0a02f100
0a02f100
0a02f100
0a02f100
=
struct force_align2 {
  char a;
  unsigned char  b:2;
};
-
{a=>74,b=>1}
4a01
4a01
4a01
4a01
-
{a=>-7,b=>1}
f901
f901
f901
f901
-
{a=>102,b=>1}
6601
6601
6601
6601
-
{a=>10,b=>3}
0a03
0a03
0a03
0a03
-
{a=>-7,b=>2}
f902
f902
f902
f902
=
struct force_align2 {
  char a;
  unsigned char  b:2;
  unsigned char  c:2;
};
-
{c=>3,a=>7,b=>1}
070d
070d
070d
070d
-
{c=>3,a=>50,b=>0}
320c
320c
320c
320c
-
{c=>2,a=>-125,b=>0}
8308
8308
8308
8308
-
{c=>2,a=>-32,b=>0}
e008
e008
e008
e008
-
{c=>1,a=>68,b=>0}
4404
4404
4404
4404
=
struct force_align2 {
  char a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
};
-
{c=>2,a=>-127,b=>0}
8108
8108
8108
8108
-
{c=>1,a=>-27,b=>0}
e504
e504
e504
e504
-
{c=>2,a=>30,b=>1}
1e09
1e09
1e09
1e09
-
{c=>0,a=>-25,b=>1}
e701
e701
e701
e701
-
{c=>2,a=>-15,b=>1}
f109
f109
f109
f109
=
struct force_align2 {
  char a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
  unsigned char  d:2;
};
-
{c=>1,a=>75,b=>1,d=>2}
4b0502
4b0502
4b0502
4b0502
-
{c=>1,a=>18,b=>1,d=>3}
120503
120503
120503
120503
-
{c=>2,a=>-39,b=>2,d=>0}
d90a00
d90a00
d90a00
d90a00
-
{c=>3,a=>-91,b=>2,d=>0}
a50e00
a50e00
a50e00
a50e00
-
{c=>1,a=>60,b=>1,d=>0}
3c0500
3c0500
3c0500
3c0500
=
struct force_align2 {
  char a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
  unsigned char  d:2;
  unsigned short e;
};
-
{e=>11,c=>2,a=>39,b=>0,d=>2}
2708020b00
270802000b00
270802000b00
270802000b00
-
{e=>219,c=>0,a=>42,b=>3,d=>1}
2a0301db00
2a030100db00
2a030100db00
2a030100db00
-
{e=>154,c=>0,a=>-14,b=>1,d=>1}
f201019a00
f20101009a00
f20101009a00
f20101009a00
-
{e=>86,c=>1,a=>20,b=>3,d=>1}
1407015600
140701005600
140701005600
140701005600
-
{e=>7,c=>0,a=>-109,b=>1,d=>1}
9301010700
930101000700
930101000700
930101000700
=
struct force_align2 {
  short a;
  unsigned char  b:2;
};
-
{a=>-77,b=>0}
b3ff00
b3ff0000
b3ff0000
b3ff0000
-
{a=>32,b=>1}
200001
20000100
20000100
20000100
-
{a=>-116,b=>3}
8cff03
8cff0300
8cff0300
8cff0300
-
{a=>127,b=>2}
7f0002
7f000200
7f000200
7f000200
-
{a=>47,b=>2}
2f0002
2f000200
2f000200
2f000200
=
struct force_align2 {
  short a;
  unsigned char  b:2;
  unsigned char  c:2;
};
-
{c=>1,a=>-56,b=>2}
c8ff06
c8ff0600
c8ff0600
c8ff0600
-
{c=>1,a=>96,b=>0}
600004
60000400
60000400
60000400
-
{c=>1,a=>-89,b=>1}
a7ff05
a7ff0500
a7ff0500
a7ff0500
-
{c=>1,a=>-121,b=>1}
87ff05
87ff0500
87ff0500
87ff0500
-
{c=>2,a=>80,b=>3}
50000b
50000b00
50000b00
50000b00
=
struct force_align2 {
  short a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
};
-
{c=>0,a=>-50,b=>1}
ceff01
ceff0100
ceff0100
ceff0100
-
{c=>3,a=>26,b=>0}
1a000c
1a000c00
1a000c00
1a000c00
-
{c=>2,a=>-116,b=>2}
8cff0a
8cff0a00
8cff0a00
8cff0a00
-
{c=>3,a=>-72,b=>2}
b8ff0e
b8ff0e00
b8ff0e00
b8ff0e00
-
{c=>1,a=>87,b=>2}
570006
57000600
57000600
57000600
=
struct force_align2 {
  short a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
  unsigned char  d:2;
};
-
{c=>0,a=>-94,b=>1,d=>3}
a2ff0103
a2ff0103
a2ff0103
a2ff0103
-
{c=>0,a=>-117,b=>0,d=>1}
8bff0001
8bff0001
8bff0001
8bff0001
-
{c=>2,a=>18,b=>2,d=>2}
12000a02
12000a02
12000a02
12000a02
-
{c=>3,a=>-15,b=>0,d=>0}
f1ff0c00
f1ff0c00
f1ff0c00
f1ff0c00
-
{c=>0,a=>-39,b=>2,d=>3}
d9ff0203
d9ff0203
d9ff0203
d9ff0203
=
struct force_align2 {
  short a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
  unsigned char  d:2;
  unsigned short e;
};
-
{e=>213,c=>2,a=>98,b=>3,d=>0}
62000b00d500
62000b00d500
62000b00d500
62000b00d500
-
{e=>183,c=>3,a=>104,b=>2,d=>0}
68000e00b700
68000e00b700
68000e00b700
68000e00b700
-
{e=>152,c=>3,a=>68,b=>3,d=>1}
44000f019800
44000f019800
44000f019800
44000f019800
-
{e=>117,c=>0,a=>83,b=>2,d=>1}
530002017500
530002017500
530002017500
530002017500
-
{e=>183,c=>0,a=>-82,b=>3,d=>3}
aeff0303b700
aeff0303b700
aeff0303b700
aeff0303b700
=
struct force_align2 {
  int a;
  unsigned char  b:2;
};
-
{a=>-20,b=>3}
ecffffff03
ecffffff0300
ecffffff03000000
ecffffff03000000
-
{a=>123,b=>1}
7b00000001
7b0000000100
7b00000001000000
7b00000001000000
-
{a=>-106,b=>0}
96ffffff00
96ffffff0000
96ffffff00000000
96ffffff00000000
-
{a=>6,b=>3}
0600000003
060000000300
0600000003000000
0600000003000000
-
{a=>60,b=>0}
3c00000000
3c0000000000
3c00000000000000
3c00000000000000
=
struct force_align2 {
  int a;
  unsigned char  b:2;
  unsigned char  c:2;
};
-
{c=>2,a=>55,b=>0}
3700000008
370000000800
3700000008000000
3700000008000000
-
{c=>2,a=>-128,b=>3}
80ffffff0b
80ffffff0b00
80ffffff0b000000
80ffffff0b000000
-
{c=>3,a=>-119,b=>3}
89ffffff0f
89ffffff0f00
89ffffff0f000000
89ffffff0f000000
-
{c=>2,a=>46,b=>0}
2e00000008
2e0000000800
2e00000008000000
2e00000008000000
-
{c=>2,a=>-13,b=>2}
f3ffffff0a
f3ffffff0a00
f3ffffff0a000000
f3ffffff0a000000
=
struct force_align2 {
  int a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
};
-
{c=>3,a=>-72,b=>3}
b8ffffff0f
b8ffffff0f00
b8ffffff0f000000
b8ffffff0f000000
-
{c=>3,a=>31,b=>0}
1f0000000c
1f0000000c00
1f0000000c000000
1f0000000c000000
-
{c=>0,a=>105,b=>1}
6900000001
690000000100
6900000001000000
6900000001000000
-
{c=>2,a=>74,b=>1}
4a00000009
4a0000000900
4a00000009000000
4a00000009000000
-
{c=>0,a=>12,b=>1}
0c00000001
0c0000000100
0c00000001000000
0c00000001000000
=
struct force_align2 {
  int a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
  unsigned char  d:2;
};
-
{c=>2,a=>-93,b=>0,d=>3}
a3ffffff0803
a3ffffff0803
a3ffffff08030000
a3ffffff08030000
-
{c=>0,a=>-88,b=>2,d=>0}
a8ffffff0200
a8ffffff0200
a8ffffff02000000
a8ffffff02000000
-
{c=>0,a=>89,b=>3,d=>0}
590000000300
590000000300
5900000003000000
5900000003000000
-
{c=>1,a=>-61,b=>2,d=>1}
c3ffffff0601
c3ffffff0601
c3ffffff06010000
c3ffffff06010000
-
{c=>0,a=>-21,b=>0,d=>1}
ebffffff0001
ebffffff0001
ebffffff00010000
ebffffff00010000
=
struct force_align2 {
  int a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
  unsigned char  d:2;
  unsigned short e;
};
-
{e=>23,c=>0,a=>-79,b=>1,d=>3}
b1ffffff01031700
b1ffffff01031700
b1ffffff01031700
b1ffffff01031700
-
{e=>106,c=>2,a=>-36,b=>0,d=>0}
dcffffff08006a00
dcffffff08006a00
dcffffff08006a00
dcffffff08006a00
-
{e=>139,c=>3,a=>114,b=>3,d=>3}
720000000f038b00
720000000f038b00
720000000f038b00
720000000f038b00
-
{e=>151,c=>2,a=>-110,b=>0,d=>3}
92ffffff08039700
92ffffff08039700
92ffffff08039700
92ffffff08039700
-
{e=>15,c=>1,a=>-72,b=>0,d=>3}
b8ffffff04030f00
b8ffffff04030f00
b8ffffff04030f00
b8ffffff04030f00
=
struct force_align2 {
  long a;
  unsigned char  b:2;
};
-
{a=>-86,b=>1}
aaffffff01
aaffffff0100
aaffffff01000000
aaffffff01000000
-
{a=>-16,b=>0}
f0ffffff00
f0ffffff0000
f0ffffff00000000
f0ffffff00000000
-
{a=>-65,b=>2}
bfffffff02
bfffffff0200
bfffffff02000000
bfffffff02000000
-
{a=>2,b=>2}
0200000002
020000000200
0200000002000000
0200000002000000
-
{a=>-85,b=>2}
abffffff02
abffffff0200
abffffff02000000
abffffff02000000
=
struct force_align2 {
  long a;
  unsigned char  b:2;
  unsigned char  c:2;
};
-
{c=>3,a=>-105,b=>2}
97ffffff0e
97ffffff0e00
97ffffff0e000000
97ffffff0e000000
-
{c=>1,a=>14,b=>1}
0e00000005
0e0000000500
0e00000005000000
0e00000005000000
-
{c=>1,a=>-120,b=>2}
88ffffff06
88ffffff0600
88ffffff06000000
88ffffff06000000
-
{c=>2,a=>67,b=>3}
430000000b
430000000b00
430000000b000000
430000000b000000
-
{c=>1,a=>85,b=>0}
5500000004
550000000400
5500000004000000
5500000004000000
=
struct force_align2 {
  long a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
};
-
{c=>1,a=>113,b=>1}
7100000005
710000000500
7100000005000000
7100000005000000
-
{c=>0,a=>-59,b=>2}
c5ffffff02
c5ffffff0200
c5ffffff02000000
c5ffffff02000000
-
{c=>2,a=>115,b=>1}
7300000009
730000000900
7300000009000000
7300000009000000
-
{c=>1,a=>-97,b=>3}
9fffffff07
9fffffff0700
9fffffff07000000
9fffffff07000000
-
{c=>2,a=>38,b=>2}
260000000a
260000000a00
260000000a000000
260000000a000000
=
struct force_align2 {
  long a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
  unsigned char  d:2;
};
-
{c=>2,a=>14,b=>0,d=>0}
0e0000000800
0e0000000800
0e00000008000000
0e00000008000000
-
{c=>3,a=>-56,b=>0,d=>3}
c8ffffff0c03
c8ffffff0c03
c8ffffff0c030000
c8ffffff0c030000
-
{c=>1,a=>84,b=>0,d=>2}
540000000402
540000000402
5400000004020000
5400000004020000
-
{c=>1,a=>-54,b=>2,d=>0}
caffffff0600
caffffff0600
caffffff06000000
caffffff06000000
-
{c=>0,a=>61,b=>2,d=>0}
3d0000000200
3d0000000200
3d00000002000000
3d00000002000000
=
struct force_align2 {
  long a;
  unsigned char  b:2;
  unsigned char  c:2;
  unsigned char   :0;
  unsigned char  d:2;
  unsigned short e;
};
-
{e=>109,c=>0,a=>66,b=>0,d=>1}
4200000000016d00
4200000000016d00
4200000000016d00
4200000000016d00
-
{e=>167,c=>2,a=>-15,b=>2,d=>0}
f1ffffff0a00a700
f1ffffff0a00a700
f1ffffff0a00a700
f1ffffff0a00a700
-
{e=>39,c=>1,a=>92,b=>1,d=>3}
5c00000005032700
5c00000005032700
5c00000005032700
5c00000005032700
-
{e=>135,c=>3,a=>-67,b=>0,d=>2}
bdffffff0c028700
bdffffff0c028700
bdffffff0c028700
bdffffff0c028700
-
{e=>180,c=>1,a=>38,b=>0,d=>0}
260000000400b400
260000000400b400
260000000400b400
260000000400b400
=
struct mixed1 {
  unsigned int a:1;
};
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>1}
01000000
01000000
01000000
01000000
-
{a=>1}
01000000
01000000
01000000
01000000
-
{a=>0}
00000000
00000000
00000000
00000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
};
-
{a=>1,b=>0}
01000000
01000000
01000000
01000000
-
{a=>1,b=>0}
01000000
01000000
01000000
01000000
-
{a=>1,b=>0}
01000000
01000000
01000000
01000000
-
{a=>1,b=>1}
03000000
03000000
03000000
03000000
-
{a=>1,b=>0}
01000000
01000000
01000000
01000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
  unsigned int  :0;
};
-
{a=>0,b=>1}
02000000
02000000
02000000
02000000
-
{a=>1,b=>0}
01000000
01000000
01000000
01000000
-
{a=>0,b=>1}
02000000
02000000
02000000
02000000
-
{a=>0,b=>0}
00000000
00000000
00000000
00000000
-
{a=>1,b=>1}
03000000
03000000
03000000
03000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
  unsigned int  :0;
  unsigned int c:1;
};
-
{c=>1,a=>0,b=>0}
0000000001000000
0000000001000000
0000000001000000
0000000001000000
-
{c=>1,a=>1,b=>1}
0300000001000000
0300000001000000
0300000001000000
0300000001000000
-
{c=>0,a=>1,b=>0}
0100000000000000
0100000000000000
0100000000000000
0100000000000000
-
{c=>0,a=>0,b=>1}
0200000000000000
0200000000000000
0200000000000000
0200000000000000
-
{c=>0,a=>1,b=>0}
0100000000000000
0100000000000000
0100000000000000
0100000000000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
  unsigned int  :0;
  unsigned int c:1;
  signed   int d:1;
};
-
{c=>0,a=>1,b=>1,d=>0}
0300000000000000
0300000000000000
0300000000000000
0300000000000000
-
{c=>0,a=>1,b=>1,d=>-1}
0300000002000000
0300000002000000
0300000002000000
0300000002000000
-
{c=>1,a=>0,b=>0,d=>0}
0000000001000000
0000000001000000
0000000001000000
0000000001000000
-
{c=>0,a=>1,b=>1,d=>-1}
0300000002000000
0300000002000000
0300000002000000
0300000002000000
-
{c=>0,a=>1,b=>0,d=>0}
0100000000000000
0100000000000000
0100000000000000
0100000000000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
  unsigned int  :0;
  unsigned int c:1;
  signed   int d:1;
  signed   int e:1;
};
-
{e=>0,c=>0,a=>0,b=>1,d=>0}
0200000000000000
0200000000000000
0200000000000000
0200000000000000
-
{e=>-1,c=>0,a=>0,b=>1,d=>-1}
0200000006000000
0200000006000000
0200000006000000
0200000006000000
-
{e=>0,c=>0,a=>1,b=>1,d=>-1}
0300000002000000
0300000002000000
0300000002000000
0300000002000000
-
{e=>-1,c=>1,a=>1,b=>0,d=>-1}
0100000007000000
0100000007000000
0100000007000000
0100000007000000
-
{e=>0,c=>0,a=>0,b=>0,d=>0}
0000000000000000
0000000000000000
0000000000000000
0000000000000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
  unsigned int  :0;
  unsigned int c:1;
  signed   int d:1;
  signed   int e:1;
  signed   int  :0;
};
-
{e=>-1,c=>0,a=>1,b=>0,d=>-1}
0100000006000000
0100000006000000
0100000006000000
0100000006000000
-
{e=>0,c=>1,a=>1,b=>0,d=>0}
0100000001000000
0100000001000000
0100000001000000
0100000001000000
-
{e=>-1,c=>0,a=>1,b=>0,d=>0}
0100000004000000
0100000004000000
0100000004000000
0100000004000000
-
{e=>0,c=>1,a=>0,b=>1,d=>-1}
0200000003000000
0200000003000000
0200000003000000
0200000003000000
-
{e=>-1,c=>1,a=>1,b=>1,d=>-1}
0300000007000000
0300000007000000
0300000007000000
0300000007000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
  unsigned int  :0;
  unsigned int c:1;
  signed   int d:1;
  signed   int e:1;
  signed   int  :0;
  signed   int f:1;
};
-
{e=>-1,c=>1,a=>0,b=>1,d=>-1,f=>-1}
020000000700000001000000
020000000700000001000000
020000000700000001000000
020000000700000001000000
-
{e=>-1,c=>0,a=>0,b=>1,d=>0,f=>-1}
020000000400000001000000
020000000400000001000000
020000000400000001000000
020000000400000001000000
-
{e=>-1,c=>1,a=>0,b=>1,d=>-1,f=>-1}
020000000700000001000000
020000000700000001000000
020000000700000001000000
020000000700000001000000
-
{e=>0,c=>1,a=>0,b=>0,d=>0,f=>-1}
000000000100000001000000
000000000100000001000000
000000000100000001000000
000000000100000001000000
-
{e=>-1,c=>1,a=>0,b=>1,d=>-1,f=>-1}
020000000700000001000000
020000000700000001000000
020000000700000001000000
020000000700000001000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
  unsigned int  :0;
  unsigned int c:1;
  signed   int d:1;
  signed   int e:1;
  signed   int  :0;
  signed   int f:1;
  int          g:1;
};
-
{e=>0,c=>1,a=>1,g=>-1,b=>1,d=>-1,f=>-1}
030000000300000003000000
030000000300000003000000
030000000300000003000000
030000000300000003000000
-
{e=>0,c=>0,a=>1,g=>-1,b=>1,d=>0,f=>-1}
030000000000000003000000
030000000000000003000000
030000000000000003000000
030000000000000003000000
-
{e=>0,c=>0,a=>0,g=>-1,b=>0,d=>0,f=>-1}
000000000000000003000000
000000000000000003000000
000000000000000003000000
000000000000000003000000
-
{e=>0,c=>1,a=>1,g=>0,b=>1,d=>0,f=>0}
030000000100000000000000
030000000100000000000000
030000000100000000000000
030000000100000000000000
-
{e=>0,c=>1,a=>0,g=>-1,b=>1,d=>0,f=>0}
020000000100000002000000
020000000100000002000000
020000000100000002000000
020000000100000002000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
  unsigned int  :0;
  unsigned int c:1;
  signed   int d:1;
  signed   int e:1;
  signed   int  :0;
  signed   int f:1;
  int          g:1;
  int          h:1;
};
-
{e=>0,a=>1,d=>-1,c=>0,h=>0,b=>1,g=>-1,f=>-1}
030000000200000003000000
030000000200000003000000
030000000200000003000000
030000000200000003000000
-
{e=>0,a=>0,d=>0,c=>0,h=>-1,b=>1,g=>-1,f=>-1}
020000000000000007000000
020000000000000007000000
020000000000000007000000
020000000000000007000000
-
{e=>0,a=>0,d=>-1,c=>1,h=>0,b=>1,g=>-1,f=>0}
020000000300000002000000
020000000300000002000000
020000000300000002000000
020000000300000002000000
-
{e=>0,a=>0,d=>-1,c=>1,h=>-1,b=>0,g=>-1,f=>0}
000000000300000006000000
000000000300000006000000
000000000300000006000000
000000000300000006000000
-
{e=>0,a=>1,d=>-1,c=>0,h=>-1,b=>1,g=>0,f=>-1}
030000000200000005000000
030000000200000005000000
030000000200000005000000
030000000200000005000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
  unsigned int  :0;
  unsigned int c:1;
  signed   int d:1;
  signed   int e:1;
  signed   int  :0;
  signed   int f:1;
  int          g:1;
  int          h:1;
  int           :0;
};
-
{e=>0,a=>1,d=>0,c=>0,h=>-1,b=>0,g=>0,f=>-1}
010000000000000005000000
010000000000000005000000
010000000000000005000000
010000000000000005000000
-
{e=>0,a=>1,d=>-1,c=>0,h=>-1,b=>0,g=>0,f=>-1}
010000000200000005000000
010000000200000005000000
010000000200000005000000
010000000200000005000000
-
{e=>-1,a=>0,d=>0,c=>0,h=>0,b=>1,g=>0,f=>-1}
020000000400000001000000
020000000400000001000000
020000000400000001000000
020000000400000001000000
-
{e=>0,a=>1,d=>-1,c=>0,h=>-1,b=>1,g=>0,f=>-1}
030000000200000005000000
030000000200000005000000
030000000200000005000000
030000000200000005000000
-
{e=>-1,a=>1,d=>0,c=>0,h=>0,b=>0,g=>-1,f=>-1}
010000000400000003000000
010000000400000003000000
010000000400000003000000
010000000400000003000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
  unsigned int  :0;
  unsigned int c:1;
  signed   int d:1;
  signed   int e:1;
  signed   int  :0;
  signed   int f:1;
  int          g:1;
  int          h:1;
  int           :0;
  int          i:1;
};
-
{e=>-1,a=>1,d=>0,c=>1,h=>-1,b=>0,g=>-1,f=>-1,i=>0}
01000000050000000700000000000000
01000000050000000700000000000000
01000000050000000700000000000000
01000000050000000700000000000000
-
{e=>0,a=>1,d=>0,c=>0,h=>-1,b=>0,g=>0,f=>-1,i=>0}
01000000000000000500000000000000
01000000000000000500000000000000
01000000000000000500000000000000
01000000000000000500000000000000
-
{e=>0,a=>1,d=>-1,c=>1,h=>-1,b=>0,g=>0,f=>-1,i=>0}
01000000030000000500000000000000
01000000030000000500000000000000
01000000030000000500000000000000
01000000030000000500000000000000
-
{e=>0,a=>1,d=>-1,c=>1,h=>-1,b=>1,g=>0,f=>-1,i=>0}
03000000030000000500000000000000
03000000030000000500000000000000
03000000030000000500000000000000
03000000030000000500000000000000
-
{e=>-1,a=>1,d=>-1,c=>0,h=>-1,b=>0,g=>-1,f=>0,i=>-1}
01000000060000000600000001000000
01000000060000000600000001000000
01000000060000000600000001000000
01000000060000000600000001000000
=
struct mixed1 {
  unsigned int a:1;
  unsigned int b:1;
  unsigned int  :0;
  unsigned int c:1;
  signed   int d:1;
  signed   int e:1;
  signed   int  :0;
  signed   int f:1;
  int          g:1;
  int          h:1;
  int           :0;
  int          i:1;
  long         j;
};
-
{e=>-1,a=>0,d=>-1,j=>95,c=>0,h=>-1,b=>0,g=>-1,f=>0,i=>-1}
000000000600000006000000010000005f000000
000000000600000006000000010000005f000000
000000000600000006000000010000005f000000
000000000600000006000000010000005f000000
-
{e=>-1,a=>0,d=>0,j=>6,c=>1,h=>-1,b=>1,g=>0,f=>-1,i=>0}
0200000005000000050000000000000006000000
0200000005000000050000000000000006000000
0200000005000000050000000000000006000000
0200000005000000050000000000000006000000
-
{e=>0,a=>1,d=>-1,j=>2,c=>1,h=>0,b=>1,g=>0,f=>-1,i=>-1}
0300000003000000010000000100000002000000
0300000003000000010000000100000002000000
0300000003000000010000000100000002000000
0300000003000000010000000100000002000000
-
{e=>0,a=>1,d=>0,j=>29,c=>0,h=>0,b=>1,g=>0,f=>0,i=>-1}
030000000000000000000000010000001d000000
030000000000000000000000010000001d000000
030000000000000000000000010000001d000000
030000000000000000000000010000001d000000
-
{e=>0,a=>0,d=>-1,j=>-28,c=>0,h=>-1,b=>1,g=>-1,f=>-1,i=>0}
02000000020000000700000000000000e4ffffff
02000000020000000700000000000000e4ffffff
02000000020000000700000000000000e4ffffff
02000000020000000700000000000000e4ffffff
=
struct mixed1 {
  char a;
  unsigned int b:1;
};
-
{a=>110,b=>1}
6e01000000
6e0001000000
6e00000001000000
6e00000001000000
-
{a=>-117,b=>1}
8b01000000
8b0001000000
8b00000001000000
8b00000001000000
-
{a=>-103,b=>0}
9900000000
990000000000
9900000000000000
9900000000000000
-
{a=>-42,b=>0}
d600000000
d60000000000
d600000000000000
d600000000000000
-
{a=>71,b=>1}
4701000000
470001000000
4700000001000000
4700000001000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
};
-
{c=>0,a=>53,b=>0}
3500000000
350000000000
3500000000000000
3500000000000000
-
{c=>1,a=>5,b=>1}
0503000000
050003000000
0500000003000000
0500000003000000
-
{c=>0,a=>-80,b=>0}
b000000000
b00000000000
b000000000000000
b000000000000000
-
{c=>1,a=>100,b=>0}
6402000000
640002000000
6400000002000000
6400000002000000
-
{c=>1,a=>-94,b=>1}
a203000000
a20003000000
a200000003000000
a200000003000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
};
-
{c=>0,a=>-121,b=>1}
8701000000
870001000000
8700000001000000
8700000001000000
-
{c=>0,a=>-57,b=>1}
c701000000
c70001000000
c700000001000000
c700000001000000
-
{c=>0,a=>37,b=>1}
2501000000
250001000000
2500000001000000
2500000001000000
-
{c=>1,a=>37,b=>1}
2503000000
250003000000
2500000003000000
2500000003000000
-
{c=>0,a=>-110,b=>0}
9200000000
920000000000
9200000000000000
9200000000000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
};
-
{c=>0,a=>43,b=>0,d=>0}
2b0000000000000000
2b000000000000000000
2b0000000000000000000000
2b0000000000000000000000
-
{c=>1,a=>72,b=>1,d=>0}
480300000000000000
48000300000000000000
480000000300000000000000
480000000300000000000000
-
{c=>1,a=>70,b=>0,d=>0}
460200000000000000
46000200000000000000
460000000200000000000000
460000000200000000000000
-
{c=>1,a=>50,b=>1,d=>0}
320300000000000000
32000300000000000000
320000000300000000000000
320000000300000000000000
-
{c=>0,a=>104,b=>0,d=>0}
680000000000000000
68000000000000000000
680000000000000000000000
680000000000000000000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
};
-
{e=>0,c=>0,a=>48,b=>1,d=>1}
300100000001000000
30000100000001000000
300000000100000001000000
300000000100000001000000
-
{e=>-1,c=>0,a=>-115,b=>1,d=>0}
8d0100000002000000
8d000100000002000000
8d0000000100000002000000
8d0000000100000002000000
-
{e=>-1,c=>1,a=>-71,b=>0,d=>1}
b90200000003000000
b9000200000003000000
b90000000200000003000000
b90000000200000003000000
-
{e=>-1,c=>0,a=>38,b=>0,d=>0}
260000000002000000
26000000000002000000
260000000000000002000000
260000000000000002000000
-
{e=>-1,c=>1,a=>110,b=>0,d=>0}
6e0200000002000000
6e000200000002000000
6e0000000200000002000000
6e0000000200000002000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
};
-
{e=>0,c=>0,a=>-12,b=>0,d=>1,f=>0}
f40000000001000000
f4000000000001000000
f40000000000000001000000
f40000000000000001000000
-
{e=>0,c=>0,a=>5,b=>0,d=>1,f=>0}
050000000001000000
05000000000001000000
050000000000000001000000
050000000000000001000000
-
{e=>-1,c=>1,a=>47,b=>0,d=>0,f=>0}
2f0200000002000000
2f000200000002000000
2f0000000200000002000000
2f0000000200000002000000
-
{e=>-1,c=>1,a=>87,b=>0,d=>0,f=>-1}
570200000006000000
57000200000006000000
570000000200000006000000
570000000200000006000000
-
{e=>0,c=>0,a=>-26,b=>1,d=>1,f=>0}
e60100000001000000
e6000100000001000000
e60000000100000001000000
e60000000100000001000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
};
-
{e=>0,c=>0,a=>-46,b=>1,d=>1,f=>0}
d20100000001000000
d2000100000001000000
d20000000100000001000000
d20000000100000001000000
-
{e=>-1,c=>0,a=>-8,b=>1,d=>1,f=>0}
f80100000003000000
f8000100000003000000
f80000000100000003000000
f80000000100000003000000
-
{e=>-1,c=>1,a=>-104,b=>1,d=>0,f=>-1}
980300000006000000
98000300000006000000
980000000300000006000000
980000000300000006000000
-
{e=>0,c=>1,a=>111,b=>1,d=>1,f=>0}
6f0300000001000000
6f000300000001000000
6f0000000300000001000000
6f0000000300000001000000
-
{e=>-1,c=>1,a=>66,b=>1,d=>0,f=>-1}
420300000006000000
42000300000006000000
420000000300000006000000
420000000300000006000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
};
-
{e=>0,c=>0,a=>33,g=>0,b=>1,d=>1,f=>-1}
21010000000500000000000000
2100010000000500000000000000
21000000010000000500000000000000
21000000010000000500000000000000
-
{e=>0,c=>1,a=>-26,g=>0,b=>1,d=>1,f=>-1}
e6030000000500000000000000
e600030000000500000000000000
e6000000030000000500000000000000
e6000000030000000500000000000000
-
{e=>-1,c=>1,a=>-58,g=>0,b=>0,d=>1,f=>-1}
c6020000000700000000000000
c600020000000700000000000000
c6000000020000000700000000000000
c6000000020000000700000000000000
-
{e=>0,c=>1,a=>-27,g=>-1,b=>0,d=>0,f=>-1}
e5020000000400000001000000
e500020000000400000001000000
e5000000020000000400000001000000
e5000000020000000400000001000000
-
{e=>-1,c=>1,a=>-33,g=>0,b=>0,d=>1,f=>0}
df020000000300000000000000
df00020000000300000000000000
df000000020000000300000000000000
df000000020000000300000000000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
};
-
{e=>-1,a=>40,d=>0,c=>1,h=>0,b=>1,g=>0,f=>0}
28030000000200000000000000
2800030000000200000000000000
28000000030000000200000000000000
28000000030000000200000000000000
-
{e=>-1,a=>123,d=>0,c=>0,h=>0,b=>1,g=>-1,f=>-1}
7b010000000600000001000000
7b00010000000600000001000000
7b000000010000000600000001000000
7b000000010000000600000001000000
-
{e=>-1,a=>102,d=>0,c=>1,h=>0,b=>0,g=>-1,f=>-1}
66020000000600000001000000
6600020000000600000001000000
66000000020000000600000001000000
66000000020000000600000001000000
-
{e=>0,a=>-10,d=>1,c=>1,h=>-1,b=>1,g=>0,f=>-1}
f6030000000500000002000000
f600030000000500000002000000
f6000000030000000500000002000000
f6000000030000000500000002000000
-
{e=>0,a=>49,d=>1,c=>0,h=>0,b=>0,g=>-1,f=>-1}
31000000000500000001000000
3100000000000500000001000000
31000000000000000500000001000000
31000000000000000500000001000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
};
-
{e=>-1,a=>-11,d=>1,c=>1,h=>-1,b=>1,g=>-1,f=>0,i=>-1}
f5030000000300000007000000
f500030000000300000007000000
f5000000030000000300000007000000
f5000000030000000300000007000000
-
{e=>0,a=>-102,d=>0,c=>0,h=>0,b=>0,g=>-1,f=>-1,i=>0}
9a000000000400000001000000
9a00000000000400000001000000
9a000000000000000400000001000000
9a000000000000000400000001000000
-
{e=>0,a=>-33,d=>1,c=>0,h=>-1,b=>0,g=>0,f=>0,i=>0}
df000000000100000002000000
df00000000000100000002000000
df000000000000000100000002000000
df000000000000000100000002000000
-
{e=>-1,a=>-96,d=>1,c=>0,h=>0,b=>1,g=>0,f=>0,i=>0}
a0010000000300000000000000
a000010000000300000000000000
a0000000010000000300000000000000
a0000000010000000300000000000000
-
{e=>-1,a=>125,d=>1,c=>1,h=>-1,b=>0,g=>0,f=>-1,i=>-1}
7d020000000700000006000000
7d00020000000700000006000000
7d000000020000000700000006000000
7d000000020000000700000006000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
};
-
{e=>-1,a=>-41,d=>0,c=>0,h=>-1,b=>1,g=>-1,f=>-1,i=>-1}
d7010000000600000007000000
d700010000000600000007000000
d7000000010000000600000007000000
d7000000010000000600000007000000
-
{e=>-1,a=>51,d=>1,c=>0,h=>-1,b=>1,g=>-1,f=>-1,i=>0}
33010000000700000003000000
3300010000000700000003000000
33000000010000000700000003000000
33000000010000000700000003000000
-
{e=>0,a=>43,d=>0,c=>0,h=>0,b=>1,g=>0,f=>-1,i=>-1}
2b010000000400000004000000
2b00010000000400000004000000
2b000000010000000400000004000000
2b000000010000000400000004000000
-
{e=>0,a=>33,d=>0,c=>1,h=>-1,b=>0,g=>0,f=>0,i=>-1}
21020000000000000006000000
2100020000000000000006000000
21000000020000000000000006000000
21000000020000000000000006000000
-
{e=>-1,a=>-111,d=>1,c=>1,h=>0,b=>0,g=>0,f=>-1,i=>0}
91020000000700000000000000
9100020000000700000000000000
91000000020000000700000000000000
91000000020000000700000000000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
  int          j:1;
};
-
{e=>-1,a=>-32,d=>0,j=>-1,c=>1,h=>-1,b=>0,g=>-1,f=>0,i=>0}
e002000000020000000300000001000000
e00002000000020000000300000001000000
e000000002000000020000000300000001000000
e000000002000000020000000300000001000000
-
{e=>0,a=>-11,d=>0,j=>0,c=>1,h=>0,b=>1,g=>-1,f=>-1,i=>-1}
f503000000040000000500000000000000
f50003000000040000000500000000000000
f500000003000000040000000500000000000000
f500000003000000040000000500000000000000
-
{e=>0,a=>-110,d=>1,j=>-1,c=>1,h=>-1,b=>1,g=>-1,f=>0,i=>-1}
9203000000010000000700000001000000
920003000000010000000700000001000000
9200000003000000010000000700000001000000
9200000003000000010000000700000001000000
-
{e=>-1,a=>-1,d=>0,j=>-1,c=>1,h=>-1,b=>0,g=>-1,f=>0,i=>-1}
ff02000000020000000700000001000000
ff0002000000020000000700000001000000
ff00000002000000020000000700000001000000
ff00000002000000020000000700000001000000
-
{e=>0,a=>-47,d=>0,j=>-1,c=>1,h=>0,b=>1,g=>0,f=>0,i=>-1}
d103000000000000000400000001000000
d10003000000000000000400000001000000
d100000003000000000000000400000001000000
d100000003000000000000000400000001000000
=
struct mixed1 {
  char a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
  int          j:1;
  long         k;
};
-
{e=>0,a=>-103,d=>1,j=>0,c=>1,k=>81,h=>0,b=>1,g=>0,f=>0,i=>0}
990300000001000000000000000000000051000000
99000300000001000000000000000000000051000000
990000000300000001000000000000000000000051000000
990000000300000001000000000000000000000051000000
-
{e=>0,a=>5,d=>0,j=>0,c=>1,k=>-43,h=>0,b=>0,g=>0,f=>-1,i=>-1}
0502000000040000000400000000000000d5ffffff
050002000000040000000400000000000000d5ffffff
0500000002000000040000000400000000000000d5ffffff
0500000002000000040000000400000000000000d5ffffff
-
{e=>0,a=>48,d=>0,j=>0,c=>1,k=>-96,h=>0,b=>0,g=>0,f=>-1,i=>0}
3002000000040000000000000000000000a0ffffff
300002000000040000000000000000000000a0ffffff
3000000002000000040000000000000000000000a0ffffff
3000000002000000040000000000000000000000a0ffffff
-
{e=>-1,a=>113,d=>0,j=>-1,c=>1,k=>-112,h=>-1,b=>1,g=>0,f=>-1,i=>0}
710300000006000000020000000100000090ffffff
71000300000006000000020000000100000090ffffff
710000000300000006000000020000000100000090ffffff
710000000300000006000000020000000100000090ffffff
-
{e=>0,a=>124,d=>1,j=>-1,c=>1,k=>62,h=>0,b=>0,g=>0,f=>-1,i=>0}
7c020000000500000000000000010000003e000000
7c00020000000500000000000000010000003e000000
7c000000020000000500000000000000010000003e000000
7c000000020000000500000000000000010000003e000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
};
-
{a=>110,b=>1}
6e0001000000
6e0001000000
6e00000001000000
6e00000001000000
-
{a=>-33,b=>1}
dfff01000000
dfff01000000
dfff000001000000
dfff000001000000
-
{a=>-68,b=>0}
bcff00000000
bcff00000000
bcff000000000000
bcff000000000000
-
{a=>-44,b=>1}
d4ff01000000
d4ff01000000
d4ff000001000000
d4ff000001000000
-
{a=>94,b=>0}
5e0000000000
5e0000000000
5e00000000000000
5e00000000000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
};
-
{c=>1,a=>-20,b=>1}
ecff03000000
ecff03000000
ecff000003000000
ecff000003000000
-
{c=>1,a=>-53,b=>1}
cbff03000000
cbff03000000
cbff000003000000
cbff000003000000
-
{c=>1,a=>123,b=>0}
7b0002000000
7b0002000000
7b00000002000000
7b00000002000000
-
{c=>1,a=>-52,b=>0}
ccff02000000
ccff02000000
ccff000002000000
ccff000002000000
-
{c=>1,a=>93,b=>0}
5d0002000000
5d0002000000
5d00000002000000
5d00000002000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
};
-
{c=>1,a=>110,b=>0}
6e0002000000
6e0002000000
6e00000002000000
6e00000002000000
-
{c=>0,a=>51,b=>0}
330000000000
330000000000
3300000000000000
3300000000000000
-
{c=>0,a=>118,b=>0}
760000000000
760000000000
7600000000000000
7600000000000000
-
{c=>1,a=>27,b=>1}
1b0003000000
1b0003000000
1b00000003000000
1b00000003000000
-
{c=>0,a=>-97,b=>1}
9fff01000000
9fff01000000
9fff000001000000
9fff000001000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
};
-
{c=>1,a=>102,b=>1,d=>0}
66000300000000000000
66000300000000000000
660000000300000000000000
660000000300000000000000
-
{c=>0,a=>-89,b=>1,d=>0}
a7ff0100000000000000
a7ff0100000000000000
a7ff00000100000000000000
a7ff00000100000000000000
-
{c=>1,a=>37,b=>0,d=>0}
25000200000000000000
25000200000000000000
250000000200000000000000
250000000200000000000000
-
{c=>1,a=>111,b=>1,d=>0}
6f000300000000000000
6f000300000000000000
6f0000000300000000000000
6f0000000300000000000000
-
{c=>0,a=>33,b=>0,d=>0}
21000000000000000000
21000000000000000000
210000000000000000000000
210000000000000000000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
};
-
{e=>0,c=>1,a=>-77,b=>0,d=>0}
b3ff0200000000000000
b3ff0200000000000000
b3ff00000200000000000000
b3ff00000200000000000000
-
{e=>-1,c=>0,a=>73,b=>1,d=>1}
49000100000003000000
49000100000003000000
490000000100000003000000
490000000100000003000000
-
{e=>-1,c=>0,a=>50,b=>1,d=>0}
32000100000002000000
32000100000002000000
320000000100000002000000
320000000100000002000000
-
{e=>0,c=>1,a=>-125,b=>0,d=>1}
83ff0200000001000000
83ff0200000001000000
83ff00000200000001000000
83ff00000200000001000000
-
{e=>0,c=>0,a=>55,b=>1,d=>0}
37000100000000000000
37000100000000000000
370000000100000000000000
370000000100000000000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
};
-
{e=>0,c=>1,a=>-25,b=>1,d=>1,f=>-1}
e7ff0300000005000000
e7ff0300000005000000
e7ff00000300000005000000
e7ff00000300000005000000
-
{e=>0,c=>0,a=>110,b=>0,d=>0,f=>-1}
6e000000000004000000
6e000000000004000000
6e0000000000000004000000
6e0000000000000004000000
-
{e=>0,c=>0,a=>-28,b=>1,d=>0,f=>0}
e4ff0100000000000000
e4ff0100000000000000
e4ff00000100000000000000
e4ff00000100000000000000
-
{e=>0,c=>1,a=>38,b=>1,d=>1,f=>0}
26000300000001000000
26000300000001000000
260000000300000001000000
260000000300000001000000
-
{e=>-1,c=>0,a=>38,b=>0,d=>1,f=>-1}
26000000000007000000
26000000000007000000
260000000000000007000000
260000000000000007000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
};
-
{e=>0,c=>0,a=>-35,b=>1,d=>1,f=>-1}
ddff0100000005000000
ddff0100000005000000
ddff00000100000005000000
ddff00000100000005000000
-
{e=>0,c=>0,a=>-82,b=>0,d=>0,f=>0}
aeff0000000000000000
aeff0000000000000000
aeff00000000000000000000
aeff00000000000000000000
-
{e=>0,c=>0,a=>-124,b=>1,d=>0,f=>0}
84ff0100000000000000
84ff0100000000000000
84ff00000100000000000000
84ff00000100000000000000
-
{e=>0,c=>0,a=>-50,b=>0,d=>1,f=>0}
ceff0000000001000000
ceff0000000001000000
ceff00000000000001000000
ceff00000000000001000000
-
{e=>-1,c=>1,a=>-121,b=>0,d=>0,f=>-1}
87ff0200000006000000
87ff0200000006000000
87ff00000200000006000000
87ff00000200000006000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
};
-
{e=>-1,c=>1,a=>39,g=>0,b=>1,d=>1,f=>0}
2700030000000300000000000000
2700030000000300000000000000
27000000030000000300000000000000
27000000030000000300000000000000
-
{e=>-1,c=>0,a=>-21,g=>0,b=>0,d=>0,f=>0}
ebff000000000200000000000000
ebff000000000200000000000000
ebff0000000000000200000000000000
ebff0000000000000200000000000000
-
{e=>-1,c=>1,a=>-9,g=>-1,b=>1,d=>0,f=>0}
f7ff030000000200000001000000
f7ff030000000200000001000000
f7ff0000030000000200000001000000
f7ff0000030000000200000001000000
-
{e=>0,c=>0,a=>39,g=>-1,b=>0,d=>1,f=>0}
2700000000000100000001000000
2700000000000100000001000000
27000000000000000100000001000000
27000000000000000100000001000000
-
{e=>0,c=>0,a=>-23,g=>0,b=>1,d=>1,f=>0}
e9ff010000000100000000000000
e9ff010000000100000000000000
e9ff0000010000000100000000000000
e9ff0000010000000100000000000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
};
-
{e=>-1,a=>-109,d=>1,c=>1,h=>0,b=>0,g=>0,f=>-1}
93ff020000000700000000000000
93ff020000000700000000000000
93ff0000020000000700000000000000
93ff0000020000000700000000000000
-
{e=>0,a=>113,d=>1,c=>0,h=>-1,b=>0,g=>0,f=>-1}
7100000000000500000002000000
7100000000000500000002000000
71000000000000000500000002000000
71000000000000000500000002000000
-
{e=>-1,a=>115,d=>1,c=>0,h=>-1,b=>1,g=>-1,f=>0}
7300010000000300000003000000
7300010000000300000003000000
73000000010000000300000003000000
73000000010000000300000003000000
-
{e=>0,a=>86,d=>1,c=>0,h=>0,b=>0,g=>0,f=>0}
5600000000000100000000000000
5600000000000100000000000000
56000000000000000100000000000000
56000000000000000100000000000000
-
{e=>-1,a=>-14,d=>1,c=>1,h=>-1,b=>1,g=>-1,f=>0}
f2ff030000000300000003000000
f2ff030000000300000003000000
f2ff0000030000000300000003000000
f2ff0000030000000300000003000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
};
-
{e=>-1,a=>97,d=>1,c=>0,h=>-1,b=>0,g=>-1,f=>0,i=>0}
6100000000000300000003000000
6100000000000300000003000000
61000000000000000300000003000000
61000000000000000300000003000000
-
{e=>0,a=>-1,d=>0,c=>0,h=>-1,b=>1,g=>0,f=>0,i=>0}
ffff010000000000000002000000
ffff010000000000000002000000
ffff0000010000000000000002000000
ffff0000010000000000000002000000
-
{e=>-1,a=>62,d=>1,c=>0,h=>0,b=>0,g=>-1,f=>0,i=>-1}
3e00000000000300000005000000
3e00000000000300000005000000
3e000000000000000300000005000000
3e000000000000000300000005000000
-
{e=>0,a=>-110,d=>0,c=>0,h=>-1,b=>1,g=>0,f=>0,i=>-1}
92ff010000000000000006000000
92ff010000000000000006000000
92ff0000010000000000000006000000
92ff0000010000000000000006000000
-
{e=>0,a=>-40,d=>1,c=>0,h=>-1,b=>0,g=>0,f=>-1,i=>0}
d8ff000000000500000002000000
d8ff000000000500000002000000
d8ff0000000000000500000002000000
d8ff0000000000000500000002000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
};
-
{e=>-1,a=>-48,d=>0,c=>1,h=>0,b=>0,g=>0,f=>0,i=>0}
d0ff020000000200000000000000
d0ff020000000200000000000000
d0ff0000020000000200000000000000
d0ff0000020000000200000000000000
-
{e=>0,a=>27,d=>1,c=>0,h=>0,b=>0,g=>-1,f=>-1,i=>-1}
1b00000000000500000005000000
1b00000000000500000005000000
1b000000000000000500000005000000
1b000000000000000500000005000000
-
{e=>0,a=>47,d=>1,c=>0,h=>-1,b=>1,g=>0,f=>0,i=>-1}
2f00010000000100000006000000
2f00010000000100000006000000
2f000000010000000100000006000000
2f000000010000000100000006000000
-
{e=>-1,a=>24,d=>0,c=>1,h=>-1,b=>1,g=>-1,f=>-1,i=>-1}
1800030000000600000007000000
1800030000000600000007000000
18000000030000000600000007000000
18000000030000000600000007000000
-
{e=>0,a=>-105,d=>1,c=>1,h=>-1,b=>0,g=>-1,f=>0,i=>0}
97ff020000000100000003000000
97ff020000000100000003000000
97ff0000020000000100000003000000
97ff0000020000000100000003000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
  int          j:1;
};
-
{e=>-1,a=>-24,d=>0,j=>0,c=>1,h=>0,b=>0,g=>0,f=>0,i=>0}
e8ff02000000020000000000000000000000
e8ff02000000020000000000000000000000
e8ff000002000000020000000000000000000000
e8ff000002000000020000000000000000000000
-
{e=>-1,a=>-22,d=>0,j=>0,c=>1,h=>0,b=>0,g=>-1,f=>0,i=>0}
eaff02000000020000000100000000000000
eaff02000000020000000100000000000000
eaff000002000000020000000100000000000000
eaff000002000000020000000100000000000000
-
{e=>0,a=>-38,d=>0,j=>-1,c=>0,h=>-1,b=>1,g=>-1,f=>-1,i=>0}
daff01000000040000000300000001000000
daff01000000040000000300000001000000
daff000001000000040000000300000001000000
daff000001000000040000000300000001000000
-
{e=>0,a=>72,d=>1,j=>0,c=>1,h=>-1,b=>1,g=>0,f=>-1,i=>0}
480003000000050000000200000000000000
480003000000050000000200000000000000
4800000003000000050000000200000000000000
4800000003000000050000000200000000000000
-
{e=>0,a=>-62,d=>0,j=>0,c=>0,h=>0,b=>1,g=>-1,f=>-1,i=>0}
c2ff01000000040000000100000000000000
c2ff01000000040000000100000000000000
c2ff000001000000040000000100000000000000
c2ff000001000000040000000100000000000000
=
struct mixed1 {
  short a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
  int          j:1;
  long         k;
};
-
{e=>-1,a=>29,d=>0,j=>-1,c=>1,k=>-52,h=>-1,b=>1,g=>0,f=>0,i=>0}
1d0003000000020000000200000001000000ccffffff
1d0003000000020000000200000001000000ccffffff
1d00000003000000020000000200000001000000ccffffff
1d00000003000000020000000200000001000000ccffffff
-
{e=>0,a=>71,d=>0,j=>-1,c=>0,k=>11,h=>0,b=>0,g=>0,f=>0,i=>-1}
4700000000000000000004000000010000000b000000
4700000000000000000004000000010000000b000000
47000000000000000000000004000000010000000b000000
47000000000000000000000004000000010000000b000000
-
{e=>-1,a=>7,d=>0,j=>0,c=>0,k=>101,h=>-1,b=>0,g=>-1,f=>0,i=>-1}
07000000000002000000070000000000000065000000
07000000000002000000070000000000000065000000
070000000000000002000000070000000000000065000000
070000000000000002000000070000000000000065000000
-
{e=>-1,a=>-19,d=>1,j=>0,c=>0,k=>8,h=>-1,b=>1,g=>0,f=>0,i=>-1}
edff0100000003000000060000000000000008000000
edff0100000003000000060000000000000008000000
edff00000100000003000000060000000000000008000000
edff00000100000003000000060000000000000008000000
-
{e=>-1,a=>71,d=>1,j=>0,c=>0,k=>-64,h=>0,b=>1,g=>-1,f=>-1,i=>-1}
470001000000070000000500000000000000c0ffffff
470001000000070000000500000000000000c0ffffff
4700000001000000070000000500000000000000c0ffffff
4700000001000000070000000500000000000000c0ffffff
=
struct mixed1 {
  int a;
  unsigned int b:1;
};
-
{a=>-120,b=>0}
88ffffff00000000
88ffffff00000000
88ffffff00000000
88ffffff00000000
-
{a=>-74,b=>1}
b6ffffff01000000
b6ffffff01000000
b6ffffff01000000
b6ffffff01000000
-
{a=>-4,b=>1}
fcffffff01000000
fcffffff01000000
fcffffff01000000
fcffffff01000000
-
{a=>-89,b=>0}
a7ffffff00000000
a7ffffff00000000
a7ffffff00000000
a7ffffff00000000
-
{a=>95,b=>0}
5f00000000000000
5f00000000000000
5f00000000000000
5f00000000000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
};
-
{c=>0,a=>124,b=>1}
7c00000001000000
7c00000001000000
7c00000001000000
7c00000001000000
-
{c=>0,a=>97,b=>1}
6100000001000000
6100000001000000
6100000001000000
6100000001000000
-
{c=>0,a=>-1,b=>0}
ffffffff00000000
ffffffff00000000
ffffffff00000000
ffffffff00000000
-
{c=>0,a=>-59,b=>0}
c5ffffff00000000
c5ffffff00000000
c5ffffff00000000
c5ffffff00000000
-
{c=>1,a=>23,b=>1}
1700000003000000
1700000003000000
1700000003000000
1700000003000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
};
-
{c=>0,a=>1,b=>0}
0100000000000000
0100000000000000
0100000000000000
0100000000000000
-
{c=>0,a=>-43,b=>1}
d5ffffff01000000
d5ffffff01000000
d5ffffff01000000
d5ffffff01000000
-
{c=>0,a=>-32,b=>1}
e0ffffff01000000
e0ffffff01000000
e0ffffff01000000
e0ffffff01000000
-
{c=>0,a=>-65,b=>1}
bfffffff01000000
bfffffff01000000
bfffffff01000000
bfffffff01000000
-
{c=>0,a=>-14,b=>0}
f2ffffff00000000
f2ffffff00000000
f2ffffff00000000
f2ffffff00000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
};
-
{c=>0,a=>89,b=>0,d=>0}
590000000000000000000000
590000000000000000000000
590000000000000000000000
590000000000000000000000
-
{c=>0,a=>-30,b=>0,d=>1}
e2ffffff0000000001000000
e2ffffff0000000001000000
e2ffffff0000000001000000
e2ffffff0000000001000000
-
{c=>1,a=>-6,b=>0,d=>0}
faffffff0200000000000000
faffffff0200000000000000
faffffff0200000000000000
faffffff0200000000000000
-
{c=>1,a=>-16,b=>1,d=>0}
f0ffffff0300000000000000
f0ffffff0300000000000000
f0ffffff0300000000000000
f0ffffff0300000000000000
-
{c=>0,a=>94,b=>1,d=>1}
5e0000000100000001000000
5e0000000100000001000000
5e0000000100000001000000
5e0000000100000001000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
};
-
{e=>-1,c=>0,a=>-26,b=>1,d=>1}
e6ffffff0100000003000000
e6ffffff0100000003000000
e6ffffff0100000003000000
e6ffffff0100000003000000
-
{e=>0,c=>0,a=>-38,b=>1,d=>0}
daffffff0100000000000000
daffffff0100000000000000
daffffff0100000000000000
daffffff0100000000000000
-
{e=>-1,c=>1,a=>82,b=>1,d=>1}
520000000300000003000000
520000000300000003000000
520000000300000003000000
520000000300000003000000
-
{e=>-1,c=>1,a=>-3,b=>1,d=>0}
fdffffff0300000002000000
fdffffff0300000002000000
fdffffff0300000002000000
fdffffff0300000002000000
-
{e=>-1,c=>1,a=>104,b=>0,d=>1}
680000000200000003000000
680000000200000003000000
680000000200000003000000
680000000200000003000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
};
-
{e=>-1,c=>0,a=>-49,b=>0,d=>1,f=>0}
cfffffff0000000003000000
cfffffff0000000003000000
cfffffff0000000003000000
cfffffff0000000003000000
-
{e=>-1,c=>1,a=>-85,b=>0,d=>1,f=>-1}
abffffff0200000007000000
abffffff0200000007000000
abffffff0200000007000000
abffffff0200000007000000
-
{e=>0,c=>1,a=>-109,b=>0,d=>0,f=>0}
93ffffff0200000000000000
93ffffff0200000000000000
93ffffff0200000000000000
93ffffff0200000000000000
-
{e=>0,c=>0,a=>109,b=>0,d=>0,f=>0}
6d0000000000000000000000
6d0000000000000000000000
6d0000000000000000000000
6d0000000000000000000000
-
{e=>0,c=>1,a=>-3,b=>0,d=>0,f=>0}
fdffffff0200000000000000
fdffffff0200000000000000
fdffffff0200000000000000
fdffffff0200000000000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
};
-
{e=>0,c=>0,a=>-89,b=>0,d=>0,f=>-1}
a7ffffff0000000004000000
a7ffffff0000000004000000
a7ffffff0000000004000000
a7ffffff0000000004000000
-
{e=>-1,c=>0,a=>-6,b=>1,d=>1,f=>0}
faffffff0100000003000000
faffffff0100000003000000
faffffff0100000003000000
faffffff0100000003000000
-
{e=>0,c=>0,a=>-60,b=>0,d=>1,f=>0}
c4ffffff0000000001000000
c4ffffff0000000001000000
c4ffffff0000000001000000
c4ffffff0000000001000000
-
{e=>-1,c=>1,a=>-65,b=>0,d=>1,f=>0}
bfffffff0200000003000000
bfffffff0200000003000000
bfffffff0200000003000000
bfffffff0200000003000000
-
{e=>0,c=>0,a=>-92,b=>0,d=>0,f=>-1}
a4ffffff0000000004000000
a4ffffff0000000004000000
a4ffffff0000000004000000
a4ffffff0000000004000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
};
-
{e=>0,c=>1,a=>23,g=>0,b=>0,d=>0,f=>0}
17000000020000000000000000000000
17000000020000000000000000000000
17000000020000000000000000000000
17000000020000000000000000000000
-
{e=>0,c=>0,a=>-110,g=>-1,b=>1,d=>1,f=>0}
92ffffff010000000100000001000000
92ffffff010000000100000001000000
92ffffff010000000100000001000000
92ffffff010000000100000001000000
-
{e=>0,c=>1,a=>6,g=>0,b=>0,d=>1,f=>-1}
06000000020000000500000000000000
06000000020000000500000000000000
06000000020000000500000000000000
06000000020000000500000000000000
-
{e=>-1,c=>0,a=>-15,g=>-1,b=>0,d=>1,f=>0}
f1ffffff000000000300000001000000
f1ffffff000000000300000001000000
f1ffffff000000000300000001000000
f1ffffff000000000300000001000000
-
{e=>-1,c=>1,a=>-105,g=>-1,b=>1,d=>1,f=>-1}
97ffffff030000000700000001000000
97ffffff030000000700000001000000
97ffffff030000000700000001000000
97ffffff030000000700000001000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
};
-
{e=>-1,a=>-67,d=>0,c=>1,h=>-1,b=>1,g=>-1,f=>-1}
bdffffff030000000600000003000000
bdffffff030000000600000003000000
bdffffff030000000600000003000000
bdffffff030000000600000003000000
-
{e=>0,a=>16,d=>0,c=>1,h=>0,b=>0,g=>-1,f=>-1}
10000000020000000400000001000000
10000000020000000400000001000000
10000000020000000400000001000000
10000000020000000400000001000000
-
{e=>0,a=>75,d=>0,c=>0,h=>0,b=>0,g=>0,f=>-1}
4b000000000000000400000000000000
4b000000000000000400000000000000
4b000000000000000400000000000000
4b000000000000000400000000000000
-
{e=>-1,a=>-78,d=>0,c=>1,h=>0,b=>1,g=>-1,f=>0}
b2ffffff030000000200000001000000
b2ffffff030000000200000001000000
b2ffffff030000000200000001000000
b2ffffff030000000200000001000000
-
{e=>0,a=>50,d=>1,c=>1,h=>0,b=>1,g=>0,f=>0}
32000000030000000100000000000000
32000000030000000100000000000000
32000000030000000100000000000000
32000000030000000100000000000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
};
-
{e=>0,a=>45,d=>0,c=>1,h=>0,b=>0,g=>-1,f=>-1,i=>-1}
2d000000020000000400000005000000
2d000000020000000400000005000000
2d000000020000000400000005000000
2d000000020000000400000005000000
-
{e=>0,a=>-65,d=>1,c=>1,h=>-1,b=>0,g=>-1,f=>-1,i=>0}
bfffffff020000000500000003000000
bfffffff020000000500000003000000
bfffffff020000000500000003000000
bfffffff020000000500000003000000
-
{e=>-1,a=>5,d=>0,c=>1,h=>0,b=>1,g=>0,f=>-1,i=>0}
05000000030000000600000000000000
05000000030000000600000000000000
05000000030000000600000000000000
05000000030000000600000000000000
-
{e=>-1,a=>53,d=>1,c=>0,h=>-1,b=>1,g=>0,f=>-1,i=>-1}
35000000010000000700000006000000
35000000010000000700000006000000
35000000010000000700000006000000
35000000010000000700000006000000
-
{e=>-1,a=>-98,d=>0,c=>1,h=>-1,b=>1,g=>0,f=>0,i=>-1}
9effffff030000000200000006000000
9effffff030000000200000006000000
9effffff030000000200000006000000
9effffff030000000200000006000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
};
-
{e=>0,a=>79,d=>0,c=>0,h=>-1,b=>1,g=>-1,f=>0,i=>0}
4f000000010000000000000003000000
4f000000010000000000000003000000
4f000000010000000000000003000000
4f000000010000000000000003000000
-
{e=>0,a=>-115,d=>1,c=>0,h=>0,b=>1,g=>0,f=>-1,i=>-1}
8dffffff010000000500000004000000
8dffffff010000000500000004000000
8dffffff010000000500000004000000
8dffffff010000000500000004000000
-
{e=>-1,a=>-69,d=>0,c=>1,h=>-1,b=>1,g=>-1,f=>0,i=>0}
bbffffff030000000200000003000000
bbffffff030000000200000003000000
bbffffff030000000200000003000000
bbffffff030000000200000003000000
-
{e=>-1,a=>0,d=>0,c=>1,h=>0,b=>1,g=>-1,f=>0,i=>-1}
00000000030000000200000005000000
00000000030000000200000005000000
00000000030000000200000005000000
00000000030000000200000005000000
-
{e=>-1,a=>34,d=>1,c=>1,h=>0,b=>1,g=>0,f=>-1,i=>-1}
22000000030000000700000004000000
22000000030000000700000004000000
22000000030000000700000004000000
22000000030000000700000004000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
  int          j:1;
};
-
{e=>0,a=>67,d=>0,j=>0,c=>1,h=>0,b=>1,g=>0,f=>-1,i=>0}
4300000003000000040000000000000000000000
4300000003000000040000000000000000000000
4300000003000000040000000000000000000000
4300000003000000040000000000000000000000
-
{e=>0,a=>23,d=>0,j=>-1,c=>1,h=>0,b=>0,g=>-1,f=>-1,i=>-1}
1700000002000000040000000500000001000000
1700000002000000040000000500000001000000
1700000002000000040000000500000001000000
1700000002000000040000000500000001000000
-
{e=>0,a=>89,d=>0,j=>0,c=>0,h=>-1,b=>0,g=>-1,f=>-1,i=>0}
5900000000000000040000000300000000000000
5900000000000000040000000300000000000000
5900000000000000040000000300000000000000
5900000000000000040000000300000000000000
-
{e=>0,a=>-97,d=>0,j=>0,c=>1,h=>-1,b=>0,g=>-1,f=>0,i=>-1}
9fffffff02000000000000000700000000000000
9fffffff02000000000000000700000000000000
9fffffff02000000000000000700000000000000
9fffffff02000000000000000700000000000000
-
{e=>0,a=>-76,d=>1,j=>-1,c=>0,h=>-1,b=>1,g=>-1,f=>0,i=>0}
b4ffffff01000000010000000300000001000000
b4ffffff01000000010000000300000001000000
b4ffffff01000000010000000300000001000000
b4ffffff01000000010000000300000001000000
=
struct mixed1 {
  int a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
  int          j:1;
  long         k;
};
-
{e=>0,a=>-74,d=>1,j=>0,c=>1,k=>96,h=>0,b=>1,g=>-1,f=>0,i=>0}
b6ffffff0300000001000000010000000000000060000000
b6ffffff0300000001000000010000000000000060000000
b6ffffff0300000001000000010000000000000060000000
b6ffffff0300000001000000010000000000000060000000
-
{e=>0,a=>89,d=>1,j=>0,c=>0,k=>-51,h=>0,b=>0,g=>-1,f=>0,i=>-1}
5900000000000000010000000500000000000000cdffffff
5900000000000000010000000500000000000000cdffffff
5900000000000000010000000500000000000000cdffffff
5900000000000000010000000500000000000000cdffffff
-
{e=>-1,a=>48,d=>0,j=>0,c=>0,k=>116,h=>-1,b=>0,g=>-1,f=>0,i=>-1}
300000000000000002000000070000000000000074000000
300000000000000002000000070000000000000074000000
300000000000000002000000070000000000000074000000
300000000000000002000000070000000000000074000000
-
{e=>0,a=>-74,d=>0,j=>0,c=>1,k=>59,h=>0,b=>1,g=>0,f=>-1,i=>0}
b6ffffff030000000400000000000000000000003b000000
b6ffffff030000000400000000000000000000003b000000
b6ffffff030000000400000000000000000000003b000000
b6ffffff030000000400000000000000000000003b000000
-
{e=>-1,a=>63,d=>1,j=>-1,c=>0,k=>49,h=>0,b=>0,g=>-1,f=>0,i=>0}
3f0000000000000003000000010000000100000031000000
3f0000000000000003000000010000000100000031000000
3f0000000000000003000000010000000100000031000000
3f0000000000000003000000010000000100000031000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
};
-
{a=>-77,b=>1}
b3ffffff01000000
b3ffffff01000000
b3ffffff01000000
b3ffffff01000000
-
{a=>-4,b=>0}
fcffffff00000000
fcffffff00000000
fcffffff00000000
fcffffff00000000
-
{a=>106,b=>1}
6a00000001000000
6a00000001000000
6a00000001000000
6a00000001000000
-
{a=>-44,b=>1}
d4ffffff01000000
d4ffffff01000000
d4ffffff01000000
d4ffffff01000000
-
{a=>-88,b=>1}
a8ffffff01000000
a8ffffff01000000
a8ffffff01000000
a8ffffff01000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
};
-
{c=>0,a=>-69,b=>1}
bbffffff01000000
bbffffff01000000
bbffffff01000000
bbffffff01000000
-
{c=>0,a=>-85,b=>1}
abffffff01000000
abffffff01000000
abffffff01000000
abffffff01000000
-
{c=>0,a=>33,b=>1}
2100000001000000
2100000001000000
2100000001000000
2100000001000000
-
{c=>1,a=>40,b=>1}
2800000003000000
2800000003000000
2800000003000000
2800000003000000
-
{c=>0,a=>-14,b=>1}
f2ffffff01000000
f2ffffff01000000
f2ffffff01000000
f2ffffff01000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
};
-
{c=>0,a=>-30,b=>0}
e2ffffff00000000
e2ffffff00000000
e2ffffff00000000
e2ffffff00000000
-
{c=>0,a=>-60,b=>0}
c4ffffff00000000
c4ffffff00000000
c4ffffff00000000
c4ffffff00000000
-
{c=>1,a=>57,b=>0}
3900000002000000
3900000002000000
3900000002000000
3900000002000000
-
{c=>1,a=>11,b=>0}
0b00000002000000
0b00000002000000
0b00000002000000
0b00000002000000
-
{c=>1,a=>-73,b=>1}
b7ffffff03000000
b7ffffff03000000
b7ffffff03000000
b7ffffff03000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
};
-
{c=>0,a=>-46,b=>0,d=>1}
d2ffffff0000000001000000
d2ffffff0000000001000000
d2ffffff0000000001000000
d2ffffff0000000001000000
-
{c=>0,a=>27,b=>0,d=>0}
1b0000000000000000000000
1b0000000000000000000000
1b0000000000000000000000
1b0000000000000000000000
-
{c=>1,a=>1,b=>1,d=>0}
010000000300000000000000
010000000300000000000000
010000000300000000000000
010000000300000000000000
-
{c=>1,a=>71,b=>0,d=>0}
470000000200000000000000
470000000200000000000000
470000000200000000000000
470000000200000000000000
-
{c=>0,a=>-14,b=>1,d=>1}
f2ffffff0100000001000000
f2ffffff0100000001000000
f2ffffff0100000001000000
f2ffffff0100000001000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
};
-
{e=>-1,c=>1,a=>19,b=>0,d=>0}
130000000200000002000000
130000000200000002000000
130000000200000002000000
130000000200000002000000
-
{e=>-1,c=>1,a=>70,b=>0,d=>1}
460000000200000003000000
460000000200000003000000
460000000200000003000000
460000000200000003000000
-
{e=>-1,c=>1,a=>-112,b=>1,d=>0}
90ffffff0300000002000000
90ffffff0300000002000000
90ffffff0300000002000000
90ffffff0300000002000000
-
{e=>0,c=>0,a=>90,b=>0,d=>1}
5a0000000000000001000000
5a0000000000000001000000
5a0000000000000001000000
5a0000000000000001000000
-
{e=>-1,c=>1,a=>-16,b=>1,d=>0}
f0ffffff0300000002000000
f0ffffff0300000002000000
f0ffffff0300000002000000
f0ffffff0300000002000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
};
-
{e=>-1,c=>1,a=>92,b=>0,d=>0,f=>-1}
5c0000000200000006000000
5c0000000200000006000000
5c0000000200000006000000
5c0000000200000006000000
-
{e=>0,c=>1,a=>-112,b=>1,d=>0,f=>0}
90ffffff0300000000000000
90ffffff0300000000000000
90ffffff0300000000000000
90ffffff0300000000000000
-
{e=>-1,c=>0,a=>-75,b=>1,d=>1,f=>0}
b5ffffff0100000003000000
b5ffffff0100000003000000
b5ffffff0100000003000000
b5ffffff0100000003000000
-
{e=>0,c=>0,a=>-54,b=>1,d=>1,f=>-1}
caffffff0100000005000000
caffffff0100000005000000
caffffff0100000005000000
caffffff0100000005000000
-
{e=>0,c=>0,a=>-3,b=>0,d=>0,f=>-1}
fdffffff0000000004000000
fdffffff0000000004000000
fdffffff0000000004000000
fdffffff0000000004000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
};
-
{e=>0,c=>1,a=>99,b=>1,d=>0,f=>0}
630000000300000000000000
630000000300000000000000
630000000300000000000000
630000000300000000000000
-
{e=>0,c=>1,a=>121,b=>1,d=>1,f=>0}
790000000300000001000000
790000000300000001000000
790000000300000001000000
790000000300000001000000
-
{e=>0,c=>1,a=>101,b=>0,d=>0,f=>-1}
650000000200000004000000
650000000200000004000000
650000000200000004000000
650000000200000004000000
-
{e=>0,c=>1,a=>-100,b=>0,d=>0,f=>0}
9cffffff0200000000000000
9cffffff0200000000000000
9cffffff0200000000000000
9cffffff0200000000000000
-
{e=>0,c=>1,a=>-59,b=>0,d=>1,f=>0}
c5ffffff0200000001000000
c5ffffff0200000001000000
c5ffffff0200000001000000
c5ffffff0200000001000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
};
-
{e=>0,c=>0,a=>73,g=>-1,b=>1,d=>1,f=>-1}
49000000010000000500000001000000
49000000010000000500000001000000
49000000010000000500000001000000
49000000010000000500000001000000
-
{e=>0,c=>0,a=>11,g=>0,b=>1,d=>0,f=>0}
0b000000010000000000000000000000
0b000000010000000000000000000000
0b000000010000000000000000000000
0b000000010000000000000000000000
-
{e=>-1,c=>0,a=>-31,g=>-1,b=>1,d=>1,f=>0}
e1ffffff010000000300000001000000
e1ffffff010000000300000001000000
e1ffffff010000000300000001000000
e1ffffff010000000300000001000000
-
{e=>-1,c=>0,a=>-124,g=>-1,b=>1,d=>1,f=>-1}
84ffffff010000000700000001000000
84ffffff010000000700000001000000
84ffffff010000000700000001000000
84ffffff010000000700000001000000
-
{e=>-1,c=>0,a=>-42,g=>0,b=>1,d=>0,f=>-1}
d6ffffff010000000600000000000000
d6ffffff010000000600000000000000
d6ffffff010000000600000000000000
d6ffffff010000000600000000000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
};
-
{e=>-1,a=>86,d=>0,c=>0,h=>0,b=>0,g=>0,f=>-1}
56000000000000000600000000000000
56000000000000000600000000000000
56000000000000000600000000000000
56000000000000000600000000000000
-
{e=>-1,a=>-97,d=>1,c=>0,h=>0,b=>0,g=>-1,f=>-1}
9fffffff000000000700000001000000
9fffffff000000000700000001000000
9fffffff000000000700000001000000
9fffffff000000000700000001000000
-
{e=>0,a=>18,d=>0,c=>1,h=>-1,b=>0,g=>0,f=>0}
12000000020000000000000002000000
12000000020000000000000002000000
12000000020000000000000002000000
12000000020000000000000002000000
-
{e=>0,a=>-102,d=>0,c=>0,h=>-1,b=>1,g=>-1,f=>0}
9affffff010000000000000003000000
9affffff010000000000000003000000
9affffff010000000000000003000000
9affffff010000000000000003000000
-
{e=>0,a=>-36,d=>0,c=>0,h=>-1,b=>1,g=>0,f=>0}
dcffffff010000000000000002000000
dcffffff010000000000000002000000
dcffffff010000000000000002000000
dcffffff010000000000000002000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
};
-
{e=>-1,a=>83,d=>1,c=>1,h=>-1,b=>1,g=>-1,f=>-1,i=>0}
53000000030000000700000003000000
53000000030000000700000003000000
53000000030000000700000003000000
53000000030000000700000003000000
-
{e=>0,a=>35,d=>1,c=>0,h=>0,b=>1,g=>-1,f=>0,i=>0}
23000000010000000100000001000000
23000000010000000100000001000000
23000000010000000100000001000000
23000000010000000100000001000000
-
{e=>-1,a=>-48,d=>1,c=>1,h=>-1,b=>0,g=>0,f=>-1,i=>0}
d0ffffff020000000700000002000000
d0ffffff020000000700000002000000
d0ffffff020000000700000002000000
d0ffffff020000000700000002000000
-
{e=>-1,a=>47,d=>1,c=>1,h=>-1,b=>0,g=>0,f=>0,i=>0}
2f000000020000000300000002000000
2f000000020000000300000002000000
2f000000020000000300000002000000
2f000000020000000300000002000000
-
{e=>-1,a=>-92,d=>1,c=>0,h=>-1,b=>1,g=>-1,f=>0,i=>0}
a4ffffff010000000300000003000000
a4ffffff010000000300000003000000
a4ffffff010000000300000003000000
a4ffffff010000000300000003000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
};
-
{e=>0,a=>-32,d=>0,c=>0,h=>-1,b=>1,g=>-1,f=>-1,i=>0}
e0ffffff010000000400000003000000
e0ffffff010000000400000003000000
e0ffffff010000000400000003000000
e0ffffff010000000400000003000000
-
{e=>0,a=>-105,d=>1,c=>1,h=>0,b=>0,g=>-1,f=>-1,i=>-1}
97ffffff020000000500000005000000
97ffffff020000000500000005000000
97ffffff020000000500000005000000
97ffffff020000000500000005000000
-
{e=>0,a=>95,d=>1,c=>1,h=>-1,b=>1,g=>-1,f=>-1,i=>-1}
5f000000030000000500000007000000
5f000000030000000500000007000000
5f000000030000000500000007000000
5f000000030000000500000007000000
-
{e=>-1,a=>-81,d=>0,c=>0,h=>0,b=>1,g=>0,f=>0,i=>0}
afffffff010000000200000000000000
afffffff010000000200000000000000
afffffff010000000200000000000000
afffffff010000000200000000000000
-
{e=>-1,a=>54,d=>0,c=>0,h=>-1,b=>0,g=>-1,f=>0,i=>-1}
36000000000000000200000007000000
36000000000000000200000007000000
36000000000000000200000007000000
36000000000000000200000007000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
  int          j:1;
};
-
{e=>0,a=>-112,d=>0,j=>0,c=>1,h=>0,b=>1,g=>-1,f=>0,i=>-1}
90ffffff03000000000000000500000000000000
90ffffff03000000000000000500000000000000
90ffffff03000000000000000500000000000000
90ffffff03000000000000000500000000000000
-
{e=>0,a=>39,d=>0,j=>0,c=>1,h=>-1,b=>1,g=>-1,f=>-1,i=>0}
2700000003000000040000000300000000000000
2700000003000000040000000300000000000000
2700000003000000040000000300000000000000
2700000003000000040000000300000000000000
-
{e=>-1,a=>113,d=>1,j=>-1,c=>1,h=>-1,b=>0,g=>0,f=>-1,i=>0}
7100000002000000070000000200000001000000
7100000002000000070000000200000001000000
7100000002000000070000000200000001000000
7100000002000000070000000200000001000000
-
{e=>0,a=>118,d=>1,j=>0,c=>1,h=>0,b=>0,g=>0,f=>0,i=>-1}
7600000002000000010000000400000000000000
7600000002000000010000000400000000000000
7600000002000000010000000400000000000000
7600000002000000010000000400000000000000
-
{e=>-1,a=>80,d=>0,j=>-1,c=>1,h=>0,b=>0,g=>-1,f=>-1,i=>0}
5000000002000000060000000100000001000000
5000000002000000060000000100000001000000
5000000002000000060000000100000001000000
5000000002000000060000000100000001000000
=
struct mixed1 {
  long a;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int  :0;
  unsigned int d:1;
  signed   int e:1;
  signed   int f:1;
  signed   int  :0;
  signed   int g:1;
  int          h:1;
  int          i:1;
  int           :0;
  int          j:1;
  long         k;
};
-
{e=>-1,a=>2,d=>0,j=>0,c=>1,k=>-79,h=>0,b=>1,g=>0,f=>0,i=>0}
0200000003000000020000000000000000000000b1ffffff
0200000003000000020000000000000000000000b1ffffff
0200000003000000020000000000000000000000b1ffffff
0200000003000000020000000000000000000000b1ffffff
-
{e=>0,a=>-88,d=>1,j=>0,c=>1,k=>-90,h=>0,b=>0,g=>-1,f=>0,i=>0}
a8ffffff02000000010000000100000000000000a6ffffff
a8ffffff02000000010000000100000000000000a6ffffff
a8ffffff02000000010000000100000000000000a6ffffff
a8ffffff02000000010000000100000000000000a6ffffff
-
{e=>0,a=>-63,d=>0,j=>-1,c=>1,k=>22,h=>-1,b=>0,g=>0,f=>-1,i=>0}
c1ffffff0200000004000000020000000100000016000000
c1ffffff0200000004000000020000000100000016000000
c1ffffff0200000004000000020000000100000016000000
c1ffffff0200000004000000020000000100000016000000
-
{e=>0,a=>23,d=>1,j=>0,c=>1,k=>21,h=>0,b=>1,g=>-1,f=>-1,i=>0}
170000000300000005000000010000000000000015000000
170000000300000005000000010000000000000015000000
170000000300000005000000010000000000000015000000
170000000300000005000000010000000000000015000000
-
{e=>-1,a=>84,d=>1,j=>-1,c=>1,k=>47,h=>0,b=>1,g=>-1,f=>0,i=>-1}
54000000030000000300000005000000010000002f000000
54000000030000000300000005000000010000002f000000
54000000030000000300000005000000010000002f000000
54000000030000000300000005000000010000002f000000
=
struct mixed2 {
  unsigned int a:2;
};
-
{a=>1}
01000000
01000000
01000000
01000000
-
{a=>2}
02000000
02000000
02000000
02000000
-
{a=>2}
02000000
02000000
02000000
02000000
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>0}
00000000
00000000
00000000
00000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
};
-
{a=>0,b=>0}
00000000
00000000
00000000
00000000
-
{a=>0,b=>2}
08000000
08000000
08000000
08000000
-
{a=>3,b=>3}
0f000000
0f000000
0f000000
0f000000
-
{a=>2,b=>1}
06000000
06000000
06000000
06000000
-
{a=>0,b=>0}
00000000
00000000
00000000
00000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
  unsigned int  :0;
};
-
{a=>2,b=>1}
06000000
06000000
06000000
06000000
-
{a=>0,b=>3}
0c000000
0c000000
0c000000
0c000000
-
{a=>2,b=>2}
0a000000
0a000000
0a000000
0a000000
-
{a=>3,b=>0}
03000000
03000000
03000000
03000000
-
{a=>3,b=>1}
07000000
07000000
07000000
07000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
  unsigned int  :0;
  unsigned int c:2;
};
-
{c=>0,a=>3,b=>2}
0b00000000000000
0b00000000000000
0b00000000000000
0b00000000000000
-
{c=>2,a=>2,b=>3}
0e00000002000000
0e00000002000000
0e00000002000000
0e00000002000000
-
{c=>3,a=>2,b=>2}
0a00000003000000
0a00000003000000
0a00000003000000
0a00000003000000
-
{c=>1,a=>2,b=>3}
0e00000001000000
0e00000001000000
0e00000001000000
0e00000001000000
-
{c=>1,a=>0,b=>1}
0400000001000000
0400000001000000
0400000001000000
0400000001000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
  unsigned int  :0;
  unsigned int c:2;
  signed   int d:2;
};
-
{c=>0,a=>2,b=>2,d=>-1}
0a0000000c000000
0a0000000c000000
0a0000000c000000
0a0000000c000000
-
{c=>1,a=>0,b=>1,d=>0}
0400000001000000
0400000001000000
0400000001000000
0400000001000000
-
{c=>2,a=>2,b=>1,d=>0}
0600000002000000
0600000002000000
0600000002000000
0600000002000000
-
{c=>2,a=>0,b=>2,d=>0}
0800000002000000
0800000002000000
0800000002000000
0800000002000000
-
{c=>1,a=>1,b=>3,d=>0}
0d00000001000000
0d00000001000000
0d00000001000000
0d00000001000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
  unsigned int  :0;
  unsigned int c:2;
  signed   int d:2;
  signed   int e:2;
};
-
{e=>1,c=>0,a=>1,b=>2,d=>-2}
0900000018000000
0900000018000000
0900000018000000
0900000018000000
-
{e=>0,c=>1,a=>0,b=>2,d=>-1}
080000000d000000
080000000d000000
080000000d000000
080000000d000000
-
{e=>-2,c=>3,a=>3,b=>1,d=>1}
0700000027000000
0700000027000000
0700000027000000
0700000027000000
-
{e=>1,c=>3,a=>0,b=>1,d=>-1}
040000001f000000
040000001f000000
040000001f000000
040000001f000000
-
{e=>-2,c=>0,a=>0,b=>3,d=>-2}
0c00000028000000
0c00000028000000
0c00000028000000
0c00000028000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
  unsigned int  :0;
  unsigned int c:2;
  signed   int d:2;
  signed   int e:2;
  signed   int  :0;
};
-
{e=>-1,c=>3,a=>2,b=>1,d=>1}
0600000037000000
0600000037000000
0600000037000000
0600000037000000
-
{e=>-2,c=>0,a=>1,b=>2,d=>-2}
0900000028000000
0900000028000000
0900000028000000
0900000028000000
-
{e=>0,c=>3,a=>2,b=>2,d=>0}
0a00000003000000
0a00000003000000
0a00000003000000
0a00000003000000
-
{e=>1,c=>2,a=>1,b=>2,d=>-2}
090000001a000000
090000001a000000
090000001a000000
090000001a000000
-
{e=>1,c=>2,a=>2,b=>3,d=>0}
0e00000012000000
0e00000012000000
0e00000012000000
0e00000012000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
  unsigned int  :0;
  unsigned int c:2;
  signed   int d:2;
  signed   int e:2;
  signed   int  :0;
  signed   int f:2;
};
-
{e=>0,c=>1,a=>2,b=>3,d=>0,f=>-1}
0e0000000100000003000000
0e0000000100000003000000
0e0000000100000003000000
0e0000000100000003000000
-
{e=>0,c=>0,a=>0,b=>2,d=>-1,f=>1}
080000000c00000001000000
080000000c00000001000000
080000000c00000001000000
080000000c00000001000000
-
{e=>0,c=>2,a=>0,b=>0,d=>0,f=>-2}
000000000200000002000000
000000000200000002000000
000000000200000002000000
000000000200000002000000
-
{e=>-2,c=>3,a=>2,b=>1,d=>-2,f=>-2}
060000002b00000002000000
060000002b00000002000000
060000002b00000002000000
060000002b00000002000000
-
{e=>-2,c=>2,a=>0,b=>3,d=>-2,f=>-1}
0c0000002a00000003000000
0c0000002a00000003000000
0c0000002a00000003000000
0c0000002a00000003000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
  unsigned int  :0;
  unsigned int c:2;
  signed   int d:2;
  signed   int e:2;
  signed   int  :0;
  signed   int f:2;
  int          g:2;
};
-
{e=>0,c=>2,a=>1,g=>-1,b=>3,d=>1,f=>-1}
0d000000060000000f000000
0d000000060000000f000000
0d000000060000000f000000
0d000000060000000f000000
-
{e=>1,c=>2,a=>2,g=>1,b=>2,d=>1,f=>1}
0a0000001600000005000000
0a0000001600000005000000
0a0000001600000005000000
0a0000001600000005000000
-
{e=>0,c=>2,a=>2,g=>-1,b=>2,d=>-2,f=>-1}
0a0000000a0000000f000000
0a0000000a0000000f000000
0a0000000a0000000f000000
0a0000000a0000000f000000
-
{e=>-2,c=>0,a=>2,g=>-2,b=>1,d=>-1,f=>1}
060000002c00000009000000
060000002c00000009000000
060000002c00000009000000
060000002c00000009000000
-
{e=>-1,c=>3,a=>1,g=>-1,b=>0,d=>0,f=>0}
01000000330000000c000000
01000000330000000c000000
01000000330000000c000000
01000000330000000c000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
  unsigned int  :0;
  unsigned int c:2;
  signed   int d:2;
  signed   int e:2;
  signed   int  :0;
  signed   int f:2;
  int          g:2;
  int          h:2;
};
-
{e=>-2,a=>0,d=>1,c=>2,h=>-1,b=>1,g=>-2,f=>-2}
04000000260000003a000000
04000000260000003a000000
04000000260000003a000000
04000000260000003a000000
-
{e=>-2,a=>0,d=>1,c=>0,h=>0,b=>0,g=>1,f=>0}
000000002400000004000000
000000002400000004000000
000000002400000004000000
000000002400000004000000
-
{e=>1,a=>1,d=>1,c=>1,h=>0,b=>0,g=>-1,f=>-2}
01000000150000000e000000
01000000150000000e000000
01000000150000000e000000
01000000150000000e000000
-
{e=>0,a=>3,d=>0,c=>0,h=>1,b=>2,g=>0,f=>1}
0b0000000000000011000000
0b0000000000000011000000
0b0000000000000011000000
0b0000000000000011000000
-
{e=>-1,a=>1,d=>0,c=>1,h=>0,b=>0,g=>0,f=>0}
010000003100000000000000
010000003100000000000000
010000003100000000000000
010000003100000000000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
  unsigned int  :0;
  unsigned int c:2;
  signed   int d:2;
  signed   int e:2;
  signed   int  :0;
  signed   int f:2;
  int          g:2;
  int          h:2;
  int           :0;
};
-
{e=>-2,a=>0,d=>0,c=>0,h=>-1,b=>1,g=>0,f=>-2}
040000002000000032000000
040000002000000032000000
040000002000000032000000
040000002000000032000000
-
{e=>0,a=>3,d=>-2,c=>2,h=>-1,b=>3,g=>-1,f=>-2}
0f0000000a0000003e000000
0f0000000a0000003e000000
0f0000000a0000003e000000
0f0000000a0000003e000000
-
{e=>-1,a=>0,d=>0,c=>1,h=>-1,b=>0,g=>-1,f=>0}
00000000310000003c000000
00000000310000003c000000
00000000310000003c000000
00000000310000003c000000
-
{e=>0,a=>3,d=>-2,c=>0,h=>1,b=>2,g=>-2,f=>1}
0b0000000800000019000000
0b0000000800000019000000
0b0000000800000019000000
0b0000000800000019000000
-
{e=>-1,a=>2,d=>0,c=>1,h=>1,b=>0,g=>0,f=>1}
020000003100000011000000
020000003100000011000000
020000003100000011000000
020000003100000011000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
  unsigned int  :0;
  unsigned int c:2;
  signed   int d:2;
  signed   int e:2;
  signed   int  :0;
  signed   int f:2;
  int          g:2;
  int          h:2;
  int           :0;
  int          i:2;
};
-
{e=>0,a=>0,d=>0,c=>2,h=>-1,b=>2,g=>1,f=>0,i=>1}
08000000020000003400000001000000
08000000020000003400000001000000
08000000020000003400000001000000
08000000020000003400000001000000
-
{e=>0,a=>0,d=>-2,c=>0,h=>-1,b=>0,g=>-2,f=>1,i=>1}
00000000080000003900000001000000
00000000080000003900000001000000
00000000080000003900000001000000
00000000080000003900000001000000
-
{e=>-1,a=>2,d=>0,c=>0,h=>0,b=>1,g=>-2,f=>0,i=>-1}
06000000300000000800000003000000
06000000300000000800000003000000
06000000300000000800000003000000
06000000300000000800000003000000
-
{e=>1,a=>0,d=>0,c=>2,h=>0,b=>2,g=>1,f=>0,i=>1}
08000000120000000400000001000000
08000000120000000400000001000000
08000000120000000400000001000000
08000000120000000400000001000000
-
{e=>0,a=>3,d=>-1,c=>0,h=>-1,b=>2,g=>-2,f=>0,i=>-2}
0b0000000c0000003800000002000000
0b0000000c0000003800000002000000
0b0000000c0000003800000002000000
0b0000000c0000003800000002000000
=
struct mixed2 {
  unsigned int a:2;
  unsigned int b:2;
  unsigned int  :0;
  unsigned int c:2;
  signed   int d:2;
  signed   int e:2;
  signed   int  :0;
  signed   int f:2;
  int          g:2;
  int          h:2;
  int           :0;
  int          i:2;
  int          j;
};
-
{e=>-2,a=>1,d=>0,j=>11,c=>0,h=>-2,b=>1,g=>1,f=>-1,i=>-1}
050000002000000027000000030000000b000000
050000002000000027000000030000000b000000
050000002000000027000000030000000b000000
050000002000000027000000030000000b000000
-
{e=>1,a=>2,d=>-2,j=>76,c=>3,h=>-1,b=>1,g=>0,f=>-1,i=>1}
060000001b00000033000000010000004c000000
060000001b00000033000000010000004c000000
060000001b00000033000000010000004c000000
060000001b00000033000000010000004c000000
-
{e=>1,a=>3,d=>0,j=>-66,c=>0,h=>-2,b=>3,g=>-2,f=>-1,i=>-2}
0f000000100000002b00000002000000beffffff
0f000000100000002b00000002000000beffffff
0f000000100000002b00000002000000beffffff
0f000000100000002b00000002000000beffffff
-
{e=>-1,a=>0,d=>0,j=>-99,c=>1,h=>0,b=>1,g=>-2,f=>0,i=>1}
040000003100000008000000010000009dffffff
040000003100000008000000010000009dffffff
040000003100000008000000010000009dffffff
040000003100000008000000010000009dffffff
-
{e=>-1,a=>2,d=>1,j=>94,c=>3,h=>-2,b=>3,g=>1,f=>-2,i=>-2}
0e0000003700000026000000020000005e000000
0e0000003700000026000000020000005e000000
0e0000003700000026000000020000005e000000
0e0000003700000026000000020000005e000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
};
-
{a=>-56,b=>3}
c803000000
c80003000000
c800000003000000
c800000003000000
-
{a=>127,b=>0}
7f00000000
7f0000000000
7f00000000000000
7f00000000000000
-
{a=>43,b=>2}
2b02000000
2b0002000000
2b00000002000000
2b00000002000000
-
{a=>-28,b=>1}
e401000000
e40001000000
e400000001000000
e400000001000000
-
{a=>38,b=>0}
2600000000
260000000000
2600000000000000
2600000000000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
};
-
{c=>0,a=>35,b=>1}
2301000000
230001000000
2300000001000000
2300000001000000
-
{c=>0,a=>53,b=>3}
3503000000
350003000000
3500000003000000
3500000003000000
-
{c=>3,a=>120,b=>0}
780c000000
78000c000000
780000000c000000
780000000c000000
-
{c=>3,a=>-123,b=>1}
850d000000
85000d000000
850000000d000000
850000000d000000
-
{c=>1,a=>29,b=>3}
1d07000000
1d0007000000
1d00000007000000
1d00000007000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
};
-
{c=>2,a=>79,b=>2}
4f0a000000
4f000a000000
4f0000000a000000
4f0000000a000000
-
{c=>1,a=>-102,b=>2}
9a06000000
9a0006000000
9a00000006000000
9a00000006000000
-
{c=>0,a=>-112,b=>1}
9001000000
900001000000
9000000001000000
9000000001000000
-
{c=>0,a=>86,b=>0}
5600000000
560000000000
5600000000000000
5600000000000000
-
{c=>2,a=>-112,b=>2}
900a000000
90000a000000
900000000a000000
900000000a000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
};
-
{c=>1,a=>9,b=>1,d=>2}
090500000002000000
09000500000002000000
090000000500000002000000
090000000500000002000000
-
{c=>2,a=>-42,b=>0,d=>3}
d60800000003000000
d6000800000003000000
d60000000800000003000000
d60000000800000003000000
-
{c=>2,a=>65,b=>2,d=>2}
410a00000002000000
41000a00000002000000
410000000a00000002000000
410000000a00000002000000
-
{c=>1,a=>-14,b=>2,d=>0}
f20600000000000000
f2000600000000000000
f20000000600000000000000
f20000000600000000000000
-
{c=>3,a=>-69,b=>1,d=>1}
bb0d00000001000000
bb000d00000001000000
bb0000000d00000001000000
bb0000000d00000001000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
};
-
{e=>0,c=>1,a=>-38,b=>2,d=>1}
da0600000001000000
da000600000001000000
da0000000600000001000000
da0000000600000001000000
-
{e=>0,c=>0,a=>66,b=>2,d=>1}
420200000001000000
42000200000001000000
420000000200000001000000
420000000200000001000000
-
{e=>1,c=>2,a=>-56,b=>1,d=>2}
c80900000006000000
c8000900000006000000
c80000000900000006000000
c80000000900000006000000
-
{e=>-1,c=>1,a=>120,b=>1,d=>2}
78050000000e000000
7800050000000e000000
78000000050000000e000000
78000000050000000e000000
-
{e=>0,c=>2,a=>62,b=>0,d=>3}
3e0800000003000000
3e000800000003000000
3e0000000800000003000000
3e0000000800000003000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
};
-
{e=>1,c=>3,a=>-41,b=>1,d=>2,f=>0}
d70d00000006000000
d7000d00000006000000
d70000000d00000006000000
d70000000d00000006000000
-
{e=>-2,c=>2,a=>100,b=>2,d=>1,f=>1}
640a00000019000000
64000a00000019000000
640000000a00000019000000
640000000a00000019000000
-
{e=>1,c=>0,a=>86,b=>0,d=>3,f=>1}
560000000017000000
56000000000017000000
560000000000000017000000
560000000000000017000000
-
{e=>1,c=>3,a=>-89,b=>3,d=>2,f=>-2}
a70f00000026000000
a7000f00000026000000
a70000000f00000026000000
a70000000f00000026000000
-
{e=>-1,c=>3,a=>-109,b=>3,d=>0,f=>1}
930f0000001c000000
93000f0000001c000000
930000000f0000001c000000
930000000f0000001c000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
};
-
{e=>-2,c=>0,a=>-11,b=>1,d=>3,f=>1}
f5010000001b000000
f500010000001b000000
f5000000010000001b000000
f5000000010000001b000000
-
{e=>-2,c=>0,a=>11,b=>0,d=>0,f=>1}
0b0000000018000000
0b000000000018000000
0b0000000000000018000000
0b0000000000000018000000
-
{e=>0,c=>3,a=>100,b=>1,d=>3,f=>0}
640d00000003000000
64000d00000003000000
640000000d00000003000000
640000000d00000003000000
-
{e=>0,c=>3,a=>-21,b=>2,d=>0,f=>-2}
eb0e00000020000000
eb000e00000020000000
eb0000000e00000020000000
eb0000000e00000020000000
-
{e=>1,c=>0,a=>-82,b=>1,d=>1,f=>-1}
ae0100000035000000
ae000100000035000000
ae0000000100000035000000
ae0000000100000035000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
};
-
{e=>1,c=>1,a=>-87,g=>-2,b=>0,d=>0,f=>0}
a9040000000400000002000000
a900040000000400000002000000
a9000000040000000400000002000000
a9000000040000000400000002000000
-
{e=>-2,c=>1,a=>1,g=>-2,b=>0,d=>0,f=>-2}
01040000002800000002000000
0100040000002800000002000000
01000000040000002800000002000000
01000000040000002800000002000000
-
{e=>-1,c=>2,a=>107,g=>-2,b=>3,d=>3,f=>-1}
6b0b0000003f00000002000000
6b000b0000003f00000002000000
6b0000000b0000003f00000002000000
6b0000000b0000003f00000002000000
-
{e=>-1,c=>1,a=>-44,g=>0,b=>0,d=>0,f=>-1}
d4040000003c00000000000000
d400040000003c00000000000000
d4000000040000003c00000000000000
d4000000040000003c00000000000000
-
{e=>-1,c=>2,a=>-40,g=>-1,b=>0,d=>3,f=>0}
d8080000000f00000003000000
d800080000000f00000003000000
d8000000080000000f00000003000000
d8000000080000000f00000003000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
};
-
{e=>-2,a=>30,d=>2,c=>0,h=>-1,b=>1,g=>-2,f=>-1}
1e010000003a0000000e000000
1e00010000003a0000000e000000
1e000000010000003a0000000e000000
1e000000010000003a0000000e000000
-
{e=>1,a=>52,d=>3,c=>0,h=>-2,b=>2,g=>0,f=>0}
34020000000700000008000000
3400020000000700000008000000
34000000020000000700000008000000
34000000020000000700000008000000
-
{e=>1,a=>-125,d=>2,c=>2,h=>1,b=>0,g=>1,f=>-1}
83080000003600000005000000
8300080000003600000005000000
83000000080000003600000005000000
83000000080000003600000005000000
-
{e=>-1,a=>70,d=>0,c=>3,h=>-1,b=>3,g=>1,f=>-1}
460f0000003c0000000d000000
46000f0000003c0000000d000000
460000000f0000003c0000000d000000
460000000f0000003c0000000d000000
-
{e=>0,a=>-57,d=>2,c=>3,h=>1,b=>0,g=>-1,f=>-1}
c70c0000003200000007000000
c7000c0000003200000007000000
c70000000c0000003200000007000000
c70000000c0000003200000007000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
};
-
{e=>-2,a=>122,d=>0,c=>1,h=>0,b=>1,g=>0,f=>0,i=>-2}
7a050000000800000020000000
7a00050000000800000020000000
7a000000050000000800000020000000
7a000000050000000800000020000000
-
{e=>-2,a=>76,d=>3,c=>3,h=>-1,b=>2,g=>0,f=>-1,i=>-1}
4c0e0000003b0000003c000000
4c000e0000003b0000003c000000
4c0000000e0000003b0000003c000000
4c0000000e0000003b0000003c000000
-
{e=>1,a=>56,d=>3,c=>2,h=>-1,b=>3,g=>-1,f=>1,i=>0}
380b000000170000000f000000
38000b000000170000000f000000
380000000b000000170000000f000000
380000000b000000170000000f000000
-
{e=>-2,a=>79,d=>0,c=>1,h=>1,b=>2,g=>-2,f=>0,i=>1}
4f060000000800000016000000
4f00060000000800000016000000
4f000000060000000800000016000000
4f000000060000000800000016000000
-
{e=>1,a=>-87,d=>2,c=>1,h=>-1,b=>1,g=>0,f=>0,i=>0}
a905000000060000000c000000
a90005000000060000000c000000
a900000005000000060000000c000000
a900000005000000060000000c000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
};
-
{e=>-1,a=>-90,d=>0,c=>2,h=>1,b=>2,g=>0,f=>-2,i=>-2}
a60a0000002c00000024000000
a6000a0000002c00000024000000
a60000000a0000002c00000024000000
a60000000a0000002c00000024000000
-
{e=>-2,a=>-119,d=>1,c=>0,h=>0,b=>2,g=>-2,f=>-1,i=>1}
89020000003900000012000000
8900020000003900000012000000
89000000020000003900000012000000
89000000020000003900000012000000
-
{e=>1,a=>108,d=>3,c=>3,h=>0,b=>3,g=>-1,f=>-1,i=>1}
6c0f0000003700000013000000
6c000f0000003700000013000000
6c0000000f0000003700000013000000
6c0000000f0000003700000013000000
-
{e=>0,a=>-126,d=>0,c=>3,h=>1,b=>2,g=>-2,f=>0,i=>-1}
820e0000000000000036000000
82000e0000000000000036000000
820000000e0000000000000036000000
820000000e0000000000000036000000
-
{e=>1,a=>-120,d=>2,c=>2,h=>0,b=>1,g=>-2,f=>0,i=>-1}
88090000000600000032000000
8800090000000600000032000000
88000000090000000600000032000000
88000000090000000600000032000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
  int          j:2;
};
-
{e=>1,a=>-105,d=>3,j=>1,c=>3,h=>0,b=>1,g=>-2,f=>-2,i=>0}
970d000000270000000200000001000000
97000d000000270000000200000001000000
970000000d000000270000000200000001000000
970000000d000000270000000200000001000000
-
{e=>0,a=>32,d=>0,j=>0,c=>2,h=>1,b=>2,g=>1,f=>-1,i=>-1}
200a000000300000003500000000000000
20000a000000300000003500000000000000
200000000a000000300000003500000000000000
200000000a000000300000003500000000000000
-
{e=>1,a=>57,d=>1,j=>-2,c=>2,h=>-1,b=>1,g=>-2,f=>-2,i=>1}
3909000000250000001e00000002000000
390009000000250000001e00000002000000
3900000009000000250000001e00000002000000
3900000009000000250000001e00000002000000
-
{e=>0,a=>59,d=>3,j=>-1,c=>0,h=>-2,b=>1,g=>0,f=>1,i=>-2}
3b01000000130000002800000003000000
3b0001000000130000002800000003000000
3b00000001000000130000002800000003000000
3b00000001000000130000002800000003000000
-
{e=>-2,a=>68,d=>0,j=>1,c=>0,h=>1,b=>3,g=>0,f=>-2,i=>0}
4403000000280000000400000001000000
440003000000280000000400000001000000
4400000003000000280000000400000001000000
4400000003000000280000000400000001000000
=
struct mixed2 {
  char a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
  int          j:2;
  int          k;
};
-
{e=>1,a=>-55,d=>1,j=>-2,c=>3,k=>111,h=>-1,b=>1,g=>-1,f=>0,i=>-1}
c90d000000050000003f000000020000006f000000
c9000d000000050000003f000000020000006f000000
c90000000d000000050000003f000000020000006f000000
c90000000d000000050000003f000000020000006f000000
-
{e=>-2,a=>-69,d=>3,j=>0,c=>0,k=>-83,h=>0,b=>3,g=>0,f=>-1,i=>1}
bb030000003b0000001000000000000000adffffff
bb00030000003b0000001000000000000000adffffff
bb000000030000003b0000001000000000000000adffffff
bb000000030000003b0000001000000000000000adffffff
-
{e=>0,a=>110,d=>0,j=>0,c=>3,k=>116,h=>-1,b=>3,g=>-2,f=>1,i=>-1}
6e0f000000100000003e0000000000000074000000
6e000f000000100000003e0000000000000074000000
6e0000000f000000100000003e0000000000000074000000
6e0000000f000000100000003e0000000000000074000000
-
{e=>0,a=>-42,d=>1,j=>-1,c=>0,k=>92,h=>-1,b=>2,g=>1,f=>-2,i=>-2}
d602000000210000002d000000030000005c000000
d60002000000210000002d000000030000005c000000
d600000002000000210000002d000000030000005c000000
d600000002000000210000002d000000030000005c000000
-
{e=>-1,a=>-34,d=>0,j=>-2,c=>3,k=>22,h=>-2,b=>2,g=>-1,f=>0,i=>0}
de0e0000000c0000000b0000000200000016000000
de000e0000000c0000000b0000000200000016000000
de0000000e0000000c0000000b0000000200000016000000
de0000000e0000000c0000000b0000000200000016000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
};
-
{a=>-36,b=>3}
dcff03000000
dcff03000000
dcff000003000000
dcff000003000000
-
{a=>77,b=>0}
4d0000000000
4d0000000000
4d00000000000000
4d00000000000000
-
{a=>-125,b=>0}
83ff00000000
83ff00000000
83ff000000000000
83ff000000000000
-
{a=>33,b=>0}
210000000000
210000000000
2100000000000000
2100000000000000
-
{a=>18,b=>3}
120003000000
120003000000
1200000003000000
1200000003000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
};
-
{c=>2,a=>39,b=>2}
27000a000000
27000a000000
270000000a000000
270000000a000000
-
{c=>2,a=>-73,b=>3}
b7ff0b000000
b7ff0b000000
b7ff00000b000000
b7ff00000b000000
-
{c=>2,a=>12,b=>1}
0c0009000000
0c0009000000
0c00000009000000
0c00000009000000
-
{c=>1,a=>107,b=>2}
6b0006000000
6b0006000000
6b00000006000000
6b00000006000000
-
{c=>0,a=>-10,b=>2}
f6ff02000000
f6ff02000000
f6ff000002000000
f6ff000002000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
};
-
{c=>0,a=>-15,b=>0}
f1ff00000000
f1ff00000000
f1ff000000000000
f1ff000000000000
-
{c=>2,a=>-103,b=>1}
99ff09000000
99ff09000000
99ff000009000000
99ff000009000000
-
{c=>0,a=>106,b=>3}
6a0003000000
6a0003000000
6a00000003000000
6a00000003000000
-
{c=>0,a=>77,b=>3}
4d0003000000
4d0003000000
4d00000003000000
4d00000003000000
-
{c=>0,a=>-60,b=>2}
c4ff02000000
c4ff02000000
c4ff000002000000
c4ff000002000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
};
-
{c=>3,a=>-90,b=>2,d=>1}
a6ff0e00000001000000
a6ff0e00000001000000
a6ff00000e00000001000000
a6ff00000e00000001000000
-
{c=>1,a=>-112,b=>3,d=>1}
90ff0700000001000000
90ff0700000001000000
90ff00000700000001000000
90ff00000700000001000000
-
{c=>3,a=>-67,b=>0,d=>1}
bdff0c00000001000000
bdff0c00000001000000
bdff00000c00000001000000
bdff00000c00000001000000
-
{c=>1,a=>-2,b=>0,d=>3}
feff0400000003000000
feff0400000003000000
feff00000400000003000000
feff00000400000003000000
-
{c=>0,a=>-45,b=>1,d=>1}
d3ff0100000001000000
d3ff0100000001000000
d3ff00000100000001000000
d3ff00000100000001000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
};
-
{e=>-1,c=>2,a=>-104,b=>2,d=>0}
98ff0a0000000c000000
98ff0a0000000c000000
98ff00000a0000000c000000
98ff00000a0000000c000000
-
{e=>-2,c=>1,a=>-128,b=>3,d=>2}
80ff070000000a000000
80ff070000000a000000
80ff0000070000000a000000
80ff0000070000000a000000
-
{e=>1,c=>3,a=>-119,b=>2,d=>1}
89ff0e00000005000000
89ff0e00000005000000
89ff00000e00000005000000
89ff00000e00000005000000
-
{e=>-1,c=>3,a=>31,b=>1,d=>0}
1f000d0000000c000000
1f000d0000000c000000
1f0000000d0000000c000000
1f0000000d0000000c000000
-
{e=>-1,c=>0,a=>-28,b=>1,d=>0}
e4ff010000000c000000
e4ff010000000c000000
e4ff0000010000000c000000
e4ff0000010000000c000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
};
-
{e=>-1,c=>0,a=>15,b=>3,d=>0,f=>-2}
0f00030000002c000000
0f00030000002c000000
0f000000030000002c000000
0f000000030000002c000000
-
{e=>-1,c=>2,a=>-51,b=>3,d=>1,f=>0}
cdff0b0000000d000000
cdff0b0000000d000000
cdff00000b0000000d000000
cdff00000b0000000d000000
-
{e=>-1,c=>2,a=>-69,b=>1,d=>3,f=>1}
bbff090000001f000000
bbff090000001f000000
bbff0000090000001f000000
bbff0000090000001f000000
-
{e=>1,c=>3,a=>121,b=>2,d=>1,f=>0}
79000e00000005000000
79000e00000005000000
790000000e00000005000000
790000000e00000005000000
-
{e=>0,c=>2,a=>17,b=>3,d=>3,f=>-1}
11000b00000033000000
11000b00000033000000
110000000b00000033000000
110000000b00000033000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
};
-
{e=>0,c=>1,a=>-102,b=>2,d=>2,f=>-1}
9aff0600000032000000
9aff0600000032000000
9aff00000600000032000000
9aff00000600000032000000
-
{e=>-2,c=>2,a=>-45,b=>2,d=>2,f=>-2}
d3ff0a0000002a000000
d3ff0a0000002a000000
d3ff00000a0000002a000000
d3ff00000a0000002a000000
-
{e=>-2,c=>3,a=>1,b=>0,d=>1,f=>-1}
01000c00000039000000
01000c00000039000000
010000000c00000039000000
010000000c00000039000000
-
{e=>1,c=>1,a=>-70,b=>0,d=>1,f=>0}
baff0400000005000000
baff0400000005000000
baff00000400000005000000
baff00000400000005000000
-
{e=>0,c=>3,a=>-67,b=>3,d=>2,f=>-2}
bdff0f00000022000000
bdff0f00000022000000
bdff00000f00000022000000
bdff00000f00000022000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
};
-
{e=>-1,c=>1,a=>-14,g=>-2,b=>2,d=>3,f=>0}
f2ff060000000f00000002000000
f2ff060000000f00000002000000
f2ff0000060000000f00000002000000
f2ff0000060000000f00000002000000
-
{e=>0,c=>2,a=>-82,g=>-2,b=>2,d=>0,f=>0}
aeff0a0000000000000002000000
aeff0a0000000000000002000000
aeff00000a0000000000000002000000
aeff00000a0000000000000002000000
-
{e=>1,c=>1,a=>-117,g=>-1,b=>0,d=>3,f=>0}
8bff040000000700000003000000
8bff040000000700000003000000
8bff0000040000000700000003000000
8bff0000040000000700000003000000
-
{e=>1,c=>3,a=>-88,g=>1,b=>3,d=>0,f=>0}
a8ff0f0000000400000001000000
a8ff0f0000000400000001000000
a8ff00000f0000000400000001000000
a8ff00000f0000000400000001000000
-
{e=>0,c=>3,a=>38,g=>0,b=>3,d=>1,f=>-1}
26000f0000003100000000000000
26000f0000003100000000000000
260000000f0000003100000000000000
260000000f0000003100000000000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
};
-
{e=>0,a=>14,d=>3,c=>1,h=>-2,b=>2,g=>-2,f=>-2}
0e0006000000230000000a000000
0e0006000000230000000a000000
0e00000006000000230000000a000000
0e00000006000000230000000a000000
-
{e=>1,a=>73,d=>0,c=>0,h=>-1,b=>3,g=>0,f=>0}
490003000000040000000c000000
490003000000040000000c000000
4900000003000000040000000c000000
4900000003000000040000000c000000
-
{e=>-2,a=>5,d=>2,c=>1,h=>-1,b=>2,g=>1,f=>-2}
0500060000002a0000000d000000
0500060000002a0000000d000000
05000000060000002a0000000d000000
05000000060000002a0000000d000000
-
{e=>0,a=>-57,d=>2,c=>0,h=>-1,b=>0,g=>0,f=>1}
c7ff00000000120000000c000000
c7ff00000000120000000c000000
c7ff000000000000120000000c000000
c7ff000000000000120000000c000000
-
{e=>-1,a=>-21,d=>0,c=>3,h=>-1,b=>0,g=>-1,f=>1}
ebff0c0000001c0000000f000000
ebff0c0000001c0000000f000000
ebff00000c0000001c0000000f000000
ebff00000c0000001c0000000f000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
};
-
{e=>-2,a=>64,d=>3,c=>1,h=>1,b=>0,g=>1,f=>0,i=>-2}
4000040000000b00000025000000
4000040000000b00000025000000
40000000040000000b00000025000000
40000000040000000b00000025000000
-
{e=>-1,a=>-28,d=>2,c=>0,h=>-2,b=>3,g=>-1,f=>-1,i=>-1}
e4ff030000003e0000003b000000
e4ff030000003e0000003b000000
e4ff0000030000003e0000003b000000
e4ff0000030000003e0000003b000000
-
{e=>-1,a=>16,d=>0,c=>1,h=>0,b=>2,g=>-1,f=>1,i=>-1}
1000060000001c00000033000000
1000060000001c00000033000000
10000000060000001c00000033000000
10000000060000001c00000033000000
-
{e=>1,a=>-116,d=>0,c=>2,h=>-1,b=>3,g=>0,f=>-2,i=>0}
8cff0b000000240000000c000000
8cff0b000000240000000c000000
8cff00000b000000240000000c000000
8cff00000b000000240000000c000000
-
{e=>0,a=>-24,d=>0,c=>0,h=>-1,b=>1,g=>1,f=>-2,i=>0}
e8ff01000000200000000d000000
e8ff01000000200000000d000000
e8ff000001000000200000000d000000
e8ff000001000000200000000d000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
};
-
{e=>0,a=>-98,d=>3,c=>1,h=>-2,b=>3,g=>-2,f=>1,i=>-1}
9eff07000000130000003a000000
9eff07000000130000003a000000
9eff000007000000130000003a000000
9eff000007000000130000003a000000
-
{e=>1,a=>87,d=>3,c=>2,h=>-1,b=>2,g=>-1,f=>-2,i=>-1}
57000a000000270000003f000000
57000a000000270000003f000000
570000000a000000270000003f000000
570000000a000000270000003f000000
-
{e=>1,a=>-69,d=>2,c=>1,h=>0,b=>3,g=>0,f=>-2,i=>-1}
bbff070000002600000030000000
bbff070000002600000030000000
bbff0000070000002600000030000000
bbff0000070000002600000030000000
-
{e=>-1,a=>-28,d=>3,c=>0,h=>-1,b=>1,g=>-1,f=>0,i=>-2}
e4ff010000000f0000002f000000
e4ff010000000f0000002f000000
e4ff0000010000000f0000002f000000
e4ff0000010000000f0000002f000000
-
{e=>0,a=>58,d=>3,c=>3,h=>0,b=>3,g=>-2,f=>-1,i=>0}
3a000f0000003300000002000000
3a000f0000003300000002000000
3a0000000f0000003300000002000000
3a0000000f0000003300000002000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
  int          j:2;
};
-
{e=>0,a=>-102,d=>3,j=>-2,c=>1,h=>0,b=>2,g=>0,f=>0,i=>-1}
9aff06000000030000003000000002000000
9aff06000000030000003000000002000000
9aff000006000000030000003000000002000000
9aff000006000000030000003000000002000000
-
{e=>-1,a=>-12,d=>1,j=>1,c=>1,h=>-2,b=>0,g=>-2,f=>1,i=>-2}
f4ff040000001d0000002a00000001000000
f4ff040000001d0000002a00000001000000
f4ff0000040000001d0000002a00000001000000
f4ff0000040000001d0000002a00000001000000
-
{e=>-2,a=>98,d=>3,j=>1,c=>0,h=>0,b=>0,g=>-1,f=>-2,i=>-2}
6200000000002b0000002300000001000000
6200000000002b0000002300000001000000
62000000000000002b0000002300000001000000
62000000000000002b0000002300000001000000
-
{e=>-1,a=>-38,d=>3,j=>-1,c=>1,h=>-1,b=>1,g=>-2,f=>0,i=>1}
daff050000000f0000001e00000003000000
daff050000000f0000001e00000003000000
daff0000050000000f0000001e00000003000000
daff0000050000000f0000001e00000003000000
-
{e=>1,a=>0,d=>2,j=>-2,c=>1,h=>0,b=>2,g=>1,f=>-2,i=>0}
000006000000260000000100000002000000
000006000000260000000100000002000000
0000000006000000260000000100000002000000
0000000006000000260000000100000002000000
=
struct mixed2 {
  short a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
  int          j:2;
  int          k;
};
-
{e=>-1,a=>-67,d=>0,j=>-2,c=>2,k=>-19,h=>1,b=>0,g=>0,f=>-1,i=>1}
bdff080000003c0000001400000002000000edffffff
bdff080000003c0000001400000002000000edffffff
bdff0000080000003c0000001400000002000000edffffff
bdff0000080000003c0000001400000002000000edffffff
-
{e=>0,a=>-109,d=>2,j=>0,c=>1,k=>116,h=>0,b=>0,g=>1,f=>1,i=>-1}
93ff0400000012000000310000000000000074000000
93ff0400000012000000310000000000000074000000
93ff00000400000012000000310000000000000074000000
93ff00000400000012000000310000000000000074000000
-
{e=>0,a=>102,d=>0,j=>1,c=>3,k=>116,h=>1,b=>2,g=>0,f=>1,i=>1}
66000e00000010000000140000000100000074000000
66000e00000010000000140000000100000074000000
660000000e00000010000000140000000100000074000000
660000000e00000010000000140000000100000074000000
-
{e=>0,a=>27,d=>1,j=>-1,c=>0,k=>-116,h=>-2,b=>2,g=>1,f=>-1,i=>-1}
1b00020000003100000039000000030000008cffffff
1b00020000003100000039000000030000008cffffff
1b000000020000003100000039000000030000008cffffff
1b000000020000003100000039000000030000008cffffff
-
{e=>1,a=>-68,d=>0,j=>-1,c=>3,k=>-47,h=>-1,b=>1,g=>0,f=>0,i=>-2}
bcff0d000000040000002c00000003000000d1ffffff
bcff0d000000040000002c00000003000000d1ffffff
bcff00000d000000040000002c00000003000000d1ffffff
bcff00000d000000040000002c00000003000000d1ffffff
=
struct mixed2 {
  int a;
  unsigned int b:2;
};
-
{a=>-99,b=>3}
9dffffff03000000
9dffffff03000000
9dffffff03000000
9dffffff03000000
-
{a=>-83,b=>3}
adffffff03000000
adffffff03000000
adffffff03000000
adffffff03000000
-
{a=>15,b=>2}
0f00000002000000
0f00000002000000
0f00000002000000
0f00000002000000
-
{a=>60,b=>1}
3c00000001000000
3c00000001000000
3c00000001000000
3c00000001000000
-
{a=>15,b=>2}
0f00000002000000
0f00000002000000
0f00000002000000
0f00000002000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
};
-
{c=>2,a=>64,b=>2}
400000000a000000
400000000a000000
400000000a000000
400000000a000000
-
{c=>3,a=>21,b=>3}
150000000f000000
150000000f000000
150000000f000000
150000000f000000
-
{c=>1,a=>88,b=>1}
5800000005000000
5800000005000000
5800000005000000
5800000005000000
-
{c=>2,a=>-84,b=>2}
acffffff0a000000
acffffff0a000000
acffffff0a000000
acffffff0a000000
-
{c=>3,a=>127,b=>2}
7f0000000e000000
7f0000000e000000
7f0000000e000000
7f0000000e000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
};
-
{c=>0,a=>-11,b=>2}
f5ffffff02000000
f5ffffff02000000
f5ffffff02000000
f5ffffff02000000
-
{c=>1,a=>-114,b=>1}
8effffff05000000
8effffff05000000
8effffff05000000
8effffff05000000
-
{c=>3,a=>-66,b=>1}
beffffff0d000000
beffffff0d000000
beffffff0d000000
beffffff0d000000
-
{c=>2,a=>-101,b=>1}
9bffffff09000000
9bffffff09000000
9bffffff09000000
9bffffff09000000
-
{c=>2,a=>51,b=>3}
330000000b000000
330000000b000000
330000000b000000
330000000b000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
};
-
{c=>3,a=>71,b=>3,d=>2}
470000000f00000002000000
470000000f00000002000000
470000000f00000002000000
470000000f00000002000000
-
{c=>0,a=>-59,b=>3,d=>2}
c5ffffff0300000002000000
c5ffffff0300000002000000
c5ffffff0300000002000000
c5ffffff0300000002000000
-
{c=>1,a=>-34,b=>1,d=>2}
deffffff0500000002000000
deffffff0500000002000000
deffffff0500000002000000
deffffff0500000002000000
-
{c=>1,a=>-50,b=>0,d=>2}
ceffffff0400000002000000
ceffffff0400000002000000
ceffffff0400000002000000
ceffffff0400000002000000
-
{c=>2,a=>98,b=>3,d=>1}
620000000b00000001000000
620000000b00000001000000
620000000b00000001000000
620000000b00000001000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
};
-
{e=>0,c=>2,a=>-115,b=>0,d=>3}
8dffffff0800000003000000
8dffffff0800000003000000
8dffffff0800000003000000
8dffffff0800000003000000
-
{e=>0,c=>2,a=>120,b=>0,d=>1}
780000000800000001000000
780000000800000001000000
780000000800000001000000
780000000800000001000000
-
{e=>-1,c=>3,a=>-67,b=>0,d=>1}
bdffffff0c0000000d000000
bdffffff0c0000000d000000
bdffffff0c0000000d000000
bdffffff0c0000000d000000
-
{e=>-2,c=>2,a=>52,b=>2,d=>0}
340000000a00000008000000
340000000a00000008000000
340000000a00000008000000
340000000a00000008000000
-
{e=>-1,c=>2,a=>94,b=>3,d=>2}
5e0000000b0000000e000000
5e0000000b0000000e000000
5e0000000b0000000e000000
5e0000000b0000000e000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
};
-
{e=>0,c=>3,a=>-74,b=>1,d=>1,f=>1}
b6ffffff0d00000011000000
b6ffffff0d00000011000000
b6ffffff0d00000011000000
b6ffffff0d00000011000000
-
{e=>-1,c=>3,a=>117,b=>2,d=>1,f=>1}
750000000e0000001d000000
750000000e0000001d000000
750000000e0000001d000000
750000000e0000001d000000
-
{e=>1,c=>1,a=>-117,b=>0,d=>2,f=>-2}
8bffffff0400000026000000
8bffffff0400000026000000
8bffffff0400000026000000
8bffffff0400000026000000
-
{e=>-2,c=>1,a=>-90,b=>1,d=>0,f=>-2}
a6ffffff0500000028000000
a6ffffff0500000028000000
a6ffffff0500000028000000
a6ffffff0500000028000000
-
{e=>-1,c=>2,a=>41,b=>0,d=>3,f=>0}
29000000080000000f000000
29000000080000000f000000
29000000080000000f000000
29000000080000000f000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
};
-
{e=>0,c=>3,a=>-75,b=>1,d=>1,f=>0}
b5ffffff0d00000001000000
b5ffffff0d00000001000000
b5ffffff0d00000001000000
b5ffffff0d00000001000000
-
{e=>1,c=>3,a=>-74,b=>1,d=>1,f=>0}
b6ffffff0d00000005000000
b6ffffff0d00000005000000
b6ffffff0d00000005000000
b6ffffff0d00000005000000
-
{e=>-2,c=>0,a=>7,b=>2,d=>2,f=>0}
07000000020000000a000000
07000000020000000a000000
07000000020000000a000000
07000000020000000a000000
-
{e=>-1,c=>0,a=>-14,b=>3,d=>2,f=>-1}
f2ffffff030000003e000000
f2ffffff030000003e000000
f2ffffff030000003e000000
f2ffffff030000003e000000
-
{e=>0,c=>2,a=>-68,b=>1,d=>3,f=>-2}
bcffffff0900000023000000
bcffffff0900000023000000
bcffffff0900000023000000
bcffffff0900000023000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
};
-
{e=>-1,c=>0,a=>-121,g=>-2,b=>1,d=>0,f=>-2}
87ffffff010000002c00000002000000
87ffffff010000002c00000002000000
87ffffff010000002c00000002000000
87ffffff010000002c00000002000000
-
{e=>-2,c=>2,a=>125,g=>-2,b=>3,d=>3,f=>-2}
7d0000000b0000002b00000002000000
7d0000000b0000002b00000002000000
7d0000000b0000002b00000002000000
7d0000000b0000002b00000002000000
-
{e=>-2,c=>0,a=>23,g=>-2,b=>0,d=>0,f=>1}
17000000000000001800000002000000
17000000000000001800000002000000
17000000000000001800000002000000
17000000000000001800000002000000
-
{e=>-2,c=>0,a=>-89,g=>1,b=>2,d=>2,f=>-1}
a7ffffff020000003a00000001000000
a7ffffff020000003a00000001000000
a7ffffff020000003a00000001000000
a7ffffff020000003a00000001000000
-
{e=>-1,c=>3,a=>46,g=>1,b=>1,d=>1,f=>0}
2e0000000d0000000d00000001000000
2e0000000d0000000d00000001000000
2e0000000d0000000d00000001000000
2e0000000d0000000d00000001000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
};
-
{e=>-2,a=>-37,d=>1,c=>1,h=>0,b=>0,g=>1,f=>-1}
dbffffff040000003900000001000000
dbffffff040000003900000001000000
dbffffff040000003900000001000000
dbffffff040000003900000001000000
-
{e=>0,a=>-96,d=>3,c=>3,h=>1,b=>0,g=>-2,f=>1}
a0ffffff0c0000001300000006000000
a0ffffff0c0000001300000006000000
a0ffffff0c0000001300000006000000
a0ffffff0c0000001300000006000000
-
{e=>-1,a=>-27,d=>1,c=>3,h=>-1,b=>1,g=>1,f=>-1}
e5ffffff0d0000003d0000000d000000
e5ffffff0d0000003d0000000d000000
e5ffffff0d0000003d0000000d000000
e5ffffff0d0000003d0000000d000000
-
{e=>-2,a=>-117,d=>3,c=>2,h=>-2,b=>1,g=>-1,f=>-2}
8bffffff090000002b0000000b000000
8bffffff090000002b0000000b000000
8bffffff090000002b0000000b000000
8bffffff090000002b0000000b000000
-
{e=>1,a=>-10,d=>0,c=>0,h=>-2,b=>0,g=>1,f=>1}
f6ffffff000000001400000009000000
f6ffffff000000001400000009000000
f6ffffff000000001400000009000000
f6ffffff000000001400000009000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
};
-
{e=>1,a=>-4,d=>3,c=>3,h=>-2,b=>0,g=>1,f=>-1,i=>-1}
fcffffff0c0000003700000039000000
fcffffff0c0000003700000039000000
fcffffff0c0000003700000039000000
fcffffff0c0000003700000039000000
-
{e=>0,a=>98,d=>2,c=>2,h=>0,b=>2,g=>0,f=>1,i=>-2}
620000000a0000001200000020000000
620000000a0000001200000020000000
620000000a0000001200000020000000
620000000a0000001200000020000000
-
{e=>1,a=>40,d=>3,c=>2,h=>1,b=>3,g=>0,f=>-1,i=>1}
280000000b0000003700000014000000
280000000b0000003700000014000000
280000000b0000003700000014000000
280000000b0000003700000014000000
-
{e=>0,a=>-91,d=>0,c=>3,h=>0,b=>2,g=>-1,f=>-1,i=>-1}
a5ffffff0e0000003000000033000000
a5ffffff0e0000003000000033000000
a5ffffff0e0000003000000033000000
a5ffffff0e0000003000000033000000
-
{e=>0,a=>111,d=>2,c=>1,h=>-1,b=>0,g=>-2,f=>-2,i=>-1}
6f00000004000000220000003e000000
6f00000004000000220000003e000000
6f00000004000000220000003e000000
6f00000004000000220000003e000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
};
-
{e=>0,a=>-110,d=>2,c=>3,h=>-1,b=>1,g=>0,f=>-2,i=>0}
92ffffff0d000000220000000c000000
92ffffff0d000000220000000c000000
92ffffff0d000000220000000c000000
92ffffff0d000000220000000c000000
-
{e=>-2,a=>-48,d=>1,c=>0,h=>-2,b=>3,g=>1,f=>0,i=>1}
d0ffffff030000000900000019000000
d0ffffff030000000900000019000000
d0ffffff030000000900000019000000
d0ffffff030000000900000019000000
-
{e=>-1,a=>107,d=>3,c=>3,h=>0,b=>3,g=>1,f=>1,i=>0}
6b0000000f0000001f00000001000000
6b0000000f0000001f00000001000000
6b0000000f0000001f00000001000000
6b0000000f0000001f00000001000000
-
{e=>-1,a=>23,d=>3,c=>0,h=>-2,b=>0,g=>0,f=>0,i=>1}
17000000000000000f00000018000000
17000000000000000f00000018000000
17000000000000000f00000018000000
17000000000000000f00000018000000
-
{e=>-2,a=>-85,d=>3,c=>2,h=>0,b=>1,g=>0,f=>-1,i=>1}
abffffff090000003b00000010000000
abffffff090000003b00000010000000
abffffff090000003b00000010000000
abffffff090000003b00000010000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
  int          j:2;
};
-
{e=>0,a=>-100,d=>3,j=>-1,c=>2,h=>-1,b=>1,g=>-1,f=>-1,i=>-1}
9cffffff09000000330000003f00000003000000
9cffffff09000000330000003f00000003000000
9cffffff09000000330000003f00000003000000
9cffffff09000000330000003f00000003000000
-
{e=>1,a=>18,d=>0,j=>1,c=>2,h=>-2,b=>2,g=>1,f=>-2,i=>0}
120000000a000000240000000900000001000000
120000000a000000240000000900000001000000
120000000a000000240000000900000001000000
120000000a000000240000000900000001000000
-
{e=>-2,a=>-36,d=>1,j=>0,c=>0,h=>-2,b=>2,g=>-1,f=>0,i=>-1}
dcffffff02000000090000003b00000000000000
dcffffff02000000090000003b00000000000000
dcffffff02000000090000003b00000000000000
dcffffff02000000090000003b00000000000000
-
{e=>1,a=>-45,d=>0,j=>0,c=>0,h=>0,b=>0,g=>1,f=>0,i=>-1}
d3ffffff00000000040000003100000000000000
d3ffffff00000000040000003100000000000000
d3ffffff00000000040000003100000000000000
d3ffffff00000000040000003100000000000000
-
{e=>-2,a=>103,d=>3,j=>-2,c=>0,h=>1,b=>0,g=>1,f=>0,i=>1}
67000000000000000b0000001500000002000000
67000000000000000b0000001500000002000000
67000000000000000b0000001500000002000000
67000000000000000b0000001500000002000000
=
struct mixed2 {
  int a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
  int          j:2;
  int          k;
};
-
{e=>-2,a=>108,d=>3,j=>-2,c=>0,k=>-117,h=>1,b=>0,g=>1,f=>-1,i=>-1}
6c000000000000003b00000035000000020000008bffffff
6c000000000000003b00000035000000020000008bffffff
6c000000000000003b00000035000000020000008bffffff
6c000000000000003b00000035000000020000008bffffff
-
{e=>-1,a=>43,d=>1,j=>-1,c=>1,k=>16,h=>-2,b=>2,g=>-2,f=>-2,i=>1}
2b000000060000002d0000001a0000000300000010000000
2b000000060000002d0000001a0000000300000010000000
2b000000060000002d0000001a0000000300000010000000
2b000000060000002d0000001a0000000300000010000000
-
{e=>1,a=>-38,d=>0,j=>0,c=>3,k=>-25,h=>-1,b=>0,g=>-1,f=>0,i=>1}
daffffff0c000000040000001f00000000000000e7ffffff
daffffff0c000000040000001f00000000000000e7ffffff
daffffff0c000000040000001f00000000000000e7ffffff
daffffff0c000000040000001f00000000000000e7ffffff
-
{e=>0,a=>-93,d=>3,j=>0,c=>1,k=>23,h=>-2,b=>1,g=>-1,f=>0,i=>0}
a3ffffff05000000030000000b0000000000000017000000
a3ffffff05000000030000000b0000000000000017000000
a3ffffff05000000030000000b0000000000000017000000
a3ffffff05000000030000000b0000000000000017000000
-
{e=>0,a=>108,d=>2,j=>-1,c=>1,k=>90,h=>-2,b=>0,g=>-2,f=>0,i=>1}
6c00000004000000020000001a000000030000005a000000
6c00000004000000020000001a000000030000005a000000
6c00000004000000020000001a000000030000005a000000
6c00000004000000020000001a000000030000005a000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
};
-
{a=>25,b=>0}
1900000000000000
1900000000000000
1900000000000000
1900000000000000
-
{a=>-13,b=>2}
f3ffffff02000000
f3ffffff02000000
f3ffffff02000000
f3ffffff02000000
-
{a=>-45,b=>3}
d3ffffff03000000
d3ffffff03000000
d3ffffff03000000
d3ffffff03000000
-
{a=>-4,b=>0}
fcffffff00000000
fcffffff00000000
fcffffff00000000
fcffffff00000000
-
{a=>121,b=>3}
7900000003000000
7900000003000000
7900000003000000
7900000003000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
};
-
{c=>2,a=>-103,b=>2}
99ffffff0a000000
99ffffff0a000000
99ffffff0a000000
99ffffff0a000000
-
{c=>1,a=>15,b=>2}
0f00000006000000
0f00000006000000
0f00000006000000
0f00000006000000
-
{c=>2,a=>30,b=>1}
1e00000009000000
1e00000009000000
1e00000009000000
1e00000009000000
-
{c=>0,a=>77,b=>1}
4d00000001000000
4d00000001000000
4d00000001000000
4d00000001000000
-
{c=>0,a=>35,b=>3}
2300000003000000
2300000003000000
2300000003000000
2300000003000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
};
-
{c=>3,a=>24,b=>2}
180000000e000000
180000000e000000
180000000e000000
180000000e000000
-
{c=>1,a=>20,b=>0}
1400000004000000
1400000004000000
1400000004000000
1400000004000000
-
{c=>3,a=>-15,b=>2}
f1ffffff0e000000
f1ffffff0e000000
f1ffffff0e000000
f1ffffff0e000000
-
{c=>1,a=>8,b=>1}
0800000005000000
0800000005000000
0800000005000000
0800000005000000
-
{c=>3,a=>79,b=>3}
4f0000000f000000
4f0000000f000000
4f0000000f000000
4f0000000f000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
};
-
{c=>1,a=>-41,b=>3,d=>0}
d7ffffff0700000000000000
d7ffffff0700000000000000
d7ffffff0700000000000000
d7ffffff0700000000000000
-
{c=>0,a=>89,b=>3,d=>2}
590000000300000002000000
590000000300000002000000
590000000300000002000000
590000000300000002000000
-
{c=>1,a=>72,b=>2,d=>1}
480000000600000001000000
480000000600000001000000
480000000600000001000000
480000000600000001000000
-
{c=>3,a=>-32,b=>1,d=>2}
e0ffffff0d00000002000000
e0ffffff0d00000002000000
e0ffffff0d00000002000000
e0ffffff0d00000002000000
-
{c=>1,a=>96,b=>0,d=>0}
600000000400000000000000
600000000400000000000000
600000000400000000000000
600000000400000000000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
};
-
{e=>-2,c=>1,a=>52,b=>3,d=>1}
340000000700000009000000
340000000700000009000000
340000000700000009000000
340000000700000009000000
-
{e=>-1,c=>2,a=>-124,b=>2,d=>3}
84ffffff0a0000000f000000
84ffffff0a0000000f000000
84ffffff0a0000000f000000
84ffffff0a0000000f000000
-
{e=>-1,c=>1,a=>-79,b=>2,d=>1}
b1ffffff060000000d000000
b1ffffff060000000d000000
b1ffffff060000000d000000
b1ffffff060000000d000000
-
{e=>0,c=>0,a=>-70,b=>2,d=>2}
baffffff0200000002000000
baffffff0200000002000000
baffffff0200000002000000
baffffff0200000002000000
-
{e=>-1,c=>0,a=>-18,b=>2,d=>1}
eeffffff020000000d000000
eeffffff020000000d000000
eeffffff020000000d000000
eeffffff020000000d000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
};
-
{e=>-1,c=>2,a=>-31,b=>0,d=>2,f=>1}
e1ffffff080000001e000000
e1ffffff080000001e000000
e1ffffff080000001e000000
e1ffffff080000001e000000
-
{e=>0,c=>2,a=>-103,b=>2,d=>1,f=>0}
99ffffff0a00000001000000
99ffffff0a00000001000000
99ffffff0a00000001000000
99ffffff0a00000001000000
-
{e=>-1,c=>2,a=>51,b=>3,d=>1,f=>-1}
330000000b0000003d000000
330000000b0000003d000000
330000000b0000003d000000
330000000b0000003d000000
-
{e=>1,c=>3,a=>-94,b=>0,d=>0,f=>-1}
a2ffffff0c00000034000000
a2ffffff0c00000034000000
a2ffffff0c00000034000000
a2ffffff0c00000034000000
-
{e=>-1,c=>3,a=>-14,b=>0,d=>2,f=>-2}
f2ffffff0c0000002e000000
f2ffffff0c0000002e000000
f2ffffff0c0000002e000000
f2ffffff0c0000002e000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
};
-
{e=>-2,c=>0,a=>80,b=>1,d=>0,f=>0}
500000000100000008000000
500000000100000008000000
500000000100000008000000
500000000100000008000000
-
{e=>1,c=>2,a=>12,b=>1,d=>1,f=>-2}
0c0000000900000025000000
0c0000000900000025000000
0c0000000900000025000000
0c0000000900000025000000
-
{e=>-2,c=>0,a=>-50,b=>2,d=>3,f=>-1}
ceffffff020000003b000000
ceffffff020000003b000000
ceffffff020000003b000000
ceffffff020000003b000000
-
{e=>-1,c=>1,a=>95,b=>3,d=>2,f=>-1}
5f000000070000003e000000
5f000000070000003e000000
5f000000070000003e000000
5f000000070000003e000000
-
{e=>1,c=>2,a=>99,b=>0,d=>3,f=>0}
630000000800000007000000
630000000800000007000000
630000000800000007000000
630000000800000007000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
};
-
{e=>1,c=>2,a=>-83,g=>-2,b=>3,d=>2,f=>1}
adffffff0b0000001600000002000000
adffffff0b0000001600000002000000
adffffff0b0000001600000002000000
adffffff0b0000001600000002000000
-
{e=>1,c=>2,a=>21,g=>-2,b=>3,d=>1,f=>1}
150000000b0000001500000002000000
150000000b0000001500000002000000
150000000b0000001500000002000000
150000000b0000001500000002000000
-
{e=>0,c=>2,a=>90,g=>0,b=>0,d=>2,f=>1}
5a000000080000001200000000000000
5a000000080000001200000000000000
5a000000080000001200000000000000
5a000000080000001200000000000000
-
{e=>-2,c=>3,a=>-13,g=>-2,b=>2,d=>2,f=>-2}
f3ffffff0e0000002a00000002000000
f3ffffff0e0000002a00000002000000
f3ffffff0e0000002a00000002000000
f3ffffff0e0000002a00000002000000
-
{e=>-2,c=>0,a=>125,g=>-1,b=>1,d=>1,f=>-2}
7d000000010000002900000003000000
7d000000010000002900000003000000
7d000000010000002900000003000000
7d000000010000002900000003000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
};
-
{e=>1,a=>-118,d=>0,c=>1,h=>0,b=>2,g=>0,f=>1}
8affffff060000001400000000000000
8affffff060000001400000000000000
8affffff060000001400000000000000
8affffff060000001400000000000000
-
{e=>-1,a=>-22,d=>2,c=>1,h=>-2,b=>0,g=>-2,f=>-1}
eaffffff040000003e0000000a000000
eaffffff040000003e0000000a000000
eaffffff040000003e0000000a000000
eaffffff040000003e0000000a000000
-
{e=>0,a=>35,d=>2,c=>2,h=>1,b=>0,g=>-1,f=>0}
23000000080000000200000007000000
23000000080000000200000007000000
23000000080000000200000007000000
23000000080000000200000007000000
-
{e=>1,a=>109,d=>0,c=>0,h=>0,b=>0,g=>1,f=>0}
6d000000000000000400000001000000
6d000000000000000400000001000000
6d000000000000000400000001000000
6d000000000000000400000001000000
-
{e=>1,a=>67,d=>1,c=>1,h=>0,b=>0,g=>-2,f=>0}
43000000040000000500000002000000
43000000040000000500000002000000
43000000040000000500000002000000
43000000040000000500000002000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
};
-
{e=>-1,a=>-88,d=>2,c=>3,h=>-1,b=>3,g=>-2,f=>0,i=>-1}
a8ffffff0f0000000e0000003e000000
a8ffffff0f0000000e0000003e000000
a8ffffff0f0000000e0000003e000000
a8ffffff0f0000000e0000003e000000
-
{e=>-1,a=>117,d=>0,c=>2,h=>-1,b=>2,g=>-1,f=>0,i=>0}
750000000a0000000c0000000f000000
750000000a0000000c0000000f000000
750000000a0000000c0000000f000000
750000000a0000000c0000000f000000
-
{e=>-1,a=>119,d=>1,c=>0,h=>-1,b=>2,g=>1,f=>-2,i=>1}
77000000020000002d0000001d000000
77000000020000002d0000001d000000
77000000020000002d0000001d000000
77000000020000002d0000001d000000
-
{e=>0,a=>-126,d=>1,c=>2,h=>1,b=>2,g=>0,f=>0,i=>-2}
82ffffff0a0000000100000024000000
82ffffff0a0000000100000024000000
82ffffff0a0000000100000024000000
82ffffff0a0000000100000024000000
-
{e=>-1,a=>-78,d=>3,c=>2,h=>-2,b=>2,g=>-2,f=>-1,i=>1}
b2ffffff0a0000003f0000001a000000
b2ffffff0a0000003f0000001a000000
b2ffffff0a0000003f0000001a000000
b2ffffff0a0000003f0000001a000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
};
-
{e=>0,a=>-53,d=>0,c=>3,h=>-1,b=>1,g=>1,f=>1,i=>0}
cbffffff0d000000100000000d000000
cbffffff0d000000100000000d000000
cbffffff0d000000100000000d000000
cbffffff0d000000100000000d000000
-
{e=>-2,a=>-108,d=>2,c=>0,h=>-1,b=>2,g=>-1,f=>0,i=>-2}
94ffffff020000000a0000002f000000
94ffffff020000000a0000002f000000
94ffffff020000000a0000002f000000
94ffffff020000000a0000002f000000
-
{e=>1,a=>-117,d=>1,c=>1,h=>0,b=>1,g=>-2,f=>0,i=>-1}
8bffffff050000000500000032000000
8bffffff050000000500000032000000
8bffffff050000000500000032000000
8bffffff050000000500000032000000
-
{e=>1,a=>121,d=>1,c=>1,h=>-2,b=>0,g=>1,f=>0,i=>1}
79000000040000000500000019000000
79000000040000000500000019000000
79000000040000000500000019000000
79000000040000000500000019000000
-
{e=>-2,a=>-2,d=>1,c=>3,h=>-2,b=>0,g=>-1,f=>-2,i=>-2}
feffffff0c000000290000002b000000
feffffff0c000000290000002b000000
feffffff0c000000290000002b000000
feffffff0c000000290000002b000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
  int          j:2;
};
-
{e=>-1,a=>65,d=>2,j=>-1,c=>3,h=>0,b=>0,g=>1,f=>0,i=>0}
410000000c0000000e0000000100000003000000
410000000c0000000e0000000100000003000000
410000000c0000000e0000000100000003000000
410000000c0000000e0000000100000003000000
-
{e=>-1,a=>68,d=>0,j=>1,c=>0,h=>-2,b=>2,g=>-1,f=>-2,i=>-1}
44000000020000002c0000003b00000001000000
44000000020000002c0000003b00000001000000
44000000020000002c0000003b00000001000000
44000000020000002c0000003b00000001000000
-
{e=>1,a=>15,d=>3,j=>0,c=>0,h=>-1,b=>3,g=>1,f=>-2,i=>-1}
0f00000003000000270000003d00000000000000
0f00000003000000270000003d00000000000000
0f00000003000000270000003d00000000000000
0f00000003000000270000003d00000000000000
-
{e=>-1,a=>-76,d=>3,j=>-2,c=>3,h=>1,b=>2,g=>1,f=>-2,i=>1}
b4ffffff0e0000002f0000001500000002000000
b4ffffff0e0000002f0000001500000002000000
b4ffffff0e0000002f0000001500000002000000
b4ffffff0e0000002f0000001500000002000000
-
{e=>-1,a=>65,d=>3,j=>1,c=>1,h=>0,b=>2,g=>0,f=>0,i=>0}
41000000060000000f0000000000000001000000
41000000060000000f0000000000000001000000
41000000060000000f0000000000000001000000
41000000060000000f0000000000000001000000
=
struct mixed2 {
  long a;
  unsigned int b:2;
  unsigned int c:2;
  unsigned int  :0;
  unsigned int d:2;
  signed   int e:2;
  signed   int f:2;
  signed   int  :0;
  signed   int g:2;
  int          h:2;
  int          i:2;
  int           :0;
  int          j:2;
  int          k;
};
-
{e=>1,a=>-49,d=>0,j=>-2,c=>3,k=>-42,h=>1,b=>0,g=>-2,f=>1,i=>-2}
cfffffff0c000000140000002600000002000000d6ffffff
cfffffff0c000000140000002600000002000000d6ffffff
cfffffff0c000000140000002600000002000000d6ffffff
cfffffff0c000000140000002600000002000000d6ffffff
-
{e=>0,a=>91,d=>3,j=>-2,c=>2,k=>-107,h=>0,b=>3,g=>-2,f=>-2,i=>0}
5b0000000b00000023000000020000000200000095ffffff
5b0000000b00000023000000020000000200000095ffffff
5b0000000b00000023000000020000000200000095ffffff
5b0000000b00000023000000020000000200000095ffffff
-
{e=>-1,a=>119,d=>0,j=>-1,c=>2,k=>-75,h=>0,b=>0,g=>0,f=>0,i=>1}
77000000080000000c0000001000000003000000b5ffffff
77000000080000000c0000001000000003000000b5ffffff
77000000080000000c0000001000000003000000b5ffffff
77000000080000000c0000001000000003000000b5ffffff
-
{e=>1,a=>56,d=>2,j=>-2,c=>1,k=>-42,h=>-2,b=>2,g=>0,f=>-1,i=>0}
3800000006000000360000000800000002000000d6ffffff
3800000006000000360000000800000002000000d6ffffff
3800000006000000360000000800000002000000d6ffffff
3800000006000000360000000800000002000000d6ffffff
-
{e=>0,a=>47,d=>2,j=>1,c=>3,k=>-15,h=>-1,b=>0,g=>-1,f=>0,i=>1}
2f0000000c000000020000001f00000001000000f1ffffff
2f0000000c000000020000001f00000001000000f1ffffff
2f0000000c000000020000001f00000001000000f1ffffff
2f0000000c000000020000001f00000001000000f1ffffff
=
struct uch_wrap {
  unsigned char a:3;
};
-
{a=>1}
01
01
01
01
-
{a=>4}
04
04
04
04
-
{a=>3}
03
03
03
03
-
{a=>1}
01
01
01
01
-
{a=>7}
07
07
07
07
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
};
-
{a=>1,b=>3}
19
19
19
19
-
{a=>0,b=>4}
20
20
20
20
-
{a=>1,b=>6}
31
31
31
31
-
{a=>5,b=>4}
25
25
25
25
-
{a=>0,b=>4}
20
20
20
20
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
};
-
{c=>4,a=>7,b=>7}
3f04
3f04
3f04
3f04
-
{c=>7,a=>3,b=>3}
1b07
1b07
1b07
1b07
-
{c=>0,a=>6,b=>5}
2e00
2e00
2e00
2e00
-
{c=>3,a=>5,b=>3}
1d03
1d03
1d03
1d03
-
{c=>5,a=>6,b=>1}
0e05
0e05
0e05
0e05
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
};
-
{c=>2,a=>2,b=>6,d=>2}
3212
3212
3212
3212
-
{c=>3,a=>2,b=>5,d=>7}
2a3b
2a3b
2a3b
2a3b
-
{c=>2,a=>6,b=>7,d=>2}
3e12
3e12
3e12
3e12
-
{c=>7,a=>6,b=>6,d=>4}
3627
3627
3627
3627
-
{c=>7,a=>2,b=>2,d=>7}
123f
123f
123f
123f
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
};
-
{e=>6,c=>0,a=>7,b=>2,d=>5}
172806
172806
172806
172806
-
{e=>0,c=>7,a=>1,b=>5,d=>5}
292f00
292f00
292f00
292f00
-
{e=>7,c=>4,a=>7,b=>7,d=>7}
3f3c07
3f3c07
3f3c07
3f3c07
-
{e=>2,c=>2,a=>2,b=>6,d=>6}
323202
323202
323202
323202
-
{e=>0,c=>5,a=>6,b=>6,d=>5}
362d00
362d00
362d00
362d00
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
};
-
{e=>2,c=>2,a=>0,b=>7,d=>5,f=>4}
382a22
382a22
382a22
382a22
-
{e=>1,c=>5,a=>1,b=>5,d=>5,f=>5}
292d29
292d29
292d29
292d29
-
{e=>5,c=>7,a=>1,b=>7,d=>6,f=>4}
393725
393725
393725
393725
-
{e=>5,c=>6,a=>6,b=>1,d=>4,f=>1}
0e260d
0e260d
0e260d
0e260d
-
{e=>6,c=>2,a=>7,b=>1,d=>6,f=>3}
0f321e
0f321e
0f321e
0f321e
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
};
-
{e=>7,c=>4,a=>5,g=>0,b=>1,d=>1,f=>1}
0d0c0f00
0d0c0f00
0d0c0f00
0d0c0f00
-
{e=>3,c=>4,a=>6,g=>2,b=>4,d=>2,f=>0}
26140302
26140302
26140302
26140302
-
{e=>2,c=>4,a=>7,g=>6,b=>6,d=>4,f=>6}
37243206
37243206
37243206
37243206
-
{e=>0,c=>6,a=>3,g=>0,b=>1,d=>6,f=>1}
0b360800
0b360800
0b360800
0b360800
-
{e=>3,c=>7,a=>0,g=>4,b=>4,d=>1,f=>4}
200f2304
200f2304
200f2304
200f2304
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
};
-
{e=>1,a=>1,d=>4,c=>6,h=>5,b=>3,g=>5,f=>5}
1926292d
1926292d
1926292d
1926292d
-
{e=>7,a=>4,d=>6,c=>1,h=>0,b=>0,g=>0,f=>3}
04311f00
04311f00
04311f00
04311f00
-
{e=>2,a=>6,d=>4,c=>1,h=>5,b=>4,g=>6,f=>3}
26211a2e
26211a2e
26211a2e
26211a2e
-
{e=>1,a=>2,d=>6,c=>2,h=>6,b=>4,g=>3,f=>0}
22320133
22320133
22320133
22320133
-
{e=>0,a=>1,d=>0,c=>3,h=>5,b=>3,g=>4,f=>5}
1903282c
1903282c
1903282c
1903282c
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
};
-
{e=>4,a=>6,d=>7,c=>0,h=>5,b=>3,g=>6,f=>2,i=>5}
1e38142e05
1e38142e05
1e38142e05
1e38142e05
-
{e=>7,a=>3,d=>1,c=>0,h=>0,b=>2,g=>5,f=>6,i=>6}
1308370506
1308370506
1308370506
1308370506
-
{e=>3,a=>2,d=>4,c=>3,h=>6,b=>2,g=>7,f=>7,i=>6}
12233b3706
12233b3706
12233b3706
12233b3706
-
{e=>0,a=>3,d=>7,c=>1,h=>7,b=>7,g=>0,f=>4,i=>0}
3b39203800
3b39203800
3b39203800
3b39203800
-
{e=>5,a=>7,d=>0,c=>1,h=>3,b=>7,g=>3,f=>6,i=>1}
3f01351b01
3f01351b01
3f01351b01
3f01351b01
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
};
-
{e=>3,a=>6,d=>1,j=>4,c=>0,h=>4,b=>1,g=>5,f=>4,i=>1}
0e08232521
0e08232521
0e08232521
0e08232521
-
{e=>6,a=>1,d=>1,j=>1,c=>2,h=>3,b=>4,g=>0,f=>5,i=>1}
210a2e1809
210a2e1809
210a2e1809
210a2e1809
-
{e=>5,a=>2,d=>6,j=>3,c=>7,h=>0,b=>7,g=>1,f=>7,i=>3}
3a373d011b
3a373d011b
3a373d011b
3a373d011b
-
{e=>6,a=>1,d=>3,j=>3,c=>5,h=>6,b=>1,g=>5,f=>3,i=>7}
091d1e351f
091d1e351f
091d1e351f
091d1e351f
-
{e=>4,a=>0,d=>5,j=>4,c=>5,h=>2,b=>1,g=>1,f=>1,i=>2}
082d0c1122
082d0c1122
082d0c1122
082d0c1122
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
};
-
{e=>0,a=>4,d=>4,j=>1,c=>3,k=>2,h=>3,b=>4,g=>2,f=>6,i=>2}
2423301a0a02
2423301a0a02
2423301a0a02
2423301a0a02
-
{e=>1,a=>6,d=>5,j=>4,c=>0,k=>1,h=>7,b=>1,g=>4,f=>7,i=>2}
0e28393c2201
0e28393c2201
0e28393c2201
0e28393c2201
-
{e=>6,a=>3,d=>6,j=>5,c=>4,k=>1,h=>2,b=>1,g=>2,f=>2,i=>7}
0b3416122f01
0b3416122f01
0b3416122f01
0b3416122f01
-
{e=>4,a=>2,d=>5,j=>1,c=>2,k=>7,h=>0,b=>0,g=>1,f=>0,i=>4}
022a04010c07
022a04010c07
022a04010c07
022a04010c07
-
{e=>5,a=>0,d=>0,j=>4,c=>6,k=>4,h=>1,b=>3,g=>4,f=>2,i=>2}
1806150c2204
1806150c2204
1806150c2204
1806150c2204
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
};
-
{e=>1,a=>4,d=>2,j=>3,l=>2,c=>1,k=>0,h=>2,b=>4,g=>2,f=>4,i=>7}
241121121f10
241121121f10
241121121f10
241121121f10
-
{e=>3,a=>2,d=>1,j=>0,l=>7,c=>0,k=>0,h=>5,b=>2,g=>6,f=>1,i=>0}
12080b2e0038
12080b2e0038
12080b2e0038
12080b2e0038
-
{e=>7,a=>6,d=>5,j=>3,l=>2,c=>7,k=>0,h=>4,b=>0,g=>7,f=>1,i=>5}
062f0f271d10
062f0f271d10
062f0f271d10
062f0f271d10
-
{e=>0,a=>3,d=>3,j=>3,l=>1,c=>5,k=>4,h=>3,b=>4,g=>3,f=>5,i=>7}
231d281b1f0c
231d281b1f0c
231d281b1f0c
231d281b1f0c
-
{e=>2,a=>2,d=>6,j=>1,l=>1,c=>6,k=>7,h=>3,b=>7,g=>5,f=>4,i=>0}
3a36221d080f
3a36221d080f
3a36221d080f
3a36221d080f
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
};
-
{e=>3,a=>6,m=>7,d=>3,j=>4,l=>4,c=>2,k=>2,h=>5,b=>7,g=>6,f=>2,i=>3}
3e1a132e232207
3e1a132e232207
3e1a132e232207
3e1a132e232207
-
{e=>2,a=>3,m=>0,d=>7,j=>7,l=>0,c=>2,k=>3,h=>1,b=>2,g=>1,f=>7,i=>7}
133a3a093f0300
133a3a093f0300
133a3a093f0300
133a3a093f0300
-
{e=>3,a=>7,m=>0,d=>4,j=>6,l=>5,c=>1,k=>6,h=>2,b=>5,g=>7,f=>5,i=>1}
2f212b17312e00
2f212b17312e00
2f212b17312e00
2f212b17312e00
-
{e=>6,a=>5,m=>3,d=>0,j=>1,l=>5,c=>1,k=>3,h=>0,b=>6,g=>4,f=>4,i=>2}
350126040a2b03
350126040a2b03
350126040a2b03
350126040a2b03
-
{e=>3,a=>3,m=>1,d=>1,j=>3,l=>4,c=>1,k=>6,h=>6,b=>1,g=>4,f=>1,i=>4}
0b090b341c2601
0b090b341c2601
0b090b341c2601
0b090b341c2601
=
struct uch_wrap {
  unsigned char a:3;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
  short         n;
};
-
{e=>1,n=>106,a=>2,m=>4,d=>4,j=>1,l=>4,c=>1,k=>6,h=>1,b=>0,g=>4,f=>7,i=>1}
0221390c0926046a00
0221390c092604006a00
0221390c092604006a00
0221390c092604006a00
-
{e=>4,n=>74,a=>5,m=>5,d=>7,j=>0,l=>4,c=>0,k=>0,h=>4,b=>7,g=>2,f=>7,i=>5}
3d383c220520054a00
3d383c22052005004a00
3d383c22052005004a00
3d383c22052005004a00
-
{e=>7,n=>-6,a=>5,m=>1,d=>2,j=>6,l=>5,c=>2,k=>2,h=>7,b=>2,g=>0,f=>0,i=>7}
15120738372a01faff
15120738372a0100faff
15120738372a0100faff
15120738372a0100faff
-
{e=>7,n=>-54,a=>2,m=>1,d=>4,j=>7,l=>3,c=>1,k=>2,h=>1,b=>2,g=>0,f=>5,i=>3}
12212f083b1a01caff
12212f083b1a0100caff
12212f083b1a0100caff
12212f083b1a0100caff
-
{e=>6,n=>118,a=>5,m=>6,d=>0,j=>7,l=>4,c=>2,k=>6,h=>3,b=>6,g=>4,f=>7,i=>0}
35023e1c3826067600
35023e1c382606007600
35023e1c382606007600
35023e1c382606007600
=
struct uch_wrap {
  char a;
  unsigned char b:3;
};
-
{a=>-70,b=>6}
ba06
ba06
ba06
ba06
-
{a=>-97,b=>5}
9f05
9f05
9f05
9f05
-
{a=>-15,b=>0}
f100
f100
f100
f100
-
{a=>-44,b=>0}
d400
d400
d400
d400
-
{a=>102,b=>7}
6607
6607
6607
6607
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
};
-
{c=>6,a=>32,b=>5}
2035
2035
2035
2035
-
{c=>5,a=>-69,b=>3}
bb2b
bb2b
bb2b
bb2b
-
{c=>3,a=>90,b=>2}
5a1a
5a1a
5a1a
5a1a
-
{c=>5,a=>80,b=>6}
502e
502e
502e
502e
-
{c=>6,a=>117,b=>3}
7533
7533
7533
7533
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
};
-
{c=>1,a=>4,b=>6,d=>2}
040e02
040e02
040e02
040e02
-
{c=>7,a=>-20,b=>1,d=>3}
ec3903
ec3903
ec3903
ec3903
-
{c=>2,a=>127,b=>1,d=>3}
7f1103
7f1103
7f1103
7f1103
-
{c=>6,a=>-48,b=>4,d=>4}
d03404
d03404
d03404
d03404
-
{c=>4,a=>-78,b=>2,d=>5}
b22205
b22205
b22205
b22205
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
};
-
{e=>3,c=>0,a=>120,b=>7,d=>7}
78071f
78071f
78071f
78071f
-
{e=>6,c=>6,a=>-75,b=>2,d=>3}
b53233
b53233
b53233
b53233
-
{e=>3,c=>2,a=>-61,b=>6,d=>7}
c3161f
c3161f
c3161f
c3161f
-
{e=>1,c=>0,a=>59,b=>7,d=>2}
3b070a
3b070a
3b070a
3b070a
-
{e=>2,c=>4,a=>61,b=>4,d=>6}
3d2416
3d2416
3d2416
3d2416
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
};
-
{e=>1,c=>4,a=>48,b=>5,d=>6,f=>3}
30250e03
30250e03
30250e03
30250e03
-
{e=>6,c=>0,a=>-47,b=>4,d=>5,f=>3}
d1043503
d1043503
d1043503
d1043503
-
{e=>5,c=>1,a=>-5,b=>4,d=>1,f=>0}
fb0c2900
fb0c2900
fb0c2900
fb0c2900
-
{e=>6,c=>2,a=>106,b=>7,d=>3,f=>4}
6a173304
6a173304
6a173304
6a173304
-
{e=>5,c=>5,a=>-105,b=>3,d=>6,f=>3}
972b2e03
972b2e03
972b2e03
972b2e03
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
};
-
{e=>4,c=>1,a=>71,g=>5,b=>0,d=>7,f=>0}
47082728
47082728
47082728
47082728
-
{e=>6,c=>7,a=>36,g=>5,b=>1,d=>5,f=>4}
2439352c
2439352c
2439352c
2439352c
-
{e=>3,c=>5,a=>-22,g=>5,b=>5,d=>4,f=>1}
ea2d1c29
ea2d1c29
ea2d1c29
ea2d1c29
-
{e=>6,c=>2,a=>43,g=>6,b=>0,d=>2,f=>0}
2b103230
2b103230
2b103230
2b103230
-
{e=>0,c=>1,a=>-119,g=>0,b=>4,d=>4,f=>1}
890c0401
890c0401
890c0401
890c0401
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
};
-
{e=>6,a=>88,d=>3,c=>5,h=>1,b=>3,g=>7,f=>2}
582b333a01
582b333a01
582b333a01
582b333a01
-
{e=>3,a=>-69,d=>7,c=>6,h=>7,b=>3,g=>7,f=>4}
bb331f3c07
bb331f3c07
bb331f3c07
bb331f3c07
-
{e=>7,a=>-30,d=>6,c=>4,h=>5,b=>0,g=>7,f=>3}
e2203e3b05
e2203e3b05
e2203e3b05
e2203e3b05
-
{e=>6,a=>-16,d=>6,c=>7,h=>5,b=>2,g=>1,f=>6}
f03a360e05
f03a360e05
f03a360e05
f03a360e05
-
{e=>1,a=>72,d=>2,c=>1,h=>1,b=>5,g=>1,f=>6}
480d0a0e01
480d0a0e01
480d0a0e01
480d0a0e01
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
};
-
{e=>2,a=>-92,d=>4,c=>2,h=>6,b=>6,g=>0,f=>3,i=>7}
a41614033e
a41614033e
a41614033e
a41614033e
-
{e=>1,a=>50,d=>4,c=>7,h=>0,b=>5,g=>6,f=>2,i=>0}
323d0c3200
323d0c3200
323d0c3200
323d0c3200
-
{e=>7,a=>-126,d=>7,c=>3,h=>5,b=>2,g=>0,f=>0,i=>4}
821a3f0025
821a3f0025
821a3f0025
821a3f0025
-
{e=>6,a=>123,d=>7,c=>4,h=>6,b=>0,g=>3,f=>6,i=>4}
7b20371e26
7b20371e26
7b20371e26
7b20371e26
-
{e=>5,a=>21,d=>0,c=>7,h=>1,b=>3,g=>0,f=>7,i=>5}
153b280729
153b280729
153b280729
153b280729
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
};
-
{e=>1,a=>79,d=>6,j=>1,c=>6,h=>0,b=>1,g=>1,f=>5,i=>4}
4f310e0d2001
4f310e0d2001
4f310e0d2001
4f310e0d2001
-
{e=>5,a=>70,d=>7,j=>4,c=>1,h=>1,b=>4,g=>2,f=>5,i=>2}
460c2f151104
460c2f151104
460c2f151104
460c2f151104
-
{e=>2,a=>90,d=>2,j=>3,c=>7,h=>2,b=>6,g=>4,f=>7,i=>4}
5a3e12272203
5a3e12272203
5a3e12272203
5a3e12272203
-
{e=>6,a=>48,d=>0,j=>3,c=>5,h=>3,b=>5,g=>6,f=>5,i=>3}
302d30351b03
302d30351b03
302d30351b03
302d30351b03
-
{e=>6,a=>-79,d=>1,j=>4,c=>1,h=>6,b=>7,g=>6,f=>4,i=>5}
b10f31342e04
b10f31342e04
b10f31342e04
b10f31342e04
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
};
-
{e=>3,a=>33,d=>5,j=>0,c=>5,k=>3,h=>3,b=>4,g=>0,f=>2,i=>4}
212c1d022318
212c1d022318
212c1d022318
212c1d022318
-
{e=>1,a=>64,d=>0,j=>2,c=>1,k=>7,h=>7,b=>1,g=>3,f=>0,i=>6}
40090818373a
40090818373a
40090818373a
40090818373a
-
{e=>0,a=>121,d=>0,j=>2,c=>3,k=>3,h=>1,b=>5,g=>0,f=>4,i=>5}
791d0004291a
791d0004291a
791d0004291a
791d0004291a
-
{e=>7,a=>-117,d=>1,j=>1,c=>6,k=>5,h=>1,b=>3,g=>1,f=>5,i=>4}
8b33390d2129
8b33390d2129
8b33390d2129
8b33390d2129
-
{e=>5,a=>105,d=>3,j=>2,c=>3,k=>7,h=>6,b=>3,g=>5,f=>1,i=>1}
691b2b290e3a
691b2b290e3a
691b2b290e3a
691b2b290e3a
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
};
-
{e=>1,a=>-36,d=>3,j=>4,l=>1,c=>5,k=>1,h=>3,b=>7,g=>3,f=>0,i=>2}
dc2f0b18130c01
dc2f0b18130c01
dc2f0b18130c01
dc2f0b18130c01
-
{e=>5,a=>-81,d=>1,j=>6,l=>1,c=>3,k=>7,h=>3,b=>5,g=>3,f=>5,i=>1}
af1d291d0b3e01
af1d291d0b3e01
af1d291d0b3e01
af1d291d0b3e01
-
{e=>0,a=>-44,d=>7,j=>3,l=>5,c=>3,k=>2,h=>2,b=>2,g=>3,f=>0,i=>6}
d41a0718321305
d41a0718321305
d41a0718321305
d41a0718321305
-
{e=>1,a=>-34,d=>1,j=>6,l=>7,c=>6,k=>0,h=>6,b=>6,g=>5,f=>2,i=>5}
de36092a2e0607
de36092a2e0607
de36092a2e0607
de36092a2e0607
-
{e=>0,a=>57,d=>4,j=>0,l=>4,c=>6,k=>1,h=>2,b=>2,g=>7,f=>6,i=>2}
3932043e120804
3932043e120804
3932043e120804
3932043e120804
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
};
-
{e=>7,a=>-101,m=>1,d=>6,j=>3,l=>6,c=>4,k=>6,h=>5,b=>1,g=>1,f=>6,i=>0}
9b213e0e05330e
9b213e0e05330e
9b213e0e05330e
9b213e0e05330e
-
{e=>3,a=>-11,m=>4,d=>2,j=>6,l=>7,c=>6,k=>4,h=>7,b=>2,g=>1,f=>4,i=>3}
f5321a0c1f2627
f5321a0c1f2627
f5321a0c1f2627
f5321a0c1f2627
-
{e=>0,a=>47,m=>2,d=>7,j=>5,l=>2,c=>2,k=>3,h=>4,b=>5,g=>5,f=>1,i=>7}
2f1507293c1d12
2f1507293c1d12
2f1507293c1d12
2f1507293c1d12
-
{e=>1,a=>-113,m=>7,d=>2,j=>1,l=>6,c=>7,k=>4,h=>7,b=>5,g=>0,f=>6,i=>7}
8f3d0a063f213e
8f3d0a063f213e
8f3d0a063f213e
8f3d0a063f213e
-
{e=>2,a=>19,m=>6,d=>7,j=>5,l=>4,c=>3,k=>7,h=>4,b=>1,g=>4,f=>0,i=>3}
131917201c3d34
131917201c3d34
131917201c3d34
131917201c3d34
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
  unsigned char n:3;
};
-
{e=>6,n=>5,a=>-111,m=>0,d=>3,j=>5,l=>6,c=>7,k=>5,h=>6,b=>0,g=>4,f=>0,i=>6}
91383320362d0605
91383320362d0605
91383320362d0605
91383320362d0605
-
{e=>7,n=>4,a=>-30,m=>6,d=>4,j=>3,l=>0,c=>4,k=>4,h=>1,b=>7,g=>7,f=>5,i=>0}
e2273c3d01233004
e2273c3d01233004
e2273c3d01233004
e2273c3d01233004
-
{e=>0,n=>1,a=>22,m=>5,d=>7,j=>5,l=>0,c=>0,k=>1,h=>5,b=>3,g=>2,f=>7,i=>3}
160307171d0d2801
160307171d0d2801
160307171d0d2801
160307171d0d2801
-
{e=>4,n=>5,a=>4,m=>0,d=>1,j=>2,l=>4,c=>1,k=>3,h=>0,b=>0,g=>0,f=>7,i=>6}
04082107301a0405
04082107301a0405
04082107301a0405
04082107301a0405
-
{e=>2,n=>3,a=>-83,m=>6,d=>6,j=>6,l=>6,c=>0,k=>1,h=>2,b=>6,g=>0,f=>6,i=>5}
ad0616062a0e3603
ad0616062a0e3603
ad0616062a0e3603
ad0616062a0e3603
=
struct uch_wrap {
  char a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
  unsigned char n:3;
  short         o;
};
-
{e=>0,n=>2,a=>-105,m=>1,d=>3,j=>0,l=>1,c=>6,k=>1,h=>1,b=>2,g=>7,f=>2,o=>-102,i=>2}
9732033a110809029aff
9732033a110809029aff
9732033a110809029aff
9732033a110809029aff
-
{e=>1,n=>2,a=>-82,m=>2,d=>4,j=>2,l=>6,c=>0,k=>3,h=>1,b=>6,g=>6,f=>3,o=>29,i=>2}
ae060c33111a16021d00
ae060c33111a16021d00
ae060c33111a16021d00
ae060c33111a16021d00
-
{e=>5,n=>7,a=>-14,m=>4,d=>0,j=>7,l=>1,c=>2,k=>7,h=>7,b=>4,g=>1,f=>5,o=>-24,i=>2}
f214280d173f2107e8ff
f214280d173f2107e8ff
f214280d173f2107e8ff
f214280d173f2107e8ff
-
{e=>0,n=>6,a=>96,m=>7,d=>3,j=>0,l=>3,c=>3,k=>1,h=>3,b=>6,g=>6,f=>7,o=>81,i=>2}
601e033713083b065100
601e033713083b065100
601e033713083b065100
601e033713083b065100
-
{e=>6,n=>2,a=>-36,m=>0,d=>2,j=>6,l=>5,c=>4,k=>0,h=>3,b=>6,g=>6,f=>5,o=>-17,i=>5}
dc2632352b060502efff
dc2632352b060502efff
dc2632352b060502efff
dc2632352b060502efff
=
struct uch_wrap {
  short a;
  unsigned char b:3;
};
-
{a=>102,b=>2}
660002
66000200
66000200
66000200
-
{a=>39,b=>4}
270004
27000400
27000400
27000400
-
{a=>-119,b=>5}
89ff05
89ff0500
89ff0500
89ff0500
-
{a=>69,b=>7}
450007
45000700
45000700
45000700
-
{a=>46,b=>7}
2e0007
2e000700
2e000700
2e000700
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
};
-
{c=>2,a=>-97,b=>2}
9fff12
9fff1200
9fff1200
9fff1200
-
{c=>5,a=>-16,b=>5}
f0ff2d
f0ff2d00
f0ff2d00
f0ff2d00
-
{c=>5,a=>100,b=>5}
64002d
64002d00
64002d00
64002d00
-
{c=>1,a=>117,b=>2}
75000a
75000a00
75000a00
75000a00
-
{c=>1,a=>-105,b=>4}
97ff0c
97ff0c00
97ff0c00
97ff0c00
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
};
-
{c=>2,a=>7,b=>5,d=>3}
07001503
07001503
07001503
07001503
-
{c=>7,a=>-90,b=>4,d=>1}
a6ff3c01
a6ff3c01
a6ff3c01
a6ff3c01
-
{c=>1,a=>61,b=>0,d=>2}
3d000802
3d000802
3d000802
3d000802
-
{c=>1,a=>36,b=>7,d=>2}
24000f02
24000f02
24000f02
24000f02
-
{c=>4,a=>-76,b=>5,d=>0}
b4ff2500
b4ff2500
b4ff2500
b4ff2500
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
};
-
{e=>4,c=>2,a=>-103,b=>0,d=>3}
99ff1023
99ff1023
99ff1023
99ff1023
-
{e=>2,c=>0,a=>17,b=>5,d=>5}
11000515
11000515
11000515
11000515
-
{e=>5,c=>5,a=>27,b=>2,d=>1}
1b002a29
1b002a29
1b002a29
1b002a29
-
{e=>1,c=>5,a=>-77,b=>3,d=>5}
b3ff2b0d
b3ff2b0d
b3ff2b0d
b3ff2b0d
-
{e=>2,c=>0,a=>-112,b=>4,d=>1}
90ff0411
90ff0411
90ff0411
90ff0411
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
};
-
{e=>3,c=>1,a=>61,b=>4,d=>2,f=>2}
3d000c1a02
3d000c1a0200
3d000c1a0200
3d000c1a0200
-
{e=>1,c=>7,a=>-8,b=>0,d=>6,f=>0}
f8ff380e00
f8ff380e0000
f8ff380e0000
f8ff380e0000
-
{e=>2,c=>6,a=>-96,b=>0,d=>5,f=>7}
a0ff301507
a0ff30150700
a0ff30150700
a0ff30150700
-
{e=>3,c=>2,a=>122,b=>5,d=>0,f=>0}
7a00151800
7a0015180000
7a0015180000
7a0015180000
-
{e=>3,c=>6,a=>-122,b=>0,d=>1,f=>2}
86ff301902
86ff30190200
86ff30190200
86ff30190200
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
};
-
{e=>1,c=>5,a=>-86,g=>7,b=>7,d=>7,f=>6}
aaff2f0f3e
aaff2f0f3e00
aaff2f0f3e00
aaff2f0f3e00
-
{e=>5,c=>7,a=>78,g=>2,b=>1,d=>6,f=>1}
4e00392e11
4e00392e1100
4e00392e1100
4e00392e1100
-
{e=>4,c=>0,a=>-57,g=>4,b=>2,d=>4,f=>1}
c7ff022421
c7ff02242100
c7ff02242100
c7ff02242100
-
{e=>6,c=>6,a=>36,g=>3,b=>1,d=>5,f=>3}
240031351b
240031351b00
240031351b00
240031351b00
-
{e=>5,c=>6,a=>-105,g=>2,b=>7,d=>7,f=>0}
97ff372f10
97ff372f1000
97ff372f1000
97ff372f1000
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
};
-
{e=>2,a=>103,d=>5,c=>5,h=>6,b=>3,g=>2,f=>1}
67002b151106
67002b151106
67002b151106
67002b151106
-
{e=>1,a=>-88,d=>4,c=>6,h=>1,b=>5,g=>2,f=>3}
a8ff350c1301
a8ff350c1301
a8ff350c1301
a8ff350c1301
-
{e=>0,a=>-80,d=>3,c=>7,h=>5,b=>3,g=>5,f=>6}
b0ff3b032e05
b0ff3b032e05
b0ff3b032e05
b0ff3b032e05
-
{e=>5,a=>-89,d=>6,c=>6,h=>1,b=>0,g=>4,f=>1}
a7ff302e2101
a7ff302e2101
a7ff302e2101
a7ff302e2101
-
{e=>4,a=>-32,d=>5,c=>2,h=>0,b=>4,g=>7,f=>7}
e0ff14253f00
e0ff14253f00
e0ff14253f00
e0ff14253f00
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
};
-
{e=>6,a=>-1,d=>6,c=>3,h=>1,b=>6,g=>2,f=>7,i=>5}
ffff1e361729
ffff1e361729
ffff1e361729
ffff1e361729
-
{e=>1,a=>21,d=>3,c=>7,h=>0,b=>3,g=>5,f=>0,i=>1}
15003b0b2808
15003b0b2808
15003b0b2808
15003b0b2808
-
{e=>4,a=>124,d=>0,c=>3,h=>5,b=>6,g=>1,f=>0,i=>7}
7c001e20083d
7c001e20083d
7c001e20083d
7c001e20083d
-
{e=>6,a=>53,d=>6,c=>4,h=>3,b=>7,g=>3,f=>0,i=>0}
350027361803
350027361803
350027361803
350027361803
-
{e=>5,a=>14,d=>0,c=>5,h=>0,b=>0,g=>0,f=>4,i=>1}
0e0028280408
0e0028280408
0e0028280408
0e0028280408
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
};
-
{e=>4,a=>-128,d=>5,j=>4,c=>0,h=>4,b=>2,g=>7,f=>5,i=>5}
80ff02253d2c04
80ff02253d2c0400
80ff02253d2c0400
80ff02253d2c0400
-
{e=>5,a=>-33,d=>3,j=>4,c=>5,h=>7,b=>7,g=>1,f=>6,i=>5}
dfff2f2b0e2f04
dfff2f2b0e2f0400
dfff2f2b0e2f0400
dfff2f2b0e2f0400
-
{e=>3,a=>-96,d=>1,j=>1,c=>4,h=>2,b=>3,g=>7,f=>6,i=>6}
a0ff23193e3201
a0ff23193e320100
a0ff23193e320100
a0ff23193e320100
-
{e=>7,a=>-9,d=>6,j=>4,c=>3,h=>1,b=>3,g=>3,f=>1,i=>0}
f7ff1b3e190104
f7ff1b3e19010400
f7ff1b3e19010400
f7ff1b3e19010400
-
{e=>2,a=>63,d=>4,j=>2,c=>4,h=>0,b=>4,g=>3,f=>5,i=>0}
3f0024141d0002
3f0024141d000200
3f0024141d000200
3f0024141d000200
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
};
-
{e=>4,a=>57,d=>7,j=>7,c=>4,k=>0,h=>5,b=>3,g=>3,f=>4,i=>6}
390023271c3507
390023271c350700
390023271c350700
390023271c350700
-
{e=>7,a=>-11,d=>1,j=>4,c=>0,k=>5,h=>1,b=>5,g=>5,f=>7,i=>5}
f5ff05392f292c
f5ff05392f292c00
f5ff05392f292c00
f5ff05392f292c00
-
{e=>7,a=>-117,d=>2,j=>6,c=>7,k=>6,h=>1,b=>2,g=>0,f=>1,i=>1}
8bff3a3a010936
8bff3a3a01093600
8bff3a3a01093600
8bff3a3a01093600
-
{e=>7,a=>-118,d=>6,j=>3,c=>7,k=>4,h=>2,b=>4,g=>3,f=>6,i=>0}
8aff3c3e1e0223
8aff3c3e1e022300
8aff3c3e1e022300
8aff3c3e1e022300
-
{e=>4,a=>-15,d=>1,j=>1,c=>7,k=>6,h=>5,b=>4,g=>7,f=>3,i=>7}
f1ff3c213b3d31
f1ff3c213b3d3100
f1ff3c213b3d3100
f1ff3c213b3d3100
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
};
-
{e=>5,a=>24,d=>4,j=>2,l=>6,c=>3,k=>2,h=>1,b=>5,g=>4,f=>5,i=>2}
18001d2c25111206
18001d2c25111206
18001d2c25111206
18001d2c25111206
-
{e=>7,a=>-76,d=>2,j=>2,l=>5,c=>2,k=>2,h=>3,b=>5,g=>4,f=>7,i=>5}
b4ff153a272b1205
b4ff153a272b1205
b4ff153a272b1205
b4ff153a272b1205
-
{e=>4,a=>69,d=>4,j=>6,l=>1,c=>1,k=>0,h=>0,b=>6,g=>7,f=>1,i=>3}
45000e2439180601
45000e2439180601
45000e2439180601
45000e2439180601
-
{e=>6,a=>-5,d=>4,j=>4,l=>7,c=>6,k=>6,h=>2,b=>3,g=>6,f=>5,i=>6}
fbff333435323407
fbff333435323407
fbff333435323407
fbff333435323407
-
{e=>1,a=>84,d=>1,j=>5,l=>6,c=>3,k=>4,h=>7,b=>2,g=>6,f=>4,i=>3}
54001a09341f2506
54001a09341f2506
54001a09341f2506
54001a09341f2506
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
};
-
{e=>0,a=>-34,m=>7,d=>7,j=>0,l=>2,c=>3,k=>5,h=>5,b=>1,g=>0,f=>6,i=>6}
deff19070635283a
deff19070635283a
deff19070635283a
deff19070635283a
-
{e=>1,a=>-67,m=>0,d=>2,j=>7,l=>0,c=>2,k=>4,h=>2,b=>7,g=>3,f=>7,i=>4}
bdff170a1f222700
bdff170a1f222700
bdff170a1f222700
bdff170a1f222700
-
{e=>5,a=>61,m=>7,d=>1,j=>3,l=>5,c=>6,k=>5,h=>3,b=>4,g=>7,f=>3,i=>7}
3d0034293b3b2b3d
3d0034293b3b2b3d
3d0034293b3b2b3d
3d0034293b3b2b3d
-
{e=>5,a=>96,m=>6,d=>5,j=>4,l=>5,c=>1,k=>3,h=>1,b=>6,g=>2,f=>2,i=>3}
60000e2d12191c35
60000e2d12191c35
60000e2d12191c35
60000e2d12191c35
-
{e=>3,a=>-6,m=>6,d=>3,j=>6,l=>6,c=>5,k=>2,h=>5,b=>6,g=>3,f=>5,i=>0}
faff2e1b1d051636
faff2e1b1d051636
faff2e1b1d051636
faff2e1b1d051636
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
  unsigned char n:3;
};
-
{e=>7,n=>7,a=>-88,m=>4,d=>0,j=>4,l=>6,c=>3,k=>5,h=>2,b=>1,g=>6,f=>5,i=>7}
a8ff1938353a2c2607
a8ff1938353a2c260700
a8ff1938353a2c260700
a8ff1938353a2c260700
-
{e=>0,n=>1,a=>-51,m=>3,d=>3,j=>2,l=>4,c=>1,k=>1,h=>6,b=>6,g=>5,f=>7,i=>2}
cdff0e032f160a1c01
cdff0e032f160a1c0100
cdff0e032f160a1c0100
cdff0e032f160a1c0100
-
{e=>2,n=>6,a=>20,m=>5,d=>3,j=>4,l=>6,c=>1,k=>3,h=>6,b=>5,g=>4,f=>2,i=>5}
14000d13222e1c2e06
14000d13222e1c2e0600
14000d13222e1c2e0600
14000d13222e1c2e0600
-
{e=>4,n=>1,a=>-110,m=>2,d=>6,j=>4,l=>5,c=>4,k=>5,h=>0,b=>1,g=>7,f=>4,i=>6}
92ff21263c302c1501
92ff21263c302c150100
92ff21263c302c150100
92ff21263c302c150100
-
{e=>0,n=>0,a=>-45,m=>2,d=>5,j=>7,l=>4,c=>5,k=>6,h=>1,b=>2,g=>6,f=>4,i=>0}
d3ff2a053401371400
d3ff2a05340137140000
d3ff2a05340137140000
d3ff2a05340137140000
=
struct uch_wrap {
  short a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
  unsigned char n:3;
  short         o;
};
-
{e=>0,n=>2,a=>-65,m=>5,d=>5,j=>4,l=>2,c=>5,k=>0,h=>7,b=>2,g=>6,f=>3,o=>-15,i=>2}
bfff2a053317042a02f1ff
bfff2a053317042a0200f1ff
bfff2a053317042a0200f1ff
bfff2a053317042a0200f1ff
-
{e=>3,n=>6,a=>15,m=>2,d=>7,j=>7,l=>4,c=>5,k=>4,h=>2,b=>0,g=>3,f=>3,o=>30,i=>1}
0f00281f1b0a2714061e00
0f00281f1b0a271406001e00
0f00281f1b0a271406001e00
0f00281f1b0a271406001e00
-
{e=>5,n=>7,a=>74,m=>6,d=>0,j=>7,l=>5,c=>3,k=>4,h=>4,b=>3,g=>6,f=>2,o=>69,i=>5}
4a001b28322c2735074500
4a001b28322c273507004500
4a001b28322c273507004500
4a001b28322c273507004500
-
{e=>1,n=>2,a=>84,m=>2,d=>3,j=>5,l=>4,c=>3,k=>6,h=>6,b=>1,g=>6,f=>7,o=>98,i=>6}
5400190b37363514026200
5400190b3736351402006200
5400190b3736351402006200
5400190b3736351402006200
-
{e=>3,n=>6,a=>57,m=>7,d=>6,j=>0,l=>4,c=>4,k=>1,h=>1,b=>2,g=>2,f=>7,o=>-43,i=>0}
3900221e1701083c06d5ff
3900221e1701083c0600d5ff
3900221e1701083c0600d5ff
3900221e1701083c0600d5ff
=
struct uch_wrap {
  int a;
  unsigned char b:3;
};
-
{a=>-6,b=>4}
faffffff04
faffffff0400
faffffff04000000
faffffff04000000
-
{a=>48,b=>4}
3000000004
300000000400
3000000004000000
3000000004000000
-
{a=>24,b=>4}
1800000004
180000000400
1800000004000000
1800000004000000
-
{a=>-13,b=>5}
f3ffffff05
f3ffffff0500
f3ffffff05000000
f3ffffff05000000
-
{a=>-58,b=>1}
c6ffffff01
c6ffffff0100
c6ffffff01000000
c6ffffff01000000
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
};
-
{c=>3,a=>52,b=>2}
340000001a
340000001a00
340000001a000000
340000001a000000
-
{c=>6,a=>-113,b=>2}
8fffffff32
8fffffff3200
8fffffff32000000
8fffffff32000000
-
{c=>7,a=>-72,b=>6}
b8ffffff3e
b8ffffff3e00
b8ffffff3e000000
b8ffffff3e000000
-
{c=>4,a=>93,b=>7}
5d00000027
5d0000002700
5d00000027000000
5d00000027000000
-
{c=>5,a=>34,b=>5}
220000002d
220000002d00
220000002d000000
220000002d000000
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
};
-
{c=>4,a=>1,b=>6,d=>5}
010000002605
010000002605
0100000026050000
0100000026050000
-
{c=>1,a=>35,b=>0,d=>6}
230000000806
230000000806
2300000008060000
2300000008060000
-
{c=>3,a=>81,b=>1,d=>7}
510000001907
510000001907
5100000019070000
5100000019070000
-
{c=>5,a=>19,b=>3,d=>2}
130000002b02
130000002b02
130000002b020000
130000002b020000
-
{c=>7,a=>-108,b=>5,d=>3}
94ffffff3d03
94ffffff3d03
94ffffff3d030000
94ffffff3d030000
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
};
-
{e=>0,c=>0,a=>58,b=>1,d=>6}
3a0000000106
3a0000000106
3a00000001060000
3a00000001060000
-
{e=>4,c=>2,a=>67,b=>4,d=>2}
430000001422
430000001422
4300000014220000
4300000014220000
-
{e=>0,c=>2,a=>20,b=>7,d=>4}
140000001704
140000001704
1400000017040000
1400000017040000
-
{e=>7,c=>4,a=>-17,b=>5,d=>7}
efffffff253f
efffffff253f
efffffff253f0000
efffffff253f0000
-
{e=>7,c=>1,a=>-49,b=>4,d=>7}
cfffffff0c3f
cfffffff0c3f
cfffffff0c3f0000
cfffffff0c3f0000
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
};
-
{e=>7,c=>0,a=>-9,b=>1,d=>3,f=>6}
f7ffffff013b06
f7ffffff013b0600
f7ffffff013b0600
f7ffffff013b0600
-
{e=>2,c=>2,a=>72,b=>4,d=>6,f=>1}
48000000141601
4800000014160100
4800000014160100
4800000014160100
-
{e=>7,c=>0,a=>-66,b=>1,d=>4,f=>5}
beffffff013c05
beffffff013c0500
beffffff013c0500
beffffff013c0500
-
{e=>6,c=>1,a=>121,b=>7,d=>2,f=>2}
790000000f3202
790000000f320200
790000000f320200
790000000f320200
-
{e=>1,c=>6,a=>-56,b=>7,d=>4,f=>3}
c8ffffff370c03
c8ffffff370c0300
c8ffffff370c0300
c8ffffff370c0300
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
};
-
{e=>6,c=>3,a=>76,g=>4,b=>6,d=>4,f=>4}
4c0000001e3424
4c0000001e342400
4c0000001e342400
4c0000001e342400
-
{e=>0,c=>4,a=>-114,g=>7,b=>4,d=>6,f=>5}
8effffff24063d
8effffff24063d00
8effffff24063d00
8effffff24063d00
-
{e=>4,c=>5,a=>8,g=>7,b=>4,d=>0,f=>4}
080000002c203c
080000002c203c00
080000002c203c00
080000002c203c00
-
{e=>5,c=>3,a=>-73,g=>2,b=>6,d=>6,f=>4}
b7ffffff1e2e14
b7ffffff1e2e1400
b7ffffff1e2e1400
b7ffffff1e2e1400
-
{e=>7,c=>6,a=>69,g=>5,b=>2,d=>5,f=>2}
45000000323d2a
45000000323d2a00
45000000323d2a00
45000000323d2a00
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
};
-
{e=>0,a=>21,d=>5,c=>3,h=>0,b=>7,g=>4,f=>4}
150000001f052400
150000001f052400
150000001f052400
150000001f052400
-
{e=>5,a=>124,d=>3,c=>5,h=>6,b=>1,g=>3,f=>6}
7c000000292b1e06
7c000000292b1e06
7c000000292b1e06
7c000000292b1e06
-
{e=>6,a=>1,d=>4,c=>7,h=>1,b=>2,g=>4,f=>7}
010000003a342701
010000003a342701
010000003a342701
010000003a342701
-
{e=>7,a=>36,d=>6,c=>0,h=>7,b=>1,g=>5,f=>2}
24000000013e2a07
24000000013e2a07
24000000013e2a07
24000000013e2a07
-
{e=>1,a=>121,d=>4,c=>4,h=>0,b=>0,g=>6,f=>5}
79000000200c3500
79000000200c3500
79000000200c3500
79000000200c3500
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
};
-
{e=>4,a=>-75,d=>3,c=>1,h=>2,b=>0,g=>4,f=>3,i=>4}
b5ffffff08232322
b5ffffff08232322
b5ffffff08232322
b5ffffff08232322
-
{e=>4,a=>-82,d=>3,c=>2,h=>4,b=>5,g=>0,f=>2,i=>2}
aeffffff15230214
aeffffff15230214
aeffffff15230214
aeffffff15230214
-
{e=>0,a=>46,d=>7,c=>3,h=>6,b=>6,g=>7,f=>6,i=>5}
2e0000001e073e2e
2e0000001e073e2e
2e0000001e073e2e
2e0000001e073e2e
-
{e=>0,a=>4,d=>0,c=>6,h=>3,b=>5,g=>3,f=>0,i=>3}
040000003500181b
040000003500181b
040000003500181b
040000003500181b
-
{e=>0,a=>-54,d=>1,c=>7,h=>7,b=>1,g=>7,f=>6,i=>6}
caffffff39013e37
caffffff39013e37
caffffff39013e37
caffffff39013e37
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
};
-
{e=>4,a=>101,d=>4,j=>0,c=>1,h=>6,b=>4,g=>7,f=>6,i=>5}
650000000c243e2e00
650000000c243e2e0000
650000000c243e2e00000000
650000000c243e2e00000000
-
{e=>0,a=>33,d=>6,j=>1,c=>0,h=>2,b=>3,g=>0,f=>1,i=>4}
210000000306012201
21000000030601220100
210000000306012201000000
210000000306012201000000
-
{e=>0,a=>31,d=>4,j=>4,c=>3,h=>2,b=>7,g=>3,f=>7,i=>4}
1f0000001f041f2204
1f0000001f041f220400
1f0000001f041f2204000000
1f0000001f041f2204000000
-
{e=>0,a=>-102,d=>5,j=>2,c=>1,h=>3,b=>1,g=>4,f=>5,i=>4}
9affffff0905252302
9affffff090525230200
9affffff0905252302000000
9affffff0905252302000000
-
{e=>3,a=>117,d=>6,j=>5,c=>1,h=>3,b=>4,g=>4,f=>7,i=>4}
750000000c1e272305
750000000c1e27230500
750000000c1e272305000000
750000000c1e272305000000
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
};
-
{e=>7,a=>7,d=>0,j=>2,c=>5,k=>6,h=>2,b=>2,g=>6,f=>1,i=>1}
070000002a38310a32
070000002a38310a3200
070000002a38310a32000000
070000002a38310a32000000
-
{e=>0,a=>73,d=>0,j=>0,c=>6,k=>0,h=>7,b=>2,g=>4,f=>2,i=>6}
490000003200223700
49000000320022370000
490000003200223700000000
490000003200223700000000
-
{e=>5,a=>-16,d=>1,j=>5,c=>2,k=>0,h=>5,b=>3,g=>5,f=>2,i=>0}
f0ffffff13292a0505
f0ffffff13292a050500
f0ffffff13292a0505000000
f0ffffff13292a0505000000
-
{e=>2,a=>85,d=>1,j=>7,c=>7,k=>5,h=>0,b=>2,g=>7,f=>4,i=>6}
550000003a113c302f
550000003a113c302f00
550000003a113c302f000000
550000003a113c302f000000
-
{e=>1,a=>-111,d=>4,j=>1,c=>4,k=>4,h=>0,b=>1,g=>3,f=>1,i=>4}
91ffffff210c192021
91ffffff210c19202100
91ffffff210c192021000000
91ffffff210c192021000000
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
};
-
{e=>4,a=>-94,d=>1,j=>5,l=>1,c=>6,k=>5,h=>7,b=>6,g=>1,f=>1,i=>7}
a2ffffff3621093f2d01
a2ffffff3621093f2d01
a2ffffff3621093f2d010000
a2ffffff3621093f2d010000
-
{e=>2,a=>-111,d=>5,j=>6,l=>5,c=>3,k=>0,h=>6,b=>2,g=>0,f=>1,i=>6}
91ffffff1a1501360605
91ffffff1a1501360605
91ffffff1a15013606050000
91ffffff1a15013606050000
-
{e=>6,a=>-48,d=>0,j=>4,l=>6,c=>7,k=>6,h=>2,b=>0,g=>6,f=>2,i=>3}
d0ffffff3830321a3406
d0ffffff3830321a3406
d0ffffff3830321a34060000
d0ffffff3830321a34060000
-
{e=>4,a=>25,d=>5,j=>1,l=>4,c=>1,k=>1,h=>4,b=>3,g=>6,f=>7,i=>7}
190000000b25373c0904
190000000b25373c0904
190000000b25373c09040000
190000000b25373c09040000
-
{e=>5,a=>-90,d=>1,j=>4,l=>1,c=>4,k=>6,h=>6,b=>6,g=>4,f=>7,i=>6}
a6ffffff262927363401
a6ffffff262927363401
a6ffffff2629273634010000
a6ffffff2629273634010000
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
};
-
{e=>0,a=>27,m=>0,d=>1,j=>1,l=>0,c=>1,k=>4,h=>7,b=>3,g=>3,f=>1,i=>7}
1b0000000b01193f2100
1b0000000b01193f2100
1b0000000b01193f21000000
1b0000000b01193f21000000
-
{e=>4,a=>-76,m=>6,d=>7,j=>1,l=>5,c=>4,k=>7,h=>1,b=>3,g=>1,f=>4,i=>1}
b4ffffff23270c093935
b4ffffff23270c093935
b4ffffff23270c0939350000
b4ffffff23270c0939350000
-
{e=>2,a=>-46,m=>4,d=>7,j=>1,l=>1,c=>3,k=>7,h=>2,b=>4,g=>5,f=>0,i=>2}
d2ffffff1c1728123921
d2ffffff1c1728123921
d2ffffff1c17281239210000
d2ffffff1c17281239210000
-
{e=>2,a=>81,m=>0,d=>2,j=>0,l=>7,c=>1,k=>0,h=>1,b=>4,g=>7,f=>2,i=>6}
510000000c123a310007
510000000c123a310007
510000000c123a3100070000
510000000c123a3100070000
-
{e=>4,a=>-102,m=>6,d=>6,j=>4,l=>0,c=>7,k=>3,h=>1,b=>2,g=>3,f=>4,i=>6}
9affffff3a261c311c30
9affffff3a261c311c30
9affffff3a261c311c300000
9affffff3a261c311c300000
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
  unsigned char n:3;
};
-
{e=>0,n=>2,a=>71,m=>2,d=>1,j=>7,l=>0,c=>5,k=>5,h=>3,b=>5,g=>5,f=>0,i=>7}
470000002d01283b2f1002
470000002d01283b2f100200
470000002d01283b2f100200
470000002d01283b2f100200
-
{e=>1,n=>0,a=>26,m=>3,d=>0,j=>5,l=>7,c=>2,k=>0,h=>0,b=>7,g=>1,f=>6,i=>4}
1a00000017080e20051f00
1a00000017080e20051f0000
1a00000017080e20051f0000
1a00000017080e20051f0000
-
{e=>2,n=>4,a=>60,m=>5,d=>5,j=>6,l=>6,c=>6,k=>2,h=>3,b=>0,g=>2,f=>4,i=>3}
3c0000003015141b162e04
3c0000003015141b162e0400
3c0000003015141b162e0400
3c0000003015141b162e0400
-
{e=>7,n=>3,a=>95,m=>4,d=>7,j=>4,l=>5,c=>2,k=>6,h=>4,b=>0,g=>3,f=>0,i=>3}
5f000000103f181c342503
5f000000103f181c34250300
5f000000103f181c34250300
5f000000103f181c34250300
-
{e=>6,n=>2,a=>-72,m=>1,d=>7,j=>3,l=>3,c=>4,k=>4,h=>2,b=>2,g=>7,f=>7,i=>3}
b8ffffff22373f1a230b02
b8ffffff22373f1a230b0200
b8ffffff22373f1a230b0200
b8ffffff22373f1a230b0200
=
struct uch_wrap {
  int a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
  unsigned char n:3;
  short         o;
};
-
{e=>3,n=>5,a=>-18,m=>0,d=>5,j=>5,l=>2,c=>0,k=>7,h=>6,b=>1,g=>3,f=>2,o=>-124,i=>5}
eeffffff011d1a2e3d020584ff
eeffffff011d1a2e3d02050084ff
eeffffff011d1a2e3d02050084ff0000
eeffffff011d1a2e3d02050084ff0000
-
{e=>7,n=>6,a=>-18,m=>7,d=>6,j=>5,l=>7,c=>5,k=>6,h=>4,b=>5,g=>7,f=>5,o=>-74,i=>7}
eeffffff2d3e3d3c353f06b6ff
eeffffff2d3e3d3c353f0600b6ff
eeffffff2d3e3d3c353f0600b6ff0000
eeffffff2d3e3d3c353f0600b6ff0000
-
{e=>1,n=>5,a=>121,m=>1,d=>3,j=>4,l=>5,c=>3,k=>7,h=>1,b=>0,g=>5,f=>1,o=>-94,i=>1}
79000000180b29093c0d05a2ff
79000000180b29093c0d0500a2ff
79000000180b29093c0d0500a2ff0000
79000000180b29093c0d0500a2ff0000
-
{e=>2,n=>1,a=>-41,m=>4,d=>5,j=>7,l=>2,c=>6,k=>0,h=>4,b=>3,g=>7,f=>6,o=>-66,i=>7}
d7ffffff33153e3c072201beff
d7ffffff33153e3c07220100beff
d7ffffff33153e3c07220100beff0000
d7ffffff33153e3c07220100beff0000
-
{e=>7,n=>2,a=>39,m=>7,d=>4,j=>7,l=>6,c=>7,k=>2,h=>0,b=>7,g=>1,f=>2,o=>-125,i=>1}
270000003f3c0a08173e0283ff
270000003f3c0a08173e020083ff
270000003f3c0a08173e020083ff0000
270000003f3c0a08173e020083ff0000
=
struct uch_wrap {
  long a;
  unsigned char b:3;
};
-
{a=>-40,b=>5}
d8ffffff05
d8ffffff0500
d8ffffff05000000
d8ffffff05000000
-
{a=>-42,b=>6}
d6ffffff06
d6ffffff0600
d6ffffff06000000
d6ffffff06000000
-
{a=>-83,b=>0}
adffffff00
adffffff0000
adffffff00000000
adffffff00000000
-
{a=>6,b=>4}
0600000004
060000000400
0600000004000000
0600000004000000
-
{a=>-27,b=>4}
e5ffffff04
e5ffffff0400
e5ffffff04000000
e5ffffff04000000
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
};
-
{c=>4,a=>56,b=>5}
3800000025
380000002500
3800000025000000
3800000025000000
-
{c=>4,a=>-12,b=>5}
f4ffffff25
f4ffffff2500
f4ffffff25000000
f4ffffff25000000
-
{c=>0,a=>-103,b=>3}
99ffffff03
99ffffff0300
99ffffff03000000
99ffffff03000000
-
{c=>3,a=>104,b=>6}
680000001e
680000001e00
680000001e000000
680000001e000000
-
{c=>6,a=>-64,b=>6}
c0ffffff36
c0ffffff3600
c0ffffff36000000
c0ffffff36000000
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
};
-
{c=>6,a=>-23,b=>3,d=>2}
e9ffffff3302
e9ffffff3302
e9ffffff33020000
e9ffffff33020000
-
{c=>7,a=>-55,b=>6,d=>0}
c9ffffff3e00
c9ffffff3e00
c9ffffff3e000000
c9ffffff3e000000
-
{c=>0,a=>84,b=>5,d=>3}
540000000503
540000000503
5400000005030000
5400000005030000
-
{c=>7,a=>-40,b=>0,d=>5}
d8ffffff3805
d8ffffff3805
d8ffffff38050000
d8ffffff38050000
-
{c=>6,a=>-97,b=>1,d=>1}
9fffffff3101
9fffffff3101
9fffffff31010000
9fffffff31010000
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
};
-
{e=>5,c=>5,a=>-118,b=>4,d=>3}
8affffff2c2b
8affffff2c2b
8affffff2c2b0000
8affffff2c2b0000
-
{e=>7,c=>6,a=>-96,b=>3,d=>4}
a0ffffff333c
a0ffffff333c
a0ffffff333c0000
a0ffffff333c0000
-
{e=>0,c=>5,a=>93,b=>2,d=>3}
5d0000002a03
5d0000002a03
5d0000002a030000
5d0000002a030000
-
{e=>4,c=>6,a=>60,b=>0,d=>0}
3c0000003020
3c0000003020
3c00000030200000
3c00000030200000
-
{e=>7,c=>0,a=>-10,b=>2,d=>6}
f6ffffff023e
f6ffffff023e
f6ffffff023e0000
f6ffffff023e0000
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
};
-
{e=>0,c=>2,a=>-92,b=>1,d=>1,f=>0}
a4ffffff110100
a4ffffff11010000
a4ffffff11010000
a4ffffff11010000
-
{e=>3,c=>4,a=>-86,b=>4,d=>0,f=>7}
aaffffff241807
aaffffff24180700
aaffffff24180700
aaffffff24180700
-
{e=>0,c=>5,a=>117,b=>0,d=>1,f=>3}
75000000280103
7500000028010300
7500000028010300
7500000028010300
-
{e=>4,c=>6,a=>103,b=>2,d=>4,f=>0}
67000000322400
6700000032240000
6700000032240000
6700000032240000
-
{e=>2,c=>4,a=>42,b=>3,d=>2,f=>5}
2a000000231205
2a00000023120500
2a00000023120500
2a00000023120500
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
};
-
{e=>2,c=>0,a=>-3,g=>2,b=>5,d=>4,f=>5}
fdffffff051415
fdffffff05141500
fdffffff05141500
fdffffff05141500
-
{e=>5,c=>6,a=>-39,g=>0,b=>0,d=>0,f=>1}
d9ffffff302801
d9ffffff30280100
d9ffffff30280100
d9ffffff30280100
-
{e=>4,c=>0,a=>79,g=>3,b=>3,d=>7,f=>1}
4f000000032719
4f00000003271900
4f00000003271900
4f00000003271900
-
{e=>1,c=>2,a=>-123,g=>2,b=>1,d=>0,f=>4}
85ffffff110814
85ffffff11081400
85ffffff11081400
85ffffff11081400
-
{e=>4,c=>7,a=>100,g=>2,b=>3,d=>3,f=>6}
640000003b2316
640000003b231600
640000003b231600
640000003b231600
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
};
-
{e=>6,a=>-8,d=>6,c=>1,h=>6,b=>3,g=>1,f=>2}
f8ffffff0b360a06
f8ffffff0b360a06
f8ffffff0b360a06
f8ffffff0b360a06
-
{e=>4,a=>-75,d=>7,c=>3,h=>7,b=>3,g=>5,f=>3}
b5ffffff1b272b07
b5ffffff1b272b07
b5ffffff1b272b07
b5ffffff1b272b07
-
{e=>7,a=>-105,d=>6,c=>4,h=>5,b=>3,g=>2,f=>0}
97ffffff233e1005
97ffffff233e1005
97ffffff233e1005
97ffffff233e1005
-
{e=>4,a=>115,d=>1,c=>7,h=>4,b=>6,g=>0,f=>0}
730000003e210004
730000003e210004
730000003e210004
730000003e210004
-
{e=>4,a=>-9,d=>7,c=>1,h=>7,b=>7,g=>5,f=>3}
f7ffffff0f272b07
f7ffffff0f272b07
f7ffffff0f272b07
f7ffffff0f272b07
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
};
-
{e=>4,a=>-19,d=>4,c=>4,h=>6,b=>5,g=>6,f=>5,i=>7}
edffffff2524353e
edffffff2524353e
edffffff2524353e
edffffff2524353e
-
{e=>6,a=>-94,d=>4,c=>3,h=>2,b=>4,g=>7,f=>3,i=>1}
a2ffffff1c343b0a
a2ffffff1c343b0a
a2ffffff1c343b0a
a2ffffff1c343b0a
-
{e=>5,a=>117,d=>2,c=>3,h=>2,b=>6,g=>0,f=>7,i=>3}
750000001e2a071a
750000001e2a071a
750000001e2a071a
750000001e2a071a
-
{e=>7,a=>-27,d=>5,c=>4,h=>4,b=>1,g=>0,f=>5,i=>6}
e5ffffff213d0534
e5ffffff213d0534
e5ffffff213d0534
e5ffffff213d0534
-
{e=>4,a=>-18,d=>4,c=>3,h=>2,b=>0,g=>4,f=>1,i=>0}
eeffffff18242102
eeffffff18242102
eeffffff18242102
eeffffff18242102
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
};
-
{e=>6,a=>-43,d=>7,j=>2,c=>3,h=>5,b=>4,g=>2,f=>2,i=>3}
d5ffffff1c37121d02
d5ffffff1c37121d0200
d5ffffff1c37121d02000000
d5ffffff1c37121d02000000
-
{e=>1,a=>41,d=>0,j=>6,c=>4,h=>7,b=>5,g=>5,f=>6,i=>0}
2900000025082e0706
2900000025082e070600
2900000025082e0706000000
2900000025082e0706000000
-
{e=>0,a=>-53,d=>2,j=>3,c=>6,h=>4,b=>2,g=>2,f=>1,i=>3}
cbffffff3202111c03
cbffffff3202111c0300
cbffffff3202111c03000000
cbffffff3202111c03000000
-
{e=>7,a=>6,d=>6,j=>3,c=>7,h=>3,b=>3,g=>4,f=>6,i=>0}
060000003b3e260303
060000003b3e26030300
060000003b3e260303000000
060000003b3e260303000000
-
{e=>7,a=>8,d=>4,j=>4,c=>4,h=>1,b=>2,g=>7,f=>1,i=>5}
08000000223c392904
08000000223c39290400
08000000223c392904000000
08000000223c392904000000
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
};
-
{e=>2,a=>-120,d=>3,j=>3,c=>1,k=>7,h=>5,b=>6,g=>1,f=>2,i=>6}
88ffffff0e130a353b
88ffffff0e130a353b00
88ffffff0e130a353b000000
88ffffff0e130a353b000000
-
{e=>0,a=>116,d=>7,j=>1,c=>4,k=>0,h=>3,b=>1,g=>4,f=>3,i=>1}
740000002107230b01
740000002107230b0100
740000002107230b01000000
740000002107230b01000000
-
{e=>4,a=>108,d=>2,j=>7,c=>4,k=>6,h=>2,b=>1,g=>0,f=>5,i=>0}
6c0000002122050237
6c000000212205023700
6c0000002122050237000000
6c0000002122050237000000
-
{e=>3,a=>-126,d=>7,j=>0,c=>5,k=>6,h=>1,b=>0,g=>1,f=>7,i=>3}
82ffffff281f0f1930
82ffffff281f0f193000
82ffffff281f0f1930000000
82ffffff281f0f1930000000
-
{e=>2,a=>-78,d=>3,j=>3,c=>7,k=>4,h=>1,b=>7,g=>2,f=>1,i=>2}
b2ffffff3f13111123
b2ffffff3f1311112300
b2ffffff3f13111123000000
b2ffffff3f13111123000000
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
};
-
{e=>7,a=>14,d=>4,j=>1,l=>0,c=>6,k=>4,h=>3,b=>1,g=>2,f=>7,i=>1}
0e000000313c170b2100
0e000000313c170b2100
0e000000313c170b21000000
0e000000313c170b21000000
-
{e=>0,a=>121,d=>5,j=>2,l=>2,c=>3,k=>1,h=>2,b=>0,g=>4,f=>2,i=>0}
79000000180522020a02
79000000180522020a02
79000000180522020a020000
79000000180522020a020000
-
{e=>5,a=>-2,d=>5,j=>7,l=>4,c=>3,k=>0,h=>2,b=>2,g=>6,f=>3,i=>0}
feffffff1a2d33020704
feffffff1a2d33020704
feffffff1a2d330207040000
feffffff1a2d330207040000
-
{e=>4,a=>8,d=>2,j=>4,l=>3,c=>7,k=>2,h=>6,b=>4,g=>0,f=>5,i=>2}
080000003c2205161403
080000003c2205161403
080000003c22051614030000
080000003c22051614030000
-
{e=>1,a=>-123,d=>4,j=>6,l=>2,c=>4,k=>3,h=>5,b=>7,g=>1,f=>5,i=>6}
85ffffff270c0d351e02
85ffffff270c0d351e02
85ffffff270c0d351e020000
85ffffff270c0d351e020000
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
};
-
{e=>5,a=>-111,m=>3,d=>7,j=>6,l=>5,c=>6,k=>6,h=>6,b=>0,g=>4,f=>1,i=>2}
91ffffff302f2116361d
91ffffff302f2116361d
91ffffff302f2116361d0000
91ffffff302f2116361d0000
-
{e=>4,a=>-44,m=>0,d=>4,j=>5,l=>1,c=>5,k=>0,h=>2,b=>2,g=>4,f=>7,i=>6}
d4ffffff2a2427320501
d4ffffff2a2427320501
d4ffffff2a24273205010000
d4ffffff2a24273205010000
-
{e=>7,a=>-24,m=>0,d=>0,j=>3,l=>1,c=>5,k=>5,h=>1,b=>2,g=>3,f=>5,i=>4}
e8ffffff2a381d212b01
e8ffffff2a381d212b01
e8ffffff2a381d212b010000
e8ffffff2a381d212b010000
-
{e=>4,a=>96,m=>2,d=>0,j=>1,l=>2,c=>2,k=>4,h=>4,b=>4,g=>3,f=>7,i=>2}
6000000014201f142112
6000000014201f142112
6000000014201f1421120000
6000000014201f1421120000
-
{e=>2,a=>-3,m=>4,d=>0,j=>4,l=>5,c=>7,k=>3,h=>7,b=>5,g=>0,f=>1,i=>6}
fdffffff3d1001371c25
fdffffff3d1001371c25
fdffffff3d1001371c250000
fdffffff3d1001371c250000
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
  unsigned char n:3;
};
-
{e=>5,n=>3,a=>-107,m=>1,d=>3,j=>7,l=>5,c=>0,k=>2,h=>0,b=>6,g=>2,f=>2,i=>7}
95ffffff062b1238170d03
95ffffff062b1238170d0300
95ffffff062b1238170d0300
95ffffff062b1238170d0300
-
{e=>7,n=>1,a=>9,m=>6,d=>1,j=>2,l=>4,c=>7,k=>6,h=>7,b=>5,g=>4,f=>4,i=>6}
090000003d392437323401
090000003d39243732340100
090000003d39243732340100
090000003d39243732340100
-
{e=>2,n=>1,a=>-50,m=>7,d=>3,j=>1,l=>6,c=>0,k=>2,h=>7,b=>2,g=>1,f=>5,i=>6}
ceffffff02130d37113e01
ceffffff02130d37113e0100
ceffffff02130d37113e0100
ceffffff02130d37113e0100
-
{e=>7,n=>4,a=>123,m=>1,d=>1,j=>2,l=>4,c=>4,k=>7,h=>0,b=>4,g=>6,f=>0,i=>6}
7b000000243930303a0c04
7b000000243930303a0c0400
7b000000243930303a0c0400
7b000000243930303a0c0400
-
{e=>2,n=>4,a=>-2,m=>5,d=>3,j=>4,l=>4,c=>3,k=>2,h=>7,b=>4,g=>7,f=>3,i=>4}
feffffff1c133b27142c04
feffffff1c133b27142c0400
feffffff1c133b27142c0400
feffffff1c133b27142c0400
=
struct uch_wrap {
  long a;
  unsigned char b:3;
  unsigned char c:3;
  unsigned char d:3;
  unsigned char e:3;
  unsigned char f:3;
  unsigned char g:3;
  unsigned char h:3;
  unsigned char i:3;
  unsigned char j:3;
  unsigned char k:3;
  unsigned char l:3;
  unsigned char m:3;
  unsigned char n:3;
  short         o;
};
-
{e=>2,n=>2,a=>66,m=>1,d=>2,j=>2,l=>3,c=>0,k=>3,h=>7,b=>2,g=>5,f=>1,o=>-57,i=>2}
42000000021229171a0b02c7ff
42000000021229171a0b0200c7ff
42000000021229171a0b0200c7ff0000
42000000021229171a0b0200c7ff0000
-
{e=>5,n=>3,a=>-74,m=>0,d=>7,j=>6,l=>1,c=>4,k=>7,h=>6,b=>7,g=>3,f=>5,o=>39,i=>2}
b6ffffff272f1d163e01032700
b6ffffff272f1d163e0103002700
b6ffffff272f1d163e01030027000000
b6ffffff272f1d163e01030027000000
-
{e=>0,n=>4,a=>-119,m=>6,d=>5,j=>3,l=>4,c=>5,k=>2,h=>2,b=>3,g=>4,f=>1,o=>-9,i=>4}
89ffffff2b052122133404f7ff
89ffffff2b05212213340400f7ff
89ffffff2b05212213340400f7ff0000
89ffffff2b05212213340400f7ff0000
-
{e=>3,n=>6,a=>-85,m=>7,d=>1,j=>6,l=>3,c=>7,k=>4,h=>4,b=>2,g=>5,f=>0,o=>120,i=>0}
abffffff3a192804263b067800
abffffff3a192804263b06007800
abffffff3a192804263b060078000000
abffffff3a192804263b060078000000
-
{e=>1,n=>6,a=>5,m=>5,d=>5,j=>2,l=>1,c=>4,k=>2,h=>0,b=>7,g=>0,f=>2,o=>-21,i=>6}
05000000270d0230122906ebff
05000000270d023012290600ebff
05000000270d023012290600ebff0000
05000000270d023012290600ebff0000
=
struct int_wrap {
  int a:3;
};
-
{a=>3}
03000000
03000000
03000000
03000000
-
{a=>-2}
06000000
06000000
06000000
06000000
-
{a=>-2}
06000000
06000000
06000000
06000000
-
{a=>2}
02000000
02000000
02000000
02000000
-
{a=>1}
01000000
01000000
01000000
01000000
=
struct int_wrap {
  int a:3;
  int b:3;
};
-
{a=>-4,b=>-1}
3c000000
3c000000
3c000000
3c000000
-
{a=>-1,b=>-1}
3f000000
3f000000
3f000000
3f000000
-
{a=>2,b=>3}
1a000000
1a000000
1a000000
1a000000
-
{a=>-2,b=>-4}
26000000
26000000
26000000
26000000
-
{a=>-2,b=>1}
0e000000
0e000000
0e000000
0e000000
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
};
-
{c=>-2,a=>-3,b=>2}
95010000
95010000
95010000
95010000
-
{c=>-3,a=>-4,b=>3}
5c010000
5c010000
5c010000
5c010000
-
{c=>2,a=>1,b=>3}
99000000
99000000
99000000
99000000
-
{c=>-4,a=>-4,b=>-1}
3c010000
3c010000
3c010000
3c010000
-
{c=>-1,a=>-3,b=>-4}
e5010000
e5010000
e5010000
e5010000
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
  int d:3;
};
-
{c=>-1,a=>0,b=>-1,d=>0}
f8010000
f8010000
f8010000
f8010000
-
{c=>-2,a=>-2,b=>1,d=>2}
8e050000
8e050000
8e050000
8e050000
-
{c=>-2,a=>0,b=>-4,d=>2}
a0050000
a0050000
a0050000
a0050000
-
{c=>-3,a=>1,b=>-4,d=>3}
61070000
61070000
61070000
61070000
-
{c=>1,a=>-2,b=>2,d=>0}
56000000
56000000
56000000
56000000
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
};
-
{e=>-3,c=>-3,a=>1,b=>-4,d=>-4}
61590000
61590000
61590000
61590000
-
{e=>-3,c=>2,a=>0,b=>1,d=>0}
88500000
88500000
88500000
88500000
-
{e=>-3,c=>3,a=>2,b=>-1,d=>0}
fa500000
fa500000
fa500000
fa500000
-
{e=>1,c=>-2,a=>-2,b=>-2,d=>3}
b6170000
b6170000
b6170000
b6170000
-
{e=>3,c=>1,a=>-1,b=>2,d=>-2}
573c0000
573c0000
573c0000
573c0000
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
};
-
{e=>-1,c=>-2,a=>-2,b=>2,d=>1,f=>3}
96f30100
96f30100
96f30100
96f30100
-
{e=>-3,c=>-4,a=>3,b=>2,d=>1,f=>-3}
13d30200
13d30200
13d30200
13d30200
-
{e=>-4,c=>0,a=>-1,b=>-4,d=>-1,f=>-2}
274e0300
274e0300
274e0300
274e0300
-
{e=>-1,c=>-4,a=>-1,b=>1,d=>0,f=>-3}
0ff10200
0ff10200
0ff10200
0ff10200
-
{e=>-4,c=>-2,a=>1,b=>3,d=>2,f=>-3}
99c50200
99c50200
99c50200
99c50200
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
};
-
{e=>-4,c=>1,a=>-4,g=>0,b=>-2,d=>0,f=>-3}
74c00200
74c00200
74c00200
74c00200
-
{e=>-2,c=>0,a=>-4,g=>3,b=>-4,d=>0,f=>-3}
24e00e00
24e00e00
24e00e00
24e00e00
-
{e=>0,c=>1,a=>3,g=>2,b=>-3,d=>0,f=>0}
6b000800
6b000800
6b000800
6b000800
-
{e=>-4,c=>-2,a=>-1,g=>3,b=>1,d=>1,f=>0}
8f430c00
8f430c00
8f430c00
8f430c00
-
{e=>2,c=>-2,a=>-3,g=>0,b=>-3,d=>1,f=>-2}
ad230300
ad230300
ad230300
ad230300
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
};
-
{e=>-2,a=>3,d=>-1,c=>-4,h=>-2,b=>-1,g=>0,f=>-4}
3b6fc200
3b6fc200
3b6fc200
3b6fc200
-
{e=>3,a=>-4,d=>1,c=>1,h=>0,b=>2,g=>-3,f=>2}
54321500
54321500
54321500
54321500
-
{e=>2,a=>-2,d=>2,c=>3,h=>-3,b=>3,g=>3,f=>-4}
de24ae00
de24ae00
de24ae00
de24ae00
-
{e=>2,a=>-1,d=>-1,c=>1,h=>-3,b=>-4,g=>2,f=>-4}
672eaa00
672eaa00
672eaa00
672eaa00
-
{e=>0,a=>0,d=>0,c=>-4,h=>2,b=>3,g=>3,f=>0}
18014c00
18014c00
18014c00
18014c00
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
};
-
{e=>-4,a=>2,d=>-2,c=>-2,h=>3,b=>-3,g=>-2,f=>-3,i=>0}
aacd7a00
aacd7a00
aacd7a00
aacd7a00
-
{e=>-4,a=>-1,d=>2,c=>3,h=>1,b=>-1,g=>0,f=>-1,i=>0}
ffc42300
ffc42300
ffc42300
ffc42300
-
{e=>2,a=>0,d=>-1,c=>2,h=>2,b=>1,g=>3,f=>-1,i=>0}
88ae4f00
88ae4f00
88ae4f00
88ae4f00
-
{e=>-3,a=>-4,d=>2,c=>-1,h=>-3,b=>2,g=>1,f=>-3,i=>-3}
d4d5a605
d4d5a605
d4d5a605
d4d5a605
-
{e=>1,a=>-1,d=>-1,c=>-1,h=>0,b=>-1,g=>-3,f=>-3,i=>2}
ff9f1602
ff9f1602
ff9f1602
ff9f1602
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
};
-
{e=>-3,a=>0,d=>-3,j=>-4,c=>3,h=>-1,b=>-3,g=>1,f=>1,i=>-4}
e8dae424
e8dae424
e8dae424
e8dae424
-
{e=>1,a=>3,d=>-3,j=>2,c=>-3,h=>3,b=>-1,g=>1,f=>-1,i=>-4}
7b9b6714
7b9b6714
7b9b6714
7b9b6714
-
{e=>-3,a=>-3,d=>1,j=>-4,c=>-4,h=>3,b=>-1,g=>-1,f=>-2,i=>0}
3d537f20
3d537f20
3d537f20
3d537f20
-
{e=>2,a=>0,d=>-4,j=>1,c=>3,h=>1,b=>-2,g=>1,f=>-2,i=>2}
f028270a
f028270a
f028270a
f028270a
-
{e=>-2,a=>1,d=>-1,j=>3,c=>-4,h=>2,b=>1,g=>0,f=>2,i=>3}
096f411b
096f411b
096f411b
096f411b
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
};
-
{e=>-4,a=>2,d=>-4,j=>2,c=>-3,k=>-1,h=>-1,b=>2,g=>-3,f=>-3,i=>-4}
52c9f61407000000
52c9f61407000000
52c9f61407000000
52c9f61407000000
-
{e=>3,a=>2,d=>-3,j=>-3,c=>-1,k=>-3,h=>-3,b=>0,g=>-4,f=>-3,i=>0}
c2bbb22805000000
c2bbb22805000000
c2bbb22805000000
c2bbb22805000000
-
{e=>-2,a=>1,d=>3,j=>-4,c=>-1,k=>3,h=>3,b=>1,g=>1,f=>2,i=>-3}
c967652503000000
c967652503000000
c967652503000000
c967652503000000
-
{e=>2,a=>3,d=>-4,j=>-4,c=>0,k=>-4,h=>-4,b=>3,g=>3,f=>-3,i=>-2}
1ba88e2604000000
1ba88e2604000000
1ba88e2604000000
1ba88e2604000000
-
{e=>-1,a=>0,d=>-1,j=>-3,c=>-1,k=>2,h=>2,b=>-4,g=>-4,f=>-4,i=>-1}
e07f522f02000000
e07f522f02000000
e07f522f02000000
e07f522f02000000
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
};
-
{e=>-3,a=>3,d=>-2,j=>-3,l=>0,c=>-3,k=>3,h=>-3,b=>-1,g=>1,f=>-3,i=>1}
7bdda62903000000
7bdda62903000000
7bdda62903000000
7bdda62903000000
-
{e=>-2,a=>-1,d=>1,j=>3,l=>-3,c=>-2,k=>-1,h=>1,b=>3,g=>2,f=>-4,i=>2}
9f632a1a2f000000
9f632a1a2f000000
9f632a1a2f000000
9f632a1a2f000000
-
{e=>-3,a=>3,d=>3,j=>3,l=>3,c=>2,k=>2,h=>-2,b=>0,g=>1,f=>-3,i=>-1}
83d6c61f1a000000
83d6c61f1a000000
83d6c61f1a000000
83d6c61f1a000000
-
{e=>1,a=>2,d=>-3,j=>-4,l=>-4,c=>-4,k=>-3,h=>0,b=>-4,g=>1,f=>2,i=>3}
221b052325000000
221b052325000000
221b052325000000
221b052325000000
-
{e=>0,a=>-4,d=>3,j=>-1,l=>0,c=>-1,k=>-3,h=>-2,b=>-3,g=>0,f=>-3,i=>-1}
ec87c23f05000000
ec87c23f05000000
ec87c23f05000000
ec87c23f05000000
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
};
-
{e=>2,a=>3,m=>-2,d=>0,j=>-1,l=>0,c=>-3,k=>-4,h=>0,b=>1,g=>1,f=>0,i=>-1}
4b21043f84010000
4b21043f84010000
4b21043f84010000
4b21043f84010000
-
{e=>1,a=>-1,m=>0,d=>3,j=>2,l=>-2,c=>1,k=>1,h=>-3,b=>0,g=>3,f=>0,i=>-1}
4716ac1731000000
4716ac1731000000
4716ac1731000000
4716ac1731000000
-
{e=>3,a=>0,m=>-3,d=>2,j=>-4,l=>-3,c=>-4,k=>-1,h=>2,b=>2,g=>2,f=>-3,i=>-2}
10b54a266f010000
10b54a266f010000
10b54a266f010000
10b54a266f010000
-
{e=>3,a=>1,m=>0,d=>3,j=>0,l=>3,c=>-4,k=>-1,h=>-3,b=>-3,g=>-3,f=>1,i=>1}
29b7b4011f000000
29b7b4011f000000
29b7b4011f000000
29b7b4011f000000
-
{e=>-4,a=>-3,m=>1,d=>1,j=>-4,l=>0,c=>0,k=>0,h=>-1,b=>3,g=>1,f=>2,i=>3}
1d42e52340000000
1d42e52340000000
1d42e52340000000
1d42e52340000000
=
struct int_wrap {
  int a:3;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
  int n;
};
-
{e=>-4,n=>-50,a=>0,m=>-1,d=>-4,j=>-4,l=>3,c=>-4,k=>2,h=>2,b=>0,g=>1,f=>-1,i=>-3}
00c94725da010000ceffffff
00c94725da010000ceffffff
00c94725da010000ceffffff
00c94725da010000ceffffff
-
{e=>2,n=>59,a=>1,m=>2,d=>-1,j=>2,l=>0,c=>-3,k=>0,h=>-2,b=>-3,g=>-3,f=>0,i=>0}
692fd410800000003b000000
692fd410800000003b000000
692fd410800000003b000000
692fd410800000003b000000
-
{e=>3,n=>94,a=>2,m=>2,d=>-4,j=>-2,l=>-2,c=>-3,k=>-1,h=>-3,b=>-1,g=>-2,f=>2,i=>2}
7a39b932b70000005e000000
7a39b932b70000005e000000
7a39b932b70000005e000000
7a39b932b70000005e000000
-
{e=>0,n=>126,a=>3,m=>1,d=>0,j=>0,l=>2,c=>-2,k=>-1,h=>-4,b=>2,g=>-3,f=>0,i=>0}
93019400570000007e000000
93019400570000007e000000
93019400570000007e000000
93019400570000007e000000
-
{e=>3,n=>50,a=>-3,m=>2,d=>2,j=>-2,l=>-3,c=>-2,k=>3,h=>-1,b=>-2,g=>2,f=>-3,i=>-1}
b5b5ea37ab00000032000000
b5b5ea37ab00000032000000
b5b5ea37ab00000032000000
b5b5ea37ab00000032000000
=
struct int_wrap {
  char a;
  int b:3;
};
-
{a=>-96,b=>2}
a002000000
a00002000000
a000000002000000
a000000002000000
-
{a=>-46,b=>2}
d202000000
d20002000000
d200000002000000
d200000002000000
-
{a=>-68,b=>3}
bc03000000
bc0003000000
bc00000003000000
bc00000003000000
-
{a=>0,b=>3}
0003000000
000003000000
0000000003000000
0000000003000000
-
{a=>-26,b=>-2}
e606000000
e60006000000
e600000006000000
e600000006000000
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
};
-
{c=>1,a=>123,b=>0}
7b08000000
7b0008000000
7b00000008000000
7b00000008000000
-
{c=>-1,a=>-98,b=>2}
9e3a000000
9e003a000000
9e0000003a000000
9e0000003a000000
-
{c=>-3,a=>75,b=>-4}
4b2c000000
4b002c000000
4b0000002c000000
4b0000002c000000
-
{c=>-4,a=>-4,b=>-4}
fc24000000
fc0024000000
fc00000024000000
fc00000024000000
-
{c=>-1,a=>17,b=>1}
1139000000
110039000000
1100000039000000
1100000039000000
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
};
-
{c=>-4,a=>17,b=>-2,d=>1}
1166000000
110066000000
1100000066000000
1100000066000000
-
{c=>0,a=>75,b=>0,d=>3}
4bc0000000
4b00c0000000
4b000000c0000000
4b000000c0000000
-
{c=>3,a=>-89,b=>1,d=>1}
a759000000
a70059000000
a700000059000000
a700000059000000
-
{c=>2,a=>86,b=>2,d=>3}
56d2000000
5600d2000000
56000000d2000000
56000000d2000000
-
{c=>-4,a=>53,b=>-1,d=>0}
3527000000
350027000000
3500000027000000
3500000027000000
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
};
-
{e=>-4,c=>-3,a=>-104,b=>-2,d=>0}
982e080000
98002e080000
980000002e080000
980000002e080000
-
{e=>0,c=>2,a=>8,b=>2,d=>-3}
0852010000
080052010000
0800000052010000
0800000052010000
-
{e=>0,c=>-2,a=>-41,b=>-2,d=>0}
d736000000
d70036000000
d700000036000000
d700000036000000
-
{e=>-4,c=>-4,a=>56,b=>2,d=>-4}
3822090000
380022090000
3800000022090000
3800000022090000
-
{e=>-3,c=>3,a=>-43,b=>-2,d=>-3}
d55e0b0000
d5005e0b0000
d50000005e0b0000
d50000005e0b0000
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
};
-
{e=>-4,c=>1,a=>119,b=>1,d=>1,f=>1}
7749180000
770049180000
7700000049180000
7700000049180000
-
{e=>-1,c=>-3,a=>-91,b=>-2,d=>2,f=>-4}
a5ae4e0000
a500ae4e0000
a5000000ae4e0000
a5000000ae4e0000
-
{e=>0,c=>-4,a=>-43,b=>2,d=>0,f=>-1}
d522700000
d50022700000
d500000022700000
d500000022700000
-
{e=>1,c=>-3,a=>121,b=>2,d=>1,f=>-3}
796a520000
79006a520000
790000006a520000
790000006a520000
-
{e=>1,c=>3,a=>12,b=>0,d=>1,f=>-2}
0c58620000
0c0058620000
0c00000058620000
0c00000058620000
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
};
-
{e=>1,c=>3,a=>92,g=>2,b=>0,d=>-4,f=>-1}
5c18730100
5c0018730100
5c00000018730100
5c00000018730100
-
{e=>-3,c=>3,a=>70,g=>-1,b=>1,d=>2,f=>1}
46999a0300
4600999a0300
46000000999a0300
46000000999a0300
-
{e=>0,c=>2,a=>61,g=>-4,b=>-3,d=>-3,f=>0}
3d55010200
3d0055010200
3d00000055010200
3d00000055010200
-
{e=>1,c=>1,a=>-72,g=>-3,b=>2,d=>0,f=>0}
b80a820200
b8000a820200
b80000000a820200
b80000000a820200
-
{e=>3,c=>2,a=>36,g=>-3,b=>-1,d=>1,f=>-1}
2457f60200
240057f60200
2400000057f60200
2400000057f60200
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
};
-
{e=>1,a=>2,d=>2,c=>-4,h=>1,b=>1,g=>3,f=>3}
02a1b20500
0200a1b20500
02000000a1b20500
02000000a1b20500
-
{e=>-4,a=>-16,d=>-2,c=>2,h=>-3,b=>0,g=>-4,f=>-3}
f090591600
f00090591600
f000000090591600
f000000090591600
-
{e=>-3,a=>86,d=>2,c=>3,h=>-3,b=>0,g=>1,f=>-3}
5698da1400
560098da1400
5600000098da1400
5600000098da1400
-
{e=>-2,a=>-5,d=>-2,c=>1,h=>2,b=>-1,g=>-4,f=>2}
fb8f2d0a00
fb008f2d0a00
fb0000008f2d0a00
fb0000008f2d0a00
-
{e=>3,a=>-13,d=>-3,c=>-2,h=>1,b=>-3,g=>2,f=>-2}
f375670500
f30075670500
f300000075670500
f300000075670500
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
};
-
{e=>0,a=>87,d=>-1,c=>-2,h=>-2,b=>-2,g=>1,f=>-3,i=>-3}
57f6d1b800
5700f6d1b800
57000000f6d1b800
57000000f6d1b800
-
{e=>0,a=>28,d=>-3,c=>-3,h=>1,b=>0,g=>-1,f=>2,i=>1}
1c68a12700
1c0068a12700
1c00000068a12700
1c00000068a12700
-
{e=>3,a=>63,d=>3,c=>2,h=>-3,b=>-4,g=>-2,f=>-2,i=>2}
3fd4665700
3f00d4665700
3f000000d4665700
3f000000d4665700
-
{e=>-4,a=>70,d=>3,c=>-4,h=>2,b=>-1,g=>-2,f=>3,i=>-3}
46e738ab00
4600e738ab00
46000000e738ab00
46000000e738ab00
-
{e=>-1,a=>16,d=>-4,c=>0,h=>-1,b=>-2,g=>-2,f=>2,i=>0}
10062f1f00
1000062f1f00
10000000062f1f00
10000000062f1f00
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
};
-
{e=>3,a=>-82,d=>-3,j=>-4,c=>-2,h=>0,b=>-3,g=>2,f=>3,i=>0}
ae75370104
ae0075370104
ae00000075370104
ae00000075370104
-
{e=>-2,a=>-73,d=>0,j=>-3,c=>-2,h=>2,b=>-4,g=>0,f=>0,i=>0}
b7340c0805
b700340c0805
b7000000340c0805
b7000000340c0805
-
{e=>2,a=>-108,d=>3,j=>2,c=>2,h=>3,b=>1,g=>-1,f=>-2,i=>3}
94d1e46f02
9400d1e46f02
94000000d1e46f02
94000000d1e46f02
-
{e=>-1,a=>-101,d=>1,j=>2,c=>-4,h=>0,b=>2,g=>-1,f=>-3,i=>2}
9b62de4302
9b0062de4302
9b00000062de4302
9b00000062de4302
-
{e=>2,a=>67,d=>-1,j=>-1,c=>-4,h=>-4,b=>1,g=>-4,f=>-1,i=>-3}
43e175b207
4300e175b207
43000000e175b207
43000000e175b207
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
};
-
{e=>-3,a=>-38,d=>-4,j=>0,c=>1,k=>3,h=>-1,b=>3,g=>-2,f=>2,i=>0}
da0b2b1f18
da000b2b1f18
da0000000b2b1f18
da0000000b2b1f18
-
{e=>2,a=>-104,d=>-4,j=>-2,c=>2,k=>1,h=>0,b=>3,g=>1,f=>1,i=>-2}
981395c00e
98001395c00e
980000001395c00e
980000001395c00e
-
{e=>-1,a=>-37,d=>-1,j=>-3,c=>-4,k=>-4,h=>-1,b=>1,g=>-3,f=>-4,i=>0}
dbe1cf1e25
db00e1cf1e25
db000000e1cf1e25
db000000e1cf1e25
-
{e=>1,a=>93,d=>3,j=>0,c=>0,k=>0,h=>-2,b=>1,g=>3,f=>2,i=>1}
5dc1a23900
5d00c1a23900
5d000000c1a23900
5d000000c1a23900
-
{e=>3,a=>41,d=>2,j=>-2,c=>3,k=>-1,h=>-3,b=>0,g=>-1,f=>0,i=>3}
299886773e
29009886773e
290000009886773e
290000009886773e
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
};
-
{e=>-1,a=>104,d=>3,j=>-3,l=>1,c=>-3,k=>3,h=>-2,b=>3,g=>-4,f=>-2,i=>-1}
68eb6efa1d01000000
6800eb6efa1d01000000
68000000eb6efa1d01000000
68000000eb6efa1d01000000
-
{e=>-1,a=>-32,d=>2,j=>-3,l=>3,c=>0,k=>0,h=>-2,b=>-2,g=>1,f=>0,i=>0}
e0868e180503000000
e000868e180503000000
e0000000868e180503000000
e0000000868e180503000000
-
{e=>0,a=>-7,d=>2,j=>3,l=>3,c=>2,k=>1,h=>-4,b=>1,g=>-3,f=>-3,i=>-2}
f991d0d20b03000000
f90091d0d20b03000000
f900000091d0d20b03000000
f900000091d0d20b03000000
-
{e=>-1,a=>78,d=>0,j=>1,l=>-2,c=>-2,k=>3,h=>1,b=>-2,g=>1,f=>1,i=>0}
4e369e041906000000
4e00369e041906000000
4e000000369e041906000000
4e000000369e041906000000
-
{e=>2,a=>-39,d=>-4,j=>-4,l=>2,c=>3,k=>-1,h=>1,b=>2,g=>-3,f=>-2,i=>0}
d91ae5063c02000000
d9001ae5063c02000000
d90000001ae5063c02000000
d90000001ae5063c02000000
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
};
-
{e=>-4,a=>4,m=>-2,d=>-4,j=>2,l=>-2,c=>0,k=>1,h=>1,b=>2,g=>-3,f=>2,i=>1}
0402a9260a36000000
040002a9260a36000000
0400000002a9260a36000000
0400000002a9260a36000000
-
{e=>-1,a=>-76,m=>-1,d=>1,j=>0,l=>-1,c=>-4,k=>3,h=>-1,b=>-1,g=>2,f=>0,i=>-3}
b4670ebd183f000000
b400670ebd183f000000
b4000000670ebd183f000000
b4000000670ebd183f000000
-
{e=>3,a=>64,m=>-2,d=>-2,j=>-1,l=>1,c=>2,k=>2,h=>2,b=>1,g=>-2,f=>3,i=>-2}
409137cb1731000000
40009137cb1731000000
400000009137cb1731000000
400000009137cb1731000000
-
{e=>0,a=>13,m=>1,d=>-3,j=>0,l=>-3,c=>-4,k=>0,h=>-3,b=>0,g=>2,f=>3,i=>-1}
0d6031f5000d000000
0d006031f5000d000000
0d0000006031f5000d000000
0d0000006031f5000d000000
-
{e=>-3,a=>-31,m=>3,d=>3,j=>-3,l=>-3,c=>-3,k=>1,h=>-3,b=>-1,g=>3,f=>0,i=>-2}
e1ef8ad50d1d000000
e100ef8ad50d1d000000
e1000000ef8ad50d1d000000
e1000000ef8ad50d1d000000
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
  int n:3;
};
-
{e=>3,n=>0,a=>68,m=>2,d=>2,j=>-1,l=>0,c=>-1,k=>0,h=>-4,b=>-3,g=>2,f=>-2,i=>2}
44bd66510710000000
4400bd66510710000000
44000000bd66510710000000
44000000bd66510710000000
-
{e=>-3,n=>-2,a=>83,m=>3,d=>-3,j=>0,l=>-4,c=>-3,k=>-3,h=>0,b=>2,g=>-4,f=>-1,i=>2}
536a7b42289c010000
53006a7b42289c010000
530000006a7b42289c010000
530000006a7b42289c010000
-
{e=>-4,n=>-1,a=>-51,m=>3,d=>-2,j=>-3,l=>-4,c=>3,k=>0,h=>2,b=>0,g=>0,f=>-3,i=>-3}
cd9859a805dc010000
cd009859a805dc010000
cd0000009859a805dc010000
cd0000009859a805dc010000
-
{e=>-4,n=>-2,a=>53,m=>2,d=>0,j=>-4,l=>-1,c=>2,k=>-4,h=>-2,b=>0,g=>-1,f=>2,i=>1}
3510a83b2497010000
350010a83b2497010000
3500000010a83b2497010000
3500000010a83b2497010000
-
{e=>-4,n=>-4,a=>-114,m=>-1,d=>-1,j=>0,l=>3,c=>-1,k=>3,h=>1,b=>0,g=>1,f=>-4,i=>0}
8ef8c904183b010000
8e00f8c904183b010000
8e000000f8c904183b010000
8e000000f8c904183b010000
=
struct int_wrap {
  char a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
  int n:3;
  int o;
};
-
{e=>2,n=>2,a=>81,m=>3,d=>2,j=>0,l=>1,c=>-2,k=>-1,h=>3,b=>-2,g=>-1,f=>3,o=>64,i=>2}
51b6b44f389900000040000000
5100b6b44f389900000040000000
51000000b6b44f389900000040000000
51000000b6b44f389900000040000000
-
{e=>-3,n=>0,a=>114,m=>0,d=>1,j=>-1,l=>-4,c=>1,k=>0,h=>-3,b=>3,g=>-4,f=>-3,o=>31,i=>2}
724b5a5607040000001f000000
72004b5a5607040000001f000000
720000004b5a5607040000001f000000
720000004b5a5607040000001f000000
-
{e=>-2,n=>2,a=>-90,m=>-1,d=>-2,j=>1,l=>2,c=>-1,k=>-2,h=>-2,b=>-3,g=>2,f=>3,o=>11,i=>-2}
a6bd3dd931ba0000000b000000
a600bd3dd931ba0000000b000000
a6000000bd3dd931ba0000000b000000
a6000000bd3dd931ba0000000b000000
-
{e=>-4,n=>1,a=>-83,m=>2,d=>0,j=>-3,l=>3,c=>-3,k=>0,h=>0,b=>0,g=>-3,f=>-3,o=>-60,i=>-1}
ad28d8e20553000000c4ffffff
ad0028d8e20553000000c4ffffff
ad00000028d8e20553000000c4ffffff
ad00000028d8e20553000000c4ffffff
-
{e=>3,n=>0,a=>-38,m=>-4,d=>2,j=>-3,l=>-4,c=>-2,k=>-4,h=>-3,b=>0,g=>-4,f=>-4,o=>-32,i=>-4}
dab046962524000000e0ffffff
da00b046962524000000e0ffffff
da000000b046962524000000e0ffffff
da000000b046962524000000e0ffffff
=
struct int_wrap {
  short a;
  int b:3;
};
-
{a=>69,b=>-1}
450007000000
450007000000
4500000007000000
4500000007000000
-
{a=>50,b=>1}
320001000000
320001000000
3200000001000000
3200000001000000
-
{a=>40,b=>0}
280000000000
280000000000
2800000000000000
2800000000000000
-
{a=>-10,b=>-4}
f6ff04000000
f6ff04000000
f6ff000004000000
f6ff000004000000
-
{a=>-64,b=>-1}
c0ff07000000
c0ff07000000
c0ff000007000000
c0ff000007000000
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
};
-
{c=>0,a=>106,b=>-1}
6a0007000000
6a0007000000
6a00000007000000
6a00000007000000
-
{c=>-3,a=>112,b=>0}
700028000000
700028000000
7000000028000000
7000000028000000
-
{c=>-1,a=>75,b=>-4}
4b003c000000
4b003c000000
4b0000003c000000
4b0000003c000000
-
{c=>1,a=>-46,b=>1}
d2ff09000000
d2ff09000000
d2ff000009000000
d2ff000009000000
-
{c=>-4,a=>22,b=>-4}
160024000000
160024000000
1600000024000000
1600000024000000
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
};
-
{c=>0,a=>-84,b=>-2,d=>-1}
acffc6010000
acffc6010000
acff0000c6010000
acff0000c6010000
-
{c=>0,a=>-79,b=>2,d=>-1}
b1ffc2010000
b1ffc2010000
b1ff0000c2010000
b1ff0000c2010000
-
{c=>-2,a=>102,b=>2,d=>0}
660032000000
660032000000
6600000032000000
6600000032000000
-
{c=>-4,a=>117,b=>-3,d=>-2}
7500a5010000
7500a5010000
75000000a5010000
75000000a5010000
-
{c=>-1,a=>-97,b=>-1,d=>-2}
9fffbf010000
9fffbf010000
9fff0000bf010000
9fff0000bf010000
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
};
-
{e=>-1,c=>-2,a=>63,b=>0,d=>-4}
3f00300f0000
3f00300f0000
3f000000300f0000
3f000000300f0000
-
{e=>2,c=>-1,a=>-22,b=>-2,d=>2}
eaffbe040000
eaffbe040000
eaff0000be040000
eaff0000be040000
-
{e=>0,c=>1,a=>-97,b=>0,d=>3}
9fffc8000000
9fffc8000000
9fff0000c8000000
9fff0000c8000000
-
{e=>0,c=>-3,a=>-3,b=>-3,d=>3}
fdffed000000
fdffed000000
fdff0000ed000000
fdff0000ed000000
-
{e=>-2,c=>0,a=>-35,b=>-1,d=>-1}
ddffc70d0000
ddffc70d0000
ddff0000c70d0000
ddff0000c70d0000
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
};
-
{e=>-3,c=>0,a=>-77,b=>-2,d=>3,f=>3}
b3ffc63a0000
b3ffc63a0000
b3ff0000c63a0000
b3ff0000c63a0000
-
{e=>-2,c=>1,a=>108,b=>2,d=>1,f=>2}
6c004a2c0000
6c004a2c0000
6c0000004a2c0000
6c0000004a2c0000
-
{e=>-3,c=>3,a=>-37,b=>-2,d=>-3,f=>2}
dbff5e2b0000
dbff5e2b0000
dbff00005e2b0000
dbff00005e2b0000
-
{e=>-2,c=>3,a=>-8,b=>-3,d=>-1,f=>-1}
f8ffdd7d0000
f8ffdd7d0000
f8ff0000dd7d0000
f8ff0000dd7d0000
-
{e=>3,c=>-1,a=>-111,b=>-4,d=>-2,f=>-2}
91ffbc670000
91ffbc670000
91ff0000bc670000
91ff0000bc670000
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
};
-
{e=>-2,c=>1,a=>81,g=>-3,b=>2,d=>-3,f=>3}
51004abd0200
51004abd0200
510000004abd0200
510000004abd0200
-
{e=>1,c=>-2,a=>75,g=>-3,b=>-4,d=>-3,f=>-1}
4b0074f30200
4b0074f30200
4b00000074f30200
4b00000074f30200
-
{e=>1,c=>-4,a=>54,g=>-4,b=>-1,d=>-4,f=>-4}
360027430200
360027430200
3600000027430200
3600000027430200
-
{e=>-1,c=>-2,a=>82,g=>3,b=>1,d=>-4,f=>-3}
520031df0100
520031df0100
5200000031df0100
5200000031df0100
-
{e=>0,c=>-2,a=>-94,g=>3,b=>-1,d=>-4,f=>3}
a2ff37b10100
a2ff37b10100
a2ff000037b10100
a2ff000037b10100
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
};
-
{e=>-2,a=>-123,d=>2,c=>3,h=>0,b=>2,g=>2,f=>-2}
85ff9a6c0100
85ff9a6c0100
85ff00009a6c0100
85ff00009a6c0100
-
{e=>-4,a=>-75,d=>-2,c=>2,h=>-3,b=>0,g=>-4,f=>0}
b5ff90091600
b5ff90091600
b5ff000090091600
b5ff000090091600
-
{e=>-1,a=>-85,d=>0,c=>-4,h=>-4,b=>1,g=>-2,f=>-4}
abff214e1300
abff214e1300
abff0000214e1300
abff0000214e1300
-
{e=>-4,a=>94,d=>-1,c=>-4,h=>2,b=>-2,g=>-2,f=>3}
5e00e6390b00
5e00e6390b00
5e000000e6390b00
5e000000e6390b00
-
{e=>1,a=>26,d=>-3,c=>-3,h=>-3,b=>2,g=>-4,f=>2}
1a006a231600
1a006a231600
1a0000006a231600
1a0000006a231600
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
};
-
{e=>-4,a=>-127,d=>1,c=>0,h=>3,b=>1,g=>-1,f=>3,i=>3}
81ff41b86f00
81ff41b86f00
81ff000041b86f00
81ff000041b86f00
-
{e=>-2,a=>-73,d=>-3,c=>1,h=>-3,b=>-1,g=>3,f=>-3,i=>-4}
b7ff4fdd9500
b7ff4fdd9500
b7ff00004fdd9500
b7ff00004fdd9500
-
{e=>-4,a=>-22,d=>2,c=>-4,h=>3,b=>2,g=>0,f=>3,i=>-2}
eaffa238cc00
eaffa238cc00
eaff0000a238cc00
eaff0000a238cc00
-
{e=>3,a=>-124,d=>3,c=>2,h=>3,b=>0,g=>0,f=>2,i=>2}
84ffd0264c00
84ffd0264c00
84ff0000d0264c00
84ff0000d0264c00
-
{e=>2,a=>115,d=>3,c=>1,h=>-3,b=>2,g=>3,f=>-1,i=>0}
7300caf41500
7300caf41500
73000000caf41500
73000000caf41500
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
};
-
{e=>-4,a=>-21,d=>-2,j=>-2,c=>-1,h=>-1,b=>-2,g=>-2,f=>-3,i=>1}
ebffbe593f06
ebffbe593f06
ebff0000be593f06
ebff0000be593f06
-
{e=>-3,a=>71,d=>1,j=>-1,c=>2,h=>0,b=>-4,g=>1,f=>-4,i=>-4}
470054ca8007
470054ca8007
4700000054ca8007
4700000054ca8007
-
{e=>-2,a=>-5,d=>-3,j=>3,c=>-3,h=>1,b=>-3,g=>3,f=>2,i=>-1}
fbff6dade503
fbff6dade503
fbff00006dade503
fbff00006dade503
-
{e=>1,a=>-46,d=>3,j=>-2,c=>3,h=>-4,b=>-4,g=>-3,f=>-2,i=>0}
d2ffdce21206
d2ffdce21206
d2ff0000dce21206
d2ff0000dce21206
-
{e=>2,a=>-69,d=>-4,j=>0,c=>3,h=>3,b=>1,g=>2,f=>-2,i=>2}
bbff19654d00
bbff19654d00
bbff000019654d00
bbff000019654d00
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
};
-
{e=>3,a=>-20,d=>2,j=>-2,c=>-4,k=>3,h=>-1,b=>-1,g=>-2,f=>-4,i=>-3}
ecffa746bf1e
ecffa746bf1e
ecff0000a746bf1e
ecff0000a746bf1e
-
{e=>-1,a=>-104,d=>2,j=>-4,c=>1,k=>-2,h=>-1,b=>1,g=>-3,f=>-4,i=>1}
98ff89ce3e34
98ff89ce3e34
98ff000089ce3e34
98ff000089ce3e34
-
{e=>3,a=>11,d=>3,j=>0,c=>2,k=>-3,h=>-3,b=>-2,g=>0,f=>-1,i=>-4}
0b00d6769428
0b00d6769428
0b000000d6769428
0b000000d6769428
-
{e=>-1,a=>102,d=>2,j=>-2,c=>-4,k=>-4,h=>-1,b=>0,g=>-4,f=>-2,i=>2}
6600a06e5e26
6600a06e5e26
66000000a06e5e26
66000000a06e5e26
-
{e=>0,a=>-79,d=>-3,j=>-1,c=>0,k=>-2,h=>0,b=>3,g=>1,f=>-3,i=>-3}
b1ff43d1a037
b1ff43d1a037
b1ff000043d1a037
b1ff000043d1a037
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
};
-
{e=>-3,a=>-109,d=>-4,j=>-3,l=>-4,c=>-4,k=>-4,h=>-1,b=>1,g=>-1,f=>-4,i=>1}
93ff21cb3f2504000000
93ff21cb3f2504000000
93ff000021cb3f2504000000
93ff000021cb3f2504000000
-
{e=>1,a=>-37,d=>-3,j=>-2,l=>-3,c=>2,k=>-3,h=>-4,b=>3,g=>-1,f=>-4,i=>-2}
dbff53c3d32e05000000
dbff53c3d32e05000000
dbff000053c3d32e05000000
dbff000053c3d32e05000000
-
{e=>-3,a=>-27,d=>-3,j=>-2,l=>-3,c=>1,k=>1,h=>-2,b=>-4,g=>1,f=>3,i=>-4}
e5ff4cbb980e05000000
e5ff4cbb980e05000000
e5ff00004cbb980e05000000
e5ff00004cbb980e05000000
-
{e=>3,a=>-69,d=>-3,j=>-3,l=>-1,c=>-3,k=>1,h=>2,b=>3,g=>2,f=>0,i=>3}
bbff6b07690d07000000
bbff6b07690d07000000
bbff00006b07690d07000000
bbff00006b07690d07000000
-
{e=>0,a=>-52,d=>1,j=>2,l=>1,c=>-3,k=>-4,h=>0,b=>-3,g=>3,f=>-3,i=>0}
ccff6dd0012201000000
ccff6dd0012201000000
ccff00006dd0012201000000
ccff00006dd0012201000000
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
};
-
{e=>1,a=>-21,m=>-3,d=>-4,j=>-2,l=>2,c=>-4,k=>-2,h=>-4,b=>-4,g=>2,f=>-1,i=>2}
ebff247351362a000000
ebff247351362a000000
ebff0000247351362a000000
ebff0000247351362a000000
-
{e=>-1,a=>-68,m=>-2,d=>-2,j=>0,l=>1,c=>3,k=>2,h=>-3,b=>0,g=>3,f=>-3,i=>0}
bcff98df151031000000
bcff98df151031000000
bcff000098df151031000000
bcff000098df151031000000
-
{e=>-1,a=>-32,m=>-3,d=>0,j=>1,l=>2,c=>2,k=>-2,h=>0,b=>0,g=>-2,f=>-2,i=>-3}
e0ff106ea3312a000000
e0ff106ea3312a000000
e0ff0000106ea3312a000000
e0ff0000106ea3312a000000
-
{e=>1,a=>-68,m=>0,d=>1,j=>-3,l=>3,c=>-4,k=>2,h=>-4,b=>0,g=>3,f=>-1,i=>2}
bcff60f2511503000000
bcff60f2511503000000
bcff000060f2511503000000
bcff000060f2511503000000
-
{e=>-4,a=>-109,m=>-4,d=>2,j=>2,l=>-1,c=>-2,k=>2,h=>-1,b=>-4,g=>-1,f=>0,i=>-2}
93ffb488df1227000000
93ffb488df1227000000
93ff0000b488df1227000000
93ff0000b488df1227000000
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
  int n:3;
};
-
{e=>-2,n=>-4,a=>79,m=>-3,d=>3,j=>-2,l=>2,c=>-4,k=>-1,h=>0,b=>-1,g=>-4,f=>-4,i=>-4}
4f00e74c823e2a010000
4f00e74c823e2a010000
4f000000e74c823e2a010000
4f000000e74c823e2a010000
-
{e=>3,n=>0,a=>-114,m=>-3,d=>-1,j=>2,l=>-1,c=>0,k=>1,h=>0,b=>-1,g=>-1,f=>3,i=>0}
8effc7b7030a2f000000
8effc7b7030a2f000000
8eff0000c7b7030a2f000000
8eff0000c7b7030a2f000000
-
{e=>1,n=>0,a=>-17,m=>-1,d=>1,j=>2,l=>-2,c=>-4,k=>3,h=>-4,b=>-3,g=>-3,f=>0,i=>0}
efff6582121a3e000000
efff6582121a3e000000
efff00006582121a3e000000
efff00006582121a3e000000
-
{e=>2,n=>2,a=>-31,m=>0,d=>-4,j=>2,l=>-1,c=>0,k=>-2,h=>-1,b=>-3,g=>-4,f=>-2,i=>-1}
e1ff0565fe3287000000
e1ff0565fe3287000000
e1ff00000565fe3287000000
e1ff00000565fe3287000000
-
{e=>-4,n=>3,a=>-41,m=>1,d=>-1,j=>0,l=>-2,c=>1,k=>-1,h=>-2,b=>1,g=>0,f=>0,i=>0}
d7ffc9091838ce000000
d7ffc9091838ce000000
d7ff0000c9091838ce000000
d7ff0000c9091838ce000000
=
struct int_wrap {
  short a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
  int n:3;
  int o;
};
-
{e=>1,n=>0,a=>69,m=>-1,d=>-4,j=>1,l=>1,c=>-1,k=>-2,h=>-1,b=>-1,g=>-2,f=>-3,o=>1,i=>-1}
45003f53ff313900000001000000
45003f53ff313900000001000000
450000003f53ff313900000001000000
450000003f53ff313900000001000000
-
{e=>2,n=>0,a=>-113,m=>3,d=>1,j=>1,l=>-1,c=>0,k=>3,h=>2,b=>-1,g=>-1,f=>-4,o=>-65,i=>-3}
8fff47c4ab191f000000bfffffff
8fff47c4ab191f000000bfffffff
8fff000047c4ab191f000000bfffffff
8fff000047c4ab191f000000bfffffff
-
{e=>1,n=>-3,a=>-34,m=>0,d=>-1,j=>3,l=>0,c=>1,k=>3,h=>-1,b=>-1,g=>-1,f=>2,o=>-8,i=>0}
deffcfa31f1b40010000f8ffffff
deffcfa31f1b40010000f8ffffff
deff0000cfa31f1b40010000f8ffffff
deff0000cfa31f1b40010000f8ffffff
-
{e=>3,n=>1,a=>84,m=>-2,d=>1,j=>1,l=>1,c=>2,k=>3,h=>3,b=>3,g=>-4,f=>3,o=>115,i=>-3}
54005336ae197100000073000000
54005336ae197100000073000000
540000005336ae197100000073000000
540000005336ae197100000073000000
-
{e=>3,n=>0,a=>-51,m=>-3,d=>-3,j=>2,l=>0,c=>3,k=>2,h=>0,b=>1,g=>1,f=>3,o=>-72,i=>-3}
cdff59b7a01228000000b8ffffff
cdff59b7a01228000000b8ffffff
cdff000059b7a01228000000b8ffffff
cdff000059b7a01228000000b8ffffff
=
struct int_wrap {
  int a;
  int b:3;
};
-
{a=>-84,b=>-2}
acffffff06000000
acffffff06000000
acffffff06000000
acffffff06000000
-
{a=>71,b=>2}
4700000002000000
4700000002000000
4700000002000000
4700000002000000
-
{a=>-81,b=>0}
afffffff00000000
afffffff00000000
afffffff00000000
afffffff00000000
-
{a=>-113,b=>-3}
8fffffff05000000
8fffffff05000000
8fffffff05000000
8fffffff05000000
-
{a=>16,b=>-1}
1000000007000000
1000000007000000
1000000007000000
1000000007000000
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
};
-
{c=>-3,a=>53,b=>-4}
350000002c000000
350000002c000000
350000002c000000
350000002c000000
-
{c=>-3,a=>67,b=>-4}
430000002c000000
430000002c000000
430000002c000000
430000002c000000
-
{c=>1,a=>102,b=>2}
660000000a000000
660000000a000000
660000000a000000
660000000a000000
-
{c=>0,a=>-10,b=>1}
f6ffffff01000000
f6ffffff01000000
f6ffffff01000000
f6ffffff01000000
-
{c=>0,a=>-76,b=>0}
b4ffffff00000000
b4ffffff00000000
b4ffffff00000000
b4ffffff00000000
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
};
-
{c=>-1,a=>-33,b=>-1,d=>-1}
dfffffffff010000
dfffffffff010000
dfffffffff010000
dfffffffff010000
-
{c=>-4,a=>-87,b=>2,d=>-1}
a9ffffffe2010000
a9ffffffe2010000
a9ffffffe2010000
a9ffffffe2010000
-
{c=>3,a=>19,b=>0,d=>3}
13000000d8000000
13000000d8000000
13000000d8000000
13000000d8000000
-
{c=>-4,a=>39,b=>0,d=>-1}
27000000e0010000
27000000e0010000
27000000e0010000
27000000e0010000
-
{c=>0,a=>-2,b=>3,d=>-4}
feffffff03010000
feffffff03010000
feffffff03010000
feffffff03010000
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
};
-
{e=>1,c=>2,a=>-32,b=>1,d=>-2}
e0ffffff91030000
e0ffffff91030000
e0ffffff91030000
e0ffffff91030000
-
{e=>-4,c=>0,a=>12,b=>0,d=>2}
0c00000080080000
0c00000080080000
0c00000080080000
0c00000080080000
-
{e=>-2,c=>1,a=>74,b=>0,d=>0}
4a000000080c0000
4a000000080c0000
4a000000080c0000
4a000000080c0000
-
{e=>-3,c=>3,a=>-43,b=>-1,d=>-1}
d5ffffffdf0b0000
d5ffffffdf0b0000
d5ffffffdf0b0000
d5ffffffdf0b0000
-
{e=>3,c=>3,a=>67,b=>1,d=>-1}
43000000d9070000
43000000d9070000
43000000d9070000
43000000d9070000
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
};
-
{e=>0,c=>3,a=>-63,b=>2,d=>0,f=>1}
c1ffffff1a100000
c1ffffff1a100000
c1ffffff1a100000
c1ffffff1a100000
-
{e=>3,c=>3,a=>-76,b=>-1,d=>-4,f=>3}
b4ffffff1f370000
b4ffffff1f370000
b4ffffff1f370000
b4ffffff1f370000
-
{e=>-1,c=>0,a=>45,b=>3,d=>3,f=>0}
2d000000c30e0000
2d000000c30e0000
2d000000c30e0000
2d000000c30e0000
-
{e=>1,c=>2,a=>117,b=>-1,d=>-3,f=>-2}
7500000057630000
7500000057630000
7500000057630000
7500000057630000
-
{e=>-3,c=>-1,a=>75,b=>-4,d=>3,f=>3}
4b000000fc3a0000
4b000000fc3a0000
4b000000fc3a0000
4b000000fc3a0000
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
};
-
{e=>2,c=>0,a=>94,g=>-4,b=>2,d=>2,f=>2}
5e00000082240200
5e00000082240200
5e00000082240200
5e00000082240200
-
{e=>-4,c=>-3,a=>-22,g=>-3,b=>3,d=>3,f=>3}
eaffffffebb80200
eaffffffebb80200
eaffffffebb80200
eaffffffebb80200
-
{e=>3,c=>1,a=>14,g=>0,b=>1,d=>1,f=>1}
0e00000049160000
0e00000049160000
0e00000049160000
0e00000049160000
-
{e=>-3,c=>3,a=>-61,g=>-1,b=>-3,d=>-2,f=>-4}
c3ffffff9dcb0300
c3ffffff9dcb0300
c3ffffff9dcb0300
c3ffffff9dcb0300
-
{e=>-1,c=>-2,a=>28,g=>2,b=>1,d=>0,f=>-3}
1c000000315e0100
1c000000315e0100
1c000000315e0100
1c000000315e0100
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
};
-
{e=>1,a=>115,d=>2,c=>1,h=>0,b=>1,g=>1,f=>3}
7300000089b20000
7300000089b20000
7300000089b20000
7300000089b20000
-
{e=>1,a=>19,d=>-2,c=>-3,h=>2,b=>-1,g=>-1,f=>-1}
13000000aff30b00
13000000aff30b00
13000000aff30b00
13000000aff30b00
-
{e=>2,a=>-115,d=>2,c=>-4,h=>0,b=>-2,g=>-3,f=>-3}
8dffffffa6d40200
8dffffffa6d40200
8dffffffa6d40200
8dffffffa6d40200
-
{e=>-1,a=>126,d=>2,c=>-3,h=>2,b=>-4,g=>2,f=>2}
7e000000ac2e0900
7e000000ac2e0900
7e000000ac2e0900
7e000000ac2e0900
-
{e=>3,a=>123,d=>3,c=>0,h=>-4,b=>-2,g=>1,f=>-4}
7b000000c6c61000
7b000000c6c61000
7b000000c6c61000
7b000000c6c61000
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
};
-
{e=>0,a=>-116,d=>-4,c=>0,h=>-3,b=>0,g=>-4,f=>3,i=>-1}
8cffffff0031f600
8cffffff0031f600
8cffffff0031f600
8cffffff0031f600
-
{e=>-1,a=>-120,d=>0,c=>0,h=>-2,b=>2,g=>-1,f=>1,i=>-4}
88ffffff029e9b00
88ffffff029e9b00
88ffffff029e9b00
88ffffff029e9b00
-
{e=>0,a=>89,d=>0,c=>-3,h=>3,b=>-2,g=>0,f=>-1,i=>-4}
590000002e708c00
590000002e708c00
590000002e708c00
590000002e708c00
-
{e=>2,a=>107,d=>-1,c=>0,h=>-4,b=>0,g=>-2,f=>1,i=>2}
6b000000c0155300
6b000000c0155300
6b000000c0155300
6b000000c0155300
-
{e=>1,a=>126,d=>-2,c=>-1,h=>-3,b=>1,g=>3,f=>-4,i=>-2}
7e000000b9c3d500
7e000000b9c3d500
7e000000b9c3d500
7e000000b9c3d500
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
};
-
{e=>-1,a=>-65,d=>2,j=>-4,c=>-2,h=>-4,b=>0,g=>-1,f=>-3,i=>1}
bfffffffb0de3304
bfffffffb0de3304
bfffffffb0de3304
bfffffffb0de3304
-
{e=>-4,a=>-87,d=>-1,j=>1,c=>-2,h=>1,b=>3,g=>-2,f=>0,i=>2}
a9fffffff3094701
a9fffffff3094701
a9fffffff3094701
a9fffffff3094701
-
{e=>0,a=>19,d=>0,j=>0,c=>1,h=>1,b=>2,g=>-3,f=>3,i=>3}
130000000ab06600
130000000ab06600
130000000ab06600
130000000ab06600
-
{e=>1,a=>-111,d=>-2,j=>1,c=>3,h=>0,b=>-4,g=>-4,f=>1,i=>0}
91ffffff9c130201
91ffffff9c130201
91ffffff9c130201
91ffffff9c130201
-
{e=>-1,a=>-103,d=>1,j=>0,c=>-1,h=>-4,b=>2,g=>1,f=>-3,i=>3}
99ffffff7ade7000
99ffffff7ade7000
99ffffff7ade7000
99ffffff7ade7000
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
};
-
{e=>-3,a=>38,d=>-2,j=>2,c=>-2,k=>1,h=>1,b=>0,g=>0,f=>2,i=>0}
26000000b02b040a
26000000b02b040a
26000000b02b040a
26000000b02b040a
-
{e=>2,a=>41,d=>0,j=>-3,c=>1,k=>-2,h=>-3,b=>0,g=>0,f=>0,i=>0}
2900000008041435
2900000008041435
2900000008041435
2900000008041435
-
{e=>3,a=>107,d=>-3,j=>-1,c=>2,k=>-2,h=>1,b=>0,g=>-1,f=>3,i=>1}
6b00000050b72737
6b00000050b72737
6b00000050b72737
6b00000050b72737
-
{e=>3,a=>18,d=>-4,j=>2,c=>-4,k=>-1,h=>-3,b=>-1,g=>-3,f=>-3,i=>-3}
1200000027d7b63a
1200000027d7b63a
1200000027d7b63a
1200000027d7b63a
-
{e=>3,a=>-10,d=>-4,j=>2,c=>1,k=>0,h=>-1,b=>-4,g=>0,f=>1,i=>2}
f6ffffff0c175c02
f6ffffff0c175c02
f6ffffff0c175c02
f6ffffff0c175c02
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
};
-
{e=>1,a=>-91,d=>3,j=>-3,l=>2,c=>2,k=>-1,h=>1,b=>-1,g=>-4,f=>-2,i=>-3}
a5ffffffd762a63d02000000
a5ffffffd762a63d02000000
a5ffffffd762a63d02000000
a5ffffffd762a63d02000000
-
{e=>-1,a=>-28,d=>0,j=>-4,l=>-3,c=>-2,k=>2,h=>-4,b=>-2,g=>-2,f=>-1,i=>0}
e4ffffff367e131405000000
e4ffffff367e131405000000
e4ffffff367e131405000000
e4ffffff367e131405000000
-
{e=>1,a=>78,d=>-3,j=>-3,l=>-2,c=>1,k=>2,h=>0,b=>-2,g=>0,f=>-2,i=>-3}
4e0000004e63a01506000000
4e0000004e63a01506000000
4e0000004e63a01506000000
4e0000004e63a01506000000
-
{e=>-2,a=>71,d=>2,j=>-4,l=>-1,c=>-4,k=>2,h=>3,b=>1,g=>0,f=>-1,i=>1}
47000000a17c2c1407000000
47000000a17c2c1407000000
47000000a17c2c1407000000
47000000a17c2c1407000000
-
{e=>-2,a=>-99,d=>-4,j=>-2,l=>-4,c=>-2,k=>3,h=>-1,b=>1,g=>-4,f=>-1,i=>-1}
9dffffff317dfe1e04000000
9dffffff317dfe1e04000000
9dffffff317dfe1e04000000
9dffffff317dfe1e04000000
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
};
-
{e=>1,a=>11,m=>3,d=>0,j=>-1,l=>2,c=>2,k=>-2,h=>0,b=>2,g=>-1,f=>-4,i=>-3}
0b00000012c2a3371a000000
0b00000012c2a3371a000000
0b00000012c2a3371a000000
0b00000012c2a3371a000000
-
{e=>3,a=>-31,m=>-1,d=>1,j=>3,l=>1,c=>-3,k=>-4,h=>-3,b=>-3,g=>3,f=>-2,i=>0}
e1ffffff6de6152339000000
e1ffffff6de6152339000000
e1ffffff6de6152339000000
e1ffffff6de6152339000000
-
{e=>-1,a=>-107,m=>-1,d=>-4,j=>3,l=>-4,c=>3,k=>-3,h=>3,b=>0,g=>3,f=>-1,i=>2}
95ffffff18ff4d2b3c000000
95ffffff18ff4d2b3c000000
95ffffff18ff4d2b3c000000
95ffffff18ff4d2b3c000000
-
{e=>-3,a=>-123,m=>-3,d=>3,j=>-1,l=>3,c=>2,k=>-2,h=>1,b=>2,g=>-4,f=>-2,i=>-2}
85ffffffd26ac6372b000000
85ffffffd26ac6372b000000
85ffffffd26ac6372b000000
85ffffffd26ac6372b000000
-
{e=>-3,a=>-105,m=>-4,d=>-1,j=>-2,l=>-2,c=>-1,k=>3,h=>-4,b=>3,g=>-1,f=>3,i=>1}
97fffffffbbb331e26000000
97fffffffbbb331e26000000
97fffffffbbb331e26000000
97fffffffbbb331e26000000
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
  int n:3;
};
-
{e=>1,n=>2,a=>-70,m=>2,d=>-1,j=>-2,l=>-2,c=>-4,k=>0,h=>-3,b=>-3,g=>-4,f=>0,i=>-2}
baffffffe503d60696000000
baffffffe503d60696000000
baffffffe503d60696000000
baffffffe503d60696000000
-
{e=>-2,n=>-3,a=>99,m=>1,d=>-4,j=>0,l=>2,c=>-3,k=>2,h=>-4,b=>3,g=>1,f=>3,i=>1}
630000002bbd30104a010000
630000002bbd30104a010000
630000002bbd30104a010000
630000002bbd30104a010000
-
{e=>0,n=>-4,a=>-106,m=>2,d=>-4,j=>-1,l=>-3,c=>-1,k=>3,h=>2,b=>-4,g=>2,f=>-1,i=>2}
96ffffff3c71491f15010000
96ffffff3c71491f15010000
96ffffff3c71491f15010000
96ffffff3c71491f15010000
-
{e=>0,n=>1,a=>-37,m=>1,d=>1,j=>-3,l=>-4,c=>0,k=>-2,h=>0,b=>3,g=>-4,f=>-2,i=>-1}
dbffffff4360e2354c000000
dbffffff4360e2354c000000
dbffffff4360e2354c000000
dbffffff4360e2354c000000
-
{e=>-2,n=>-1,a=>21,m=>1,d=>-4,j=>-2,l=>0,c=>1,k=>-4,h=>-3,b=>1,g=>3,f=>-2,i=>-3}
1500000009edb526c8010000
1500000009edb526c8010000
1500000009edb526c8010000
1500000009edb526c8010000
=
struct int_wrap {
  int a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
  int n:3;
  int o;
};
-
{e=>-2,n=>-3,a=>77,m=>1,d=>0,j=>3,l=>-4,c=>1,k=>3,h=>-2,b=>-3,g=>0,f=>3,o=>-17,i=>2}
4d0000000d3c581b4c010000efffffff
4d0000000d3c581b4c010000efffffff
4d0000000d3c581b4c010000efffffff
4d0000000d3c581b4c010000efffffff
-
{e=>-1,n=>3,a=>113,m=>3,d=>3,j=>-1,l=>3,c=>3,k=>-3,h=>-4,b=>-4,g=>2,f=>-3,o=>72,i=>2}
71000000dc5e512fdb00000048000000
71000000dc5e512fdb00000048000000
71000000dc5e512fdb00000048000000
71000000dc5e512fdb00000048000000
-
{e=>-4,n=>2,a=>0,m=>2,d=>1,j=>2,l=>-2,c=>2,k=>-1,h=>-1,b=>-2,g=>-3,f=>-4,o=>60,i=>2}
0000000056c85e3a960000003c000000
0000000056c85e3a960000003c000000
0000000056c85e3a960000003c000000
0000000056c85e3a960000003c000000
-
{e=>-1,n=>-3,a=>65,m=>2,d=>-2,j=>3,l=>2,c=>3,k=>0,h=>3,b=>-4,g=>0,f=>1,o=>-92,i=>0}
410000009c1f0c0352010000a4ffffff
410000009c1f0c0352010000a4ffffff
410000009c1f0c0352010000a4ffffff
410000009c1f0c0352010000a4ffffff
-
{e=>1,n=>2,a=>64,m=>0,d=>-2,j=>2,l=>1,c=>-3,k=>0,h=>-1,b=>3,g=>2,f=>1,o=>-43,i=>-2}
40000000ab13dd0281000000d5ffffff
40000000ab13dd0281000000d5ffffff
40000000ab13dd0281000000d5ffffff
40000000ab13dd0281000000d5ffffff
=
struct int_wrap {
  long a;
  int b:3;
};
-
{a=>33,b=>-4}
2100000004000000
2100000004000000
2100000004000000
2100000004000000
-
{a=>122,b=>-4}
7a00000004000000
7a00000004000000
7a00000004000000
7a00000004000000
-
{a=>107,b=>-3}
6b00000005000000
6b00000005000000
6b00000005000000
6b00000005000000
-
{a=>17,b=>1}
1100000001000000
1100000001000000
1100000001000000
1100000001000000
-
{a=>-47,b=>2}
d1ffffff02000000
d1ffffff02000000
d1ffffff02000000
d1ffffff02000000
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
};
-
{c=>-2,a=>-37,b=>1}
dbffffff31000000
dbffffff31000000
dbffffff31000000
dbffffff31000000
-
{c=>-2,a=>-7,b=>1}
f9ffffff31000000
f9ffffff31000000
f9ffffff31000000
f9ffffff31000000
-
{c=>3,a=>124,b=>0}
7c00000018000000
7c00000018000000
7c00000018000000
7c00000018000000
-
{c=>0,a=>-128,b=>-4}
80ffffff04000000
80ffffff04000000
80ffffff04000000
80ffffff04000000
-
{c=>3,a=>5,b=>2}
050000001a000000
050000001a000000
050000001a000000
050000001a000000
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
};
-
{c=>3,a=>-33,b=>0,d=>-2}
dfffffff98010000
dfffffff98010000
dfffffff98010000
dfffffff98010000
-
{c=>1,a=>87,b=>1,d=>-3}
5700000049010000
5700000049010000
5700000049010000
5700000049010000
-
{c=>2,a=>-12,b=>0,d=>0}
f4ffffff10000000
f4ffffff10000000
f4ffffff10000000
f4ffffff10000000
-
{c=>3,a=>-30,b=>-2,d=>3}
e2ffffffde000000
e2ffffffde000000
e2ffffffde000000
e2ffffffde000000
-
{c=>1,a=>81,b=>3,d=>2}
510000008b000000
510000008b000000
510000008b000000
510000008b000000
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
};
-
{e=>2,c=>-1,a=>-61,b=>3,d=>2}
c3ffffffbb040000
c3ffffffbb040000
c3ffffffbb040000
c3ffffffbb040000
-
{e=>-2,c=>-3,a=>86,b=>2,d=>-1}
56000000ea0d0000
56000000ea0d0000
56000000ea0d0000
56000000ea0d0000
-
{e=>-2,c=>0,a=>126,b=>3,d=>-2}
7e000000830d0000
7e000000830d0000
7e000000830d0000
7e000000830d0000
-
{e=>-4,c=>2,a=>-98,b=>-3,d=>-2}
9effffff95090000
9effffff95090000
9effffff95090000
9effffff95090000
-
{e=>3,c=>3,a=>-97,b=>0,d=>3}
9fffffffd8060000
9fffffffd8060000
9fffffffd8060000
9fffffffd8060000
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
};
-
{e=>-4,c=>-1,a=>-9,b=>-1,d=>1,f=>-2}
f7ffffff7f680000
f7ffffff7f680000
f7ffffff7f680000
f7ffffff7f680000
-
{e=>1,c=>-4,a=>112,b=>-4,d=>1,f=>-3}
7000000064520000
7000000064520000
7000000064520000
7000000064520000
-
{e=>3,c=>-1,a=>-116,b=>2,d=>2,f=>-4}
8cffffffba460000
8cffffffba460000
8cffffffba460000
8cffffffba460000
-
{e=>-4,c=>-3,a=>-4,b=>-4,d=>2,f=>1}
fcffffffac180000
fcffffffac180000
fcffffffac180000
fcffffffac180000
-
{e=>-2,c=>-3,a=>-52,b=>3,d=>3,f=>0}
ccffffffeb0c0000
ccffffffeb0c0000
ccffffffeb0c0000
ccffffffeb0c0000
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
};
-
{e=>-2,c=>0,a=>92,g=>-1,b=>-2,d=>-2,f=>-2}
5c00000086ed0300
5c00000086ed0300
5c00000086ed0300
5c00000086ed0300
-
{e=>1,c=>-1,a=>-32,g=>-4,b=>3,d=>0,f=>-1}
e0ffffff3b720200
e0ffffff3b720200
e0ffffff3b720200
e0ffffff3b720200
-
{e=>-4,c=>3,a=>17,g=>-4,b=>1,d=>-4,f=>2}
1100000019290200
1100000019290200
1100000019290200
1100000019290200
-
{e=>1,c=>-4,a=>-113,g=>-1,b=>1,d=>-4,f=>-4}
8fffffff21c30300
8fffffff21c30300
8fffffff21c30300
8fffffff21c30300
-
{e=>0,c=>1,a=>23,g=>2,b=>3,d=>-3,f=>-3}
170000004b510100
170000004b510100
170000004b510100
170000004b510100
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
};
-
{e=>0,a=>76,d=>2,c=>-1,h=>-3,b=>3,g=>-3,f=>0}
4c000000bb801600
4c000000bb801600
4c000000bb801600
4c000000bb801600
-
{e=>3,a=>39,d=>-4,c=>-3,h=>1,b=>-2,g=>-2,f=>1}
270000002e170700
270000002e170700
270000002e170700
270000002e170700
-
{e=>2,a=>108,d=>2,c=>1,h=>3,b=>1,g=>2,f=>-2}
6c00000089640d00
6c00000089640d00
6c00000089640d00
6c00000089640d00
-
{e=>-2,a=>52,d=>-2,c=>-3,h=>-2,b=>1,g=>-4,f=>-2}
34000000a96d1a00
34000000a96d1a00
34000000a96d1a00
34000000a96d1a00
-
{e=>-3,a=>-110,d=>-4,c=>-4,h=>2,b=>-1,g=>1,f=>2}
92ffffff27ab0800
92ffffff27ab0800
92ffffff27ab0800
92ffffff27ab0800
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
};
-
{e=>2,a=>-27,d=>0,c=>0,h=>-3,b=>2,g=>-3,f=>-4,i=>-4}
e5ffffff02c49600
e5ffffff02c49600
e5ffffff02c49600
e5ffffff02c49600
-
{e=>-1,a=>109,d=>2,c=>1,h=>-2,b=>1,g=>0,f=>-3,i=>-3}
6d000000895eb800
6d000000895eb800
6d000000895eb800
6d000000895eb800
-
{e=>-3,a=>-65,d=>3,c=>2,h=>3,b=>0,g=>2,f=>-4,i=>-2}
bfffffffd04acd00
bfffffffd04acd00
bfffffffd04acd00
bfffffffd04acd00
-
{e=>3,a=>-118,d=>-1,c=>1,h=>-1,b=>0,g=>3,f=>2,i=>-4}
8affffffc8a79d00
8affffffc8a79d00
8affffffc8a79d00
8affffffc8a79d00
-
{e=>-4,a=>77,d=>-3,c=>3,h=>-1,b=>-2,g=>-1,f=>-3,i=>-3}
4d0000005ed9bf00
4d0000005ed9bf00
4d0000005ed9bf00
4d0000005ed9bf00
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
};
-
{e=>-3,a=>60,d=>2,j=>2,c=>2,h=>-3,b=>3,g=>-1,f=>-2,i=>-1}
3c00000093eaf702
3c00000093eaf702
3c00000093eaf702
3c00000093eaf702
-
{e=>-3,a=>-119,d=>0,j=>-2,c=>3,h=>-3,b=>3,g=>-3,f=>-3,i=>-3}
89ffffff1bdab606
89ffffff1bdab606
89ffffff1bdab606
89ffffff1bdab606
-
{e=>-4,a=>94,d=>2,j=>2,c=>1,h=>3,b=>1,g=>1,f=>3,i=>3}
5e00000089b86c02
5e00000089b86c02
5e00000089b86c02
5e00000089b86c02
-
{e=>3,a=>116,d=>1,j=>2,c=>-4,h=>-3,b=>0,g=>3,f=>2,i=>-4}
7400000060a69502
7400000060a69502
7400000060a69502
7400000060a69502
-
{e=>1,a=>42,d=>-4,j=>-4,c=>-2,h=>-2,b=>2,g=>-3,f=>-2,i=>-3}
2a00000032e3ba04
2a00000032e3ba04
2a00000032e3ba04
2a00000032e3ba04
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
};
-
{e=>0,a=>15,d=>3,j=>2,c=>0,k=>3,h=>-4,b=>3,g=>-1,f=>-4,i=>-4}
0f000000c3c0931a
0f000000c3c0931a
0f000000c3c0931a
0f000000c3c0931a
-
{e=>-2,a=>-58,d=>-3,j=>-1,c=>-1,k=>-2,h=>1,b=>-2,g=>3,f=>-4,i=>-3}
c6ffffff7ecda537
c6ffffff7ecda537
c6ffffff7ecda537
c6ffffff7ecda537
-
{e=>0,a=>3,d=>-4,j=>-4,c=>2,k=>1,h=>3,b=>0,g=>-4,f=>3,i=>-4}
0300000010318e0c
0300000010318e0c
0300000010318e0c
0300000010318e0c
-
{e=>-2,a=>9,d=>3,j=>3,c=>-3,k=>-2,h=>-1,b=>-1,g=>1,f=>-4,i=>3}
09000000efcc7c33
09000000efcc7c33
09000000efcc7c33
09000000efcc7c33
-
{e=>-2,a=>41,d=>2,j=>-1,c=>-3,k=>-2,h=>-4,b=>-2,g=>-1,f=>2,i=>3}
29000000aeac7337
29000000aeac7337
29000000aeac7337
29000000aeac7337
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
};
-
{e=>-3,a=>-21,d=>3,j=>0,l=>-3,c=>-3,k=>3,h=>0,b=>2,g=>-4,f=>-3,i=>-3}
ebffffffea5aa21805000000
ebffffffea5aa21805000000
ebffffffea5aa21805000000
ebffffffea5aa21805000000
-
{e=>0,a=>26,d=>3,j=>3,l=>-4,c=>0,k=>2,h=>-1,b=>-1,g=>-2,f=>0,i=>-4}
1a000000c7009f1304000000
1a000000c7009f1304000000
1a000000c7009f1304000000
1a000000c7009f1304000000
-
{e=>-3,a=>-32,d=>-2,j=>0,l=>-4,c=>-3,k=>-2,h=>2,b=>-1,g=>1,f=>2,i=>-3}
e0ffffffafaba83004000000
e0ffffffafaba83004000000
e0ffffffafaba83004000000
e0ffffffafaba83004000000
-
{e=>2,a=>-37,d=>-2,j=>-3,l=>-4,c=>1,k=>1,h=>-2,b=>2,g=>3,f=>0,i=>3}
dbffffff8a85790d04000000
dbffffff8a85790d04000000
dbffffff8a85790d04000000
dbffffff8a85790d04000000
-
{e=>1,a=>-116,d=>-2,j=>0,l=>2,c=>1,k=>-4,h=>0,b=>2,g=>-3,f=>-1,i=>-4}
8cffffff8af3822002000000
8cffffff8af3822002000000
8cffffff8af3822002000000
8cffffff8af3822002000000
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
};
-
{e=>-1,a=>-6,m=>-3,d=>0,j=>3,l=>1,c=>-4,k=>1,h=>-4,b=>1,g=>2,f=>1,i=>2}
faffffff211e510b29000000
faffffff211e510b29000000
faffffff211e510b29000000
faffffff211e510b29000000
-
{e=>2,a=>-118,m=>-4,d=>-1,j=>-2,l=>2,c=>3,k=>-3,h=>3,b=>0,g=>-3,f=>-4,i=>3}
8affffffd8c56e2e22000000
8affffffd8c56e2e22000000
8affffffd8c56e2e22000000
8affffffd8c56e2e22000000
-
{e=>3,a=>-56,m=>1,d=>3,j=>0,l=>3,c=>2,k=>-2,h=>1,b=>2,g=>0,f=>-3,i=>-2}
c8ffffffd256c4300b000000
c8ffffffd256c4300b000000
c8ffffffd256c4300b000000
c8ffffffd256c4300b000000
-
{e=>1,a=>-55,m=>-4,d=>0,j=>-1,l=>3,c=>-3,k=>-4,h=>3,b=>-4,g=>2,f=>-2,i=>-4}
c9ffffff2c628d2723000000
c9ffffff2c628d2723000000
c9ffffff2c628d2723000000
c9ffffff2c628d2723000000
-
{e=>-3,a=>-107,m=>0,d=>-1,j=>2,l=>-3,c=>-2,k=>-2,h=>-2,b=>-4,g=>2,f=>1,i=>-3}
95fffffff41bb93205000000
95fffffff41bb93205000000
95fffffff41bb93205000000
95fffffff41bb93205000000
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
  int n:3;
};
-
{e=>-1,n=>-1,a=>-103,m=>-3,d=>-3,j=>2,l=>-4,c=>-3,k=>3,h=>2,b=>3,g=>-4,f=>1,i=>1}
99ffffff6b1f2a1aec010000
99ffffff6b1f2a1aec010000
99ffffff6b1f2a1aec010000
99ffffff6b1f2a1aec010000
-
{e=>1,n=>-1,a=>-117,m=>3,d=>-3,j=>3,l=>2,c=>-4,k=>2,h=>-1,b=>-3,g=>-1,f=>0,i=>-1}
8bffffff6583ff13da010000
8bffffff6583ff13da010000
8bffffff6583ff13da010000
8bffffff6583ff13da010000
-
{e=>1,n=>-3,a=>28,m=>-1,d=>-4,j=>2,l=>-4,c=>3,k=>-4,h=>-2,b=>0,g=>2,f=>-4,i=>1}
1c000000184339227c010000
1c000000184339227c010000
1c000000184339227c010000
1c000000184339227c010000
-
{e=>-4,n=>3,a=>29,m=>-4,d=>2,j=>-2,l=>-4,c=>-2,k=>-2,h=>2,b=>-2,g=>-2,f=>-2,i=>-2}
1d000000b668cb36e4000000
1d000000b668cb36e4000000
1d000000b668cb36e4000000
1d000000b668cb36e4000000
-
{e=>3,n=>-1,a=>-93,m=>-1,d=>3,j=>3,l=>-2,c=>2,k=>2,h=>-2,b=>1,g=>0,f=>3,i=>2}
a3ffffffd1365813fe010000
a3ffffffd1365813fe010000
a3ffffffd1365813fe010000
a3ffffffd1365813fe010000
=
struct int_wrap {
  long a;
  int b:3;
  int c:3;
  int d:3;
  int e:3;
  int f:3;
  int g:3;
  int h:3;
  int i:3;
  int j:3;
  int k:3;
  int l:3;
  int m:3;
  int n:3;
  int o;
};
-
{e=>-3,n=>1,a=>-24,m=>2,d=>-2,j=>-2,l=>-4,c=>-1,k=>0,h=>-4,b=>-1,g=>-4,f=>0,o=>10,i=>1}
e8ffffffbf0b3206540000000a000000
e8ffffffbf0b3206540000000a000000
e8ffffffbf0b3206540000000a000000
e8ffffffbf0b3206540000000a000000
-
{e=>0,n=>3,a=>91,m=>3,d=>1,j=>-2,l=>-1,c=>-3,k=>0,h=>1,b=>3,g=>3,f=>0,o=>0,i=>0}
5b0000006b800506df00000000000000
5b0000006b800506df00000000000000
5b0000006b800506df00000000000000
5b0000006b800506df00000000000000
-
{e=>-4,n=>-4,a=>-91,m=>0,d=>1,j=>0,l=>3,c=>1,k=>-4,h=>0,b=>3,g=>1,f=>-2,o=>81,i=>-3}
a5ffffff4be8a0200301000051000000
a5ffffff4be8a0200301000051000000
a5ffffff4be8a0200301000051000000
a5ffffff4be8a0200301000051000000
-
{e=>0,n=>-3,a=>-22,m=>-1,d=>-4,j=>-1,l=>0,c=>3,k=>-2,h=>3,b=>-3,g=>-1,f=>-3,o=>40,i=>2}
eaffffff1dd14f377801000028000000
eaffffff1dd14f377801000028000000
eaffffff1dd14f377801000028000000
eaffffff1dd14f377801000028000000
-
{e=>-2,n=>1,a=>-71,m=>2,d=>2,j=>-3,l=>-4,c=>0,k=>-3,h=>2,b=>-2,g=>2,f=>0,o=>-119,i=>-2}
b9ffffff860cc92d5400000089ffffff
b9ffffff860cc92d5400000089ffffff
b9ffffff860cc92d5400000089ffffff
b9ffffff860cc92d5400000089ffffff
=
struct umixed3 {
  unsigned char  a:3;
};
-
{a=>7}
07
07
07
07
-
{a=>4}
04
04
04
04
-
{a=>1}
01
01
01
01
-
{a=>2}
02
02
02
02
-
{a=>5}
05
05
05
05
=
struct umixed3 {
  unsigned char  a:3;
  unsigned char  b:3;
};
-
{a=>6,b=>0}
06
06
06
06
-
{a=>0,b=>4}
20
20
20
20
-
{a=>2,b=>1}
0a
0a
0a
0a
-
{a=>7,b=>3}
1f
1f
1f
1f
-
{a=>2,b=>3}
1a
1a
1a
1a
=
struct umixed3 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned int   c:3;
};
-
{c=>0,a=>7,b=>5}
2f00000000
2f0000000000
2f00000000000000
2f00000000000000
-
{c=>2,a=>6,b=>7}
3e02000000
3e0002000000
3e00000002000000
3e00000002000000
-
{c=>2,a=>7,b=>2}
1702000000
170002000000
1700000002000000
1700000002000000
-
{c=>7,a=>1,b=>3}
1907000000
190007000000
1900000007000000
1900000007000000
-
{c=>5,a=>3,b=>4}
2305000000
230005000000
2300000005000000
2300000005000000
=
struct umixed3 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned int   c:3;
  unsigned char  d:3;
};
-
{c=>6,a=>2,b=>1,d=>2}
0a0600000002
0a00060000000200
0a0000000600000002000000
0a0000000600000002000000
-
{c=>5,a=>6,b=>1,d=>3}
0e0500000003
0e00050000000300
0e0000000500000003000000
0e0000000500000003000000
-
{c=>4,a=>6,b=>1,d=>0}
0e0400000000
0e00040000000000
0e0000000400000000000000
0e0000000400000000000000
-
{c=>0,a=>1,b=>5,d=>6}
290000000006
2900000000000600
290000000000000006000000
290000000000000006000000
-
{c=>7,a=>6,b=>2,d=>2}
160700000002
1600070000000200
160000000700000002000000
160000000700000002000000
=
struct umixed3 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned int   c:3;
  unsigned char  d:3;
  unsigned short e:3;
};
-
{e=>3,c=>6,a=>3,b=>0,d=>1}
0306000000010300
03000600000001000300
030000000600000001000300
030000000600000001000300
-
{e=>6,c=>0,a=>3,b=>1,d=>5}
0b00000000050600
0b000000000005000600
0b0000000000000005000600
0b0000000000000005000600
-
{e=>7,c=>2,a=>2,b=>6,d=>5}
3202000000050700
32000200000005000700
320000000200000005000700
320000000200000005000700
-
{e=>6,c=>0,a=>3,b=>3,d=>3}
1b00000000030600
1b000000000003000600
1b0000000000000003000600
1b0000000000000003000600
-
{e=>6,c=>7,a=>0,b=>3,d=>3}
1807000000030600
18000700000003000600
180000000700000003000600
180000000700000003000600
=
struct umixed3 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned int   c:3;
  unsigned char  d:3;
  unsigned short e:3;
  unsigned char  f:3;
};
-
{e=>3,c=>4,a=>4,b=>7,d=>6,f=>2}
3c0400000006030002
3c0004000000060003000200
3c000000040000000600030002000000
3c000000040000000600030002000000
-
{e=>5,c=>4,a=>2,b=>7,d=>0,f=>6}
3a0400000000050006
3a0004000000000005000600
3a000000040000000000050006000000
3a000000040000000000050006000000
-
{e=>7,c=>6,a=>0,b=>4,d=>1,f=>6}
200600000001070006
200006000000010007000600
20000000060000000100070006000000
20000000060000000100070006000000
-
{e=>4,c=>6,a=>1,b=>0,d=>1,f=>3}
010600000001040003
010006000000010004000300
01000000060000000100040003000000
01000000060000000100040003000000
-
{e=>6,c=>4,a=>6,b=>6,d=>6,f=>0}
360400000006060000
360004000000060006000000
36000000040000000600060000000000
36000000040000000600060000000000
=
struct umixed3 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned int   c:3;
  unsigned char  d:3;
  unsigned short e:3;
  unsigned char  f:3;
  unsigned long  g;
};
-
{e=>4,c=>5,a=>4,g=>216,b=>7,d=>5,f=>4}
3c0500000005040004d8000000
3c0005000000050004000400d8000000
3c000000050000000500040004000000d8000000
3c000000050000000500040004000000d8000000
-
{e=>0,c=>0,a=>7,g=>119,b=>7,d=>3,f=>5}
3f000000000300000577000000
3f000000000003000000050077000000
3f00000000000000030000000500000077000000
3f00000000000000030000000500000077000000
-
{e=>4,c=>0,a=>7,g=>69,b=>6,d=>3,f=>3}
37000000000304000345000000
37000000000003000400030045000000
3700000000000000030004000300000045000000
3700000000000000030004000300000045000000
-
{e=>1,c=>0,a=>5,g=>247,b=>4,d=>1,f=>7}
250000000001010007f7000000
250000000000010001000700f7000000
25000000000000000100010007000000f7000000
25000000000000000100010007000000f7000000
-
{e=>4,c=>5,a=>4,g=>112,b=>1,d=>3,f=>4}
0c050000000304000470000000
0c000500000003000400040070000000
0c00000005000000030004000400000070000000
0c00000005000000030004000400000070000000
=
struct umixed3 {
  char a;
  unsigned char  b:3;
};
-
{a=>-63,b=>6}
c106
c106
c106
c106
-
{a=>-85,b=>7}
ab07
ab07
ab07
ab07
-
{a=>52,b=>0}
3400
3400
3400
3400
-
{a=>-89,b=>2}
a702
a702
a702
a702
-
{a=>-62,b=>7}
c207
c207
c207
c207
=
struct umixed3 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>1,a=>77,b=>0}
4d08
4d08
4d08
4d08
-
{c=>7,a=>73,b=>2}
493a
493a
493a
493a
-
{c=>5,a=>116,b=>5}
742d
742d
742d
742d
-
{c=>7,a=>-44,b=>1}
d439
d439
d439
d439
-
{c=>7,a=>-66,b=>7}
be3f
be3f
be3f
be3f
=
struct umixed3 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
};
-
{c=>0,a=>-16,b=>5,d=>5}
f00505000000
f00505000000
f005000005000000
f005000005000000
-
{c=>0,a=>-4,b=>7,d=>6}
fc0706000000
fc0706000000
fc07000006000000
fc07000006000000
-
{c=>5,a=>-11,b=>0,d=>2}
f52802000000
f52802000000
f528000002000000
f528000002000000
-
{c=>6,a=>-39,b=>1,d=>0}
d93100000000
d93100000000
d931000000000000
d931000000000000
-
{c=>7,a=>78,b=>1,d=>0}
4e3900000000
4e3900000000
4e39000000000000
4e39000000000000
=
struct umixed3 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
};
-
{e=>2,c=>6,a=>28,b=>6,d=>7}
1c360700000002
1c36070000000200
1c3600000700000002000000
1c3600000700000002000000
-
{e=>0,c=>6,a=>-11,b=>2,d=>3}
f5320300000000
f532030000000000
f53200000300000000000000
f53200000300000000000000
-
{e=>5,c=>7,a=>27,b=>0,d=>1}
1b380100000005
1b38010000000500
1b3800000100000005000000
1b3800000100000005000000
-
{e=>2,c=>5,a=>1,b=>0,d=>7}
01280700000002
0128070000000200
012800000700000002000000
012800000700000002000000
-
{e=>7,c=>1,a=>79,b=>3,d=>7}
4f0b0700000007
4f0b070000000700
4f0b00000700000007000000
4f0b00000700000007000000
=
struct umixed3 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
};
-
{e=>1,c=>7,a=>43,b=>0,d=>7,f=>3}
2b3807000000010300
2b380700000001000300
2b3800000700000001000300
2b3800000700000001000300
-
{e=>3,c=>7,a=>-115,b=>7,d=>5,f=>4}
8d3f05000000030400
8d3f0500000003000400
8d3f00000500000003000400
8d3f00000500000003000400
-
{e=>4,c=>7,a=>86,b=>7,d=>6,f=>6}
563f06000000040600
563f0600000004000600
563f00000600000004000600
563f00000600000004000600
-
{e=>1,c=>0,a=>-25,b=>3,d=>2,f=>1}
e70302000000010100
e7030200000001000100
e70300000200000001000100
e70300000200000001000100
-
{e=>7,c=>7,a=>19,b=>4,d=>7,f=>0}
133c07000000070000
133c0700000007000000
133c00000700000007000000
133c00000700000007000000
=
struct umixed3 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
  unsigned char  g:3;
};
-
{e=>7,c=>3,a=>-86,g=>1,b=>7,d=>6,f=>1}
aa1f0600000007010001
aa1f06000000070001000100
aa1f0000060000000700010001000000
aa1f0000060000000700010001000000
-
{e=>1,c=>6,a=>18,g=>4,b=>6,d=>5,f=>5}
12360500000001050004
123605000000010005000400
12360000050000000100050004000000
12360000050000000100050004000000
-
{e=>0,c=>5,a=>6,g=>2,b=>6,d=>1,f=>0}
062e0100000000000002
062e01000000000000000200
062e0000010000000000000002000000
062e0000010000000000000002000000
-
{e=>0,c=>2,a=>2,g=>1,b=>5,d=>3,f=>4}
02150300000000040001
021503000000000004000100
02150000030000000000040001000000
02150000030000000000040001000000
-
{e=>4,c=>6,a=>110,g=>5,b=>6,d=>3,f=>1}
6e360300000004010005
6e3603000000040001000500
6e360000030000000400010005000000
6e360000030000000400010005000000
=
struct umixed3 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
  unsigned char  g:3;
  unsigned long  h;
};
-
{e=>7,a=>-103,d=>2,c=>7,h=>28,b=>4,g=>0,f=>0}
993c02000000070000001c000000
993c020000000700000000001c000000
993c00000200000007000000000000001c000000
993c00000200000007000000000000001c000000
-
{e=>1,a=>-118,d=>7,c=>2,h=>87,b=>6,g=>2,f=>7}
8a16070000000107000257000000
8a160700000001000700020057000000
8a16000007000000010007000200000057000000
8a16000007000000010007000200000057000000
-
{e=>0,a=>93,d=>0,c=>4,h=>190,b=>4,g=>2,f=>4}
5d240000000000040002be000000
5d2400000000000004000200be000000
5d240000000000000000040002000000be000000
5d240000000000000000040002000000be000000
-
{e=>4,a=>119,d=>3,c=>2,h=>230,b=>0,g=>6,f=>3}
77100300000004030006e6000000
771003000000040003000600e6000000
77100000030000000400030006000000e6000000
77100000030000000400030006000000e6000000
-
{e=>5,a=>-101,d=>5,c=>7,h=>52,b=>3,g=>7,f=>4}
9b3b050000000504000734000000
9b3b0500000005000400070034000000
9b3b000005000000050004000700000034000000
9b3b000005000000050004000700000034000000
=
struct umixed3 {
  short a;
  unsigned char  b:3;
};
-
{a=>117,b=>6}
750006
75000600
75000600
75000600
-
{a=>27,b=>7}
1b0007
1b000700
1b000700
1b000700
-
{a=>-51,b=>0}
cdff00
cdff0000
cdff0000
cdff0000
-
{a=>-8,b=>4}
f8ff04
f8ff0400
f8ff0400
f8ff0400
-
{a=>72,b=>7}
480007
48000700
48000700
48000700
=
struct umixed3 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>0,a=>-49,b=>3}
cfff03
cfff0300
cfff0300
cfff0300
-
{c=>4,a=>28,b=>7}
1c0027
1c002700
1c002700
1c002700
-
{c=>2,a=>97,b=>5}
610015
61001500
61001500
61001500
-
{c=>3,a=>-123,b=>0}
85ff18
85ff1800
85ff1800
85ff1800
-
{c=>3,a=>71,b=>7}
47001f
47001f00
47001f00
47001f00
=
struct umixed3 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
};
-
{c=>6,a=>-55,b=>7,d=>2}
c9ff3702000000
c9ff370002000000
c9ff370002000000
c9ff370002000000
-
{c=>4,a=>118,b=>0,d=>7}
76002007000000
7600200007000000
7600200007000000
7600200007000000
-
{c=>4,a=>-56,b=>7,d=>0}
c8ff2700000000
c8ff270000000000
c8ff270000000000
c8ff270000000000
-
{c=>1,a=>111,b=>5,d=>1}
6f000d01000000
6f000d0001000000
6f000d0001000000
6f000d0001000000
-
{c=>4,a=>-108,b=>3,d=>3}
94ff2303000000
94ff230003000000
94ff230003000000
94ff230003000000
=
struct umixed3 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
};
-
{e=>2,c=>5,a=>2,b=>4,d=>4}
02002c0400000002
02002c00040000000200
02002c000400000002000000
02002c000400000002000000
-
{e=>7,c=>2,a=>57,b=>2,d=>1}
3900120100000007
39001200010000000700
390012000100000007000000
390012000100000007000000
-
{e=>1,c=>6,a=>92,b=>1,d=>3}
5c00310300000001
5c003100030000000100
5c0031000300000001000000
5c0031000300000001000000
-
{e=>0,c=>1,a=>-36,b=>0,d=>2}
dcff080200000000
dcff0800020000000000
dcff08000200000000000000
dcff08000200000000000000
-
{e=>1,c=>4,a=>-88,b=>1,d=>0}
a8ff210000000001
a8ff2100000000000100
a8ff21000000000001000000
a8ff21000000000001000000
=
struct umixed3 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
};
-
{e=>0,c=>1,a=>-52,b=>6,d=>1,f=>6}
ccff0e01000000000600
ccff0e000100000000000600
ccff0e000100000000000600
ccff0e000100000000000600
-
{e=>3,c=>5,a=>-41,b=>2,d=>6,f=>0}
d7ff2a06000000030000
d7ff2a000600000003000000
d7ff2a000600000003000000
d7ff2a000600000003000000
-
{e=>2,c=>3,a=>-90,b=>5,d=>7,f=>3}
a6ff1d07000000020300
a6ff1d000700000002000300
a6ff1d000700000002000300
a6ff1d000700000002000300
-
{e=>1,c=>4,a=>6,b=>2,d=>4,f=>7}
06002204000000010700
060022000400000001000700
060022000400000001000700
060022000400000001000700
-
{e=>2,c=>4,a=>24,b=>4,d=>4,f=>7}
18002404000000020700
180024000400000002000700
180024000400000002000700
180024000400000002000700
=
struct umixed3 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
  unsigned char  g:3;
};
-
{e=>4,c=>2,a=>-91,g=>7,b=>6,d=>2,f=>3}
a5ff160200000004030007
a5ff160002000000040003000700
a5ff1600020000000400030007000000
a5ff1600020000000400030007000000
-
{e=>3,c=>0,a=>116,g=>7,b=>3,d=>7,f=>4}
7400030700000003040007
7400030007000000030004000700
74000300070000000300040007000000
74000300070000000300040007000000
-
{e=>2,c=>7,a=>93,g=>4,b=>6,d=>6,f=>7}
5d003e0600000002070004
5d003e0006000000020007000400
5d003e00060000000200070004000000
5d003e00060000000200070004000000
-
{e=>2,c=>5,a=>108,g=>5,b=>4,d=>4,f=>2}
6c002c0400000002020005
6c002c0004000000020002000500
6c002c00040000000200020005000000
6c002c00040000000200020005000000
-
{e=>4,c=>2,a=>-28,g=>3,b=>4,d=>2,f=>6}
e4ff140200000004060003
e4ff140002000000040006000300
e4ff1400020000000400060003000000
e4ff1400020000000400060003000000
=
struct umixed3 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
  unsigned char  g:3;
  unsigned long  h;
};
-
{e=>4,a=>-83,d=>2,c=>5,h=>218,b=>0,g=>2,f=>5}
adff280200000004050002da000000
adff280002000000040005000200da000000
adff2800020000000400050002000000da000000
adff2800020000000400050002000000da000000
-
{e=>2,a=>12,d=>1,c=>2,h=>88,b=>2,g=>6,f=>2}
0c0012010000000202000658000000
0c0012000100000002000200060058000000
0c00120001000000020002000600000058000000
0c00120001000000020002000600000058000000
-
{e=>1,a=>-57,d=>1,c=>1,h=>75,b=>1,g=>4,f=>3}
c7ff0901000000010300044b000000
c7ff0900010000000100030004004b000000
c7ff09000100000001000300040000004b000000
c7ff09000100000001000300040000004b000000
-
{e=>7,a=>17,d=>6,c=>0,h=>143,b=>5,g=>4,f=>1}
11000506000000070100048f000000
11000500060000000700010004008f000000
110005000600000007000100040000008f000000
110005000600000007000100040000008f000000
-
{e=>1,a=>10,d=>6,c=>1,h=>73,b=>1,g=>0,f=>6}
0a0009060000000106000049000000
0a0009000600000001000600000049000000
0a00090006000000010006000000000049000000
0a00090006000000010006000000000049000000
=
struct umixed3 {
  int a;
  unsigned char  b:3;
};
-
{a=>-62,b=>6}
c2ffffff06
c2ffffff0600
c2ffffff06000000
c2ffffff06000000
-
{a=>-53,b=>2}
cbffffff02
cbffffff0200
cbffffff02000000
cbffffff02000000
-
{a=>118,b=>0}
7600000000
760000000000
7600000000000000
7600000000000000
-
{a=>59,b=>0}
3b00000000
3b0000000000
3b00000000000000
3b00000000000000
-
{a=>-20,b=>1}
ecffffff01
ecffffff0100
ecffffff01000000
ecffffff01000000
=
struct umixed3 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>5,a=>-62,b=>7}
c2ffffff2f
c2ffffff2f00
c2ffffff2f000000
c2ffffff2f000000
-
{c=>6,a=>-14,b=>1}
f2ffffff31
f2ffffff3100
f2ffffff31000000
f2ffffff31000000
-
{c=>6,a=>63,b=>7}
3f00000037
3f0000003700
3f00000037000000
3f00000037000000
-
{c=>3,a=>41,b=>2}
290000001a
290000001a00
290000001a000000
290000001a000000
-
{c=>7,a=>18,b=>2}
120000003a
120000003a00
120000003a000000
120000003a000000
=
struct umixed3 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
};
-
{c=>5,a=>75,b=>4,d=>6}
4b0000002c06000000
4b0000002c0006000000
4b0000002c00000006000000
4b0000002c00000006000000
-
{c=>0,a=>117,b=>6,d=>0}
750000000600000000
75000000060000000000
750000000600000000000000
750000000600000000000000
-
{c=>2,a=>-47,b=>1,d=>6}
d1ffffff1106000000
d1ffffff110006000000
d1ffffff1100000006000000
d1ffffff1100000006000000
-
{c=>4,a=>-11,b=>0,d=>3}
f5ffffff2003000000
f5ffffff200003000000
f5ffffff2000000003000000
f5ffffff2000000003000000
-
{c=>1,a=>64,b=>7,d=>5}
400000000f05000000
400000000f0005000000
400000000f00000005000000
400000000f00000005000000
=
struct umixed3 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
};
-
{e=>1,c=>3,a=>-106,b=>7,d=>0}
96ffffff1f0000000001
96ffffff1f00000000000100
96ffffff1f0000000000000001000000
96ffffff1f0000000000000001000000
-
{e=>5,c=>5,a=>-62,b=>1,d=>2}
c2ffffff290200000005
c2ffffff2900020000000500
c2ffffff290000000200000005000000
c2ffffff290000000200000005000000
-
{e=>6,c=>2,a=>-4,b=>4,d=>4}
fcffffff140400000006
fcffffff1400040000000600
fcffffff140000000400000006000000
fcffffff140000000400000006000000
-
{e=>5,c=>7,a=>-93,b=>4,d=>2}
a3ffffff3c0200000005
a3ffffff3c00020000000500
a3ffffff3c0000000200000005000000
a3ffffff3c0000000200000005000000
-
{e=>7,c=>3,a=>67,b=>3,d=>2}
430000001b0200000007
430000001b00020000000700
430000001b0000000200000007000000
430000001b0000000200000007000000
=
struct umixed3 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
};
-
{e=>2,c=>6,a=>83,b=>3,d=>5,f=>4}
530000003305000000020400
5300000033000500000002000400
53000000330000000500000002000400
53000000330000000500000002000400
-
{e=>0,c=>5,a=>121,b=>1,d=>7,f=>3}
790000002907000000000300
7900000029000700000000000300
79000000290000000700000000000300
79000000290000000700000000000300
-
{e=>7,c=>2,a=>-79,b=>3,d=>7,f=>1}
b1ffffff1307000000070100
b1ffffff13000700000007000100
b1ffffff130000000700000007000100
b1ffffff130000000700000007000100
-
{e=>4,c=>0,a=>-82,b=>1,d=>3,f=>3}
aeffffff0103000000040300
aeffffff01000300000004000300
aeffffff010000000300000004000300
aeffffff010000000300000004000300
-
{e=>3,c=>4,a=>32,b=>4,d=>6,f=>0}
200000002406000000030000
2000000024000600000003000000
20000000240000000600000003000000
20000000240000000600000003000000
=
struct umixed3 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
  unsigned char  g:3;
};
-
{e=>7,c=>4,a=>-119,g=>7,b=>6,d=>2,f=>5}
89ffffff260200000007050007
89ffffff260002000000070005000700
89ffffff26000000020000000700050007000000
89ffffff26000000020000000700050007000000
-
{e=>4,c=>7,a=>75,g=>5,b=>7,d=>2,f=>3}
4b0000003f0200000004030005
4b0000003f0002000000040003000500
4b0000003f000000020000000400030005000000
4b0000003f000000020000000400030005000000
-
{e=>1,c=>0,a=>-122,g=>5,b=>5,d=>2,f=>1}
86ffffff050200000001010005
86ffffff050002000000010001000500
86ffffff05000000020000000100010005000000
86ffffff05000000020000000100010005000000
-
{e=>7,c=>6,a=>-118,g=>7,b=>5,d=>1,f=>3}
8affffff350100000007030007
8affffff350001000000070003000700
8affffff35000000010000000700030007000000
8affffff35000000010000000700030007000000
-
{e=>6,c=>5,a=>-69,g=>0,b=>7,d=>1,f=>1}
bbffffff2f0100000006010000
bbffffff2f0001000000060001000000
bbffffff2f000000010000000600010000000000
bbffffff2f000000010000000600010000000000
=
struct umixed3 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
  unsigned char  g:3;
  unsigned long  h;
};
-
{e=>7,a=>22,d=>3,c=>6,h=>27,b=>7,g=>2,f=>4}
160000003703000000070400021b000000
160000003700030000000700040002001b000000
16000000370000000300000007000400020000001b000000
16000000370000000300000007000400020000001b000000
-
{e=>0,a=>-54,d=>1,c=>7,h=>112,b=>1,g=>4,f=>2}
caffffff39010000000002000470000000
caffffff39000100000000000200040070000000
caffffff3900000001000000000002000400000070000000
caffffff3900000001000000000002000400000070000000
-
{e=>7,a=>1,d=>5,c=>7,h=>4,b=>5,g=>5,f=>4}
010000003d050000000704000504000000
010000003d000500000007000400050004000000
010000003d00000005000000070004000500000004000000
010000003d00000005000000070004000500000004000000
-
{e=>2,a=>10,d=>0,c=>1,h=>37,b=>2,g=>4,f=>7}
0a0000000a000000000207000425000000
0a0000000a000000000002000700040025000000
0a0000000a00000000000000020007000400000025000000
0a0000000a00000000000000020007000400000025000000
-
{e=>4,a=>-17,d=>3,c=>0,h=>76,b=>4,g=>0,f=>6}
efffffff0403000000040600004c000000
efffffff0400030000000400060000004c000000
efffffff040000000300000004000600000000004c000000
efffffff040000000300000004000600000000004c000000
=
struct umixed3 {
  long a;
  unsigned char  b:3;
};
-
{a=>83,b=>2}
5300000002
530000000200
5300000002000000
5300000002000000
-
{a=>21,b=>7}
1500000007
150000000700
1500000007000000
1500000007000000
-
{a=>-112,b=>2}
90ffffff02
90ffffff0200
90ffffff02000000
90ffffff02000000
-
{a=>56,b=>1}
3800000001
380000000100
3800000001000000
3800000001000000
-
{a=>-36,b=>0}
dcffffff00
dcffffff0000
dcffffff00000000
dcffffff00000000
=
struct umixed3 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>5,a=>-25,b=>4}
e7ffffff2c
e7ffffff2c00
e7ffffff2c000000
e7ffffff2c000000
-
{c=>4,a=>-122,b=>2}
86ffffff22
86ffffff2200
86ffffff22000000
86ffffff22000000
-
{c=>1,a=>-102,b=>1}
9affffff09
9affffff0900
9affffff09000000
9affffff09000000
-
{c=>4,a=>2,b=>3}
0200000023
020000002300
0200000023000000
0200000023000000
-
{c=>4,a=>120,b=>2}
7800000022
780000002200
7800000022000000
7800000022000000
=
struct umixed3 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
};
-
{c=>5,a=>-39,b=>2,d=>0}
d9ffffff2a00000000
d9ffffff2a0000000000
d9ffffff2a00000000000000
d9ffffff2a00000000000000
-
{c=>3,a=>-53,b=>0,d=>4}
cbffffff1804000000
cbffffff180004000000
cbffffff1800000004000000
cbffffff1800000004000000
-
{c=>5,a=>-104,b=>4,d=>7}
98ffffff2c07000000
98ffffff2c0007000000
98ffffff2c00000007000000
98ffffff2c00000007000000
-
{c=>6,a=>-123,b=>4,d=>2}
85ffffff3402000000
85ffffff340002000000
85ffffff3400000002000000
85ffffff3400000002000000
-
{c=>3,a=>-127,b=>3,d=>6}
81ffffff1b06000000
81ffffff1b0006000000
81ffffff1b00000006000000
81ffffff1b00000006000000
=
struct umixed3 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
};
-
{e=>6,c=>5,a=>61,b=>1,d=>1}
3d000000290100000006
3d0000002900010000000600
3d000000290000000100000006000000
3d000000290000000100000006000000
-
{e=>7,c=>2,a=>72,b=>7,d=>7}
48000000170700000007
480000001700070000000700
48000000170000000700000007000000
48000000170000000700000007000000
-
{e=>6,c=>1,a=>33,b=>1,d=>5}
21000000090500000006
210000000900050000000600
21000000090000000500000006000000
21000000090000000500000006000000
-
{e=>1,c=>5,a=>59,b=>3,d=>6}
3b0000002b0600000001
3b0000002b00060000000100
3b0000002b0000000600000001000000
3b0000002b0000000600000001000000
-
{e=>5,c=>7,a=>-74,b=>4,d=>1}
b6ffffff3c0100000005
b6ffffff3c00010000000500
b6ffffff3c0000000100000005000000
b6ffffff3c0000000100000005000000
=
struct umixed3 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
};
-
{e=>2,c=>0,a=>72,b=>0,d=>6,f=>6}
480000000006000000020600
4800000000000600000002000600
48000000000000000600000002000600
48000000000000000600000002000600
-
{e=>1,c=>6,a=>-5,b=>3,d=>2,f=>4}
fbffffff3302000000010400
fbffffff33000200000001000400
fbffffff330000000200000001000400
fbffffff330000000200000001000400
-
{e=>3,c=>4,a=>-25,b=>7,d=>2,f=>1}
e7ffffff2702000000030100
e7ffffff27000200000003000100
e7ffffff270000000200000003000100
e7ffffff270000000200000003000100
-
{e=>6,c=>2,a=>127,b=>5,d=>2,f=>0}
7f0000001502000000060000
7f00000015000200000006000000
7f000000150000000200000006000000
7f000000150000000200000006000000
-
{e=>1,c=>2,a=>-28,b=>2,d=>6,f=>6}
e4ffffff1206000000010600
e4ffffff12000600000001000600
e4ffffff120000000600000001000600
e4ffffff120000000600000001000600
=
struct umixed3 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
  unsigned char  g:3;
};
-
{e=>5,c=>0,a=>-20,g=>4,b=>1,d=>6,f=>7}
ecffffff010600000005070004
ecffffff010006000000050007000400
ecffffff01000000060000000500070004000000
ecffffff01000000060000000500070004000000
-
{e=>6,c=>7,a=>89,g=>0,b=>6,d=>5,f=>4}
590000003e0500000006040000
590000003e0005000000060004000000
590000003e000000050000000600040000000000
590000003e000000050000000600040000000000
-
{e=>2,c=>7,a=>75,g=>1,b=>0,d=>5,f=>5}
4b000000380500000002050001
4b000000380005000000020005000100
4b00000038000000050000000200050001000000
4b00000038000000050000000200050001000000
-
{e=>5,c=>6,a=>-7,g=>2,b=>2,d=>4,f=>2}
f9ffffff320400000005020002
f9ffffff320004000000050002000200
f9ffffff32000000040000000500020002000000
f9ffffff32000000040000000500020002000000
-
{e=>0,c=>5,a=>-93,g=>6,b=>5,d=>1,f=>2}
a3ffffff2d0100000000020006
a3ffffff2d0001000000000002000600
a3ffffff2d000000010000000000020006000000
a3ffffff2d000000010000000000020006000000
=
struct umixed3 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned int   d:3;
  unsigned char  e:3;
  unsigned short f:3;
  unsigned char  g:3;
  unsigned long  h;
};
-
{e=>7,a=>-73,d=>5,c=>2,h=>27,b=>3,g=>0,f=>5}
b7ffffff1305000000070500001b000000
b7ffffff1300050000000700050000001b000000
b7ffffff130000000500000007000500000000001b000000
b7ffffff130000000500000007000500000000001b000000
-
{e=>5,a=>-115,d=>0,c=>4,h=>51,b=>2,g=>3,f=>6}
8dffffff22000000000506000333000000
8dffffff22000000000005000600030033000000
8dffffff2200000000000000050006000300000033000000
8dffffff2200000000000000050006000300000033000000
-
{e=>4,a=>20,d=>0,c=>2,h=>56,b=>5,g=>7,f=>4}
1400000015000000000404000738000000
1400000015000000000004000400070038000000
140000001500000000000000040004000700000038000000
140000001500000000000000040004000700000038000000
-
{e=>6,a=>115,d=>7,c=>2,h=>157,b=>2,g=>0,f=>3}
730000001207000000060300009d000000
730000001200070000000600030000009d000000
73000000120000000700000006000300000000009d000000
73000000120000000700000006000300000000009d000000
-
{e=>1,a=>101,d=>4,c=>2,h=>189,b=>7,g=>1,f=>6}
65000000170400000001060001bd000000
65000000170004000000010006000100bd000000
6500000017000000040000000100060001000000bd000000
6500000017000000040000000100060001000000bd000000
=
struct umixed_no_pack {
  unsigned char  a:3;
};
-
{a=>2}
02
02
02
02
-
{a=>3}
03
03
03
03
-
{a=>0}
00
00
00
00
-
{a=>6}
06
06
06
06
-
{a=>5}
05
05
05
05
=
struct umixed_no_pack {
  unsigned char  a:3;
  unsigned char  b:3;
};
-
{a=>3,b=>4}
23
23
23
23
-
{a=>4,b=>4}
24
24
24
24
-
{a=>0,b=>0}
00
00
00
00
-
{a=>6,b=>0}
06
06
06
06
-
{a=>7,b=>2}
17
17
17
17
=
struct umixed_no_pack {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
};
-
{c=>2,a=>4,b=>5}
2c0200
2c000200
2c000200
2c000200
-
{c=>6,a=>2,b=>7}
3a0600
3a000600
3a000600
3a000600
-
{c=>5,a=>1,b=>5}
290500
29000500
29000500
29000500
-
{c=>5,a=>1,b=>5}
290500
29000500
29000500
29000500
-
{c=>6,a=>2,b=>0}
020600
02000600
02000600
02000600
=
struct umixed_no_pack {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
};
-
{c=>2,a=>3,b=>4,d=>16659437}
230200ed33fe00
23000200ed33fe00
23000200ed33fe00
23000200ed33fe00
-
{c=>7,a=>2,b=>3,d=>201260983}
1a0700b7fffe0b
1a000700b7fffe0b
1a000700b7fffe0b
1a000700b7fffe0b
-
{c=>1,a=>6,b=>3,d=>256219575}
1e0100b799450f
1e000100b799450f
1e000100b799450f
1e000100b799450f
-
{c=>7,a=>6,b=>0,d=>55997687}
060700f7745603
06000700f7745603
06000700f7745603
06000700f7745603
-
{c=>2,a=>4,b=>4,d=>103672891}
2402003bec2d06
240002003bec2d06
240002003bec2d06
240002003bec2d06
=
struct umixed_no_pack {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
};
-
{e=>4,c=>3,a=>3,b=>1,d=>63303944}
0b030008f1c50304
0b00030008f1c5030400
0b00030008f1c50304000000
0b00030008f1c50304000000
-
{e=>6,c=>1,a=>7,b=>5,d=>115286698}
2f0100aa22df0606
2f000100aa22df060600
2f000100aa22df0606000000
2f000100aa22df0606000000
-
{e=>5,c=>7,a=>5,b=>1,d=>33758906}
0d0700ba1e030205
0d000700ba1e03020500
0d000700ba1e030205000000
0d000700ba1e030205000000
-
{e=>1,c=>7,a=>2,b=>1,d=>75998826}
0a07006aa6870401
0a0007006aa687040100
0a0007006aa6870401000000
0a0007006aa6870401000000
-
{e=>0,c=>4,a=>2,b=>7,d=>23580046}
3a04008ecd670100
3a0004008ecd67010000
3a0004008ecd670100000000
3a0004008ecd670100000000
=
struct umixed_no_pack {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
};
-
{e=>1,c=>0,a=>2,b=>7,d=>158148049,f=>0}
3a0000d1256d0901
3a000000d1256d090100
3a000000d1256d0901000000
3a000000d1256d0901000000
-
{e=>3,c=>1,a=>1,b=>7,d=>228592629,f=>0}
390100f50ba00d03
39000100f50ba00d0300
39000100f50ba00d03000000
39000100f50ba00d03000000
-
{e=>6,c=>5,a=>5,b=>6,d=>13400160,f=>0}
3505006078cc0006
350005006078cc000600
350005006078cc0006000000
350005006078cc0006000000
-
{e=>1,c=>2,a=>1,b=>1,d=>252868262,f=>3}
090200a676120f19
09000200a676120f1900
09000200a676120f19000000
09000200a676120f19000000
-
{e=>6,c=>3,a=>3,b=>0,d=>45793175,f=>0}
03030097bfba0206
0300030097bfba020600
0300030097bfba0206000000
0300030097bfba0206000000
=
struct umixed_no_pack {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
  unsigned short g:13;
};
-
{e=>1,c=>2,a=>6,g=>1699,b=>6,d=>41631336,f=>2}
360200683e7b0211a306
36000200683e7b021100a306
36000200683e7b021100a306
36000200683e7b021100a306
-
{e=>2,c=>0,a=>2,g=>602,b=>2,d=>186423654,f=>2}
12000066991c0b125a02
1200000066991c0b12005a02
1200000066991c0b12005a02
1200000066991c0b12005a02
-
{e=>2,c=>7,a=>4,g=>6342,b=>7,d=>247473427,f=>2}
3c07001325c00e12c618
3c0007001325c00e1200c618
3c0007001325c00e1200c618
3c0007001325c00e1200c618
-
{e=>5,c=>7,a=>4,g=>2765,b=>7,d=>238172392,f=>1}
3c0700e838320e0dcd0a
3c000700e838320e0d00cd0a
3c000700e838320e0d00cd0a
3c000700e838320e0d00cd0a
-
{e=>1,c=>7,a=>1,g=>5584,b=>7,d=>2742541,f=>3}
3907000dd9290019d015
390007000dd929001900d015
390007000dd929001900d015
390007000dd929001900d015
=
struct umixed_no_pack {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
  unsigned short g:13;
  signed   int   h;
};
-
{e=>5,a=>0,d=>63927408,c=>7,h=>-86,b=>6,g=>5835,f=>1}
3007007074cf030dcb16aaffffff
300007007074cf030d00cb16aaffffff
300007007074cf030d00cb16aaffffff
300007007074cf030d00cb16aaffffff
-
{e=>7,a=>3,d=>165783275,c=>6,h=>-85,b=>5,g=>3147,f=>0}
2b0600eba6e109074b0cabffffff
2b000600eba6e10907004b0cabffffff
2b000600eba6e10907004b0cabffffff
2b000600eba6e10907004b0cabffffff
-
{e=>7,a=>0,d=>262181766,c=>7,h=>-76,b=>2,g=>3227,f=>0}
1007008693a00f079b0cb4ffffff
100007008693a00f07009b0cb4ffffff
100007008693a00f07009b0cb4ffffff
100007008693a00f07009b0cb4ffffff
-
{e=>2,a=>1,d=>258295770,c=>1,h=>-44,b=>2,g=>2696,f=>2}
110100da47650f12880ad4ffffff
11000100da47650f1200880ad4ffffff
11000100da47650f1200880ad4ffffff
11000100da47650f1200880ad4ffffff
-
{e=>6,a=>7,d=>149674579,c=>6,h=>44,b=>7,g=>3480,f=>1}
3f060053daeb080e980d2c000000
3f00060053daeb080e00980d2c000000
3f00060053daeb080e00980d2c000000
3f00060053daeb080e00980d2c000000
=
struct umixed_no_pack {
  char a;
  unsigned char  b:3;
};
-
{a=>18,b=>7}
1207
1207
1207
1207
-
{a=>-34,b=>4}
de04
de04
de04
de04
-
{a=>-63,b=>4}
c104
c104
c104
c104
-
{a=>-10,b=>4}
f604
f604
f604
f604
-
{a=>117,b=>1}
7501
7501
7501
7501
=
struct umixed_no_pack {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>4,a=>-68,b=>6}
bc26
bc26
bc26
bc26
-
{c=>7,a=>48,b=>6}
303e
303e
303e
303e
-
{c=>7,a=>124,b=>0}
7c38
7c38
7c38
7c38
-
{c=>7,a=>111,b=>4}
6f3c
6f3c
6f3c
6f3c
-
{c=>5,a=>-83,b=>1}
ad29
ad29
ad29
ad29
=
struct umixed_no_pack {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>2,a=>116,b=>6,d=>5}
74160500
74160500
74160500
74160500
-
{c=>0,a=>-85,b=>7,d=>7}
ab070700
ab070700
ab070700
ab070700
-
{c=>7,a=>13,b=>7,d=>6}
0d3f0600
0d3f0600
0d3f0600
0d3f0600
-
{c=>6,a=>118,b=>4,d=>6}
76340600
76340600
76340600
76340600
-
{c=>3,a=>59,b=>4,d=>5}
3b1c0500
3b1c0500
3b1c0500
3b1c0500
=
struct umixed_no_pack {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>27672616,c=>4,a=>110,b=>5,d=>2}
6e2502002840a601
6e2502002840a601
6e2502002840a601
6e2502002840a601
-
{e=>87433172,c=>4,a=>106,b=>7,d=>5}
6a270500d41f3605
6a270500d41f3605
6a270500d41f3605
6a270500d41f3605
-
{e=>33757072,c=>4,a=>-72,b=>4,d=>2}
b824020090170302
b824020090170302
b824020090170302
b824020090170302
-
{e=>12459290,c=>0,a=>49,b=>7,d=>0}
310700001a1dbe00
310700001a1dbe00
310700001a1dbe00
310700001a1dbe00
-
{e=>265383931,c=>3,a=>-91,b=>4,d=>1}
a51c0100fb6fd10f
a51c0100fb6fd10f
a51c0100fb6fd10f
a51c0100fb6fd10f
=
struct umixed_no_pack {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>121017809,c=>3,a=>-127,b=>5,d=>0,f=>6}
811d0000d195360706
811d0000d19536070600
811d0000d195360706000000
811d0000d195360706000000
-
{e=>38181014,c=>5,a=>-86,b=>4,d=>3,f=>1}
aa2c03009698460201
aa2c0300969846020100
aa2c03009698460201000000
aa2c03009698460201000000
-
{e=>206063701,c=>2,a=>-126,b=>5,d=>3,f=>4}
821503005548480c04
821503005548480c0400
821503005548480c04000000
821503005548480c04000000
-
{e=>102799155,c=>1,a=>-102,b=>5,d=>0,f=>1}
9a0d00003397200601
9a0d0000339720060100
9a0d00003397200601000000
9a0d00003397200601000000
-
{e=>35733158,c=>5,a=>48,b=>7,d=>5,f=>4}
302f0500a63e210204
302f0500a63e21020400
302f0500a63e210204000000
302f0500a63e210204000000
=
struct umixed_no_pack {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>259030873,c=>6,a=>-99,g=>3,b=>6,d=>6,f=>7}
9d360600597f700f1f
9d360600597f700f1f00
9d360600597f700f1f000000
9d360600597f700f1f000000
-
{e=>113534093,c=>3,a=>-82,g=>1,b=>7,d=>1,f=>1}
ae1f01008d64c40609
ae1f01008d64c4060900
ae1f01008d64c40609000000
ae1f01008d64c40609000000
-
{e=>196254634,c=>6,a=>-82,g=>0,b=>2,d=>5,f=>3}
ae320500aa9bb20b03
ae320500aa9bb20b0300
ae320500aa9bb20b03000000
ae320500aa9bb20b03000000
-
{e=>211207759,c=>7,a=>26,g=>3,b=>3,d=>6,f=>4}
1a3b06004fc6960c1c
1a3b06004fc6960c1c00
1a3b06004fc6960c1c000000
1a3b06004fc6960c1c000000
-
{e=>35365642,c=>5,a=>-40,g=>0,b=>6,d=>0,f=>6}
d82e00000aa31b0206
d82e00000aa31b020600
d82e00000aa31b0206000000
d82e00000aa31b0206000000
=
struct umixed_no_pack {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>95421875,a=>113,d=>4,c=>0,h=>6613,b=>1,g=>2,f=>5}
71010400b305b00515d519
71010400b305b0051500d519
71010400b305b0051500d519
71010400b305b0051500d519
-
{e=>219735823,a=>24,d=>6,c=>5,h=>3918,b=>5,g=>1,f=>0}
182d06000fe7180d084e0f
182d06000fe7180d08004e0f
182d06000fe7180d08004e0f
182d06000fe7180d08004e0f
-
{e=>114141874,a=>-127,d=>4,c=>4,h=>3018,b=>0,g=>0,f=>2}
81200400b2aacd0602ca0b
81200400b2aacd060200ca0b
81200400b2aacd060200ca0b
81200400b2aacd060200ca0b
-
{e=>116157792,a=>52,d=>7,c=>1,h=>7261,b=>4,g=>0,f=>5}
340c0700606dec06055d1c
340c0700606dec0605005d1c
340c0700606dec0605005d1c
340c0700606dec0605005d1c
-
{e=>164478627,a=>-23,d=>7,c=>1,h=>2155,b=>4,g=>3,f=>7}
e90c0700a3becd091f6b08
e90c0700a3becd091f006b08
e90c0700a3becd091f006b08
e90c0700a3becd091f006b08
=
struct umixed_no_pack {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  signed   int   i;
};
-
{e=>31308849,a=>-51,d=>6,c=>1,h=>3257,b=>7,g=>2,f=>6,i=>35}
cd0f060031bcdd0116b90c23000000
cd0f060031bcdd011600b90c23000000
cd0f060031bcdd011600b90c23000000
cd0f060031bcdd011600b90c23000000
-
{e=>200850095,a=>59,d=>3,c=>5,h=>4223,b=>2,g=>3,f=>7,i=>-30}
3b2a0300afbaf80b1f7f10e2ffffff
3b2a0300afbaf80b1f007f10e2ffffff
3b2a0300afbaf80b1f007f10e2ffffff
3b2a0300afbaf80b1f007f10e2ffffff
-
{e=>2384984,a=>-78,d=>5,c=>3,h=>4113,b=>0,g=>3,f=>7,i=>33}
b2180500586424001f111021000000
b2180500586424001f00111021000000
b2180500586424001f00111021000000
b2180500586424001f00111021000000
-
{e=>170834401,a=>-122,d=>7,c=>0,h=>305,b=>5,g=>1,f=>3,i=>93}
86050700e1b92e0a0b31015d000000
86050700e1b92e0a0b0031015d000000
86050700e1b92e0a0b0031015d000000
86050700e1b92e0a0b0031015d000000
-
{e=>202616049,a=>-1,d=>7,c=>3,h=>4385,b=>5,g=>3,f=>0,i=>101}
ff1d0700f1ac130c18211165000000
ff1d0700f1ac130c1800211165000000
ff1d0700f1ac130c1800211165000000
ff1d0700f1ac130c1800211165000000
=
struct umixed_no_pack {
  short a;
  unsigned char  b:3;
};
-
{a=>-23,b=>3}
e9ff03
e9ff0300
e9ff0300
e9ff0300
-
{a=>-90,b=>7}
a6ff07
a6ff0700
a6ff0700
a6ff0700
-
{a=>33,b=>2}
210002
21000200
21000200
21000200
-
{a=>-4,b=>6}
fcff06
fcff0600
fcff0600
fcff0600
-
{a=>-31,b=>5}
e1ff05
e1ff0500
e1ff0500
e1ff0500
=
struct umixed_no_pack {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>4,a=>-107,b=>7}
95ff27
95ff2700
95ff2700
95ff2700
-
{c=>7,a=>6,b=>0}
060038
06003800
06003800
06003800
-
{c=>7,a=>47,b=>6}
2f003e
2f003e00
2f003e00
2f003e00
-
{c=>2,a=>-33,b=>2}
dfff12
dfff1200
dfff1200
dfff1200
-
{c=>2,a=>-93,b=>3}
a3ff13
a3ff1300
a3ff1300
a3ff1300
=
struct umixed_no_pack {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>4,a=>35,b=>3,d=>7}
2300230700
230023000700
230023000700
230023000700
-
{c=>1,a=>-77,b=>0,d=>4}
b3ff080400
b3ff08000400
b3ff08000400
b3ff08000400
-
{c=>4,a=>-88,b=>6,d=>0}
a8ff260000
a8ff26000000
a8ff26000000
a8ff26000000
-
{c=>2,a=>-10,b=>6,d=>4}
f6ff160400
f6ff16000400
f6ff16000400
f6ff16000400
-
{c=>2,a=>17,b=>4,d=>3}
1100140300
110014000300
110014000300
110014000300
=
struct umixed_no_pack {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>230924365,c=>5,a=>-34,b=>0,d=>1}
deff2801004da0c30d
deff280001004da0c30d
deff2800010000004da0c30d
deff2800010000004da0c30d
-
{e=>235124443,c=>6,a=>-25,b=>1,d=>0}
e7ff310000dbb6030e
e7ff31000000dbb6030e
e7ff310000000000dbb6030e
e7ff310000000000dbb6030e
-
{e=>218139234,c=>4,a=>-11,b=>4,d=>6}
f5ff240600628a000d
f5ff24000600628a000d
f5ff240006000000628a000d
f5ff240006000000628a000d
-
{e=>96460758,c=>3,a=>-25,b=>1,d=>3}
e7ff190300d6dfbf05
e7ff19000300d6dfbf05
e7ff190003000000d6dfbf05
e7ff190003000000d6dfbf05
-
{e=>143236939,c=>5,a=>117,b=>3,d=>0}
75002b00004b9f8908
75002b0000004b9f8908
75002b00000000004b9f8908
75002b00000000004b9f8908
=
struct umixed_no_pack {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>81182875,c=>2,a=>49,b=>2,d=>5,f=>3}
31001205009bc0d60403
3100120005009bc0d6040300
31001200050000009bc0d60403000000
31001200050000009bc0d60403000000
-
{e=>165824077,c=>1,a=>51,b=>0,d=>0,f=>4}
33000800004d46e20904
3300080000004d46e2090400
33000800000000004d46e20904000000
33000800000000004d46e20904000000
-
{e=>20080403,c=>1,a=>41,b=>4,d=>7,f=>6}
29000c07001367320106
29000c000700136732010600
29000c00070000001367320106000000
29000c00070000001367320106000000
-
{e=>100629693,c=>0,a=>61,b=>6,d=>6,f=>1}
3d00060600bd7cff0501
3d0006000600bd7cff050100
3d00060006000000bd7cff0501000000
3d00060006000000bd7cff0501000000
-
{e=>190350127,c=>5,a=>-101,b=>6,d=>0,f=>3}
9bff2e00002f83580b03
9bff2e0000002f83580b0300
9bff2e00000000002f83580b03000000
9bff2e00000000002f83580b03000000
=
struct umixed_no_pack {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>227828092,c=>0,a=>-16,g=>2,b=>1,d=>0,f=>0}
f0ff0100007c61940d10
f0ff010000007c61940d1000
f0ff0100000000007c61940d10000000
f0ff0100000000007c61940d10000000
-
{e=>182355747,c=>1,a=>112,g=>0,b=>0,d=>3,f=>7}
70000803002387de0a07
7000080003002387de0a0700
70000800030000002387de0a07000000
70000800030000002387de0a07000000
-
{e=>183757219,c=>3,a=>117,g=>3,b=>6,d=>6,f=>2}
75001e0600a3e9f30a1a
75001e000600a3e9f30a1a00
75001e0006000000a3e9f30a1a000000
75001e0006000000a3e9f30a1a000000
-
{e=>250036859,c=>6,a=>66,g=>1,b=>2,d=>0,f=>6}
42003200007b42e70e0e
4200320000007b42e70e0e00
42003200000000007b42e70e0e000000
42003200000000007b42e70e0e000000
-
{e=>238803723,c=>4,a=>110,g=>0,b=>1,d=>6,f=>1}
6e002106000bdb3b0e01
6e00210006000bdb3b0e0100
6e002100060000000bdb3b0e01000000
6e002100060000000bdb3b0e01000000
=
struct umixed_no_pack {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>123354721,a=>77,d=>1,c=>5,h=>6510,b=>2,g=>2,f=>7}
4d002a0100613e5a07176e19
4d002a000100613e5a0717006e19
4d002a0001000000613e5a0717006e19
4d002a0001000000613e5a0717006e19
-
{e=>6270702,a=>72,d=>1,c=>2,h=>3832,b=>3,g=>1,f=>4}
4800130100eeae5f000cf80e
480013000100eeae5f000c00f80e
4800130001000000eeae5f000c00f80e
4800130001000000eeae5f000c00f80e
-
{e=>151397274,a=>-111,d=>6,c=>7,h=>1061,b=>6,g=>3,f=>3}
91ff3e06009a2306091b2504
91ff3e0006009a2306091b002504
91ff3e00060000009a2306091b002504
91ff3e00060000009a2306091b002504
-
{e=>139689776,a=>26,d=>3,c=>0,h=>1364,b=>6,g=>1,f=>4}
1a00060300307f53080c5405
1a0006000300307f53080c005405
1a00060003000000307f53080c005405
1a00060003000000307f53080c005405
-
{e=>36719821,a=>73,d=>2,c=>4,h=>2049,b=>7,g=>2,f=>3}
4900270200cd4c3002130108
490027000200cd4c300213000108
4900270002000000cd4c300213000108
4900270002000000cd4c300213000108
=
struct umixed_no_pack {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  signed   int   i;
};
-
{e=>80052423,a=>38,d=>7,c=>5,h=>719,b=>0,g=>1,f=>2,i=>58}
2600280700c780c5040acf023a000000
260028000700c780c5040a00cf023a000000
2600280007000000c780c5040a00cf023a000000
2600280007000000c780c5040a00cf023a000000
-
{e=>84879964,a=>-58,d=>2,c=>2,h=>7754,b=>5,g=>2,f=>6,i=>3}
c6ff1502005c2a0f05164a1e03000000
c6ff150002005c2a0f0516004a1e03000000
c6ff1500020000005c2a0f0516004a1e03000000
c6ff1500020000005c2a0f0516004a1e03000000
-
{e=>208832370,a=>-38,d=>5,c=>6,h=>7000,b=>7,g=>3,f=>1,i=>27}
daff3705007287720c19581b1b000000
daff370005007287720c1900581b1b000000
daff3700050000007287720c1900581b1b000000
daff3700050000007287720c1900581b1b000000
-
{e=>224138316,a=>99,d=>4,c=>7,h=>2886,b=>1,g=>1,f=>2,i=>-60}
63003904004c145c0d0a460bc4ffffff
6300390004004c145c0d0a00460bc4ffffff
63003900040000004c145c0d0a00460bc4ffffff
63003900040000004c145c0d0a00460bc4ffffff
-
{e=>208271774,a=>61,d=>7,c=>5,h=>4345,b=>5,g=>1,f=>2,i=>-10}
3d002d07009ef9690c0af910f6ffffff
3d002d0007009ef9690c0a00f910f6ffffff
3d002d00070000009ef9690c0a00f910f6ffffff
3d002d00070000009ef9690c0a00f910f6ffffff
=
struct umixed_no_pack {
  int a;
  unsigned char  b:3;
};
-
{a=>77,b=>5}
4d00000005
4d0000000500
4d00000005000000
4d00000005000000
-
{a=>-91,b=>1}
a5ffffff01
a5ffffff0100
a5ffffff01000000
a5ffffff01000000
-
{a=>42,b=>3}
2a00000003
2a0000000300
2a00000003000000
2a00000003000000
-
{a=>-15,b=>3}
f1ffffff03
f1ffffff0300
f1ffffff03000000
f1ffffff03000000
-
{a=>-34,b=>2}
deffffff02
deffffff0200
deffffff02000000
deffffff02000000
=
struct umixed_no_pack {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>0,a=>123,b=>7}
7b00000007
7b0000000700
7b00000007000000
7b00000007000000
-
{c=>5,a=>35,b=>6}
230000002e
230000002e00
230000002e000000
230000002e000000
-
{c=>3,a=>-76,b=>4}
b4ffffff1c
b4ffffff1c00
b4ffffff1c000000
b4ffffff1c000000
-
{c=>6,a=>84,b=>4}
5400000034
540000003400
5400000034000000
5400000034000000
-
{c=>5,a=>-26,b=>5}
e6ffffff2d
e6ffffff2d00
e6ffffff2d000000
e6ffffff2d000000
=
struct umixed_no_pack {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>6,a=>89,b=>0,d=>2}
59000000300200
5900000030000200
5900000030000200
5900000030000200
-
{c=>2,a=>71,b=>6,d=>6}
47000000160600
4700000016000600
4700000016000600
4700000016000600
-
{c=>6,a=>43,b=>6,d=>4}
2b000000360400
2b00000036000400
2b00000036000400
2b00000036000400
-
{c=>7,a=>74,b=>6,d=>1}
4a0000003e0100
4a0000003e000100
4a0000003e000100
4a0000003e000100
-
{c=>1,a=>24,b=>1,d=>7}
18000000090700
1800000009000700
1800000009000700
1800000009000700
=
struct umixed_no_pack {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>258411058,c=>2,a=>-56,b=>3,d=>1}
c8ffffff130100320a670f
c8ffffff13000100320a670f
c8ffffff13000100320a670f
c8ffffff13000100320a670f
-
{e=>192775493,c=>2,a=>6,b=>7,d=>4}
0600000017040045857d0b
060000001700040045857d0b
060000001700040045857d0b
060000001700040045857d0b
-
{e=>70245712,c=>3,a=>-1,b=>7,d=>1}
ffffffff1f010050dd2f04
ffffffff1f00010050dd2f04
ffffffff1f00010050dd2f04
ffffffff1f00010050dd2f04
-
{e=>100376726,c=>7,a=>115,b=>0,d=>7}
7300000038070096a0fb05
730000003800070096a0fb05
730000003800070096a0fb05
730000003800070096a0fb05
-
{e=>261070995,c=>7,a=>-47,b=>1,d=>0}
d1ffffff39000093a08f0f
d1ffffff3900000093a08f0f
d1ffffff3900000093a08f0f
d1ffffff3900000093a08f0f
=
struct umixed_no_pack {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>202903687,c=>1,a=>-41,b=>7,d=>0,f=>7}
d7ffffff0f00008710180c07
d7ffffff0f0000008710180c0700
d7ffffff0f0000008710180c07000000
d7ffffff0f0000008710180c07000000
-
{e=>156182618,c=>1,a=>83,b=>7,d=>1,f=>1}
530000000f01005a284f0901
530000000f0001005a284f090100
530000000f0001005a284f0901000000
530000000f0001005a284f0901000000
-
{e=>30752427,c=>5,a=>-26,b=>6,d=>3,f=>6}
e6ffffff2e0300ab3ed50106
e6ffffff2e000300ab3ed5010600
e6ffffff2e000300ab3ed50106000000
e6ffffff2e000300ab3ed50106000000
-
{e=>13986533,c=>2,a=>73,b=>0,d=>3,f=>0}
49000000100300e56ad50000
4900000010000300e56ad5000000
4900000010000300e56ad50000000000
4900000010000300e56ad50000000000
-
{e=>97832562,c=>7,a=>67,b=>3,d=>1,f=>6}
430000003b010072ced40506
430000003b00010072ced4050600
430000003b00010072ced40506000000
430000003b00010072ced40506000000
=
struct umixed_no_pack {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>224204808,c=>0,a=>-125,g=>3,b=>2,d=>6,f=>5}
83ffffff02060008185d0d1d
83ffffff0200060008185d0d1d00
83ffffff0200060008185d0d1d000000
83ffffff0200060008185d0d1d000000
-
{e=>248110203,c=>2,a=>32,g=>2,b=>2,d=>2,f=>2}
200000001202007bdcc90e12
20000000120002007bdcc90e1200
20000000120002007bdcc90e12000000
20000000120002007bdcc90e12000000
-
{e=>176808355,c=>3,a=>74,g=>3,b=>7,d=>1,f=>0}
4a0000001f0100a3e1890a18
4a0000001f000100a3e1890a1800
4a0000001f000100a3e1890a18000000
4a0000001f000100a3e1890a18000000
-
{e=>200366377,c=>3,a=>-125,g=>2,b=>4,d=>6,f=>4}
83ffffff1c06002959f10b14
83ffffff1c0006002959f10b1400
83ffffff1c0006002959f10b14000000
83ffffff1c0006002959f10b14000000
-
{e=>40965455,c=>3,a=>107,g=>2,b=>0,d=>3,f=>4}
6b0000001803004f15710214
6b000000180003004f1571021400
6b000000180003004f15710214000000
6b000000180003004f15710214000000
=
struct umixed_no_pack {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>261834522,a=>113,d=>2,c=>3,h=>1720,b=>5,g=>2,f=>7}
710000001d02001a479b0f17b806
710000001d0002001a479b0f1700b806
710000001d0002001a479b0f1700b806
710000001d0002001a479b0f1700b806
-
{e=>81177197,a=>52,d=>7,c=>0,h=>7442,b=>0,g=>0,f=>3}
340000000007006daad60403121d
34000000000007006daad6040300121d
34000000000007006daad6040300121d
34000000000007006daad6040300121d
-
{e=>252859983,a=>117,d=>4,c=>2,h=>3820,b=>7,g=>1,f=>3}
750000001704004f56120f0bec0e
75000000170004004f56120f0b00ec0e
75000000170004004f56120f0b00ec0e
75000000170004004f56120f0b00ec0e
-
{e=>260755755,a=>39,d=>6,c=>3,h=>5333,b=>4,g=>1,f=>6}
270000001c06002bd18a0f0ed514
270000001c0006002bd18a0f0e00d514
270000001c0006002bd18a0f0e00d514
270000001c0006002bd18a0f0e00d514
-
{e=>197646476,a=>44,d=>1,c=>0,h=>1255,b=>0,g=>1,f=>7}
2c0000000001008cd8c70b0fe704
2c000000000001008cd8c70b0f00e704
2c000000000001008cd8c70b0f00e704
2c000000000001008cd8c70b0f00e704
=
struct umixed_no_pack {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  signed   int   i;
};
-
{e=>3714946,a=>-88,d=>6,c=>2,h=>3065,b=>4,g=>0,f=>1,i=>-7}
a8ffffff14060082af380001f90bf9ffffff
a8ffffff1400060082af38000100f90bf9ffffff
a8ffffff1400060082af38000100f90bf9ffffff
a8ffffff1400060082af38000100f90bf9ffffff
-
{e=>217660046,a=>63,d=>4,c=>2,h=>4968,b=>5,g=>3,f=>5,i=>-17}
3f0000001504008e3af90c1d6813efffffff
3f000000150004008e3af90c1d006813efffffff
3f000000150004008e3af90c1d006813efffffff
3f000000150004008e3af90c1d006813efffffff
-
{e=>50265395,a=>101,d=>1,c=>3,h=>1816,b=>7,g=>1,f=>7,i=>113}
650000001f010033fdfe020f180771000000
650000001f00010033fdfe020f00180771000000
650000001f00010033fdfe020f00180771000000
650000001f00010033fdfe020f00180771000000
-
{e=>165795744,a=>11,d=>5,c=>4,h=>2771,b=>2,g=>3,f=>6,i=>-6}
0b000000220500a0d7e1091ed30afaffffff
0b00000022000500a0d7e1091e00d30afaffffff
0b00000022000500a0d7e1091e00d30afaffffff
0b00000022000500a0d7e1091e00d30afaffffff
-
{e=>246643849,a=>56,d=>5,c=>2,h=>3254,b=>0,g=>3,f=>7,i=>-43}
38000000100500897cb30e1fb60cd5ffffff
3800000010000500897cb30e1f00b60cd5ffffff
3800000010000500897cb30e1f00b60cd5ffffff
3800000010000500897cb30e1f00b60cd5ffffff
=
struct umixed_no_pack {
  long a;
  unsigned char  b:3;
};
-
{a=>-22,b=>3}
eaffffff03
eaffffff0300
eaffffff03000000
eaffffff03000000
-
{a=>15,b=>0}
0f00000000
0f0000000000
0f00000000000000
0f00000000000000
-
{a=>-58,b=>4}
c6ffffff04
c6ffffff0400
c6ffffff04000000
c6ffffff04000000
-
{a=>39,b=>0}
2700000000
270000000000
2700000000000000
2700000000000000
-
{a=>55,b=>0}
3700000000
370000000000
3700000000000000
3700000000000000
=
struct umixed_no_pack {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>6,a=>53,b=>3}
3500000033
350000003300
3500000033000000
3500000033000000
-
{c=>6,a=>-101,b=>4}
9bffffff34
9bffffff3400
9bffffff34000000
9bffffff34000000
-
{c=>6,a=>62,b=>1}
3e00000031
3e0000003100
3e00000031000000
3e00000031000000
-
{c=>5,a=>-63,b=>5}
c1ffffff2d
c1ffffff2d00
c1ffffff2d000000
c1ffffff2d000000
-
{c=>2,a=>26,b=>4}
1a00000014
1a0000001400
1a00000014000000
1a00000014000000
=
struct umixed_no_pack {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>7,a=>84,b=>5,d=>0}
540000003d0000
540000003d000000
540000003d000000
540000003d000000
-
{c=>2,a=>-4,b=>6,d=>7}
fcffffff160700
fcffffff16000700
fcffffff16000700
fcffffff16000700
-
{c=>0,a=>-1,b=>2,d=>4}
ffffffff020400
ffffffff02000400
ffffffff02000400
ffffffff02000400
-
{c=>5,a=>75,b=>2,d=>1}
4b0000002a0100
4b0000002a000100
4b0000002a000100
4b0000002a000100
-
{c=>1,a=>-35,b=>2,d=>2}
ddffffff0a0200
ddffffff0a000200
ddffffff0a000200
ddffffff0a000200
=
struct umixed_no_pack {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>12846720,c=>5,a=>-2,b=>6,d=>4}
feffffff2e04008006c400
feffffff2e0004008006c400
feffffff2e0004008006c400
feffffff2e0004008006c400
-
{e=>122850482,c=>0,a=>44,b=>4,d=>5}
2c000000040500b28c5207
2c00000004000500b28c5207
2c00000004000500b28c5207
2c00000004000500b28c5207
-
{e=>110531108,c=>0,a=>6,b=>7,d=>5}
0600000007050024929606
060000000700050024929606
060000000700050024929606
060000000700050024929606
-
{e=>172922041,c=>3,a=>-21,b=>6,d=>1}
ebffffff1e0100b9944e0a
ebffffff1e000100b9944e0a
ebffffff1e000100b9944e0a
ebffffff1e000100b9944e0a
-
{e=>55535187,c=>1,a=>-73,b=>2,d=>3}
b7ffffff0a030053664f03
b7ffffff0a00030053664f03
b7ffffff0a00030053664f03
b7ffffff0a00030053664f03
=
struct umixed_no_pack {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>66805985,c=>5,a=>115,b=>6,d=>2,f=>6}
730000002e0200e160fb0306
730000002e000200e160fb030600
730000002e000200e160fb0306000000
730000002e000200e160fb0306000000
-
{e=>217412345,c=>5,a=>83,b=>2,d=>7,f=>1}
530000002a0700f972f50c01
530000002a000700f972f50c0100
530000002a000700f972f50c01000000
530000002a000700f972f50c01000000
-
{e=>143288860,c=>4,a=>80,b=>4,d=>7,f=>2}
500000002407001c6a8a0802
50000000240007001c6a8a080200
50000000240007001c6a8a0802000000
50000000240007001c6a8a0802000000
-
{e=>80533529,c=>3,a=>-56,b=>0,d=>4,f=>3}
c8ffffff18040019d8cc0403
c8ffffff1800040019d8cc040300
c8ffffff1800040019d8cc0403000000
c8ffffff1800040019d8cc0403000000
-
{e=>76049210,c=>4,a=>41,b=>4,d=>0,f=>2}
290000002400003a6b880402
29000000240000003a6b88040200
29000000240000003a6b880402000000
29000000240000003a6b880402000000
=
struct umixed_no_pack {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>33149186,c=>0,a=>-66,g=>2,b=>6,d=>0,f=>2}
beffffff06000002d1f90112
beffffff0600000002d1f9011200
beffffff0600000002d1f90112000000
beffffff0600000002d1f90112000000
-
{e=>24018713,c=>6,a=>42,g=>0,b=>3,d=>1,f=>7}
2a000000330100197f6e0107
2a00000033000100197f6e010700
2a00000033000100197f6e0107000000
2a00000033000100197f6e0107000000
-
{e=>238049791,c=>1,a=>-89,g=>0,b=>5,d=>4,f=>3}
a7ffffff0d0400ff59300e03
a7ffffff0d000400ff59300e0300
a7ffffff0d000400ff59300e03000000
a7ffffff0d000400ff59300e03000000
-
{e=>45452680,c=>4,a=>85,g=>3,b=>5,d=>4,f=>2}
55000000250400888db5021a
5500000025000400888db5021a00
5500000025000400888db5021a000000
5500000025000400888db5021a000000
-
{e=>127560049,c=>0,a=>38,g=>3,b=>5,d=>1,f=>4}
2600000005010071699a071c
260000000500010071699a071c00
260000000500010071699a071c000000
260000000500010071699a071c000000
=
struct umixed_no_pack {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>143259895,a=>-70,d=>4,c=>3,h=>4312,b=>6,g=>0,f=>5}
baffffff1e0400f7f8890805d810
baffffff1e000400f7f889080500d810
baffffff1e000400f7f889080500d810
baffffff1e000400f7f889080500d810
-
{e=>130209381,a=>75,d=>3,c=>6,h=>1172,b=>2,g=>1,f=>0}
4b00000032030065d6c207089404
4b0000003200030065d6c20708009404
4b0000003200030065d6c20708009404
4b0000003200030065d6c20708009404
-
{e=>169515883,a=>36,d=>3,c=>7,h=>7983,b=>7,g=>2,f=>0}
240000003f03006b9b1a0a102f1f
240000003f0003006b9b1a0a10002f1f
240000003f0003006b9b1a0a10002f1f
240000003f0003006b9b1a0a10002f1f
-
{e=>204680465,a=>-15,d=>2,c=>5,h=>8017,b=>2,g=>0,f=>6}
f1ffffff2a0200112d330c06511f
f1ffffff2a000200112d330c0600511f
f1ffffff2a000200112d330c0600511f
f1ffffff2a000200112d330c0600511f
-
{e=>243063688,a=>85,d=>2,c=>6,h=>342,b=>2,g=>0,f=>3}
5500000032020088db7c0e035601
550000003200020088db7c0e03005601
550000003200020088db7c0e03005601
550000003200020088db7c0e03005601
=
struct umixed_no_pack {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  signed   int   i;
};
-
{e=>256419346,a=>25,d=>4,c=>1,h=>4924,b=>3,g=>1,f=>2,i=>-112}
190000000b040012a6480f0a3c1390ffffff
190000000b00040012a6480f0a003c1390ffffff
190000000b00040012a6480f0a003c1390ffffff
190000000b00040012a6480f0a003c1390ffffff
-
{e=>155022430,a=>75,d=>3,c=>2,h=>362,b=>7,g=>2,f=>1,i=>-49}
4b0000001703005e743d09116a01cfffffff
4b000000170003005e743d0911006a01cfffffff
4b000000170003005e743d0911006a01cfffffff
4b000000170003005e743d0911006a01cfffffff
-
{e=>190447867,a=>-73,d=>1,c=>2,h=>2876,b=>7,g=>0,f=>7,i=>1}
b7ffffff170100fb005a0b073c0b01000000
b7ffffff17000100fb005a0b07003c0b01000000
b7ffffff17000100fb005a0b07003c0b01000000
b7ffffff17000100fb005a0b07003c0b01000000
-
{e=>179690236,a=>9,d=>7,c=>0,h=>7267,b=>7,g=>1,f=>0,i=>-85}
09000000070700fcdab50a08631cabffffff
0900000007000700fcdab50a0800631cabffffff
0900000007000700fcdab50a0800631cabffffff
0900000007000700fcdab50a0800631cabffffff
-
{e=>104415787,a=>74,d=>7,c=>3,h=>3028,b=>4,g=>3,f=>7,i=>92}
4a0000001c07002b4239061fd40b5c000000
4a0000001c0007002b4239061f00d40b5c000000
4a0000001c0007002b4239061f00d40b5c000000
4a0000001c0007002b4239061f00d40b5c000000
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  unsigned char  a:3;
};
-
{a=>1}
01
01
01
01
-
{a=>0}
00
00
00
00
-
{a=>1}
01
01
01
01
-
{a=>3}
03
03
03
03
-
{a=>5}
05
05
05
05
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  unsigned char  a:3;
  unsigned char  b:3;
};
-
{a=>4,b=>3}
1c
1c
1c
1c
-
{a=>5,b=>6}
35
35
35
35
-
{a=>1,b=>3}
19
19
19
19
-
{a=>7,b=>6}
37
37
37
37
-
{a=>1,b=>0}
01
01
01
01
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
};
-
{c=>7,a=>2,b=>6}
320700
320700
320700
320700
-
{c=>3,a=>1,b=>4}
210300
210300
210300
210300
-
{c=>0,a=>2,b=>1}
0a0000
0a0000
0a0000
0a0000
-
{c=>7,a=>6,b=>6}
360700
360700
360700
360700
-
{c=>6,a=>5,b=>3}
1d0600
1d0600
1d0600
1d0600
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
};
-
{c=>3,a=>4,b=>6,d=>50977657}
34030079db0903
34030079db0903
34030079db0903
34030079db0903
-
{c=>4,a=>1,b=>0,d=>156580251}
0104009b395509
0104009b395509
0104009b395509
0104009b395509
-
{c=>0,a=>6,b=>1,d=>120765803}
0e00006bbd3207
0e00006bbd3207
0e00006bbd3207
0e00006bbd3207
-
{c=>5,a=>6,b=>4,d=>190259749}
2605002522570b
2605002522570b
2605002522570b
2605002522570b
-
{c=>3,a=>6,b=>1,d=>14877875}
0e0300b304e300
0e0300b304e300
0e0300b304e300
0e0300b304e300
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
};
-
{e=>7,c=>0,a=>5,b=>4,d=>131151049}
250000c934d10707
250000c934d10707
250000c934d10707
250000c934d10707
-
{e=>4,c=>6,a=>0,b=>3,d=>27196562}
18060092fc9e0104
18060092fc9e0104
18060092fc9e0104
18060092fc9e0104
-
{e=>5,c=>2,a=>5,b=>2,d=>79198194}
150200f277b80405
150200f277b80405
150200f277b80405
150200f277b80405
-
{e=>1,c=>6,a=>1,b=>1,d=>53011008}
09060040e2280301
09060040e2280301
09060040e2280301
09060040e2280301
-
{e=>3,c=>0,a=>3,b=>5,d=>229669114}
2b0000fa78b00d03
2b0000fa78b00d03
2b0000fa78b00d03
2b0000fa78b00d03
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
};
-
{e=>7,c=>4,a=>3,b=>2,d=>224213968,f=>0}
130400d03b5d0d07
130400d03b5d0d07
130400d03b5d0d07
130400d03b5d0d07
-
{e=>5,c=>0,a=>6,b=>7,d=>149199438,f=>2}
3e00004e9ae40815
3e00004e9ae40815
3e00004e9ae40815
3e00004e9ae40815
-
{e=>4,c=>7,a=>4,b=>6,d=>212284222,f=>0}
3407003e33a70c04
3407003e33a70c04
3407003e33a70c04
3407003e33a70c04
-
{e=>0,c=>4,a=>1,b=>3,d=>183266435,f=>3}
190400836cec0a18
190400836cec0a18
190400836cec0a18
190400836cec0a18
-
{e=>3,c=>3,a=>2,b=>0,d=>193465720,f=>3}
020300780d880b1b
020300780d880b1b
020300780d880b1b
020300780d880b1b
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
  unsigned short g:13;
};
-
{e=>2,c=>0,a=>4,g=>7279,b=>3,d=>226086089,f=>0}
1c0000c9cc790d026f1c
1c0000c9cc790d026f1c
1c0000c9cc790d026f1c
1c0000c9cc790d026f1c
-
{e=>4,c=>1,a=>5,g=>1474,b=>6,d=>135043372,f=>2}
3501002c990c0814c205
3501002c990c0814c205
3501002c990c0814c205
3501002c990c0814c205
-
{e=>0,c=>2,a=>4,g=>4289,b=>6,d=>167538358,f=>2}
340200b66efc0910c110
340200b66efc0910c110
340200b66efc0910c110
340200b66efc0910c110
-
{e=>3,c=>4,a=>0,g=>1460,b=>0,d=>191785714,f=>1}
000400f26a6e0b0bb405
000400f26a6e0b0bb405
000400f26a6e0b0bb405
000400f26a6e0b0bb405
-
{e=>1,c=>0,a=>4,g=>4192,b=>7,d=>193646184,f=>0}
3c000068ce8a0b016010
3c000068ce8a0b016010
3c000068ce8a0b016010
3c000068ce8a0b016010
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
  unsigned short g:13;
  unsigned char  h;
};
-
{e=>2,a=>6,d=>72412399,c=>7,h=>156,b=>2,g=>1487,f=>3}
160700efec50041acf059c
160700efec50041acf059c
160700efec50041acf059c
160700efec50041acf059c
-
{e=>6,a=>3,d=>227300670,c=>1,h=>201,b=>3,g=>4275,f=>1}
1b01003e558c0d0eb310c9
1b01003e558c0d0eb310c9
1b01003e558c0d0eb310c9
1b01003e558c0d0eb310c9
-
{e=>3,a=>7,d=>180879568,c=>1,h=>224,b=>5,g=>7892,f=>3}
2f0100d000c80a1bd41ee0
2f0100d000c80a1bd41ee0
2f0100d000c80a1bd41ee0
2f0100d000c80a1bd41ee0
-
{e=>3,a=>0,d=>137129408,c=>6,h=>116,b=>2,g=>269,f=>0}
100600c06d2c08030d0174
100600c06d2c08030d0174
100600c06d2c08030d0174
100600c06d2c08030d0174
-
{e=>1,a=>3,d=>206927027,c=>2,h=>226,b=>7,g=>3383,f=>2}
3b0200b374550c11370de2
3b0200b374550c11370de2
3b0200b374550c11370de2
3b0200b374550c11370de2
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  char a;
  unsigned char  b:3;
};
-
{a=>5,b=>0}
0500
0500
0500
0500
-
{a=>53,b=>0}
3500
3500
3500
3500
-
{a=>83,b=>5}
5305
5305
5305
5305
-
{a=>4,b=>3}
0403
0403
0403
0403
-
{a=>-108,b=>1}
9401
9401
9401
9401
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>4,a=>-89,b=>5}
a725
a725
a725
a725
-
{c=>3,a=>-94,b=>1}
a219
a219
a219
a219
-
{c=>2,a=>41,b=>1}
2911
2911
2911
2911
-
{c=>0,a=>-104,b=>5}
9805
9805
9805
9805
-
{c=>4,a=>123,b=>7}
7b27
7b27
7b27
7b27
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>1,a=>26,b=>2,d=>6}
1a0a0600
1a0a0600
1a0a0600
1a0a0600
-
{c=>0,a=>41,b=>3,d=>7}
29030700
29030700
29030700
29030700
-
{c=>0,a=>-60,b=>7,d=>5}
c4070500
c4070500
c4070500
c4070500
-
{c=>4,a=>21,b=>5,d=>1}
15250100
15250100
15250100
15250100
-
{c=>1,a=>-57,b=>3,d=>7}
c70b0700
c70b0700
c70b0700
c70b0700
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>251650091,c=>3,a=>18,b=>2,d=>6}
121a06002be0ff0e
121a06002be0ff0e
121a06002be0ff0e
121a06002be0ff0e
-
{e=>184337798,c=>4,a=>67,b=>1,d=>5}
4321050086c5fc0a
4321050086c5fc0a
4321050086c5fc0a
4321050086c5fc0a
-
{e=>18454609,c=>4,a=>-22,b=>2,d=>3}
ea22030051981901
ea22030051981901
ea22030051981901
ea22030051981901
-
{e=>172433341,c=>6,a=>76,b=>6,d=>7}
4c360700bd1f470a
4c360700bd1f470a
4c360700bd1f470a
4c360700bd1f470a
-
{e=>134101335,c=>2,a=>103,b=>0,d=>4}
671004005739fe07
671004005739fe07
671004005739fe07
671004005739fe07
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>200236336,c=>5,a=>-24,b=>2,d=>3,f=>1}
e82a0300305def0b01
e82a0300305def0b01
e82a0300305def0b01
e82a0300305def0b01
-
{e=>16740769,c=>4,a=>-26,b=>0,d=>1,f=>3}
e6200100a171ff0003
e6200100a171ff0003
e6200100a171ff0003
e6200100a171ff0003
-
{e=>6071845,c=>4,a=>121,b=>4,d=>1,f=>2}
7924010025a65c0002
7924010025a65c0002
7924010025a65c0002
7924010025a65c0002
-
{e=>24355757,c=>3,a=>-75,b=>5,d=>2,f=>2}
b51d0200ada3730102
b51d0200ada3730102
b51d0200ada3730102
b51d0200ada3730102
-
{e=>167185341,c=>2,a=>21,b=>6,d=>4,f=>4}
15160400bd0bf70904
15160400bd0bf70904
15160400bd0bf70904
15160400bd0bf70904
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>98259173,c=>2,a=>-44,g=>2,b=>6,d=>2,f=>2}
d4160200e550db0512
d4160200e550db0512
d4160200e550db0512
d4160200e550db0512
-
{e=>101458287,c=>3,a=>107,g=>0,b=>2,d=>7,f=>2}
6b1a07006f210c0602
6b1a07006f210c0602
6b1a07006f210c0602
6b1a07006f210c0602
-
{e=>73372275,c=>5,a=>-94,g=>0,b=>1,d=>7,f=>1}
a229070073925f0401
a229070073925f0401
a229070073925f0401
a229070073925f0401
-
{e=>168006158,c=>5,a=>-34,g=>0,b=>0,d=>0,f=>5}
de2800000e92030a05
de2800000e92030a05
de2800000e92030a05
de2800000e92030a05
-
{e=>251692646,c=>0,a=>58,g=>1,b=>7,d=>2,f=>6}
3a0702006686000f0e
3a0702006686000f0e
3a0702006686000f0e
3a0702006686000f0e
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>72582175,a=>66,d=>0,c=>0,h=>6020,b=>1,g=>0,f=>1}
420100001f845304018417
420100001f845304018417
420100001f845304018417
420100001f845304018417
-
{e=>184039552,a=>30,d=>0,c=>3,h=>2419,b=>7,g=>2,f=>0}
1e1f00008038f80a107309
1e1f00008038f80a107309
1e1f00008038f80a107309
1e1f00008038f80a107309
-
{e=>80164592,a=>-49,d=>3,c=>6,h=>7825,b=>5,g=>0,f=>7}
cf350300f036c70407911e
cf350300f036c70407911e
cf350300f036c70407911e
cf350300f036c70407911e
-
{e=>159880110,a=>-107,d=>6,c=>0,h=>4520,b=>3,g=>1,f=>4}
95030600ae9387090ca811
95030600ae9387090ca811
95030600ae9387090ca811
95030600ae9387090ca811
-
{e=>237506163,a=>-31,d=>6,c=>0,h=>1061,b=>7,g=>3,f=>6}
e1070600730e280e1e2504
e1070600730e280e1e2504
e1070600730e280e1e2504
e1070600730e280e1e2504
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>75173975,a=>0,d=>7,c=>5,h=>219,b=>2,g=>0,f=>2,i=>75}
002a070057107b0402db004b
002a070057107b0402db004b
002a070057107b0402db004b
002a070057107b0402db004b
-
{e=>14359521,a=>-73,d=>7,c=>3,h=>7081,b=>3,g=>1,f=>4,i=>127}
b71b0700e11bdb000ca91b7f
b71b0700e11bdb000ca91b7f
b71b0700e11bdb000ca91b7f
b71b0700e11bdb000ca91b7f
-
{e=>93479715,a=>-14,d=>2,c=>4,h=>5837,b=>2,g=>0,f=>5,i=>120}
f22202002363920505cd1678
f22202002363920505cd1678
f22202002363920505cd1678
f22202002363920505cd1678
-
{e=>240985188,a=>123,d=>3,c=>4,h=>1817,b=>6,g=>0,f=>0,i=>75}
7b26030064245d0e0019074b
7b26030064245d0e0019074b
7b26030064245d0e0019074b
7b26030064245d0e0019074b
-
{e=>31234999,a=>99,d=>6,c=>3,h=>4938,b=>0,g=>3,f=>3,i=>200}
63180600b79bdc011b4a13c8
63180600b79bdc011b4a13c8
63180600b79bdc011b4a13c8
63180600b79bdc011b4a13c8
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  short a;
  unsigned char  b:3;
};
-
{a=>-20,b=>2}
ecff02
ecff02
ecff02
ecff02
-
{a=>51,b=>0}
330000
330000
330000
330000
-
{a=>-61,b=>7}
c3ff07
c3ff07
c3ff07
c3ff07
-
{a=>109,b=>2}
6d0002
6d0002
6d0002
6d0002
-
{a=>3,b=>5}
030005
030005
030005
030005
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>1,a=>91,b=>0}
5b0008
5b0008
5b0008
5b0008
-
{c=>6,a=>40,b=>1}
280031
280031
280031
280031
-
{c=>3,a=>73,b=>7}
49001f
49001f
49001f
49001f
-
{c=>2,a=>-70,b=>0}
baff10
baff10
baff10
baff10
-
{c=>3,a=>-86,b=>2}
aaff1a
aaff1a
aaff1a
aaff1a
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>7,a=>-16,b=>2,d=>0}
f0ff3a0000
f0ff3a0000
f0ff3a0000
f0ff3a0000
-
{c=>2,a=>120,b=>3,d=>3}
7800130300
7800130300
7800130300
7800130300
-
{c=>1,a=>109,b=>6,d=>6}
6d000e0600
6d000e0600
6d000e0600
6d000e0600
-
{c=>2,a=>109,b=>7,d=>5}
6d00170500
6d00170500
6d00170500
6d00170500
-
{c=>7,a=>35,b=>6,d=>4}
23003e0400
23003e0400
23003e0400
23003e0400
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>242573218,c=>0,a=>-82,b=>5,d=>3}
aeff050300a25f750e
aeff050300a25f750e
aeff050300a25f750e
aeff050300a25f750e
-
{e=>30225390,c=>1,a=>-90,b=>1,d=>0}
a6ff090000ee33cd01
a6ff090000ee33cd01
a6ff090000ee33cd01
a6ff090000ee33cd01
-
{e=>42673361,c=>7,a=>2,b=>7,d=>4}
02003f0400d1248b02
02003f0400d1248b02
02003f0400d1248b02
02003f0400d1248b02
-
{e=>177618799,c=>1,a=>-74,b=>4,d=>0}
b6ff0c00006f3f960a
b6ff0c00006f3f960a
b6ff0c00006f3f960a
b6ff0c00006f3f960a
-
{e=>162146214,c=>1,a=>9,b=>5,d=>2}
09000d0200a627aa09
09000d0200a627aa09
09000d0200a627aa09
09000d0200a627aa09
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>51386433,c=>7,a=>-38,b=>4,d=>2,f=>2}
daff3c02004118100302
daff3c02004118100302
daff3c02004118100302
daff3c02004118100302
-
{e=>119132246,c=>3,a=>-125,b=>6,d=>1,f=>0}
83ff1e010056d0190700
83ff1e010056d0190700
83ff1e010056d0190700
83ff1e010056d0190700
-
{e=>28309628,c=>6,a=>-101,b=>5,d=>5,f=>0}
9bff3505007cf8af0100
9bff3505007cf8af0100
9bff3505007cf8af0100
9bff3505007cf8af0100
-
{e=>151543114,c=>3,a=>3,b=>2,d=>7,f=>5}
03001a07004a5d080905
03001a07004a5d080905
03001a07004a5d080905
03001a07004a5d080905
-
{e=>213132804,c=>5,a=>-95,b=>4,d=>0,f=>0}
a1ff2c00000426b40c00
a1ff2c00000426b40c00
a1ff2c00000426b40c00
a1ff2c00000426b40c00
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>142590409,c=>6,a=>-41,g=>0,b=>6,d=>3,f=>7}
d7ff360300c9c17f0807
d7ff360300c9c17f0807
d7ff360300c9c17f0807
d7ff360300c9c17f0807
-
{e=>97470275,c=>4,a=>81,g=>1,b=>6,d=>6,f=>3}
51002606004347cf050b
51002606004347cf050b
51002606004347cf050b
51002606004347cf050b
-
{e=>267791921,c=>1,a=>34,g=>1,b=>7,d=>2,f=>1}
22000f0200312ef60f09
22000f0200312ef60f09
22000f0200312ef60f09
22000f0200312ef60f09
-
{e=>41800024,c=>3,a=>-80,g=>2,b=>0,d=>0,f=>1}
b0ff18000058d17d0211
b0ff18000058d17d0211
b0ff18000058d17d0211
b0ff18000058d17d0211
-
{e=>258096646,c=>0,a=>-31,g=>2,b=>3,d=>0,f=>3}
e1ff030000063e620f13
e1ff030000063e620f13
e1ff030000063e620f13
e1ff030000063e620f13
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>122313407,a=>19,d=>3,c=>0,h=>650,b=>1,g=>1,f=>3}
1300010300bf5a4a070b8a02
1300010300bf5a4a070b8a02
1300010300bf5a4a070b8a02
1300010300bf5a4a070b8a02
-
{e=>94490750,a=>35,d=>1,c=>1,h=>5999,b=>4,g=>1,f=>0}
23000c01007ed0a105086f17
23000c01007ed0a105086f17
23000c01007ed0a105086f17
23000c01007ed0a105086f17
-
{e=>76168925,a=>-99,d=>0,c=>3,h=>6309,b=>6,g=>0,f=>6}
9dff1e0000dd3e8a0406a518
9dff1e0000dd3e8a0406a518
9dff1e0000dd3e8a0406a518
9dff1e0000dd3e8a0406a518
-
{e=>69639528,a=>-114,d=>1,c=>7,h=>2240,b=>2,g=>1,f=>7}
8eff3a0100689d26040fc008
8eff3a0100689d26040fc008
8eff3a0100689d26040fc008
8eff3a0100689d26040fc008
-
{e=>138012526,a=>109,d=>3,c=>5,h=>7241,b=>3,g=>2,f=>0}
6d002b03006ee7390810491c
6d002b03006ee7390810491c
6d002b03006ee7390810491c
6d002b03006ee7390810491c
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>213997424,a=>12,d=>4,c=>5,h=>6891,b=>4,g=>0,f=>5,i=>155}
0c002c04007057c10c05eb1a9b
0c002c04007057c10c05eb1a9b
0c002c04007057c10c05eb1a9b
0c002c04007057c10c05eb1a9b
-
{e=>80148154,a=>4,d=>3,c=>3,h=>5605,b=>4,g=>2,f=>7,i=>187}
04001c0300baf6c60417e515bb
04001c0300baf6c60417e515bb
04001c0300baf6c60417e515bb
04001c0300baf6c60417e515bb
-
{e=>17679511,a=>103,d=>4,c=>7,h=>793,b=>4,g=>1,f=>5,i=>154}
67003c040097c40d010d19039a
67003c040097c40d010d19039a
67003c040097c40d010d19039a
67003c040097c40d010d19039a
-
{e=>234963446,a=>-109,d=>7,c=>4,h=>4806,b=>2,g=>2,f=>0,i=>153}
93ff220700f641010e10c61299
93ff220700f641010e10c61299
93ff220700f641010e10c61299
93ff220700f641010e10c61299
-
{e=>233686042,a=>26,d=>5,c=>3,h=>6938,b=>4,g=>1,f=>3,i=>229}
1a001c05001ac4ed0d0b1a1be5
1a001c05001ac4ed0d0b1a1be5
1a001c05001ac4ed0d0b1a1be5
1a001c05001ac4ed0d0b1a1be5
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  int a;
  unsigned char  b:3;
};
-
{a=>-76,b=>0}
b4ffffff00
b4ffffff00
b4ffffff00
b4ffffff00
-
{a=>-65,b=>4}
bfffffff04
bfffffff04
bfffffff04
bfffffff04
-
{a=>13,b=>3}
0d00000003
0d00000003
0d00000003
0d00000003
-
{a=>79,b=>5}
4f00000005
4f00000005
4f00000005
4f00000005
-
{a=>-81,b=>4}
afffffff04
afffffff04
afffffff04
afffffff04
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>3,a=>84,b=>1}
5400000019
5400000019
5400000019
5400000019
-
{c=>1,a=>127,b=>1}
7f00000009
7f00000009
7f00000009
7f00000009
-
{c=>5,a=>-114,b=>0}
8effffff28
8effffff28
8effffff28
8effffff28
-
{c=>3,a=>108,b=>1}
6c00000019
6c00000019
6c00000019
6c00000019
-
{c=>7,a=>9,b=>1}
0900000039
0900000039
0900000039
0900000039
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>6,a=>-62,b=>1,d=>4}
c2ffffff310400
c2ffffff310400
c2ffffff310400
c2ffffff310400
-
{c=>7,a=>74,b=>5,d=>0}
4a0000003d0000
4a0000003d0000
4a0000003d0000
4a0000003d0000
-
{c=>3,a=>-122,b=>2,d=>7}
86ffffff1a0700
86ffffff1a0700
86ffffff1a0700
86ffffff1a0700
-
{c=>3,a=>-73,b=>7,d=>2}
b7ffffff1f0200
b7ffffff1f0200
b7ffffff1f0200
b7ffffff1f0200
-
{c=>1,a=>13,b=>5,d=>2}
0d0000000d0200
0d0000000d0200
0d0000000d0200
0d0000000d0200
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>130106456,c=>4,a=>127,b=>7,d=>3}
7f0000002703005844c107
7f0000002703005844c107
7f0000002703005844c107
7f0000002703005844c107
-
{e=>228064205,c=>5,a=>28,b=>5,d=>3}
1c0000002d0300cdfb970d
1c0000002d0300cdfb970d
1c0000002d0300cdfb970d
1c0000002d0300cdfb970d
-
{e=>217906279,c=>1,a=>99,b=>0,d=>7}
6300000008070067fcfc0c
6300000008070067fcfc0c
6300000008070067fcfc0c
6300000008070067fcfc0c
-
{e=>51712296,c=>5,a=>-8,b=>2,d=>6}
f8ffffff2a060028111503
f8ffffff2a060028111503
f8ffffff2a060028111503
f8ffffff2a060028111503
-
{e=>211735696,c=>6,a=>78,b=>1,d=>0}
4e00000031000090d49e0c
4e00000031000090d49e0c
4e00000031000090d49e0c
4e00000031000090d49e0c
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>242564914,c=>0,a=>6,b=>0,d=>4,f=>4}
06000000000400323f750e04
06000000000400323f750e04
06000000000400323f750e04
06000000000400323f750e04
-
{e=>142230259,c=>5,a=>-69,b=>3,d=>4,f=>0}
bbffffff2b0400f3427a0800
bbffffff2b0400f3427a0800
bbffffff2b0400f3427a0800
bbffffff2b0400f3427a0800
-
{e=>40226599,c=>3,a=>-72,b=>3,d=>0,f=>0}
b8ffffff1b000027cf650200
b8ffffff1b000027cf650200
b8ffffff1b000027cf650200
b8ffffff1b000027cf650200
-
{e=>4604876,c=>0,a=>18,b=>5,d=>2,f=>5}
12000000050200cc43460005
12000000050200cc43460005
12000000050200cc43460005
12000000050200cc43460005
-
{e=>209840252,c=>0,a=>-52,b=>3,d=>3,f=>2}
ccffffff0303007ce8810c02
ccffffff0303007ce8810c02
ccffffff0303007ce8810c02
ccffffff0303007ce8810c02
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>13259097,c=>3,a=>-63,g=>1,b=>5,d=>7,f=>3}
c1ffffff1d07005951ca000b
c1ffffff1d07005951ca000b
c1ffffff1d07005951ca000b
c1ffffff1d07005951ca000b
-
{e=>156908516,c=>4,a=>36,g=>0,b=>6,d=>0,f=>6}
24000000260000e43b5a0906
24000000260000e43b5a0906
24000000260000e43b5a0906
24000000260000e43b5a0906
-
{e=>59405293,c=>0,a=>117,g=>2,b=>5,d=>7,f=>7}
75000000050700ed738a0317
75000000050700ed738a0317
75000000050700ed738a0317
75000000050700ed738a0317
-
{e=>247527189,c=>5,a=>66,g=>2,b=>2,d=>2,f=>1}
420000002a020015f7c00e11
420000002a020015f7c00e11
420000002a020015f7c00e11
420000002a020015f7c00e11
-
{e=>80174753,c=>2,a=>-35,g=>1,b=>2,d=>0,f=>2}
ddffffff120000a15ec7040a
ddffffff120000a15ec7040a
ddffffff120000a15ec7040a
ddffffff120000a15ec7040a
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>79855944,a=>-79,d=>6,c=>0,h=>1469,b=>5,g=>1,f=>0}
b1ffffff0506004881c20408bd05
b1ffffff0506004881c20408bd05
b1ffffff0506004881c20408bd05
b1ffffff0506004881c20408bd05
-
{e=>55286286,a=>-110,d=>5,c=>5,h=>6486,b=>5,g=>1,f=>3}
92ffffff2d05000e9a4b030b5619
92ffffff2d05000e9a4b030b5619
92ffffff2d05000e9a4b030b5619
92ffffff2d05000e9a4b030b5619
-
{e=>230194727,a=>-49,d=>2,c=>2,h=>6812,b=>6,g=>1,f=>4}
cfffffff160200277eb80d0c9c1a
cfffffff160200277eb80d0c9c1a
cfffffff160200277eb80d0c9c1a
cfffffff160200277eb80d0c9c1a
-
{e=>191802023,a=>61,d=>7,c=>6,h=>7935,b=>4,g=>1,f=>2}
3d000000340700a7aa6e0b0aff1e
3d000000340700a7aa6e0b0aff1e
3d000000340700a7aa6e0b0aff1e
3d000000340700a7aa6e0b0aff1e
-
{e=>31737331,a=>18,d=>6,c=>6,h=>5531,b=>3,g=>2,f=>2}
12000000330600f345e401129b15
12000000330600f345e401129b15
12000000330600f345e401129b15
12000000330600f345e401129b15
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>257753255,a=>78,d=>5,c=>1,h=>4307,b=>5,g=>1,f=>3,i=>23}
4e0000000d0500a7005d0f0bd31017
4e0000000d0500a7005d0f0bd31017
4e0000000d0500a7005d0f0bd31017
4e0000000d0500a7005d0f0bd31017
-
{e=>154752796,a=>-128,d=>3,c=>3,h=>1857,b=>7,g=>2,f=>4,i=>149}
80ffffff1f03001c57390914410795
80ffffff1f03001c57390914410795
80ffffff1f03001c57390914410795
80ffffff1f03001c57390914410795
-
{e=>48153402,a=>-86,d=>4,c=>5,h=>2443,b=>5,g=>1,f=>3,i=>106}
aaffffff2d04003ac3de020b8b096a
aaffffff2d04003ac3de020b8b096a
aaffffff2d04003ac3de020b8b096a
aaffffff2d04003ac3de020b8b096a
-
{e=>149056525,a=>-9,d=>6,c=>2,h=>4899,b=>0,g=>1,f=>2,i=>164}
f7ffffff1006000d6ce2080a2313a4
f7ffffff1006000d6ce2080a2313a4
f7ffffff1006000d6ce2080a2313a4
f7ffffff1006000d6ce2080a2313a4
-
{e=>211134956,a=>118,d=>5,c=>1,h=>1779,b=>3,g=>1,f=>5,i=>234}
760000000b0500eca9950c0df306ea
760000000b0500eca9950c0df306ea
760000000b0500eca9950c0df306ea
760000000b0500eca9950c0df306ea
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  long a;
  unsigned char  b:3;
};
-
{a=>83,b=>3}
5300000003
5300000003
5300000003
5300000003
-
{a=>118,b=>5}
7600000005
7600000005
7600000005
7600000005
-
{a=>102,b=>4}
6600000004
6600000004
6600000004
6600000004
-
{a=>-46,b=>3}
d2ffffff03
d2ffffff03
d2ffffff03
d2ffffff03
-
{a=>-65,b=>5}
bfffffff05
bfffffff05
bfffffff05
bfffffff05
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>6,a=>101,b=>1}
6500000031
6500000031
6500000031
6500000031
-
{c=>5,a=>32,b=>7}
200000002f
200000002f
200000002f
200000002f
-
{c=>7,a=>-74,b=>2}
b6ffffff3a
b6ffffff3a
b6ffffff3a
b6ffffff3a
-
{c=>4,a=>-84,b=>1}
acffffff21
acffffff21
acffffff21
acffffff21
-
{c=>3,a=>-100,b=>4}
9cffffff1c
9cffffff1c
9cffffff1c
9cffffff1c
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>3,a=>-18,b=>2,d=>4}
eeffffff1a0400
eeffffff1a0400
eeffffff1a0400
eeffffff1a0400
-
{c=>0,a=>-123,b=>2,d=>3}
85ffffff020300
85ffffff020300
85ffffff020300
85ffffff020300
-
{c=>5,a=>85,b=>2,d=>3}
550000002a0300
550000002a0300
550000002a0300
550000002a0300
-
{c=>5,a=>-113,b=>7,d=>6}
8fffffff2f0600
8fffffff2f0600
8fffffff2f0600
8fffffff2f0600
-
{c=>3,a=>66,b=>0,d=>6}
42000000180600
42000000180600
42000000180600
42000000180600
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>160937402,c=>7,a=>27,b=>7,d=>5}
1b0000003f0500bab59709
1b0000003f0500bab59709
1b0000003f0500bab59709
1b0000003f0500bab59709
-
{e=>20048177,c=>3,a=>28,b=>7,d=>6}
1c0000001f060031e93101
1c0000001f060031e93101
1c0000001f060031e93101
1c0000001f060031e93101
-
{e=>246627849,c=>0,a=>-81,b=>4,d=>3}
afffffff040300093eb30e
afffffff040300093eb30e
afffffff040300093eb30e
afffffff040300093eb30e
-
{e=>200039194,c=>5,a=>112,b=>2,d=>1}
700000002a01001a5bec0b
700000002a01001a5bec0b
700000002a01001a5bec0b
700000002a01001a5bec0b
-
{e=>250650060,c=>0,a=>124,b=>1,d=>6}
7c000000010600cc9df00e
7c000000010600cc9df00e
7c000000010600cc9df00e
7c000000010600cc9df00e
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>164019807,c=>0,a=>-107,b=>4,d=>4,f=>4}
95ffffff0404005fbec60904
95ffffff0404005fbec60904
95ffffff0404005fbec60904
95ffffff0404005fbec60904
-
{e=>148347054,c=>7,a=>122,b=>5,d=>4,f=>4}
7a0000003d0400ae98d70804
7a0000003d0400ae98d70804
7a0000003d0400ae98d70804
7a0000003d0400ae98d70804
-
{e=>201328566,c=>2,a=>-38,b=>2,d=>0,f=>5}
daffffff120000b607000c05
daffffff120000b607000c05
daffffff120000b607000c05
daffffff120000b607000c05
-
{e=>17793067,c=>3,a=>62,b=>5,d=>1,f=>6}
3e0000001d01002b800f0106
3e0000001d01002b800f0106
3e0000001d01002b800f0106
3e0000001d01002b800f0106
-
{e=>265362806,c=>3,a=>-81,b=>7,d=>0,f=>0}
afffffff1f0000761dd10f00
afffffff1f0000761dd10f00
afffffff1f0000761dd10f00
afffffff1f0000761dd10f00
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>119342936,c=>2,a=>-110,g=>0,b=>2,d=>6,f=>7}
92ffffff12060058071d0707
92ffffff12060058071d0707
92ffffff12060058071d0707
92ffffff12060058071d0707
-
{e=>62059604,c=>7,a=>-92,g=>3,b=>4,d=>4,f=>7}
a4ffffff3c040054f4b2031f
a4ffffff3c040054f4b2031f
a4ffffff3c040054f4b2031f
a4ffffff3c040054f4b2031f
-
{e=>174545826,c=>6,a=>-60,g=>3,b=>2,d=>3,f=>1}
c4ffffff320300a25b670a19
c4ffffff320300a25b670a19
c4ffffff320300a25b670a19
c4ffffff320300a25b670a19
-
{e=>133811322,c=>5,a=>106,g=>2,b=>2,d=>0,f=>4}
6a0000002a00007accf90714
6a0000002a00007accf90714
6a0000002a00007accf90714
6a0000002a00007accf90714
-
{e=>181399152,c=>6,a=>71,g=>3,b=>4,d=>7,f=>7}
4700000034070070eecf0a1f
4700000034070070eecf0a1f
4700000034070070eecf0a1f
4700000034070070eecf0a1f
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>178239616,a=>-56,d=>2,c=>0,h=>947,b=>6,g=>2,f=>5}
c8ffffff06020080b89f0a15b303
c8ffffff06020080b89f0a15b303
c8ffffff06020080b89f0a15b303
c8ffffff06020080b89f0a15b303
-
{e=>92807764,a=>66,d=>7,c=>0,h=>2391,b=>5,g=>2,f=>3}
4200000005070054228805135709
4200000005070054228805135709
4200000005070054228805135709
4200000005070054228805135709
-
{e=>217147655,a=>26,d=>5,c=>6,h=>7725,b=>4,g=>1,f=>2}
1a0000003405000769f10c0a2d1e
1a0000003405000769f10c0a2d1e
1a0000003405000769f10c0a2d1e
1a0000003405000769f10c0a2d1e
-
{e=>94483661,a=>-122,d=>7,c=>6,h=>3773,b=>6,g=>2,f=>7}
86ffffff360700cdb4a10517bd0e
86ffffff360700cdb4a10517bd0e
86ffffff360700cdb4a10517bd0e
86ffffff360700cdb4a10517bd0e
-
{e=>255972856,a=>-65,d=>4,c=>6,h=>4167,b=>3,g=>2,f=>7}
bfffffff330400f8d5410f174710
bfffffff330400f8d5410f174710
bfffffff330400f8d5410f174710
bfffffff330400f8d5410f174710
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct umixed_pack_1 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>236368736,a=>50,d=>0,c=>0,h=>550,b=>0,g=>3,f=>2,i=>115}
3200000000000060b3160e1a260273
3200000000000060b3160e1a260273
3200000000000060b3160e1a260273
3200000000000060b3160e1a260273
-
{e=>88524857,a=>-90,d=>2,c=>1,h=>306,b=>4,g=>3,f=>5,i=>249}
a6ffffff0c020039c846051d3201f9
a6ffffff0c020039c846051d3201f9
a6ffffff0c020039c846051d3201f9
a6ffffff0c020039c846051d3201f9
-
{e=>192500988,a=>-84,d=>1,c=>2,h=>5667,b=>5,g=>0,f=>5,i=>178}
acffffff150100fc54790b052316b2
acffffff150100fc54790b052316b2
acffffff150100fc54790b052316b2
acffffff150100fc54790b052316b2
-
{e=>102319901,a=>48,d=>6,c=>5,h=>4809,b=>5,g=>0,f=>5,i=>243}
300000002d06001d47190605c912f3
300000002d06001d47190605c912f3
300000002d06001d47190605c912f3
300000002d06001d47190605c912f3
-
{e=>105125875,a=>-48,d=>6,c=>2,h=>3701,b=>4,g=>0,f=>6,i=>134}
d0ffffff140600f317440606750e86
d0ffffff140600f317440606750e86
d0ffffff140600f317440606750e86
d0ffffff140600f317440606750e86
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  unsigned char  a:3;
};
-
{a=>7}
07
07
07
07
-
{a=>4}
04
04
04
04
-
{a=>4}
04
04
04
04
-
{a=>7}
07
07
07
07
-
{a=>1}
01
01
01
01
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  unsigned char  a:3;
  unsigned char  b:3;
};
-
{a=>6,b=>7}
3e
3e
3e
3e
-
{a=>6,b=>0}
06
06
06
06
-
{a=>1,b=>6}
31
31
31
31
-
{a=>3,b=>4}
23
23
23
23
-
{a=>5,b=>5}
2d
2d
2d
2d
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
};
-
{c=>6,a=>3,b=>3}
1b000600
1b000600
1b000600
1b000600
-
{c=>2,a=>6,b=>1}
0e000200
0e000200
0e000200
0e000200
-
{c=>6,a=>4,b=>1}
0c000600
0c000600
0c000600
0c000600
-
{c=>2,a=>1,b=>0}
01000200
01000200
01000200
01000200
-
{c=>7,a=>4,b=>7}
3c000700
3c000700
3c000700
3c000700
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
};
-
{c=>1,a=>4,b=>4,d=>133269742}
24000100ee88f107
24000100ee88f107
24000100ee88f107
24000100ee88f107
-
{c=>3,a=>7,b=>1,d=>257081784}
0f000300b8c1520f
0f000300b8c1520f
0f000300b8c1520f
0f000300b8c1520f
-
{c=>0,a=>7,b=>6,d=>258403104}
3700000020eb660f
3700000020eb660f
3700000020eb660f
3700000020eb660f
-
{c=>5,a=>7,b=>0,d=>128978242}
07000500420db007
07000500420db007
07000500420db007
07000500420db007
-
{c=>5,a=>0,b=>4,d=>243031951}
200005008f5f7c0e
200005008f5f7c0e
200005008f5f7c0e
200005008f5f7c0e
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
};
-
{e=>0,c=>2,a=>6,b=>7,d=>33702724}
3e000200444302020000
3e000200444302020000
3e000200444302020000
3e000200444302020000
-
{e=>2,c=>5,a=>5,b=>2,d=>6095297}
15000500c1015d000200
15000500c1015d000200
15000500c1015d000200
15000500c1015d000200
-
{e=>4,c=>4,a=>4,b=>6,d=>213519559}
34000400c70cba0c0400
34000400c70cba0c0400
34000400c70cba0c0400
34000400c70cba0c0400
-
{e=>5,c=>2,a=>7,b=>5,d=>18462540}
2f0002004cb719010500
2f0002004cb719010500
2f0002004cb719010500
2f0002004cb719010500
-
{e=>1,c=>6,a=>1,b=>7,d=>89059346}
3900060012f04e050100
3900060012f04e050100
3900060012f04e050100
3900060012f04e050100
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
};
-
{e=>5,c=>1,a=>7,b=>1,d=>136757511,f=>1}
0f00010007c126080d00
0f00010007c126080d00
0f00010007c126080d00
0f00010007c126080d00
-
{e=>0,c=>4,a=>7,b=>4,d=>125709169,f=>0}
27000400712b7e070000
27000400712b7e070000
27000400712b7e070000
27000400712b7e070000
-
{e=>4,c=>6,a=>4,b=>0,d=>58396282,f=>2}
040006007a0e7b031400
040006007a0e7b031400
040006007a0e7b031400
040006007a0e7b031400
-
{e=>0,c=>7,a=>2,b=>1,d=>156900784,f=>0}
0a000700b01d5a090000
0a000700b01d5a090000
0a000700b01d5a090000
0a000700b01d5a090000
-
{e=>6,c=>5,a=>4,b=>0,d=>153791533,f=>0}
040005002dac2a090600
040005002dac2a090600
040005002dac2a090600
040005002dac2a090600
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
  unsigned short g:13;
};
-
{e=>4,c=>6,a=>0,g=>3159,b=>3,d=>201444973,f=>3}
180006006dce010c1c00570c
180006006dce010c1c00570c
180006006dce010c1c00570c
180006006dce010c1c00570c
-
{e=>3,c=>5,a=>2,g=>1311,b=>0,d=>216985875,f=>0}
0200050013f1ee0c03001f05
0200050013f1ee0c03001f05
0200050013f1ee0c03001f05
0200050013f1ee0c03001f05
-
{e=>4,c=>1,a=>4,g=>4089,b=>3,d=>90392677,f=>2}
1c000100654863051400f90f
1c000100654863051400f90f
1c000100654863051400f90f
1c000100654863051400f90f
-
{e=>4,c=>6,a=>2,g=>6577,b=>0,d=>32952048,f=>2}
02000600f0cef6011400b119
02000600f0cef6011400b119
02000600f0cef6011400b119
02000600f0cef6011400b119
-
{e=>6,c=>3,a=>2,g=>5134,b=>2,d=>70582675,f=>0}
120003009301350406000e14
120003009301350406000e14
120003009301350406000e14
120003009301350406000e14
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
  unsigned short g:13;
  unsigned char  h;
};
-
{e=>4,a=>7,d=>66200696,c=>5,h=>31,b=>4,g=>6484,f=>1}
270005007824f2030c0054191f00
270005007824f2030c0054191f00
270005007824f2030c0054191f00
270005007824f2030c0054191f00
-
{e=>3,a=>0,d=>142854848,c=>3,h=>30,b=>3,g=>2350,f=>3}
18000300c0ca83081b002e091e00
18000300c0ca83081b002e091e00
18000300c0ca83081b002e091e00
18000300c0ca83081b002e091e00
-
{e=>0,a=>3,d=>178180283,c=>3,h=>162,b=>2,g=>1577,f=>2}
13000300bbd09e0a10002906a200
13000300bbd09e0a10002906a200
13000300bbd09e0a10002906a200
13000300bbd09e0a10002906a200
-
{e=>7,a=>3,d=>71770977,c=>0,h=>159,b=>4,g=>2221,f=>2}
23000000612347041700ad089f00
23000000612347041700ad089f00
23000000612347041700ad089f00
23000000612347041700ad089f00
-
{e=>3,a=>7,d=>209718566,c=>4,h=>184,b=>0,g=>4011,f=>3}
07000400260d800c1b00ab0fb800
07000400260d800c1b00ab0fb800
07000400260d800c1b00ab0fb800
07000400260d800c1b00ab0fb800
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  char a;
  unsigned char  b:3;
};
-
{a=>-101,b=>3}
9b03
9b03
9b03
9b03
-
{a=>-121,b=>0}
8700
8700
8700
8700
-
{a=>49,b=>5}
3105
3105
3105
3105
-
{a=>-18,b=>5}
ee05
ee05
ee05
ee05
-
{a=>-28,b=>7}
e407
e407
e407
e407
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>5,a=>-95,b=>6}
a12e
a12e
a12e
a12e
-
{c=>3,a=>105,b=>5}
691d
691d
691d
691d
-
{c=>5,a=>-88,b=>7}
a82f
a82f
a82f
a82f
-
{c=>3,a=>-100,b=>0}
9c18
9c18
9c18
9c18
-
{c=>0,a=>-15,b=>0}
f100
f100
f100
f100
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>1,a=>78,b=>7,d=>5}
4e0f0500
4e0f0500
4e0f0500
4e0f0500
-
{c=>4,a=>18,b=>5,d=>2}
12250200
12250200
12250200
12250200
-
{c=>7,a=>56,b=>5,d=>0}
383d0000
383d0000
383d0000
383d0000
-
{c=>5,a=>-82,b=>5,d=>1}
ae2d0100
ae2d0100
ae2d0100
ae2d0100
-
{c=>7,a=>60,b=>6,d=>5}
3c3e0500
3c3e0500
3c3e0500
3c3e0500
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>221131133,c=>6,a=>105,b=>3,d=>0}
693300007d312e0d
693300007d312e0d
693300007d312e0d
693300007d312e0d
-
{e=>105130068,c=>7,a=>43,b=>7,d=>4}
2b3f040054284406
2b3f040054284406
2b3f040054284406
2b3f040054284406
-
{e=>200295387,c=>7,a=>95,b=>0,d=>4}
5f380400db43f00b
5f380400db43f00b
5f380400db43f00b
5f380400db43f00b
-
{e=>204864432,c=>4,a=>121,b=>0,d=>5}
79200500b0fb350c
79200500b0fb350c
79200500b0fb350c
79200500b0fb350c
-
{e=>116121104,c=>3,a=>-77,b=>7,d=>7}
b31f070010deeb06
b31f070010deeb06
b31f070010deeb06
b31f070010deeb06
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>172836301,c=>0,a=>32,b=>7,d=>6,f=>3}
20070600cd454d0a0300
20070600cd454d0a0300
20070600cd454d0a0300
20070600cd454d0a0300
-
{e=>127428220,c=>5,a=>-44,b=>2,d=>7,f=>1}
d42a07007c6698070100
d42a07007c6698070100
d42a07007c6698070100
d42a07007c6698070100
-
{e=>422562,c=>0,a=>60,b=>7,d=>1,f=>2}
3c070100a27206000200
3c070100a27206000200
3c070100a27206000200
3c070100a27206000200
-
{e=>96278787,c=>7,a=>3,b=>7,d=>2,f=>0}
033f02000319bd050000
033f02000319bd050000
033f02000319bd050000
033f02000319bd050000
-
{e=>241856194,c=>3,a=>-107,b=>0,d=>6,f=>5}
95180600c26e6a0e0500
95180600c26e6a0e0500
95180600c26e6a0e0500
95180600c26e6a0e0500
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>239818291,c=>6,a=>50,g=>2,b=>1,d=>2,f=>7}
3231020033564b0e1700
3231020033564b0e1700
3231020033564b0e1700
3231020033564b0e1700
-
{e=>27118579,c=>2,a=>-3,g=>0,b=>0,d=>4,f=>5}
fd100400f3cb9d010500
fd100400f3cb9d010500
fd100400f3cb9d010500
fd100400f3cb9d010500
-
{e=>134242001,c=>3,a=>59,g=>3,b=>5,d=>5,f=>6}
3b1d0500d15e00081e00
3b1d0500d15e00081e00
3b1d0500d15e00081e00
3b1d0500d15e00081e00
-
{e=>65328260,c=>1,a=>-116,g=>1,b=>5,d=>4,f=>3}
8c0d040084d4e4030b00
8c0d040084d4e4030b00
8c0d040084d4e4030b00
8c0d040084d4e4030b00
-
{e=>139743207,c=>3,a=>-41,g=>1,b=>3,d=>1,f=>6}
d71b0100e74f54080e00
d71b0100e74f54080e00
d71b0100e74f54080e00
d71b0100e74f54080e00
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>230124716,a=>16,d=>7,c=>1,h=>3908,b=>7,g=>2,f=>7}
100f0700ac6cb70d1700440f
100f0700ac6cb70d1700440f
100f0700ac6cb70d1700440f
100f0700ac6cb70d1700440f
-
{e=>124232976,a=>64,d=>4,c=>0,h=>5030,b=>2,g=>3,f=>4}
4002040010a567071c00a613
4002040010a567071c00a613
4002040010a567071c00a613
4002040010a567071c00a613
-
{e=>239963925,a=>67,d=>1,c=>5,h=>5257,b=>4,g=>2,f=>4}
432c0100158f4d0e14008914
432c0100158f4d0e14008914
432c0100158f4d0e14008914
432c0100158f4d0e14008914
-
{e=>119523408,a=>-65,d=>2,c=>5,h=>4247,b=>2,g=>2,f=>3}
bf2a020050c81f0713009710
bf2a020050c81f0713009710
bf2a020050c81f0713009710
bf2a020050c81f0713009710
-
{e=>9728961,a=>51,d=>5,c=>0,h=>2851,b=>7,g=>0,f=>4}
33070500c17394000400230b
33070500c17394000400230b
33070500c17394000400230b
33070500c17394000400230b
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>180027965,a=>92,d=>2,c=>4,h=>1057,b=>1,g=>1,f=>0,i=>60}
5c2102003d02bb0a080021043c00
5c2102003d02bb0a080021043c00
5c2102003d02bb0a080021043c00
5c2102003d02bb0a080021043c00
-
{e=>231855491,a=>-124,d=>6,c=>4,h=>1682,b=>7,g=>0,f=>6,i=>222}
8427060083d5d10d06009206de00
8427060083d5d10d06009206de00
8427060083d5d10d06009206de00
8427060083d5d10d06009206de00
-
{e=>14781907,a=>-124,d=>1,c=>0,h=>7235,b=>7,g=>0,f=>3,i=>179}
84070100d38de1000300431cb300
84070100d38de1000300431cb300
84070100d38de1000300431cb300
84070100d38de1000300431cb300
-
{e=>268185659,a=>-127,d=>4,c=>0,h=>4094,b=>2,g=>3,f=>7,i=>166}
810204003b30fc0f1f00fe0fa600
810204003b30fc0f1f00fe0fa600
810204003b30fc0f1f00fe0fa600
810204003b30fc0f1f00fe0fa600
-
{e=>102826413,a=>-10,d=>2,c=>6,h=>6758,b=>6,g=>2,f=>7,i=>80}
f6360200ad0121061700661a5000
f6360200ad0121061700661a5000
f6360200ad0121061700661a5000
f6360200ad0121061700661a5000
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  short a;
  unsigned char  b:3;
};
-
{a=>-45,b=>6}
d3ff0600
d3ff0600
d3ff0600
d3ff0600
-
{a=>-32,b=>7}
e0ff0700
e0ff0700
e0ff0700
e0ff0700
-
{a=>43,b=>2}
2b000200
2b000200
2b000200
2b000200
-
{a=>8,b=>3}
08000300
08000300
08000300
08000300
-
{a=>-1,b=>1}
ffff0100
ffff0100
ffff0100
ffff0100
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>5,a=>126,b=>7}
7e002f00
7e002f00
7e002f00
7e002f00
-
{c=>4,a=>-38,b=>6}
daff2600
daff2600
daff2600
daff2600
-
{c=>3,a=>-19,b=>2}
edff1a00
edff1a00
edff1a00
edff1a00
-
{c=>0,a=>26,b=>4}
1a000400
1a000400
1a000400
1a000400
-
{c=>4,a=>125,b=>4}
7d002400
7d002400
7d002400
7d002400
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>4,a=>66,b=>0,d=>6}
420020000600
420020000600
420020000600
420020000600
-
{c=>3,a=>-65,b=>7,d=>5}
bfff1f000500
bfff1f000500
bfff1f000500
bfff1f000500
-
{c=>5,a=>42,b=>5,d=>4}
2a002d000400
2a002d000400
2a002d000400
2a002d000400
-
{c=>1,a=>-96,b=>4,d=>5}
a0ff0c000500
a0ff0c000500
a0ff0c000500
a0ff0c000500
-
{c=>2,a=>-85,b=>0,d=>4}
abff10000400
abff10000400
abff10000400
abff10000400
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>144118602,c=>6,a=>-68,b=>2,d=>5}
bcff320005004a139708
bcff320005004a139708
bcff320005004a139708
bcff320005004a139708
-
{e=>194550170,c=>1,a=>-13,b=>2,d=>6}
f3ff0a0006009a99980b
f3ff0a0006009a99980b
f3ff0a0006009a99980b
f3ff0a0006009a99980b
-
{e=>80715514,c=>4,a=>100,b=>3,d=>0}
640023000000fa9ecf04
640023000000fa9ecf04
640023000000fa9ecf04
640023000000fa9ecf04
-
{e=>265138084,c=>6,a=>37,b=>2,d=>0}
250032000000a4afcd0f
250032000000a4afcd0f
250032000000a4afcd0f
250032000000a4afcd0f
-
{e=>222887293,c=>6,a=>11,b=>1,d=>5}
0b00310005007dfd480d
0b00310005007dfd480d
0b00310005007dfd480d
0b00310005007dfd480d
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>18626280,c=>1,a=>-46,b=>5,d=>7,f=>5}
d2ff0d000700e8361c010500
d2ff0d000700e8361c010500
d2ff0d000700e8361c010500
d2ff0d000700e8361c010500
-
{e=>65331951,c=>5,a=>-123,b=>1,d=>4,f=>2}
85ff29000400efe2e4030200
85ff29000400efe2e4030200
85ff29000400efe2e4030200
85ff29000400efe2e4030200
-
{e=>22199225,c=>6,a=>19,b=>2,d=>4,f=>0}
130032000400b9bb52010000
130032000400b9bb52010000
130032000400b9bb52010000
130032000400b9bb52010000
-
{e=>9181650,c=>6,a=>56,b=>1,d=>0,f=>5}
380031000000d2198c000500
380031000000d2198c000500
380031000000d2198c000500
380031000000d2198c000500
-
{e=>157034625,c=>6,a=>76,b=>0,d=>2,f=>5}
4c003000020081285c090500
4c003000020081285c090500
4c003000020081285c090500
4c003000020081285c090500
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>267203857,c=>2,a=>90,g=>1,b=>5,d=>0,f=>2}
5a00150000001135ed0f0a00
5a00150000001135ed0f0a00
5a00150000001135ed0f0a00
5a00150000001135ed0f0a00
-
{e=>138564760,c=>2,a=>-49,g=>2,b=>4,d=>6,f=>3}
cfff14000600985442081300
cfff14000600985442081300
cfff14000600985442081300
cfff14000600985442081300
-
{e=>91970329,c=>6,a=>-122,g=>1,b=>1,d=>3,f=>0}
86ff31000300195b7b050800
86ff31000300195b7b050800
86ff31000300195b7b050800
86ff31000300195b7b050800
-
{e=>102576163,c=>7,a=>39,g=>1,b=>0,d=>2,f=>6}
27003800020023301d060e00
27003800020023301d060e00
27003800020023301d060e00
27003800020023301d060e00
-
{e=>263662536,c=>3,a=>-27,g=>1,b=>3,d=>4,f=>5}
e5ff1b000400c82bb70f0d00
e5ff1b000400c82bb70f0d00
e5ff1b000400c82bb70f0d00
e5ff1b000400c82bb70f0d00
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>194432513,a=>30,d=>2,c=>2,h=>1472,b=>2,g=>1,f=>3}
1e001200020001ce960b0b00c005
1e001200020001ce960b0b00c005
1e001200020001ce960b0b00c005
1e001200020001ce960b0b00c005
-
{e=>90729129,a=>18,d=>7,c=>0,h=>7366,b=>1,g=>1,f=>4}
120001000700a96a68050c00c61c
120001000700a96a68050c00c61c
120001000700a96a68050c00c61c
120001000700a96a68050c00c61c
-
{e=>241644573,a=>75,d=>6,c=>6,h=>2932,b=>7,g=>3,f=>1}
4b00370006001d34670e1900740b
4b00370006001d34670e1900740b
4b00370006001d34670e1900740b
4b00370006001d34670e1900740b
-
{e=>176079331,a=>31,d=>2,c=>1,h=>4829,b=>6,g=>2,f=>2}
1f000e000200e3c17e0a1200dd12
1f000e000200e3c17e0a1200dd12
1f000e000200e3c17e0a1200dd12
1f000e000200e3c17e0a1200dd12
-
{e=>239368188,a=>55,d=>5,c=>3,h=>1857,b=>6,g=>3,f=>7}
37001e000500fc77440e1f004107
37001e000500fc77440e1f004107
37001e000500fc77440e1f004107
37001e000500fc77440e1f004107
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>108438729,a=>58,d=>1,c=>1,h=>5562,b=>0,g=>0,f=>6,i=>192}
3a0008000100c9a476060600ba15c000
3a0008000100c9a476060600ba15c000
3a0008000100c9a476060600ba15c000
3a0008000100c9a476060600ba15c000
-
{e=>5753109,a=>98,d=>6,c=>2,h=>3842,b=>0,g=>1,f=>4,i=>170}
62001000060015c957000c00020faa00
62001000060015c957000c00020faa00
62001000060015c957000c00020faa00
62001000060015c957000c00020faa00
-
{e=>152483984,a=>118,d=>4,c=>6,h=>3538,b=>4,g=>1,f=>6,i=>229}
76003400040090b816090e00d20de500
76003400040090b816090e00d20de500
76003400040090b816090e00d20de500
76003400040090b816090e00d20de500
-
{e=>54363077,a=>36,d=>6,c=>6,h=>7156,b=>2,g=>1,f=>3,i=>92}
240032000600c5833d030b00f41b5c00
240032000600c5833d030b00f41b5c00
240032000600c5833d030b00f41b5c00
240032000600c5833d030b00f41b5c00
-
{e=>73602633,a=>-19,d=>3,c=>5,h=>1654,b=>6,g=>2,f=>6,i=>188}
edff2e0003004916630416007606bc00
edff2e0003004916630416007606bc00
edff2e0003004916630416007606bc00
edff2e0003004916630416007606bc00
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  int a;
  unsigned char  b:3;
};
-
{a=>31,b=>7}
1f0000000700
1f0000000700
1f0000000700
1f0000000700
-
{a=>70,b=>7}
460000000700
460000000700
460000000700
460000000700
-
{a=>-101,b=>4}
9bffffff0400
9bffffff0400
9bffffff0400
9bffffff0400
-
{a=>111,b=>2}
6f0000000200
6f0000000200
6f0000000200
6f0000000200
-
{a=>-80,b=>3}
b0ffffff0300
b0ffffff0300
b0ffffff0300
b0ffffff0300
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>7,a=>76,b=>1}
4c0000003900
4c0000003900
4c0000003900
4c0000003900
-
{c=>6,a=>52,b=>5}
340000003500
340000003500
340000003500
340000003500
-
{c=>4,a=>-96,b=>4}
a0ffffff2400
a0ffffff2400
a0ffffff2400
a0ffffff2400
-
{c=>4,a=>16,b=>5}
100000002500
100000002500
100000002500
100000002500
-
{c=>5,a=>-115,b=>3}
8dffffff2b00
8dffffff2b00
8dffffff2b00
8dffffff2b00
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>3,a=>-95,b=>1,d=>3}
a1ffffff19000300
a1ffffff19000300
a1ffffff19000300
a1ffffff19000300
-
{c=>1,a=>-30,b=>2,d=>7}
e2ffffff0a000700
e2ffffff0a000700
e2ffffff0a000700
e2ffffff0a000700
-
{c=>3,a=>28,b=>7,d=>3}
1c0000001f000300
1c0000001f000300
1c0000001f000300
1c0000001f000300
-
{c=>1,a=>34,b=>1,d=>3}
2200000009000300
2200000009000300
2200000009000300
2200000009000300
-
{c=>5,a=>88,b=>6,d=>1}
580000002e000100
580000002e000100
580000002e000100
580000002e000100
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>228389954,c=>6,a=>10,b=>1,d=>3}
0a0000003100030042f49c0d
0a0000003100030042f49c0d
0a0000003100030042f49c0d
0a0000003100030042f49c0d
-
{e=>26173929,c=>1,a=>46,b=>7,d=>3}
2e0000000f000300e9618f01
2e0000000f000300e9618f01
2e0000000f000300e9618f01
2e0000000f000300e9618f01
-
{e=>31378561,c=>1,a=>-102,b=>0,d=>0}
9affffff0800000081ccde01
9affffff0800000081ccde01
9affffff0800000081ccde01
9affffff0800000081ccde01
-
{e=>133881414,c=>3,a=>83,b=>6,d=>6}
530000001e00060046defa07
530000001e00060046defa07
530000001e00060046defa07
530000001e00060046defa07
-
{e=>185498202,c=>4,a=>-46,b=>2,d=>4}
d2ffffff220004005a7a0e0b
d2ffffff220004005a7a0e0b
d2ffffff220004005a7a0e0b
d2ffffff220004005a7a0e0b
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>108248036,c=>1,a=>-113,b=>3,d=>5,f=>4}
8fffffff0b000500e4bb73060400
8fffffff0b000500e4bb73060400
8fffffff0b000500e4bb73060400
8fffffff0b000500e4bb73060400
-
{e=>244754857,c=>2,a=>53,b=>1,d=>6,f=>7}
3500000011000600a9a9960e0700
3500000011000600a9a9960e0700
3500000011000600a9a9960e0700
3500000011000600a9a9960e0700
-
{e=>82868130,c=>3,a=>-17,b=>3,d=>4,f=>1}
efffffff1b000400a277f0040100
efffffff1b000400a277f0040100
efffffff1b000400a277f0040100
efffffff1b000400a277f0040100
-
{e=>128771168,c=>5,a=>-97,b=>6,d=>5,f=>6}
9fffffff2e00050060e4ac070600
9fffffff2e00050060e4ac070600
9fffffff2e00050060e4ac070600
9fffffff2e00050060e4ac070600
-
{e=>201646189,c=>5,a=>87,b=>0,d=>1,f=>3}
57000000280001006de0040c0300
57000000280001006de0040c0300
57000000280001006de0040c0300
57000000280001006de0040c0300
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>52201699,c=>3,a=>-21,g=>2,b=>2,d=>3,f=>7}
ebffffff1a000300e3881c031700
ebffffff1a000300e3881c031700
ebffffff1a000300e3881c031700
ebffffff1a000300e3881c031700
-
{e=>156859917,c=>7,a=>28,g=>2,b=>4,d=>1,f=>7}
1c0000003c0001000d7e59091700
1c0000003c0001000d7e59091700
1c0000003c0001000d7e59091700
1c0000003c0001000d7e59091700
-
{e=>73487576,c=>2,a=>44,g=>3,b=>5,d=>4,f=>1}
2c00000015000400d85461041900
2c00000015000400d85461041900
2c00000015000400d85461041900
2c00000015000400d85461041900
-
{e=>172142530,c=>5,a=>101,g=>2,b=>7,d=>3,f=>5}
650000002f000300c2af420a1500
650000002f000300c2af420a1500
650000002f000300c2af420a1500
650000002f000300c2af420a1500
-
{e=>150725544,c=>6,a=>71,g=>1,b=>6,d=>0,f=>3}
4700000036000000a8e3fb080b00
4700000036000000a8e3fb080b00
4700000036000000a8e3fb080b00
4700000036000000a8e3fb080b00
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>165197259,a=>-34,d=>6,c=>6,h=>2543,b=>0,g=>1,f=>4}
deffffff30000600cbb5d8090c00ef09
deffffff30000600cbb5d8090c00ef09
deffffff30000600cbb5d8090c00ef09
deffffff30000600cbb5d8090c00ef09
-
{e=>66930837,a=>-1,d=>4,c=>3,h=>8014,b=>5,g=>2,f=>1}
ffffffff1d0004009548fd0311004e1f
ffffffff1d0004009548fd0311004e1f
ffffffff1d0004009548fd0311004e1f
ffffffff1d0004009548fd0311004e1f
-
{e=>133257048,a=>80,d=>2,c=>3,h=>7657,b=>4,g=>1,f=>2}
500000001c0002005857f1070a00e91d
500000001c0002005857f1070a00e91d
500000001c0002005857f1070a00e91d
500000001c0002005857f1070a00e91d
-
{e=>213734502,a=>-90,d=>4,c=>5,h=>5237,b=>1,g=>2,f=>0}
a6ffffff290004006654bd0c10007514
a6ffffff290004006654bd0c10007514
a6ffffff290004006654bd0c10007514
a6ffffff290004006654bd0c10007514
-
{e=>132335321,a=>121,d=>0,c=>3,h=>5451,b=>4,g=>0,f=>7}
790000001c000000d946e30707004b15
790000001c000000d946e30707004b15
790000001c000000d946e30707004b15
790000001c000000d946e30707004b15
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>54142455,a=>-77,d=>3,c=>0,h=>5806,b=>5,g=>0,f=>1,i=>177}
b3ffffff05000300f7253a030100ae16b100
b3ffffff05000300f7253a030100ae16b100
b3ffffff05000300f7253a030100ae16b100
b3ffffff05000300f7253a030100ae16b100
-
{e=>146569251,a=>-111,d=>5,c=>1,h=>6377,b=>1,g=>3,f=>2,i=>217}
91ffffff090005002378bc081a00e918d900
91ffffff090005002378bc081a00e918d900
91ffffff090005002378bc081a00e918d900
91ffffff090005002378bc081a00e918d900
-
{e=>103323231,a=>-35,d=>5,c=>3,h=>286,b=>0,g=>2,f=>5,i=>160}
ddffffff180005005f96280615001e01a000
ddffffff180005005f96280615001e01a000
ddffffff180005005f96280615001e01a000
ddffffff180005005f96280615001e01a000
-
{e=>80135875,a=>-121,d=>4,c=>6,h=>4052,b=>0,g=>0,f=>6,i=>139}
87ffffff30000400c3c6c6040600d40f8b00
87ffffff30000400c3c6c6040600d40f8b00
87ffffff30000400c3c6c6040600d40f8b00
87ffffff30000400c3c6c6040600d40f8b00
-
{e=>212259421,a=>46,d=>5,c=>2,h=>3423,b=>7,g=>2,f=>4,i=>165}
2e000000170005005dd2a60c14005f0da500
2e000000170005005dd2a60c14005f0da500
2e000000170005005dd2a60c14005f0da500
2e000000170005005dd2a60c14005f0da500
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  long a;
  unsigned char  b:3;
};
-
{a=>-17,b=>1}
efffffff0100
efffffff0100
efffffff0100
efffffff0100
-
{a=>-21,b=>5}
ebffffff0500
ebffffff0500
ebffffff0500
ebffffff0500
-
{a=>117,b=>4}
750000000400
750000000400
750000000400
750000000400
-
{a=>90,b=>5}
5a0000000500
5a0000000500
5a0000000500
5a0000000500
-
{a=>48,b=>4}
300000000400
300000000400
300000000400
300000000400
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>0,a=>16,b=>5}
100000000500
100000000500
100000000500
100000000500
-
{c=>6,a=>123,b=>0}
7b0000003000
7b0000003000
7b0000003000
7b0000003000
-
{c=>4,a=>92,b=>2}
5c0000002200
5c0000002200
5c0000002200
5c0000002200
-
{c=>4,a=>64,b=>0}
400000002000
400000002000
400000002000
400000002000
-
{c=>0,a=>-8,b=>0}
f8ffffff0000
f8ffffff0000
f8ffffff0000
f8ffffff0000
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>6,a=>124,b=>2,d=>6}
7c00000032000600
7c00000032000600
7c00000032000600
7c00000032000600
-
{c=>2,a=>-19,b=>2,d=>0}
edffffff12000000
edffffff12000000
edffffff12000000
edffffff12000000
-
{c=>5,a=>55,b=>0,d=>1}
3700000028000100
3700000028000100
3700000028000100
3700000028000100
-
{c=>5,a=>-44,b=>0,d=>7}
d4ffffff28000700
d4ffffff28000700
d4ffffff28000700
d4ffffff28000700
-
{c=>6,a=>-50,b=>1,d=>4}
ceffffff31000400
ceffffff31000400
ceffffff31000400
ceffffff31000400
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>95288597,c=>5,a=>-109,b=>2,d=>7}
93ffffff2a00070015fdad05
93ffffff2a00070015fdad05
93ffffff2a00070015fdad05
93ffffff2a00070015fdad05
-
{e=>135290620,c=>4,a=>117,b=>5,d=>5}
7500000025000500fc5e1008
7500000025000500fc5e1008
7500000025000500fc5e1008
7500000025000500fc5e1008
-
{e=>60560071,c=>0,a=>38,b=>6,d=>3}
2600000006000300c7129c03
2600000006000300c7129c03
2600000006000300c7129c03
2600000006000300c7129c03
-
{e=>3218489,c=>7,a=>-111,b=>2,d=>3}
91ffffff3a000300391c3100
91ffffff3a000300391c3100
91ffffff3a000300391c3100
91ffffff3a000300391c3100
-
{e=>124836907,c=>6,a=>-119,b=>3,d=>2}
89ffffff330002002bdc7007
89ffffff330002002bdc7007
89ffffff330002002bdc7007
89ffffff330002002bdc7007
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>12389401,c=>4,a=>83,b=>0,d=>1,f=>1}
5300000020000100190cbd000100
5300000020000100190cbd000100
5300000020000100190cbd000100
5300000020000100190cbd000100
-
{e=>142083432,c=>7,a=>-99,b=>5,d=>3,f=>3}
9dffffff3d000300680578080300
9dffffff3d000300680578080300
9dffffff3d000300680578080300
9dffffff3d000300680578080300
-
{e=>187721880,c=>2,a=>52,b=>6,d=>5,f=>2}
34000000160005009868300b0200
34000000160005009868300b0200
34000000160005009868300b0200
34000000160005009868300b0200
-
{e=>48069462,c=>5,a=>48,b=>0,d=>2,f=>4}
3000000028000200567bdd020400
3000000028000200567bdd020400
3000000028000200567bdd020400
3000000028000200567bdd020400
-
{e=>65320048,c=>4,a=>2,b=>6,d=>4,f=>3}
020000002600040070b4e4030300
020000002600040070b4e4030300
020000002600040070b4e4030300
020000002600040070b4e4030300
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>260512924,c=>0,a=>13,g=>3,b=>2,d=>7,f=>5}
0d000000020007009c1c870f1d00
0d000000020007009c1c870f1d00
0d000000020007009c1c870f1d00
0d000000020007009c1c870f1d00
-
{e=>57231972,c=>0,a=>50,g=>1,b=>1,d=>1,f=>1}
3200000001000100644a69030900
3200000001000100644a69030900
3200000001000100644a69030900
3200000001000100644a69030900
-
{e=>202592947,c=>7,a=>-82,g=>2,b=>0,d=>0,f=>6}
aeffffff38000000b352130c1600
aeffffff38000000b352130c1600
aeffffff38000000b352130c1600
aeffffff38000000b352130c1600
-
{e=>222000348,c=>7,a=>-76,g=>2,b=>4,d=>4,f=>5}
b4ffffff3c000400dc743b0d1500
b4ffffff3c000400dc743b0d1500
b4ffffff3c000400dc743b0d1500
b4ffffff3c000400dc743b0d1500
-
{e=>259177945,c=>7,a=>-89,g=>3,b=>2,d=>4,f=>1}
a7ffffff3a000400d9bd720f1900
a7ffffff3a000400d9bd720f1900
a7ffffff3a000400d9bd720f1900
a7ffffff3a000400d9bd720f1900
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>83948314,a=>-39,d=>7,c=>7,h=>5026,b=>2,g=>2,f=>5}
d9ffffff3a0007001af300051500a213
d9ffffff3a0007001af300051500a213
d9ffffff3a0007001af300051500a213
d9ffffff3a0007001af300051500a213
-
{e=>263712322,a=>73,d=>0,c=>3,h=>5678,b=>2,g=>3,f=>7}
490000001a00000042eeb70f1f002e16
490000001a00000042eeb70f1f002e16
490000001a00000042eeb70f1f002e16
490000001a00000042eeb70f1f002e16
-
{e=>29595889,a=>-74,d=>7,c=>3,h=>3087,b=>2,g=>3,f=>4}
b6ffffff1a000700f198c3011c000f0c
b6ffffff1a000700f198c3011c000f0c
b6ffffff1a000700f198c3011c000f0c
b6ffffff1a000700f198c3011c000f0c
-
{e=>229616258,a=>-13,d=>2,c=>2,h=>5537,b=>5,g=>2,f=>6}
f3ffffff1500020082aaaf0d1600a115
f3ffffff1500020082aaaf0d1600a115
f3ffffff1500020082aaaf0d1600a115
f3ffffff1500020082aaaf0d1600a115
-
{e=>192578723,a=>-50,d=>5,c=>7,h=>779,b=>7,g=>0,f=>1}
ceffffff3f000500a3847a0b01000b03
ceffffff3f000500a3847a0b01000b03
ceffffff3f000500a3847a0b01000b03
ceffffff3f000500a3847a0b01000b03
=
#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct umixed_pack_2 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>53556282,a=>93,d=>1,c=>0,h=>6233,b=>5,g=>2,f=>6,i=>8}
5d000000050001003a343103160059180800
5d000000050001003a343103160059180800
5d000000050001003a343103160059180800
5d000000050001003a343103160059180800
-
{e=>177717941,a=>-92,d=>4,c=>4,h=>2021,b=>5,g=>1,f=>5,i=>247}
a4ffffff25000400b5c2970a0d00e507f700
a4ffffff25000400b5c2970a0d00e507f700
a4ffffff25000400b5c2970a0d00e507f700
a4ffffff25000400b5c2970a0d00e507f700
-
{e=>182845399,a=>88,d=>7,c=>0,h=>1885,b=>2,g=>0,f=>7,i=>153}
5800000002000700d7ffe50a07005d079900
5800000002000700d7ffe50a07005d079900
5800000002000700d7ffe50a07005d079900
5800000002000700d7ffe50a07005d079900
-
{e=>88054627,a=>92,d=>5,c=>7,h=>765,b=>5,g=>0,f=>1,i=>252}
5c0000003d000500639b3f050100fd02fc00
5c0000003d000500639b3f050100fd02fc00
5c0000003d000500639b3f050100fd02fc00
5c0000003d000500639b3f050100fd02fc00
-
{e=>77656705,a=>-32,d=>0,c=>0,h=>6746,b=>6,g=>3,f=>4,i=>4}
e0ffffff0600000081f2a0041c005a1a0400
e0ffffff0600000081f2a0041c005a1a0400
e0ffffff0600000081f2a0041c005a1a0400
e0ffffff0600000081f2a0041c005a1a0400
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  unsigned char  a:3;
};
-
{a=>0}
00
00
00
00
-
{a=>2}
02
02
02
02
-
{a=>3}
03
03
03
03
-
{a=>4}
04
04
04
04
-
{a=>1}
01
01
01
01
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  unsigned char  a:3;
  unsigned char  b:3;
};
-
{a=>1,b=>7}
39
39
39
39
-
{a=>5,b=>4}
25
25
25
25
-
{a=>2,b=>6}
32
32
32
32
-
{a=>6,b=>0}
06
06
06
06
-
{a=>6,b=>3}
1e
1e
1e
1e
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
};
-
{c=>7,a=>2,b=>3}
1a000700
1a000700
1a000700
1a000700
-
{c=>7,a=>5,b=>5}
2d000700
2d000700
2d000700
2d000700
-
{c=>6,a=>2,b=>1}
0a000600
0a000600
0a000600
0a000600
-
{c=>2,a=>0,b=>4}
20000200
20000200
20000200
20000200
-
{c=>2,a=>0,b=>0}
00000200
00000200
00000200
00000200
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
};
-
{c=>3,a=>7,b=>1,d=>50028689}
0f0003009160fb02
0f0003009160fb02
0f0003009160fb02
0f0003009160fb02
-
{c=>0,a=>6,b=>4,d=>214060677}
26000000854ec20c
26000000854ec20c
26000000854ec20c
26000000854ec20c
-
{c=>5,a=>3,b=>2,d=>195763511}
13000500371dab0b
13000500371dab0b
13000500371dab0b
13000500371dab0b
-
{c=>3,a=>3,b=>6,d=>63439012}
33000300a400c803
33000300a400c803
33000300a400c803
33000300a400c803
-
{c=>0,a=>5,b=>5,d=>244764352}
2d000000c0ce960e
2d000000c0ce960e
2d000000c0ce960e
2d000000c0ce960e
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
};
-
{e=>3,c=>2,a=>4,b=>7,d=>224624247}
3c000200777e630d03000000
3c000200777e630d03000000
3c000200777e630d03000000
3c000200777e630d03000000
-
{e=>0,c=>1,a=>5,b=>1,d=>177052414}
0d000100fe9a8d0a00000000
0d000100fe9a8d0a00000000
0d000100fe9a8d0a00000000
0d000100fe9a8d0a00000000
-
{e=>0,c=>0,a=>2,b=>5,d=>246117108}
2a000000f472ab0e00000000
2a000000f472ab0e00000000
2a000000f472ab0e00000000
2a000000f472ab0e00000000
-
{e=>6,c=>6,a=>5,b=>7,d=>185373738}
3d0006002a940c0b06000000
3d0006002a940c0b06000000
3d0006002a940c0b06000000
3d0006002a940c0b06000000
-
{e=>5,c=>3,a=>4,b=>5,d=>54818930}
2c0003007278440305000000
2c0003007278440305000000
2c0003007278440305000000
2c0003007278440305000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
};
-
{e=>3,c=>4,a=>4,b=>0,d=>79628885,f=>3}
04000400550abf041b000000
04000400550abf041b000000
04000400550abf041b000000
04000400550abf041b000000
-
{e=>2,c=>4,a=>1,b=>5,d=>144152264,f=>2}
29000400c896970812000000
29000400c896970812000000
29000400c896970812000000
29000400c896970812000000
-
{e=>5,c=>6,a=>2,b=>0,d=>26710878,f=>3}
020006005e9397011d000000
020006005e9397011d000000
020006005e9397011d000000
020006005e9397011d000000
-
{e=>5,c=>6,a=>7,b=>4,d=>34004101,f=>1}
2700060085dc06020d000000
2700060085dc06020d000000
2700060085dc06020d000000
2700060085dc06020d000000
-
{e=>0,c=>4,a=>2,b=>1,d=>16933732,f=>1}
0a0004006463020108000000
0a0004006463020108000000
0a0004006463020108000000
0a0004006463020108000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
  unsigned short g:13;
};
-
{e=>6,c=>4,a=>7,g=>5071,b=>0,d=>231122139,f=>3}
07000400dba4c60d1e00cf13
07000400dba4c60d1e00cf13
07000400dba4c60d1e00cf13
07000400dba4c60d1e00cf13
-
{e=>6,c=>2,a=>7,g=>456,b=>3,d=>180080748,f=>0}
1f0002006cd0bb0a0600c801
1f0002006cd0bb0a0600c801
1f0002006cd0bb0a0600c801
1f0002006cd0bb0a0600c801
-
{e=>2,c=>3,a=>3,g=>5849,b=>3,d=>79209729,f=>3}
1b00030001a5b8041a00d916
1b00030001a5b8041a00d916
1b00030001a5b8041a00d916
1b00030001a5b8041a00d916
-
{e=>1,c=>3,a=>7,g=>2821,b=>0,d=>127280147,f=>3}
07000300132496071900050b
07000300132496071900050b
07000300132496071900050b
07000300132496071900050b
-
{e=>3,c=>1,a=>1,g=>507,b=>0,d=>255482069,f=>1}
01000100d5583a0f0b00fb01
01000100d5583a0f0b00fb01
01000100d5583a0f0b00fb01
01000100d5583a0f0b00fb01
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  unsigned char  a:3;
  unsigned char  b:3;
  unsigned short c:3;
  unsigned int   d:28;
  unsigned char  e:3;
  unsigned char  f:2;
  unsigned short g:13;
  unsigned char  h;
};
-
{e=>6,a=>7,d=>257420570,c=>7,h=>84,b=>1,g=>1915,f=>3}
0f0007001aed570f1e007b0754000000
0f0007001aed570f1e007b0754000000
0f0007001aed570f1e007b0754000000
0f0007001aed570f1e007b0754000000
-
{e=>5,a=>5,d=>71066412,c=>2,h=>226,b=>3,g=>1456,f=>3}
1d0002002c633c041d00b005e2000000
1d0002002c633c041d00b005e2000000
1d0002002c633c041d00b005e2000000
1d0002002c633c041d00b005e2000000
-
{e=>5,a=>0,d=>136880796,c=>4,h=>149,b=>6,g=>7356,f=>2}
300004009ca228081500bc1c95000000
300004009ca228081500bc1c95000000
300004009ca228081500bc1c95000000
300004009ca228081500bc1c95000000
-
{e=>4,a=>2,d=>230323768,c=>1,h=>107,b=>2,g=>1870,f=>0}
120001003876ba0d04004e076b000000
120001003876ba0d04004e076b000000
120001003876ba0d04004e076b000000
120001003876ba0d04004e076b000000
-
{e=>0,a=>1,d=>100150911,c=>2,h=>68,b=>6,g=>5875,f=>1}
310002007f2ef8050800f31644000000
310002007f2ef8050800f31644000000
310002007f2ef8050800f31644000000
310002007f2ef8050800f31644000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  char a;
  unsigned char  b:3;
};
-
{a=>65,b=>3}
4103
4103
4103
4103
-
{a=>6,b=>0}
0600
0600
0600
0600
-
{a=>95,b=>6}
5f06
5f06
5f06
5f06
-
{a=>-19,b=>1}
ed01
ed01
ed01
ed01
-
{a=>69,b=>7}
4507
4507
4507
4507
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>6,a=>-76,b=>3}
b433
b433
b433
b433
-
{c=>6,a=>58,b=>2}
3a32
3a32
3a32
3a32
-
{c=>0,a=>-87,b=>7}
a907
a907
a907
a907
-
{c=>5,a=>95,b=>6}
5f2e
5f2e
5f2e
5f2e
-
{c=>6,a=>69,b=>2}
4532
4532
4532
4532
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>3,a=>-39,b=>1,d=>1}
d9190100
d9190100
d9190100
d9190100
-
{c=>0,a=>-41,b=>0,d=>0}
d7000000
d7000000
d7000000
d7000000
-
{c=>4,a=>98,b=>0,d=>0}
62200000
62200000
62200000
62200000
-
{c=>0,a=>-29,b=>1,d=>5}
e3010500
e3010500
e3010500
e3010500
-
{c=>3,a=>-22,b=>1,d=>5}
ea190500
ea190500
ea190500
ea190500
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>124299546,c=>2,a=>-99,b=>6,d=>6}
9d1606001aa96807
9d1606001aa96807
9d1606001aa96807
9d1606001aa96807
-
{e=>146480008,c=>7,a=>77,b=>1,d=>1}
4d390100881bbb08
4d390100881bbb08
4d390100881bbb08
4d390100881bbb08
-
{e=>114844914,c=>3,a=>-69,b=>7,d=>6}
bb1f0600f264d806
bb1f0600f264d806
bb1f0600f264d806
bb1f0600f264d806
-
{e=>66012636,c=>0,a=>-38,b=>2,d=>6}
da020600dc45ef03
da020600dc45ef03
da020600dc45ef03
da020600dc45ef03
-
{e=>262518736,c=>0,a=>20,b=>2,d=>0}
14020000d0b7a50f
14020000d0b7a50f
14020000d0b7a50f
14020000d0b7a50f
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>262442666,c=>5,a=>-46,b=>1,d=>0,f=>1}
d2290000aa8ea40f01000000
d2290000aa8ea40f01000000
d2290000aa8ea40f01000000
d2290000aa8ea40f01000000
-
{e=>51404586,c=>7,a=>-117,b=>0,d=>7,f=>2}
8b3807002a5f100302000000
8b3807002a5f100302000000
8b3807002a5f100302000000
8b3807002a5f100302000000
-
{e=>62750320,c=>6,a=>103,b=>6,d=>5,f=>7}
67360500707ebd0307000000
67360500707ebd0307000000
67360500707ebd0307000000
67360500707ebd0307000000
-
{e=>224998807,c=>7,a=>-64,b=>3,d=>6,f=>1}
c03b06009735690d01000000
c03b06009735690d01000000
c03b06009735690d01000000
c03b06009735690d01000000
-
{e=>147103397,c=>2,a=>51,b=>5,d=>5,f=>6}
33150500a59ec40806000000
33150500a59ec40806000000
33150500a59ec40806000000
33150500a59ec40806000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>126791030,c=>2,a=>62,g=>0,b=>5,d=>3,f=>3}
3e15030076ad8e0703000000
3e15030076ad8e0703000000
3e15030076ad8e0703000000
3e15030076ad8e0703000000
-
{e=>121945673,c=>5,a=>14,g=>2,b=>7,d=>0,f=>6}
0e2f000049be440716000000
0e2f000049be440716000000
0e2f000049be440716000000
0e2f000049be440716000000
-
{e=>144073686,c=>3,a=>96,g=>1,b=>3,d=>3,f=>6}
601b0300d66396080e000000
601b0300d66396080e000000
601b0300d66396080e000000
601b0300d66396080e000000
-
{e=>215969518,c=>7,a=>-47,g=>2,b=>4,d=>4,f=>2}
d13c0400ee6edf0c12000000
d13c0400ee6edf0c12000000
d13c0400ee6edf0c12000000
d13c0400ee6edf0c12000000
-
{e=>140309850,c=>5,a=>-50,g=>1,b=>5,d=>2,f=>0}
ce2d02005af55c0808000000
ce2d02005af55c0808000000
ce2d02005af55c0808000000
ce2d02005af55c0808000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>255150489,a=>50,d=>2,c=>3,h=>5131,b=>7,g=>0,f=>5}
321f02009949350f05000b14
321f02009949350f05000b14
321f02009949350f05000b14
321f02009949350f05000b14
-
{e=>88288107,a=>30,d=>5,c=>2,h=>508,b=>1,g=>1,f=>4}
1e1105006b2b43050c00fc01
1e1105006b2b43050c00fc01
1e1105006b2b43050c00fc01
1e1105006b2b43050c00fc01
-
{e=>69089767,a=>-51,d=>7,c=>1,h=>2817,b=>4,g=>0,f=>1}
cd0c0700e7391e040100010b
cd0c0700e7391e040100010b
cd0c0700e7391e040100010b
cd0c0700e7391e040100010b
-
{e=>181343856,a=>45,d=>0,c=>7,h=>8181,b=>5,g=>0,f=>3}
2d3d00007016cf0a0300f51f
2d3d00007016cf0a0300f51f
2d3d00007016cf0a0300f51f
2d3d00007016cf0a0300f51f
-
{e=>255383303,a=>-26,d=>0,c=>4,h=>6731,b=>2,g=>0,f=>2}
e622000007d7380f02004b1a
e622000007d7380f02004b1a
e622000007d7380f02004b1a
e622000007d7380f02004b1a
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  char a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>166068539,a=>7,d=>5,c=>2,h=>5695,b=>7,g=>1,f=>6,i=>154}
071705003b01e6090e003f169a000000
071705003b01e6090e003f169a000000
071705003b01e6090e003f169a000000
071705003b01e6090e003f169a000000
-
{e=>33996722,a=>19,d=>3,c=>1,h=>5872,b=>0,g=>3,f=>4,i=>109}
13080300b2bf06021c00f0166d000000
13080300b2bf06021c00f0166d000000
13080300b2bf06021c00f0166d000000
13080300b2bf06021c00f0166d000000
-
{e=>233609477,a=>33,d=>2,c=>7,h=>5345,b=>1,g=>1,f=>4,i=>42}
213902000599ec0d0c00e1142a000000
213902000599ec0d0c00e1142a000000
213902000599ec0d0c00e1142a000000
213902000599ec0d0c00e1142a000000
-
{e=>221295631,a=>68,d=>4,c=>7,h=>2330,b=>4,g=>0,f=>7,i=>18}
443c04000fb4300d07001a0912000000
443c04000fb4300d07001a0912000000
443c04000fb4300d07001a0912000000
443c04000fb4300d07001a0912000000
-
{e=>91575618,a=>-124,d=>7,c=>1,h=>4394,b=>5,g=>0,f=>3,i=>236}
840d07004255750503002a11ec000000
840d07004255750503002a11ec000000
840d07004255750503002a11ec000000
840d07004255750503002a11ec000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  short a;
  unsigned char  b:3;
};
-
{a=>116,b=>5}
74000500
74000500
74000500
74000500
-
{a=>71,b=>2}
47000200
47000200
47000200
47000200
-
{a=>-124,b=>5}
84ff0500
84ff0500
84ff0500
84ff0500
-
{a=>80,b=>5}
50000500
50000500
50000500
50000500
-
{a=>-89,b=>4}
a7ff0400
a7ff0400
a7ff0400
a7ff0400
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>3,a=>-17,b=>0}
efff1800
efff1800
efff1800
efff1800
-
{c=>1,a=>-2,b=>7}
feff0f00
feff0f00
feff0f00
feff0f00
-
{c=>1,a=>-91,b=>5}
a5ff0d00
a5ff0d00
a5ff0d00
a5ff0d00
-
{c=>0,a=>68,b=>4}
44000400
44000400
44000400
44000400
-
{c=>7,a=>-51,b=>2}
cdff3a00
cdff3a00
cdff3a00
cdff3a00
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>5,a=>-102,b=>5,d=>2}
9aff2d000200
9aff2d000200
9aff2d000200
9aff2d000200
-
{c=>4,a=>79,b=>5,d=>3}
4f0025000300
4f0025000300
4f0025000300
4f0025000300
-
{c=>7,a=>67,b=>7,d=>4}
43003f000400
43003f000400
43003f000400
43003f000400
-
{c=>1,a=>57,b=>7,d=>4}
39000f000400
39000f000400
39000f000400
39000f000400
-
{c=>7,a=>56,b=>4,d=>2}
38003c000200
38003c000200
38003c000200
38003c000200
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>13432198,c=>4,a=>37,b=>0,d=>6}
250020000600000086f5cc00
250020000600000086f5cc00
250020000600000086f5cc00
250020000600000086f5cc00
-
{e=>56807926,c=>1,a=>40,b=>5,d=>2}
28000d0002000000f6d16203
28000d0002000000f6d16203
28000d0002000000f6d16203
28000d0002000000f6d16203
-
{e=>135705606,c=>5,a=>-117,b=>1,d=>2}
8bff29000200000006b41608
8bff29000200000006b41608
8bff29000200000006b41608
8bff29000200000006b41608
-
{e=>57461598,c=>5,a=>-92,b=>1,d=>0}
a4ff2900000000005ecb6c03
a4ff2900000000005ecb6c03
a4ff2900000000005ecb6c03
a4ff2900000000005ecb6c03
-
{e=>47673734,c=>0,a=>-17,b=>2,d=>4}
efff0200040000008671d702
efff0200040000008671d702
efff0200040000008671d702
efff0200040000008671d702
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>161341178,c=>6,a=>41,b=>3,d=>6,f=>4}
2900330006000000fade9d0904000000
2900330006000000fade9d0904000000
2900330006000000fade9d0904000000
2900330006000000fade9d0904000000
-
{e=>17636513,c=>4,a=>97,b=>1,d=>0,f=>7}
6100210000000000a11c0d0107000000
6100210000000000a11c0d0107000000
6100210000000000a11c0d0107000000
6100210000000000a11c0d0107000000
-
{e=>71589661,c=>4,a=>83,b=>1,d=>4,f=>3}
53002100040000001d5f440403000000
53002100040000001d5f440403000000
53002100040000001d5f440403000000
53002100040000001d5f440403000000
-
{e=>130474327,c=>1,a=>95,b=>0,d=>6,f=>2}
5f0008000600000057e1c60702000000
5f0008000600000057e1c60702000000
5f0008000600000057e1c60702000000
5f0008000600000057e1c60702000000
-
{e=>97397382,c=>1,a=>47,b=>1,d=>2,f=>2}
2f00090002000000862ace0502000000
2f00090002000000862ace0502000000
2f00090002000000862ace0502000000
2f00090002000000862ace0502000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>212274530,c=>6,a=>61,g=>1,b=>5,d=>1,f=>6}
3d00350001000000620da70c0e000000
3d00350001000000620da70c0e000000
3d00350001000000620da70c0e000000
3d00350001000000620da70c0e000000
-
{e=>84374245,c=>6,a=>105,g=>1,b=>3,d=>2,f=>4}
6900330002000000e57207050c000000
6900330002000000e57207050c000000
6900330002000000e57207050c000000
6900330002000000e57207050c000000
-
{e=>59588346,c=>5,a=>-128,g=>1,b=>7,d=>7,f=>2}
80ff2f0007000000fa3e8d030a000000
80ff2f0007000000fa3e8d030a000000
80ff2f0007000000fa3e8d030a000000
80ff2f0007000000fa3e8d030a000000
-
{e=>183955461,c=>3,a=>33,g=>3,b=>6,d=>7,f=>3}
21001e000700000005f0f60a1b000000
21001e000700000005f0f60a1b000000
21001e000700000005f0f60a1b000000
21001e000700000005f0f60a1b000000
-
{e=>192083138,c=>3,a=>-69,g=>3,b=>4,d=>0,f=>2}
bbff1c0000000000c2f4720b1a000000
bbff1c0000000000c2f4720b1a000000
bbff1c0000000000c2f4720b1a000000
bbff1c0000000000c2f4720b1a000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>113601201,a=>91,d=>3,c=>3,h=>3432,b=>1,g=>0,f=>2}
5b00190003000000b16ac5060200680d
5b00190003000000b16ac5060200680d
5b00190003000000b16ac5060200680d
5b00190003000000b16ac5060200680d
-
{e=>203592947,a=>15,d=>7,c=>1,h=>5527,b=>6,g=>0,f=>7}
0f000e0007000000f394220c07009715
0f000e0007000000f394220c07009715
0f000e0007000000f394220c07009715
0f000e0007000000f394220c07009715
-
{e=>20997174,a=>-60,d=>7,c=>4,h=>6515,b=>6,g=>0,f=>0}
c4ff2600070000003664400100007319
c4ff2600070000003664400100007319
c4ff2600070000003664400100007319
c4ff2600070000003664400100007319
-
{e=>235268567,a=>-47,d=>5,c=>4,h=>1813,b=>6,g=>2,f=>7}
d1ff260005000000d7e9050e17001507
d1ff260005000000d7e9050e17001507
d1ff260005000000d7e9050e17001507
d1ff260005000000d7e9050e17001507
-
{e=>104426910,a=>-85,d=>3,c=>1,h=>4758,b=>4,g=>2,f=>1}
abff0c00030000009e6d390611009612
abff0c00030000009e6d390611009612
abff0c00030000009e6d390611009612
abff0c00030000009e6d390611009612
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  short a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>12539432,a=>-13,d=>1,c=>5,h=>262,b=>4,g=>3,f=>0,i=>197}
f3ff2c00010000002856bf0018000601c5000000
f3ff2c00010000002856bf0018000601c5000000
f3ff2c00010000002856bf0018000601c5000000
f3ff2c00010000002856bf0018000601c5000000
-
{e=>121930746,a=>112,d=>4,c=>3,h=>1222,b=>7,g=>1,f=>5,i=>13}
70001f0004000000fa8344070d00c6040d000000
70001f0004000000fa8344070d00c6040d000000
70001f0004000000fa8344070d00c6040d000000
70001f0004000000fa8344070d00c6040d000000
-
{e=>212968800,a=>104,d=>5,c=>7,h=>2223,b=>4,g=>2,f=>6,i=>9}
68003c000500000060a5b10c1600af0809000000
68003c000500000060a5b10c1600af0809000000
68003c000500000060a5b10c1600af0809000000
68003c000500000060a5b10c1600af0809000000
-
{e=>48555818,a=>-18,d=>2,c=>7,h=>3063,b=>4,g=>1,f=>1,i=>165}
eeff3c00020000002ae7e4020900f70ba5000000
eeff3c00020000002ae7e4020900f70ba5000000
eeff3c00020000002ae7e4020900f70ba5000000
eeff3c00020000002ae7e4020900f70ba5000000
-
{e=>204417579,a=>18,d=>3,c=>6,h=>3751,b=>6,g=>1,f=>5,i=>20}
12003600030000002b2a2f0c0d00a70e14000000
12003600030000002b2a2f0c0d00a70e14000000
12003600030000002b2a2f0c0d00a70e14000000
12003600030000002b2a2f0c0d00a70e14000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  int a;
  unsigned char  b:3;
};
-
{a=>3,b=>1}
0300000001000000
0300000001000000
0300000001000000
0300000001000000
-
{a=>-79,b=>0}
b1ffffff00000000
b1ffffff00000000
b1ffffff00000000
b1ffffff00000000
-
{a=>22,b=>0}
1600000000000000
1600000000000000
1600000000000000
1600000000000000
-
{a=>-61,b=>4}
c3ffffff04000000
c3ffffff04000000
c3ffffff04000000
c3ffffff04000000
-
{a=>4,b=>5}
0400000005000000
0400000005000000
0400000005000000
0400000005000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>1,a=>15,b=>2}
0f0000000a000000
0f0000000a000000
0f0000000a000000
0f0000000a000000
-
{c=>6,a=>8,b=>1}
0800000031000000
0800000031000000
0800000031000000
0800000031000000
-
{c=>7,a=>20,b=>5}
140000003d000000
140000003d000000
140000003d000000
140000003d000000
-
{c=>2,a=>65,b=>6}
4100000016000000
4100000016000000
4100000016000000
4100000016000000
-
{c=>6,a=>27,b=>7}
1b00000037000000
1b00000037000000
1b00000037000000
1b00000037000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>4,a=>121,b=>6,d=>0}
7900000026000000
7900000026000000
7900000026000000
7900000026000000
-
{c=>7,a=>-95,b=>4,d=>6}
a1ffffff3c000600
a1ffffff3c000600
a1ffffff3c000600
a1ffffff3c000600
-
{c=>5,a=>-88,b=>5,d=>4}
a8ffffff2d000400
a8ffffff2d000400
a8ffffff2d000400
a8ffffff2d000400
-
{c=>6,a=>101,b=>5,d=>1}
6500000035000100
6500000035000100
6500000035000100
6500000035000100
-
{c=>7,a=>24,b=>5,d=>6}
180000003d000600
180000003d000600
180000003d000600
180000003d000600
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>169306690,c=>2,a=>21,b=>0,d=>6}
1500000010000600426a170a
1500000010000600426a170a
1500000010000600426a170a
1500000010000600426a170a
-
{e=>49555571,c=>7,a=>7,b=>1,d=>7}
07000000390007007328f402
07000000390007007328f402
07000000390007007328f402
07000000390007007328f402
-
{e=>137008742,c=>3,a=>-69,b=>1,d=>4}
bbffffff1900040066962a08
bbffffff1900040066962a08
bbffffff1900040066962a08
bbffffff1900040066962a08
-
{e=>85806609,c=>1,a=>-17,b=>5,d=>3}
efffffff0d000300114e1d05
efffffff0d000300114e1d05
efffffff0d000300114e1d05
efffffff0d000300114e1d05
-
{e=>133506977,c=>6,a=>93,b=>0,d=>6}
5d00000030000600a127f507
5d00000030000600a127f507
5d00000030000600a127f507
5d00000030000600a127f507
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>156208632,c=>7,a=>-84,b=>2,d=>2,f=>2}
acffffff3a000200f88d4f0902000000
acffffff3a000200f88d4f0902000000
acffffff3a000200f88d4f0902000000
acffffff3a000200f88d4f0902000000
-
{e=>130617554,c=>4,a=>-17,b=>6,d=>7,f=>0}
efffffff26000700d210c90700000000
efffffff26000700d210c90700000000
efffffff26000700d210c90700000000
efffffff26000700d210c90700000000
-
{e=>95191856,c=>5,a=>65,b=>4,d=>6,f=>6}
410000002c0006003083ac0506000000
410000002c0006003083ac0506000000
410000002c0006003083ac0506000000
410000002c0006003083ac0506000000
-
{e=>142523577,c=>4,a=>114,b=>5,d=>2,f=>1}
7200000025000200b9bc7e0801000000
7200000025000200b9bc7e0801000000
7200000025000200b9bc7e0801000000
7200000025000200b9bc7e0801000000
-
{e=>122537461,c=>7,a=>-44,b=>5,d=>0,f=>2}
d4ffffff3d000000f5c54d0702000000
d4ffffff3d000000f5c54d0702000000
d4ffffff3d000000f5c54d0702000000
d4ffffff3d000000f5c54d0702000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>144539243,c=>5,a=>29,g=>2,b=>5,d=>0,f=>6}
1d0000002d0000006b7e9d0816000000
1d0000002d0000006b7e9d0816000000
1d0000002d0000006b7e9d0816000000
1d0000002d0000006b7e9d0816000000
-
{e=>139635304,c=>6,a=>123,g=>2,b=>7,d=>7,f=>3}
7b0000003700070068aa520813000000
7b0000003700070068aa520813000000
7b0000003700070068aa520813000000
7b0000003700070068aa520813000000
-
{e=>8969412,c=>7,a=>-110,g=>2,b=>1,d=>2,f=>2}
92ffffff39000200c4dc880012000000
92ffffff39000200c4dc880012000000
92ffffff39000200c4dc880012000000
92ffffff39000200c4dc880012000000
-
{e=>110093836,c=>0,a=>-32,g=>3,b=>2,d=>0,f=>5}
e0ffffff020000000ce68f061d000000
e0ffffff020000000ce68f061d000000
e0ffffff020000000ce68f061d000000
e0ffffff020000000ce68f061d000000
-
{e=>18345492,c=>1,a=>14,g=>2,b=>0,d=>1,f=>1}
0e0000000800010014ee170111000000
0e0000000800010014ee170111000000
0e0000000800010014ee170111000000
0e0000000800010014ee170111000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>243213622,a=>-120,d=>4,c=>7,h=>7881,b=>7,g=>3,f=>2}
88ffffff3f00040036257f0e1a00c91e
88ffffff3f00040036257f0e1a00c91e
88ffffff3f00040036257f0e1a00c91e
88ffffff3f00040036257f0e1a00c91e
-
{e=>86919501,a=>53,d=>5,c=>5,h=>380,b=>0,g=>0,f=>0}
35000000280005004d492e0500007c01
35000000280005004d492e0500007c01
35000000280005004d492e0500007c01
35000000280005004d492e0500007c01
-
{e=>147012077,a=>32,d=>1,c=>6,h=>2230,b=>1,g=>2,f=>7}
2000000031000100ed39c3081700b608
2000000031000100ed39c3081700b608
2000000031000100ed39c3081700b608
2000000031000100ed39c3081700b608
-
{e=>23638499,a=>-48,d=>3,c=>7,h=>5753,b=>7,g=>2,f=>6}
d0ffffff3f000300e3b1680116007916
d0ffffff3f000300e3b1680116007916
d0ffffff3f000300e3b1680116007916
d0ffffff3f000300e3b1680116007916
-
{e=>136927608,a=>-38,d=>6,c=>7,h=>773,b=>3,g=>2,f=>5}
daffffff3b0006007859290815000503
daffffff3b0006007859290815000503
daffffff3b0006007859290815000503
daffffff3b0006007859290815000503
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  int a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>145884245,a=>43,d=>4,c=>7,h=>3698,b=>4,g=>0,f=>0,i=>117}
2b0000003c0004005504b2080000720e75000000
2b0000003c0004005504b2080000720e75000000
2b0000003c0004005504b2080000720e75000000
2b0000003c0004005504b2080000720e75000000
-
{e=>148618604,a=>-115,d=>5,c=>6,h=>3263,b=>7,g=>2,f=>1,i=>253}
8dffffff370005006cbddb081100bf0cfd000000
8dffffff370005006cbddb081100bf0cfd000000
8dffffff370005006cbddb081100bf0cfd000000
8dffffff370005006cbddb081100bf0cfd000000
-
{e=>226652794,a=>48,d=>5,c=>2,h=>2101,b=>4,g=>1,f=>3,i=>16}
30000000140005007a72820d0b00350810000000
30000000140005007a72820d0b00350810000000
30000000140005007a72820d0b00350810000000
30000000140005007a72820d0b00350810000000
-
{e=>137257539,a=>-126,d=>4,c=>7,h=>3963,b=>0,g=>3,f=>1,i=>27}
82ffffff3800040043622e0819007b0f1b000000
82ffffff3800040043622e0819007b0f1b000000
82ffffff3800040043622e0819007b0f1b000000
82ffffff3800040043622e0819007b0f1b000000
-
{e=>106849035,a=>-61,d=>5,c=>4,h=>1757,b=>7,g=>1,f=>5,i=>42}
c3ffffff270005000b635e060d00dd062a000000
c3ffffff270005000b635e060d00dd062a000000
c3ffffff270005000b635e060d00dd062a000000
c3ffffff270005000b635e060d00dd062a000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  long a;
  unsigned char  b:3;
};
-
{a=>72,b=>5}
4800000005000000
4800000005000000
4800000005000000
4800000005000000
-
{a=>-71,b=>1}
b9ffffff01000000
b9ffffff01000000
b9ffffff01000000
b9ffffff01000000
-
{a=>-67,b=>4}
bdffffff04000000
bdffffff04000000
bdffffff04000000
bdffffff04000000
-
{a=>-126,b=>2}
82ffffff02000000
82ffffff02000000
82ffffff02000000
82ffffff02000000
-
{a=>126,b=>2}
7e00000002000000
7e00000002000000
7e00000002000000
7e00000002000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
};
-
{c=>2,a=>122,b=>0}
7a00000010000000
7a00000010000000
7a00000010000000
7a00000010000000
-
{c=>7,a=>-32,b=>1}
e0ffffff39000000
e0ffffff39000000
e0ffffff39000000
e0ffffff39000000
-
{c=>1,a=>33,b=>2}
210000000a000000
210000000a000000
210000000a000000
210000000a000000
-
{c=>2,a=>-13,b=>6}
f3ffffff16000000
f3ffffff16000000
f3ffffff16000000
f3ffffff16000000
-
{c=>6,a=>-22,b=>1}
eaffffff31000000
eaffffff31000000
eaffffff31000000
eaffffff31000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
};
-
{c=>4,a=>-120,b=>1,d=>6}
88ffffff21000600
88ffffff21000600
88ffffff21000600
88ffffff21000600
-
{c=>6,a=>-100,b=>5,d=>5}
9cffffff35000500
9cffffff35000500
9cffffff35000500
9cffffff35000500
-
{c=>7,a=>70,b=>5,d=>2}
460000003d000200
460000003d000200
460000003d000200
460000003d000200
-
{c=>5,a=>-124,b=>3,d=>0}
84ffffff2b000000
84ffffff2b000000
84ffffff2b000000
84ffffff2b000000
-
{c=>7,a=>106,b=>6,d=>3}
6a0000003e000300
6a0000003e000300
6a0000003e000300
6a0000003e000300
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
};
-
{e=>238948103,c=>0,a=>46,b=>1,d=>7}
2e00000001000700070f3e0e
2e00000001000700070f3e0e
2e00000001000700070f3e0e
2e00000001000700070f3e0e
-
{e=>85833411,c=>2,a=>41,b=>3,d=>7}
2900000013000700c3b61d05
2900000013000700c3b61d05
2900000013000700c3b61d05
2900000013000700c3b61d05
-
{e=>85862305,c=>4,a=>-94,b=>6,d=>4}
a2ffffff26000400a1271e05
a2ffffff26000400a1271e05
a2ffffff26000400a1271e05
a2ffffff26000400a1271e05
-
{e=>89255584,c=>4,a=>26,b=>1,d=>0}
1a00000021000000a0ee5105
1a00000021000000a0ee5105
1a00000021000000a0ee5105
1a00000021000000a0ee5105
-
{e=>218745112,c=>5,a=>-41,b=>3,d=>0}
d7ffffff2b00000018c9090d
d7ffffff2b00000018c9090d
d7ffffff2b00000018c9090d
d7ffffff2b00000018c9090d
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
};
-
{e=>181902780,c=>3,a=>-112,b=>6,d=>7,f=>4}
90ffffff1e000700bc9dd70a04000000
90ffffff1e000700bc9dd70a04000000
90ffffff1e000700bc9dd70a04000000
90ffffff1e000700bc9dd70a04000000
-
{e=>243947917,c=>2,a=>-87,b=>0,d=>1,f=>7}
a9ffffff100001008d598a0e07000000
a9ffffff100001008d598a0e07000000
a9ffffff100001008d598a0e07000000
a9ffffff100001008d598a0e07000000
-
{e=>87380681,c=>3,a=>-46,b=>2,d=>3,f=>1}
d2ffffff1a000300c952350501000000
d2ffffff1a000300c952350501000000
d2ffffff1a000300c952350501000000
d2ffffff1a000300c952350501000000
-
{e=>23417204,c=>4,a=>50,b=>3,d=>0,f=>5}
32000000230000007451650105000000
32000000230000007451650105000000
32000000230000007451650105000000
32000000230000007451650105000000
-
{e=>33123043,c=>0,a=>116,b=>6,d=>0,f=>4}
7400000006000000e36af90104000000
7400000006000000e36af90104000000
7400000006000000e36af90104000000
7400000006000000e36af90104000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
};
-
{e=>84208039,c=>0,a=>14,g=>1,b=>2,d=>1,f=>0}
0e00000002000100a7e9040508000000
0e00000002000100a7e9040508000000
0e00000002000100a7e9040508000000
0e00000002000100a7e9040508000000
-
{e=>116421098,c=>1,a=>-89,g=>2,b=>6,d=>4,f=>6}
a7ffffff0e000400ea71f00616000000
a7ffffff0e000400ea71f00616000000
a7ffffff0e000400ea71f00616000000
a7ffffff0e000400ea71f00616000000
-
{e=>233446560,c=>1,a=>-126,g=>0,b=>7,d=>1,f=>0}
82ffffff0f000100a01cea0d00000000
82ffffff0f000100a01cea0d00000000
82ffffff0f000100a01cea0d00000000
82ffffff0f000100a01cea0d00000000
-
{e=>196256397,c=>2,a=>-106,g=>1,b=>1,d=>5,f=>0}
96ffffff110005008da2b20b08000000
96ffffff110005008da2b20b08000000
96ffffff110005008da2b20b08000000
96ffffff110005008da2b20b08000000
-
{e=>98949361,c=>1,a=>69,g=>3,b=>4,d=>4,f=>0}
450000000c000400f1d8e50518000000
450000000c000400f1d8e50518000000
450000000c000400f1d8e50518000000
450000000c000400f1d8e50518000000
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
};
-
{e=>154431445,a=>-110,d=>6,c=>7,h=>5540,b=>6,g=>1,f=>7}
92ffffff3e000600d56f34090f00a415
92ffffff3e000600d56f34090f00a415
92ffffff3e000600d56f34090f00a415
92ffffff3e000600d56f34090f00a415
-
{e=>175556692,a=>-125,d=>1,c=>1,h=>2798,b=>5,g=>2,f=>5}
83ffffff0d00010054c8760a1500ee0a
83ffffff0d00010054c8760a1500ee0a
83ffffff0d00010054c8760a1500ee0a
83ffffff0d00010054c8760a1500ee0a
-
{e=>165973282,a=>-23,d=>2,c=>0,h=>4321,b=>0,g=>0,f=>0}
e9ffffff00000200228de4090000e110
e9ffffff00000200228de4090000e110
e9ffffff00000200228de4090000e110
e9ffffff00000200228de4090000e110
-
{e=>13388635,a=>38,d=>7,c=>3,h=>3576,b=>1,g=>1,f=>0}
26000000190007005b4bcc000800f80d
26000000190007005b4bcc000800f80d
26000000190007005b4bcc000800f80d
26000000190007005b4bcc000800f80d
-
{e=>21214690,a=>-124,d=>3,c=>4,h=>6149,b=>0,g=>3,f=>3}
84ffffff20000300e2b543011b000518
84ffffff20000300e2b543011b000518
84ffffff20000300e2b543011b000518
84ffffff20000300e2b543011b000518
=
#if defined PACK_PAREN
#pragma pack( 4 )
#elif defined PACK_NO_PAREN
#pragma pack 4
#endif
struct umixed_pack_4 {
  long a;
  unsigned char  b:3;
  unsigned char  c:3;
  unsigned short d:3;
  unsigned int   e:28;
  unsigned char  f:3;
  unsigned char  g:2;
  unsigned short h:13;
  unsigned char  i;
};
-
{e=>130293957,a=>-6,d=>3,c=>0,h=>3224,b=>7,g=>2,f=>1,i=>96}
faffffff07000300c520c4071100980c60000000
faffffff07000300c520c4071100980c60000000
faffffff07000300c520c4071100980c60000000
faffffff07000300c520c4071100980c60000000
-
{e=>22275050,a=>24,d=>7,c=>6,h=>4511,b=>7,g=>0,f=>3,i=>194}
1800000037000700eae3530103009f11c2000000
1800000037000700eae3530103009f11c2000000
1800000037000700eae3530103009f11c2000000
1800000037000700eae3530103009f11c2000000
-
{e=>185744049,a=>-60,d=>7,c=>6,h=>1844,b=>6,g=>0,f=>2,i=>56}
c4ffffff36000700b13a120b0200340738000000
c4ffffff36000700b13a120b0200340738000000
c4ffffff36000700b13a120b0200340738000000
c4ffffff36000700b13a120b0200340738000000
-
{e=>260322633,a=>-58,d=>5,c=>5,h=>6201,b=>7,g=>2,f=>2,i=>199}
c6ffffff2f0005004935840f12003918c7000000
c6ffffff2f0005004935840f12003918c7000000
c6ffffff2f0005004935840f12003918c7000000
c6ffffff2f0005004935840f12003918c7000000
-
{e=>148496573,a=>-115,d=>0,c=>0,h=>7411,b=>3,g=>0,f=>7,i=>14}
8dffffff03000000bde0d9080700f31c0e000000
8dffffff03000000bde0d9080700f31c0e000000
8dffffff03000000bde0d9080700f31c0e000000
8dffffff03000000bde0d9080700f31c0e000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
};
-
{a=>7}
07000000
07000000
07000000
07000000
-
{a=>5}
05000000
05000000
05000000
05000000
-
{a=>5}
05000000
05000000
05000000
05000000
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>7}
07000000
07000000
07000000
07000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
};
-
{a=>5,b=>3}
1d000000
1d000000
1d000000
1d000000
-
{a=>6,b=>-4}
26000000
26000000
26000000
26000000
-
{a=>7,b=>1}
0f000000
0f000000
0f000000
0f000000
-
{a=>4,b=>2}
14000000
14000000
14000000
14000000
-
{a=>3,b=>2}
13000000
13000000
13000000
13000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
};
-
{c=>1,a=>6,b=>-4}
66000000
66000000
66000000
66000000
-
{c=>3,a=>2,b=>0}
c2000000
c2000000
c2000000
c2000000
-
{c=>1,a=>4,b=>-3}
6c000000
6c000000
6c000000
6c000000
-
{c=>-4,a=>2,b=>-4}
22010000
22010000
22010000
22010000
-
{c=>-3,a=>4,b=>-3}
6c010000
6c010000
6c010000
6c010000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
};
-
{c=>-3,a=>0,b=>-3,d=>3}
6801000003
680100000300
6801000003000000
6801000003000000
-
{c=>-4,a=>3,b=>3,d=>4}
1b01000004
1b0100000400
1b01000004000000
1b01000004000000
-
{c=>-4,a=>4,b=>3,d=>1}
1c01000001
1c0100000100
1c01000001000000
1c01000001000000
-
{c=>-1,a=>6,b=>-3,d=>0}
ee01000000
ee0100000000
ee01000000000000
ee01000000000000
-
{c=>0,a=>5,b=>2,d=>2}
1500000002
150000000200
1500000002000000
1500000002000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
};
-
{e=>0,c=>2,a=>1,b=>2,d=>6}
9100000006
910000000600
9100000006000000
9100000006000000
-
{e=>-1,c=>-2,a=>6,b=>3,d=>7}
9e0100003f
9e0100003f00
9e0100003f000000
9e0100003f000000
-
{e=>-1,c=>-2,a=>0,b=>0,d=>2}
800100003a
800100003a00
800100003a000000
800100003a000000
-
{e=>0,c=>3,a=>6,b=>-1,d=>0}
fe00000000
fe0000000000
fe00000000000000
fe00000000000000
-
{e=>3,c=>-2,a=>1,b=>0,d=>7}
810100001f
810100001f00
810100001f000000
810100001f000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
};
-
{e=>2,c=>1,a=>2,b=>-4,d=>3,f=>6}
620000001306000000
62000000130006000000
620000001300000006000000
620000001300000006000000
-
{e=>-2,c=>-2,a=>6,b=>1,d=>6,f=>0}
8e0100003600000000
8e010000360000000000
8e0100003600000000000000
8e0100003600000000000000
-
{e=>1,c=>1,a=>3,b=>-4,d=>7,f=>5}
630000000f05000000
630000000f0005000000
630000000f00000005000000
630000000f00000005000000
-
{e=>2,c=>2,a=>0,b=>-1,d=>3,f=>2}
b80000001302000000
b8000000130002000000
b80000001300000002000000
b80000001300000002000000
-
{e=>0,c=>3,a=>5,b=>2,d=>5,f=>2}
d50000000502000000
d5000000050002000000
d50000000500000002000000
d50000000500000002000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
};
-
{e=>3,c=>-4,a=>1,b=>2,d=>1,f=>1}
110100001901000000
11010000190001000000
110100001900000001000000
110100001900000001000000
-
{e=>-1,c=>-2,a=>5,b=>-1,d=>7,f=>2}
bd0100003f02000000
bd0100003f0002000000
bd0100003f00000002000000
bd0100003f00000002000000
-
{e=>-3,c=>-2,a=>2,b=>-2,d=>2,f=>3}
b20100002a03000000
b20100002a0003000000
b20100002a00000003000000
b20100002a00000003000000
-
{e=>-1,c=>-1,a=>7,b=>-1,d=>3,f=>1}
ff0100003b01000000
ff0100003b0001000000
ff0100003b00000001000000
ff0100003b00000001000000
-
{e=>-3,c=>2,a=>7,b=>-2,d=>5,f=>0}
b70000002d00000000
b70000002d0000000000
b70000002d00000000000000
b70000002d00000000000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
};
-
{e=>0,c=>3,a=>3,g=>2,b=>0,d=>2,f=>7}
c3000000020700000002
c30000000200070000000200
c3000000020000000700000002000000
c3000000020000000700000002000000
-
{e=>1,c=>3,a=>0,g=>7,b=>1,d=>1,f=>4}
c8000000090400000007
c80000000900040000000700
c8000000090000000400000007000000
c8000000090000000400000007000000
-
{e=>0,c=>3,a=>7,g=>0,b=>-2,d=>7,f=>2}
f7000000070200000000
f70000000700020000000000
f7000000070000000200000000000000
f7000000070000000200000000000000
-
{e=>-2,c=>3,a=>1,g=>2,b=>0,d=>2,f=>0}
c1000000320000000002
c10000003200000000000200
c1000000320000000000000002000000
c1000000320000000000000002000000
-
{e=>2,c=>-1,a=>7,g=>5,b=>-2,d=>6,f=>7}
f7010000160700000005
f70100001600070000000500
f7010000160000000700000005000000
f7010000160000000700000005000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
};
-
{e=>1,a=>0,d=>6,c=>-1,h=>3,b=>-1,g=>7,f=>6}
f80100000e060000001f
f80100000e00060000001f00
f80100000e000000060000001f000000
f80100000e000000060000001f000000
-
{e=>-4,a=>1,d=>3,c=>-4,h=>2,b=>2,g=>0,f=>5}
11010000230500000010
110100002300050000001000
11010000230000000500000010000000
11010000230000000500000010000000
-
{e=>2,a=>3,d=>1,c=>-4,h=>0,b=>-1,g=>0,f=>2}
3b010000110200000000
3b0100001100020000000000
3b010000110000000200000000000000
3b010000110000000200000000000000
-
{e=>-2,a=>4,d=>4,c=>2,h=>-3,b=>-4,g=>7,f=>1}
a400000034010000002f
a40000003400010000002f00
a400000034000000010000002f000000
a400000034000000010000002f000000
-
{e=>-2,a=>1,d=>2,c=>-1,h=>0,b=>-2,g=>5,f=>6}
f1010000320600000005
f10100003200060000000500
f1010000320000000600000005000000
f1010000320000000600000005000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
};
-
{e=>0,a=>3,d=>4,c=>-1,h=>3,b=>-2,g=>3,f=>4,i=>1}
f301000004040000001b01000000
f30100000400040000001b0001000000
f301000004000000040000001b00000001000000
f301000004000000040000001b00000001000000
-
{e=>2,a=>5,d=>2,c=>1,h=>2,b=>-3,g=>4,f=>0,i=>3}
6d00000012000000001403000000
6d000000120000000000140003000000
6d00000012000000000000001400000003000000
6d00000012000000000000001400000003000000
-
{e=>0,a=>5,d=>3,c=>2,h=>-3,b=>-1,g=>7,f=>7,i=>4}
bd00000003070000002f04000000
bd0000000300070000002f0004000000
bd00000003000000070000002f00000004000000
bd00000003000000070000002f00000004000000
-
{e=>-3,a=>5,d=>1,c=>1,h=>3,b=>-1,g=>3,f=>2,i=>6}
7d00000029020000001b06000000
7d0000002900020000001b0006000000
7d00000029000000020000001b00000006000000
7d00000029000000020000001b00000006000000
-
{e=>3,a=>3,d=>6,c=>1,h=>0,b=>0,g=>3,f=>2,i=>7}
430000001e020000000307000000
430000001e0002000000030007000000
430000001e000000020000000300000007000000
430000001e000000020000000300000007000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
};
-
{e=>-1,a=>4,d=>4,j=>-12,c=>2,h=>1,b=>-1,g=>7,f=>7,i=>0}
bc0000003c070000000f00000000f4
bc0000003c00070000000f0000000000f400
bc0000003c000000070000000f00000000000000f4000000
bc0000003c000000070000000f00000000000000f4000000
-
{e=>3,a=>4,d=>1,j=>93,c=>-1,h=>3,b=>-4,g=>3,f=>2,i=>6}
e401000019020000001b060000005d
e40100001900020000001b00060000005d00
e401000019000000020000001b000000060000005d000000
e401000019000000020000001b000000060000005d000000
-
{e=>1,a=>1,d=>6,j=>58,c=>-2,h=>-3,b=>3,g=>7,f=>5,i=>6}
990100000e050000002f060000003a
990100000e00050000002f00060000003a00
990100000e000000050000002f000000060000003a000000
990100000e000000050000002f000000060000003a000000
-
{e=>-2,a=>4,d=>4,j=>96,c=>3,h=>3,b=>-3,g=>6,f=>0,i=>1}
ec00000034000000001e0100000060
ec0000003400000000001e00010000006000
ec00000034000000000000001e0000000100000060000000
ec00000034000000000000001e0000000100000060000000
-
{e=>-4,a=>6,d=>7,j=>-52,c=>-2,h=>-2,b=>2,g=>5,f=>4,i=>7}
9601000027040000003507000000cc
96010000270004000000350007000000cc00
9601000027000000040000003500000007000000cc000000
9601000027000000040000003500000007000000cc000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
};
-
{e=>-4,a=>4,d=>6,j=>-110,c=>3,k=>1,h=>3,b=>-4,g=>4,f=>2,i=>5}
e400000026020000001c050000009201
e40000002600020000001c00050000009201
e400000026000000020000001c0000000500000092010000
e400000026000000020000001c0000000500000092010000
-
{e=>1,a=>1,d=>5,j=>-28,c=>-3,k=>4,h=>-4,b=>2,g=>2,f=>4,i=>2}
510100000d040000002202000000e404
510100000d0004000000220002000000e404
510100000d000000040000002200000002000000e4040000
510100000d000000040000002200000002000000e4040000
-
{e=>1,a=>0,d=>1,j=>83,c=>2,k=>7,h=>0,b=>1,g=>6,f=>5,i=>0}
88000000090500000006000000005307
880000000900050000000600000000005307
880000000900000005000000060000000000000053070000
880000000900000005000000060000000000000053070000
-
{e=>3,a=>7,d=>1,j=>-110,c=>2,k=>0,h=>0,b=>-3,g=>0,f=>4,i=>6}
af000000190400000000060000009200
af0000001900040000000000060000009200
af0000001900000004000000000000000600000092000000
af0000001900000004000000000000000600000092000000
-
{e=>-4,a=>5,d=>6,j=>-88,c=>1,k=>7,h=>-3,b=>0,g=>5,f=>2,i=>2}
4500000026020000002d02000000a807
450000002600020000002d0002000000a807
4500000026000000020000002d00000002000000a8070000
4500000026000000020000002d00000002000000a8070000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
};
-
{e=>1,a=>1,d=>5,j=>101,l=>-3,c=>-4,k=>2,h=>-2,b=>3,g=>1,f=>1,i=>2}
190100000d010000003102000000652a
190100000d0001000000310002000000652a
190100000d000000010000003100000002000000652a0000
190100000d000000010000003100000002000000652a0000
-
{e=>1,a=>6,d=>2,j=>-74,l=>0,c=>-4,k=>2,h=>-2,b=>2,g=>2,f=>0,i=>4}
160100000a000000003204000000b602
160100000a0000000000320004000000b602
160100000a000000000000003200000004000000b6020000
160100000a000000000000003200000004000000b6020000
-
{e=>3,a=>7,d=>2,j=>30,l=>2,c=>3,k=>6,h=>0,b=>-4,g=>2,f=>7,i=>6}
e70000001a0700000002060000001e16
e70000001a00070000000200060000001e16
e70000001a0000000700000002000000060000001e160000
e70000001a0000000700000002000000060000001e160000
-
{e=>-2,a=>7,d=>0,j=>-4,l=>-2,c=>-4,k=>5,h=>0,b=>0,g=>4,f=>7,i=>4}
0701000030070000000404000000fc35
07010000300007000000040004000000fc35
0701000030000000070000000400000004000000fc350000
0701000030000000070000000400000004000000fc350000
-
{e=>2,a=>0,d=>6,j=>65,l=>1,c=>-3,k=>6,h=>-3,b=>-2,g=>3,f=>1,i=>6}
7001000016010000002b06000000410e
700100001600010000002b0006000000410e
7001000016000000010000002b00000006000000410e0000
7001000016000000010000002b00000006000000410e0000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
  unsigned int  m:3;
};
-
{e=>-4,a=>6,m=>1,d=>1,j=>55,l=>-2,c=>0,k=>7,h=>-2,b=>-4,g=>1,f=>0,i=>1}
2600000021000000003101000000373701000000
26000000210000000000310001000000373701000000
26000000210000000000000031000000010000003737000001000000
26000000210000000000000031000000010000003737000001000000
-
{e=>3,a=>1,m=>6,d=>6,j=>-117,l=>-4,c=>-1,k=>5,h=>-4,b=>0,g=>2,f=>6,i=>7}
c10100001e0600000022070000008b2506000000
c10100001e00060000002200070000008b2506000000
c10100001e0000000600000022000000070000008b25000006000000
c10100001e0000000600000022000000070000008b25000006000000
-
{e=>2,a=>2,m=>4,d=>7,j=>-36,l=>3,c=>-1,k=>7,h=>3,b=>3,g=>3,f=>5,i=>5}
da01000017050000001b05000000dc1f04000000
da0100001700050000001b0005000000dc1f04000000
da01000017000000050000001b00000005000000dc1f000004000000
da01000017000000050000001b00000005000000dc1f000004000000
-
{e=>1,a=>0,m=>7,d=>6,j=>-99,l=>-1,c=>0,k=>7,h=>-4,b=>1,g=>0,f=>3,i=>1}
080000000e0300000020010000009d3f07000000
080000000e00030000002000010000009d3f07000000
080000000e0000000300000020000000010000009d3f000007000000
080000000e0000000300000020000000010000009d3f000007000000
-
{e=>1,a=>2,m=>1,d=>3,j=>57,l=>-1,c=>0,k=>5,h=>3,b=>-4,g=>4,f=>4,i=>6}
220000000b040000001c06000000393d01000000
220000000b00040000001c0006000000393d01000000
220000000b000000040000001c00000006000000393d000001000000
220000000b000000040000001c00000006000000393d000001000000
=
typedef int foo;

struct mixed_no_pack {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
  unsigned int  m:3;
  unsigned char n;
};
-
{e=>0,n=>177,a=>4,m=>2,d=>0,j=>-5,l=>-2,c=>3,k=>3,h=>-3,b=>0,g=>7,f=>7,i=>3}
c400000000070000002f03000000fb3302000000b1
c40000000000070000002f0003000000fb3302000000b100
c400000000000000070000002f00000003000000fb33000002000000b1000000
c400000000000000070000002f00000003000000fb33000002000000b1000000
-
{e=>-3,n=>5,a=>7,m=>4,d=>0,j=>90,l=>-1,c=>-1,k=>6,h=>-4,b=>3,g=>6,f=>3,i=>2}
df010000280300000026020000005a3e0400000005
df0100002800030000002600020000005a3e040000000500
df010000280000000300000026000000020000005a3e00000400000005000000
df010000280000000300000026000000020000005a3e00000400000005000000
-
{e=>-2,n=>218,a=>6,m=>2,d=>3,j=>122,l=>-3,c=>0,k=>7,h=>-3,b=>-2,g=>0,f=>1,i=>0}
36000000330100000028000000007a2f02000000da
360000003300010000002800000000007a2f02000000da00
36000000330000000100000028000000000000007a2f000002000000da000000
36000000330000000100000028000000000000007a2f000002000000da000000
-
{e=>-2,n=>245,a=>5,m=>7,d=>2,j=>-67,l=>-1,c=>3,k=>0,h=>3,b=>-2,g=>3,f=>5,i=>0}
f500000032050000001b00000000bd3807000000f5
f50000003200050000001b0000000000bd3807000000f500
f500000032000000050000001b00000000000000bd38000007000000f5000000
f500000032000000050000001b00000000000000bd38000007000000f5000000
-
{e=>3,n=>3,a=>5,m=>6,d=>6,j=>-78,l=>3,c=>-1,k=>5,h=>2,b=>2,g=>4,f=>7,i=>5}
d50100001e070000001405000000b21d0600000003
d50100001e0007000000140005000000b21d060000000300
d50100001e000000070000001400000005000000b21d00000600000003000000
d50100001e000000070000001400000005000000b21d00000600000003000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
};
-
{a=>13,b=>7}
0d07000000
0d0007000000
0d00000007000000
0d00000007000000
-
{a=>-33,b=>1}
df01000000
df0001000000
df00000001000000
df00000001000000
-
{a=>-85,b=>1}
ab01000000
ab0001000000
ab00000001000000
ab00000001000000
-
{a=>58,b=>4}
3a04000000
3a0004000000
3a00000004000000
3a00000004000000
-
{a=>18,b=>6}
1206000000
120006000000
1200000006000000
1200000006000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>-4,a=>8,b=>7}
0827000000
080027000000
0800000027000000
0800000027000000
-
{c=>2,a=>-98,b=>6}
9e16000000
9e0016000000
9e00000016000000
9e00000016000000
-
{c=>-4,a=>-119,b=>6}
8926000000
890026000000
8900000026000000
8900000026000000
-
{c=>3,a=>-114,b=>0}
8e18000000
8e0018000000
8e00000018000000
8e00000018000000
-
{c=>-4,a=>104,b=>7}
6827000000
680027000000
6800000027000000
6800000027000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>2,a=>90,b=>5,d=>-3}
5a55010000
5a0055010000
5a00000055010000
5a00000055010000
-
{c=>-3,a=>-24,b=>2,d=>-1}
e8ea010000
e800ea010000
e8000000ea010000
e8000000ea010000
-
{c=>0,a=>-46,b=>4,d=>-4}
d204010000
d20004010000
d200000004010000
d200000004010000
-
{c=>1,a=>-95,b=>5,d=>-3}
a14d010000
a1004d010000
a10000004d010000
a10000004d010000
-
{c=>3,a=>-50,b=>5,d=>-3}
ce5d010000
ce005d010000
ce0000005d010000
ce0000005d010000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>2,c=>3,a=>-67,b=>0,d=>-1}
bdd801000002
bd00d80100000200
bd000000d801000002000000
bd000000d801000002000000
-
{e=>6,c=>0,a=>-85,b=>0,d=>3}
abc000000006
ab00c00000000600
ab000000c000000006000000
ab000000c000000006000000
-
{e=>1,c=>-4,a=>27,b=>3,d=>3}
1be300000001
1b00e30000000100
1b000000e300000001000000
1b000000e300000001000000
-
{e=>3,c=>1,a=>-53,b=>7,d=>3}
cbcf00000003
cb00cf0000000300
cb000000cf00000003000000
cb000000cf00000003000000
-
{e=>4,c=>3,a=>-28,b=>2,d=>-4}
e41a01000004
e4001a0100000400
e40000001a01000004000000
e40000001a01000004000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>1,c=>-1,a=>54,b=>0,d=>-1,f=>-4}
36f801000021
3600f80100002100
36000000f801000021000000
36000000f801000021000000
-
{e=>5,c=>-2,a=>43,b=>2,d=>-2,f=>-4}
2bb201000025
2b00b20100002500
2b000000b201000025000000
2b000000b201000025000000
-
{e=>2,c=>-1,a=>57,b=>7,d=>0,f=>-3}
393f0000002a
39003f0000002a00
390000003f0000002a000000
390000003f0000002a000000
-
{e=>2,c=>-4,a=>-86,b=>0,d=>-4,f=>2}
aa2001000012
aa00200100001200
aa0000002001000012000000
aa0000002001000012000000
-
{e=>5,c=>-4,a=>36,b=>6,d=>-2,f=>1}
24a60100000d
2400a60100000d00
24000000a60100000d000000
24000000a60100000d000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>1,c=>-1,a=>-59,g=>1,b=>7,d=>-1,f=>1}
c5ff0100000901000000
c500ff010000090001000000
c5000000ff0100000900000001000000
c5000000ff0100000900000001000000
-
{e=>0,c=>-3,a=>-42,g=>3,b=>3,d=>-1,f=>3}
d6eb0100001803000000
d600eb010000180003000000
d6000000eb0100001800000003000000
d6000000eb0100001800000003000000
-
{e=>1,c=>-3,a=>-91,g=>5,b=>1,d=>1,f=>2}
a5690000001105000000
a50069000000110005000000
a5000000690000001100000005000000
a5000000690000001100000005000000
-
{e=>3,c=>-2,a=>3,g=>0,b=>1,d=>0,f=>-1}
03310000003b00000000
0300310000003b0000000000
03000000310000003b00000000000000
03000000310000003b00000000000000
-
{e=>1,c=>-2,a=>-94,g=>1,b=>0,d=>-1,f=>2}
a2f00100001101000000
a200f0010000110001000000
a2000000f00100001100000001000000
a2000000f00100001100000001000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>3,c=>3,a=>-87,g=>4,b=>0,d=>2,f=>2}
a9980000001304000000
a90098000000130004000000
a9000000980000001300000004000000
a9000000980000001300000004000000
-
{e=>3,c=>2,a=>-100,g=>0,b=>7,d=>-2,f=>-4}
9c970100002300000000
9c0097010000230000000000
9c000000970100002300000000000000
9c000000970100002300000000000000
-
{e=>4,c=>3,a=>30,g=>4,b=>0,d=>3,f=>-3}
1ed80000002c04000000
1e00d80000002c0004000000
1e000000d80000002c00000004000000
1e000000d80000002c00000004000000
-
{e=>3,c=>3,a=>117,g=>7,b=>3,d=>-3,f=>1}
755b0100000b07000000
75005b0100000b0007000000
750000005b0100000b00000007000000
750000005b0100000b00000007000000
-
{e=>4,c=>-2,a=>-117,g=>5,b=>2,d=>-1,f=>0}
8bf20100000405000000
8b00f2010000040005000000
8b000000f20100000400000005000000
8b000000f20100000400000005000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>3,a=>5,d=>-4,c=>1,h=>7,b=>0,g=>0,f=>-1}
05080100003b0000000007
0500080100003b00000000000700
05000000080100003b0000000000000007000000
05000000080100003b0000000000000007000000
-
{e=>5,a=>30,d=>-4,c=>3,h=>3,b=>7,g=>4,f=>-1}
1e1f0100003d0400000003
1e001f0100003d00040000000300
1e0000001f0100003d0000000400000003000000
1e0000001f0100003d0000000400000003000000
-
{e=>7,a=>0,d=>-3,c=>1,h=>0,b=>7,g=>2,f=>-1}
004f0100003f0200000000
00004f0100003f00020000000000
000000004f0100003f0000000200000000000000
000000004f0100003f0000000200000000000000
-
{e=>0,a=>126,d=>-3,c=>0,h=>0,b=>2,g=>5,f=>-1}
7e42010000380500000000
7e00420100003800050000000000
7e00000042010000380000000500000000000000
7e00000042010000380000000500000000000000
-
{e=>0,a=>4,d=>-1,c=>-3,h=>7,b=>2,g=>4,f=>3}
04ea010000180400000007
0400ea0100001800040000000700
04000000ea010000180000000400000007000000
04000000ea010000180000000400000007000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>2,a=>55,d=>-4,c=>-4,h=>0,b=>6,g=>4,f=>2,i=>-3}
3726010000120400000028
3700260100001200040000002800
3700000026010000120000000400000028000000
3700000026010000120000000400000028000000
-
{e=>5,a=>43,d=>1,c=>1,h=>1,b=>3,g=>7,f=>-3,i=>1}
2b4b0000002d0700000009
2b004b0000002d00070000000900
2b0000004b0000002d0000000700000009000000
2b0000004b0000002d0000000700000009000000
-
{e=>2,a=>-68,d=>-4,c=>-1,h=>6,b=>2,g=>5,f=>-3,i=>-3}
bc3a0100002a050000002e
bc003a0100002a00050000002e00
bc0000003a0100002a000000050000002e000000
bc0000003a0100002a000000050000002e000000
-
{e=>3,a=>-9,d=>2,c=>-4,h=>6,b=>3,g=>7,f=>-3,i=>1}
f7a30000002b070000000e
f700a30000002b00070000000e00
f7000000a30000002b000000070000000e000000
f7000000a30000002b000000070000000e000000
-
{e=>6,a=>-80,d=>1,c=>-2,h=>3,b=>1,g=>5,f=>3,i=>-3}
b0710000001e050000002b
b000710000001e00050000002b00
b0000000710000001e000000050000002b000000
b0000000710000001e000000050000002b000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>5,a=>114,d=>-4,j=>4,c=>3,h=>6,b=>2,g=>0,f=>-4,i=>2}
721a01000025000000001604000000
72001a010000250000000000160004000000
720000001a01000025000000000000001600000004000000
720000001a01000025000000000000001600000004000000
-
{e=>3,a=>-15,d=>-2,j=>6,c=>-1,h=>1,b=>0,g=>2,f=>2,i=>0}
f1b801000013020000000106000000
f100b8010000130002000000010006000000
f1000000b801000013000000020000000100000006000000
f1000000b801000013000000020000000100000006000000
-
{e=>6,a=>-68,d=>-2,j=>5,c=>-3,h=>1,b=>4,g=>0,f=>-1,i=>2}
bcac0100003e000000001105000000
bc00ac0100003e0000000000110005000000
bc000000ac0100003e000000000000001100000005000000
bc000000ac0100003e000000000000001100000005000000
-
{e=>4,a=>-102,d=>0,j=>1,c=>1,h=>4,b=>1,g=>0,f=>1,i=>-3}
9a090000000c000000002c01000000
9a00090000000c00000000002c0001000000
9a000000090000000c000000000000002c00000001000000
9a000000090000000c000000000000002c00000001000000
-
{e=>7,a=>-118,d=>-4,j=>3,c=>-2,h=>3,b=>3,g=>4,f=>1,i=>-1}
8a330100000f040000003b03000000
8a00330100000f00040000003b0003000000
8a000000330100000f000000040000003b00000003000000
8a000000330100000f000000040000003b00000003000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>4,a=>36,d=>-2,j=>7,c=>1,k=>-85,h=>7,b=>5,g=>7,f=>-4,i=>-3}
248d01000024070000002f07000000ab
24008d0100002400070000002f0007000000ab00
240000008d01000024000000070000002f00000007000000ab000000
240000008d01000024000000070000002f00000007000000ab000000
-
{e=>2,a=>57,d=>2,j=>6,c=>0,k=>-127,h=>0,b=>5,g=>5,f=>1,i=>-1}
39850000000a05000000380600000081
3900850000000a00050000003800060000008100
39000000850000000a00000005000000380000000600000081000000
39000000850000000a00000005000000380000000600000081000000
-
{e=>7,a=>-85,d=>1,j=>0,c=>-2,k=>-9,h=>1,b=>1,g=>4,f=>0,i=>-2}
ab7100000007040000003100000000f7
ab0071000000070004000000310000000000f700
ab0000007100000007000000040000003100000000000000f7000000
ab0000007100000007000000040000003100000000000000f7000000
-
{e=>6,a=>12,d=>3,j=>2,c=>-1,k=>-109,h=>0,b=>1,g=>1,f=>3,i=>-2}
0cf90000001e01000000300200000093
0c00f90000001e00010000003000020000009300
0c000000f90000001e00000001000000300000000200000093000000
0c000000f90000001e00000001000000300000000200000093000000
-
{e=>3,a=>-93,d=>-3,j=>3,c=>0,k=>38,h=>2,b=>4,g=>2,f=>-3,i=>-3}
a3440100002b020000002a0300000026
a300440100002b00020000002a00030000002600
a3000000440100002b000000020000002a0000000300000026000000
a3000000440100002b000000020000002a0000000300000026000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>1,a=>-121,d=>0,j=>7,l=>7,c=>-2,k=>104,h=>5,b=>5,g=>2,f=>-1,i=>-1}
873500000039020000003d070000006807
8700350000003900020000003d00070000006807
870000003500000039000000020000003d0000000700000068070000
870000003500000039000000020000003d0000000700000068070000
-
{e=>4,a=>-69,d=>0,j=>7,l=>3,c=>3,k=>116,h=>2,b=>5,g=>0,f=>2,i=>3}
bb1d00000014000000001a070000007403
bb001d0000001400000000001a00070000007403
bb0000001d00000014000000000000001a0000000700000074030000
bb0000001d00000014000000000000001a0000000700000074030000
-
{e=>7,a=>-88,d=>3,j=>2,l=>6,c=>-2,k=>94,h=>0,b=>1,g=>0,f=>-2,i=>2}
a8f1000000370000000010020000005e06
a800f10000003700000000001000020000005e06
a8000000f1000000370000000000000010000000020000005e060000
a8000000f1000000370000000000000010000000020000005e060000
-
{e=>7,a=>41,d=>1,j=>2,l=>2,c=>-2,k=>-6,h=>1,b=>4,g=>1,f=>-3,i=>2}
29740000002f010000001102000000fa02
2900740000002f0001000000110002000000fa02
29000000740000002f000000010000001100000002000000fa020000
29000000740000002f000000010000001100000002000000fa020000
-
{e=>1,a=>-123,d=>-2,j=>3,l=>7,c=>3,k=>82,h=>1,b=>6,g=>6,f=>0,i=>-3}
859e010000010600000029030000005207
85009e0100000100060000002900030000005207
850000009e0100000100000006000000290000000300000052070000
850000009e0100000100000006000000290000000300000052070000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>4,a=>-121,m=>2,d=>-2,j=>6,l=>3,c=>0,k=>-106,h=>5,b=>7,g=>4,f=>3,i=>2}
87870100001c0400000015060000009613
8700870100001c00040000001500060000009613
87000000870100001c00000004000000150000000600000096130000
87000000870100001c00000004000000150000000600000096130000
-
{e=>7,a=>-56,m=>1,d=>-1,j=>2,l=>7,c=>3,k=>102,h=>6,b=>0,g=>6,f=>-4,i=>-3}
c8d801000027060000002e02000000660f
c800d80100002700060000002e0002000000660f
c8000000d801000027000000060000002e00000002000000660f0000
c8000000d801000027000000060000002e00000002000000660f0000
-
{e=>3,a=>-72,m=>-4,d=>-1,j=>6,l=>2,c=>-1,k=>-50,h=>4,b=>2,g=>1,f=>1,i=>-3}
b8fa0100000b010000002c06000000ce22
b800fa0100000b00010000002c0006000000ce22
b8000000fa0100000b000000010000002c00000006000000ce220000
b8000000fa0100000b000000010000002c00000006000000ce220000
-
{e=>5,a=>84,m=>-4,d=>-2,j=>4,l=>0,c=>1,k=>-79,h=>5,b=>6,g=>1,f=>3,i=>1}
548e0100001d010000000d04000000b120
54008e0100001d00010000000d0004000000b120
540000008e0100001d000000010000000d00000004000000b1200000
540000008e0100001d000000010000000d00000004000000b1200000
-
{e=>6,a=>-18,m=>-2,d=>-4,j=>7,l=>4,c=>-1,k=>-2,h=>1,b=>1,g=>4,f=>3,i=>-3}
ee390100001e040000002907000000fe34
ee00390100001e0004000000290007000000fe34
ee000000390100001e000000040000002900000007000000fe340000
ee000000390100001e000000040000002900000007000000fe340000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>5,n=>6,a=>-112,m=>3,d=>-1,j=>2,l=>0,c=>-3,k=>39,h=>4,b=>6,g=>4,f=>3,i=>2}
90ee0100001d040000001402000000271806000000
9000ee0100001d0004000000140002000000271806000000
90000000ee0100001d0000000400000014000000020000002718000006000000
90000000ee0100001d0000000400000014000000020000002718000006000000
-
{e=>1,n=>2,a=>93,m=>-2,d=>2,j=>5,l=>5,c=>2,k=>-95,h=>1,b=>6,g=>0,f=>-1,i=>-3}
5d9600000039000000002905000000a13502000000
5d0096000000390000000000290005000000a13502000000
5d0000009600000039000000000000002900000005000000a135000002000000
5d0000009600000039000000000000002900000005000000a135000002000000
-
{e=>2,n=>1,a=>55,m=>2,d=>-2,j=>0,l=>0,c=>-2,k=>-97,h=>1,b=>7,g=>1,f=>3,i=>3}
37b70100001a0100000019000000009f1001000000
3700b70100001a00010000001900000000009f1001000000
37000000b70100001a0000000100000019000000000000009f10000001000000
37000000b70100001a0000000100000019000000000000009f10000001000000
-
{e=>6,n=>2,a=>2,m=>2,d=>0,j=>7,l=>5,c=>-1,k=>-32,h=>7,b=>0,g=>5,f=>-2,i=>2}
023800000036050000001707000000e01502000000
020038000000360005000000170007000000e01502000000
020000003800000036000000050000001700000007000000e015000002000000
020000003800000036000000050000001700000007000000e015000002000000
-
{e=>1,n=>2,a=>-65,m=>0,d=>-3,j=>5,l=>6,c=>-1,k=>10,h=>2,b=>2,g=>3,f=>-4,i=>2}
bf7a010000210300000012050000000a0602000000
bf007a0100002100030000001200050000000a0602000000
bf0000007a010000210000000300000012000000050000000a06000002000000
bf0000007a010000210000000300000012000000050000000a06000002000000
=
typedef int foo;

struct mixed_no_pack {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>4,n=>4,a=>96,m=>-1,d=>-4,j=>2,l=>1,c=>-2,k=>-106,h=>1,b=>4,g=>2,f=>-2,o=>172,i=>3}
603401000034020000001902000000963904000000ac
600034010000340002000000190002000000963904000000ac00
6000000034010000340000000200000019000000020000009639000004000000ac000000
6000000034010000340000000200000019000000020000009639000004000000ac000000
-
{e=>3,n=>3,a=>-103,m=>-2,d=>-1,j=>6,l=>2,c=>-3,k=>-23,h=>7,b=>7,g=>4,f=>-3,o=>204,i=>0}
99ef0100002b040000000706000000e93203000000cc
9900ef0100002b0004000000070006000000e93203000000cc00
99000000ef0100002b000000040000000700000006000000e932000003000000cc000000
99000000ef0100002b000000040000000700000006000000e932000003000000cc000000
-
{e=>7,n=>2,a=>-104,m=>3,d=>2,j=>7,l=>5,c=>2,k=>49,h=>2,b=>0,g=>0,f=>3,o=>143,i=>0}
98900000001f000000000207000000311d020000008f
9800900000001f0000000000020007000000311d020000008f00
98000000900000001f000000000000000200000007000000311d0000020000008f000000
98000000900000001f000000000000000200000007000000311d0000020000008f000000
-
{e=>7,n=>0,a=>-12,m=>1,d=>2,j=>3,l=>2,c=>3,k=>73,h=>6,b=>0,g=>3,f=>-2,o=>165,i=>-3}
f49800000037030000002e03000000490a00000000a5
f400980000003700030000002e0003000000490a00000000a500
f40000009800000037000000030000002e00000003000000490a000000000000a5000000
f40000009800000037000000030000002e00000003000000490a000000000000a5000000
-
{e=>2,n=>6,a=>-124,m=>-3,d=>-3,j=>1,l=>3,c=>-4,k=>109,h=>1,b=>5,g=>0,f=>-2,o=>55,i=>-3}
8465010000320000000029010000006d2b0600000037
8400650100003200000000002900010000006d2b060000003700
8400000065010000320000000000000029000000010000006d2b00000600000037000000
8400000065010000320000000000000029000000010000006d2b00000600000037000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
};
-
{a=>92,b=>1}
5c0001000000
5c0001000000
5c00000001000000
5c00000001000000
-
{a=>51,b=>4}
330004000000
330004000000
3300000004000000
3300000004000000
-
{a=>-66,b=>3}
beff03000000
beff03000000
beff000003000000
beff000003000000
-
{a=>-113,b=>2}
8fff02000000
8fff02000000
8fff000002000000
8fff000002000000
-
{a=>10,b=>0}
0a0000000000
0a0000000000
0a00000000000000
0a00000000000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>0,a=>-103,b=>5}
99ff05000000
99ff05000000
99ff000005000000
99ff000005000000
-
{c=>0,a=>-75,b=>2}
b5ff02000000
b5ff02000000
b5ff000002000000
b5ff000002000000
-
{c=>-4,a=>-81,b=>3}
afff23000000
afff23000000
afff000023000000
afff000023000000
-
{c=>-2,a=>14,b=>7}
0e0037000000
0e0037000000
0e00000037000000
0e00000037000000
-
{c=>0,a=>94,b=>1}
5e0001000000
5e0001000000
5e00000001000000
5e00000001000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-1,a=>-100,b=>5,d=>1}
9cff7d000000
9cff7d000000
9cff00007d000000
9cff00007d000000
-
{c=>3,a=>107,b=>2,d=>-4}
6b001a010000
6b001a010000
6b0000001a010000
6b0000001a010000
-
{c=>1,a=>-24,b=>1,d=>1}
e8ff49000000
e8ff49000000
e8ff000049000000
e8ff000049000000
-
{c=>-2,a=>-62,b=>0,d=>2}
c2ffb0000000
c2ffb0000000
c2ff0000b0000000
c2ff0000b0000000
-
{c=>0,a=>-40,b=>6,d=>-1}
d8ffc6010000
d8ffc6010000
d8ff0000c6010000
d8ff0000c6010000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>4,c=>-4,a=>-8,b=>5,d=>3}
f8ffe500000004
f8ffe50000000400
f8ff0000e500000004000000
f8ff0000e500000004000000
-
{e=>4,c=>-3,a=>-46,b=>4,d=>2}
d2ffac00000004
d2ffac0000000400
d2ff0000ac00000004000000
d2ff0000ac00000004000000
-
{e=>2,c=>0,a=>-15,b=>0,d=>-2}
f1ff8001000002
f1ff800100000200
f1ff00008001000002000000
f1ff00008001000002000000
-
{e=>6,c=>3,a=>97,b=>1,d=>-1}
6100d901000006
6100d90100000600
61000000d901000006000000
61000000d901000006000000
-
{e=>5,c=>1,a=>86,b=>2,d=>-1}
5600ca01000005
5600ca0100000500
56000000ca01000005000000
56000000ca01000005000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>2,c=>-4,a=>-30,b=>0,d=>2,f=>-4}
e2ffa000000022
e2ffa00000002200
e2ff0000a000000022000000
e2ff0000a000000022000000
-
{e=>3,c=>-2,a=>58,b=>7,d=>3,f=>-2}
3a00f700000033
3a00f70000003300
3a000000f700000033000000
3a000000f700000033000000
-
{e=>3,c=>2,a=>-93,b=>0,d=>1,f=>2}
a3ff5000000013
a3ff500000001300
a3ff00005000000013000000
a3ff00005000000013000000
-
{e=>2,c=>3,a=>17,b=>1,d=>-3,f=>2}
11005901000012
1100590100001200
110000005901000012000000
110000005901000012000000
-
{e=>3,c=>2,a=>-36,b=>3,d=>-1,f=>1}
dcffd30100000b
dcffd30100000b00
dcff0000d30100000b000000
dcff0000d30100000b000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>6,c=>3,a=>-5,g=>1,b=>4,d=>-4,f=>-4}
fbff1c0100002601000000
fbff1c010000260001000000
fbff00001c0100002600000001000000
fbff00001c0100002600000001000000
-
{e=>1,c=>0,a=>5,g=>5,b=>6,d=>-1,f=>-3}
0500c60100002905000000
0500c6010000290005000000
05000000c60100002900000005000000
05000000c60100002900000005000000
-
{e=>5,c=>-3,a=>94,g=>6,b=>0,d=>-1,f=>2}
5e00e80100001506000000
5e00e8010000150006000000
5e000000e80100001500000006000000
5e000000e80100001500000006000000
-
{e=>5,c=>-3,a=>-86,g=>4,b=>3,d=>2,f=>2}
aaffab0000001504000000
aaffab000000150004000000
aaff0000ab0000001500000004000000
aaff0000ab0000001500000004000000
-
{e=>6,c=>0,a=>-114,g=>6,b=>6,d=>-3,f=>-4}
8eff460100002606000000
8eff46010000260006000000
8eff0000460100002600000006000000
8eff0000460100002600000006000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>7,c=>-1,a=>-26,g=>4,b=>2,d=>-1,f=>-2}
e6fffa0100003704000000
e6fffa010000370004000000
e6ff0000fa0100003700000004000000
e6ff0000fa0100003700000004000000
-
{e=>3,c=>-3,a=>-39,g=>5,b=>5,d=>2,f=>3}
d9ffad0000001b05000000
d9ffad0000001b0005000000
d9ff0000ad0000001b00000005000000
d9ff0000ad0000001b00000005000000
-
{e=>2,c=>-1,a=>-108,g=>4,b=>7,d=>1,f=>0}
94ff7f0000000204000000
94ff7f000000020004000000
94ff00007f0000000200000004000000
94ff00007f0000000200000004000000
-
{e=>1,c=>3,a=>36,g=>7,b=>4,d=>1,f=>-4}
24005c0000002107000000
24005c000000210007000000
240000005c0000002100000007000000
240000005c0000002100000007000000
-
{e=>0,c=>1,a=>-70,g=>2,b=>0,d=>-3,f=>0}
baff480100000002000000
baff48010000000002000000
baff0000480100000000000002000000
baff0000480100000000000002000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>1,a=>-73,d=>3,c=>-4,h=>3,b=>3,g=>5,f=>-2}
b7ffe3000000310500000003
b7ffe30000003100050000000300
b7ff0000e3000000310000000500000003000000
b7ff0000e3000000310000000500000003000000
-
{e=>2,a=>106,d=>3,c=>-1,h=>4,b=>0,g=>6,f=>-2}
6a00f8000000320600000004
6a00f80000003200060000000400
6a000000f8000000320000000600000004000000
6a000000f8000000320000000600000004000000
-
{e=>2,a=>-78,d=>3,c=>3,h=>6,b=>0,g=>0,f=>-1}
b2ffd80000003a0000000006
b2ffd80000003a00000000000600
b2ff0000d80000003a0000000000000006000000
b2ff0000d80000003a0000000000000006000000
-
{e=>4,a=>-84,d=>-2,c=>3,h=>4,b=>3,g=>5,f=>-3}
acff9b0100002c0500000004
acff9b0100002c00050000000400
acff00009b0100002c0000000500000004000000
acff00009b0100002c0000000500000004000000
-
{e=>7,a=>-108,d=>1,c=>-4,h=>2,b=>4,g=>5,f=>-4}
94ff64000000270500000002
94ff640000002700050000000200
94ff000064000000270000000500000002000000
94ff000064000000270000000500000002000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>4,a=>113,d=>3,c=>2,h=>4,b=>1,g=>6,f=>2,i=>3}
7100d100000014060000001c
7100d10000001400060000001c00
71000000d100000014000000060000001c000000
71000000d100000014000000060000001c000000
-
{e=>7,a=>83,d=>-1,c=>3,h=>0,b=>0,g=>4,f=>-3,i=>-2}
5300d80100002f0400000030
5300d80100002f00040000003000
53000000d80100002f0000000400000030000000
53000000d80100002f0000000400000030000000
-
{e=>2,a=>-34,d=>3,c=>-4,h=>4,b=>4,g=>0,f=>1,i=>-3}
deffe40000000a000000002c
deffe40000000a00000000002c00
deff0000e40000000a000000000000002c000000
deff0000e40000000a000000000000002c000000
-
{e=>1,a=>87,d=>1,c=>0,h=>1,b=>7,g=>0,f=>1,i=>-1}
570047000000090000000039
5700470000000900000000003900
5700000047000000090000000000000039000000
5700000047000000090000000000000039000000
-
{e=>1,a=>-63,d=>3,c=>-1,h=>2,b=>1,g=>6,f=>1,i=>-3}
c1fff900000009060000002a
c1fff90000000900060000002a00
c1ff0000f900000009000000060000002a000000
c1ff0000f900000009000000060000002a000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>0,a=>-8,d=>3,j=>1,c=>-3,h=>0,b=>1,g=>7,f=>3,i=>2}
f8ffe900000018070000001001000000
f8ffe9000000180007000000100001000000
f8ff0000e900000018000000070000001000000001000000
f8ff0000e900000018000000070000001000000001000000
-
{e=>1,a=>-18,d=>-3,j=>7,c=>-4,h=>4,b=>2,g=>0,f=>3,i=>-2}
eeff6201000019000000003407000000
eeff62010000190000000000340007000000
eeff00006201000019000000000000003400000007000000
eeff00006201000019000000000000003400000007000000
-
{e=>7,a=>-19,d=>0,j=>4,c=>2,h=>1,b=>3,g=>3,f=>-4,i=>3}
edff1300000027030000001904000000
edff13000000270003000000190004000000
edff00001300000027000000030000001900000004000000
edff00001300000027000000030000001900000004000000
-
{e=>4,a=>43,d=>-3,j=>6,c=>-4,h=>4,b=>0,g=>5,f=>3,i=>-3}
2b00600100001c050000002c06000000
2b00600100001c00050000002c0006000000
2b000000600100001c000000050000002c00000006000000
2b000000600100001c000000050000002c00000006000000
-
{e=>3,a=>-3,d=>0,j=>5,c=>1,h=>7,b=>6,g=>0,f=>2,i=>1}
fdff0e00000013000000000f05000000
fdff0e0000001300000000000f0005000000
fdff00000e00000013000000000000000f00000005000000
fdff00000e00000013000000000000000f00000005000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>1,a=>29,d=>-1,j=>7,c=>-3,k=>-108,h=>1,b=>7,g=>6,f=>2,i=>-1}
1d00ef0100001106000000390700000094
1d00ef0100001100060000003900070000009400
1d000000ef0100001100000006000000390000000700000094000000
1d000000ef0100001100000006000000390000000700000094000000
-
{e=>3,a=>48,d=>1,j=>5,c=>1,k=>-74,h=>0,b=>5,g=>7,f=>-2,i=>-2}
30004d00000033070000003005000000b6
30004d000000330007000000300005000000b600
300000004d00000033000000070000003000000005000000b6000000
300000004d00000033000000070000003000000005000000b6000000
-
{e=>7,a=>-122,d=>2,j=>0,c=>-3,k=>14,h=>2,b=>1,g=>4,f=>-4,i=>0}
86ffa9000000270400000002000000000e
86ffa90000002700040000000200000000000e00
86ff0000a9000000270000000400000002000000000000000e000000
86ff0000a9000000270000000400000002000000000000000e000000
-
{e=>5,a=>-32,d=>-4,j=>2,c=>3,k=>-91,h=>7,b=>0,g=>3,f=>0,i=>2}
e0ff1801000005030000001702000000a5
e0ff18010000050003000000170002000000a500
e0ff00001801000005000000030000001700000002000000a5000000
e0ff00001801000005000000030000001700000002000000a5000000
-
{e=>4,a=>-6,d=>2,j=>0,c=>-4,k=>-31,h=>6,b=>7,g=>4,f=>1,i=>0}
faffa70000000c040000000600000000e1
faffa70000000c0004000000060000000000e100
faff0000a70000000c000000040000000600000000000000e1000000
faff0000a70000000c000000040000000600000000000000e1000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>1,a=>100,d=>-3,j=>2,l=>1,c=>-3,k=>17,h=>3,b=>6,g=>3,f=>3,i=>3}
64006e01000019030000001b020000001101
64006e0100001900030000001b00020000001101
640000006e01000019000000030000001b0000000200000011010000
640000006e01000019000000030000001b0000000200000011010000
-
{e=>3,a=>46,d=>-4,j=>5,l=>3,c=>1,k=>-95,h=>7,b=>4,g=>7,f=>0,i=>1}
2e000c01000003070000000f05000000a103
2e000c0100000300070000000f0005000000a103
2e0000000c01000003000000070000000f00000005000000a1030000
2e0000000c01000003000000070000000f00000005000000a1030000
-
{e=>3,a=>-72,d=>0,j=>6,l=>7,c=>-2,k=>41,h=>2,b=>2,g=>2,f=>2,i=>-3}
b8ff3200000013020000002a060000002907
b8ff320000001300020000002a00060000002907
b8ff00003200000013000000020000002a0000000600000029070000
b8ff00003200000013000000020000002a0000000600000029070000
-
{e=>5,a=>84,d=>-1,j=>6,l=>5,c=>2,k=>95,h=>3,b=>4,g=>4,f=>2,i=>-4}
5400d4010000150400000023060000005f05
5400d40100001500040000002300060000005f05
54000000d4010000150000000400000023000000060000005f050000
54000000d4010000150000000400000023000000060000005f050000
-
{e=>1,a=>13,d=>-2,j=>3,l=>0,c=>-3,k=>-14,h=>2,b=>5,g=>0,f=>1,i=>-4}
0d00ad01000009000000002203000000f200
0d00ad010000090000000000220003000000f200
0d000000ad01000009000000000000002200000003000000f2000000
0d000000ad01000009000000000000002200000003000000f2000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>7,a=>-88,m=>2,d=>0,j=>2,l=>5,c=>0,k=>96,h=>5,b=>0,g=>7,f=>2,i=>3}
a8ff0000000017070000001d020000006015
a8ff000000001700070000001d00020000006015
a8ff00000000000017000000070000001d0000000200000060150000
a8ff00000000000017000000070000001d0000000200000060150000
-
{e=>2,a=>-64,m=>1,d=>-2,j=>2,l=>0,c=>0,k=>83,h=>6,b=>7,g=>5,f=>-3,i=>1}
c0ff870100002a050000000e020000005308
c0ff870100002a00050000000e00020000005308
c0ff0000870100002a000000050000000e0000000200000053080000
c0ff0000870100002a000000050000000e0000000200000053080000
-
{e=>1,a=>50,m=>3,d=>0,j=>6,l=>6,c=>-4,k=>20,h=>4,b=>1,g=>7,f=>0,i=>-2}
32002100000001070000003406000000141e
320021000000010007000000340006000000141e
320000002100000001000000070000003400000006000000141e0000
320000002100000001000000070000003400000006000000141e0000
-
{e=>3,a=>-2,m=>1,d=>-1,j=>4,l=>0,c=>-1,k=>106,h=>4,b=>2,g=>6,f=>-3,i=>0}
fefffa0100002b0600000004040000006a08
fefffa0100002b00060000000400040000006a08
feff0000fa0100002b0000000600000004000000040000006a080000
feff0000fa0100002b0000000600000004000000040000006a080000
-
{e=>3,a=>126,m=>2,d=>-4,j=>7,l=>2,c=>-4,k=>-75,h=>0,b=>2,g=>7,f=>-3,i=>-2}
7e00220100002b070000003007000000b512
7e00220100002b0007000000300007000000b512
7e000000220100002b000000070000003000000007000000b5120000
7e000000220100002b000000070000003000000007000000b5120000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>0,n=>3,a=>114,m=>2,d=>1,j=>4,l=>2,c=>0,k=>-114,h=>1,b=>5,g=>1,f=>1,i=>2}
720045000000080100000011040000008e1203000000
7200450000000800010000001100040000008e1203000000
7200000045000000080000000100000011000000040000008e12000003000000
7200000045000000080000000100000011000000040000008e12000003000000
-
{e=>0,n=>2,a=>11,m=>1,d=>-2,j=>4,l=>7,c=>-4,k=>-117,h=>6,b=>1,g=>5,f=>1,i=>3}
0b00a101000008050000001e040000008b0f02000000
0b00a10100000800050000001e00040000008b0f02000000
0b000000a101000008000000050000001e000000040000008b0f000002000000
0b000000a101000008000000050000001e000000040000008b0f000002000000
-
{e=>5,n=>4,a=>8,m=>0,d=>2,j=>7,l=>3,c=>3,k=>71,h=>7,b=>2,g=>4,f=>-4,i=>2}
08009a00000025040000001707000000470304000000
08009a000000250004000000170007000000470304000000
080000009a000000250000000400000017000000070000004703000004000000
080000009a000000250000000400000017000000070000004703000004000000
-
{e=>4,n=>5,a=>25,m=>1,d=>2,j=>3,l=>7,c=>-1,k=>-69,h=>4,b=>5,g=>6,f=>1,i=>-1}
1900bd0000000c060000003c03000000bb0f05000000
1900bd0000000c00060000003c0003000000bb0f05000000
19000000bd0000000c000000060000003c00000003000000bb0f000005000000
19000000bd0000000c000000060000003c00000003000000bb0f000005000000
-
{e=>1,n=>3,a=>71,m=>3,d=>-1,j=>0,l=>0,c=>-2,k=>28,h=>1,b=>7,g=>3,f=>0,i=>1}
4700f7010000010300000009000000001c1803000000
4700f70100000100030000000900000000001c1803000000
47000000f7010000010000000300000009000000000000001c18000003000000
47000000f7010000010000000300000009000000000000001c18000003000000
=
typedef int foo;

struct mixed_no_pack {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>2,n=>2,a=>-53,m=>-1,d=>2,j=>2,l=>6,c=>-3,k=>-55,h=>7,b=>3,g=>6,f=>3,o=>97,i=>-4}
cbffab0000001a060000002702000000c93e0200000061
cbffab0000001a0006000000270002000000c93e020000006100
cbff0000ab0000001a000000060000002700000002000000c93e00000200000061000000
cbff0000ab0000001a000000060000002700000002000000c93e00000200000061000000
-
{e=>0,n=>6,a=>-59,m=>1,d=>0,j=>6,l=>4,c=>0,k=>75,h=>2,b=>6,g=>7,f=>3,o=>144,i=>2}
c5ff06000000180700000012060000004b0c0600000090
c5ff060000001800070000001200060000004b0c060000009000
c5ff000006000000180000000700000012000000060000004b0c00000600000090000000
c5ff000006000000180000000700000012000000060000004b0c00000600000090000000
-
{e=>1,n=>1,a=>66,m=>2,d=>-3,j=>0,l=>3,c=>1,k=>103,h=>4,b=>3,g=>7,f=>-1,o=>216,i=>-2}
42004b01000039070000003400000000671301000000d8
42004b010000390007000000340000000000671301000000d800
420000004b010000390000000700000034000000000000006713000001000000d8000000
420000004b010000390000000700000034000000000000006713000001000000d8000000
-
{e=>2,n=>1,a=>-81,m=>-1,d=>3,j=>0,l=>3,c=>-2,k=>98,h=>2,b=>1,g=>3,f=>-2,o=>209,i=>-3}
affff100000032030000002a00000000623b01000000d1
affff10000003200030000002a0000000000623b01000000d100
afff0000f100000032000000030000002a00000000000000623b000001000000d1000000
afff0000f100000032000000030000002a00000000000000623b000001000000d1000000
-
{e=>1,n=>5,a=>-91,m=>-1,d=>-1,j=>3,l=>5,c=>-1,k=>-46,h=>2,b=>4,g=>6,f=>-2,o=>161,i=>-3}
a5fffc01000031060000002a03000000d23d05000000a1
a5fffc0100003100060000002a0003000000d23d05000000a100
a5ff0000fc01000031000000060000002a00000003000000d23d000005000000a1000000
a5ff0000fc01000031000000060000002a00000003000000d23d000005000000a1000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
};
-
{a=>55,b=>2}
3700000002000000
3700000002000000
3700000002000000
3700000002000000
-
{a=>62,b=>5}
3e00000005000000
3e00000005000000
3e00000005000000
3e00000005000000
-
{a=>127,b=>2}
7f00000002000000
7f00000002000000
7f00000002000000
7f00000002000000
-
{a=>-95,b=>4}
a1ffffff04000000
a1ffffff04000000
a1ffffff04000000
a1ffffff04000000
-
{a=>-58,b=>4}
c6ffffff04000000
c6ffffff04000000
c6ffffff04000000
c6ffffff04000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>1,a=>-70,b=>7}
baffffff0f000000
baffffff0f000000
baffffff0f000000
baffffff0f000000
-
{c=>0,a=>-56,b=>5}
c8ffffff05000000
c8ffffff05000000
c8ffffff05000000
c8ffffff05000000
-
{c=>-2,a=>-48,b=>2}
d0ffffff32000000
d0ffffff32000000
d0ffffff32000000
d0ffffff32000000
-
{c=>1,a=>31,b=>2}
1f0000000a000000
1f0000000a000000
1f0000000a000000
1f0000000a000000
-
{c=>3,a=>120,b=>2}
780000001a000000
780000001a000000
780000001a000000
780000001a000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-4,a=>-120,b=>6,d=>0}
88ffffff26000000
88ffffff26000000
88ffffff26000000
88ffffff26000000
-
{c=>0,a=>118,b=>7,d=>3}
76000000c7000000
76000000c7000000
76000000c7000000
76000000c7000000
-
{c=>-2,a=>-76,b=>5,d=>2}
b4ffffffb5000000
b4ffffffb5000000
b4ffffffb5000000
b4ffffffb5000000
-
{c=>3,a=>-39,b=>6,d=>3}
d9ffffffde000000
d9ffffffde000000
d9ffffffde000000
d9ffffffde000000
-
{c=>-3,a=>9,b=>5,d=>1}
090000006d000000
090000006d000000
090000006d000000
090000006d000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>3,c=>3,a=>-74,b=>2,d=>3}
b6ffffffda00000003
b6ffffffda0000000300
b6ffffffda00000003000000
b6ffffffda00000003000000
-
{e=>4,c=>2,a=>16,b=>7,d=>2}
100000009700000004
10000000970000000400
100000009700000004000000
100000009700000004000000
-
{e=>2,c=>0,a=>48,b=>5,d=>-3}
300000004501000002
30000000450100000200
300000004501000002000000
300000004501000002000000
-
{e=>5,c=>2,a=>77,b=>3,d=>1}
4d0000005300000005
4d000000530000000500
4d0000005300000005000000
4d0000005300000005000000
-
{e=>0,c=>-2,a=>78,b=>5,d=>1}
4e0000007500000000
4e000000750000000000
4e0000007500000000000000
4e0000007500000000000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>1,c=>2,a=>80,b=>4,d=>1,f=>0}
500000005400000001
50000000540000000100
500000005400000001000000
500000005400000001000000
-
{e=>6,c=>2,a=>-27,b=>4,d=>3,f=>-4}
e5ffffffd400000026
e5ffffffd40000002600
e5ffffffd400000026000000
e5ffffffd400000026000000
-
{e=>0,c=>2,a=>-111,b=>5,d=>3,f=>-4}
91ffffffd500000020
91ffffffd50000002000
91ffffffd500000020000000
91ffffffd500000020000000
-
{e=>7,c=>1,a=>-42,b=>7,d=>1,f=>3}
d6ffffff4f0000001f
d6ffffff4f0000001f00
d6ffffff4f0000001f000000
d6ffffff4f0000001f000000
-
{e=>5,c=>0,a=>90,b=>4,d=>0,f=>0}
5a0000000400000005
5a000000040000000500
5a0000000400000005000000
5a0000000400000005000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>3,c=>0,a=>0,g=>3,b=>3,d=>1,f=>-3}
00000000430000002b03000000
00000000430000002b0003000000
00000000430000002b00000003000000
00000000430000002b00000003000000
-
{e=>3,c=>-4,a=>-62,g=>6,b=>1,d=>-3,f=>1}
c2ffffff610100000b06000000
c2ffffff610100000b0006000000
c2ffffff610100000b00000006000000
c2ffffff610100000b00000006000000
-
{e=>2,c=>-3,a=>26,g=>5,b=>3,d=>0,f=>-4}
1a0000002b0000002205000000
1a0000002b000000220005000000
1a0000002b0000002200000005000000
1a0000002b0000002200000005000000
-
{e=>3,c=>3,a=>-96,g=>7,b=>7,d=>-3,f=>3}
a0ffffff5f0100001b07000000
a0ffffff5f0100001b0007000000
a0ffffff5f0100001b00000007000000
a0ffffff5f0100001b00000007000000
-
{e=>6,c=>2,a=>-81,g=>5,b=>1,d=>-1,f=>3}
afffffffd10100001e05000000
afffffffd10100001e0005000000
afffffffd10100001e00000005000000
afffffffd10100001e00000005000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>4,c=>2,a=>21,g=>1,b=>4,d=>-4,f=>3}
15000000140100001c01000000
15000000140100001c0001000000
15000000140100001c00000001000000
15000000140100001c00000001000000
-
{e=>3,c=>-4,a=>82,g=>4,b=>5,d=>3,f=>1}
52000000e50000000b04000000
52000000e50000000b0004000000
52000000e50000000b00000004000000
52000000e50000000b00000004000000
-
{e=>2,c=>-3,a=>28,g=>5,b=>2,d=>0,f=>-4}
1c0000002a0000002205000000
1c0000002a000000220005000000
1c0000002a0000002200000005000000
1c0000002a0000002200000005000000
-
{e=>4,c=>2,a=>116,g=>2,b=>3,d=>-2,f=>0}
74000000930100000402000000
7400000093010000040002000000
74000000930100000400000002000000
74000000930100000400000002000000
-
{e=>5,c=>-2,a=>77,g=>7,b=>6,d=>-1,f=>3}
4d000000f60100001d07000000
4d000000f60100001d0007000000
4d000000f60100001d00000007000000
4d000000f60100001d00000007000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>6,a=>-106,d=>0,c=>-3,h=>5,b=>4,g=>2,f=>0}
96ffffff2c000000060200000005
96ffffff2c0000000600020000000500
96ffffff2c000000060000000200000005000000
96ffffff2c000000060000000200000005000000
-
{e=>2,a=>41,d=>-3,c=>-3,h=>1,b=>0,g=>7,f=>-4}
2900000068010000220700000001
29000000680100002200070000000100
2900000068010000220000000700000001000000
2900000068010000220000000700000001000000
-
{e=>7,a=>-97,d=>2,c=>2,h=>5,b=>3,g=>1,f=>-3}
9fffffff930000002f0100000005
9fffffff930000002f00010000000500
9fffffff930000002f0000000100000005000000
9fffffff930000002f0000000100000005000000
-
{e=>2,a=>-90,d=>-1,c=>-4,h=>4,b=>0,g=>0,f=>3}
a6ffffffe00100001a0000000004
a6ffffffe00100001a00000000000400
a6ffffffe00100001a0000000000000004000000
a6ffffffe00100001a0000000000000004000000
-
{e=>6,a=>106,d=>-3,c=>2,h=>7,b=>7,g=>4,f=>-3}
6a000000570100002e0400000007
6a000000570100002e00040000000700
6a000000570100002e0000000400000007000000
6a000000570100002e0000000400000007000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>6,a=>-65,d=>-4,c=>-4,h=>6,b=>0,g=>5,f=>3,i=>-4}
bfffffff200100001e0500000026
bfffffff200100001e00050000002600
bfffffff200100001e0000000500000026000000
bfffffff200100001e0000000500000026000000
-
{e=>5,a=>-32,d=>-2,c=>1,h=>1,b=>6,g=>1,f=>0,i=>1}
e0ffffff8e010000050100000009
e0ffffff8e0100000500010000000900
e0ffffff8e010000050000000100000009000000
e0ffffff8e010000050000000100000009000000
-
{e=>5,a=>-95,d=>-3,c=>2,h=>7,b=>5,g=>2,f=>3,i=>-3}
a1ffffff550100001d020000002f
a1ffffff550100001d00020000002f00
a1ffffff550100001d000000020000002f000000
a1ffffff550100001d000000020000002f000000
-
{e=>3,a=>-22,d=>-1,c=>-1,h=>6,b=>6,g=>7,f=>-4,i=>-3}
eafffffffe01000023070000002e
eafffffffe0100002300070000002e00
eafffffffe01000023000000070000002e000000
eafffffffe01000023000000070000002e000000
-
{e=>6,a=>-103,d=>-1,c=>0,h=>2,b=>2,g=>7,f=>-2,i=>-4}
99ffffffc2010000360700000022
99ffffffc20100003600070000002200
99ffffffc2010000360000000700000022000000
99ffffffc2010000360000000700000022000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>7,a=>87,d=>-2,j=>7,c=>-2,h=>2,b=>2,g=>2,f=>-2,i=>2}
57000000b201000037020000001207000000
57000000b2010000370002000000120007000000
57000000b201000037000000020000001200000007000000
57000000b201000037000000020000001200000007000000
-
{e=>3,a=>-126,d=>-4,j=>4,c=>0,h=>0,b=>6,g=>1,f=>-2,i=>-4}
82ffffff0601000033010000002004000000
82ffffff06010000330001000000200004000000
82ffffff0601000033000000010000002000000004000000
82ffffff0601000033000000010000002000000004000000
-
{e=>5,a=>90,d=>0,j=>7,c=>3,h=>0,b=>5,g=>6,f=>-1,i=>-1}
5a0000001d0000003d060000003807000000
5a0000001d0000003d0006000000380007000000
5a0000001d0000003d000000060000003800000007000000
5a0000001d0000003d000000060000003800000007000000
-
{e=>6,a=>-47,d=>1,j=>3,c=>1,h=>4,b=>7,g=>7,f=>3,i=>-1}
d1ffffff4f0000001e070000003c03000000
d1ffffff4f0000001e00070000003c0003000000
d1ffffff4f0000001e000000070000003c00000003000000
d1ffffff4f0000001e000000070000003c00000003000000
-
{e=>6,a=>47,d=>2,j=>7,c=>1,h=>4,b=>6,g=>1,f=>0,i=>-4}
2f0000008e00000006010000002407000000
2f0000008e000000060001000000240007000000
2f0000008e00000006000000010000002400000007000000
2f0000008e00000006000000010000002400000007000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>4,a=>-69,d=>1,j=>5,c=>-2,k=>-25,h=>4,b=>3,g=>1,f=>3,i=>1}
bbffffff730000001c010000000c05000000e7
bbffffff730000001c00010000000c0005000000e700
bbffffff730000001c000000010000000c00000005000000e7000000
bbffffff730000001c000000010000000c00000005000000e7000000
-
{e=>1,a=>116,d=>0,j=>4,c=>2,k=>45,h=>6,b=>3,g=>3,f=>-2,i=>3}
740000001300000031030000001e040000002d
74000000130000003100030000001e00040000002d00
740000001300000031000000030000001e000000040000002d000000
740000001300000031000000030000001e000000040000002d000000
-
{e=>3,a=>-113,d=>1,j=>1,c=>0,k=>-27,h=>5,b=>5,g=>6,f=>-3,i=>-2}
8fffffff450000002b060000003501000000e5
8fffffff450000002b0006000000350001000000e500
8fffffff450000002b000000060000003500000001000000e5000000
8fffffff450000002b000000060000003500000001000000e5000000
-
{e=>3,a=>49,d=>3,j=>2,c=>-2,k=>3,h=>1,b=>0,g=>2,f=>2,i=>2}
31000000f00000001302000000110200000003
31000000f00000001300020000001100020000000300
31000000f00000001300000002000000110000000200000003000000
31000000f00000001300000002000000110000000200000003000000
-
{e=>0,a=>105,d=>-1,j=>3,c=>-3,k=>-114,h=>6,b=>5,g=>7,f=>-2,i=>3}
69000000ed01000030070000001e030000008e
69000000ed0100003000070000001e00030000008e00
69000000ed01000030000000070000001e000000030000008e000000
69000000ed01000030000000070000001e000000030000008e000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>4,a=>-33,d=>-3,j=>2,l=>4,c=>2,k=>-127,h=>2,b=>1,g=>3,f=>0,i=>3}
dfffffff5101000004030000001a020000008104
dfffffff510100000400030000001a00020000008104
dfffffff5101000004000000030000001a0000000200000081040000
dfffffff5101000004000000030000001a0000000200000081040000
-
{e=>1,a=>30,d=>0,j=>3,l=>5,c=>-2,k=>-10,h=>5,b=>0,g=>3,f=>2,i=>-2}
1e0000003000000011030000003503000000f605
1e00000030000000110003000000350003000000f605
1e0000003000000011000000030000003500000003000000f6050000
1e0000003000000011000000030000003500000003000000f6050000
-
{e=>0,a=>87,d=>-1,j=>5,l=>6,c=>-2,k=>-45,h=>2,b=>7,g=>1,f=>3,i=>-2}
57000000f701000018010000003205000000d306
57000000f7010000180001000000320005000000d306
57000000f701000018000000010000003200000005000000d3060000
57000000f701000018000000010000003200000005000000d3060000
-
{e=>1,a=>-27,d=>2,j=>3,l=>0,c=>1,k=>36,h=>0,b=>0,g=>5,f=>0,i=>-1}
e5ffffff88000000010500000038030000002400
e5ffffff880000000100050000003800030000002400
e5ffffff880000000100000005000000380000000300000024000000
e5ffffff880000000100000005000000380000000300000024000000
-
{e=>7,a=>38,d=>2,j=>1,l=>5,c=>-2,k=>37,h=>5,b=>5,g=>5,f=>1,i=>-1}
26000000b50000000f050000003d010000002505
26000000b50000000f00050000003d00010000002505
26000000b50000000f000000050000003d0000000100000025050000
26000000b50000000f000000050000003d0000000100000025050000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>4,a=>-77,m=>-1,d=>-4,j=>3,l=>6,c=>0,k=>2,h=>7,b=>7,g=>3,f=>1,i=>1}
b3ffffff070100000c030000000f03000000023e
b3ffffff070100000c00030000000f0003000000023e
b3ffffff070100000c000000030000000f00000003000000023e0000
b3ffffff070100000c000000030000000f00000003000000023e0000
-
{e=>6,a=>-85,m=>-1,d=>0,j=>6,l=>2,c=>2,k=>121,h=>4,b=>0,g=>5,f=>-4,i=>3}
abffffff1000000026050000001c06000000793a
abffffff100000002600050000001c0006000000793a
abffffff1000000026000000050000001c00000006000000793a0000
abffffff1000000026000000050000001c00000006000000793a0000
-
{e=>0,a=>63,m=>-1,d=>3,j=>3,l=>1,c=>-1,k=>54,h=>5,b=>0,g=>0,f=>1,i=>-4}
3f000000f8000000080000000025030000003639
3f000000f80000000800000000002500030000003639
3f000000f80000000800000000000000250000000300000036390000
3f000000f80000000800000000000000250000000300000036390000
-
{e=>5,a=>3,m=>-4,d=>1,j=>0,l=>5,c=>-3,k=>-15,h=>4,b=>6,g=>2,f=>1,i=>1}
030000006e0000000d020000000c00000000f125
030000006e0000000d00020000000c0000000000f125
030000006e0000000d000000020000000c00000000000000f1250000
030000006e0000000d000000020000000c00000000000000f1250000
-
{e=>1,a=>93,m=>0,d=>3,j=>0,l=>2,c=>0,k=>57,h=>6,b=>0,g=>4,f=>-1,i=>2}
5d000000c0000000390400000016000000003902
5d000000c00000003900040000001600000000003902
5d000000c00000003900000004000000160000000000000039020000
5d000000c00000003900000004000000160000000000000039020000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>6,n=>5,a=>93,m=>1,d=>1,j=>3,l=>1,c=>-2,k=>115,h=>3,b=>0,g=>2,f=>1,i=>1}
5d000000700000000e020000000b03000000730905000000
5d000000700000000e00020000000b0003000000730905000000
5d000000700000000e000000020000000b000000030000007309000005000000
5d000000700000000e000000020000000b000000030000007309000005000000
-
{e=>7,n=>6,a=>-112,m=>1,d=>-2,j=>2,l=>1,c=>-1,k=>66,h=>1,b=>5,g=>3,f=>-4,i=>3}
90ffffffbd01000027030000001902000000420906000000
90ffffffbd010000270003000000190002000000420906000000
90ffffffbd010000270000000300000019000000020000004209000006000000
90ffffffbd010000270000000300000019000000020000004209000006000000
-
{e=>7,n=>1,a=>102,m=>3,d=>3,j=>3,l=>6,c=>1,k=>-50,h=>5,b=>6,g=>7,f=>1,i=>1}
66000000ce0000000f070000000d03000000ce1e01000000
66000000ce0000000f00070000000d0003000000ce1e01000000
66000000ce0000000f000000070000000d00000003000000ce1e000001000000
66000000ce0000000f000000070000000d00000003000000ce1e000001000000
-
{e=>3,n=>6,a=>-108,m=>1,d=>-4,j=>4,l=>4,c=>-3,k=>85,h=>3,b=>7,g=>7,f=>-1,i=>1}
94ffffff2f0100003b070000000b04000000550c06000000
94ffffff2f0100003b00070000000b0004000000550c06000000
94ffffff2f0100003b000000070000000b00000004000000550c000006000000
94ffffff2f0100003b000000070000000b00000004000000550c000006000000
-
{e=>3,n=>5,a=>103,m=>1,d=>-3,j=>3,l=>2,c=>0,k=>103,h=>3,b=>4,g=>1,f=>1,i=>0}
67000000440100000b010000000303000000670a05000000
67000000440100000b0001000000030003000000670a05000000
67000000440100000b000000010000000300000003000000670a000005000000
67000000440100000b000000010000000300000003000000670a000005000000
=
typedef int foo;

struct mixed_no_pack {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>6,n=>5,a=>-4,m=>-2,d=>-1,j=>4,l=>2,c=>-1,k=>-4,h=>5,b=>5,g=>2,f=>-2,o=>251,i=>1}
fcfffffffd01000036020000000d04000000fc3205000000fb
fcfffffffd0100003600020000000d0004000000fc3205000000fb00
fcfffffffd01000036000000020000000d00000004000000fc32000005000000fb000000
fcfffffffd01000036000000020000000d00000004000000fc32000005000000fb000000
-
{e=>5,n=>7,a=>100,m=>-4,d=>-4,j=>4,l=>2,c=>0,k=>-86,h=>1,b=>5,g=>0,f=>2,o=>180,i=>-2}
640000000501000015000000003104000000aa2207000000b4
6400000005010000150000000000310004000000aa2207000000b400
640000000501000015000000000000003100000004000000aa22000007000000b4000000
640000000501000015000000000000003100000004000000aa22000007000000b4000000
-
{e=>6,n=>7,a=>-56,m=>-2,d=>-3,j=>5,l=>0,c=>-3,k=>122,h=>4,b=>7,g=>2,f=>1,o=>254,i=>0}
c8ffffff6f0100000e0200000004050000007a3007000000fe
c8ffffff6f0100000e00020000000400050000007a3007000000fe00
c8ffffff6f0100000e0000000200000004000000050000007a30000007000000fe000000
c8ffffff6f0100000e0000000200000004000000050000007a30000007000000fe000000
-
{e=>1,n=>5,a=>-64,m=>-2,d=>1,j=>0,l=>1,c=>-3,k=>77,h=>7,b=>1,g=>4,f=>-1,o=>3,i=>-2}
c0ffffff69000000390400000037000000004d310500000003
c0ffffff690000003900040000003700000000004d31050000000300
c0ffffff69000000390000000400000037000000000000004d3100000500000003000000
c0ffffff69000000390000000400000037000000000000004d3100000500000003000000
-
{e=>5,n=>6,a=>-59,m=>-3,d=>0,j=>4,l=>3,c=>-3,k=>47,h=>3,b=>7,g=>0,f=>0,o=>16,i=>2}
c5ffffff2f000000050000000013040000002f2b0600000010
c5ffffff2f0000000500000000001300040000002f2b060000001000
c5ffffff2f000000050000000000000013000000040000002f2b00000600000010000000
c5ffffff2f000000050000000000000013000000040000002f2b00000600000010000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
};
-
{a=>-106,b=>7}
96ffffff07000000
96ffffff07000000
96ffffff07000000
96ffffff07000000
-
{a=>-127,b=>2}
81ffffff02000000
81ffffff02000000
81ffffff02000000
81ffffff02000000
-
{a=>-66,b=>6}
beffffff06000000
beffffff06000000
beffffff06000000
beffffff06000000
-
{a=>49,b=>6}
3100000006000000
3100000006000000
3100000006000000
3100000006000000
-
{a=>107,b=>7}
6b00000007000000
6b00000007000000
6b00000007000000
6b00000007000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>0,a=>-18,b=>6}
eeffffff06000000
eeffffff06000000
eeffffff06000000
eeffffff06000000
-
{c=>-3,a=>-10,b=>6}
f6ffffff2e000000
f6ffffff2e000000
f6ffffff2e000000
f6ffffff2e000000
-
{c=>2,a=>40,b=>4}
2800000014000000
2800000014000000
2800000014000000
2800000014000000
-
{c=>-2,a=>-97,b=>3}
9fffffff33000000
9fffffff33000000
9fffffff33000000
9fffffff33000000
-
{c=>0,a=>-24,b=>3}
e8ffffff03000000
e8ffffff03000000
e8ffffff03000000
e8ffffff03000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>2,a=>-99,b=>5,d=>-3}
9dffffff55010000
9dffffff55010000
9dffffff55010000
9dffffff55010000
-
{c=>-3,a=>102,b=>4,d=>1}
660000006c000000
660000006c000000
660000006c000000
660000006c000000
-
{c=>-4,a=>108,b=>1,d=>2}
6c000000a1000000
6c000000a1000000
6c000000a1000000
6c000000a1000000
-
{c=>1,a=>-81,b=>6,d=>3}
afffffffce000000
afffffffce000000
afffffffce000000
afffffffce000000
-
{c=>2,a=>-53,b=>2,d=>2}
cbffffff92000000
cbffffff92000000
cbffffff92000000
cbffffff92000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>2,c=>2,a=>62,b=>7,d=>0}
3e0000001700000002
3e000000170000000200
3e0000001700000002000000
3e0000001700000002000000
-
{e=>0,c=>1,a=>-91,b=>7,d=>1}
a5ffffff4f00000000
a5ffffff4f0000000000
a5ffffff4f00000000000000
a5ffffff4f00000000000000
-
{e=>3,c=>-1,a=>50,b=>3,d=>0}
320000003b00000003
320000003b0000000300
320000003b00000003000000
320000003b00000003000000
-
{e=>2,c=>-1,a=>-68,b=>2,d=>2}
bcffffffba00000002
bcffffffba0000000200
bcffffffba00000002000000
bcffffffba00000002000000
-
{e=>5,c=>2,a=>67,b=>4,d=>1}
430000005400000005
43000000540000000500
430000005400000005000000
430000005400000005000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>1,c=>3,a=>-33,b=>2,d=>-3,f=>-3}
dfffffff5a01000029
dfffffff5a0100002900
dfffffff5a01000029000000
dfffffff5a01000029000000
-
{e=>6,c=>-4,a=>-3,b=>1,d=>-3,f=>1}
fdffffff610100000e
fdffffff610100000e00
fdffffff610100000e000000
fdffffff610100000e000000
-
{e=>5,c=>-2,a=>-125,b=>1,d=>-3,f=>-3}
83ffffff710100002d
83ffffff710100002d00
83ffffff710100002d000000
83ffffff710100002d000000
-
{e=>7,c=>-2,a=>101,b=>3,d=>-2,f=>-1}
65000000b30100003f
65000000b30100003f00
65000000b30100003f000000
65000000b30100003f000000
-
{e=>1,c=>-2,a=>71,b=>4,d=>3,f=>2}
47000000f400000011
47000000f40000001100
47000000f400000011000000
47000000f400000011000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>5,c=>0,a=>56,g=>7,b=>1,d=>-1,f=>2}
38000000c10100001507000000
38000000c1010000150007000000
38000000c10100001500000007000000
38000000c10100001500000007000000
-
{e=>6,c=>-4,a=>-45,g=>2,b=>2,d=>-1,f=>-1}
d3ffffffe20100003e02000000
d3ffffffe20100003e0002000000
d3ffffffe20100003e00000002000000
d3ffffffe20100003e00000002000000
-
{e=>7,c=>-4,a=>-101,g=>3,b=>1,d=>1,f=>-3}
9bffffff610000002f03000000
9bffffff610000002f0003000000
9bffffff610000002f00000003000000
9bffffff610000002f00000003000000
-
{e=>0,c=>3,a=>62,g=>5,b=>2,d=>-3,f=>-4}
3e0000005a0100002005000000
3e0000005a010000200005000000
3e0000005a0100002000000005000000
3e0000005a0100002000000005000000
-
{e=>6,c=>3,a=>102,g=>2,b=>6,d=>1,f=>-1}
660000005e0000003e02000000
660000005e0000003e0002000000
660000005e0000003e00000002000000
660000005e0000003e00000002000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>0,c=>-3,a=>-101,g=>1,b=>2,d=>0,f=>-3}
9bffffff2a0000002801000000
9bffffff2a000000280001000000
9bffffff2a0000002800000001000000
9bffffff2a0000002800000001000000
-
{e=>5,c=>-4,a=>-95,g=>4,b=>4,d=>-4,f=>-1}
a1ffffff240100003d04000000
a1ffffff240100003d0004000000
a1ffffff240100003d00000004000000
a1ffffff240100003d00000004000000
-
{e=>0,c=>0,a=>60,g=>4,b=>4,d=>2,f=>-3}
3c000000840000002804000000
3c00000084000000280004000000
3c000000840000002800000004000000
3c000000840000002800000004000000
-
{e=>4,c=>2,a=>-72,g=>5,b=>2,d=>1,f=>-2}
b8ffffff520000003405000000
b8ffffff52000000340005000000
b8ffffff520000003400000005000000
b8ffffff520000003400000005000000
-
{e=>4,c=>1,a=>-29,g=>7,b=>2,d=>-1,f=>2}
e3ffffffca0100001407000000
e3ffffffca010000140007000000
e3ffffffca0100001400000007000000
e3ffffffca0100001400000007000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>1,a=>23,d=>2,c=>-2,h=>0,b=>2,g=>4,f=>-3}
17000000b2000000290400000000
17000000b20000002900040000000000
17000000b2000000290000000400000000000000
17000000b2000000290000000400000000000000
-
{e=>7,a=>-108,d=>3,c=>0,h=>1,b=>7,g=>7,f=>-2}
94ffffffc7000000370700000001
94ffffffc70000003700070000000100
94ffffffc7000000370000000700000001000000
94ffffffc7000000370000000700000001000000
-
{e=>5,a=>-126,d=>2,c=>1,h=>3,b=>4,g=>0,f=>3}
82ffffff8c0000001d0000000003
82ffffff8c0000001d00000000000300
82ffffff8c0000001d0000000000000003000000
82ffffff8c0000001d0000000000000003000000
-
{e=>4,a=>-62,d=>3,c=>-4,h=>1,b=>2,g=>2,f=>-3}
c2ffffffe20000002c0200000001
c2ffffffe20000002c00020000000100
c2ffffffe20000002c0000000200000001000000
c2ffffffe20000002c0000000200000001000000
-
{e=>0,a=>89,d=>-3,c=>3,h=>0,b=>7,g=>3,f=>2}
590000005f010000100300000000
590000005f0100001000030000000000
590000005f010000100000000300000000000000
590000005f010000100000000300000000000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>6,a=>16,d=>1,c=>-4,h=>1,b=>7,g=>3,f=>-3,i=>0}
10000000670000002e0300000001
10000000670000002e00030000000100
10000000670000002e0000000300000001000000
10000000670000002e0000000300000001000000
-
{e=>6,a=>62,d=>0,c=>1,h=>2,b=>0,g=>5,f=>-3,i=>2}
3e000000080000002e0500000012
3e000000080000002e00050000001200
3e000000080000002e0000000500000012000000
3e000000080000002e0000000500000012000000
-
{e=>3,a=>-95,d=>-2,c=>3,h=>7,b=>3,g=>7,f=>-4,i=>0}
a1ffffff9b010000230700000007
a1ffffff9b0100002300070000000700
a1ffffff9b010000230000000700000007000000
a1ffffff9b010000230000000700000007000000
-
{e=>6,a=>-45,d=>1,c=>0,h=>1,b=>6,g=>3,f=>-1,i=>1}
d3ffffff460000003e0300000009
d3ffffff460000003e00030000000900
d3ffffff460000003e0000000300000009000000
d3ffffff460000003e0000000300000009000000
-
{e=>1,a=>-122,d=>1,c=>0,h=>4,b=>1,g=>4,f=>0,i=>3}
86ffffff4100000001040000001c
86ffffff410000000100040000001c00
86ffffff4100000001000000040000001c000000
86ffffff4100000001000000040000001c000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>1,a=>-114,d=>2,j=>5,c=>1,h=>4,b=>1,g=>6,f=>2,i=>-4}
8effffff8900000011060000002405000000
8effffff89000000110006000000240005000000
8effffff8900000011000000060000002400000005000000
8effffff8900000011000000060000002400000005000000
-
{e=>2,a=>-60,d=>-3,j=>3,c=>-1,h=>6,b=>2,g=>1,f=>3,i=>0}
c4ffffff7a0100001a010000000603000000
c4ffffff7a0100001a0001000000060003000000
c4ffffff7a0100001a000000010000000600000003000000
c4ffffff7a0100001a000000010000000600000003000000
-
{e=>3,a=>51,d=>1,j=>5,c=>-4,h=>6,b=>7,g=>3,f=>2,i=>2}
330000006700000013030000001605000000
3300000067000000130003000000160005000000
330000006700000013000000030000001600000005000000
330000006700000013000000030000001600000005000000
-
{e=>4,a=>-121,d=>-1,j=>3,c=>-3,h=>5,b=>3,g=>5,f=>1,i=>-1}
87ffffffeb0100000c050000003d03000000
87ffffffeb0100000c00050000003d0003000000
87ffffffeb0100000c000000050000003d00000003000000
87ffffffeb0100000c000000050000003d00000003000000
-
{e=>4,a=>80,d=>3,j=>5,c=>-1,h=>2,b=>0,g=>4,f=>-2,i=>0}
50000000f800000034040000000205000000
50000000f8000000340004000000020005000000
50000000f800000034000000040000000200000005000000
50000000f800000034000000040000000200000005000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>6,a=>-88,d=>3,j=>5,c=>-3,k=>-40,h=>0,b=>6,g=>6,f=>1,i=>-2}
a8ffffffee0000000e060000003005000000d8
a8ffffffee0000000e0006000000300005000000d800
a8ffffffee0000000e000000060000003000000005000000d8000000
a8ffffffee0000000e000000060000003000000005000000d8000000
-
{e=>2,a=>100,d=>-2,j=>0,c=>-2,k=>126,h=>4,b=>0,g=>2,f=>-3,i=>-4}
64000000b00100002a0200000024000000007e
64000000b00100002a00020000002400000000007e00
64000000b00100002a0000000200000024000000000000007e000000
64000000b00100002a0000000200000024000000000000007e000000
-
{e=>3,a=>-69,d=>2,j=>7,c=>2,k=>33,h=>6,b=>6,g=>0,f=>1,i=>-1}
bbffffff960000000b000000003e0700000021
bbffffff960000000b00000000003e00070000002100
bbffffff960000000b000000000000003e0000000700000021000000
bbffffff960000000b000000000000003e0000000700000021000000
-
{e=>4,a=>68,d=>0,j=>5,c=>-1,k=>-97,h=>7,b=>4,g=>1,f=>-1,i=>3}
440000003c0000003c010000001f050000009f
440000003c0000003c00010000001f00050000009f00
440000003c0000003c000000010000001f000000050000009f000000
440000003c0000003c000000010000001f000000050000009f000000
-
{e=>3,a=>-64,d=>-4,j=>1,c=>0,k=>-12,h=>3,b=>3,g=>2,f=>2,i=>0}
c0ffffff0301000013020000000301000000f4
c0ffffff03010000130002000000030001000000f400
c0ffffff0301000013000000020000000300000001000000f4000000
c0ffffff0301000013000000020000000300000001000000f4000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>7,a=>19,d=>-2,j=>6,l=>1,c=>3,k=>-48,h=>6,b=>3,g=>4,f=>2,i=>3}
130000009b01000017040000001e06000000d001
130000009b0100001700040000001e0006000000d001
130000009b01000017000000040000001e00000006000000d0010000
130000009b01000017000000040000001e00000006000000d0010000
-
{e=>2,a=>-64,d=>-1,j=>0,l=>2,c=>-4,k=>-102,h=>5,b=>4,g=>0,f=>-4,i=>0}
c0ffffffe4010000220000000005000000009a02
c0ffffffe40100002200000000000500000000009a02
c0ffffffe4010000220000000000000005000000000000009a020000
c0ffffffe4010000220000000000000005000000000000009a020000
-
{e=>6,a=>32,d=>3,j=>6,l=>7,c=>0,k=>-18,h=>6,b=>2,g=>6,f=>3,i=>-4}
20000000c20000001e060000002606000000ee07
20000000c20000001e0006000000260006000000ee07
20000000c20000001e000000060000002600000006000000ee070000
20000000c20000001e000000060000002600000006000000ee070000
-
{e=>4,a=>12,d=>0,j=>4,l=>0,c=>1,k=>-60,h=>6,b=>2,g=>0,f=>3,i=>-4}
0c0000000a0000001c000000002604000000c400
0c0000000a0000001c0000000000260004000000c400
0c0000000a0000001c000000000000002600000004000000c4000000
0c0000000a0000001c000000000000002600000004000000c4000000
-
{e=>1,a=>126,d=>-3,j=>3,l=>3,c=>-2,k=>127,h=>6,b=>2,g=>7,f=>3,i=>-2}
7e00000072010000190700000036030000007f03
7e000000720100001900070000003600030000007f03
7e00000072010000190000000700000036000000030000007f030000
7e00000072010000190000000700000036000000030000007f030000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>7,a=>41,m=>-2,d=>-2,j=>7,l=>3,c=>-2,k=>100,h=>7,b=>4,g=>4,f=>3,i=>2}
29000000b40100001f0400000017070000006433
29000000b40100001f00040000001700070000006433
29000000b40100001f00000004000000170000000700000064330000
29000000b40100001f00000004000000170000000700000064330000
-
{e=>0,a=>-34,m=>-1,d=>-1,j=>1,l=>4,c=>-4,k=>120,h=>0,b=>4,g=>1,f=>0,i=>1}
deffffffe401000000010000000801000000783c
deffffffe4010000000001000000080001000000783c
deffffffe401000000000000010000000800000001000000783c0000
deffffffe401000000000000010000000800000001000000783c0000
-
{e=>6,a=>29,m=>1,d=>-2,j=>2,l=>1,c=>-2,k=>-104,h=>4,b=>7,g=>2,f=>0,i=>-1}
1d000000b701000006020000003c020000009809
1d000000b70100000600020000003c00020000009809
1d000000b701000006000000020000003c0000000200000098090000
1d000000b701000006000000020000003c0000000200000098090000
-
{e=>5,a=>-81,m=>3,d=>3,j=>2,l=>6,c=>-2,k=>-76,h=>3,b=>4,g=>4,f=>-1,i=>-3}
affffffff40000003d040000002b02000000b41e
affffffff40000003d00040000002b0002000000b41e
affffffff40000003d000000040000002b00000002000000b41e0000
affffffff40000003d000000040000002b00000002000000b41e0000
-
{e=>3,a=>-14,m=>2,d=>-1,j=>5,l=>2,c=>3,k=>77,h=>2,b=>0,g=>7,f=>0,i=>1}
f2ffffffd801000003070000000a050000004d12
f2ffffffd80100000300070000000a00050000004d12
f2ffffffd801000003000000070000000a000000050000004d120000
f2ffffffd801000003000000070000000a000000050000004d120000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>0,n=>2,a=>99,m=>-3,d=>-4,j=>1,l=>6,c=>-3,k=>5,h=>5,b=>2,g=>5,f=>3,i=>0}
630000002a01000018050000000501000000052e02000000
630000002a010000180005000000050001000000052e02000000
630000002a01000018000000050000000500000001000000052e000002000000
630000002a01000018000000050000000500000001000000052e000002000000
-
{e=>7,n=>4,a=>56,m=>-1,d=>0,j=>4,l=>6,c=>3,k=>123,h=>3,b=>0,g=>0,f=>-1,i=>1}
38000000180000003f000000000b040000007b3e04000000
38000000180000003f00000000000b00040000007b3e04000000
38000000180000003f000000000000000b000000040000007b3e000004000000
38000000180000003f000000000000000b000000040000007b3e000004000000
-
{e=>1,n=>0,a=>-72,m=>-1,d=>1,j=>2,l=>5,c=>-2,k=>29,h=>1,b=>1,g=>1,f=>2,i=>-3}
b8ffffff71000000110100000029020000001d3d00000000
b8ffffff710000001100010000002900020000001d3d00000000
b8ffffff71000000110000000100000029000000020000001d3d000000000000
b8ffffff71000000110000000100000029000000020000001d3d000000000000
-
{e=>6,n=>5,a=>-35,m=>-3,d=>-2,j=>5,l=>6,c=>-1,k=>87,h=>4,b=>7,g=>0,f=>1,i=>-1}
ddffffffbf0100000e000000003c05000000572e05000000
ddffffffbf0100000e00000000003c0005000000572e05000000
ddffffffbf0100000e000000000000003c00000005000000572e000005000000
ddffffffbf0100000e000000000000003c00000005000000572e000005000000
-
{e=>0,n=>1,a=>-32,m=>-1,d=>0,j=>6,l=>3,c=>1,k=>-26,h=>3,b=>1,g=>4,f=>-1,i=>3}
e0ffffff0900000038040000001b06000000e63b01000000
e0ffffff090000003800040000001b0006000000e63b01000000
e0ffffff0900000038000000040000001b00000006000000e63b000001000000
e0ffffff0900000038000000040000001b00000006000000e63b000001000000
=
typedef int foo;

struct mixed_no_pack {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>4,n=>5,a=>-63,m=>0,d=>-4,j=>0,l=>3,c=>2,k=>0,h=>4,b=>6,g=>3,f=>0,o=>255,i=>1}
c1ffffff1601000004030000000c00000000000305000000ff
c1ffffff160100000400030000000c0000000000000305000000ff00
c1ffffff1601000004000000030000000c000000000000000003000005000000ff000000
c1ffffff1601000004000000030000000c000000000000000003000005000000ff000000
-
{e=>4,n=>4,a=>-45,m=>-1,d=>-3,j=>5,l=>4,c=>-3,k=>-116,h=>7,b=>7,g=>0,f=>1,o=>47,i=>3}
d3ffffff6f0100000c000000001f050000008c3c040000002f
d3ffffff6f0100000c00000000001f00050000008c3c040000002f00
d3ffffff6f0100000c000000000000001f000000050000008c3c0000040000002f000000
d3ffffff6f0100000c000000000000001f000000050000008c3c0000040000002f000000
-
{e=>2,n=>7,a=>37,m=>3,d=>2,j=>5,l=>5,c=>-2,k=>86,h=>3,b=>7,g=>5,f=>-2,o=>120,i=>-2}
25000000b700000032050000003305000000561d0700000078
25000000b7000000320005000000330005000000561d070000007800
25000000b700000032000000050000003300000005000000561d00000700000078000000
25000000b700000032000000050000003300000005000000561d00000700000078000000
-
{e=>7,n=>3,a=>-38,m=>-4,d=>0,j=>4,l=>5,c=>0,k=>30,h=>7,b=>7,g=>0,f=>3,o=>182,i=>-2}
daffffff070000001f0000000037040000001e2503000000b6
daffffff070000001f00000000003700040000001e2503000000b600
daffffff070000001f0000000000000037000000040000001e25000003000000b6000000
daffffff070000001f0000000000000037000000040000001e25000003000000b6000000
-
{e=>4,n=>1,a=>-127,m=>0,d=>-4,j=>1,l=>7,c=>0,k=>-88,h=>1,b=>4,g=>3,f=>-2,o=>194,i=>-2}
81ffffff0401000034030000003101000000a80701000000c2
81ffffff04010000340003000000310001000000a80701000000c200
81ffffff0401000034000000030000003100000001000000a807000001000000c2000000
81ffffff0401000034000000030000003100000001000000a807000001000000c2000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
};
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>5}
05000000
05000000
05000000
05000000
-
{a=>5}
05000000
05000000
05000000
05000000
-
{a=>4}
04000000
04000000
04000000
04000000
-
{a=>1}
01000000
01000000
01000000
01000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
};
-
{a=>0,b=>-1}
38000000
38000000
38000000
38000000
-
{a=>0,b=>2}
10000000
10000000
10000000
10000000
-
{a=>1,b=>0}
01000000
01000000
01000000
01000000
-
{a=>0,b=>3}
18000000
18000000
18000000
18000000
-
{a=>5,b=>-1}
3d000000
3d000000
3d000000
3d000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
};
-
{c=>3,a=>0,b=>-3}
e8000000
e8000000
e8000000
e8000000
-
{c=>3,a=>7,b=>-4}
e7000000
e7000000
e7000000
e7000000
-
{c=>2,a=>3,b=>3}
9b000000
9b000000
9b000000
9b000000
-
{c=>0,a=>3,b=>-3}
2b000000
2b000000
2b000000
2b000000
-
{c=>-1,a=>3,b=>2}
d3010000
d3010000
d3010000
d3010000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
};
-
{c=>3,a=>7,b=>-4,d=>7}
e700000007
e700000007
e700000007
e700000007
-
{c=>1,a=>2,b=>1,d=>0}
4a00000000
4a00000000
4a00000000
4a00000000
-
{c=>-1,a=>1,b=>-4,d=>5}
e101000005
e101000005
e101000005
e101000005
-
{c=>3,a=>6,b=>-1,d=>0}
fe00000000
fe00000000
fe00000000
fe00000000
-
{c=>1,a=>4,b=>-2,d=>0}
7400000000
7400000000
7400000000
7400000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
};
-
{e=>2,c=>-2,a=>3,b=>-2,d=>6}
b301000016
b301000016
b301000016
b301000016
-
{e=>-2,c=>-1,a=>3,b=>-3,d=>2}
eb01000032
eb01000032
eb01000032
eb01000032
-
{e=>3,c=>1,a=>7,b=>-1,d=>3}
7f0000001b
7f0000001b
7f0000001b
7f0000001b
-
{e=>-4,c=>-2,a=>5,b=>-4,d=>1}
a501000021
a501000021
a501000021
a501000021
-
{e=>1,c=>-2,a=>4,b=>-2,d=>4}
b40100000c
b40100000c
b40100000c
b40100000c
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
};
-
{e=>-3,c=>1,a=>4,b=>-1,d=>2,f=>2}
7c0000002a02000000
7c0000002a02000000
7c0000002a02000000
7c0000002a02000000
-
{e=>3,c=>2,a=>5,b=>-1,d=>0,f=>4}
bd0000001804000000
bd0000001804000000
bd0000001804000000
bd0000001804000000
-
{e=>1,c=>-3,a=>3,b=>0,d=>6,f=>6}
430100000e06000000
430100000e06000000
430100000e06000000
430100000e06000000
-
{e=>2,c=>0,a=>1,b=>-3,d=>1,f=>6}
290000001106000000
290000001106000000
290000001106000000
290000001106000000
-
{e=>2,c=>1,a=>4,b=>3,d=>0,f=>4}
5c0000001004000000
5c0000001004000000
5c0000001004000000
5c0000001004000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
};
-
{e=>-4,c=>0,a=>2,b=>2,d=>2,f=>3}
120000002203000000
120000002203000000
120000002203000000
120000002203000000
-
{e=>2,c=>-4,a=>0,b=>2,d=>4,f=>2}
100100001402000000
100100001402000000
100100001402000000
100100001402000000
-
{e=>-2,c=>-4,a=>4,b=>0,d=>3,f=>0}
040100003300000000
040100003300000000
040100003300000000
040100003300000000
-
{e=>-1,c=>1,a=>2,b=>3,d=>7,f=>0}
5a0000003f00000000
5a0000003f00000000
5a0000003f00000000
5a0000003f00000000
-
{e=>0,c=>-1,a=>1,b=>-3,d=>0,f=>5}
e90100000005000000
e90100000005000000
e90100000005000000
e90100000005000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
};
-
{e=>3,c=>1,a=>1,g=>6,b=>0,d=>5,f=>2}
410000001d0200000006
410000001d0200000006
410000001d0200000006
410000001d0200000006
-
{e=>-2,c=>-2,a=>3,g=>0,b=>3,d=>0,f=>7}
9b010000300700000000
9b010000300700000000
9b010000300700000000
9b010000300700000000
-
{e=>-2,c=>-4,a=>6,g=>3,b=>-4,d=>6,f=>3}
26010000360300000003
26010000360300000003
26010000360300000003
26010000360300000003
-
{e=>-2,c=>1,a=>7,g=>4,b=>3,d=>7,f=>3}
5f000000370300000004
5f000000370300000004
5f000000370300000004
5f000000370300000004
-
{e=>-2,c=>-3,a=>0,g=>1,b=>-3,d=>7,f=>5}
68010000370500000001
68010000370500000001
68010000370500000001
68010000370500000001
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
};
-
{e=>-2,a=>2,d=>0,c=>-4,h=>1,b=>-4,g=>0,f=>0}
22010000300000000008
22010000300000000008
22010000300000000008
22010000300000000008
-
{e=>-1,a=>0,d=>5,c=>-2,h=>-3,b=>2,g=>2,f=>7}
900100003d070000002a
900100003d070000002a
900100003d070000002a
900100003d070000002a
-
{e=>3,a=>4,d=>0,c=>2,h=>-3,b=>3,g=>2,f=>7}
9c00000018070000002a
9c00000018070000002a
9c00000018070000002a
9c00000018070000002a
-
{e=>2,a=>7,d=>5,c=>2,h=>1,b=>0,g=>0,f=>2}
87000000150200000008
87000000150200000008
87000000150200000008
87000000150200000008
-
{e=>-3,a=>3,d=>6,c=>2,h=>0,b=>-1,g=>7,f=>4}
bb0000002e0400000007
bb0000002e0400000007
bb0000002e0400000007
bb0000002e0400000007
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
};
-
{e=>2,a=>3,d=>4,c=>1,h=>-4,b=>-1,g=>4,f=>2,i=>7}
7b00000014020000002407000000
7b00000014020000002407000000
7b00000014020000002407000000
7b00000014020000002407000000
-
{e=>2,a=>7,d=>2,c=>-3,h=>2,b=>-1,g=>6,f=>7,i=>5}
7f01000012070000001605000000
7f01000012070000001605000000
7f01000012070000001605000000
7f01000012070000001605000000
-
{e=>2,a=>2,d=>5,c=>-2,h=>0,b=>-1,g=>0,f=>6,i=>7}
ba01000015060000000007000000
ba01000015060000000007000000
ba01000015060000000007000000
ba01000015060000000007000000
-
{e=>-4,a=>0,d=>7,c=>0,h=>1,b=>3,g=>6,f=>0,i=>2}
1800000027000000000e02000000
1800000027000000000e02000000
1800000027000000000e02000000
1800000027000000000e02000000
-
{e=>0,a=>4,d=>3,c=>-1,h=>-4,b=>-4,g=>3,f=>6,i=>7}
e401000003060000002307000000
e401000003060000002307000000
e401000003060000002307000000
e401000003060000002307000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
};
-
{e=>-3,a=>2,d=>5,j=>51,c=>-3,h=>-4,b=>-1,g=>5,f=>7,i=>4}
7a0100002d07000000250400000033
7a0100002d07000000250400000033
7a0100002d07000000250400000033
7a0100002d07000000250400000033
-
{e=>2,a=>5,d=>0,j=>-45,c=>-2,h=>2,b=>-1,g=>6,f=>3,i=>2}
bd01000010030000001602000000d3
bd01000010030000001602000000d3
bd01000010030000001602000000d3
bd01000010030000001602000000d3
-
{e=>-1,a=>3,d=>4,j=>-26,c=>2,h=>3,b=>0,g=>1,f=>5,i=>0}
830000003c050000001900000000e6
830000003c050000001900000000e6
830000003c050000001900000000e6
830000003c050000001900000000e6
-
{e=>1,a=>4,d=>0,j=>-56,c=>1,h=>3,b=>2,g=>2,f=>3,i=>4}
5400000008030000001a04000000c8
5400000008030000001a04000000c8
5400000008030000001a04000000c8
5400000008030000001a04000000c8
-
{e=>2,a=>7,d=>4,j=>-122,c=>-4,h=>1,b=>-2,g=>1,f=>4,i=>6}
370100001404000000090600000086
370100001404000000090600000086
370100001404000000090600000086
370100001404000000090600000086
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
};
-
{e=>3,a=>6,d=>7,j=>112,c=>0,k=>2,h=>-4,b=>-3,g=>3,f=>7,i=>5}
2e0000001f0700000023050000007002
2e0000001f0700000023050000007002
2e0000001f0700000023050000007002
2e0000001f0700000023050000007002
-
{e=>-3,a=>1,d=>7,j=>-86,c=>3,k=>2,h=>3,b=>-4,g=>7,f=>0,i=>3}
e10000002f000000001f03000000aa02
e10000002f000000001f03000000aa02
e10000002f000000001f03000000aa02
e10000002f000000001f03000000aa02
-
{e=>-2,a=>0,d=>6,j=>-117,c=>-3,k=>7,h=>0,b=>-1,g=>6,f=>7,i=>2}
78010000360700000006020000008b07
78010000360700000006020000008b07
78010000360700000006020000008b07
78010000360700000006020000008b07
-
{e=>1,a=>5,d=>5,j=>-119,c=>-2,k=>6,h=>1,b=>2,g=>3,f=>2,i=>0}
950100000d020000000b000000008906
950100000d020000000b000000008906
950100000d020000000b000000008906
950100000d020000000b000000008906
-
{e=>3,a=>6,d=>6,j=>-128,c=>-2,k=>0,h=>2,b=>-4,g=>3,f=>3,i=>5}
a60100001e0300000013050000008000
a60100001e0300000013050000008000
a60100001e0300000013050000008000
a60100001e0300000013050000008000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
};
-
{e=>-1,a=>1,d=>3,j=>90,l=>-1,c=>2,k=>4,h=>0,b=>-2,g=>5,f=>4,i=>3}
b10000003b0400000005030000005a3c
b10000003b0400000005030000005a3c
b10000003b0400000005030000005a3c
b10000003b0400000005030000005a3c
-
{e=>3,a=>0,d=>3,j=>27,l=>-2,c=>-3,k=>5,h=>0,b=>-1,g=>2,f=>1,i=>5}
780100001b0100000002050000001b35
780100001b0100000002050000001b35
780100001b0100000002050000001b35
780100001b0100000002050000001b35
-
{e=>1,a=>1,d=>3,j=>-13,l=>-4,c=>-3,k=>5,h=>2,b=>-2,g=>6,f=>1,i=>1}
710100000b010000001601000000f325
710100000b010000001601000000f325
710100000b010000001601000000f325
710100000b010000001601000000f325
-
{e=>2,a=>3,d=>7,j=>-47,l=>-2,c=>-3,k=>1,h=>3,b=>-3,g=>6,f=>3,i=>6}
6b01000017030000001e06000000d131
6b01000017030000001e06000000d131
6b01000017030000001e06000000d131
6b01000017030000001e06000000d131
-
{e=>1,a=>3,d=>4,j=>20,l=>2,c=>-4,k=>3,h=>-3,b=>2,g=>4,f=>0,i=>4}
130100000c000000002c040000001413
130100000c000000002c040000001413
130100000c000000002c040000001413
130100000c000000002c040000001413
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
  unsigned int  m:3;
};
-
{e=>-2,a=>2,m=>1,d=>3,j=>66,l=>2,c=>1,k=>7,h=>0,b=>3,g=>3,f=>3,i=>4}
5a00000033030000000304000000421701000000
5a00000033030000000304000000421701000000
5a00000033030000000304000000421701000000
5a00000033030000000304000000421701000000
-
{e=>3,a=>7,m=>5,d=>2,j=>87,l=>-2,c=>-4,k=>4,h=>0,b=>1,g=>4,f=>1,i=>1}
0f0100001a010000000401000000573405000000
0f0100001a010000000401000000573405000000
0f0100001a010000000401000000573405000000
0f0100001a010000000401000000573405000000
-
{e=>0,a=>3,m=>7,d=>4,j=>2,l=>-3,c=>2,k=>7,h=>-4,b=>-2,g=>0,f=>4,i=>1}
b300000004040000002001000000022f07000000
b300000004040000002001000000022f07000000
b300000004040000002001000000022f07000000
b300000004040000002001000000022f07000000
-
{e=>0,a=>6,m=>1,d=>0,j=>-127,l=>0,c=>0,k=>2,h=>-3,b=>-2,g=>3,f=>2,i=>1}
3600000000020000002b01000000810201000000
3600000000020000002b01000000810201000000
3600000000020000002b01000000810201000000
3600000000020000002b01000000810201000000
-
{e=>-1,a=>4,m=>4,d=>0,j=>-10,l=>-3,c=>0,k=>4,h=>-4,b=>1,g=>6,f=>3,i=>0}
0c00000038030000002600000000f62c04000000
0c00000038030000002600000000f62c04000000
0c00000038030000002600000000f62c04000000
0c00000038030000002600000000f62c04000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
  unsigned int  m:3;
  unsigned char n;
};
-
{e=>-3,n=>71,a=>1,m=>5,d=>3,j=>-14,l=>-1,c=>0,k=>5,h=>-3,b=>0,g=>0,f=>5,i=>5}
010000002b050000002805000000f23d0500000047
010000002b050000002805000000f23d0500000047
010000002b050000002805000000f23d0500000047
010000002b050000002805000000f23d0500000047
-
{e=>1,n=>212,a=>5,m=>3,d=>1,j=>-32,l=>3,c=>-2,k=>5,h=>-2,b=>-3,g=>4,f=>0,i=>4}
ad01000009000000003404000000e01d03000000d4
ad01000009000000003404000000e01d03000000d4
ad01000009000000003404000000e01d03000000d4
ad01000009000000003404000000e01d03000000d4
-
{e=>-1,n=>32,a=>4,m=>3,d=>1,j=>-40,l=>-2,c=>-1,k=>3,h=>-1,b=>2,g=>0,f=>5,i=>5}
d401000039050000003805000000d8330300000020
d401000039050000003805000000d8330300000020
d401000039050000003805000000d8330300000020
d401000039050000003805000000d8330300000020
-
{e=>-1,n=>95,a=>2,m=>6,d=>6,j=>-84,l=>0,c=>2,k=>0,h=>2,b=>-3,g=>2,f=>3,i=>2}
aa0000003e030000001202000000ac00060000005f
aa0000003e030000001202000000ac00060000005f
aa0000003e030000001202000000ac00060000005f
aa0000003e030000001202000000ac00060000005f
-
{e=>0,n=>37,a=>4,m=>6,d=>1,j=>46,l=>2,c=>-3,k=>7,h=>0,b=>3,g=>0,f=>7,i=>0}
5c010000010700000000000000002e170600000025
5c010000010700000000000000002e170600000025
5c010000010700000000000000002e170600000025
5c010000010700000000000000002e170600000025
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
};
-
{a=>106,b=>0}
6a00000000
6a00000000
6a00000000
6a00000000
-
{a=>-10,b=>0}
f600000000
f600000000
f600000000
f600000000
-
{a=>12,b=>6}
0c06000000
0c06000000
0c06000000
0c06000000
-
{a=>-86,b=>1}
aa01000000
aa01000000
aa01000000
aa01000000
-
{a=>-33,b=>2}
df02000000
df02000000
df02000000
df02000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>-3,a=>-108,b=>2}
942a000000
942a000000
942a000000
942a000000
-
{c=>1,a=>96,b=>5}
600d000000
600d000000
600d000000
600d000000
-
{c=>3,a=>-121,b=>6}
871e000000
871e000000
871e000000
871e000000
-
{c=>-1,a=>-58,b=>1}
c639000000
c639000000
c639000000
c639000000
-
{c=>2,a=>62,b=>2}
3e12000000
3e12000000
3e12000000
3e12000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-4,a=>40,b=>3,d=>-2}
28a3010000
28a3010000
28a3010000
28a3010000
-
{c=>-3,a=>68,b=>4,d=>-3}
446c010000
446c010000
446c010000
446c010000
-
{c=>-3,a=>21,b=>0,d=>3}
15e8000000
15e8000000
15e8000000
15e8000000
-
{c=>-3,a=>-98,b=>2,d=>-1}
9eea010000
9eea010000
9eea010000
9eea010000
-
{c=>-3,a=>74,b=>7,d=>1}
4a6f000000
4a6f000000
4a6f000000
4a6f000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>3,c=>-2,a=>4,b=>0,d=>-4}
043001000003
043001000003
043001000003
043001000003
-
{e=>4,c=>-1,a=>44,b=>0,d=>2}
2cb800000004
2cb800000004
2cb800000004
2cb800000004
-
{e=>7,c=>-1,a=>-108,b=>5,d=>-2}
94bd01000007
94bd01000007
94bd01000007
94bd01000007
-
{e=>3,c=>2,a=>-123,b=>0,d=>3}
85d000000003
85d000000003
85d000000003
85d000000003
-
{e=>3,c=>0,a=>-85,b=>5,d=>0}
ab0500000003
ab0500000003
ab0500000003
ab0500000003
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>2,c=>-3,a=>-86,b=>1,d=>-3,f=>3}
aa690100001a
aa690100001a
aa690100001a
aa690100001a
-
{e=>4,c=>1,a=>-10,b=>0,d=>0,f=>3}
f6080000001c
f6080000001c
f6080000001c
f6080000001c
-
{e=>7,c=>-2,a=>18,b=>2,d=>-2,f=>-1}
12b20100003f
12b20100003f
12b20100003f
12b20100003f
-
{e=>2,c=>3,a=>-8,b=>5,d=>1,f=>2}
f85d00000012
f85d00000012
f85d00000012
f85d00000012
-
{e=>1,c=>0,a=>-98,b=>0,d=>1,f=>0}
9e4000000001
9e4000000001
9e4000000001
9e4000000001
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>3,c=>1,a=>126,g=>5,b=>0,d=>0,f=>3}
7e080000001b05000000
7e080000001b05000000
7e080000001b05000000
7e080000001b05000000
-
{e=>0,c=>-4,a=>-72,g=>4,b=>2,d=>-1,f=>2}
b8e20100001004000000
b8e20100001004000000
b8e20100001004000000
b8e20100001004000000
-
{e=>4,c=>-2,a=>-68,g=>1,b=>6,d=>3,f=>3}
bcf60000001c01000000
bcf60000001c01000000
bcf60000001c01000000
bcf60000001c01000000
-
{e=>1,c=>-2,a=>34,g=>4,b=>7,d=>-4,f=>-4}
22370100002104000000
22370100002104000000
22370100002104000000
22370100002104000000
-
{e=>2,c=>3,a=>13,g=>1,b=>3,d=>2,f=>-3}
0d9b0000002a01000000
0d9b0000002a01000000
0d9b0000002a01000000
0d9b0000002a01000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>6,c=>2,a=>-126,g=>7,b=>4,d=>-3,f=>2}
82540100001607000000
82540100001607000000
82540100001607000000
82540100001607000000
-
{e=>7,c=>-3,a=>-72,g=>3,b=>6,d=>-4,f=>-3}
b82e0100002f03000000
b82e0100002f03000000
b82e0100002f03000000
b82e0100002f03000000
-
{e=>6,c=>-3,a=>67,g=>7,b=>6,d=>-1,f=>-4}
43ee0100002607000000
43ee0100002607000000
43ee0100002607000000
43ee0100002607000000
-
{e=>4,c=>-2,a=>-37,g=>6,b=>2,d=>3,f=>3}
dbf20000001c06000000
dbf20000001c06000000
dbf20000001c06000000
dbf20000001c06000000
-
{e=>4,c=>3,a=>23,g=>7,b=>1,d=>2,f=>2}
17990000001407000000
17990000001407000000
17990000001407000000
17990000001407000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>3,a=>106,d=>0,c=>1,h=>0,b=>6,g=>3,f=>3}
6a0e0000001b0300000000
6a0e0000001b0300000000
6a0e0000001b0300000000
6a0e0000001b0300000000
-
{e=>0,a=>102,d=>-2,c=>-2,h=>0,b=>5,g=>0,f=>2}
66b5010000100000000000
66b5010000100000000000
66b5010000100000000000
66b5010000100000000000
-
{e=>1,a=>-118,d=>2,c=>-3,h=>1,b=>1,g=>6,f=>3}
8aa9000000190600000001
8aa9000000190600000001
8aa9000000190600000001
8aa9000000190600000001
-
{e=>0,a=>60,d=>-3,c=>2,h=>0,b=>3,g=>0,f=>0}
3c53010000000000000000
3c53010000000000000000
3c53010000000000000000
3c53010000000000000000
-
{e=>5,a=>19,d=>-2,c=>3,h=>1,b=>2,g=>4,f=>3}
139a0100001d0400000001
139a0100001d0400000001
139a0100001d0400000001
139a0100001d0400000001
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>4,a=>126,d=>2,c=>1,h=>5,b=>4,g=>6,f=>3,i=>-4}
7e8c0000001c0600000025
7e8c0000001c0600000025
7e8c0000001c0600000025
7e8c0000001c0600000025
-
{e=>7,a=>-19,d=>0,c=>1,h=>2,b=>3,g=>5,f=>0,i=>-3}
ed0b00000007050000002a
ed0b00000007050000002a
ed0b00000007050000002a
ed0b00000007050000002a
-
{e=>0,a=>122,d=>3,c=>3,h=>2,b=>4,g=>2,f=>-2,i=>2}
7adc000000300200000012
7adc000000300200000012
7adc000000300200000012
7adc000000300200000012
-
{e=>2,a=>62,d=>-4,c=>-4,h=>6,b=>3,g=>5,f=>-2,i=>3}
3e2301000032050000001e
3e2301000032050000001e
3e2301000032050000001e
3e2301000032050000001e
-
{e=>1,a=>64,d=>-3,c=>-4,h=>0,b=>3,g=>1,f=>-4,i=>-4}
4063010000210100000020
4063010000210100000020
4063010000210100000020
4063010000210100000020
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>6,a=>-51,d=>2,j=>2,c=>1,h=>0,b=>4,g=>2,f=>0,i=>-3}
cd8c00000006020000002802000000
cd8c00000006020000002802000000
cd8c00000006020000002802000000
cd8c00000006020000002802000000
-
{e=>3,a=>36,d=>-4,j=>7,c=>3,h=>7,b=>5,g=>6,f=>0,i=>-2}
241d01000003060000003707000000
241d01000003060000003707000000
241d01000003060000003707000000
241d01000003060000003707000000
-
{e=>3,a=>-65,d=>-2,j=>7,c=>-1,h=>5,b=>0,g=>5,f=>3,i=>-1}
bfb80100001b050000003d07000000
bfb80100001b050000003d07000000
bfb80100001b050000003d07000000
bfb80100001b050000003d07000000
-
{e=>3,a=>-4,d=>2,j=>4,c=>1,h=>1,b=>5,g=>1,f=>-1,i=>1}
fc8d0000003b010000000904000000
fc8d0000003b010000000904000000
fc8d0000003b010000000904000000
fc8d0000003b010000000904000000
-
{e=>5,a=>114,d=>2,j=>0,c=>1,h=>2,b=>7,g=>2,f=>-3,i=>-3}
728f0000002d020000002a00000000
728f0000002d020000002a00000000
728f0000002d020000002a00000000
728f0000002d020000002a00000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>6,a=>66,d=>1,j=>3,c=>3,k=>-88,h=>4,b=>5,g=>0,f=>3,i=>1}
425d0000001e000000000c03000000a8
425d0000001e000000000c03000000a8
425d0000001e000000000c03000000a8
425d0000001e000000000c03000000a8
-
{e=>3,a=>-27,d=>3,j=>3,c=>-4,k=>-71,h=>2,b=>6,g=>1,f=>1,i=>-3}
e5e60000000b010000002a03000000b9
e5e60000000b010000002a03000000b9
e5e60000000b010000002a03000000b9
e5e60000000b010000002a03000000b9
-
{e=>7,a=>-4,d=>-3,j=>1,c=>-3,k=>-71,h=>5,b=>0,g=>3,f=>2,i=>-4}
fc6801000017030000002501000000b9
fc6801000017030000002501000000b9
fc6801000017030000002501000000b9
fc6801000017030000002501000000b9
-
{e=>7,a=>-35,d=>-3,j=>6,c=>2,k=>50,h=>5,b=>5,g=>6,f=>1,i=>2}
dd550100000f06000000150600000032
dd550100000f06000000150600000032
dd550100000f06000000150600000032
dd550100000f06000000150600000032
-
{e=>5,a=>-47,d=>0,j=>3,c=>3,k=>-120,h=>3,b=>2,g=>7,f=>2,i=>1}
d11a00000015070000000b0300000088
d11a00000015070000000b0300000088
d11a00000015070000000b0300000088
d11a00000015070000000b0300000088
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>2,a=>-32,d=>-4,j=>1,l=>2,c=>-4,k=>-17,h=>5,b=>0,g=>3,f=>1,i=>-3}
e0200100000a030000002d01000000ef02
e0200100000a030000002d01000000ef02
e0200100000a030000002d01000000ef02
e0200100000a030000002d01000000ef02
-
{e=>7,a=>-51,d=>2,j=>0,l=>7,c=>-1,k=>-66,h=>1,b=>5,g=>3,f=>1,i=>-1}
cdbd0000000f030000003900000000be07
cdbd0000000f030000003900000000be07
cdbd0000000f030000003900000000be07
cdbd0000000f030000003900000000be07
-
{e=>5,a=>73,d=>2,j=>4,l=>7,c=>-3,k=>-107,h=>4,b=>6,g=>4,f=>-2,i=>-4}
49ae000000350400000024040000009507
49ae000000350400000024040000009507
49ae000000350400000024040000009507
49ae000000350400000024040000009507
-
{e=>7,a=>-32,d=>0,j=>2,l=>6,c=>1,k=>-119,h=>6,b=>7,g=>0,f=>-4,i=>0}
e00f000000270000000006020000008906
e00f000000270000000006020000008906
e00f000000270000000006020000008906
e00f000000270000000006020000008906
-
{e=>7,a=>70,d=>1,j=>3,l=>0,c=>2,k=>-78,h=>4,b=>1,g=>4,f=>3,i=>-1}
46510000001f040000003c03000000b200
46510000001f040000003c03000000b200
46510000001f040000003c03000000b200
46510000001f040000003c03000000b200
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>5,a=>82,m=>1,d=>-4,j=>4,l=>4,c=>2,k=>75,h=>1,b=>7,g=>3,f=>-2,i=>2}
5217010000350300000011040000004b0c
5217010000350300000011040000004b0c
5217010000350300000011040000004b0c
5217010000350300000011040000004b0c
-
{e=>1,a=>65,m=>0,d=>-2,j=>6,l=>6,c=>1,k=>10,h=>7,b=>6,g=>6,f=>1,i=>3}
418e01000009060000001f060000000a06
418e01000009060000001f060000000a06
418e01000009060000001f060000000a06
418e01000009060000001f060000000a06
-
{e=>1,a=>50,m=>0,d=>-1,j=>4,l=>1,c=>3,k=>-39,h=>4,b=>5,g=>1,f=>3,i=>2}
32dd01000019010000001404000000d901
32dd01000019010000001404000000d901
32dd01000019010000001404000000d901
32dd01000019010000001404000000d901
-
{e=>1,a=>-30,m=>-3,d=>-3,j=>4,l=>3,c=>0,k=>-58,h=>2,b=>2,g=>4,f=>-3,i=>-1}
e24201000029040000003a04000000c62b
e24201000029040000003a04000000c62b
e24201000029040000003a04000000c62b
e24201000029040000003a04000000c62b
-
{e=>6,a=>-8,m=>-1,d=>-4,j=>1,l=>7,c=>1,k=>-96,h=>4,b=>1,g=>2,f=>-4,i=>3}
f80901000026020000001c01000000a03f
f80901000026020000001c01000000a03f
f80901000026020000001c01000000a03f
f80901000026020000001c01000000a03f
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>6,n=>7,a=>127,m=>-3,d=>2,j=>1,l=>4,c=>3,k=>113,h=>7,b=>0,g=>3,f=>-2,i=>1}
7f9800000036030000000f01000000712c07000000
7f9800000036030000000f01000000712c07000000
7f9800000036030000000f01000000712c07000000
7f9800000036030000000f01000000712c07000000
-
{e=>4,n=>0,a=>91,m=>2,d=>-1,j=>4,l=>6,c=>0,k=>7,h=>3,b=>0,g=>3,f=>2,i=>2}
5bc001000014030000001304000000071600000000
5bc001000014030000001304000000071600000000
5bc001000014030000001304000000071600000000
5bc001000014030000001304000000071600000000
-
{e=>3,n=>7,a=>-20,m=>-1,d=>-3,j=>0,l=>1,c=>3,k=>18,h=>1,b=>6,g=>4,f=>2,i=>-2}
ec5e01000013040000003100000000123907000000
ec5e01000013040000003100000000123907000000
ec5e01000013040000003100000000123907000000
ec5e01000013040000003100000000123907000000
-
{e=>6,n=>4,a=>46,m=>-4,d=>-2,j=>7,l=>6,c=>-3,k=>27,h=>0,b=>6,g=>7,f=>2,i=>3}
2eae010000160700000018070000001b2604000000
2eae010000160700000018070000001b2604000000
2eae010000160700000018070000001b2604000000
2eae010000160700000018070000001b2604000000
-
{e=>6,n=>5,a=>47,m=>-1,d=>-4,j=>7,l=>6,c=>-3,k=>-66,h=>0,b=>6,g=>0,f=>-4,i=>0}
2f2e01000026000000000007000000be3e05000000
2f2e01000026000000000007000000be3e05000000
2f2e01000026000000000007000000be3e05000000
2f2e01000026000000000007000000be3e05000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>7,n=>3,a=>90,m=>-1,d=>-4,j=>1,l=>4,c=>2,k=>65,h=>5,b=>7,g=>5,f=>1,o=>24,i=>2}
5a170100000f050000001501000000413c0300000018
5a170100000f050000001501000000413c0300000018
5a170100000f050000001501000000413c0300000018
5a170100000f050000001501000000413c0300000018
-
{e=>2,n=>4,a=>119,m=>3,d=>-2,j=>6,l=>0,c=>-4,k=>51,h=>3,b=>6,g=>7,f=>-4,o=>208,i=>-4}
77a601000022070000002306000000331804000000d0
77a601000022070000002306000000331804000000d0
77a601000022070000002306000000331804000000d0
77a601000022070000002306000000331804000000d0
-
{e=>7,n=>2,a=>-108,m=>-3,d=>2,j=>4,l=>7,c=>-1,k=>14,h=>5,b=>7,g=>3,f=>3,o=>186,i=>3}
94bf0000001f030000001d040000000e2f02000000ba
94bf0000001f030000001d040000000e2f02000000ba
94bf0000001f030000001d040000000e2f02000000ba
94bf0000001f030000001d040000000e2f02000000ba
-
{e=>6,n=>0,a=>-25,m=>-1,d=>1,j=>2,l=>3,c=>-1,k=>-23,h=>6,b=>5,g=>5,f=>2,o=>143,i=>2}
e77d00000016050000001602000000e93b000000008f
e77d00000016050000001602000000e93b000000008f
e77d00000016050000001602000000e93b000000008f
e77d00000016050000001602000000e93b000000008f
-
{e=>3,n=>2,a=>-24,m=>0,d=>-1,j=>4,l=>3,c=>3,k=>57,h=>3,b=>7,g=>0,f=>-2,o=>223,i=>2}
e8df01000033000000001304000000390302000000df
e8df01000033000000001304000000390302000000df
e8df01000033000000001304000000390302000000df
e8df01000033000000001304000000390302000000df
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
};
-
{a=>-22,b=>5}
eaff05000000
eaff05000000
eaff05000000
eaff05000000
-
{a=>45,b=>7}
2d0007000000
2d0007000000
2d0007000000
2d0007000000
-
{a=>-48,b=>5}
d0ff05000000
d0ff05000000
d0ff05000000
d0ff05000000
-
{a=>-29,b=>0}
e3ff00000000
e3ff00000000
e3ff00000000
e3ff00000000
-
{a=>124,b=>1}
7c0001000000
7c0001000000
7c0001000000
7c0001000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>0,a=>-68,b=>0}
bcff00000000
bcff00000000
bcff00000000
bcff00000000
-
{c=>0,a=>-11,b=>4}
f5ff04000000
f5ff04000000
f5ff04000000
f5ff04000000
-
{c=>-4,a=>-111,b=>3}
91ff23000000
91ff23000000
91ff23000000
91ff23000000
-
{c=>-1,a=>-105,b=>0}
97ff38000000
97ff38000000
97ff38000000
97ff38000000
-
{c=>0,a=>-96,b=>4}
a0ff04000000
a0ff04000000
a0ff04000000
a0ff04000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-4,a=>-55,b=>7,d=>1}
c9ff67000000
c9ff67000000
c9ff67000000
c9ff67000000
-
{c=>3,a=>59,b=>3,d=>-2}
3b009b010000
3b009b010000
3b009b010000
3b009b010000
-
{c=>-1,a=>-48,b=>3,d=>0}
d0ff3b000000
d0ff3b000000
d0ff3b000000
d0ff3b000000
-
{c=>-1,a=>-29,b=>6,d=>3}
e3fffe000000
e3fffe000000
e3fffe000000
e3fffe000000
-
{c=>-3,a=>32,b=>0,d=>1}
200068000000
200068000000
200068000000
200068000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>4,c=>-3,a=>20,b=>1,d=>-3}
14006901000004
14006901000004
14006901000004
14006901000004
-
{e=>3,c=>2,a=>-60,b=>0,d=>-2}
c4ff9001000003
c4ff9001000003
c4ff9001000003
c4ff9001000003
-
{e=>5,c=>-3,a=>-102,b=>3,d=>-4}
9aff2b01000005
9aff2b01000005
9aff2b01000005
9aff2b01000005
-
{e=>3,c=>-4,a=>5,b=>0,d=>1}
05006000000003
05006000000003
05006000000003
05006000000003
-
{e=>4,c=>0,a=>-80,b=>6,d=>0}
b0ff0600000004
b0ff0600000004
b0ff0600000004
b0ff0600000004
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>5,c=>-1,a=>-102,b=>0,d=>1,f=>0}
9aff7800000005
9aff7800000005
9aff7800000005
9aff7800000005
-
{e=>4,c=>2,a=>7,b=>4,d=>-4,f=>-1}
0700140100003c
0700140100003c
0700140100003c
0700140100003c
-
{e=>4,c=>-1,a=>99,b=>1,d=>1,f=>-1}
6300790000003c
6300790000003c
6300790000003c
6300790000003c
-
{e=>3,c=>-2,a=>-105,b=>7,d=>-4,f=>-3}
97ff370100002b
97ff370100002b
97ff370100002b
97ff370100002b
-
{e=>6,c=>-2,a=>102,b=>7,d=>-4,f=>-1}
6600370100003e
6600370100003e
6600370100003e
6600370100003e
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>4,c=>0,a=>106,g=>0,b=>1,d=>-3,f=>1}
6a00410100000c00000000
6a00410100000c00000000
6a00410100000c00000000
6a00410100000c00000000
-
{e=>6,c=>-4,a=>-47,g=>4,b=>0,d=>2,f=>-1}
d1ffa00000003e04000000
d1ffa00000003e04000000
d1ffa00000003e04000000
d1ffa00000003e04000000
-
{e=>2,c=>0,a=>28,g=>2,b=>3,d=>-4,f=>-1}
1c00030100003a02000000
1c00030100003a02000000
1c00030100003a02000000
1c00030100003a02000000
-
{e=>2,c=>2,a=>8,g=>0,b=>4,d=>-3,f=>1}
0800540100000a00000000
0800540100000a00000000
0800540100000a00000000
0800540100000a00000000
-
{e=>7,c=>1,a=>-41,g=>1,b=>6,d=>-3,f=>-3}
d7ff4e0100002f01000000
d7ff4e0100002f01000000
d7ff4e0100002f01000000
d7ff4e0100002f01000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>2,c=>2,a=>57,g=>4,b=>4,d=>-3,f=>-3}
3900540100002a04000000
3900540100002a04000000
3900540100002a04000000
3900540100002a04000000
-
{e=>5,c=>-1,a=>108,g=>7,b=>2,d=>-1,f=>-3}
6c00fa0100002d07000000
6c00fa0100002d07000000
6c00fa0100002d07000000
6c00fa0100002d07000000
-
{e=>3,c=>-3,a=>59,g=>1,b=>5,d=>1,f=>-2}
3b006d0000003301000000
3b006d0000003301000000
3b006d0000003301000000
3b006d0000003301000000
-
{e=>3,c=>-2,a=>82,g=>7,b=>1,d=>-1,f=>-1}
5200f10100003b07000000
5200f10100003b07000000
5200f10100003b07000000
5200f10100003b07000000
-
{e=>1,c=>-1,a=>12,g=>2,b=>6,d=>3,f=>-1}
0c00fe0000003902000000
0c00fe0000003902000000
0c00fe0000003902000000
0c00fe0000003902000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>1,a=>50,d=>-3,c=>-2,h=>0,b=>7,g=>4,f=>-2}
320077010000310400000000
320077010000310400000000
320077010000310400000000
320077010000310400000000
-
{e=>5,a=>40,d=>-3,c=>-4,h=>2,b=>3,g=>0,f=>3}
2800630100001d0000000002
2800630100001d0000000002
2800630100001d0000000002
2800630100001d0000000002
-
{e=>6,a=>21,d=>-1,c=>3,h=>2,b=>6,g=>7,f=>-1}
1500de0100003e0700000002
1500de0100003e0700000002
1500de0100003e0700000002
1500de0100003e0700000002
-
{e=>0,a=>-119,d=>0,c=>-1,h=>6,b=>1,g=>7,f=>3}
89ff39000000180700000006
89ff39000000180700000006
89ff39000000180700000006
89ff39000000180700000006
-
{e=>4,a=>-45,d=>2,c=>1,h=>2,b=>7,g=>7,f=>0}
d3ff8f000000040700000002
d3ff8f000000040700000002
d3ff8f000000040700000002
d3ff8f000000040700000002
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>2,a=>95,d=>0,c=>-2,h=>1,b=>4,g=>3,f=>0,i=>-1}
5f0034000000020300000039
5f0034000000020300000039
5f0034000000020300000039
5f0034000000020300000039
-
{e=>4,a=>34,d=>0,c=>3,h=>3,b=>2,g=>1,f=>0,i=>-1}
22001a00000004010000003b
22001a00000004010000003b
22001a00000004010000003b
22001a00000004010000003b
-
{e=>7,a=>40,d=>-2,c=>-2,h=>0,b=>3,g=>1,f=>2,i=>1}
2800b3010000170100000008
2800b3010000170100000008
2800b3010000170100000008
2800b3010000170100000008
-
{e=>2,a=>-13,d=>-3,c=>1,h=>1,b=>0,g=>5,f=>3,i=>-2}
f3ff480100001a0500000031
f3ff480100001a0500000031
f3ff480100001a0500000031
f3ff480100001a0500000031
-
{e=>6,a=>-50,d=>0,c=>1,h=>6,b=>6,g=>5,f=>-3,i=>-2}
ceff0e0000002e0500000036
ceff0e0000002e0500000036
ceff0e0000002e0500000036
ceff0e0000002e0500000036
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>0,a=>-78,d=>-2,j=>4,c=>-1,h=>1,b=>3,g=>6,f=>-3,i=>-2}
b2ffbb01000028060000003104000000
b2ffbb01000028060000003104000000
b2ffbb01000028060000003104000000
b2ffbb01000028060000003104000000
-
{e=>7,a=>76,d=>-2,j=>1,c=>-4,h=>5,b=>6,g=>3,f=>-4,i=>2}
4c00a601000027030000001501000000
4c00a601000027030000001501000000
4c00a601000027030000001501000000
4c00a601000027030000001501000000
-
{e=>7,a=>88,d=>0,j=>0,c=>1,h=>1,b=>1,g=>1,f=>1,i=>2}
5800090000000f010000001100000000
5800090000000f010000001100000000
5800090000000f010000001100000000
5800090000000f010000001100000000
-
{e=>7,a=>-27,d=>0,j=>7,c=>-1,h=>1,b=>0,g=>0,f=>-4,i=>-1}
e5ff3800000027000000003907000000
e5ff3800000027000000003907000000
e5ff3800000027000000003907000000
e5ff3800000027000000003907000000
-
{e=>1,a=>-99,d=>-3,j=>3,c=>1,h=>5,b=>1,g=>6,f=>3,i=>3}
9dff4901000019060000001d03000000
9dff4901000019060000001d03000000
9dff4901000019060000001d03000000
9dff4901000019060000001d03000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>2,a=>4,d=>1,j=>5,c=>-3,k=>75,h=>5,b=>0,g=>2,f=>3,i=>-1}
0400680000001a020000003d050000004b
0400680000001a020000003d050000004b
0400680000001a020000003d050000004b
0400680000001a020000003d050000004b
-
{e=>5,a=>7,d=>-2,j=>1,c=>0,k=>19,h=>4,b=>6,g=>6,f=>3,i=>1}
0700860100001d060000000c0100000013
0700860100001d060000000c0100000013
0700860100001d060000000c0100000013
0700860100001d060000000c0100000013
-
{e=>2,a=>57,d=>1,j=>0,c=>1,k=>89,h=>1,b=>3,g=>6,f=>3,i=>1}
39004b0000001a06000000090000000059
39004b0000001a06000000090000000059
39004b0000001a06000000090000000059
39004b0000001a06000000090000000059
-
{e=>4,a=>7,d=>0,j=>2,c=>-1,k=>-8,h=>3,b=>7,g=>4,f=>-1,i=>-4}
07003f0000003c040000002302000000f8
07003f0000003c040000002302000000f8
07003f0000003c040000002302000000f8
07003f0000003c040000002302000000f8
-
{e=>5,a=>105,d=>3,j=>1,c=>3,k=>119,h=>7,b=>7,g=>0,f=>0,i=>-2}
6900df0000000500000000370100000077
6900df0000000500000000370100000077
6900df0000000500000000370100000077
6900df0000000500000000370100000077
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>3,a=>-68,d=>3,j=>1,l=>0,c=>-3,k=>40,h=>5,b=>6,g=>0,f=>0,i=>2}
bcffee000000030000000015010000002800
bcffee000000030000000015010000002800
bcffee000000030000000015010000002800
bcffee000000030000000015010000002800
-
{e=>6,a=>84,d=>-4,j=>4,l=>0,c=>1,k=>100,h=>2,b=>1,g=>6,f=>3,i=>2}
5400090100001e0600000012040000006400
5400090100001e0600000012040000006400
5400090100001e0600000012040000006400
5400090100001e0600000012040000006400
-
{e=>2,a=>-8,d=>-4,j=>2,l=>4,c=>-2,k=>-68,h=>2,b=>6,g=>5,f=>-1,i=>-1}
f8ff360100003a050000003a02000000bc04
f8ff360100003a050000003a02000000bc04
f8ff360100003a050000003a02000000bc04
f8ff360100003a050000003a02000000bc04
-
{e=>0,a=>-64,d=>3,j=>4,l=>1,c=>-4,k=>-2,h=>3,b=>1,g=>4,f=>-3,i=>-3}
c0ffe100000028040000002b04000000fe01
c0ffe100000028040000002b04000000fe01
c0ffe100000028040000002b04000000fe01
c0ffe100000028040000002b04000000fe01
-
{e=>5,a=>64,d=>-4,j=>6,l=>7,c=>0,k=>13,h=>2,b=>4,g=>7,f=>-4,i=>3}
40000401000025070000001a060000000d07
40000401000025070000001a060000000d07
40000401000025070000001a060000000d07
40000401000025070000001a060000000d07
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>2,a=>-53,m=>2,d=>0,j=>4,l=>6,c=>0,k=>-28,h=>4,b=>1,g=>0,f=>0,i=>-1}
cbff0100000002000000003c04000000e416
cbff0100000002000000003c04000000e416
cbff0100000002000000003c04000000e416
cbff0100000002000000003c04000000e416
-
{e=>2,a=>-58,m=>-4,d=>-3,j=>7,l=>1,c=>1,k=>-110,h=>4,b=>2,g=>5,f=>-2,i=>1}
c6ff4a01000032050000000c070000009221
c6ff4a01000032050000000c070000009221
c6ff4a01000032050000000c070000009221
c6ff4a01000032050000000c070000009221
-
{e=>2,a=>-95,m=>1,d=>2,j=>3,l=>1,c=>2,k=>47,h=>7,b=>5,g=>2,f=>3,i=>0}
a1ff950000001a0200000007030000002f09
a1ff950000001a0200000007030000002f09
a1ff950000001a0200000007030000002f09
a1ff950000001a0200000007030000002f09
-
{e=>2,a=>86,m=>0,d=>-1,j=>3,l=>0,c=>3,k=>-1,h=>4,b=>3,g=>1,f=>0,i=>-3}
5600db01000002010000002c03000000ff00
5600db01000002010000002c03000000ff00
5600db01000002010000002c03000000ff00
5600db01000002010000002c03000000ff00
-
{e=>5,a=>31,m=>-3,d=>1,j=>4,l=>5,c=>1,k=>1,h=>6,b=>1,g=>2,f=>2,i=>-4}
1f004900000015020000002604000000012d
1f004900000015020000002604000000012d
1f004900000015020000002604000000012d
1f004900000015020000002604000000012d
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>4,n=>3,a=>-119,m=>-2,d=>0,j=>0,l=>0,c=>3,k=>127,h=>3,b=>3,g=>0,f=>-3,i=>-3}
89ff1b0000002c000000002b000000007f3003000000
89ff1b0000002c000000002b000000007f3003000000
89ff1b0000002c000000002b000000007f3003000000
89ff1b0000002c000000002b000000007f3003000000
-
{e=>2,n=>3,a=>47,m=>-4,d=>1,j=>6,l=>7,c=>1,k=>-126,h=>6,b=>1,g=>2,f=>-2,i=>-4}
2f004900000032020000002606000000822703000000
2f004900000032020000002606000000822703000000
2f004900000032020000002606000000822703000000
2f004900000032020000002606000000822703000000
-
{e=>6,n=>4,a=>-16,m=>3,d=>-4,j=>3,l=>3,c=>2,k=>-100,h=>4,b=>4,g=>3,f=>-1,i=>3}
f0ff140100003e030000001c030000009c1b04000000
f0ff140100003e030000001c030000009c1b04000000
f0ff140100003e030000001c030000009c1b04000000
f0ff140100003e030000001c030000009c1b04000000
-
{e=>0,n=>3,a=>99,m=>-3,d=>-4,j=>4,l=>1,c=>-1,k=>-77,h=>3,b=>1,g=>0,f=>-2,i=>3}
63003901000030000000001b04000000b32903000000
63003901000030000000001b04000000b32903000000
63003901000030000000001b04000000b32903000000
63003901000030000000001b04000000b32903000000
-
{e=>5,n=>0,a=>-106,m=>-2,d=>-4,j=>7,l=>7,c=>-3,k=>-97,h=>3,b=>3,g=>2,f=>1,i=>-3}
96ff2b0100000d020000002b070000009f3700000000
96ff2b0100000d020000002b070000009f3700000000
96ff2b0100000d020000002b070000009f3700000000
96ff2b0100000d020000002b070000009f3700000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>3,n=>7,a=>-113,m=>1,d=>-3,j=>5,l=>0,c=>1,k=>2,h=>6,b=>0,g=>5,f=>-2,o=>22,i=>0}
8fff480100003305000000060500000002080700000016
8fff480100003305000000060500000002080700000016
8fff480100003305000000060500000002080700000016
8fff480100003305000000060500000002080700000016
-
{e=>6,n=>7,a=>-82,m=>-2,d=>-3,j=>7,l=>3,c=>-1,k=>-116,h=>6,b=>1,g=>5,f=>2,o=>227,i=>-2}
aeff79010000160500000036070000008c3307000000e3
aeff79010000160500000036070000008c3307000000e3
aeff79010000160500000036070000008c3307000000e3
aeff79010000160500000036070000008c3307000000e3
-
{e=>1,n=>4,a=>-117,m=>-2,d=>-2,j=>2,l=>5,c=>1,k=>-17,h=>3,b=>6,g=>3,f=>-4,o=>238,i=>-2}
8bff8e01000021030000003302000000ef3504000000ee
8bff8e01000021030000003302000000ef3504000000ee
8bff8e01000021030000003302000000ef3504000000ee
8bff8e01000021030000003302000000ef3504000000ee
-
{e=>4,n=>6,a=>62,m=>-2,d=>3,j=>0,l=>4,c=>2,k=>119,h=>2,b=>7,g=>6,f=>0,o=>141,i=>-4}
3e00d7000000040600000022000000007734060000008d
3e00d7000000040600000022000000007734060000008d
3e00d7000000040600000022000000007734060000008d
3e00d7000000040600000022000000007734060000008d
-
{e=>0,n=>5,a=>59,m=>0,d=>1,j=>3,l=>5,c=>-2,k=>-64,h=>0,b=>7,g=>0,f=>-4,o=>130,i=>3}
3b007700000020000000001803000000c0050500000082
3b007700000020000000001803000000c0050500000082
3b007700000020000000001803000000c0050500000082
3b007700000020000000001803000000c0050500000082
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
};
-
{a=>-25,b=>5}
e7ffffff05000000
e7ffffff05000000
e7ffffff05000000
e7ffffff05000000
-
{a=>10,b=>1}
0a00000001000000
0a00000001000000
0a00000001000000
0a00000001000000
-
{a=>8,b=>7}
0800000007000000
0800000007000000
0800000007000000
0800000007000000
-
{a=>-93,b=>6}
a3ffffff06000000
a3ffffff06000000
a3ffffff06000000
a3ffffff06000000
-
{a=>-67,b=>1}
bdffffff01000000
bdffffff01000000
bdffffff01000000
bdffffff01000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>0,a=>-12,b=>7}
f4ffffff07000000
f4ffffff07000000
f4ffffff07000000
f4ffffff07000000
-
{c=>-4,a=>99,b=>7}
6300000027000000
6300000027000000
6300000027000000
6300000027000000
-
{c=>1,a=>18,b=>7}
120000000f000000
120000000f000000
120000000f000000
120000000f000000
-
{c=>2,a=>43,b=>7}
2b00000017000000
2b00000017000000
2b00000017000000
2b00000017000000
-
{c=>-4,a=>34,b=>0}
2200000020000000
2200000020000000
2200000020000000
2200000020000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-2,a=>26,b=>4,d=>1}
1a00000074000000
1a00000074000000
1a00000074000000
1a00000074000000
-
{c=>-3,a=>42,b=>5,d=>0}
2a0000002d000000
2a0000002d000000
2a0000002d000000
2a0000002d000000
-
{c=>3,a=>115,b=>3,d=>-4}
730000001b010000
730000001b010000
730000001b010000
730000001b010000
-
{c=>1,a=>21,b=>4,d=>-2}
150000008c010000
150000008c010000
150000008c010000
150000008c010000
-
{c=>1,a=>124,b=>0,d=>-2}
7c00000088010000
7c00000088010000
7c00000088010000
7c00000088010000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>1,c=>-3,a=>-59,b=>7,d=>-3}
c5ffffff6f01000001
c5ffffff6f01000001
c5ffffff6f01000001
c5ffffff6f01000001
-
{e=>5,c=>3,a=>96,b=>7,d=>1}
600000005f00000005
600000005f00000005
600000005f00000005
600000005f00000005
-
{e=>6,c=>-3,a=>97,b=>1,d=>1}
610000006900000006
610000006900000006
610000006900000006
610000006900000006
-
{e=>0,c=>-3,a=>45,b=>5,d=>-2}
2d000000ad01000000
2d000000ad01000000
2d000000ad01000000
2d000000ad01000000
-
{e=>5,c=>-4,a=>-125,b=>0,d=>1}
83ffffff6000000005
83ffffff6000000005
83ffffff6000000005
83ffffff6000000005
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>6,c=>3,a=>-75,b=>2,d=>-3,f=>0}
b5ffffff5a01000006
b5ffffff5a01000006
b5ffffff5a01000006
b5ffffff5a01000006
-
{e=>5,c=>-4,a=>-82,b=>3,d=>3,f=>1}
aeffffffe30000000d
aeffffffe30000000d
aeffffffe30000000d
aeffffffe30000000d
-
{e=>7,c=>1,a=>53,b=>4,d=>-2,f=>0}
350000008c01000007
350000008c01000007
350000008c01000007
350000008c01000007
-
{e=>1,c=>2,a=>126,b=>6,d=>-3,f=>0}
7e0000005601000001
7e0000005601000001
7e0000005601000001
7e0000005601000001
-
{e=>3,c=>0,a=>11,b=>4,d=>-1,f=>-1}
0b000000c40100003b
0b000000c40100003b
0b000000c40100003b
0b000000c40100003b
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>2,c=>-1,a=>-28,g=>6,b=>6,d=>1,f=>-2}
e4ffffff7e0000003206000000
e4ffffff7e0000003206000000
e4ffffff7e0000003206000000
e4ffffff7e0000003206000000
-
{e=>1,c=>2,a=>-122,g=>5,b=>3,d=>2,f=>-2}
86ffffff930000003105000000
86ffffff930000003105000000
86ffffff930000003105000000
86ffffff930000003105000000
-
{e=>7,c=>-2,a=>-4,g=>7,b=>7,d=>1,f=>3}
fcffffff770000001f07000000
fcffffff770000001f07000000
fcffffff770000001f07000000
fcffffff770000001f07000000
-
{e=>3,c=>-1,a=>-107,g=>6,b=>5,d=>-4,f=>-3}
95ffffff3d0100002b06000000
95ffffff3d0100002b06000000
95ffffff3d0100002b06000000
95ffffff3d0100002b06000000
-
{e=>2,c=>1,a=>-115,g=>0,b=>7,d=>2,f=>0}
8dffffff8f0000000200000000
8dffffff8f0000000200000000
8dffffff8f0000000200000000
8dffffff8f0000000200000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>4,c=>1,a=>-92,g=>6,b=>5,d=>-4,f=>-4}
a4ffffff0d0100002406000000
a4ffffff0d0100002406000000
a4ffffff0d0100002406000000
a4ffffff0d0100002406000000
-
{e=>3,c=>3,a=>112,g=>1,b=>4,d=>0,f=>-3}
700000001c0000002b01000000
700000001c0000002b01000000
700000001c0000002b01000000
700000001c0000002b01000000
-
{e=>2,c=>1,a=>-90,g=>7,b=>2,d=>1,f=>0}
a6ffffff4a0000000207000000
a6ffffff4a0000000207000000
a6ffffff4a0000000207000000
a6ffffff4a0000000207000000
-
{e=>1,c=>3,a=>20,g=>3,b=>6,d=>-1,f=>-4}
14000000de0100002103000000
14000000de0100002103000000
14000000de0100002103000000
14000000de0100002103000000
-
{e=>0,c=>1,a=>-18,g=>4,b=>0,d=>-2,f=>-2}
eeffffff880100003004000000
eeffffff880100003004000000
eeffffff880100003004000000
eeffffff880100003004000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>6,a=>38,d=>-1,c=>-1,h=>0,b=>7,g=>7,f=>3}
26000000ff0100001e0700000000
26000000ff0100001e0700000000
26000000ff0100001e0700000000
26000000ff0100001e0700000000
-
{e=>6,a=>31,d=>3,c=>2,h=>1,b=>2,g=>0,f=>3}
1f000000d20000001e0000000001
1f000000d20000001e0000000001
1f000000d20000001e0000000001
1f000000d20000001e0000000001
-
{e=>7,a=>-56,d=>-4,c=>0,h=>5,b=>1,g=>2,f=>-4}
c8ffffff01010000270200000005
c8ffffff01010000270200000005
c8ffffff01010000270200000005
c8ffffff01010000270200000005
-
{e=>7,a=>119,d=>2,c=>-4,h=>5,b=>7,g=>0,f=>-3}
77000000a70000002f0000000005
77000000a70000002f0000000005
77000000a70000002f0000000005
77000000a70000002f0000000005
-
{e=>7,a=>-122,d=>3,c=>3,h=>6,b=>2,g=>7,f=>2}
86ffffffda000000170700000006
86ffffffda000000170700000006
86ffffffda000000170700000006
86ffffffda000000170700000006
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>0,a=>66,d=>-4,c=>-4,h=>6,b=>2,g=>6,f=>3,i=>2}
4200000022010000180600000016
4200000022010000180600000016
4200000022010000180600000016
4200000022010000180600000016
-
{e=>2,a=>19,d=>-2,c=>3,h=>4,b=>6,g=>5,f=>2,i=>3}
130000009e01000012050000001c
130000009e01000012050000001c
130000009e01000012050000001c
130000009e01000012050000001c
-
{e=>1,a=>-41,d=>-3,c=>-3,h=>6,b=>5,g=>0,f=>-3,i=>-2}
d7ffffff6d010000290000000036
d7ffffff6d010000290000000036
d7ffffff6d010000290000000036
d7ffffff6d010000290000000036
-
{e=>3,a=>-25,d=>1,c=>0,h=>2,b=>2,g=>6,f=>2,i=>-3}
e7ffffff4200000013060000002a
e7ffffff4200000013060000002a
e7ffffff4200000013060000002a
e7ffffff4200000013060000002a
-
{e=>3,a=>77,d=>3,c=>-1,h=>3,b=>5,g=>6,f=>-1,i=>3}
4d000000fd0000003b060000001b
4d000000fd0000003b060000001b
4d000000fd0000003b060000001b
4d000000fd0000003b060000001b
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>7,a=>-49,d=>3,j=>4,c=>1,h=>6,b=>5,g=>7,f=>-3,i=>-2}
cfffffffcd0000002f070000003604000000
cfffffffcd0000002f070000003604000000
cfffffffcd0000002f070000003604000000
cfffffffcd0000002f070000003604000000
-
{e=>4,a=>-24,d=>-3,j=>3,c=>3,h=>3,b=>6,g=>6,f=>3,i=>1}
e8ffffff5e0100001c060000000b03000000
e8ffffff5e0100001c060000000b03000000
e8ffffff5e0100001c060000000b03000000
e8ffffff5e0100001c060000000b03000000
-
{e=>5,a=>-77,d=>1,j=>7,c=>-3,h=>0,b=>6,g=>1,f=>2,i=>1}
b3ffffff6e00000015010000000807000000
b3ffffff6e00000015010000000807000000
b3ffffff6e00000015010000000807000000
b3ffffff6e00000015010000000807000000
-
{e=>5,a=>80,d=>3,j=>5,c=>-3,h=>1,b=>6,g=>7,f=>-4,i=>3}
50000000ee00000025070000001905000000
50000000ee00000025070000001905000000
50000000ee00000025070000001905000000
50000000ee00000025070000001905000000
-
{e=>3,a=>33,d=>-4,j=>4,c=>-1,h=>5,b=>4,g=>2,f=>3,i=>-2}
210000003c0100001b020000003504000000
210000003c0100001b020000003504000000
210000003c0100001b020000003504000000
210000003c0100001b020000003504000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>1,a=>-125,d=>-4,j=>6,c=>-1,k=>-20,h=>4,b=>1,g=>5,f=>-1,i=>1}
83ffffff3901000039050000000c06000000ec
83ffffff3901000039050000000c06000000ec
83ffffff3901000039050000000c06000000ec
83ffffff3901000039050000000c06000000ec
-
{e=>6,a=>123,d=>0,j=>3,c=>1,k=>-127,h=>6,b=>5,g=>2,f=>-2,i=>-2}
7b0000000d0000003602000000360300000081
7b0000000d0000003602000000360300000081
7b0000000d0000003602000000360300000081
7b0000000d0000003602000000360300000081
-
{e=>3,a=>80,d=>-3,j=>6,c=>3,k=>-21,h=>1,b=>7,g=>5,f=>-2,i=>-1}
500000005f01000033050000003906000000eb
500000005f01000033050000003906000000eb
500000005f01000033050000003906000000eb
500000005f01000033050000003906000000eb
-
{e=>6,a=>85,d=>-2,j=>5,c=>-3,k=>-38,h=>1,b=>5,g=>2,f=>-4,i=>-1}
55000000ad01000026020000003905000000da
55000000ad01000026020000003905000000da
55000000ad01000026020000003905000000da
55000000ad01000026020000003905000000da
-
{e=>6,a=>-9,d=>-1,j=>0,c=>1,k=>20,h=>1,b=>6,g=>3,f=>-3,i=>-1}
f7ffffffce0100002e03000000390000000014
f7ffffffce0100002e03000000390000000014
f7ffffffce0100002e03000000390000000014
f7ffffffce0100002e03000000390000000014
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>5,a=>42,d=>2,j=>4,l=>7,c=>1,k=>-45,h=>5,b=>5,g=>3,f=>2,i=>1}
2a0000008d00000015030000000d04000000d307
2a0000008d00000015030000000d04000000d307
2a0000008d00000015030000000d04000000d307
2a0000008d00000015030000000d04000000d307
-
{e=>7,a=>-123,d=>2,j=>5,l=>5,c=>3,k=>-51,h=>4,b=>7,g=>5,f=>-3,i=>0}
85ffffff9f0000002f050000000405000000cd05
85ffffff9f0000002f050000000405000000cd05
85ffffff9f0000002f050000000405000000cd05
85ffffff9f0000002f050000000405000000cd05
-
{e=>0,a=>0,d=>-3,j=>0,l=>2,c=>3,k=>-69,h=>4,b=>4,g=>6,f=>-1,i=>-4}
000000005c01000038060000002400000000bb02
000000005c01000038060000002400000000bb02
000000005c01000038060000002400000000bb02
000000005c01000038060000002400000000bb02
-
{e=>0,a=>17,d=>-2,j=>3,l=>2,c=>-4,k=>-21,h=>0,b=>6,g=>7,f=>-1,i=>2}
11000000a601000038070000001003000000eb02
11000000a601000038070000001003000000eb02
11000000a601000038070000001003000000eb02
11000000a601000038070000001003000000eb02
-
{e=>2,a=>-122,d=>2,j=>5,l=>6,c=>0,k=>-75,h=>4,b=>7,g=>2,f=>-3,i=>0}
86ffffff870000002a020000000405000000b506
86ffffff870000002a020000000405000000b506
86ffffff870000002a020000000405000000b506
86ffffff870000002a020000000405000000b506
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>4,a=>-47,m=>-1,d=>-2,j=>0,l=>1,c=>2,k=>8,h=>1,b=>5,g=>4,f=>0,i=>-2}
d1ffffff95010000040400000031000000000839
d1ffffff95010000040400000031000000000839
d1ffffff95010000040400000031000000000839
d1ffffff95010000040400000031000000000839
-
{e=>4,a=>96,m=>1,d=>-1,j=>2,l=>1,c=>-4,k=>62,h=>0,b=>1,g=>6,f=>0,i=>3}
60000000e1010000040600000018020000003e09
60000000e1010000040600000018020000003e09
60000000e1010000040600000018020000003e09
60000000e1010000040600000018020000003e09
-
{e=>7,a=>119,m=>-3,d=>1,j=>2,l=>5,c=>0,k=>22,h=>2,b=>6,g=>1,f=>-4,i=>2}
770000004600000027010000001202000000162d
770000004600000027010000001202000000162d
770000004600000027010000001202000000162d
770000004600000027010000001202000000162d
-
{e=>5,a=>105,m=>-4,d=>-4,j=>6,l=>5,c=>-3,k=>5,h=>1,b=>4,g=>2,f=>1,i=>0}
690000002c0100000d0200000001060000000525
690000002c0100000d0200000001060000000525
690000002c0100000d0200000001060000000525
690000002c0100000d0200000001060000000525
-
{e=>3,a=>23,m=>1,d=>-4,j=>1,l=>2,c=>1,k=>-75,h=>5,b=>4,g=>3,f=>0,i=>3}
170000000c01000003030000001d01000000b50a
170000000c01000003030000001d01000000b50a
170000000c01000003030000001d01000000b50a
170000000c01000003030000001d01000000b50a
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>5,n=>3,a=>-113,m=>0,d=>1,j=>4,l=>0,c=>-1,k=>-9,h=>4,b=>0,g=>0,f=>2,i=>-4}
8fffffff7800000015000000002404000000f70003000000
8fffffff7800000015000000002404000000f70003000000
8fffffff7800000015000000002404000000f70003000000
8fffffff7800000015000000002404000000f70003000000
-
{e=>0,n=>4,a=>64,m=>2,d=>-3,j=>4,l=>3,c=>-3,k=>-98,h=>5,b=>3,g=>6,f=>-3,i=>-4}
400000006b010000280600000025040000009e1304000000
400000006b010000280600000025040000009e1304000000
400000006b010000280600000025040000009e1304000000
400000006b010000280600000025040000009e1304000000
-
{e=>1,n=>7,a=>-94,m=>-4,d=>3,j=>1,l=>2,c=>2,k=>-115,h=>0,b=>0,g=>6,f=>2,i=>2}
a2ffffffd0000000110600000010010000008d2207000000
a2ffffffd0000000110600000010010000008d2207000000
a2ffffffd0000000110600000010010000008d2207000000
a2ffffffd0000000110600000010010000008d2207000000
-
{e=>3,n=>0,a=>-84,m=>0,d=>-2,j=>4,l=>2,c=>-1,k=>-57,h=>4,b=>5,g=>4,f=>-1,i=>1}
acffffffbd0100003b040000000c04000000c70200000000
acffffffbd0100003b040000000c04000000c70200000000
acffffffbd0100003b040000000c04000000c70200000000
acffffffbd0100003b040000000c04000000c70200000000
-
{e=>6,n=>3,a=>-84,m=>0,d=>-2,j=>6,l=>5,c=>-4,k=>45,h=>4,b=>0,g=>3,f=>-1,i=>-3}
acffffffa00100003e030000002c060000002d0503000000
acffffffa00100003e030000002c060000002d0503000000
acffffffa00100003e030000002c060000002d0503000000
acffffffa00100003e030000002c060000002d0503000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>2,n=>1,a=>73,m=>-2,d=>1,j=>5,l=>1,c=>-4,k=>34,h=>0,b=>2,g=>0,f=>-2,o=>136,i=>0}
49000000620000003200000000000500000022310100000088
49000000620000003200000000000500000022310100000088
49000000620000003200000000000500000022310100000088
49000000620000003200000000000500000022310100000088
-
{e=>7,n=>0,a=>-14,m=>-2,d=>2,j=>2,l=>3,c=>-2,k=>-24,h=>3,b=>6,g=>5,f=>3,o=>72,i=>1}
f2ffffffb60000001f050000000b02000000e8330000000048
f2ffffffb60000001f050000000b02000000e8330000000048
f2ffffffb60000001f050000000b02000000e8330000000048
f2ffffffb60000001f050000000b02000000e8330000000048
-
{e=>7,n=>0,a=>-32,m=>0,d=>3,j=>6,l=>3,c=>-2,k=>-5,h=>3,b=>6,g=>6,f=>1,o=>139,i=>-2}
e0fffffff60000000f060000003306000000fb03000000008b
e0fffffff60000000f060000003306000000fb03000000008b
e0fffffff60000000f060000003306000000fb03000000008b
e0fffffff60000000f060000003306000000fb03000000008b
-
{e=>7,n=>0,a=>-69,m=>2,d=>2,j=>2,l=>1,c=>0,k=>118,h=>3,b=>5,g=>4,f=>-4,o=>156,i=>2}
bbffffff85000000270400000013020000007611000000009c
bbffffff85000000270400000013020000007611000000009c
bbffffff85000000270400000013020000007611000000009c
bbffffff85000000270400000013020000007611000000009c
-
{e=>0,n=>4,a=>-23,m=>-1,d=>-2,j=>3,l=>7,c=>0,k=>44,h=>7,b=>0,g=>5,f=>0,o=>146,i=>1}
e9ffffff8001000000050000000f030000002c3f0400000092
e9ffffff8001000000050000000f030000002c3f0400000092
e9ffffff8001000000050000000f030000002c3f0400000092
e9ffffff8001000000050000000f030000002c3f0400000092
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
};
-
{a=>116,b=>0}
7400000000000000
7400000000000000
7400000000000000
7400000000000000
-
{a=>-38,b=>2}
daffffff02000000
daffffff02000000
daffffff02000000
daffffff02000000
-
{a=>-116,b=>0}
8cffffff00000000
8cffffff00000000
8cffffff00000000
8cffffff00000000
-
{a=>-9,b=>4}
f7ffffff04000000
f7ffffff04000000
f7ffffff04000000
f7ffffff04000000
-
{a=>-84,b=>1}
acffffff01000000
acffffff01000000
acffffff01000000
acffffff01000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>2,a=>-53,b=>0}
cbffffff10000000
cbffffff10000000
cbffffff10000000
cbffffff10000000
-
{c=>-2,a=>54,b=>3}
3600000033000000
3600000033000000
3600000033000000
3600000033000000
-
{c=>-2,a=>90,b=>7}
5a00000037000000
5a00000037000000
5a00000037000000
5a00000037000000
-
{c=>-1,a=>16,b=>0}
1000000038000000
1000000038000000
1000000038000000
1000000038000000
-
{c=>2,a=>66,b=>6}
4200000016000000
4200000016000000
4200000016000000
4200000016000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>1,a=>101,b=>3,d=>-4}
650000000b010000
650000000b010000
650000000b010000
650000000b010000
-
{c=>0,a=>-29,b=>2,d=>-4}
e3ffffff02010000
e3ffffff02010000
e3ffffff02010000
e3ffffff02010000
-
{c=>-2,a=>-116,b=>7,d=>2}
8cffffffb7000000
8cffffffb7000000
8cffffffb7000000
8cffffffb7000000
-
{c=>-4,a=>-103,b=>1,d=>-2}
99ffffffa1010000
99ffffffa1010000
99ffffffa1010000
99ffffffa1010000
-
{c=>-4,a=>90,b=>4,d=>0}
5a00000024000000
5a00000024000000
5a00000024000000
5a00000024000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>6,c=>-3,a=>-61,b=>2,d=>-2}
c3ffffffaa01000006
c3ffffffaa01000006
c3ffffffaa01000006
c3ffffffaa01000006
-
{e=>4,c=>1,a=>111,b=>2,d=>3}
6f000000ca00000004
6f000000ca00000004
6f000000ca00000004
6f000000ca00000004
-
{e=>4,c=>0,a=>-27,b=>3,d=>-2}
e5ffffff8301000004
e5ffffff8301000004
e5ffffff8301000004
e5ffffff8301000004
-
{e=>0,c=>0,a=>123,b=>5,d=>-2}
7b0000008501000000
7b0000008501000000
7b0000008501000000
7b0000008501000000
-
{e=>2,c=>0,a=>92,b=>7,d=>-4}
5c0000000701000002
5c0000000701000002
5c0000000701000002
5c0000000701000002
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>3,c=>0,a=>-105,b=>0,d=>2,f=>0}
97ffffff8000000003
97ffffff8000000003
97ffffff8000000003
97ffffff8000000003
-
{e=>0,c=>1,a=>-22,b=>2,d=>-1,f=>-2}
eaffffffca01000030
eaffffffca01000030
eaffffffca01000030
eaffffffca01000030
-
{e=>1,c=>-3,a=>42,b=>2,d=>-1,f=>-1}
2a000000ea01000039
2a000000ea01000039
2a000000ea01000039
2a000000ea01000039
-
{e=>6,c=>0,a=>-26,b=>6,d=>-1,f=>-3}
e6ffffffc60100002e
e6ffffffc60100002e
e6ffffffc60100002e
e6ffffffc60100002e
-
{e=>2,c=>2,a=>65,b=>0,d=>0,f=>0}
410000001000000002
410000001000000002
410000001000000002
410000001000000002
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>0,c=>-2,a=>40,g=>2,b=>5,d=>2,f=>-4}
28000000b50000002002000000
28000000b50000002002000000
28000000b50000002002000000
28000000b50000002002000000
-
{e=>7,c=>3,a=>118,g=>5,b=>4,d=>-3,f=>-3}
760000005c0100002f05000000
760000005c0100002f05000000
760000005c0100002f05000000
760000005c0100002f05000000
-
{e=>5,c=>-2,a=>-74,g=>3,b=>3,d=>-4,f=>2}
b6ffffff330100001503000000
b6ffffff330100001503000000
b6ffffff330100001503000000
b6ffffff330100001503000000
-
{e=>4,c=>-4,a=>-40,g=>1,b=>7,d=>-4,f=>-1}
d8ffffff270100003c01000000
d8ffffff270100003c01000000
d8ffffff270100003c01000000
d8ffffff270100003c01000000
-
{e=>0,c=>3,a=>18,g=>6,b=>0,d=>-4,f=>1}
12000000180100000806000000
12000000180100000806000000
12000000180100000806000000
12000000180100000806000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>0,c=>-2,a=>14,g=>3,b=>7,d=>3,f=>0}
0e000000f70000000003000000
0e000000f70000000003000000
0e000000f70000000003000000
0e000000f70000000003000000
-
{e=>1,c=>0,a=>-50,g=>4,b=>7,d=>3,f=>0}
ceffffffc70000000104000000
ceffffffc70000000104000000
ceffffffc70000000104000000
ceffffffc70000000104000000
-
{e=>6,c=>-3,a=>101,g=>4,b=>2,d=>-4,f=>0}
650000002a0100000604000000
650000002a0100000604000000
650000002a0100000604000000
650000002a0100000604000000
-
{e=>4,c=>-1,a=>87,g=>0,b=>1,d=>1,f=>1}
57000000790000000c00000000
57000000790000000c00000000
57000000790000000c00000000
57000000790000000c00000000
-
{e=>3,c=>-1,a=>45,g=>7,b=>0,d=>-2,f=>3}
2d000000b80100001b07000000
2d000000b80100001b07000000
2d000000b80100001b07000000
2d000000b80100001b07000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>6,a=>-39,d=>0,c=>-2,h=>1,b=>3,g=>7,f=>-3}
d9ffffff330000002e0700000001
d9ffffff330000002e0700000001
d9ffffff330000002e0700000001
d9ffffff330000002e0700000001
-
{e=>2,a=>-6,d=>-3,c=>1,h=>0,b=>1,g=>4,f=>-1}
faffffff490100003a0400000000
faffffff490100003a0400000000
faffffff490100003a0400000000
faffffff490100003a0400000000
-
{e=>4,a=>-114,d=>3,c=>-2,h=>2,b=>6,g=>2,f=>3}
8efffffff60000001c0200000002
8efffffff60000001c0200000002
8efffffff60000001c0200000002
8efffffff60000001c0200000002
-
{e=>2,a=>-117,d=>0,c=>-2,h=>2,b=>3,g=>0,f=>0}
8bffffff33000000020000000002
8bffffff33000000020000000002
8bffffff33000000020000000002
8bffffff33000000020000000002
-
{e=>6,a=>120,d=>2,c=>1,h=>5,b=>7,g=>4,f=>-3}
780000008f0000002e0400000005
780000008f0000002e0400000005
780000008f0000002e0400000005
780000008f0000002e0400000005
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>1,a=>52,d=>1,c=>3,h=>2,b=>3,g=>6,f=>2,i=>-3}
340000005b00000011060000002a
340000005b00000011060000002a
340000005b00000011060000002a
340000005b00000011060000002a
-
{e=>3,a=>53,d=>0,c=>0,h=>1,b=>3,g=>6,f=>2,i=>1}
3500000003000000130600000009
3500000003000000130600000009
3500000003000000130600000009
3500000003000000130600000009
-
{e=>6,a=>16,d=>-4,c=>-1,h=>7,b=>1,g=>6,f=>1,i=>3}
10000000390100000e060000001f
10000000390100000e060000001f
10000000390100000e060000001f
10000000390100000e060000001f
-
{e=>5,a=>110,d=>-3,c=>-2,h=>1,b=>4,g=>6,f=>1,i=>-1}
6e000000740100000d0600000039
6e000000740100000d0600000039
6e000000740100000d0600000039
6e000000740100000d0600000039
-
{e=>2,a=>-21,d=>1,c=>3,h=>1,b=>2,g=>0,f=>-4,i=>-3}
ebffffff5a000000220000000029
ebffffff5a000000220000000029
ebffffff5a000000220000000029
ebffffff5a000000220000000029
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>3,a=>-50,d=>3,j=>1,c=>0,h=>3,b=>2,g=>2,f=>3,i=>-2}
ceffffffc20000001b020000003301000000
ceffffffc20000001b020000003301000000
ceffffffc20000001b020000003301000000
ceffffffc20000001b020000003301000000
-
{e=>1,a=>-3,d=>0,j=>2,c=>-3,h=>2,b=>0,g=>1,f=>-2,i=>-4}
fdffffff2800000031010000002202000000
fdffffff2800000031010000002202000000
fdffffff2800000031010000002202000000
fdffffff2800000031010000002202000000
-
{e=>4,a=>52,d=>-2,j=>6,c=>-2,h=>1,b=>2,g=>0,f=>0,i=>-2}
34000000b201000004000000003106000000
34000000b201000004000000003106000000
34000000b201000004000000003106000000
34000000b201000004000000003106000000
-
{e=>1,a=>99,d=>1,j=>7,c=>3,h=>7,b=>6,g=>4,f=>0,i=>3}
630000005e00000001040000001f07000000
630000005e00000001040000001f07000000
630000005e00000001040000001f07000000
630000005e00000001040000001f07000000
-
{e=>6,a=>127,d=>2,j=>0,c=>1,h=>5,b=>5,g=>5,f=>1,i=>-2}
7f0000008d0000000e050000003500000000
7f0000008d0000000e050000003500000000
7f0000008d0000000e050000003500000000
7f0000008d0000000e050000003500000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>5,a=>53,d=>-2,j=>1,c=>0,k=>-7,h=>4,b=>1,g=>5,f=>1,i=>-1}
35000000810100000d050000003c01000000f9
35000000810100000d050000003c01000000f9
35000000810100000d050000003c01000000f9
35000000810100000d050000003c01000000f9
-
{e=>4,a=>-53,d=>-4,j=>2,c=>1,k=>34,h=>7,b=>1,g=>3,f=>0,i=>0}
cbffffff090100000403000000070200000022
cbffffff090100000403000000070200000022
cbffffff090100000403000000070200000022
cbffffff090100000403000000070200000022
-
{e=>6,a=>-45,d=>3,j=>5,c=>1,k=>97,h=>4,b=>6,g=>0,f=>-3,i=>2}
d3ffffffce0000002e00000000140500000061
d3ffffffce0000002e00000000140500000061
d3ffffffce0000002e00000000140500000061
d3ffffffce0000002e00000000140500000061
-
{e=>1,a=>65,d=>1,j=>0,c=>0,k=>30,h=>0,b=>0,g=>2,f=>3,i=>-4}
4100000040000000190200000020000000001e
4100000040000000190200000020000000001e
4100000040000000190200000020000000001e
4100000040000000190200000020000000001e
-
{e=>1,a=>-80,d=>-4,j=>5,c=>-3,k=>115,h=>3,b=>5,g=>3,f=>-4,i=>3}
b0ffffff2d01000021030000001b0500000073
b0ffffff2d01000021030000001b0500000073
b0ffffff2d01000021030000001b0500000073
b0ffffff2d01000021030000001b0500000073
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>4,a=>122,d=>2,j=>4,l=>5,c=>-3,k=>111,h=>7,b=>3,g=>4,f=>2,i=>2}
7a000000ab000000140400000017040000006f05
7a000000ab000000140400000017040000006f05
7a000000ab000000140400000017040000006f05
7a000000ab000000140400000017040000006f05
-
{e=>4,a=>-118,d=>2,j=>0,l=>5,c=>-1,k=>9,h=>1,b=>4,g=>4,f=>1,i=>-3}
8affffffbc0000000c0400000029000000000905
8affffffbc0000000c0400000029000000000905
8affffffbc0000000c0400000029000000000905
8affffffbc0000000c0400000029000000000905
-
{e=>7,a=>-99,d=>-3,j=>1,l=>6,c=>3,k=>-51,h=>4,b=>0,g=>0,f=>2,i=>-1}
9dffffff5801000017000000003c01000000cd06
9dffffff5801000017000000003c01000000cd06
9dffffff5801000017000000003c01000000cd06
9dffffff5801000017000000003c01000000cd06
-
{e=>5,a=>46,d=>-1,j=>7,l=>2,c=>-4,k=>-82,h=>4,b=>6,g=>6,f=>-4,i=>-1}
2e000000e601000025060000003c07000000ae02
2e000000e601000025060000003c07000000ae02
2e000000e601000025060000003c07000000ae02
2e000000e601000025060000003c07000000ae02
-
{e=>5,a=>-15,d=>-4,j=>3,l=>1,c=>3,k=>-7,h=>3,b=>7,g=>2,f=>-3,i=>3}
f1ffffff1f0100002d020000001b03000000f901
f1ffffff1f0100002d020000001b03000000f901
f1ffffff1f0100002d020000001b03000000f901
f1ffffff1f0100002d020000001b03000000f901
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>3,a=>-125,m=>2,d=>0,j=>0,l=>5,c=>-2,k=>49,h=>6,b=>0,g=>6,f=>3,i=>-4}
83ffffff300000001b0600000026000000003115
83ffffff300000001b0600000026000000003115
83ffffff300000001b0600000026000000003115
83ffffff300000001b0600000026000000003115
-
{e=>5,a=>127,m=>1,d=>-3,j=>3,l=>3,c=>-4,k=>15,h=>1,b=>5,g=>6,f=>3,i=>1}
7f000000650100001d0600000009030000000f0b
7f000000650100001d0600000009030000000f0b
7f000000650100001d0600000009030000000f0b
7f000000650100001d0600000009030000000f0b
-
{e=>5,a=>-102,m=>2,d=>1,j=>7,l=>4,c=>-2,k=>76,h=>2,b=>5,g=>4,f=>2,i=>0}
9affffff75000000150400000002070000004c14
9affffff75000000150400000002070000004c14
9affffff75000000150400000002070000004c14
9affffff75000000150400000002070000004c14
-
{e=>3,a=>83,m=>-2,d=>-3,j=>6,l=>6,c=>-4,k=>56,h=>4,b=>0,g=>3,f=>1,i=>-1}
53000000600100000b030000003c060000003836
53000000600100000b030000003c060000003836
53000000600100000b030000003c060000003836
53000000600100000b030000003c060000003836
-
{e=>1,a=>-24,m=>-4,d=>-3,j=>0,l=>0,c=>2,k=>-52,h=>5,b=>6,g=>3,f=>2,i=>-2}
e8ffffff5601000011030000003500000000cc20
e8ffffff5601000011030000003500000000cc20
e8ffffff5601000011030000003500000000cc20
e8ffffff5601000011030000003500000000cc20
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>5,n=>0,a=>74,m=>-2,d=>1,j=>6,l=>3,c=>2,k=>113,h=>1,b=>0,g=>0,f=>0,i=>-4}
4a0000005000000005000000002106000000713300000000
4a0000005000000005000000002106000000713300000000
4a0000005000000005000000002106000000713300000000
4a0000005000000005000000002106000000713300000000
-
{e=>5,n=>3,a=>-44,m=>1,d=>-3,j=>3,l=>6,c=>2,k=>-63,h=>7,b=>0,g=>4,f=>-1,i=>3}
d4ffffff500100003d040000001f03000000c10e03000000
d4ffffff500100003d040000001f03000000c10e03000000
d4ffffff500100003d040000001f03000000c10e03000000
d4ffffff500100003d040000001f03000000c10e03000000
-
{e=>5,n=>1,a=>39,m=>1,d=>-3,j=>5,l=>0,c=>0,k=>1,h=>0,b=>1,g=>3,f=>2,i=>-1}
270000004101000015030000003805000000010801000000
270000004101000015030000003805000000010801000000
270000004101000015030000003805000000010801000000
270000004101000015030000003805000000010801000000
-
{e=>4,n=>3,a=>97,m=>-3,d=>-3,j=>7,l=>4,c=>-3,k=>75,h=>5,b=>6,g=>5,f=>3,i=>3}
610000006e0100001c050000001d070000004b2c03000000
610000006e0100001c050000001d070000004b2c03000000
610000006e0100001c050000001d070000004b2c03000000
610000006e0100001c050000001d070000004b2c03000000
-
{e=>1,n=>3,a=>77,m=>1,d=>-2,j=>3,l=>6,c=>-4,k=>50,h=>4,b=>0,g=>1,f=>-2,i=>-4}
4d000000a001000031010000002403000000320e03000000
4d000000a001000031010000002403000000320e03000000
4d000000a001000031010000002403000000320e03000000
4d000000a001000031010000002403000000320e03000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct mixed_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>2,n=>1,a=>104,m=>0,d=>3,j=>1,l=>6,c=>2,k=>-66,h=>7,b=>0,g=>4,f=>-1,o=>189,i=>-3}
68000000d00000003a040000002f01000000be0601000000bd
68000000d00000003a040000002f01000000be0601000000bd
68000000d00000003a040000002f01000000be0601000000bd
68000000d00000003a040000002f01000000be0601000000bd
-
{e=>4,n=>1,a=>-82,m=>-1,d=>-2,j=>2,l=>6,c=>3,k=>81,h=>7,b=>1,g=>0,f=>-2,o=>27,i=>-3}
aeffffff9901000034000000002f02000000513e010000001b
aeffffff9901000034000000002f02000000513e010000001b
aeffffff9901000034000000002f02000000513e010000001b
aeffffff9901000034000000002f02000000513e010000001b
-
{e=>0,n=>0,a=>110,m=>-3,d=>0,j=>2,l=>6,c=>-3,k=>27,h=>6,b=>6,g=>5,f=>0,o=>50,i=>3}
6e0000002e00000000050000001e020000001b2e0000000032
6e0000002e00000000050000001e020000001b2e0000000032
6e0000002e00000000050000001e020000001b2e0000000032
6e0000002e00000000050000001e020000001b2e0000000032
-
{e=>0,n=>5,a=>65,m=>-4,d=>1,j=>3,l=>2,c=>-1,k=>-88,h=>2,b=>4,g=>7,f=>0,o=>17,i=>1}
410000007c00000000070000000a03000000a8220500000011
410000007c00000000070000000a03000000a8220500000011
410000007c00000000070000000a03000000a8220500000011
410000007c00000000070000000a03000000a8220500000011
-
{e=>2,n=>3,a=>51,m=>-2,d=>-3,j=>1,l=>1,c=>-1,k=>-125,h=>6,b=>2,g=>2,f=>-2,o=>98,i=>2}
330000007a0100003202000000160100000083310300000062
330000007a0100003202000000160100000083310300000062
330000007a0100003202000000160100000083310300000062
330000007a0100003202000000160100000083310300000062
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
};
-
{a=>4}
04000000
04000000
04000000
04000000
-
{a=>3}
03000000
03000000
03000000
03000000
-
{a=>1}
01000000
01000000
01000000
01000000
-
{a=>5}
05000000
05000000
05000000
05000000
-
{a=>3}
03000000
03000000
03000000
03000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
};
-
{a=>1,b=>-2}
31000000
31000000
31000000
31000000
-
{a=>2,b=>3}
1a000000
1a000000
1a000000
1a000000
-
{a=>2,b=>2}
12000000
12000000
12000000
12000000
-
{a=>2,b=>-2}
32000000
32000000
32000000
32000000
-
{a=>5,b=>-4}
25000000
25000000
25000000
25000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
};
-
{c=>0,a=>0,b=>3}
18000000
18000000
18000000
18000000
-
{c=>-3,a=>0,b=>-3}
68010000
68010000
68010000
68010000
-
{c=>-3,a=>3,b=>-4}
63010000
63010000
63010000
63010000
-
{c=>-2,a=>6,b=>-2}
b6010000
b6010000
b6010000
b6010000
-
{c=>-1,a=>4,b=>-3}
ec010000
ec010000
ec010000
ec010000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
};
-
{c=>0,a=>5,b=>-1,d=>0}
3d0000000000
3d0000000000
3d0000000000
3d0000000000
-
{c=>3,a=>4,b=>-2,d=>4}
f40000000400
f40000000400
f40000000400
f40000000400
-
{c=>2,a=>0,b=>-1,d=>4}
b80000000400
b80000000400
b80000000400
b80000000400
-
{c=>-3,a=>4,b=>2,d=>3}
540100000300
540100000300
540100000300
540100000300
-
{c=>-2,a=>0,b=>0,d=>7}
800100000700
800100000700
800100000700
800100000700
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
};
-
{e=>1,c=>-1,a=>5,b=>1,d=>0}
cd0100000800
cd0100000800
cd0100000800
cd0100000800
-
{e=>-3,c=>-4,a=>1,b=>2,d=>4}
110100002c00
110100002c00
110100002c00
110100002c00
-
{e=>-1,c=>-1,a=>3,b=>0,d=>7}
c30100003f00
c30100003f00
c30100003f00
c30100003f00
-
{e=>0,c=>-3,a=>4,b=>-3,d=>0}
6c0100000000
6c0100000000
6c0100000000
6c0100000000
-
{e=>2,c=>0,a=>5,b=>1,d=>7}
0d0000001700
0d0000001700
0d0000001700
0d0000001700
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
};
-
{e=>-1,c=>3,a=>3,b=>-2,d=>2,f=>6}
f30000003a0006000000
f30000003a0006000000
f30000003a0006000000
f30000003a0006000000
-
{e=>2,c=>-1,a=>1,b=>-4,d=>5,f=>2}
e1010000150002000000
e1010000150002000000
e1010000150002000000
e1010000150002000000
-
{e=>1,c=>1,a=>3,b=>-4,d=>2,f=>6}
630000000a0006000000
630000000a0006000000
630000000a0006000000
630000000a0006000000
-
{e=>1,c=>-2,a=>2,b=>-4,d=>2,f=>3}
a20100000a0003000000
a20100000a0003000000
a20100000a0003000000
a20100000a0003000000
-
{e=>0,c=>0,a=>5,b=>-4,d=>4,f=>5}
25000000040005000000
25000000040005000000
25000000040005000000
25000000040005000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
};
-
{e=>-4,c=>-1,a=>5,b=>3,d=>2,f=>2}
dd010000220002000000
dd010000220002000000
dd010000220002000000
dd010000220002000000
-
{e=>1,c=>-1,a=>3,b=>2,d=>7,f=>6}
d30100000f0006000000
d30100000f0006000000
d30100000f0006000000
d30100000f0006000000
-
{e=>-1,c=>3,a=>0,b=>1,d=>4,f=>5}
c80000003c0005000000
c80000003c0005000000
c80000003c0005000000
c80000003c0005000000
-
{e=>1,c=>-4,a=>2,b=>1,d=>1,f=>7}
0a010000090007000000
0a010000090007000000
0a010000090007000000
0a010000090007000000
-
{e=>-4,c=>-3,a=>2,b=>-1,d=>4,f=>1}
7a010000240001000000
7a010000240001000000
7a010000240001000000
7a010000240001000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
};
-
{e=>-3,c=>3,a=>4,g=>2,b=>-1,d=>7,f=>5}
fc0000002f00050000000200
fc0000002f00050000000200
fc0000002f00050000000200
fc0000002f00050000000200
-
{e=>0,c=>-4,a=>2,g=>2,b=>-4,d=>5,f=>5}
220100000500050000000200
220100000500050000000200
220100000500050000000200
220100000500050000000200
-
{e=>2,c=>1,a=>1,g=>6,b=>3,d=>3,f=>0}
590000001300000000000600
590000001300000000000600
590000001300000000000600
590000001300000000000600
-
{e=>1,c=>-3,a=>3,g=>6,b=>2,d=>7,f=>0}
530100000f00000000000600
530100000f00000000000600
530100000f00000000000600
530100000f00000000000600
-
{e=>-4,c=>0,a=>5,g=>1,b=>-1,d=>3,f=>2}
3d0000002300020000000100
3d0000002300020000000100
3d0000002300020000000100
3d0000002300020000000100
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
};
-
{e=>-3,a=>2,d=>5,c=>-4,h=>0,b=>-1,g=>5,f=>7}
3a0100002d00070000000500
3a0100002d00070000000500
3a0100002d00070000000500
3a0100002d00070000000500
-
{e=>-3,a=>4,d=>6,c=>2,h=>-4,b=>3,g=>6,f=>3}
9c0000002e00030000002600
9c0000002e00030000002600
9c0000002e00030000002600
9c0000002e00030000002600
-
{e=>1,a=>4,d=>4,c=>3,h=>-1,b=>-2,g=>6,f=>3}
f40000000c00030000003e00
f40000000c00030000003e00
f40000000c00030000003e00
f40000000c00030000003e00
-
{e=>3,a=>5,d=>5,c=>1,h=>-2,b=>2,g=>6,f=>2}
550000001d00020000003600
550000001d00020000003600
550000001d00020000003600
550000001d00020000003600
-
{e=>1,a=>7,d=>6,c=>2,h=>0,b=>3,g=>0,f=>6}
9f0000000e00060000000000
9f0000000e00060000000000
9f0000000e00060000000000
9f0000000e00060000000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
};
-
{e=>2,a=>1,d=>3,c=>-3,h=>1,b=>-4,g=>1,f=>7,i=>5}
61010000130007000000090005000000
61010000130007000000090005000000
61010000130007000000090005000000
61010000130007000000090005000000
-
{e=>-4,a=>1,d=>3,c=>-2,h=>2,b=>-3,g=>7,f=>4,i=>3}
a9010000230004000000170003000000
a9010000230004000000170003000000
a9010000230004000000170003000000
a9010000230004000000170003000000
-
{e=>0,a=>2,d=>7,c=>3,h=>2,b=>2,g=>5,f=>2,i=>1}
d2000000070002000000150001000000
d2000000070002000000150001000000
d2000000070002000000150001000000
d2000000070002000000150001000000
-
{e=>1,a=>3,d=>2,c=>2,h=>2,b=>0,g=>7,f=>6,i=>0}
830000000a0006000000170000000000
830000000a0006000000170000000000
830000000a0006000000170000000000
830000000a0006000000170000000000
-
{e=>-4,a=>3,d=>2,c=>-1,h=>0,b=>-3,g=>4,f=>7,i=>4}
eb010000220007000000040004000000
eb010000220007000000040004000000
eb010000220007000000040004000000
eb010000220007000000040004000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
};
-
{e=>0,a=>0,d=>0,j=>-15,c=>0,h=>-4,b=>-2,g=>1,f=>2,i=>3}
30000000000002000000210003000000f100
30000000000002000000210003000000f100
30000000000002000000210003000000f100
30000000000002000000210003000000f100
-
{e=>-4,a=>2,d=>1,j=>101,c=>3,h=>1,b=>-2,g=>5,f=>1,i=>6}
f20000002100010000000d00060000006500
f20000002100010000000d00060000006500
f20000002100010000000d00060000006500
f20000002100010000000d00060000006500
-
{e=>-1,a=>0,d=>3,j=>90,c=>3,h=>3,b=>2,g=>6,f=>2,i=>1}
d00000003b00020000001e00010000005a00
d00000003b00020000001e00010000005a00
d00000003b00020000001e00010000005a00
d00000003b00020000001e00010000005a00
-
{e=>-4,a=>2,d=>2,j=>87,c=>3,h=>-1,b=>-1,g=>6,f=>4,i=>4}
fa0000002200040000003e00040000005700
fa0000002200040000003e00040000005700
fa0000002200040000003e00040000005700
fa0000002200040000003e00040000005700
-
{e=>1,a=>7,d=>3,j=>-72,c=>1,h=>0,b=>-1,g=>4,f=>1,i=>0}
7f0000000b0001000000040000000000b800
7f0000000b0001000000040000000000b800
7f0000000b0001000000040000000000b800
7f0000000b0001000000040000000000b800
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
};
-
{e=>-3,a=>3,d=>4,j=>77,c=>1,k=>1,h=>-3,b=>2,g=>3,f=>0,i=>2}
530000002c00000000002b00020000004d01
530000002c00000000002b00020000004d01
530000002c00000000002b00020000004d01
530000002c00000000002b00020000004d01
-
{e=>1,a=>1,d=>1,j=>20,c=>2,k=>1,h=>1,b=>-3,g=>3,f=>3,i=>4}
a90000000900030000000b00040000001401
a90000000900030000000b00040000001401
a90000000900030000000b00040000001401
a90000000900030000000b00040000001401
-
{e=>2,a=>5,d=>2,j=>108,c=>1,k=>5,h=>2,b=>0,g=>2,f=>5,i=>2}
450000001200050000001200020000006c05
450000001200050000001200020000006c05
450000001200050000001200020000006c05
450000001200050000001200020000006c05
-
{e=>3,a=>1,d=>1,j=>-2,c=>1,k=>7,h=>-1,b=>-3,g=>4,f=>4,i=>4}
690000001900040000003c0004000000fe07
690000001900040000003c0004000000fe07
690000001900040000003c0004000000fe07
690000001900040000003c0004000000fe07
-
{e=>0,a=>4,d=>7,j=>-104,c=>-2,k=>3,h=>2,b=>-4,g=>2,f=>6,i=>3}
a40100000700060000001200030000009803
a40100000700060000001200030000009803
a40100000700060000001200030000009803
a40100000700060000001200030000009803
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
};
-
{e=>1,a=>6,d=>7,j=>30,l=>2,c=>-1,k=>0,h=>-3,b=>-2,g=>6,f=>7,i=>5}
f60100000f00070000002e00050000001e10
f60100000f00070000002e00050000001e10
f60100000f00070000002e00050000001e10
f60100000f00070000002e00050000001e10
-
{e=>1,a=>1,d=>3,j=>-98,l=>0,c=>-1,k=>6,h=>-4,b=>-2,g=>1,f=>3,i=>1}
f10100000b00030000002100010000009e06
f10100000b00030000002100010000009e06
f10100000b00030000002100010000009e06
f10100000b00030000002100010000009e06
-
{e=>-2,a=>2,d=>1,j=>-45,l=>-2,c=>1,k=>7,h=>2,b=>-3,g=>0,f=>6,i=>6}
6a000000310006000000100006000000d337
6a000000310006000000100006000000d337
6a000000310006000000100006000000d337
6a000000310006000000100006000000d337
-
{e=>-2,a=>4,d=>2,j=>-1,l=>0,c=>-4,k=>0,h=>-3,b=>0,g=>3,f=>0,i=>4}
040100003200000000002b0004000000ff00
040100003200000000002b0004000000ff00
040100003200000000002b0004000000ff00
040100003200000000002b0004000000ff00
-
{e=>3,a=>4,d=>4,j=>110,l=>-1,c=>0,k=>1,h=>2,b=>-4,g=>0,f=>7,i=>6}
240000001c00070000001000060000006e39
240000001c00070000001000060000006e39
240000001c00070000001000060000006e39
240000001c00070000001000060000006e39
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
  unsigned int  m:3;
};
-
{e=>-2,a=>6,m=>4,d=>0,j=>28,l=>-3,c=>-3,k=>2,h=>3,b=>-1,g=>3,f=>5,i=>6}
7e0100003000050000001b00060000001c2a04000000
7e0100003000050000001b00060000001c2a04000000
7e0100003000050000001b00060000001c2a04000000
7e0100003000050000001b00060000001c2a04000000
-
{e=>-1,a=>7,m=>1,d=>6,j=>79,l=>2,c=>1,k=>3,h=>-4,b=>1,g=>1,f=>5,i=>2}
4f0000003e00050000002100020000004f1301000000
4f0000003e00050000002100020000004f1301000000
4f0000003e00050000002100020000004f1301000000
4f0000003e00050000002100020000004f1301000000
-
{e=>-3,a=>5,m=>2,d=>3,j=>43,l=>-2,c=>-4,k=>3,h=>-4,b=>-3,g=>5,f=>6,i=>5}
2d0100002b00060000002500050000002b3302000000
2d0100002b00060000002500050000002b3302000000
2d0100002b00060000002500050000002b3302000000
2d0100002b00060000002500050000002b3302000000
-
{e=>-2,a=>6,m=>4,d=>2,j=>62,l=>-2,c=>-4,k=>4,h=>-2,b=>-1,g=>1,f=>5,i=>4}
3e0100003200050000003100040000003e3404000000
3e0100003200050000003100040000003e3404000000
3e0100003200050000003100040000003e3404000000
3e0100003200050000003100040000003e3404000000
-
{e=>1,a=>1,m=>0,d=>4,j=>-74,l=>-3,c=>2,k=>1,h=>-2,b=>2,g=>2,f=>6,i=>4}
910000000c0006000000320004000000b62900000000
910000000c0006000000320004000000b62900000000
910000000c0006000000320004000000b62900000000
910000000c0006000000320004000000b62900000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  signed   char e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  unsigned int  i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
  unsigned int  m:3;
  unsigned char n;
};
-
{e=>-4,n=>116,a=>1,m=>6,d=>4,j=>-19,l=>-1,c=>-2,k=>1,h=>0,b=>-1,g=>5,f=>3,i=>5}
b9010000240003000000050005000000ed39060000007400
b9010000240003000000050005000000ed39060000007400
b9010000240003000000050005000000ed39060000007400
b9010000240003000000050005000000ed39060000007400
-
{e=>2,n=>61,a=>4,m=>3,d=>0,j=>78,l=>-2,c=>3,k=>3,h=>-3,b=>-3,g=>2,f=>0,i=>2}
ec0000001000000000002a00020000004e33030000003d00
ec0000001000000000002a00020000004e33030000003d00
ec0000001000000000002a00020000004e33030000003d00
ec0000001000000000002a00020000004e33030000003d00
-
{e=>-1,n=>150,a=>3,m=>2,d=>3,j=>-89,l=>-4,c=>-3,k=>7,h=>-3,b=>-1,g=>3,f=>5,i=>1}
7b0100003b00050000002b0001000000a727020000009600
7b0100003b00050000002b0001000000a727020000009600
7b0100003b00050000002b0001000000a727020000009600
7b0100003b00050000002b0001000000a727020000009600
-
{e=>-1,n=>162,a=>3,m=>5,d=>1,j=>46,l=>-2,c=>-1,k=>2,h=>-1,b=>3,g=>4,f=>0,i=>2}
db0100003900000000003c00020000002e3205000000a200
db0100003900000000003c00020000002e3205000000a200
db0100003900000000003c00020000002e3205000000a200
db0100003900000000003c00020000002e3205000000a200
-
{e=>-4,n=>162,a=>2,m=>5,d=>7,j=>-26,l=>2,c=>3,k=>0,h=>3,b=>-2,g=>1,f=>3,i=>6}
f2000000270003000000190006000000e61005000000a200
f2000000270003000000190006000000e61005000000a200
f2000000270003000000190006000000e61005000000a200
f2000000270003000000190006000000e61005000000a200
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
};
-
{a=>-94,b=>6}
a20006000000
a20006000000
a20006000000
a20006000000
-
{a=>-87,b=>1}
a90001000000
a90001000000
a90001000000
a90001000000
-
{a=>-8,b=>2}
f80002000000
f80002000000
f80002000000
f80002000000
-
{a=>-106,b=>2}
960002000000
960002000000
960002000000
960002000000
-
{a=>-98,b=>5}
9e0005000000
9e0005000000
9e0005000000
9e0005000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>3,a=>-72,b=>5}
b8001d000000
b8001d000000
b8001d000000
b8001d000000
-
{c=>0,a=>-13,b=>5}
f30005000000
f30005000000
f30005000000
f30005000000
-
{c=>3,a=>-92,b=>6}
a4001e000000
a4001e000000
a4001e000000
a4001e000000
-
{c=>-1,a=>79,b=>3}
4f003b000000
4f003b000000
4f003b000000
4f003b000000
-
{c=>-3,a=>-108,b=>7}
94002f000000
94002f000000
94002f000000
94002f000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>1,a=>49,b=>2,d=>-3}
31004a010000
31004a010000
31004a010000
31004a010000
-
{c=>0,a=>42,b=>7,d=>0}
2a0007000000
2a0007000000
2a0007000000
2a0007000000
-
{c=>-4,a=>41,b=>5,d=>-3}
290065010000
290065010000
290065010000
290065010000
-
{c=>1,a=>-70,b=>4,d=>0}
ba000c000000
ba000c000000
ba000c000000
ba000c000000
-
{c=>2,a=>-18,b=>5,d=>-1}
ee00d5010000
ee00d5010000
ee00d5010000
ee00d5010000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>1,c=>-3,a=>-42,b=>7,d=>-2}
d600af0100000100
d600af0100000100
d600af0100000100
d600af0100000100
-
{e=>5,c=>-4,a=>109,b=>4,d=>1}
6d00640000000500
6d00640000000500
6d00640000000500
6d00640000000500
-
{e=>7,c=>-2,a=>-119,b=>4,d=>0}
8900340000000700
8900340000000700
8900340000000700
8900340000000700
-
{e=>3,c=>-3,a=>-23,b=>6,d=>0}
e9002e0000000300
e9002e0000000300
e9002e0000000300
e9002e0000000300
-
{e=>1,c=>-4,a=>-38,b=>2,d=>3}
da00e20000000100
da00e20000000100
da00e20000000100
da00e20000000100
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>5,c=>-3,a=>-8,b=>3,d=>-1,f=>0}
f800eb0100000500
f800eb0100000500
f800eb0100000500
f800eb0100000500
-
{e=>4,c=>0,a=>3,b=>7,d=>2,f=>2}
0300870000001400
0300870000001400
0300870000001400
0300870000001400
-
{e=>4,c=>2,a=>43,b=>3,d=>-4,f=>-3}
2b00130100002c00
2b00130100002c00
2b00130100002c00
2b00130100002c00
-
{e=>2,c=>-3,a=>-97,b=>6,d=>-4,f=>1}
9f002e0100000a00
9f002e0100000a00
9f002e0100000a00
9f002e0100000a00
-
{e=>6,c=>3,a=>87,b=>5,d=>2,f=>-1}
57009d0000003e00
57009d0000003e00
57009d0000003e00
57009d0000003e00
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>7,c=>2,a=>-29,g=>2,b=>6,d=>-1,f=>-3}
e300d60100002f0002000000
e300d60100002f0002000000
e300d60100002f0002000000
e300d60100002f0002000000
-
{e=>5,c=>3,a=>-72,g=>6,b=>4,d=>-2,f=>0}
b8009c010000050006000000
b8009c010000050006000000
b8009c010000050006000000
b8009c010000050006000000
-
{e=>4,c=>0,a=>-24,g=>5,b=>4,d=>1,f=>2}
e80044000000140005000000
e80044000000140005000000
e80044000000140005000000
e80044000000140005000000
-
{e=>1,c=>-1,a=>-37,g=>1,b=>4,d=>-3,f=>1}
db007c010000090001000000
db007c010000090001000000
db007c010000090001000000
db007c010000090001000000
-
{e=>7,c=>-2,a=>92,g=>0,b=>4,d=>-2,f=>-4}
5c00b4010000270000000000
5c00b4010000270000000000
5c00b4010000270000000000
5c00b4010000270000000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>7,c=>2,a=>93,g=>4,b=>1,d=>-3,f=>3}
5d00510100001f0004000000
5d00510100001f0004000000
5d00510100001f0004000000
5d00510100001f0004000000
-
{e=>0,c=>-1,a=>-59,g=>5,b=>2,d=>-3,f=>-1}
c5007a010000380005000000
c5007a010000380005000000
c5007a010000380005000000
c5007a010000380005000000
-
{e=>5,c=>-1,a=>8,g=>5,b=>2,d=>-2,f=>-1}
0800ba0100003d0005000000
0800ba0100003d0005000000
0800ba0100003d0005000000
0800ba0100003d0005000000
-
{e=>0,c=>3,a=>-103,g=>5,b=>5,d=>1,f=>0}
99005d000000000005000000
99005d000000000005000000
99005d000000000005000000
99005d000000000005000000
-
{e=>5,c=>-3,a=>114,g=>7,b=>1,d=>-4,f=>-1}
7200290100003d0007000000
7200290100003d0007000000
7200290100003d0007000000
7200290100003d0007000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>3,a=>2,d=>0,c=>2,h=>7,b=>5,g=>6,f=>-1}
0200150000003b00060000000700
0200150000003b00060000000700
0200150000003b00060000000700
0200150000003b00060000000700
-
{e=>3,a=>-24,d=>-1,c=>-1,h=>6,b=>3,g=>2,f=>2}
e800fb0100001300020000000600
e800fb0100001300020000000600
e800fb0100001300020000000600
e800fb0100001300020000000600
-
{e=>6,a=>66,d=>0,c=>-3,h=>1,b=>3,g=>1,f=>-1}
42002b0000003e00010000000100
42002b0000003e00010000000100
42002b0000003e00010000000100
42002b0000003e00010000000100
-
{e=>7,a=>83,d=>3,c=>0,h=>1,b=>1,g=>3,f=>3}
5300c10000001f00030000000100
5300c10000001f00030000000100
5300c10000001f00030000000100
5300c10000001f00030000000100
-
{e=>2,a=>47,d=>-1,c=>-1,h=>7,b=>0,g=>5,f=>3}
2f00f80100001a00050000000700
2f00f80100001a00050000000700
2f00f80100001a00050000000700
2f00f80100001a00050000000700
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>7,a=>60,d=>-2,c=>0,h=>6,b=>2,g=>2,f=>-2,i=>-2}
3c00820100003700020000003600
3c00820100003700020000003600
3c00820100003700020000003600
3c00820100003700020000003600
-
{e=>6,a=>-97,d=>0,c=>0,h=>0,b=>3,g=>4,f=>0,i=>3}
9f00030000000600040000001800
9f00030000000600040000001800
9f00030000000600040000001800
9f00030000000600040000001800
-
{e=>3,a=>88,d=>-3,c=>-4,h=>7,b=>5,g=>1,f=>-4,i=>-2}
5800650100002300010000003700
5800650100002300010000003700
5800650100002300010000003700
5800650100002300010000003700
-
{e=>6,a=>86,d=>2,c=>0,h=>5,b=>0,g=>1,f=>3,i=>-2}
5600800000001e00010000003500
5600800000001e00010000003500
5600800000001e00010000003500
5600800000001e00010000003500
-
{e=>0,a=>52,d=>-3,c=>-4,h=>5,b=>5,g=>0,f=>3,i=>3}
3400650100001800000000001d00
3400650100001800000000001d00
3400650100001800000000001d00
3400650100001800000000001d00
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>3,a=>80,d=>-2,j=>7,c=>0,h=>3,b=>2,g=>4,f=>1,i=>3}
5000820100000b00040000001b0007000000
5000820100000b00040000001b0007000000
5000820100000b00040000001b0007000000
5000820100000b00040000001b0007000000
-
{e=>7,a=>-43,d=>-3,j=>6,c=>1,h=>2,b=>0,g=>4,f=>0,i=>3}
d500480100000700040000001a0006000000
d500480100000700040000001a0006000000
d500480100000700040000001a0006000000
d500480100000700040000001a0006000000
-
{e=>7,a=>87,d=>0,j=>3,c=>2,h=>7,b=>0,g=>7,f=>-3,i=>2}
5700100000002f0007000000170003000000
5700100000002f0007000000170003000000
5700100000002f0007000000170003000000
5700100000002f0007000000170003000000
-
{e=>1,a=>57,d=>-4,j=>7,c=>-3,h=>2,b=>7,g=>4,f=>2,i=>2}
39002f010000110004000000120007000000
39002f010000110004000000120007000000
39002f010000110004000000120007000000
39002f010000110004000000120007000000
-
{e=>1,a=>61,d=>0,j=>0,c=>-2,h=>3,b=>3,g=>7,f=>0,i=>1}
3d00330000000100070000000b0000000000
3d00330000000100070000000b0000000000
3d00330000000100070000000b0000000000
3d00330000000100070000000b0000000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>2,a=>-111,d=>2,j=>6,c=>0,k=>2,h=>7,b=>5,g=>5,f=>-2,i=>1}
9100850000003200050000000f00060000000200
9100850000003200050000000f00060000000200
9100850000003200050000000f00060000000200
9100850000003200050000000f00060000000200
-
{e=>3,a=>125,d=>-3,j=>7,c=>2,k=>102,h=>6,b=>4,g=>2,f=>-3,i=>3}
7d00540100002b00020000001e00070000006600
7d00540100002b00020000001e00070000006600
7d00540100002b00020000001e00070000006600
7d00540100002b00020000001e00070000006600
-
{e=>5,a=>-3,d=>-3,j=>4,c=>0,k=>42,h=>5,b=>0,g=>6,f=>-1,i=>-4}
fd00400100003d00060000002500040000002a00
fd00400100003d00060000002500040000002a00
fd00400100003d00060000002500040000002a00
fd00400100003d00060000002500040000002a00
-
{e=>2,a=>-127,d=>0,j=>1,c=>-1,k=>70,h=>5,b=>0,g=>0,f=>1,i=>-2}
8100380000000a00000000003500010000004600
8100380000000a00000000003500010000004600
8100380000000a00000000003500010000004600
8100380000000a00000000003500010000004600
-
{e=>0,a=>43,d=>3,j=>3,c=>2,k=>93,h=>4,b=>2,g=>6,f=>1,i=>1}
2b00d20000000800060000000c00030000005d00
2b00d20000000800060000000c00030000005d00
2b00d20000000800060000000c00030000005d00
2b00d20000000800060000000c00030000005d00
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>0,a=>-82,d=>1,j=>3,l=>2,c=>-1,k=>124,h=>4,b=>3,g=>7,f=>3,i=>-4}
ae007b0000001800070000002400030000007c02
ae007b0000001800070000002400030000007c02
ae007b0000001800070000002400030000007c02
ae007b0000001800070000002400030000007c02
-
{e=>7,a=>125,d=>-3,j=>6,l=>7,c=>-3,k=>33,h=>0,b=>5,g=>7,f=>2,i=>-3}
7d006d0100001700070000002800060000002107
7d006d0100001700070000002800060000002107
7d006d0100001700070000002800060000002107
7d006d0100001700070000002800060000002107
-
{e=>0,a=>-27,d=>-1,j=>3,l=>5,c=>-1,k=>41,h=>0,b=>7,g=>6,f=>-2,i=>-2}
e500ff0100003000060000003000030000002905
e500ff0100003000060000003000030000002905
e500ff0100003000060000003000030000002905
e500ff0100003000060000003000030000002905
-
{e=>6,a=>-76,d=>-3,j=>7,l=>0,c=>0,k=>-16,h=>5,b=>7,g=>4,f=>-1,i=>2}
b400470100003e0004000000150007000000f000
b400470100003e0004000000150007000000f000
b400470100003e0004000000150007000000f000
b400470100003e0004000000150007000000f000
-
{e=>4,a=>-66,d=>3,j=>1,l=>5,c=>2,k=>-26,h=>1,b=>6,g=>6,f=>0,i=>-1}
be00d6000000040006000000390001000000e605
be00d6000000040006000000390001000000e605
be00d6000000040006000000390001000000e605
be00d6000000040006000000390001000000e605
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>7,a=>-113,m=>3,d=>-2,j=>5,l=>3,c=>2,k=>-9,h=>0,b=>7,g=>1,f=>0,i=>1}
8f0097010000070001000000080005000000f71b
8f0097010000070001000000080005000000f71b
8f0097010000070001000000080005000000f71b
8f0097010000070001000000080005000000f71b
-
{e=>5,a=>14,m=>3,d=>-4,j=>7,l=>1,c=>-1,k=>41,h=>6,b=>4,g=>0,f=>-2,i=>-4}
0e003c0100003500000000002600070000002919
0e003c0100003500000000002600070000002919
0e003c0100003500000000002600070000002919
0e003c0100003500000000002600070000002919
-
{e=>1,a=>50,m=>2,d=>3,j=>7,l=>3,c=>-4,k=>-106,h=>4,b=>3,g=>0,f=>-1,i=>-4}
3200e30000003900000000002400070000009613
3200e30000003900000000002400070000009613
3200e30000003900000000002400070000009613
3200e30000003900000000002400070000009613
-
{e=>3,a=>122,m=>2,d=>1,j=>5,l=>6,c=>-3,k=>83,h=>4,b=>0,g=>0,f=>-2,i=>2}
7a00680000003300000000001400050000005316
7a00680000003300000000001400050000005316
7a00680000003300000000001400050000005316
7a00680000003300000000001400050000005316
-
{e=>4,a=>25,m=>-4,d=>1,j=>5,l=>0,c=>1,k=>115,h=>2,b=>1,g=>6,f=>1,i=>0}
1900490000000c00060000000200050000007320
1900490000000c00060000000200050000007320
1900490000000c00060000000200050000007320
1900490000000c00060000000200050000007320
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>3,n=>7,a=>-13,m=>2,d=>-3,j=>4,l=>5,c=>-3,k=>-63,h=>6,b=>1,g=>7,f=>3,i=>3}
f300690100001b00070000001e0004000000c11507000000
f300690100001b00070000001e0004000000c11507000000
f300690100001b00070000001e0004000000c11507000000
f300690100001b00070000001e0004000000c11507000000
-
{e=>2,n=>2,a=>10,m=>2,d=>3,j=>4,l=>0,c=>2,k=>-15,h=>1,b=>3,g=>3,f=>-3,i=>-2}
0a00d30000002a0003000000310004000000f11002000000
0a00d30000002a0003000000310004000000f11002000000
0a00d30000002a0003000000310004000000f11002000000
0a00d30000002a0003000000310004000000f11002000000
-
{e=>2,n=>5,a=>53,m=>-2,d=>2,j=>5,l=>1,c=>2,k=>-31,h=>5,b=>7,g=>4,f=>-3,i=>1}
3500970000002a00040000000d0005000000e13105000000
3500970000002a00040000000d0005000000e13105000000
3500970000002a00040000000d0005000000e13105000000
3500970000002a00040000000d0005000000e13105000000
-
{e=>2,n=>3,a=>92,m=>3,d=>3,j=>6,l=>6,c=>-2,k=>99,h=>7,b=>3,g=>4,f=>-4,i=>-2}
5c00f3000000220004000000370006000000631e03000000
5c00f3000000220004000000370006000000631e03000000
5c00f3000000220004000000370006000000631e03000000
5c00f3000000220004000000370006000000631e03000000
-
{e=>2,n=>6,a=>-14,m=>1,d=>0,j=>0,l=>2,c=>-4,k=>1,h=>7,b=>7,g=>4,f=>1,i=>-3}
f200270000000a00040000002f0000000000010a06000000
f200270000000a00040000002f0000000000010a06000000
f200270000000a00040000002f0000000000010a06000000
f200270000000a00040000002f0000000000010a06000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>0,n=>5,a=>61,m=>-2,d=>-4,j=>1,l=>6,c=>1,k=>-87,h=>5,b=>7,g=>7,f=>-1,o=>42,i=>1}
3d000f0100003800070000000d0001000000a936050000002a00
3d000f0100003800070000000d0001000000a936050000002a00
3d000f0100003800070000000d0001000000a936050000002a00
3d000f0100003800070000000d0001000000a936050000002a00
-
{e=>1,n=>4,a=>116,m=>-1,d=>-4,j=>0,l=>7,c=>3,k=>-107,h=>2,b=>6,g=>5,f=>0,o=>162,i=>3}
74001e0100000100050000001a0000000000953f04000000a200
74001e0100000100050000001a0000000000953f04000000a200
74001e0100000100050000001a0000000000953f04000000a200
74001e0100000100050000001a0000000000953f04000000a200
-
{e=>4,n=>5,a=>114,m=>-3,d=>-2,j=>4,l=>5,c=>-2,k=>68,h=>3,b=>7,g=>3,f=>-2,o=>112,i=>-2}
7200b7010000340003000000330004000000442d050000007000
7200b7010000340003000000330004000000442d050000007000
7200b7010000340003000000330004000000442d050000007000
7200b7010000340003000000330004000000442d050000007000
-
{e=>2,n=>7,a=>-31,m=>-2,d=>-2,j=>7,l=>7,c=>-4,k=>20,h=>2,b=>1,g=>3,f=>-3,o=>162,i=>-2}
e100a10100002a0003000000320007000000143707000000a200
e100a10100002a0003000000320007000000143707000000a200
e100a10100002a0003000000320007000000143707000000a200
e100a10100002a0003000000320007000000143707000000a200
-
{e=>2,n=>1,a=>-39,m=>-4,d=>-1,j=>4,l=>3,c=>1,k=>-123,h=>7,b=>7,g=>5,f=>1,o=>105,i=>-2}
d900cf0100000a00050000003700040000008523010000006900
d900cf0100000a00050000003700040000008523010000006900
d900cf0100000a00050000003700040000008523010000006900
d900cf0100000a00050000003700040000008523010000006900
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
};
-
{a=>103,b=>3}
670003000000
670003000000
670003000000
670003000000
-
{a=>38,b=>4}
260004000000
260004000000
260004000000
260004000000
-
{a=>52,b=>0}
340000000000
340000000000
340000000000
340000000000
-
{a=>-12,b=>3}
f4ff03000000
f4ff03000000
f4ff03000000
f4ff03000000
-
{a=>5,b=>6}
050006000000
050006000000
050006000000
050006000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>0,a=>-92,b=>5}
a4ff05000000
a4ff05000000
a4ff05000000
a4ff05000000
-
{c=>-2,a=>-97,b=>2}
9fff32000000
9fff32000000
9fff32000000
9fff32000000
-
{c=>3,a=>-63,b=>1}
c1ff19000000
c1ff19000000
c1ff19000000
c1ff19000000
-
{c=>2,a=>93,b=>2}
5d0012000000
5d0012000000
5d0012000000
5d0012000000
-
{c=>2,a=>1,b=>3}
010013000000
010013000000
010013000000
010013000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-2,a=>65,b=>6,d=>-1}
4100f6010000
4100f6010000
4100f6010000
4100f6010000
-
{c=>-2,a=>107,b=>0,d=>3}
6b00f0000000
6b00f0000000
6b00f0000000
6b00f0000000
-
{c=>-2,a=>-7,b=>3,d=>1}
f9ff73000000
f9ff73000000
f9ff73000000
f9ff73000000
-
{c=>-1,a=>-11,b=>3,d=>0}
f5ff3b000000
f5ff3b000000
f5ff3b000000
f5ff3b000000
-
{c=>-3,a=>-10,b=>7,d=>-3}
f6ff6f010000
f6ff6f010000
f6ff6f010000
f6ff6f010000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>7,c=>-3,a=>69,b=>7,d=>-2}
4500af0100000700
4500af0100000700
4500af0100000700
4500af0100000700
-
{e=>1,c=>1,a=>92,b=>7,d=>3}
5c00cf0000000100
5c00cf0000000100
5c00cf0000000100
5c00cf0000000100
-
{e=>5,c=>-3,a=>104,b=>7,d=>1}
68006f0000000500
68006f0000000500
68006f0000000500
68006f0000000500
-
{e=>6,c=>-3,a=>50,b=>7,d=>1}
32006f0000000600
32006f0000000600
32006f0000000600
32006f0000000600
-
{e=>6,c=>-3,a=>52,b=>5,d=>2}
3400ad0000000600
3400ad0000000600
3400ad0000000600
3400ad0000000600
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>2,c=>1,a=>-16,b=>7,d=>-4,f=>2}
f0ff0f0100001200
f0ff0f0100001200
f0ff0f0100001200
f0ff0f0100001200
-
{e=>3,c=>1,a=>-81,b=>2,d=>-3,f=>-2}
afff4a0100003300
afff4a0100003300
afff4a0100003300
afff4a0100003300
-
{e=>0,c=>-2,a=>-7,b=>6,d=>2,f=>2}
f9ffb60000001000
f9ffb60000001000
f9ffb60000001000
f9ffb60000001000
-
{e=>5,c=>3,a=>46,b=>4,d=>1,f=>3}
2e005c0000001d00
2e005c0000001d00
2e005c0000001d00
2e005c0000001d00
-
{e=>2,c=>-4,a=>110,b=>3,d=>2,f=>-3}
6e00a30000002a00
6e00a30000002a00
6e00a30000002a00
6e00a30000002a00
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>1,c=>2,a=>-118,g=>2,b=>2,d=>1,f=>1}
8aff52000000090002000000
8aff52000000090002000000
8aff52000000090002000000
8aff52000000090002000000
-
{e=>7,c=>-3,a=>73,g=>6,b=>3,d=>-4,f=>3}
49002b0100001f0006000000
49002b0100001f0006000000
49002b0100001f0006000000
49002b0100001f0006000000
-
{e=>0,c=>-4,a=>51,g=>5,b=>3,d=>-1,f=>-1}
3300e3010000380005000000
3300e3010000380005000000
3300e3010000380005000000
3300e3010000380005000000
-
{e=>6,c=>0,a=>-60,g=>3,b=>4,d=>-3,f=>1}
c4ff440100000e0003000000
c4ff440100000e0003000000
c4ff440100000e0003000000
c4ff440100000e0003000000
-
{e=>3,c=>-4,a=>-59,g=>0,b=>1,d=>-3,f=>3}
c5ff610100001b0000000000
c5ff610100001b0000000000
c5ff610100001b0000000000
c5ff610100001b0000000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>5,c=>-3,a=>-108,g=>3,b=>6,d=>-1,f=>-4}
94ffee010000250003000000
94ffee010000250003000000
94ffee010000250003000000
94ffee010000250003000000
-
{e=>0,c=>1,a=>1,g=>6,b=>4,d=>-3,f=>-3}
01004c010000280006000000
01004c010000280006000000
01004c010000280006000000
01004c010000280006000000
-
{e=>7,c=>-3,a=>-122,g=>3,b=>2,d=>-4,f=>1}
86ff2a0100000f0003000000
86ff2a0100000f0003000000
86ff2a0100000f0003000000
86ff2a0100000f0003000000
-
{e=>4,c=>-2,a=>112,g=>2,b=>6,d=>-4,f=>1}
7000360100000c0002000000
7000360100000c0002000000
7000360100000c0002000000
7000360100000c0002000000
-
{e=>0,c=>-1,a=>-72,g=>6,b=>5,d=>3,f=>-4}
b8fffd000000200006000000
b8fffd000000200006000000
b8fffd000000200006000000
b8fffd000000200006000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>7,a=>108,d=>2,c=>0,h=>5,b=>7,g=>0,f=>3}
6c00870000001f00000000000500
6c00870000001f00000000000500
6c00870000001f00000000000500
6c00870000001f00000000000500
-
{e=>3,a=>126,d=>-1,c=>3,h=>6,b=>3,g=>6,f=>-2}
7e00db0100003300060000000600
7e00db0100003300060000000600
7e00db0100003300060000000600
7e00db0100003300060000000600
-
{e=>0,a=>-62,d=>-2,c=>-4,h=>1,b=>5,g=>7,f=>-1}
c2ffa50100003800070000000100
c2ffa50100003800070000000100
c2ffa50100003800070000000100
c2ffa50100003800070000000100
-
{e=>4,a=>102,d=>2,c=>2,h=>7,b=>1,g=>3,f=>-1}
6600910000003c00030000000700
6600910000003c00030000000700
6600910000003c00030000000700
6600910000003c00030000000700
-
{e=>5,a=>-66,d=>2,c=>-4,h=>7,b=>7,g=>7,f=>-2}
beffa70000003500070000000700
beffa70000003500070000000700
beffa70000003500070000000700
beffa70000003500070000000700
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>7,a=>114,d=>1,c=>-2,h=>7,b=>7,g=>2,f=>-1,i=>-2}
7200770000003f00020000003700
7200770000003f00020000003700
7200770000003f00020000003700
7200770000003f00020000003700
-
{e=>1,a=>-112,d=>-3,c=>2,h=>5,b=>5,g=>1,f=>-2,i=>-2}
90ff550100003100010000003500
90ff550100003100010000003500
90ff550100003100010000003500
90ff550100003100010000003500
-
{e=>5,a=>88,d=>0,c=>1,h=>4,b=>4,g=>6,f=>-2,i=>2}
58000c0000003500060000001400
58000c0000003500060000001400
58000c0000003500060000001400
58000c0000003500060000001400
-
{e=>2,a=>-8,d=>-2,c=>-1,h=>5,b=>0,g=>4,f=>-4,i=>0}
f8ffb80100002200040000000500
f8ffb80100002200040000000500
f8ffb80100002200040000000500
f8ffb80100002200040000000500
-
{e=>7,a=>-35,d=>3,c=>3,h=>0,b=>4,g=>0,f=>-2,i=>-4}
ddffdc0000003700000000002000
ddffdc0000003700000000002000
ddffdc0000003700000000002000
ddffdc0000003700000000002000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>0,a=>-31,d=>-2,j=>5,c=>-3,h=>0,b=>0,g=>5,f=>-3,i=>3}
e1ffa8010000280005000000180005000000
e1ffa8010000280005000000180005000000
e1ffa8010000280005000000180005000000
e1ffa8010000280005000000180005000000
-
{e=>3,a=>0,d=>-1,j=>1,c=>-1,h=>0,b=>2,g=>1,f=>-2,i=>2}
0000fa010000330001000000100001000000
0000fa010000330001000000100001000000
0000fa010000330001000000100001000000
0000fa010000330001000000100001000000
-
{e=>0,a=>72,d=>-1,j=>5,c=>2,h=>6,b=>5,g=>1,f=>-4,i=>-4}
4800d5010000200001000000260005000000
4800d5010000200001000000260005000000
4800d5010000200001000000260005000000
4800d5010000200001000000260005000000
-
{e=>5,a=>84,d=>1,j=>1,c=>1,h=>3,b=>5,g=>2,f=>-3,i=>2}
54004d0000002d0002000000130001000000
54004d0000002d0002000000130001000000
54004d0000002d0002000000130001000000
54004d0000002d0002000000130001000000
-
{e=>2,a=>75,d=>1,j=>3,c=>1,h=>2,b=>7,g=>5,f=>-2,i=>0}
4b004f000000320005000000020003000000
4b004f000000320005000000020003000000
4b004f000000320005000000020003000000
4b004f000000320005000000020003000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>7,a=>-23,d=>-3,j=>1,c=>-3,k=>-79,h=>4,b=>0,g=>6,f=>0,i=>1}
e9ff680100000700060000000c0001000000b100
e9ff680100000700060000000c0001000000b100
e9ff680100000700060000000c0001000000b100
e9ff680100000700060000000c0001000000b100
-
{e=>2,a=>-89,d=>0,j=>5,c=>1,k=>-14,h=>6,b=>6,g=>6,f=>3,i=>-3}
a7ff0e0000001a00060000002e0005000000f200
a7ff0e0000001a00060000002e0005000000f200
a7ff0e0000001a00060000002e0005000000f200
a7ff0e0000001a00060000002e0005000000f200
-
{e=>1,a=>-23,d=>0,j=>2,c=>1,k=>-2,h=>1,b=>1,g=>5,f=>2,i=>-2}
e9ff09000000110005000000310002000000fe00
e9ff09000000110005000000310002000000fe00
e9ff09000000110005000000310002000000fe00
e9ff09000000110005000000310002000000fe00
-
{e=>7,a=>-84,d=>-2,j=>3,c=>-4,k=>1,h=>6,b=>3,g=>4,f=>-2,i=>-4}
acffa30100003700040000002600030000000100
acffa30100003700040000002600030000000100
acffa30100003700040000002600030000000100
acffa30100003700040000002600030000000100
-
{e=>4,a=>-2,d=>-1,j=>3,c=>3,k=>-56,h=>3,b=>2,g=>6,f=>0,i=>-2}
feffda010000040006000000330003000000c800
feffda010000040006000000330003000000c800
feffda010000040006000000330003000000c800
feffda010000040006000000330003000000c800
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>1,a=>43,d=>-2,j=>3,l=>3,c=>0,k=>-20,h=>3,b=>4,g=>1,f=>1,i=>-2}
2b0084010000090001000000330003000000ec03
2b0084010000090001000000330003000000ec03
2b0084010000090001000000330003000000ec03
2b0084010000090001000000330003000000ec03
-
{e=>1,a=>-33,d=>1,j=>3,l=>2,c=>-3,k=>77,h=>2,b=>4,g=>0,f=>2,i=>2}
dfff6c0000001100000000001200030000004d02
dfff6c0000001100000000001200030000004d02
dfff6c0000001100000000001200030000004d02
dfff6c0000001100000000001200030000004d02
-
{e=>7,a=>122,d=>0,j=>5,l=>3,c=>-3,k=>-62,h=>7,b=>5,g=>3,f=>3,i=>0}
7a002d0000001f0003000000070005000000c203
7a002d0000001f0003000000070005000000c203
7a002d0000001f0003000000070005000000c203
7a002d0000001f0003000000070005000000c203
-
{e=>4,a=>36,d=>3,j=>2,l=>1,c=>0,k=>-1,h=>6,b=>7,g=>1,f=>-3,i=>-3}
2400c70000002c00010000002e0002000000ff01
2400c70000002c00010000002e0002000000ff01
2400c70000002c00010000002e0002000000ff01
2400c70000002c00010000002e0002000000ff01
-
{e=>2,a=>126,d=>-4,j=>2,l=>3,c=>0,k=>-47,h=>2,b=>6,g=>7,f=>0,i=>-4}
7e0006010000020007000000220002000000d103
7e0006010000020007000000220002000000d103
7e0006010000020007000000220002000000d103
7e0006010000020007000000220002000000d103
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>0,a=>-59,m=>-4,d=>1,j=>2,l=>7,c=>0,k=>-30,h=>2,b=>7,g=>7,f=>-1,i=>0}
c5ff47000000380007000000020002000000e227
c5ff47000000380007000000020002000000e227
c5ff47000000380007000000020002000000e227
c5ff47000000380007000000020002000000e227
-
{e=>5,a=>-106,m=>-1,d=>3,j=>2,l=>5,c=>3,k=>84,h=>4,b=>3,g=>3,f=>-3,i=>-1}
96ffdb0000002d00030000003c0002000000543d
96ffdb0000002d00030000003c0002000000543d
96ffdb0000002d00030000003c0002000000543d
96ffdb0000002d00030000003c0002000000543d
-
{e=>1,a=>41,m=>1,d=>1,j=>7,l=>5,c=>2,k=>33,h=>5,b=>7,g=>4,f=>-1,i=>-1}
2900570000003900040000003d0007000000210d
2900570000003900040000003d0007000000210d
2900570000003900040000003d0007000000210d
2900570000003900040000003d0007000000210d
-
{e=>7,a=>53,m=>0,d=>2,j=>5,l=>6,c=>0,k=>-74,h=>1,b=>1,g=>6,f=>-1,i=>-4}
3500810000003f0006000000210005000000b606
3500810000003f0006000000210005000000b606
3500810000003f0006000000210005000000b606
3500810000003f0006000000210005000000b606
-
{e=>0,a=>-26,m=>0,d=>-3,j=>0,l=>6,c=>1,k=>94,h=>3,b=>2,g=>5,f=>3,i=>-2}
e6ff4a0100001800050000003300000000005e06
e6ff4a0100001800050000003300000000005e06
e6ff4a0100001800050000003300000000005e06
e6ff4a0100001800050000003300000000005e06
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>3,n=>3,a=>116,m=>1,d=>-1,j=>4,l=>5,c=>-4,k=>-99,h=>6,b=>1,g=>1,f=>-1,i=>-4}
7400e10100003b00010000002600040000009d0d03000000
7400e10100003b00010000002600040000009d0d03000000
7400e10100003b00010000002600040000009d0d03000000
7400e10100003b00010000002600040000009d0d03000000
-
{e=>5,n=>6,a=>-60,m=>-4,d=>-1,j=>1,l=>5,c=>0,k=>-90,h=>3,b=>3,g=>2,f=>-2,i=>-3}
c4ffc30100003500020000002b0001000000a62506000000
c4ffc30100003500020000002b0001000000a62506000000
c4ffc30100003500020000002b0001000000a62506000000
c4ffc30100003500020000002b0001000000a62506000000
-
{e=>1,n=>3,a=>101,m=>1,d=>1,j=>5,l=>4,c=>-1,k=>0,h=>0,b=>0,g=>3,f=>3,i=>2}
650078000000190003000000100005000000000c03000000
650078000000190003000000100005000000000c03000000
650078000000190003000000100005000000000c03000000
650078000000190003000000100005000000000c03000000
-
{e=>1,n=>5,a=>-81,m=>-2,d=>1,j=>4,l=>7,c=>-3,k=>24,h=>2,b=>7,g=>4,f=>2,i=>1}
afff6f0000001100040000000a0004000000183705000000
afff6f0000001100040000000a0004000000183705000000
afff6f0000001100040000000a0004000000183705000000
afff6f0000001100040000000a0004000000183705000000
-
{e=>5,n=>7,a=>69,m=>-1,d=>-4,j=>4,l=>5,c=>-3,k=>-48,h=>3,b=>1,g=>1,f=>-3,i=>1}
4500290100002d00010000000b0004000000d03d07000000
4500290100002d00010000000b0004000000d03d07000000
4500290100002d00010000000b0004000000d03d07000000
4500290100002d00010000000b0004000000d03d07000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>6,n=>1,a=>-4,m=>-3,d=>1,j=>6,l=>4,c=>1,k=>-26,h=>3,b=>6,g=>0,f=>3,o=>238,i=>2}
fcff4e0000001e0000000000130006000000e62c01000000ee00
fcff4e0000001e0000000000130006000000e62c01000000ee00
fcff4e0000001e0000000000130006000000e62c01000000ee00
fcff4e0000001e0000000000130006000000e62c01000000ee00
-
{e=>0,n=>1,a=>-68,m=>-2,d=>1,j=>5,l=>3,c=>-2,k=>121,h=>3,b=>2,g=>1,f=>-2,o=>129,i=>2}
bcff720000003000010000001300050000007933010000008100
bcff720000003000010000001300050000007933010000008100
bcff720000003000010000001300050000007933010000008100
bcff720000003000010000001300050000007933010000008100
-
{e=>0,n=>3,a=>-111,m=>-4,d=>2,j=>1,l=>5,c=>-4,k=>58,h=>7,b=>2,g=>1,f=>-4,o=>239,i=>-2}
91ffa20000002000010000003700010000003a2503000000ef00
91ffa20000002000010000003700010000003a2503000000ef00
91ffa20000002000010000003700010000003a2503000000ef00
91ffa20000002000010000003700010000003a2503000000ef00
-
{e=>0,n=>5,a=>-114,m=>-2,d=>-4,j=>1,l=>2,c=>2,k=>-17,h=>7,b=>3,g=>3,f=>-3,o=>107,i=>-1}
8eff130100002800030000003f0001000000ef32050000006b00
8eff130100002800030000003f0001000000ef32050000006b00
8eff130100002800030000003f0001000000ef32050000006b00
8eff130100002800030000003f0001000000ef32050000006b00
-
{e=>1,n=>6,a=>-2,m=>1,d=>0,j=>0,l=>6,c=>1,k=>68,h=>6,b=>2,g=>4,f=>-3,o=>139,i=>1}
feff0a0000002900040000000e0000000000440e060000008b00
feff0a0000002900040000000e0000000000440e060000008b00
feff0a0000002900040000000e0000000000440e060000008b00
feff0a0000002900040000000e0000000000440e060000008b00
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
};
-
{a=>109,b=>7}
6d00000007000000
6d00000007000000
6d00000007000000
6d00000007000000
-
{a=>-103,b=>4}
99ffffff04000000
99ffffff04000000
99ffffff04000000
99ffffff04000000
-
{a=>111,b=>4}
6f00000004000000
6f00000004000000
6f00000004000000
6f00000004000000
-
{a=>-58,b=>4}
c6ffffff04000000
c6ffffff04000000
c6ffffff04000000
c6ffffff04000000
-
{a=>117,b=>4}
7500000004000000
7500000004000000
7500000004000000
7500000004000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>-4,a=>54,b=>7}
3600000027000000
3600000027000000
3600000027000000
3600000027000000
-
{c=>-4,a=>-26,b=>7}
e6ffffff27000000
e6ffffff27000000
e6ffffff27000000
e6ffffff27000000
-
{c=>1,a=>35,b=>7}
230000000f000000
230000000f000000
230000000f000000
230000000f000000
-
{c=>-3,a=>59,b=>0}
3b00000028000000
3b00000028000000
3b00000028000000
3b00000028000000
-
{c=>-3,a=>70,b=>2}
460000002a000000
460000002a000000
460000002a000000
460000002a000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-4,a=>-61,b=>4,d=>2}
c3ffffffa4000000
c3ffffffa4000000
c3ffffffa4000000
c3ffffffa4000000
-
{c=>-3,a=>79,b=>5,d=>3}
4f000000ed000000
4f000000ed000000
4f000000ed000000
4f000000ed000000
-
{c=>-3,a=>-113,b=>0,d=>-3}
8fffffff68010000
8fffffff68010000
8fffffff68010000
8fffffff68010000
-
{c=>-3,a=>-20,b=>5,d=>3}
ecffffffed000000
ecffffffed000000
ecffffffed000000
ecffffffed000000
-
{c=>-1,a=>84,b=>7,d=>-3}
540000007f010000
540000007f010000
540000007f010000
540000007f010000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>4,c=>0,a=>-47,b=>6,d=>-1}
d1ffffffc60100000400
d1ffffffc60100000400
d1ffffffc60100000400
d1ffffffc60100000400
-
{e=>3,c=>1,a=>-93,b=>5,d=>-3}
a3ffffff4d0100000300
a3ffffff4d0100000300
a3ffffff4d0100000300
a3ffffff4d0100000300
-
{e=>1,c=>3,a=>123,b=>0,d=>-1}
7b000000d80100000100
7b000000d80100000100
7b000000d80100000100
7b000000d80100000100
-
{e=>1,c=>-1,a=>-36,b=>7,d=>3}
dcffffffff0000000100
dcffffffff0000000100
dcffffffff0000000100
dcffffffff0000000100
-
{e=>2,c=>0,a=>-51,b=>2,d=>1}
cdffffff420000000200
cdffffff420000000200
cdffffff420000000200
cdffffff420000000200
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>6,c=>-3,a=>54,b=>4,d=>-3,f=>1}
360000006c0100000e00
360000006c0100000e00
360000006c0100000e00
360000006c0100000e00
-
{e=>4,c=>2,a=>53,b=>2,d=>-4,f=>0}
35000000120100000400
35000000120100000400
35000000120100000400
35000000120100000400
-
{e=>3,c=>1,a=>-32,b=>6,d=>2,f=>1}
e0ffffff8e0000000b00
e0ffffff8e0000000b00
e0ffffff8e0000000b00
e0ffffff8e0000000b00
-
{e=>4,c=>-4,a=>57,b=>1,d=>-1,f=>-4}
39000000e10100002400
39000000e10100002400
39000000e10100002400
39000000e10100002400
-
{e=>2,c=>-2,a=>-128,b=>2,d=>0,f=>-2}
80ffffff320000003200
80ffffff320000003200
80ffffff320000003200
80ffffff320000003200
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>7,c=>-2,a=>-88,g=>0,b=>2,d=>3,f=>-4}
a8fffffff2000000270000000000
a8fffffff2000000270000000000
a8fffffff2000000270000000000
a8fffffff2000000270000000000
-
{e=>5,c=>-3,a=>90,g=>6,b=>2,d=>-1,f=>1}
5a000000ea0100000d0006000000
5a000000ea0100000d0006000000
5a000000ea0100000d0006000000
5a000000ea0100000d0006000000
-
{e=>4,c=>3,a=>68,g=>6,b=>2,d=>-1,f=>-3}
44000000da0100002c0006000000
44000000da0100002c0006000000
44000000da0100002c0006000000
44000000da0100002c0006000000
-
{e=>0,c=>3,a=>54,g=>6,b=>1,d=>-2,f=>2}
3600000099010000100006000000
3600000099010000100006000000
3600000099010000100006000000
3600000099010000100006000000
-
{e=>2,c=>2,a=>45,g=>3,b=>1,d=>2,f=>-4}
2d00000091000000220003000000
2d00000091000000220003000000
2d00000091000000220003000000
2d00000091000000220003000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>3,c=>2,a=>-87,g=>6,b=>4,d=>0,f=>-1}
a9ffffff140000003b0006000000
a9ffffff140000003b0006000000
a9ffffff140000003b0006000000
a9ffffff140000003b0006000000
-
{e=>7,c=>-3,a=>103,g=>6,b=>0,d=>2,f=>-4}
67000000a8000000270006000000
67000000a8000000270006000000
67000000a8000000270006000000
67000000a8000000270006000000
-
{e=>2,c=>2,a=>-32,g=>2,b=>6,d=>2,f=>-2}
e0ffffff96000000320002000000
e0ffffff96000000320002000000
e0ffffff96000000320002000000
e0ffffff96000000320002000000
-
{e=>5,c=>0,a=>122,g=>7,b=>4,d=>-4,f=>1}
7a000000040100000d0007000000
7a000000040100000d0007000000
7a000000040100000d0007000000
7a000000040100000d0007000000
-
{e=>4,c=>-2,a=>-85,g=>0,b=>0,d=>-3,f=>-3}
abffffff700100002c0000000000
abffffff700100002c0000000000
abffffff700100002c0000000000
abffffff700100002c0000000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>2,a=>-79,d=>-4,c=>2,h=>5,b=>0,g=>4,f=>-4}
b1ffffff100100002200040000000500
b1ffffff100100002200040000000500
b1ffffff100100002200040000000500
b1ffffff100100002200040000000500
-
{e=>1,a=>61,d=>1,c=>-2,h=>7,b=>2,g=>4,f=>-3}
3d000000720000002900040000000700
3d000000720000002900040000000700
3d000000720000002900040000000700
3d000000720000002900040000000700
-
{e=>7,a=>-36,d=>3,c=>-2,h=>0,b=>2,g=>0,f=>-1}
dcfffffff20000003f00000000000000
dcfffffff20000003f00000000000000
dcfffffff20000003f00000000000000
dcfffffff20000003f00000000000000
-
{e=>3,a=>-11,d=>-2,c=>-4,h=>2,b=>6,g=>5,f=>3}
f5ffffffa60100001b00050000000200
f5ffffffa60100001b00050000000200
f5ffffffa60100001b00050000000200
f5ffffffa60100001b00050000000200
-
{e=>7,a=>-10,d=>1,c=>-3,h=>4,b=>7,g=>0,f=>3}
f6ffffff6f0000001f00000000000400
f6ffffff6f0000001f00000000000400
f6ffffff6f0000001f00000000000400
f6ffffff6f0000001f00000000000400
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>6,a=>32,d=>-2,c=>1,h=>7,b=>7,g=>0,f=>1,i=>3}
200000008f0100000e00000000001f00
200000008f0100000e00000000001f00
200000008f0100000e00000000001f00
200000008f0100000e00000000001f00
-
{e=>7,a=>-98,d=>-3,c=>3,h=>1,b=>1,g=>1,f=>-1,i=>1}
9effffff590100003f00010000000900
9effffff590100003f00010000000900
9effffff590100003f00010000000900
9effffff590100003f00010000000900
-
{e=>0,a=>-83,d=>-2,c=>-4,h=>7,b=>5,g=>5,f=>-4,i=>1}
adffffffa50100002000050000000f00
adffffffa50100002000050000000f00
adffffffa50100002000050000000f00
adffffffa50100002000050000000f00
-
{e=>6,a=>-52,d=>-4,c=>-4,h=>5,b=>5,g=>0,f=>-1,i=>-2}
ccffffff250100003e00000000003500
ccffffff250100003e00000000003500
ccffffff250100003e00000000003500
ccffffff250100003e00000000003500
-
{e=>4,a=>123,d=>2,c=>0,h=>6,b=>7,g=>2,f=>-1,i=>0}
7b000000870000003c00020000000600
7b000000870000003c00020000000600
7b000000870000003c00020000000600
7b000000870000003c00020000000600
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>3,a=>62,d=>-1,j=>3,c=>-2,h=>0,b=>7,g=>2,f=>1,i=>-3}
3e000000f70100000b0002000000280003000000
3e000000f70100000b0002000000280003000000
3e000000f70100000b0002000000280003000000
3e000000f70100000b0002000000280003000000
-
{e=>6,a=>-59,d=>2,j=>5,c=>1,h=>5,b=>5,g=>7,f=>3,i=>0}
c5ffffff8d0000001e0007000000050005000000
c5ffffff8d0000001e0007000000050005000000
c5ffffff8d0000001e0007000000050005000000
c5ffffff8d0000001e0007000000050005000000
-
{e=>6,a=>76,d=>0,j=>7,c=>2,h=>1,b=>4,g=>2,f=>1,i=>-1}
4c000000140000000e0002000000390007000000
4c000000140000000e0002000000390007000000
4c000000140000000e0002000000390007000000
4c000000140000000e0002000000390007000000
-
{e=>6,a=>-74,d=>0,j=>1,c=>1,h=>5,b=>6,g=>7,f=>3,i=>-1}
b6ffffff0e0000001e00070000003d0001000000
b6ffffff0e0000001e00070000003d0001000000
b6ffffff0e0000001e00070000003d0001000000
b6ffffff0e0000001e00070000003d0001000000
-
{e=>0,a=>-90,d=>-4,j=>4,c=>3,h=>5,b=>5,g=>2,f=>-2,i=>0}
a6ffffff1d010000300002000000050004000000
a6ffffff1d010000300002000000050004000000
a6ffffff1d010000300002000000050004000000
a6ffffff1d010000300002000000050004000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>6,a=>-103,d=>-1,j=>0,c=>1,k=>-31,h=>7,b=>0,g=>1,f=>1,i=>-3}
99ffffffc80100000e00010000002f0000000000e100
99ffffffc80100000e00010000002f0000000000e100
99ffffffc80100000e00010000002f0000000000e100
99ffffffc80100000e00010000002f0000000000e100
-
{e=>5,a=>-2,d=>-1,j=>6,c=>0,k=>78,h=>6,b=>1,g=>4,f=>3,i=>3}
feffffffc10100001d00040000001e00060000004e00
feffffffc10100001d00040000001e00060000004e00
feffffffc10100001d00040000001e00060000004e00
feffffffc10100001d00040000001e00060000004e00
-
{e=>3,a=>-110,d=>-1,j=>1,c=>2,k=>-117,h=>6,b=>1,g=>6,f=>1,i=>2}
92ffffffd10100000b00060000001600010000008b00
92ffffffd10100000b00060000001600010000008b00
92ffffffd10100000b00060000001600010000008b00
92ffffffd10100000b00060000001600010000008b00
-
{e=>3,a=>-42,d=>-2,j=>0,c=>-2,k=>-72,h=>4,b=>5,g=>4,f=>-4,i=>1}
d6ffffffb50100002300040000000c0000000000b800
d6ffffffb50100002300040000000c0000000000b800
d6ffffffb50100002300040000000c0000000000b800
d6ffffffb50100002300040000000c0000000000b800
-
{e=>1,a=>117,d=>-4,j=>1,c=>-3,k=>97,h=>4,b=>0,g=>1,f=>2,i=>-3}
75000000280100001100010000002c00010000006100
75000000280100001100010000002c00010000006100
75000000280100001100010000002c00010000006100
75000000280100001100010000002c00010000006100
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>3,a=>-57,d=>2,j=>6,l=>1,c=>0,k=>73,h=>5,b=>5,g=>3,f=>1,i=>-3}
c7ffffff850000000b00030000002d00060000004901
c7ffffff850000000b00030000002d00060000004901
c7ffffff850000000b00030000002d00060000004901
c7ffffff850000000b00030000002d00060000004901
-
{e=>6,a=>-107,d=>1,j=>5,l=>4,c=>-2,k=>25,h=>2,b=>1,g=>3,f=>3,i=>3}
95ffffff710000001e00030000001a00050000001904
95ffffff710000001e00030000001a00050000001904
95ffffff710000001e00030000001a00050000001904
95ffffff710000001e00030000001a00050000001904
-
{e=>2,a=>108,d=>-3,j=>1,l=>5,c=>-3,k=>74,h=>4,b=>7,g=>4,f=>0,i=>-3}
6c0000006f0100000200040000002c00010000004a05
6c0000006f0100000200040000002c00010000004a05
6c0000006f0100000200040000002c00010000004a05
6c0000006f0100000200040000002c00010000004a05
-
{e=>7,a=>-5,d=>3,j=>2,l=>7,c=>-3,k=>54,h=>0,b=>1,g=>0,f=>-2,i=>-1}
fbffffffe90000003700000000003800020000003607
fbffffffe90000003700000000003800020000003607
fbffffffe90000003700000000003800020000003607
fbffffffe90000003700000000003800020000003607
-
{e=>0,a=>-52,d=>2,j=>2,l=>0,c=>0,k=>118,h=>7,b=>0,g=>4,f=>1,i=>3}
ccffffff800000000800040000001f00020000007600
ccffffff800000000800040000001f00020000007600
ccffffff800000000800040000001f00020000007600
ccffffff800000000800040000001f00020000007600
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>3,a=>-84,m=>1,d=>0,j=>1,l=>3,c=>-2,k=>78,h=>2,b=>4,g=>7,f=>2,i=>-3}
acffffff340000001300070000002a00010000004e0b
acffffff340000001300070000002a00010000004e0b
acffffff340000001300070000002a00010000004e0b
acffffff340000001300070000002a00010000004e0b
-
{e=>7,a=>80,m=>-4,d=>0,j=>6,l=>1,c=>3,k=>-88,h=>3,b=>1,g=>7,f=>-3,i=>1}
50000000190000002f00070000000b0006000000a821
50000000190000002f00070000000b0006000000a821
50000000190000002f00070000000b0006000000a821
50000000190000002f00070000000b0006000000a821
-
{e=>6,a=>112,m=>-2,d=>1,j=>3,l=>1,c=>3,k=>69,h=>2,b=>1,g=>4,f=>-1,i=>2}
70000000590000003e00040000001200030000004531
70000000590000003e00040000001200030000004531
70000000590000003e00040000001200030000004531
70000000590000003e00040000001200030000004531
-
{e=>1,a=>110,m=>-1,d=>0,j=>1,l=>3,c=>0,k=>-21,h=>1,b=>4,g=>0,f=>2,i=>1}
6e00000004000000110000000000090001000000eb3b
6e00000004000000110000000000090001000000eb3b
6e00000004000000110000000000090001000000eb3b
6e00000004000000110000000000090001000000eb3b
-
{e=>7,a=>35,m=>-2,d=>0,j=>1,l=>1,c=>3,k=>36,h=>3,b=>4,g=>4,f=>-4,i=>-3}
230000001c0000002700040000002b00010000002431
230000001c0000002700040000002b00010000002431
230000001c0000002700040000002b00010000002431
230000001c0000002700040000002b00010000002431
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>2,n=>0,a=>-6,m=>3,d=>0,j=>7,l=>2,c=>-4,k=>-55,h=>7,b=>3,g=>5,f=>2,i=>-2}
faffffff23000000120005000000370007000000c91a00000000
faffffff23000000120005000000370007000000c91a00000000
faffffff23000000120005000000370007000000c91a00000000
faffffff23000000120005000000370007000000c91a00000000
-
{e=>1,n=>7,a=>-87,m=>0,d=>0,j=>6,l=>4,c=>-2,k=>24,h=>7,b=>2,g=>1,f=>-3,i=>-3}
a9ffffff320000002900010000002f0006000000180407000000
a9ffffff320000002900010000002f0006000000180407000000
a9ffffff320000002900010000002f0006000000180407000000
a9ffffff320000002900010000002f0006000000180407000000
-
{e=>4,n=>4,a=>-107,m=>-1,d=>-2,j=>6,l=>0,c=>1,k=>-90,h=>5,b=>5,g=>2,f=>-4,i=>-2}
95ffffff8d010000240002000000350006000000a63804000000
95ffffff8d010000240002000000350006000000a63804000000
95ffffff8d010000240002000000350006000000a63804000000
95ffffff8d010000240002000000350006000000a63804000000
-
{e=>1,n=>5,a=>-24,m=>-2,d=>-4,j=>6,l=>7,c=>1,k=>-102,h=>1,b=>5,g=>0,f=>-2,i=>0}
e8ffffff0d0100003100000000000100060000009a3705000000
e8ffffff0d0100003100000000000100060000009a3705000000
e8ffffff0d0100003100000000000100060000009a3705000000
e8ffffff0d0100003100000000000100060000009a3705000000
-
{e=>0,n=>4,a=>127,m=>-2,d=>-1,j=>7,l=>4,c=>-4,k=>68,h=>0,b=>1,g=>4,f=>-4,i=>-3}
7f000000e1010000200004000000280007000000443404000000
7f000000e1010000200004000000280007000000443404000000
7f000000e1010000200004000000280007000000443404000000
7f000000e1010000200004000000280007000000443404000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>2,n=>4,a=>47,m=>3,d=>0,j=>7,l=>0,c=>3,k=>-117,h=>2,b=>3,g=>0,f=>-4,o=>238,i=>-3}
2f0000001b0000002200000000002a00070000008b1804000000ee00
2f0000001b0000002200000000002a00070000008b1804000000ee00
2f0000001b0000002200000000002a00070000008b1804000000ee00
2f0000001b0000002200000000002a00070000008b1804000000ee00
-
{e=>1,n=>4,a=>-56,m=>-3,d=>0,j=>0,l=>3,c=>-3,k=>-65,h=>0,b=>6,g=>7,f=>-2,o=>157,i=>3}
c8ffffff2e000000310007000000180000000000bf2b040000009d00
c8ffffff2e000000310007000000180000000000bf2b040000009d00
c8ffffff2e000000310007000000180000000000bf2b040000009d00
c8ffffff2e000000310007000000180000000000bf2b040000009d00
-
{e=>6,n=>5,a=>44,m=>1,d=>1,j=>3,l=>1,c=>1,k=>57,h=>1,b=>7,g=>4,f=>2,o=>68,i=>2}
2c0000004f0000001600040000001100030000003909050000004400
2c0000004f0000001600040000001100030000003909050000004400
2c0000004f0000001600040000001100030000003909050000004400
2c0000004f0000001600040000001100030000003909050000004400
-
{e=>2,n=>6,a=>-122,m=>0,d=>0,j=>6,l=>6,c=>3,k=>87,h=>1,b=>2,g=>7,f=>2,o=>182,i=>3}
86ffffff1a000000120007000000190006000000570606000000b600
86ffffff1a000000120007000000190006000000570606000000b600
86ffffff1a000000120007000000190006000000570606000000b600
86ffffff1a000000120007000000190006000000570606000000b600
-
{e=>6,n=>4,a=>-93,m=>0,d=>-3,j=>5,l=>2,c=>2,k=>104,h=>6,b=>0,g=>1,f=>-3,o=>134,i=>-1}
a3ffffff500100002e00010000003e00050000006802040000008600
a3ffffff500100002e00010000003e00050000006802040000008600
a3ffffff500100002e00010000003e00050000006802040000008600
a3ffffff500100002e00010000003e00050000006802040000008600
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
};
-
{a=>92,b=>7}
5c00000007000000
5c00000007000000
5c00000007000000
5c00000007000000
-
{a=>73,b=>2}
4900000002000000
4900000002000000
4900000002000000
4900000002000000
-
{a=>-17,b=>2}
efffffff02000000
efffffff02000000
efffffff02000000
efffffff02000000
-
{a=>6,b=>0}
0600000000000000
0600000000000000
0600000000000000
0600000000000000
-
{a=>-12,b=>7}
f4ffffff07000000
f4ffffff07000000
f4ffffff07000000
f4ffffff07000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>0,a=>5,b=>1}
0500000001000000
0500000001000000
0500000001000000
0500000001000000
-
{c=>3,a=>54,b=>3}
360000001b000000
360000001b000000
360000001b000000
360000001b000000
-
{c=>3,a=>58,b=>0}
3a00000018000000
3a00000018000000
3a00000018000000
3a00000018000000
-
{c=>2,a=>-6,b=>6}
faffffff16000000
faffffff16000000
faffffff16000000
faffffff16000000
-
{c=>1,a=>-30,b=>2}
e2ffffff0a000000
e2ffffff0a000000
e2ffffff0a000000
e2ffffff0a000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>3,a=>18,b=>6,d=>1}
120000005e000000
120000005e000000
120000005e000000
120000005e000000
-
{c=>-1,a=>-92,b=>2,d=>-2}
a4ffffffba010000
a4ffffffba010000
a4ffffffba010000
a4ffffffba010000
-
{c=>-1,a=>-128,b=>5,d=>3}
80fffffffd000000
80fffffffd000000
80fffffffd000000
80fffffffd000000
-
{c=>-4,a=>-90,b=>0,d=>0}
a6ffffff20000000
a6ffffff20000000
a6ffffff20000000
a6ffffff20000000
-
{c=>2,a=>-12,b=>2,d=>2}
f4ffffff92000000
f4ffffff92000000
f4ffffff92000000
f4ffffff92000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>4,c=>-2,a=>-52,b=>1,d=>-2}
ccffffffb10100000400
ccffffffb10100000400
ccffffffb10100000400
ccffffffb10100000400
-
{e=>3,c=>2,a=>-5,b=>6,d=>0}
fbffffff160000000300
fbffffff160000000300
fbffffff160000000300
fbffffff160000000300
-
{e=>5,c=>-4,a=>51,b=>1,d=>-2}
33000000a10100000500
33000000a10100000500
33000000a10100000500
33000000a10100000500
-
{e=>2,c=>2,a=>-120,b=>6,d=>-4}
88ffffff160100000200
88ffffff160100000200
88ffffff160100000200
88ffffff160100000200
-
{e=>5,c=>1,a=>-11,b=>3,d=>2}
f5ffffff8b0000000500
f5ffffff8b0000000500
f5ffffff8b0000000500
f5ffffff8b0000000500
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
};
-
{e=>6,c=>-4,a=>-32,b=>4,d=>0,f=>-1}
e0ffffff240000003e00
e0ffffff240000003e00
e0ffffff240000003e00
e0ffffff240000003e00
-
{e=>5,c=>2,a=>50,b=>1,d=>2,f=>1}
32000000910000000d00
32000000910000000d00
32000000910000000d00
32000000910000000d00
-
{e=>7,c=>-2,a=>106,b=>5,d=>-4,f=>1}
6a000000350100000f00
6a000000350100000f00
6a000000350100000f00
6a000000350100000f00
-
{e=>4,c=>-4,a=>-26,b=>5,d=>-3,f=>-4}
e6ffffff650100002400
e6ffffff650100002400
e6ffffff650100002400
e6ffffff650100002400
-
{e=>6,c=>1,a=>30,b=>1,d=>-3,f=>1}
1e000000490100000e00
1e000000490100000e00
1e000000490100000e00
1e000000490100000e00
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
};
-
{e=>2,c=>-3,a=>34,g=>7,b=>0,d=>0,f=>-2}
2200000028000000320007000000
2200000028000000320007000000
2200000028000000320007000000
2200000028000000320007000000
-
{e=>7,c=>1,a=>-121,g=>0,b=>5,d=>0,f=>-2}
87ffffff0d000000370000000000
87ffffff0d000000370000000000
87ffffff0d000000370000000000
87ffffff0d000000370000000000
-
{e=>3,c=>-3,a=>0,g=>1,b=>0,d=>2,f=>-1}
00000000a80000003b0001000000
00000000a80000003b0001000000
00000000a80000003b0001000000
00000000a80000003b0001000000
-
{e=>5,c=>-3,a=>-126,g=>5,b=>5,d=>-3,f=>3}
82ffffff6d0100001d0005000000
82ffffff6d0100001d0005000000
82ffffff6d0100001d0005000000
82ffffff6d0100001d0005000000
-
{e=>0,c=>2,a=>-72,g=>7,b=>0,d=>3,f=>3}
b8ffffffd0000000180007000000
b8ffffffd0000000180007000000
b8ffffffd0000000180007000000
b8ffffffd0000000180007000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>1,c=>-1,a=>16,g=>1,b=>3,d=>-4,f=>-4}
100000003b010000210001000000
100000003b010000210001000000
100000003b010000210001000000
100000003b010000210001000000
-
{e=>5,c=>-2,a=>-124,g=>2,b=>1,d=>3,f=>3}
84fffffff10000001d0002000000
84fffffff10000001d0002000000
84fffffff10000001d0002000000
84fffffff10000001d0002000000
-
{e=>3,c=>-4,a=>-30,g=>6,b=>6,d=>0,f=>-3}
e2ffffff260000002b0006000000
e2ffffff260000002b0006000000
e2ffffff260000002b0006000000
e2ffffff260000002b0006000000
-
{e=>5,c=>-4,a=>101,g=>4,b=>2,d=>2,f=>2}
65000000a2000000150004000000
65000000a2000000150004000000
65000000a2000000150004000000
65000000a2000000150004000000
-
{e=>0,c=>1,a=>-30,g=>0,b=>0,d=>-1,f=>-1}
e2ffffffc8010000380000000000
e2ffffffc8010000380000000000
e2ffffffc8010000380000000000
e2ffffffc8010000380000000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>3,a=>-63,d=>-4,c=>-3,h=>4,b=>0,g=>7,f=>-1}
c1ffffff280100003b00070000000400
c1ffffff280100003b00070000000400
c1ffffff280100003b00070000000400
c1ffffff280100003b00070000000400
-
{e=>1,a=>-112,d=>3,c=>0,h=>7,b=>3,g=>1,f=>2}
90ffffffc30000001100010000000700
90ffffffc30000001100010000000700
90ffffffc30000001100010000000700
90ffffffc30000001100010000000700
-
{e=>5,a=>-65,d=>-1,c=>2,h=>5,b=>6,g=>4,f=>-2}
bfffffffd60100003500040000000500
bfffffffd60100003500040000000500
bfffffffd60100003500040000000500
bfffffffd60100003500040000000500
-
{e=>7,a=>63,d=>0,c=>-4,h=>3,b=>5,g=>4,f=>1}
3f000000250000000f00040000000300
3f000000250000000f00040000000300
3f000000250000000f00040000000300
3f000000250000000f00040000000300
-
{e=>3,a=>-66,d=>-3,c=>3,h=>4,b=>0,g=>2,f=>-3}
beffffff580100002b00020000000400
beffffff580100002b00020000000400
beffffff580100002b00020000000400
beffffff580100002b00020000000400
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>0,a=>-44,d=>-1,c=>-2,h=>7,b=>4,g=>5,f=>-3,i=>1}
d4fffffff40100002800050000000f00
d4fffffff40100002800050000000f00
d4fffffff40100002800050000000f00
d4fffffff40100002800050000000f00
-
{e=>2,a=>-106,d=>-4,c=>2,h=>0,b=>5,g=>5,f=>-3,i=>-2}
96ffffff150100002a00050000003000
96ffffff150100002a00050000003000
96ffffff150100002a00050000003000
96ffffff150100002a00050000003000
-
{e=>0,a=>127,d=>-4,c=>2,h=>5,b=>2,g=>1,f=>-2,i=>-4}
7f000000120100003000010000002500
7f000000120100003000010000002500
7f000000120100003000010000002500
7f000000120100003000010000002500
-
{e=>2,a=>-89,d=>1,c=>-2,h=>5,b=>4,g=>0,f=>-2,i=>3}
a7ffffff740000003200000000001d00
a7ffffff740000003200000000001d00
a7ffffff740000003200000000001d00
a7ffffff740000003200000000001d00
-
{e=>3,a=>86,d=>2,c=>1,h=>6,b=>4,g=>7,f=>3,i=>-4}
560000008c0000001b00070000002600
560000008c0000001b00070000002600
560000008c0000001b00070000002600
560000008c0000001b00070000002600
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
};
-
{e=>2,a=>68,d=>-3,j=>7,c=>-1,h=>6,b=>2,g=>2,f=>-2,i=>-1}
440000007a0100003200020000003e0007000000
440000007a0100003200020000003e0007000000
440000007a0100003200020000003e0007000000
440000007a0100003200020000003e0007000000
-
{e=>5,a=>125,d=>2,j=>0,c=>2,h=>0,b=>0,g=>1,f=>2,i=>3}
7d00000090000000150001000000180000000000
7d00000090000000150001000000180000000000
7d00000090000000150001000000180000000000
7d00000090000000150001000000180000000000
-
{e=>7,a=>-98,d=>-3,j=>3,c=>1,h=>0,b=>2,g=>0,f=>3,i=>2}
9effffff4a0100001f0000000000100003000000
9effffff4a0100001f0000000000100003000000
9effffff4a0100001f0000000000100003000000
9effffff4a0100001f0000000000100003000000
-
{e=>6,a=>65,d=>-4,j=>2,c=>2,h=>4,b=>4,g=>6,f=>0,i=>-1}
41000000140100000600060000003c0002000000
41000000140100000600060000003c0002000000
41000000140100000600060000003c0002000000
41000000140100000600060000003c0002000000
-
{e=>4,a=>-43,d=>-4,j=>1,c=>0,h=>7,b=>1,g=>0,f=>1,i=>2}
d5ffffff010100000c0000000000170001000000
d5ffffff010100000c0000000000170001000000
d5ffffff010100000c0000000000170001000000
d5ffffff010100000c0000000000170001000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
};
-
{e=>7,a=>86,d=>3,j=>2,c=>0,k=>-13,h=>7,b=>3,g=>7,f=>3,i=>-4}
56000000c30000001f0007000000270002000000f300
56000000c30000001f0007000000270002000000f300
56000000c30000001f0007000000270002000000f300
56000000c30000001f0007000000270002000000f300
-
{e=>5,a=>-12,d=>-3,j=>6,c=>-3,k=>-95,h=>0,b=>6,g=>0,f=>-2,i=>-3}
f4ffffff6e010000350000000000280006000000a100
f4ffffff6e010000350000000000280006000000a100
f4ffffff6e010000350000000000280006000000a100
f4ffffff6e010000350000000000280006000000a100
-
{e=>6,a=>-124,d=>3,j=>3,c=>-3,k=>50,h=>6,b=>7,g=>2,f=>-1,i=>-1}
84ffffffef0000003e00020000003e00030000003200
84ffffffef0000003e00020000003e00030000003200
84ffffffef0000003e00020000003e00030000003200
84ffffffef0000003e00020000003e00030000003200
-
{e=>2,a=>47,d=>0,j=>0,c=>-4,k=>102,h=>3,b=>7,g=>6,f=>-4,i=>2}
2f000000270000002200060000001300000000006600
2f000000270000002200060000001300000000006600
2f000000270000002200060000001300000000006600
2f000000270000002200060000001300000000006600
-
{e=>5,a=>95,d=>0,j=>6,c=>0,k=>66,h=>6,b=>6,g=>6,f=>-4,i=>-4}
5f000000060000002500060000002600060000004200
5f000000060000002500060000002600060000004200
5f000000060000002500060000002600060000004200
5f000000060000002500060000002600060000004200
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>7,a=>101,d=>-2,j=>1,l=>0,c=>-3,k=>83,h=>7,b=>0,g=>3,f=>-4,i=>2}
65000000a80100002700030000001700010000005300
65000000a80100002700030000001700010000005300
65000000a80100002700030000001700010000005300
65000000a80100002700030000001700010000005300
-
{e=>7,a=>-82,d=>2,j=>3,l=>2,c=>1,k=>50,h=>0,b=>2,g=>7,f=>-2,i=>-2}
aeffffff8a0000003700070000003000030000003202
aeffffff8a0000003700070000003000030000003202
aeffffff8a0000003700070000003000030000003202
aeffffff8a0000003700070000003000030000003202
-
{e=>5,a=>49,d=>-3,j=>1,l=>7,c=>-2,k=>-9,h=>7,b=>5,g=>5,f=>-1,i=>2}
31000000750100003d0005000000170001000000f707
31000000750100003d0005000000170001000000f707
31000000750100003d0005000000170001000000f707
31000000750100003d0005000000170001000000f707
-
{e=>0,a=>-76,d=>3,j=>0,l=>0,c=>-1,k=>-27,h=>7,b=>6,g=>6,f=>-1,i=>-4}
b4fffffffe000000380006000000270000000000e500
b4fffffffe000000380006000000270000000000e500
b4fffffffe000000380006000000270000000000e500
b4fffffffe000000380006000000270000000000e500
-
{e=>5,a=>62,d=>2,j=>1,l=>2,c=>-1,k=>-59,h=>5,b=>1,g=>5,f=>-2,i=>-2}
3e000000b9000000350005000000350001000000c502
3e000000b9000000350005000000350001000000c502
3e000000b9000000350005000000350001000000c502
3e000000b9000000350005000000350001000000c502
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>7,a=>61,m=>-3,d=>-2,j=>7,l=>1,c=>3,k=>-49,h=>5,b=>0,g=>1,f=>-3,i=>0}
3d000000980100002f0001000000050007000000cf29
3d000000980100002f0001000000050007000000cf29
3d000000980100002f0001000000050007000000cf29
3d000000980100002f0001000000050007000000cf29
-
{e=>6,a=>115,m=>-1,d=>0,j=>4,l=>2,c=>-2,k=>32,h=>7,b=>4,g=>3,f=>-2,i=>-2}
7300000034000000360003000000370004000000203a
7300000034000000360003000000370004000000203a
7300000034000000360003000000370004000000203a
7300000034000000360003000000370004000000203a
-
{e=>7,a=>74,m=>3,d=>-1,j=>6,l=>5,c=>-1,k=>34,h=>3,b=>4,g=>4,f=>2,i=>2}
4a000000fc010000170004000000130006000000221d
4a000000fc010000170004000000130006000000221d
4a000000fc010000170004000000130006000000221d
4a000000fc010000170004000000130006000000221d
-
{e=>3,a=>91,m=>-3,d=>0,j=>2,l=>7,c=>-1,k=>-86,h=>5,b=>0,g=>1,f=>-1,i=>-4}
5b000000380000003b0001000000250002000000aa2f
5b000000380000003b0001000000250002000000aa2f
5b000000380000003b0001000000250002000000aa2f
5b000000380000003b0001000000250002000000aa2f
-
{e=>4,a=>-16,m=>0,d=>2,j=>2,l=>3,c=>-2,k=>-46,h=>7,b=>2,g=>0,f=>-1,i=>-3}
f0ffffffb20000003c00000000002f0002000000d203
f0ffffffb20000003c00000000002f0002000000d203
f0ffffffb20000003c00000000002f0002000000d203
f0ffffffb20000003c00000000002f0002000000d203
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>1,n=>1,a=>-128,m=>-2,d=>2,j=>3,l=>2,c=>3,k=>-47,h=>3,b=>1,g=>0,f=>1,i=>0}
80ffffff99000000090000000000030003000000d13201000000
80ffffff99000000090000000000030003000000d13201000000
80ffffff99000000090000000000030003000000d13201000000
80ffffff99000000090000000000030003000000d13201000000
-
{e=>0,n=>3,a=>39,m=>2,d=>2,j=>2,l=>2,c=>-2,k=>-60,h=>2,b=>2,g=>1,f=>-4,i=>-1}
27000000b20000002000010000003a0002000000c41203000000
27000000b20000002000010000003a0002000000c41203000000
27000000b20000002000010000003a0002000000c41203000000
27000000b20000002000010000003a0002000000c41203000000
-
{e=>0,n=>7,a=>86,m=>-3,d=>-2,j=>4,l=>4,c=>-1,k=>24,h=>1,b=>4,g=>3,f=>-2,i=>3}
56000000bc010000300003000000190004000000182c07000000
56000000bc010000300003000000190004000000182c07000000
56000000bc010000300003000000190004000000182c07000000
56000000bc010000300003000000190004000000182c07000000
-
{e=>3,n=>4,a=>-28,m=>2,d=>3,j=>2,l=>5,c=>0,k=>-23,h=>7,b=>2,g=>7,f=>1,i=>1}
e4ffffffc20000000b00070000000f0002000000e91504000000
e4ffffffc20000000b00070000000f0002000000e91504000000
e4ffffffc20000000b00070000000f0002000000e91504000000
e4ffffffc20000000b00070000000f0002000000e91504000000
-
{e=>3,n=>3,a=>-127,m=>-4,d=>-2,j=>6,l=>7,c=>0,k=>51,h=>2,b=>0,g=>5,f=>-3,i=>-2}
81ffffff800100002b0005000000320006000000332703000000
81ffffff800100002b0005000000320006000000332703000000
81ffffff800100002b0005000000320006000000332703000000
81ffffff800100002b0005000000320006000000332703000000
=
typedef int foo;

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct mixed_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  signed   char f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  unsigned int  j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>2,n=>5,a=>-107,m=>2,d=>3,j=>1,l=>1,c=>-1,k=>88,h=>1,b=>3,g=>2,f=>3,o=>104,i=>2}
95fffffffb0000001a00020000001100010000005811050000006800
95fffffffb0000001a00020000001100010000005811050000006800
95fffffffb0000001a00020000001100010000005811050000006800
95fffffffb0000001a00020000001100010000005811050000006800
-
{e=>1,n=>6,a=>84,m=>-1,d=>-2,j=>3,l=>7,c=>1,k=>29,h=>2,b=>3,g=>3,f=>-2,o=>30,i=>-3}
540000008b0100003100030000002a00030000001d3f060000001e00
540000008b0100003100030000002a00030000001d3f060000001e00
540000008b0100003100030000002a00030000001d3f060000001e00
540000008b0100003100030000002a00030000001d3f060000001e00
-
{e=>3,n=>0,a=>79,m=>3,d=>-3,j=>2,l=>6,c=>1,k=>125,h=>1,b=>2,g=>3,f=>3,o=>59,i=>-1}
4f0000004a0100001b00030000003900020000007d1e000000003b00
4f0000004a0100001b00030000003900020000007d1e000000003b00
4f0000004a0100001b00030000003900020000007d1e000000003b00
4f0000004a0100001b00030000003900020000007d1e000000003b00
-
{e=>7,n=>7,a=>112,m=>-1,d=>3,j=>4,l=>0,c=>1,k=>-29,h=>5,b=>4,g=>4,f=>-2,o=>130,i=>2}
70000000cc000000370004000000150004000000e338070000008200
70000000cc000000370004000000150004000000e338070000008200
70000000cc000000370004000000150004000000e338070000008200
70000000cc000000370004000000150004000000e338070000008200
-
{e=>7,n=>0,a=>27,m=>-1,d=>2,j=>1,l=>6,c=>-2,k=>40,h=>4,b=>0,g=>5,f=>1,o=>182,i=>-4}
1b000000b00000000f0005000000240001000000283e00000000b600
1b000000b00000000f0005000000240001000000283e00000000b600
1b000000b00000000f0005000000240001000000283e00000000b600
1b000000b00000000f0005000000240001000000283e00000000b600
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
};
-
{a=>3}
03000000
03000000
03000000
03000000
-
{a=>1}
01000000
01000000
01000000
01000000
-
{a=>1}
01000000
01000000
01000000
01000000
-
{a=>6}
06000000
06000000
06000000
06000000
-
{a=>5}
05000000
05000000
05000000
05000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
};
-
{a=>4,b=>-3}
2c000000
2c000000
2c000000
2c000000
-
{a=>7,b=>-4}
27000000
27000000
27000000
27000000
-
{a=>3,b=>-3}
2b000000
2b000000
2b000000
2b000000
-
{a=>3,b=>-3}
2b000000
2b000000
2b000000
2b000000
-
{a=>6,b=>-3}
2e000000
2e000000
2e000000
2e000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
};
-
{c=>3,a=>7,b=>-3}
ef000000
ef000000
ef000000
ef000000
-
{c=>-3,a=>7,b=>-3}
6f010000
6f010000
6f010000
6f010000
-
{c=>-4,a=>0,b=>2}
10010000
10010000
10010000
10010000
-
{c=>1,a=>0,b=>3}
58000000
58000000
58000000
58000000
-
{c=>-1,a=>5,b=>-2}
f5010000
f5010000
f5010000
f5010000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
};
-
{c=>1,a=>5,b=>-2,d=>7}
7500000007
7500000007
7500000007
7500000007
-
{c=>-3,a=>0,b=>-4,d=>1}
6001000001
6001000001
6001000001
6001000001
-
{c=>-4,a=>4,b=>-2,d=>0}
3401000000
3401000000
3401000000
3401000000
-
{c=>0,a=>3,b=>3,d=>5}
1b00000005
1b00000005
1b00000005
1b00000005
-
{c=>-4,a=>6,b=>2,d=>3}
1601000003
1601000003
1601000003
1601000003
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
};
-
{e=>'UE6',c=>2,a=>1,b=>-1,d=>1}
b90000000106000000
b90000000106000000
b90000000106000000
b90000000106000000
-
{e=>'UE7',c=>-2,a=>1,b=>1,d=>0}
890100000007000000
890100000007000000
890100000007000000
890100000007000000
-
{e=>'UE7',c=>-4,a=>0,b=>-1,d=>4}
380100000407000000
380100000407000000
380100000407000000
380100000407000000
-
{e=>'UE0',c=>-3,a=>4,b=>-4,d=>0}
640100000000000000
640100000000000000
640100000000000000
640100000000000000
-
{e=>'UE5',c=>-3,a=>5,b=>-3,d=>0}
6d0100000005000000
6d0100000005000000
6d0100000005000000
6d0100000005000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
};
-
{e=>'UE2',c=>-2,a=>7,b=>1,d=>7,f=>1}
8f010000070a000000
8f010000070a000000
8f010000070a000000
8f010000070a000000
-
{e=>'UE3',c=>0,a=>4,b=>2,d=>4,f=>2}
140000000413000000
140000000413000000
140000000413000000
140000000413000000
-
{e=>'UE2',c=>3,a=>4,b=>0,d=>0,f=>0}
c40000000002000000
c40000000002000000
c40000000002000000
c40000000002000000
-
{e=>'UE1',c=>0,a=>3,b=>1,d=>0,f=>6}
0b0000000031000000
0b0000000031000000
0b0000000031000000
0b0000000031000000
-
{e=>'UE2',c=>3,a=>1,b=>2,d=>3,f=>5}
d1000000032a000000
d1000000032a000000
d1000000032a000000
d1000000032a000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
};
-
{e=>'UE1',c=>3,a=>2,b=>-3,d=>0,f=>0}
ea0000000001000000
ea0000000001000000
ea0000000001000000
ea0000000001000000
-
{e=>'UE6',c=>-2,a=>7,b=>-2,d=>7,f=>1}
b7010000070e000000
b7010000070e000000
b7010000070e000000
b7010000070e000000
-
{e=>'UE2',c=>-2,a=>5,b=>2,d=>6,f=>5}
95010000062a000000
95010000062a000000
95010000062a000000
95010000062a000000
-
{e=>'UE1',c=>2,a=>1,b=>-1,d=>4,f=>6}
b90000000431000000
b90000000431000000
b90000000431000000
b90000000431000000
-
{e=>'UE1',c=>3,a=>1,b=>-3,d=>3,f=>4}
e90000000321000000
e90000000321000000
e90000000321000000
e90000000321000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
};
-
{e=>'UE6',c=>-2,a=>0,g=>0,b=>3,d=>6,f=>4}
98010000062600000000
98010000062600000000
98010000062600000000
98010000062600000000
-
{e=>'UE4',c=>2,a=>2,g=>2,b=>-4,d=>7,f=>3}
a2000000071c00000002
a2000000071c00000002
a2000000071c00000002
a2000000071c00000002
-
{e=>'UE2',c=>-3,a=>4,g=>6,b=>3,d=>6,f=>7}
5c010000063a00000006
5c010000063a00000006
5c010000063a00000006
5c010000063a00000006
-
{e=>'UE6',c=>-1,a=>7,g=>6,b=>2,d=>7,f=>6}
d7010000073600000006
d7010000073600000006
d7010000073600000006
d7010000073600000006
-
{e=>'UE3',c=>-2,a=>7,g=>2,b=>-3,d=>4,f=>7}
af010000043b00000002
af010000043b00000002
af010000043b00000002
af010000043b00000002
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
};
-
{e=>'UE2',a=>3,d=>3,c=>1,h=>2,b=>-1,g=>0,f=>2}
7b000000031200000010
7b000000031200000010
7b000000031200000010
7b000000031200000010
-
{e=>'UE5',a=>4,d=>6,c=>1,h=>-4,b=>-1,g=>5,f=>4}
7c000000062500000025
7c000000062500000025
7c000000062500000025
7c000000062500000025
-
{e=>'UE0',a=>7,d=>2,c=>3,h=>1,b=>-3,g=>2,f=>1}
ef00000002080000000a
ef00000002080000000a
ef00000002080000000a
ef00000002080000000a
-
{e=>'UE0',a=>1,d=>7,c=>-3,h=>-1,b=>1,g=>3,f=>4}
4901000007200000003b
4901000007200000003b
4901000007200000003b
4901000007200000003b
-
{e=>'UE1',a=>5,d=>3,c=>3,h=>2,b=>-4,g=>2,f=>5}
e5000000032900000012
e5000000032900000012
e5000000032900000012
e5000000032900000012
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
};
-
{e=>'UE2',a=>0,d=>0,c=>-4,h=>1,b=>1,g=>0,f=>7,i=>'SEM2'}
08010000003a0000000806000000
08010000003a0000000806000000
08010000003a0000000806000000
08010000003a0000000806000000
-
{e=>'UE1',a=>1,d=>7,c=>-1,h=>3,b=>2,g=>2,f=>5,i=>'SEM1'}
d101000007290000001a07000000
d101000007290000001a07000000
d101000007290000001a07000000
d101000007290000001a07000000
-
{e=>'UE7',a=>7,d=>3,c=>-4,h=>3,b=>-3,g=>0,f=>5,i=>'SE0'}
2f010000032f0000001800000000
2f010000032f0000001800000000
2f010000032f0000001800000000
2f010000032f0000001800000000
-
{e=>'UE6',a=>6,d=>1,c=>3,h=>0,b=>1,g=>5,f=>5,i=>'SEM2'}
ce000000012e0000000506000000
ce000000012e0000000506000000
ce000000012e0000000506000000
ce000000012e0000000506000000
-
{e=>'UE6',a=>5,d=>4,c=>3,h=>1,b=>3,g=>2,f=>4,i=>'SE1'}
dd00000004260000000a01000000
dd00000004260000000a01000000
dd00000004260000000a01000000
dd00000004260000000a01000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
  char          j;
};
-
{e=>'UE4',a=>6,d=>2,j=>117,c=>2,h=>-4,b=>2,g=>0,f=>5,i=>'SE2'}
96000000022c000000200200000075
96000000022c000000200200000075
96000000022c000000200200000075
96000000022c000000200200000075
-
{e=>'UE1',a=>3,d=>4,j=>126,c=>3,h=>0,b=>-4,g=>2,f=>5,i=>'SEM3'}
e3000000042900000002050000007e
e3000000042900000002050000007e
e3000000042900000002050000007e
e3000000042900000002050000007e
-
{e=>'UE4',a=>4,d=>7,j=>-36,c=>1,h=>-4,b=>-3,g=>7,f=>2,i=>'SEM2'}
6c00000007140000002706000000dc
6c00000007140000002706000000dc
6c00000007140000002706000000dc
6c00000007140000002706000000dc
-
{e=>'UE5',a=>1,d=>1,j=>61,c=>-3,h=>-3,b=>-4,g=>4,f=>6,i=>'SEM1'}
6101000001350000002c070000003d
6101000001350000002c070000003d
6101000001350000002c070000003d
6101000001350000002c070000003d
-
{e=>'UE6',a=>3,d=>1,j=>-91,c=>1,h=>-1,b=>-1,g=>6,f=>1,i=>'SEM4'}
7b000000010e0000003e04000000a5
7b000000010e0000003e04000000a5
7b000000010e0000003e04000000a5
7b000000010e0000003e04000000a5
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
  char          j;
  unsigned char k:3;
};
-
{e=>'UE4',a=>1,d=>0,j=>-29,c=>-3,k=>3,h=>3,b=>-1,g=>1,f=>7,i=>'SE2'}
79010000003c0000001902000000e303
79010000003c0000001902000000e303
79010000003c0000001902000000e303
79010000003c0000001902000000e303
-
{e=>'UE7',a=>0,d=>6,j=>9,c=>1,k=>7,h=>2,b=>-4,g=>3,f=>4,i=>'SEM4'}
60000000062700000013040000000907
60000000062700000013040000000907
60000000062700000013040000000907
60000000062700000013040000000907
-
{e=>'UE2',a=>0,d=>2,j=>101,c=>2,k=>1,h=>-4,b=>1,g=>7,f=>1,i=>'SEM2'}
88000000020a00000027060000006501
88000000020a00000027060000006501
88000000020a00000027060000006501
88000000020a00000027060000006501
-
{e=>'UE3',a=>0,d=>6,j=>74,c=>1,k=>1,h=>-1,b=>1,g=>4,f=>2,i=>'SE0'}
4800000006130000003c000000004a01
4800000006130000003c000000004a01
4800000006130000003c000000004a01
4800000006130000003c000000004a01
-
{e=>'UE1',a=>4,d=>7,j=>-119,c=>-3,k=>4,h=>1,b=>2,g=>7,f=>4,i=>'SEM4'}
5401000007210000000f040000008904
5401000007210000000f040000008904
5401000007210000000f040000008904
5401000007210000000f040000008904
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
};
-
{e=>'UE0',a=>5,d=>7,j=>-122,l=>-3,c=>-4,k=>2,h=>1,b=>-1,g=>4,f=>3,i=>'SEM3'}
3d01000007180000000c05000000862a
3d01000007180000000c05000000862a
3d01000007180000000c05000000862a
3d01000007180000000c05000000862a
-
{e=>'UE0',a=>1,d=>3,j=>-34,l=>-4,c=>-3,k=>6,h=>-3,b=>-2,g=>1,f=>7,i=>'SEM1'}
7101000003380000002907000000de26
7101000003380000002907000000de26
7101000003380000002907000000de26
7101000003380000002907000000de26
-
{e=>'UE1',a=>1,d=>0,j=>86,l=>-4,c=>-3,k=>3,h=>2,b=>1,g=>0,f=>0,i=>'SEM3'}
49010000000100000010050000005623
49010000000100000010050000005623
49010000000100000010050000005623
49010000000100000010050000005623
-
{e=>'UE1',a=>2,d=>1,j=>-57,l=>-1,c=>3,k=>5,h=>1,b=>-2,g=>7,f=>0,i=>'SE3'}
f200000001010000000f03000000c73d
f200000001010000000f03000000c73d
f200000001010000000f03000000c73d
f200000001010000000f03000000c73d
-
{e=>'UE7',a=>3,d=>1,j=>111,l=>-4,c=>-4,k=>6,h=>-3,b=>-2,g=>4,f=>3,i=>'SEM2'}
33010000011f0000002c060000006f26
33010000011f0000002c060000006f26
33010000011f0000002c060000006f26
33010000011f0000002c060000006f26
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
  unsigned int  m:3;
};
-
{e=>'UE3',a=>5,m=>4,d=>5,j=>-36,l=>2,c=>0,k=>4,h=>0,b=>-3,g=>5,f=>0,i=>'SEM1'}
2d00000005030000000507000000dc1404000000
2d00000005030000000507000000dc1404000000
2d00000005030000000507000000dc1404000000
2d00000005030000000507000000dc1404000000
-
{e=>'UE7',a=>5,m=>0,d=>6,j=>-48,l=>3,c=>1,k=>3,h=>2,b=>-3,g=>2,f=>0,i=>'SE1'}
6d00000006070000001201000000d01b00000000
6d00000006070000001201000000d01b00000000
6d00000006070000001201000000d01b00000000
6d00000006070000001201000000d01b00000000
-
{e=>'UE5',a=>6,m=>5,d=>5,j=>-112,l=>1,c=>-4,k=>5,h=>0,b=>2,g=>1,f=>3,i=>'SEM2'}
16010000051d0000000106000000900d05000000
16010000051d0000000106000000900d05000000
16010000051d0000000106000000900d05000000
16010000051d0000000106000000900d05000000
-
{e=>'UE3',a=>5,m=>5,d=>5,j=>-44,l=>-2,c=>-3,k=>0,h=>1,b=>-1,g=>4,f=>3,i=>'SE0'}
7d010000051b0000000c00000000d43005000000
7d010000051b0000000c00000000d43005000000
7d010000051b0000000c00000000d43005000000
7d010000051b0000000c00000000d43005000000
-
{e=>'UE1',a=>5,m=>1,d=>7,j=>-106,l=>0,c=>-2,k=>7,h=>-4,b=>2,g=>0,f=>0,i=>'SE2'}
9501000007010000002002000000960701000000
9501000007010000002002000000960701000000
9501000007010000002002000000960701000000
9501000007010000002002000000960701000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
  unsigned int  m:3;
  unsigned char n;
};
-
{e=>'UE2',n=>245,a=>6,m=>3,d=>5,j=>21,l=>-3,c=>3,k=>3,h=>-2,b=>1,g=>3,f=>4,i=>'SE2'}
ce00000005220000003302000000152b03000000f5
ce00000005220000003302000000152b03000000f5
ce00000005220000003302000000152b03000000f5
ce00000005220000003302000000152b03000000f5
-
{e=>'UE4',n=>39,a=>4,m=>1,d=>1,j=>-106,l=>0,c=>-3,k=>5,h=>2,b=>1,g=>6,f=>2,i=>'SEM1'}
4c0100000114000000160700000096050100000027
4c0100000114000000160700000096050100000027
4c0100000114000000160700000096050100000027
4c0100000114000000160700000096050100000027
-
{e=>'UE2',n=>222,a=>0,m=>0,d=>4,j=>23,l=>0,c=>-2,k=>3,h=>3,b=>-1,g=>2,f=>1,i=>'SE1'}
b8010000040a0000001a01000000170300000000de
b8010000040a0000001a01000000170300000000de
b8010000040a0000001a01000000170300000000de
b8010000040a0000001a01000000170300000000de
-
{e=>'UE1',n=>14,a=>6,m=>6,d=>0,j=>-82,l=>3,c=>-4,k=>6,h=>-2,b=>-4,g=>4,f=>7,i=>'SEM4'}
2601000000390000003404000000ae1e060000000e
2601000000390000003404000000ae1e060000000e
2601000000390000003404000000ae1e060000000e
2601000000390000003404000000ae1e060000000e
-
{e=>'UE5',n=>1,a=>2,m=>5,d=>2,j=>-12,l=>1,c=>-3,k=>4,h=>-3,b=>1,g=>0,f=>7,i=>'SEM3'}
4a010000023d0000002805000000f40c0500000001
4a010000023d0000002805000000f40c0500000001
4a010000023d0000002805000000f40c0500000001
4a010000023d0000002805000000f40c0500000001
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
};
-
{a=>13,b=>3}
0d03000000
0d03000000
0d03000000
0d03000000
-
{a=>-11,b=>1}
f501000000
f501000000
f501000000
f501000000
-
{a=>5,b=>2}
0502000000
0502000000
0502000000
0502000000
-
{a=>-65,b=>1}
bf01000000
bf01000000
bf01000000
bf01000000
-
{a=>51,b=>3}
3303000000
3303000000
3303000000
3303000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>3,a=>-27,b=>4}
e51c000000
e51c000000
e51c000000
e51c000000
-
{c=>-2,a=>123,b=>4}
7b34000000
7b34000000
7b34000000
7b34000000
-
{c=>-4,a=>-38,b=>5}
da25000000
da25000000
da25000000
da25000000
-
{c=>-3,a=>4,b=>0}
0428000000
0428000000
0428000000
0428000000
-
{c=>0,a=>-104,b=>5}
9805000000
9805000000
9805000000
9805000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-2,a=>-116,b=>0,d=>-2}
8cb0010000
8cb0010000
8cb0010000
8cb0010000
-
{c=>-3,a=>-33,b=>2,d=>-3}
df6a010000
df6a010000
df6a010000
df6a010000
-
{c=>-2,a=>-99,b=>7,d=>2}
9db7000000
9db7000000
9db7000000
9db7000000
-
{c=>-4,a=>103,b=>5,d=>-3}
6765010000
6765010000
6765010000
6765010000
-
{c=>1,a=>111,b=>5,d=>0}
6f0d000000
6f0d000000
6f0d000000
6f0d000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>1,c=>0,a=>17,b=>1,d=>-4}
110101000001
110101000001
110101000001
110101000001
-
{e=>4,c=>-2,a=>-99,b=>6,d=>-1}
9df601000004
9df601000004
9df601000004
9df601000004
-
{e=>3,c=>-1,a=>-98,b=>4,d=>-1}
9efc01000003
9efc01000003
9efc01000003
9efc01000003
-
{e=>1,c=>-2,a=>-9,b=>2,d=>3}
f7f200000001
f7f200000001
f7f200000001
f7f200000001
-
{e=>5,c=>0,a=>-8,b=>0,d=>0}
f80000000005
f80000000005
f80000000005
f80000000005
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
};
-
{e=>5,c=>-1,a=>-128,b=>0,d=>2,f=>'UE2'}
80b80000000502000000
80b80000000502000000
80b80000000502000000
80b80000000502000000
-
{e=>1,c=>-1,a=>19,b=>6,d=>3,f=>'UE0'}
13fe0000000100000000
13fe0000000100000000
13fe0000000100000000
13fe0000000100000000
-
{e=>3,c=>1,a=>-34,b=>1,d=>-3,f=>'UE2'}
de490100000302000000
de490100000302000000
de490100000302000000
de490100000302000000
-
{e=>3,c=>3,a=>-85,b=>7,d=>1,f=>'UE4'}
ab5f0000000304000000
ab5f0000000304000000
ab5f0000000304000000
ab5f0000000304000000
-
{e=>3,c=>-3,a=>14,b=>3,d=>1,f=>'UE7'}
0e6b0000000307000000
0e6b0000000307000000
0e6b0000000307000000
0e6b0000000307000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
};
-
{e=>3,c=>-2,a=>-81,g=>5,b=>0,d=>3,f=>'UE1'}
aff00000000329000000
aff00000000329000000
aff00000000329000000
aff00000000329000000
-
{e=>5,c=>3,a=>-48,g=>4,b=>5,d=>-3,f=>'UE0'}
d05d0100000520000000
d05d0100000520000000
d05d0100000520000000
d05d0100000520000000
-
{e=>6,c=>1,a=>72,g=>3,b=>3,d=>-3,f=>'UE4'}
484b010000061c000000
484b010000061c000000
484b010000061c000000
484b010000061c000000
-
{e=>5,c=>-4,a=>-73,g=>6,b=>4,d=>-1,f=>'UE3'}
b7e40100000533000000
b7e40100000533000000
b7e40100000533000000
b7e40100000533000000
-
{e=>4,c=>-4,a=>33,g=>5,b=>5,d=>-3,f=>'UE6'}
2165010000042e000000
2165010000042e000000
2165010000042e000000
2165010000042e000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>4,c=>2,a=>15,g=>5,b=>7,d=>1,f=>'UE1'}
0f570000000429000000
0f570000000429000000
0f570000000429000000
0f570000000429000000
-
{e=>6,c=>-2,a=>117,g=>0,b=>0,d=>-2,f=>'UE3'}
75b00100000603000000
75b00100000603000000
75b00100000603000000
75b00100000603000000
-
{e=>3,c=>2,a=>70,g=>7,b=>0,d=>2,f=>'UE0'}
46900000000338000000
46900000000338000000
46900000000338000000
46900000000338000000
-
{e=>7,c=>-3,a=>95,g=>4,b=>2,d=>-2,f=>'UE7'}
5faa0100000727000000
5faa0100000727000000
5faa0100000727000000
5faa0100000727000000
-
{e=>3,c=>0,a=>42,g=>4,b=>7,d=>2,f=>'UE4'}
2a870000000324000000
2a870000000324000000
2a870000000324000000
2a870000000324000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>5,a=>-95,d=>0,c=>-2,h=>7,b=>4,g=>4,f=>'UE1'}
a134000000052100000007
a134000000052100000007
a134000000052100000007
a134000000052100000007
-
{e=>0,a=>79,d=>3,c=>3,h=>4,b=>2,g=>0,f=>'UE4'}
4fda000000000400000004
4fda000000000400000004
4fda000000000400000004
4fda000000000400000004
-
{e=>4,a=>23,d=>0,c=>3,h=>5,b=>5,g=>0,f=>'UE4'}
171d000000040400000005
171d000000040400000005
171d000000040400000005
171d000000040400000005
-
{e=>5,a=>-48,d=>2,c=>1,h=>4,b=>4,g=>4,f=>'UE1'}
d08c000000052100000004
d08c000000052100000004
d08c000000052100000004
d08c000000052100000004
-
{e=>1,a=>-57,d=>3,c=>1,h=>5,b=>0,g=>0,f=>'UE3'}
c7c8000000010300000005
c7c8000000010300000005
c7c8000000010300000005
c7c8000000010300000005
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>5,a=>-24,d=>-4,c=>3,h=>2,b=>2,g=>3,f=>'UE2',i=>-2}
e81a010000051a00000032
e81a010000051a00000032
e81a010000051a00000032
e81a010000051a00000032
-
{e=>7,a=>25,d=>0,c=>3,h=>3,b=>2,g=>3,f=>'UE0',i=>0}
191a000000071800000003
191a000000071800000003
191a000000071800000003
191a000000071800000003
-
{e=>3,a=>31,d=>2,c=>-1,h=>1,b=>1,g=>4,f=>'UE5',i=>1}
1fb9000000032500000009
1fb9000000032500000009
1fb9000000032500000009
1fb9000000032500000009
-
{e=>4,a=>21,d=>-2,c=>1,h=>4,b=>6,g=>6,f=>'UE4',i=>-2}
158e010000043400000034
158e010000043400000034
158e010000043400000034
158e010000043400000034
-
{e=>6,a=>106,d=>-1,c=>1,h=>0,b=>0,g=>4,f=>'UE5',i=>-2}
6ac8010000062500000030
6ac8010000062500000030
6ac8010000062500000030
6ac8010000062500000030
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
};
-
{e=>5,a=>-92,d=>-4,j=>'SEM4',c=>1,h=>0,b=>7,g=>4,f=>'UE4',i=>0}
a40f01000005240000000004000000
a40f01000005240000000004000000
a40f01000005240000000004000000
a40f01000005240000000004000000
-
{e=>6,a=>89,d=>1,j=>'SEM4',c=>0,h=>5,b=>5,g=>1,f=>'UE7',i=>2}
5945000000060f0000001504000000
5945000000060f0000001504000000
5945000000060f0000001504000000
5945000000060f0000001504000000
-
{e=>2,a=>15,d=>0,j=>'SEM2',c=>1,h=>1,b=>4,g=>3,f=>'UE7',i=>0}
0f0c000000021f0000000106000000
0f0c000000021f0000000106000000
0f0c000000021f0000000106000000
0f0c000000021f0000000106000000
-
{e=>3,a=>-2,d=>3,j=>'SEM2',c=>1,h=>1,b=>3,g=>4,f=>'UE7',i=>1}
fecb00000003270000000906000000
fecb00000003270000000906000000
fecb00000003270000000906000000
fecb00000003270000000906000000
-
{e=>5,a=>113,d=>0,j=>'SE2',c=>3,h=>5,b=>4,g=>5,f=>'UE2',i=>3}
711c000000052a0000001d02000000
711c000000052a0000001d02000000
711c000000052a0000001d02000000
711c000000052a0000001d02000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
};
-
{e=>4,a=>-108,d=>-2,j=>'SE0',c=>3,k=>33,h=>1,b=>5,g=>1,f=>'UE4',i=>-2}
949d010000040c000000310000000021
949d010000040c000000310000000021
949d010000040c000000310000000021
949d010000040c000000310000000021
-
{e=>5,a=>-119,d=>-4,j=>'SE1',c=>-2,k=>-4,h=>2,b=>0,g=>3,f=>'UE2',i=>-4}
8930010000051a0000002201000000fc
8930010000051a0000002201000000fc
8930010000051a0000002201000000fc
8930010000051a0000002201000000fc
-
{e=>7,a=>-38,d=>-4,j=>'SEM1',c=>1,k=>-5,h=>1,b=>7,g=>7,f=>'UE2',i=>1}
da0f010000073a0000000907000000fb
da0f010000073a0000000907000000fb
da0f010000073a0000000907000000fb
da0f010000073a0000000907000000fb
-
{e=>4,a=>-11,d=>0,j=>'SEM3',c=>3,k=>-84,h=>3,b=>6,g=>3,f=>'UE3',i=>2}
f51e000000041b0000001305000000ac
f51e000000041b0000001305000000ac
f51e000000041b0000001305000000ac
f51e000000041b0000001305000000ac
-
{e=>0,a=>27,d=>2,j=>'SE2',c=>1,k=>-54,h=>0,b=>4,g=>1,f=>'UE4',i=>3}
1b8c000000000c0000001802000000ca
1b8c000000000c0000001802000000ca
1b8c000000000c0000001802000000ca
1b8c000000000c0000001802000000ca
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>4,a=>-97,d=>3,j=>'SEM4',l=>0,c=>-2,k=>122,h=>3,b=>1,g=>1,f=>'UE3',i=>1}
9ff1000000040b0000000b040000007a00
9ff1000000040b0000000b040000007a00
9ff1000000040b0000000b040000007a00
9ff1000000040b0000000b040000007a00
-
{e=>4,a=>-122,d=>3,j=>'SEM2',l=>1,c=>3,k=>50,h=>0,b=>4,g=>5,f=>'UE0',i=>-3}
86dc000000042800000028060000003201
86dc000000042800000028060000003201
86dc000000042800000028060000003201
86dc000000042800000028060000003201
-
{e=>1,a=>-106,d=>0,j=>'SEM1',l=>1,c=>3,k=>-92,h=>5,b=>3,g=>7,f=>'UE1',i=>1}
961b00000001390000000d07000000a401
961b00000001390000000d07000000a401
961b00000001390000000d07000000a401
961b00000001390000000d07000000a401
-
{e=>5,a=>-50,d=>0,j=>'SE1',l=>0,c=>-2,k=>62,h=>7,b=>3,g=>6,f=>'UE5',i=>0}
ce33000000053500000007010000003e00
ce33000000053500000007010000003e00
ce33000000053500000007010000003e00
ce33000000053500000007010000003e00
-
{e=>5,a=>100,d=>0,j=>'SE3',l=>3,c=>-4,k=>67,h=>1,b=>1,g=>7,f=>'UE3',i=>1}
6421000000053b00000009030000004303
6421000000053b00000009030000004303
6421000000053b00000009030000004303
6421000000053b00000009030000004303
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>3,a=>18,m=>-4,d=>-2,j=>'SE0',l=>1,c=>-3,k=>-93,h=>5,b=>2,g=>6,f=>'UE1',i=>3}
12aa01000003310000001d00000000a321
12aa01000003310000001d00000000a321
12aa01000003310000001d00000000a321
12aa01000003310000001d00000000a321
-
{e=>3,a=>-79,m=>-4,d=>0,j=>'SEM1',l=>5,c=>3,k=>20,h=>2,b=>5,g=>5,f=>'UE2',i=>-3}
b11d000000032a0000002a070000001425
b11d000000032a0000002a070000001425
b11d000000032a0000002a070000001425
b11d000000032a0000002a070000001425
-
{e=>1,a=>16,m=>-1,d=>2,j=>'SEM3',l=>5,c=>1,k=>116,h=>3,b=>7,g=>5,f=>'UE1',i=>-3}
108f00000001290000002b05000000743d
108f00000001290000002b05000000743d
108f00000001290000002b05000000743d
108f00000001290000002b05000000743d
-
{e=>3,a=>33,m=>-2,d=>0,j=>'SE0',l=>4,c=>3,k=>98,h=>3,b=>1,g=>6,f=>'UE6',i=>0}
2119000000033600000003000000006234
2119000000033600000003000000006234
2119000000033600000003000000006234
2119000000033600000003000000006234
-
{e=>7,a=>-14,m=>-4,d=>-2,j=>'SE2',l=>7,c=>1,k=>-62,h=>0,b=>2,g=>0,f=>'UE2',i=>-1}
f28a01000007020000003802000000c227
f28a01000007020000003802000000c227
f28a01000007020000003802000000c227
f28a01000007020000003802000000c227
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>2,n=>0,a=>-27,m=>-4,d=>-3,j=>'SEM3',l=>3,c=>3,k=>23,h=>3,b=>6,g=>7,f=>'UE4',i=>-3}
e55e010000023c0000002b05000000172300000000
e55e010000023c0000002b05000000172300000000
e55e010000023c0000002b05000000172300000000
e55e010000023c0000002b05000000172300000000
-
{e=>4,n=>7,a=>-105,m=>-4,d=>-4,j=>'SE0',l=>6,c=>2,k=>99,h=>3,b=>1,g=>6,f=>'UE0',i=>2}
971101000004300000001300000000632607000000
971101000004300000001300000000632607000000
971101000004300000001300000000632607000000
971101000004300000001300000000632607000000
-
{e=>4,n=>4,a=>96,m=>-3,d=>-3,j=>'SEM2',l=>4,c=>-1,k=>7,h=>7,b=>3,g=>5,f=>'UE3',i=>1}
607b010000042b0000000f06000000072c04000000
607b010000042b0000000f06000000072c04000000
607b010000042b0000000f06000000072c04000000
607b010000042b0000000f06000000072c04000000
-
{e=>0,n=>4,a=>-116,m=>-1,d=>-4,j=>'SE1',l=>1,c=>0,k=>-79,h=>4,b=>7,g=>6,f=>'UE4',i=>-2}
8c0701000000340000003401000000b13904000000
8c0701000000340000003401000000b13904000000
8c0701000000340000003401000000b13904000000
8c0701000000340000003401000000b13904000000
-
{e=>3,n=>0,a=>75,m=>0,d=>1,j=>'SEM4',l=>3,c=>-1,k=>-22,h=>4,b=>7,g=>7,f=>'UE1',i=>-2}
4b7f00000003390000003404000000ea0300000000
4b7f00000003390000003404000000ea0300000000
4b7f00000003390000003404000000ea0300000000
4b7f00000003390000003404000000ea0300000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>7,n=>0,a=>-125,m=>1,d=>-1,j=>'SE1',l=>4,c=>3,k=>75,h=>2,b=>4,g=>2,f=>'UE4',o=>207,i=>1}
83dc01000007140000000a010000004b0c00000000cf
83dc01000007140000000a010000004b0c00000000cf
83dc01000007140000000a010000004b0c00000000cf
83dc01000007140000000a010000004b0c00000000cf
-
{e=>5,n=>5,a=>123,m=>2,d=>2,j=>'SEM4',l=>0,c=>-1,k=>-99,h=>5,b=>0,g=>6,f=>'UE2',o=>139,i=>0}
7bb8000000053200000005040000009d10050000008b
7bb8000000053200000005040000009d10050000008b
7bb8000000053200000005040000009d10050000008b
7bb8000000053200000005040000009d10050000008b
-
{e=>4,n=>3,a=>11,m=>-1,d=>-1,j=>'SE1',l=>7,c=>-1,k=>-112,h=>3,b=>4,g=>6,f=>'UE7',o=>200,i=>-2}
0bfc01000004370000003301000000903f03000000c8
0bfc01000004370000003301000000903f03000000c8
0bfc01000004370000003301000000903f03000000c8
0bfc01000004370000003301000000903f03000000c8
-
{e=>3,n=>1,a=>-24,m=>1,d=>1,j=>'SE3',l=>4,c=>1,k=>14,h=>1,b=>5,g=>4,f=>'UE3',o=>226,i=>1}
e84d000000032300000009030000000e0c01000000e2
e84d000000032300000009030000000e0c01000000e2
e84d000000032300000009030000000e0c01000000e2
e84d000000032300000009030000000e0c01000000e2
-
{e=>1,n=>3,a=>-40,m=>-4,d=>3,j=>'SE0',l=>2,c=>3,k=>-119,h=>2,b=>6,g=>1,f=>'UE3',o=>233,i=>0}
d8de000000010b0000000200000000892203000000e9
d8de000000010b0000000200000000892203000000e9
d8de000000010b0000000200000000892203000000e9
d8de000000010b0000000200000000892203000000e9
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
};
-
{a=>66,b=>2}
420002000000
420002000000
420002000000
420002000000
-
{a=>47,b=>3}
2f0003000000
2f0003000000
2f0003000000
2f0003000000
-
{a=>34,b=>7}
220007000000
220007000000
220007000000
220007000000
-
{a=>-104,b=>2}
98ff02000000
98ff02000000
98ff02000000
98ff02000000
-
{a=>43,b=>2}
2b0002000000
2b0002000000
2b0002000000
2b0002000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>1,a=>3,b=>3}
03000b000000
03000b000000
03000b000000
03000b000000
-
{c=>-2,a=>65,b=>7}
410037000000
410037000000
410037000000
410037000000
-
{c=>-2,a=>41,b=>1}
290031000000
290031000000
290031000000
290031000000
-
{c=>2,a=>111,b=>5}
6f0015000000
6f0015000000
6f0015000000
6f0015000000
-
{c=>-2,a=>11,b=>1}
0b0031000000
0b0031000000
0b0031000000
0b0031000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>1,a=>121,b=>6,d=>-2}
79008e010000
79008e010000
79008e010000
79008e010000
-
{c=>2,a=>-66,b=>7,d=>-3}
beff57010000
beff57010000
beff57010000
beff57010000
-
{c=>3,a=>-37,b=>3,d=>1}
dbff5b000000
dbff5b000000
dbff5b000000
dbff5b000000
-
{c=>-1,a=>-22,b=>6,d=>-3}
eaff7e010000
eaff7e010000
eaff7e010000
eaff7e010000
-
{c=>-1,a=>-107,b=>1,d=>-2}
95ffb9010000
95ffb9010000
95ffb9010000
95ffb9010000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>2,c=>3,a=>113,b=>7,d=>2}
71009f00000002
71009f00000002
71009f00000002
71009f00000002
-
{e=>3,c=>2,a=>104,b=>0,d=>-2}
68009001000003
68009001000003
68009001000003
68009001000003
-
{e=>4,c=>-4,a=>91,b=>2,d=>-1}
5b00e201000004
5b00e201000004
5b00e201000004
5b00e201000004
-
{e=>1,c=>0,a=>-67,b=>3,d=>0}
bdff0300000001
bdff0300000001
bdff0300000001
bdff0300000001
-
{e=>6,c=>-2,a=>-125,b=>5,d=>-2}
83ffb501000006
83ffb501000006
83ffb501000006
83ffb501000006
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
};
-
{e=>4,c=>-4,a=>63,b=>1,d=>-3,f=>'UE7'}
3f00610100000407000000
3f00610100000407000000
3f00610100000407000000
3f00610100000407000000
-
{e=>2,c=>2,a=>20,b=>1,d=>-4,f=>'UE1'}
1400110100000201000000
1400110100000201000000
1400110100000201000000
1400110100000201000000
-
{e=>6,c=>-3,a=>-51,b=>5,d=>1,f=>'UE1'}
cdff6d0000000601000000
cdff6d0000000601000000
cdff6d0000000601000000
cdff6d0000000601000000
-
{e=>6,c=>0,a=>82,b=>2,d=>0,f=>'UE0'}
5200020000000600000000
5200020000000600000000
5200020000000600000000
5200020000000600000000
-
{e=>5,c=>-4,a=>32,b=>4,d=>0,f=>'UE6'}
2000240000000506000000
2000240000000506000000
2000240000000506000000
2000240000000506000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
};
-
{e=>0,c=>-4,a=>-51,g=>5,b=>5,d=>1,f=>'UE0'}
cdff650000000028000000
cdff650000000028000000
cdff650000000028000000
cdff650000000028000000
-
{e=>3,c=>-3,a=>51,g=>5,b=>3,d=>1,f=>'UE7'}
33006b000000032f000000
33006b000000032f000000
33006b000000032f000000
33006b000000032f000000
-
{e=>2,c=>-3,a=>-58,g=>5,b=>3,d=>3,f=>'UE3'}
c6ffeb000000022b000000
c6ffeb000000022b000000
c6ffeb000000022b000000
c6ffeb000000022b000000
-
{e=>5,c=>1,a=>-74,g=>7,b=>3,d=>-2,f=>'UE3'}
b6ff8b010000053b000000
b6ff8b010000053b000000
b6ff8b010000053b000000
b6ff8b010000053b000000
-
{e=>3,c=>1,a=>90,g=>5,b=>1,d=>3,f=>'UE6'}
5a00c9000000032e000000
5a00c9000000032e000000
5a00c9000000032e000000
5a00c9000000032e000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>7,c=>-4,a=>20,g=>5,b=>1,d=>2,f=>'UE0'}
1400a10000000728000000
1400a10000000728000000
1400a10000000728000000
1400a10000000728000000
-
{e=>3,c=>-3,a=>78,g=>5,b=>4,d=>2,f=>'UE5'}
4e00ac000000032d000000
4e00ac000000032d000000
4e00ac000000032d000000
4e00ac000000032d000000
-
{e=>6,c=>3,a=>-109,g=>0,b=>6,d=>2,f=>'UE4'}
93ff9e0000000604000000
93ff9e0000000604000000
93ff9e0000000604000000
93ff9e0000000604000000
-
{e=>5,c=>0,a=>92,g=>2,b=>4,d=>1,f=>'UE1'}
5c00440000000511000000
5c00440000000511000000
5c00440000000511000000
5c00440000000511000000
-
{e=>6,c=>2,a=>-108,g=>4,b=>7,d=>-1,f=>'UE4'}
94ffd70100000624000000
94ffd70100000624000000
94ffd70100000624000000
94ffd70100000624000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>3,a=>8,d=>-1,c=>-4,h=>6,b=>1,g=>5,f=>'UE6'}
0800e1010000032e00000006
0800e1010000032e00000006
0800e1010000032e00000006
0800e1010000032e00000006
-
{e=>4,a=>118,d=>1,c=>0,h=>2,b=>3,g=>1,f=>'UE6'}
760043000000040e00000002
760043000000040e00000002
760043000000040e00000002
760043000000040e00000002
-
{e=>7,a=>27,d=>-4,c=>2,h=>1,b=>4,g=>3,f=>'UE2'}
1b0014010000071a00000001
1b0014010000071a00000001
1b0014010000071a00000001
1b0014010000071a00000001
-
{e=>0,a=>91,d=>-2,c=>3,h=>3,b=>5,g=>1,f=>'UE6'}
5b009d010000000e00000003
5b009d010000000e00000003
5b009d010000000e00000003
5b009d010000000e00000003
-
{e=>2,a=>70,d=>-3,c=>1,h=>6,b=>6,g=>5,f=>'UE4'}
46004e010000022c00000006
46004e010000022c00000006
46004e010000022c00000006
46004e010000022c00000006
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>2,a=>-26,d=>1,c=>-1,h=>0,b=>3,g=>0,f=>'UE4',i=>-4}
e6ff7b000000020400000020
e6ff7b000000020400000020
e6ff7b000000020400000020
e6ff7b000000020400000020
-
{e=>0,a=>70,d=>3,c=>0,h=>3,b=>0,g=>5,f=>'UE0',i=>1}
4600c000000000280000000b
4600c000000000280000000b
4600c000000000280000000b
4600c000000000280000000b
-
{e=>1,a=>17,d=>3,c=>-4,h=>3,b=>1,g=>1,f=>'UE4',i=>-1}
1100e1000000010c0000003b
1100e1000000010c0000003b
1100e1000000010c0000003b
1100e1000000010c0000003b
-
{e=>2,a=>39,d=>1,c=>1,h=>0,b=>1,g=>0,f=>'UE1',i=>0}
270049000000020100000000
270049000000020100000000
270049000000020100000000
270049000000020100000000
-
{e=>6,a=>-65,d=>-2,c=>-1,h=>2,b=>6,g=>7,f=>'UE1',i=>-4}
bfffbe010000063900000022
bfffbe010000063900000022
bfffbe010000063900000022
bfffbe010000063900000022
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
};
-
{e=>7,a=>118,d=>1,j=>'SE2',c=>1,h=>6,b=>3,g=>5,f=>'UE4',i=>2}
76004b000000072c0000001602000000
76004b000000072c0000001602000000
76004b000000072c0000001602000000
76004b000000072c0000001602000000
-
{e=>0,a=>32,d=>2,j=>'SE3',c=>2,h=>5,b=>3,g=>7,f=>'UE1',i=>-4}
20009300000000390000002503000000
20009300000000390000002503000000
20009300000000390000002503000000
20009300000000390000002503000000
-
{e=>2,a=>88,d=>0,j=>'SEM3',c=>1,h=>5,b=>2,g=>2,f=>'UE0',i=>1}
58000a00000002100000000d05000000
58000a00000002100000000d05000000
58000a00000002100000000d05000000
58000a00000002100000000d05000000
-
{e=>7,a=>105,d=>-3,j=>'SE3',c=>0,h=>0,b=>3,g=>2,f=>'UE0',i=>-2}
69004301000007100000003003000000
69004301000007100000003003000000
69004301000007100000003003000000
69004301000007100000003003000000
-
{e=>4,a=>-56,d=>-2,j=>'SE0',c=>-3,h=>4,b=>1,g=>4,f=>'UE4',i=>2}
c8ffa901000004240000001400000000
c8ffa901000004240000001400000000
c8ffa901000004240000001400000000
c8ffa901000004240000001400000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
};
-
{e=>0,a=>-104,d=>-4,j=>'SE0',c=>-2,k=>8,h=>1,b=>4,g=>6,f=>'UE1',i=>1}
98ff340100000031000000090000000008
98ff340100000031000000090000000008
98ff340100000031000000090000000008
98ff340100000031000000090000000008
-
{e=>2,a=>-127,d=>-1,j=>'SE0',c=>0,k=>-15,h=>5,b=>7,g=>0,f=>'UE1',i=>-1}
81ffc701000002010000003d00000000f1
81ffc701000002010000003d00000000f1
81ffc701000002010000003d00000000f1
81ffc701000002010000003d00000000f1
-
{e=>0,a=>47,d=>2,j=>'SEM2',c=>-4,k=>-44,h=>0,b=>7,g=>0,f=>'UE3',i=>-3}
2f00a700000000030000002806000000d4
2f00a700000000030000002806000000d4
2f00a700000000030000002806000000d4
2f00a700000000030000002806000000d4
-
{e=>7,a=>116,d=>-1,j=>'SEM3',c=>-3,k=>-14,h=>3,b=>5,g=>1,f=>'UE7',i=>2}
7400ed010000070f0000001305000000f2
7400ed010000070f0000001305000000f2
7400ed010000070f0000001305000000f2
7400ed010000070f0000001305000000f2
-
{e=>7,a=>45,d=>-1,j=>'SE3',c=>-4,k=>65,h=>3,b=>2,g=>6,f=>'UE0',i=>1}
2d00e201000007300000000b0300000041
2d00e201000007300000000b0300000041
2d00e201000007300000000b0300000041
2d00e201000007300000000b0300000041
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>1,a=>-38,d=>0,j=>'SEM4',l=>1,c=>3,k=>122,h=>0,b=>3,g=>6,f=>'UE0',i=>-4}
daff1b000000013000000020040000007a01
daff1b000000013000000020040000007a01
daff1b000000013000000020040000007a01
daff1b000000013000000020040000007a01
-
{e=>6,a=>-120,d=>-2,j=>'SE0',l=>0,c=>2,k=>-45,h=>4,b=>5,g=>6,f=>'UE7',i=>-1}
88ff9501000006370000003c00000000d300
88ff9501000006370000003c00000000d300
88ff9501000006370000003c00000000d300
88ff9501000006370000003c00000000d300
-
{e=>2,a=>115,d=>3,j=>'SEM4',l=>2,c=>-1,k=>-24,h=>4,b=>3,g=>1,f=>'UE2',i=>-3}
7300fb000000020a0000002c04000000e802
7300fb000000020a0000002c04000000e802
7300fb000000020a0000002c04000000e802
7300fb000000020a0000002c04000000e802
-
{e=>2,a=>-120,d=>2,j=>'SEM3',l=>5,c=>-3,k=>-38,h=>3,b=>5,g=>5,f=>'UE0',i=>0}
88ffad00000002280000000305000000da05
88ffad00000002280000000305000000da05
88ffad00000002280000000305000000da05
88ffad00000002280000000305000000da05
-
{e=>1,a=>-3,d=>3,j=>'SEM4',l=>6,c=>3,k=>-72,h=>4,b=>1,g=>3,f=>'UE4',i=>-3}
fdffd9000000011c0000002c04000000b806
fdffd9000000011c0000002c04000000b806
fdffd9000000011c0000002c04000000b806
fdffd9000000011c0000002c04000000b806
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>0,a=>-115,m=>-1,d=>1,j=>'SE1',l=>5,c=>3,k=>34,h=>4,b=>3,g=>5,f=>'UE3',i=>-1}
8dff5b000000002b0000003c01000000223d
8dff5b000000002b0000003c01000000223d
8dff5b000000002b0000003c01000000223d
8dff5b000000002b0000003c01000000223d
-
{e=>7,a=>101,m=>-3,d=>2,j=>'SE2',l=>7,c=>2,k=>33,h=>5,b=>4,g=>7,f=>'UE5',i=>1}
650094000000073d0000000d02000000212f
650094000000073d0000000d02000000212f
650094000000073d0000000d02000000212f
650094000000073d0000000d02000000212f
-
{e=>4,a=>75,m=>-2,d=>-1,j=>'SE0',l=>6,c=>-4,k=>-42,h=>0,b=>5,g=>5,f=>'UE2',i=>-1}
4b00e5010000042a0000003800000000d636
4b00e5010000042a0000003800000000d636
4b00e5010000042a0000003800000000d636
4b00e5010000042a0000003800000000d636
-
{e=>4,a=>124,m=>-2,d=>1,j=>'SE0',l=>2,c=>2,k=>-11,h=>2,b=>2,g=>2,f=>'UE5',i=>-1}
7c005200000004150000003a00000000f532
7c005200000004150000003a00000000f532
7c005200000004150000003a00000000f532
7c005200000004150000003a00000000f532
-
{e=>1,a=>39,m=>-2,d=>2,j=>'SE1',l=>5,c=>0,k=>86,h=>1,b=>1,g=>0,f=>'UE6',i=>-4}
270081000000010600000021010000005635
270081000000010600000021010000005635
270081000000010600000021010000005635
270081000000010600000021010000005635
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>5,n=>6,a=>-69,m=>-2,d=>1,j=>'SE2',l=>5,c=>3,k=>-27,h=>7,b=>0,g=>7,f=>'UE6',i=>-2}
bbff58000000053e0000003702000000e53506000000
bbff58000000053e0000003702000000e53506000000
bbff58000000053e0000003702000000e53506000000
bbff58000000053e0000003702000000e53506000000
-
{e=>5,n=>2,a=>107,m=>-3,d=>0,j=>'SE1',l=>1,c=>-4,k=>111,h=>1,b=>0,g=>4,f=>'UE6',i=>-2}
6b0020000000052600000031010000006f2902000000
6b0020000000052600000031010000006f2902000000
6b0020000000052600000031010000006f2902000000
6b0020000000052600000031010000006f2902000000
-
{e=>4,n=>7,a=>-128,m=>-2,d=>-1,j=>'SEM2',l=>7,c=>-4,k=>-5,h=>5,b=>5,g=>1,f=>'UE7',i=>-4}
80ffe5010000040f0000002506000000fb3707000000
80ffe5010000040f0000002506000000fb3707000000
80ffe5010000040f0000002506000000fb3707000000
80ffe5010000040f0000002506000000fb3707000000
-
{e=>4,n=>4,a=>-44,m=>0,d=>3,j=>'SEM3',l=>3,c=>1,k=>-62,h=>4,b=>0,g=>2,f=>'UE5',i=>-1}
d4ffc800000004150000003c05000000c20304000000
d4ffc800000004150000003c05000000c20304000000
d4ffc800000004150000003c05000000c20304000000
d4ffc800000004150000003c05000000c20304000000
-
{e=>1,n=>3,a=>20,m=>0,d=>-3,j=>'SE0',l=>7,c=>3,k=>86,h=>1,b=>3,g=>2,f=>'UE2',i=>3}
14005b01000001120000001900000000560703000000
14005b01000001120000001900000000560703000000
14005b01000001120000001900000000560703000000
14005b01000001120000001900000000560703000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>0,n=>7,a=>-36,m=>-2,d=>-4,j=>'SEM1',l=>5,c=>-4,k=>-30,h=>6,b=>2,g=>7,f=>'UE1',o=>11,i=>-1}
dcff2201000000390000003e07000000e235070000000b
dcff2201000000390000003e07000000e235070000000b
dcff2201000000390000003e07000000e235070000000b
dcff2201000000390000003e07000000e235070000000b
-
{e=>1,n=>0,a=>47,m=>2,d=>-1,j=>'SE1',l=>6,c=>2,k=>19,h=>7,b=>5,g=>3,f=>'UE5',o=>117,i=>-1}
2f00d5010000011d0000003f0100000013160000000075
2f00d5010000011d0000003f0100000013160000000075
2f00d5010000011d0000003f0100000013160000000075
2f00d5010000011d0000003f0100000013160000000075
-
{e=>3,n=>4,a=>60,m=>-4,d=>0,j=>'SE0',l=>6,c=>-2,k=>48,h=>1,b=>2,g=>6,f=>'UE7',o=>42,i=>1}
3c0032000000033700000009000000003026040000002a
3c0032000000033700000009000000003026040000002a
3c0032000000033700000009000000003026040000002a
3c0032000000033700000009000000003026040000002a
-
{e=>1,n=>2,a=>116,m=>1,d=>-4,j=>'SEM2',l=>7,c=>3,k=>100,h=>0,b=>7,g=>2,f=>'UE3',o=>77,i=>-1}
74001f01000001130000003806000000640f020000004d
74001f01000001130000003806000000640f020000004d
74001f01000001130000003806000000640f020000004d
74001f01000001130000003806000000640f020000004d
-
{e=>1,n=>7,a=>-98,m=>-3,d=>2,j=>'SEM4',l=>5,c=>0,k=>27,h=>7,b=>1,g=>1,f=>'UE2',o=>35,i=>-2}
9eff81000000010a00000037040000001b2d0700000023
9eff81000000010a00000037040000001b2d0700000023
9eff81000000010a00000037040000001b2d0700000023
9eff81000000010a00000037040000001b2d0700000023
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
};
-
{a=>54,b=>7}
3600000007000000
3600000007000000
3600000007000000
3600000007000000
-
{a=>-14,b=>1}
f2ffffff01000000
f2ffffff01000000
f2ffffff01000000
f2ffffff01000000
-
{a=>8,b=>5}
0800000005000000
0800000005000000
0800000005000000
0800000005000000
-
{a=>-128,b=>2}
80ffffff02000000
80ffffff02000000
80ffffff02000000
80ffffff02000000
-
{a=>89,b=>7}
5900000007000000
5900000007000000
5900000007000000
5900000007000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>-4,a=>71,b=>4}
4700000024000000
4700000024000000
4700000024000000
4700000024000000
-
{c=>-1,a=>22,b=>7}
160000003f000000
160000003f000000
160000003f000000
160000003f000000
-
{c=>3,a=>6,b=>4}
060000001c000000
060000001c000000
060000001c000000
060000001c000000
-
{c=>0,a=>5,b=>7}
0500000007000000
0500000007000000
0500000007000000
0500000007000000
-
{c=>-1,a=>71,b=>5}
470000003d000000
470000003d000000
470000003d000000
470000003d000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-3,a=>-39,b=>5,d=>-4}
d9ffffff2d010000
d9ffffff2d010000
d9ffffff2d010000
d9ffffff2d010000
-
{c=>1,a=>-63,b=>0,d=>-1}
c1ffffffc8010000
c1ffffffc8010000
c1ffffffc8010000
c1ffffffc8010000
-
{c=>3,a=>-125,b=>4,d=>1}
83ffffff5c000000
83ffffff5c000000
83ffffff5c000000
83ffffff5c000000
-
{c=>-4,a=>-67,b=>6,d=>-1}
bdffffffe6010000
bdffffffe6010000
bdffffffe6010000
bdffffffe6010000
-
{c=>3,a=>-19,b=>7,d=>-4}
edffffff1f010000
edffffff1f010000
edffffff1f010000
edffffff1f010000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>2,c=>-1,a=>96,b=>4,d=>1}
600000007c00000002
600000007c00000002
600000007c00000002
600000007c00000002
-
{e=>0,c=>1,a=>-33,b=>2,d=>0}
dfffffff0a00000000
dfffffff0a00000000
dfffffff0a00000000
dfffffff0a00000000
-
{e=>1,c=>-3,a=>-123,b=>4,d=>-2}
85ffffffac01000001
85ffffffac01000001
85ffffffac01000001
85ffffffac01000001
-
{e=>2,c=>0,a=>-85,b=>3,d=>2}
abffffff8300000002
abffffff8300000002
abffffff8300000002
abffffff8300000002
-
{e=>5,c=>2,a=>93,b=>6,d=>-3}
5d0000005601000005
5d0000005601000005
5d0000005601000005
5d0000005601000005
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
};
-
{e=>4,c=>-2,a=>-117,b=>4,d=>2,f=>'UE6'}
8bffffffb40000000406000000
8bffffffb40000000406000000
8bffffffb40000000406000000
8bffffffb40000000406000000
-
{e=>2,c=>-4,a=>78,b=>0,d=>-2,f=>'UE4'}
4e000000a00100000204000000
4e000000a00100000204000000
4e000000a00100000204000000
4e000000a00100000204000000
-
{e=>3,c=>3,a=>-102,b=>0,d=>-3,f=>'UE2'}
9affffff580100000302000000
9affffff580100000302000000
9affffff580100000302000000
9affffff580100000302000000
-
{e=>3,c=>-4,a=>10,b=>2,d=>0,f=>'UE1'}
0a000000220000000301000000
0a000000220000000301000000
0a000000220000000301000000
0a000000220000000301000000
-
{e=>5,c=>3,a=>112,b=>7,d=>-2,f=>'UE1'}
700000009f0100000501000000
700000009f0100000501000000
700000009f0100000501000000
700000009f0100000501000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
};
-
{e=>4,c=>3,a=>77,g=>5,b=>3,d=>2,f=>'UE5'}
4d0000009b000000042d000000
4d0000009b000000042d000000
4d0000009b000000042d000000
4d0000009b000000042d000000
-
{e=>7,c=>3,a=>5,g=>6,b=>2,d=>0,f=>'UE5'}
050000001a0000000735000000
050000001a0000000735000000
050000001a0000000735000000
050000001a0000000735000000
-
{e=>7,c=>-2,a=>-24,g=>2,b=>0,d=>3,f=>'UE1'}
e8fffffff00000000711000000
e8fffffff00000000711000000
e8fffffff00000000711000000
e8fffffff00000000711000000
-
{e=>7,c=>3,a=>-1,g=>3,b=>6,d=>-2,f=>'UE6'}
ffffffff9e010000071e000000
ffffffff9e010000071e000000
ffffffff9e010000071e000000
ffffffff9e010000071e000000
-
{e=>1,c=>-1,a=>-111,g=>1,b=>4,d=>1,f=>'UE5'}
91ffffff7c000000010d000000
91ffffff7c000000010d000000
91ffffff7c000000010d000000
91ffffff7c000000010d000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>3,c=>-3,a=>50,g=>6,b=>2,d=>-3,f=>'UE2'}
320000006a0100000332000000
320000006a0100000332000000
320000006a0100000332000000
320000006a0100000332000000
-
{e=>2,c=>-3,a=>47,g=>0,b=>3,d=>-3,f=>'UE1'}
2f0000006b0100000201000000
2f0000006b0100000201000000
2f0000006b0100000201000000
2f0000006b0100000201000000
-
{e=>0,c=>0,a=>-123,g=>6,b=>6,d=>-3,f=>'UE4'}
85ffffff460100000034000000
85ffffff460100000034000000
85ffffff460100000034000000
85ffffff460100000034000000
-
{e=>1,c=>-2,a=>-46,g=>4,b=>5,d=>0,f=>'UE6'}
d2ffffff350000000126000000
d2ffffff350000000126000000
d2ffffff350000000126000000
d2ffffff350000000126000000
-
{e=>4,c=>-4,a=>41,g=>7,b=>7,d=>-2,f=>'UE3'}
29000000a7010000043b000000
29000000a7010000043b000000
29000000a7010000043b000000
29000000a7010000043b000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>4,a=>-86,d=>3,c=>3,h=>2,b=>7,g=>7,f=>'UE7'}
aaffffffdf000000043f00000002
aaffffffdf000000043f00000002
aaffffffdf000000043f00000002
aaffffffdf000000043f00000002
-
{e=>4,a=>64,d=>2,c=>1,h=>5,b=>5,g=>4,f=>'UE0'}
400000008d000000042000000005
400000008d000000042000000005
400000008d000000042000000005
400000008d000000042000000005
-
{e=>4,a=>-56,d=>2,c=>-4,h=>6,b=>5,g=>1,f=>'UE6'}
c8ffffffa5000000040e00000006
c8ffffffa5000000040e00000006
c8ffffffa5000000040e00000006
c8ffffffa5000000040e00000006
-
{e=>6,a=>78,d=>3,c=>-1,h=>3,b=>0,g=>6,f=>'UE4'}
4e000000f8000000063400000003
4e000000f8000000063400000003
4e000000f8000000063400000003
4e000000f8000000063400000003
-
{e=>7,a=>-101,d=>0,c=>-2,h=>6,b=>1,g=>4,f=>'UE1'}
9bffffff31000000072100000006
9bffffff31000000072100000006
9bffffff31000000072100000006
9bffffff31000000072100000006
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>4,a=>98,d=>1,c=>0,h=>3,b=>1,g=>0,f=>'UE5',i=>-4}
6200000041000000040500000023
6200000041000000040500000023
6200000041000000040500000023
6200000041000000040500000023
-
{e=>6,a=>-56,d=>-2,c=>-4,h=>6,b=>4,g=>7,f=>'UE5',i=>2}
c8ffffffa4010000063d00000016
c8ffffffa4010000063d00000016
c8ffffffa4010000063d00000016
c8ffffffa4010000063d00000016
-
{e=>3,a=>-48,d=>0,c=>1,h=>5,b=>7,g=>5,f=>'UE1',i=>3}
d0ffffff0f00000003290000001d
d0ffffff0f00000003290000001d
d0ffffff0f00000003290000001d
d0ffffff0f00000003290000001d
-
{e=>0,a=>-14,d=>-1,c=>-4,h=>1,b=>1,g=>4,f=>'UE1',i=>1}
f2ffffffe1010000002100000009
f2ffffffe1010000002100000009
f2ffffffe1010000002100000009
f2ffffffe1010000002100000009
-
{e=>4,a=>-3,d=>3,c=>2,h=>1,b=>6,g=>6,f=>'UE4',i=>-2}
fdffffffd6000000043400000031
fdffffffd6000000043400000031
fdffffffd6000000043400000031
fdffffffd6000000043400000031
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
};
-
{e=>7,a=>-125,d=>-1,j=>'SE0',c=>-3,h=>0,b=>3,g=>0,f=>'UE0',i=>0}
83ffffffeb01000007000000000000000000
83ffffffeb01000007000000000000000000
83ffffffeb01000007000000000000000000
83ffffffeb01000007000000000000000000
-
{e=>4,a=>-83,d=>1,j=>'SEM1',c=>-2,h=>0,b=>5,g=>2,f=>'UE1',i=>3}
adffffff7500000004110000001807000000
adffffff7500000004110000001807000000
adffffff7500000004110000001807000000
adffffff7500000004110000001807000000
-
{e=>1,a=>118,d=>-1,j=>'SE0',c=>1,h=>6,b=>1,g=>5,f=>'UE7',i=>0}
76000000c9010000012f0000000600000000
76000000c9010000012f0000000600000000
76000000c9010000012f0000000600000000
76000000c9010000012f0000000600000000
-
{e=>1,a=>-5,d=>-4,j=>'SE0',c=>0,h=>0,b=>6,g=>3,f=>'UE3',i=>2}
fbffffff06010000011b0000001000000000
fbffffff06010000011b0000001000000000
fbffffff06010000011b0000001000000000
fbffffff06010000011b0000001000000000
-
{e=>0,a=>70,d=>-3,j=>'SEM1',c=>0,h=>3,b=>5,g=>3,f=>'UE5',i=>2}
4600000045010000001d0000001307000000
4600000045010000001d0000001307000000
4600000045010000001d0000001307000000
4600000045010000001d0000001307000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
};
-
{e=>0,a=>2,d=>0,j=>'SE2',c=>2,k=>37,h=>4,b=>1,g=>0,f=>'UE2',i=>0}
02000000110000000002000000040200000025
02000000110000000002000000040200000025
02000000110000000002000000040200000025
02000000110000000002000000040200000025
-
{e=>1,a=>68,d=>-2,j=>'SEM2',c=>-4,k=>-109,h=>0,b=>4,g=>2,f=>'UE5',i=>0}
44000000a40100000115000000000600000093
44000000a40100000115000000000600000093
44000000a40100000115000000000600000093
44000000a40100000115000000000600000093
-
{e=>4,a=>117,d=>-4,j=>'SEM4',c=>2,k=>-10,h=>7,b=>3,g=>1,f=>'UE3',i=>-2}
7500000013010000040b0000003704000000f6
7500000013010000040b0000003704000000f6
7500000013010000040b0000003704000000f6
7500000013010000040b0000003704000000f6
-
{e=>7,a=>-56,d=>-3,j=>'SE2',c=>3,k=>30,h=>7,b=>6,g=>5,f=>'UE5',i=>-1}
c8ffffff5e010000072d0000003f020000001e
c8ffffff5e010000072d0000003f020000001e
c8ffffff5e010000072d0000003f020000001e
c8ffffff5e010000072d0000003f020000001e
-
{e=>1,a=>-1,d=>-2,j=>'SEM1',c=>-3,k=>-71,h=>6,b=>6,g=>3,f=>'UE2',i=>-3}
ffffffffae010000011a0000002e07000000b9
ffffffffae010000011a0000002e07000000b9
ffffffffae010000011a0000002e07000000b9
ffffffffae010000011a0000002e07000000b9
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>1,a=>26,d=>2,j=>'SEM1',l=>2,c=>-2,k=>-113,h=>2,b=>0,g=>0,f=>'UE7',i=>-3}
1a000000b000000001070000002a070000008f02
1a000000b000000001070000002a070000008f02
1a000000b000000001070000002a070000008f02
1a000000b000000001070000002a070000008f02
-
{e=>2,a=>117,d=>-4,j=>'SE1',l=>6,c=>3,k=>-95,h=>1,b=>6,g=>4,f=>'UE0',i=>1}
750000001e01000002200000000901000000a106
750000001e01000002200000000901000000a106
750000001e01000002200000000901000000a106
750000001e01000002200000000901000000a106
-
{e=>4,a=>69,d=>3,j=>'SE1',l=>7,c=>-3,k=>-103,h=>5,b=>4,g=>7,f=>'UE2',i=>-4}
45000000ec000000043a00000025010000009907
45000000ec000000043a00000025010000009907
45000000ec000000043a00000025010000009907
45000000ec000000043a00000025010000009907
-
{e=>0,a=>66,d=>0,j=>'SEM1',l=>4,c=>-2,k=>-115,h=>0,b=>6,g=>2,f=>'UE6',i=>-1}
4200000036000000001600000038070000008d04
4200000036000000001600000038070000008d04
4200000036000000001600000038070000008d04
4200000036000000001600000038070000008d04
-
{e=>0,a=>115,d=>3,j=>'SE3',l=>6,c=>-3,k=>-110,h=>4,b=>7,g=>6,f=>'UE3',i=>1}
73000000ef00000000330000000c030000009206
73000000ef00000000330000000c030000009206
73000000ef00000000330000000c030000009206
73000000ef00000000330000000c030000009206
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>1,a=>20,m=>-3,d=>1,j=>'SE3',l=>5,c=>-3,k=>47,h=>7,b=>3,g=>2,f=>'UE7',i=>-4}
140000006b000000011700000027030000002f2d
140000006b000000011700000027030000002f2d
140000006b000000011700000027030000002f2d
140000006b000000011700000027030000002f2d
-
{e=>5,a=>113,m=>0,d=>-2,j=>'SE3',l=>3,c=>-4,k=>63,h=>2,b=>7,g=>2,f=>'UE2',i=>2}
71000000a7010000051200000012030000003f03
71000000a7010000051200000012030000003f03
71000000a7010000051200000012030000003f03
71000000a7010000051200000012030000003f03
-
{e=>1,a=>58,m=>-1,d=>-1,j=>'SEM2',l=>1,c=>1,k=>4,h=>1,b=>2,g=>7,f=>'UE5',i=>-2}
3a000000ca010000013d00000031060000000439
3a000000ca010000013d00000031060000000439
3a000000ca010000013d00000031060000000439
3a000000ca010000013d00000031060000000439
-
{e=>5,a=>101,m=>0,d=>3,j=>'SEM4',l=>6,c=>-2,k=>124,h=>5,b=>7,g=>0,f=>'UE0',i=>-1}
65000000f700000005000000003d040000007c06
65000000f700000005000000003d040000007c06
65000000f700000005000000003d040000007c06
65000000f700000005000000003d040000007c06
-
{e=>1,a=>73,m=>-4,d=>-1,j=>'SEM1',l=>2,c=>1,k=>-19,h=>4,b=>0,g=>5,f=>'UE3',i=>-4}
49000000c8010000012b0000002407000000ed22
49000000c8010000012b0000002407000000ed22
49000000c8010000012b0000002407000000ed22
49000000c8010000012b0000002407000000ed22
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>1,n=>1,a=>-71,m=>-2,d=>0,j=>'SE1',l=>0,c=>-2,k=>60,h=>6,b=>4,g=>5,f=>'UE5',i=>-1}
b9ffffff34000000012d0000003e010000003c3001000000
b9ffffff34000000012d0000003e010000003c3001000000
b9ffffff34000000012d0000003e010000003c3001000000
b9ffffff34000000012d0000003e010000003c3001000000
-
{e=>7,n=>5,a=>-15,m=>-1,d=>0,j=>'SEM1',l=>5,c=>-2,k=>4,h=>2,b=>3,g=>3,f=>'UE0',i=>-3}
f1ffffff3300000007180000002a07000000043d05000000
f1ffffff3300000007180000002a07000000043d05000000
f1ffffff3300000007180000002a07000000043d05000000
f1ffffff3300000007180000002a07000000043d05000000
-
{e=>6,n=>3,a=>12,m=>1,d=>3,j=>'SE3',l=>4,c=>-4,k=>116,h=>6,b=>1,g=>4,f=>'UE2',i=>-2}
0c000000e100000006220000003603000000740c03000000
0c000000e100000006220000003603000000740c03000000
0c000000e100000006220000003603000000740c03000000
0c000000e100000006220000003603000000740c03000000
-
{e=>5,n=>3,a=>42,m=>1,d=>-3,j=>'SE3',l=>4,c=>1,k=>-90,h=>4,b=>3,g=>6,f=>'UE3',i=>-1}
2a0000004b01000005330000003c03000000a60c03000000
2a0000004b01000005330000003c03000000a60c03000000
2a0000004b01000005330000003c03000000a60c03000000
2a0000004b01000005330000003c03000000a60c03000000
-
{e=>7,n=>3,a=>55,m=>-2,d=>0,j=>'SE2',l=>0,c=>2,k=>-125,h=>4,b=>5,g=>7,f=>'UE7',i=>-4}
3700000015000000073f0000002402000000833003000000
3700000015000000073f0000002402000000833003000000
3700000015000000073f0000002402000000833003000000
3700000015000000073f0000002402000000833003000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>7,n=>5,a=>111,m=>-1,d=>3,j=>'SE1',l=>5,c=>-1,k=>85,h=>5,b=>0,g=>4,f=>'UE7',o=>100,i=>2}
6f000000f800000007270000001501000000553d0500000064
6f000000f800000007270000001501000000553d0500000064
6f000000f800000007270000001501000000553d0500000064
6f000000f800000007270000001501000000553d0500000064
-
{e=>3,n=>3,a=>68,m=>3,d=>-2,j=>'SE0',l=>2,c=>3,k=>30,h=>0,b=>6,g=>3,f=>'UE0',o=>140,i=>-1}
440000009e010000031800000038000000001e1a030000008c
440000009e010000031800000038000000001e1a030000008c
440000009e010000031800000038000000001e1a030000008c
440000009e010000031800000038000000001e1a030000008c
-
{e=>1,n=>2,a=>-1,m=>2,d=>1,j=>'SE0',l=>1,c=>3,k=>-56,h=>3,b=>0,g=>3,f=>'UE1',o=>96,i=>2}
ffffffff5800000001190000001300000000c8110200000060
ffffffff5800000001190000001300000000c8110200000060
ffffffff5800000001190000001300000000c8110200000060
ffffffff5800000001190000001300000000c8110200000060
-
{e=>7,n=>5,a=>26,m=>3,d=>1,j=>'SEM3',l=>5,c=>-1,k=>-127,h=>0,b=>4,g=>2,f=>'UE1',o=>99,i=>-3}
1a0000007c00000007110000002805000000811d0500000063
1a0000007c00000007110000002805000000811d0500000063
1a0000007c00000007110000002805000000811d0500000063
1a0000007c00000007110000002805000000811d0500000063
-
{e=>1,n=>3,a=>-55,m=>0,d=>0,j=>'SEM1',l=>2,c=>1,k=>-1,h=>1,b=>3,g=>3,f=>'UE2',o=>164,i=>-4}
c9ffffff0b000000011a0000002107000000ff0203000000a4
c9ffffff0b000000011a0000002107000000ff0203000000a4
c9ffffff0b000000011a0000002107000000ff0203000000a4
c9ffffff0b000000011a0000002107000000ff0203000000a4
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
};
-
{a=>30,b=>3}
1e00000003000000
1e00000003000000
1e00000003000000
1e00000003000000
-
{a=>-14,b=>4}
f2ffffff04000000
f2ffffff04000000
f2ffffff04000000
f2ffffff04000000
-
{a=>3,b=>2}
0300000002000000
0300000002000000
0300000002000000
0300000002000000
-
{a=>98,b=>5}
6200000005000000
6200000005000000
6200000005000000
6200000005000000
-
{a=>85,b=>3}
5500000003000000
5500000003000000
5500000003000000
5500000003000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>-1,a=>-46,b=>6}
d2ffffff3e000000
d2ffffff3e000000
d2ffffff3e000000
d2ffffff3e000000
-
{c=>2,a=>-36,b=>5}
dcffffff15000000
dcffffff15000000
dcffffff15000000
dcffffff15000000
-
{c=>-4,a=>78,b=>7}
4e00000027000000
4e00000027000000
4e00000027000000
4e00000027000000
-
{c=>-4,a=>65,b=>5}
4100000025000000
4100000025000000
4100000025000000
4100000025000000
-
{c=>-1,a=>124,b=>3}
7c0000003b000000
7c0000003b000000
7c0000003b000000
7c0000003b000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>0,a=>45,b=>2,d=>1}
2d00000042000000
2d00000042000000
2d00000042000000
2d00000042000000
-
{c=>0,a=>-85,b=>5,d=>0}
abffffff05000000
abffffff05000000
abffffff05000000
abffffff05000000
-
{c=>-3,a=>62,b=>0,d=>0}
3e00000028000000
3e00000028000000
3e00000028000000
3e00000028000000
-
{c=>3,a=>52,b=>1,d=>1}
3400000059000000
3400000059000000
3400000059000000
3400000059000000
-
{c=>-2,a=>17,b=>6,d=>-4}
1100000036010000
1100000036010000
1100000036010000
1100000036010000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>4,c=>-1,a=>-49,b=>1,d=>-4}
cfffffff3901000004
cfffffff3901000004
cfffffff3901000004
cfffffff3901000004
-
{e=>5,c=>0,a=>127,b=>4,d=>0}
7f0000000400000005
7f0000000400000005
7f0000000400000005
7f0000000400000005
-
{e=>3,c=>0,a=>28,b=>0,d=>3}
1c000000c000000003
1c000000c000000003
1c000000c000000003
1c000000c000000003
-
{e=>3,c=>2,a=>42,b=>3,d=>-4}
2a0000001301000003
2a0000001301000003
2a0000001301000003
2a0000001301000003
-
{e=>1,c=>3,a=>-60,b=>0,d=>-2}
c4ffffff9801000001
c4ffffff9801000001
c4ffffff9801000001
c4ffffff9801000001
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
};
-
{e=>7,c=>3,a=>-108,b=>1,d=>-1,f=>'UE1'}
94ffffffd90100000701000000
94ffffffd90100000701000000
94ffffffd90100000701000000
94ffffffd90100000701000000
-
{e=>6,c=>-2,a=>4,b=>1,d=>-4,f=>'UE2'}
04000000310100000602000000
04000000310100000602000000
04000000310100000602000000
04000000310100000602000000
-
{e=>3,c=>-3,a=>79,b=>0,d=>-4,f=>'UE0'}
4f000000280100000300000000
4f000000280100000300000000
4f000000280100000300000000
4f000000280100000300000000
-
{e=>2,c=>-2,a=>45,b=>0,d=>3,f=>'UE5'}
2d000000f00000000205000000
2d000000f00000000205000000
2d000000f00000000205000000
2d000000f00000000205000000
-
{e=>4,c=>-1,a=>18,b=>7,d=>-1,f=>'UE2'}
12000000ff0100000402000000
12000000ff0100000402000000
12000000ff0100000402000000
12000000ff0100000402000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
};
-
{e=>5,c=>-1,a=>107,g=>7,b=>1,d=>-2,f=>'UE5'}
6b000000b9010000053d000000
6b000000b9010000053d000000
6b000000b9010000053d000000
6b000000b9010000053d000000
-
{e=>0,c=>-1,a=>-57,g=>6,b=>7,d=>-4,f=>'UE2'}
c7ffffff3f0100000032000000
c7ffffff3f0100000032000000
c7ffffff3f0100000032000000
c7ffffff3f0100000032000000
-
{e=>1,c=>2,a=>9,g=>5,b=>7,d=>2,f=>'UE7'}
0900000097000000012f000000
0900000097000000012f000000
0900000097000000012f000000
0900000097000000012f000000
-
{e=>3,c=>3,a=>-7,g=>4,b=>4,d=>2,f=>'UE5'}
f9ffffff9c0000000325000000
f9ffffff9c0000000325000000
f9ffffff9c0000000325000000
f9ffffff9c0000000325000000
-
{e=>7,c=>1,a=>-15,g=>6,b=>2,d=>2,f=>'UE0'}
f1ffffff8a0000000730000000
f1ffffff8a0000000730000000
f1ffffff8a0000000730000000
f1ffffff8a0000000730000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>1,c=>-1,a=>-17,g=>2,b=>3,d=>-2,f=>'UE0'}
efffffffbb0100000110000000
efffffffbb0100000110000000
efffffffbb0100000110000000
efffffffbb0100000110000000
-
{e=>7,c=>-2,a=>6,g=>1,b=>0,d=>-3,f=>'UE6'}
0600000070010000070e000000
0600000070010000070e000000
0600000070010000070e000000
0600000070010000070e000000
-
{e=>2,c=>3,a=>64,g=>4,b=>2,d=>2,f=>'UE1'}
400000009a0000000221000000
400000009a0000000221000000
400000009a0000000221000000
400000009a0000000221000000
-
{e=>2,c=>1,a=>58,g=>6,b=>1,d=>1,f=>'UE5'}
3a000000490000000235000000
3a000000490000000235000000
3a000000490000000235000000
3a000000490000000235000000
-
{e=>0,c=>1,a=>-124,g=>4,b=>2,d=>-1,f=>'UE4'}
84ffffffca0100000024000000
84ffffffca0100000024000000
84ffffffca0100000024000000
84ffffffca0100000024000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>5,a=>5,d=>1,c=>-3,h=>0,b=>1,g=>2,f=>'UE1'}
0500000069000000051100000000
0500000069000000051100000000
0500000069000000051100000000
0500000069000000051100000000
-
{e=>2,a=>-102,d=>-2,c=>-2,h=>5,b=>0,g=>1,f=>'UE6'}
9affffffb0010000020e00000005
9affffffb0010000020e00000005
9affffffb0010000020e00000005
9affffffb0010000020e00000005
-
{e=>5,a=>65,d=>-4,c=>0,h=>7,b=>3,g=>2,f=>'UE7'}
4100000003010000051700000007
4100000003010000051700000007
4100000003010000051700000007
4100000003010000051700000007
-
{e=>2,a=>-87,d=>3,c=>-1,h=>1,b=>7,g=>2,f=>'UE6'}
a9ffffffff000000021600000001
a9ffffffff000000021600000001
a9ffffffff000000021600000001
a9ffffffff000000021600000001
-
{e=>5,a=>-29,d=>2,c=>-4,h=>3,b=>6,g=>7,f=>'UE3'}
e3ffffffa6000000053b00000003
e3ffffffa6000000053b00000003
e3ffffffa6000000053b00000003
e3ffffffa6000000053b00000003
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>1,a=>-52,d=>-3,c=>2,h=>1,b=>4,g=>2,f=>'UE6',i=>3}
ccffffff54010000011600000019
ccffffff54010000011600000019
ccffffff54010000011600000019
ccffffff54010000011600000019
-
{e=>6,a=>-55,d=>-2,c=>2,h=>7,b=>1,g=>4,f=>'UE2',i=>-2}
c9ffffff91010000062200000037
c9ffffff91010000062200000037
c9ffffff91010000062200000037
c9ffffff91010000062200000037
-
{e=>3,a=>1,d=>-4,c=>3,h=>2,b=>6,g=>2,f=>'UE1',i=>0}
010000001e010000031100000002
010000001e010000031100000002
010000001e010000031100000002
010000001e010000031100000002
-
{e=>7,a=>92,d=>1,c=>0,h=>3,b=>6,g=>4,f=>'UE3',i=>3}
5c0000004600000007230000001b
5c0000004600000007230000001b
5c0000004600000007230000001b
5c0000004600000007230000001b
-
{e=>4,a=>83,d=>-3,c=>-2,h=>6,b=>1,g=>6,f=>'UE5',i=>-3}
530000007101000004350000002e
530000007101000004350000002e
530000007101000004350000002e
530000007101000004350000002e
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
};
-
{e=>2,a=>104,d=>1,j=>'SEM2',c=>-3,h=>4,b=>3,g=>5,f=>'UE4',i=>3}
680000006b000000022c0000001c06000000
680000006b000000022c0000001c06000000
680000006b000000022c0000001c06000000
680000006b000000022c0000001c06000000
-
{e=>5,a=>72,d=>-3,j=>'SE0',c=>2,h=>6,b=>2,g=>5,f=>'UE0',i=>0}
480000005201000005280000000600000000
480000005201000005280000000600000000
480000005201000005280000000600000000
480000005201000005280000000600000000
-
{e=>4,a=>-114,d=>2,j=>'SE0',c=>-4,h=>4,b=>5,g=>7,f=>'UE7',i=>3}
8effffffa5000000043f0000001c00000000
8effffffa5000000043f0000001c00000000
8effffffa5000000043f0000001c00000000
8effffffa5000000043f0000001c00000000
-
{e=>5,a=>-114,d=>3,j=>'SE1',c=>2,h=>2,b=>5,g=>2,f=>'UE1',i=>-2}
8effffffd500000005110000003201000000
8effffffd500000005110000003201000000
8effffffd500000005110000003201000000
8effffffd500000005110000003201000000
-
{e=>7,a=>-75,d=>1,j=>'SEM3',c=>-3,h=>1,b=>7,g=>1,f=>'UE2',i=>0}
b5ffffff6f000000070a0000000105000000
b5ffffff6f000000070a0000000105000000
b5ffffff6f000000070a0000000105000000
b5ffffff6f000000070a0000000105000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
};
-
{e=>2,a=>48,d=>-2,j=>'SE3',c=>3,k=>43,h=>4,b=>2,g=>2,f=>'UE5',i=>0}
300000009a010000021500000004030000002b
300000009a010000021500000004030000002b
300000009a010000021500000004030000002b
300000009a010000021500000004030000002b
-
{e=>6,a=>-50,d=>0,j=>'SE0',c=>-1,k=>78,h=>6,b=>5,g=>5,f=>'UE6',i=>-3}
ceffffff3d000000062e0000002e000000004e
ceffffff3d000000062e0000002e000000004e
ceffffff3d000000062e0000002e000000004e
ceffffff3d000000062e0000002e000000004e
-
{e=>4,a=>67,d=>0,j=>'SEM2',c=>3,k=>-96,h=>7,b=>3,g=>1,f=>'UE3',i=>2}
430000001b000000040b0000001706000000a0
430000001b000000040b0000001706000000a0
430000001b000000040b0000001706000000a0
430000001b000000040b0000001706000000a0
-
{e=>5,a=>-6,d=>1,j=>'SE2',c=>0,k=>69,h=>4,b=>5,g=>0,f=>'UE0',i=>-4}
faffffff450000000500000000240200000045
faffffff450000000500000000240200000045
faffffff450000000500000000240200000045
faffffff450000000500000000240200000045
-
{e=>7,a=>-120,d=>1,j=>'SE0',c=>-1,k=>92,h=>1,b=>5,g=>5,f=>'UE3',i=>2}
88ffffff7d000000072b00000011000000005c
88ffffff7d000000072b00000011000000005c
88ffffff7d000000072b00000011000000005c
88ffffff7d000000072b00000011000000005c
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>3,a=>-102,d=>-2,j=>'SEM4',l=>7,c=>-3,k=>-44,h=>3,b=>3,g=>7,f=>'UE6',i=>0}
9affffffab010000033e0000000304000000d407
9affffffab010000033e0000000304000000d407
9affffffab010000033e0000000304000000d407
9affffffab010000033e0000000304000000d407
-
{e=>6,a=>15,d=>1,j=>'SE1',l=>1,c=>2,k=>-19,h=>5,b=>7,g=>1,f=>'UE6',i=>-2}
0f00000057000000060e0000003501000000ed01
0f00000057000000060e0000003501000000ed01
0f00000057000000060e0000003501000000ed01
0f00000057000000060e0000003501000000ed01
-
{e=>2,a=>-49,d=>-1,j=>'SEM3',l=>3,c=>-2,k=>75,h=>0,b=>4,g=>7,f=>'UE3',i=>-3}
cffffffff4010000023b00000028050000004b03
cffffffff4010000023b00000028050000004b03
cffffffff4010000023b00000028050000004b03
cffffffff4010000023b00000028050000004b03
-
{e=>6,a=>-49,d=>1,j=>'SEM2',l=>3,c=>3,k=>-128,h=>7,b=>5,g=>0,f=>'UE1',i=>2}
cfffffff5d000000060100000017060000008003
cfffffff5d000000060100000017060000008003
cfffffff5d000000060100000017060000008003
cfffffff5d000000060100000017060000008003
-
{e=>3,a=>-61,d=>0,j=>'SEM1',l=>1,c=>1,k=>6,h=>0,b=>1,g=>3,f=>'UE0',i=>-2}
c3ffffff09000000031800000030070000000601
c3ffffff09000000031800000030070000000601
c3ffffff09000000031800000030070000000601
c3ffffff09000000031800000030070000000601
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>1,a=>101,m=>1,d=>3,j=>'SEM4',l=>0,c=>3,k=>115,h=>2,b=>1,g=>3,f=>'UE0',i=>-3}
65000000d900000001180000002a040000007308
65000000d900000001180000002a040000007308
65000000d900000001180000002a040000007308
65000000d900000001180000002a040000007308
-
{e=>4,a=>-15,m=>1,d=>-3,j=>'SE2',l=>6,c=>-3,k=>-105,h=>6,b=>3,g=>5,f=>'UE5',i=>1}
f1ffffff6b010000042d0000000e02000000970e
f1ffffff6b010000042d0000000e02000000970e
f1ffffff6b010000042d0000000e02000000970e
f1ffffff6b010000042d0000000e02000000970e
-
{e=>3,a=>111,m=>-1,d=>1,j=>'SE0',l=>6,c=>-1,k=>-84,h=>3,b=>4,g=>0,f=>'UE4',i=>-1}
6f0000007c00000003040000003b00000000ac3e
6f0000007c00000003040000003b00000000ac3e
6f0000007c00000003040000003b00000000ac3e
6f0000007c00000003040000003b00000000ac3e
-
{e=>7,a=>-11,m=>3,d=>-4,j=>'SEM1',l=>3,c=>0,k=>-99,h=>0,b=>4,g=>4,f=>'UE4',i=>-3}
f5ffffff04010000072400000028070000009d1b
f5ffffff04010000072400000028070000009d1b
f5ffffff04010000072400000028070000009d1b
f5ffffff04010000072400000028070000009d1b
-
{e=>4,a=>-69,m=>-3,d=>-2,j=>'SEM3',l=>2,c=>0,k=>94,h=>2,b=>4,g=>3,f=>'UE3',i=>2}
bbffffff84010000041b00000012050000005e2a
bbffffff84010000041b00000012050000005e2a
bbffffff84010000041b00000012050000005e2a
bbffffff84010000041b00000012050000005e2a
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>5,n=>4,a=>-5,m=>-1,d=>-3,j=>'SE0',l=>4,c=>-3,k=>70,h=>7,b=>6,g=>4,f=>'UE5',i=>-3}
fbffffff6e01000005250000002f00000000463c04000000
fbffffff6e01000005250000002f00000000463c04000000
fbffffff6e01000005250000002f00000000463c04000000
fbffffff6e01000005250000002f00000000463c04000000
-
{e=>7,n=>6,a=>108,m=>-3,d=>1,j=>'SEM3',l=>5,c=>-3,k=>-4,h=>3,b=>0,g=>6,f=>'UE6',i=>-2}
6c0000006800000007360000003305000000fc2d06000000
6c0000006800000007360000003305000000fc2d06000000
6c0000006800000007360000003305000000fc2d06000000
6c0000006800000007360000003305000000fc2d06000000
-
{e=>3,n=>7,a=>-39,m=>-2,d=>3,j=>'SEM2',l=>2,c=>-4,k=>59,h=>1,b=>0,g=>7,f=>'UE5',i=>-4}
d9ffffffe0000000033d00000021060000003b3207000000
d9ffffffe0000000033d00000021060000003b3207000000
d9ffffffe0000000033d00000021060000003b3207000000
d9ffffffe0000000033d00000021060000003b3207000000
-
{e=>2,n=>0,a=>-64,m=>1,d=>1,j=>'SE1',l=>0,c=>2,k=>123,h=>0,b=>7,g=>7,f=>'UE7',i=>1}
c0ffffff57000000023f00000008010000007b0800000000
c0ffffff57000000023f00000008010000007b0800000000
c0ffffff57000000023f00000008010000007b0800000000
c0ffffff57000000023f00000008010000007b0800000000
-
{e=>5,n=>7,a=>-49,m=>-2,d=>-3,j=>'SE2',l=>0,c=>0,k=>95,h=>1,b=>5,g=>6,f=>'UE1',i=>-1}
cfffffff45010000053100000039020000005f3007000000
cfffffff45010000053100000039020000005f3007000000
cfffffff45010000053100000039020000005f3007000000
cfffffff45010000053100000039020000005f3007000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct enum_pack_1 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>6,n=>7,a=>-65,m=>-2,d=>-3,j=>'SEM3',l=>0,c=>0,k=>67,h=>5,b=>3,g=>6,f=>'UE7',o=>184,i=>3}
bfffffff4301000006370000001d05000000433007000000b8
bfffffff4301000006370000001d05000000433007000000b8
bfffffff4301000006370000001d05000000433007000000b8
bfffffff4301000006370000001d05000000433007000000b8
-
{e=>5,n=>0,a=>80,m=>-2,d=>0,j=>'SEM2',l=>4,c=>-3,k=>18,h=>7,b=>4,g=>5,f=>'UE5',o=>3,i=>1}
500000002c000000052d0000000f0600000012340000000003
500000002c000000052d0000000f0600000012340000000003
500000002c000000052d0000000f0600000012340000000003
500000002c000000052d0000000f0600000012340000000003
-
{e=>5,n=>0,a=>89,m=>-1,d=>-4,j=>'SEM4',l=>6,c=>2,k=>-48,h=>0,b=>2,g=>2,f=>'UE7',o=>146,i=>2}
590000001201000005170000001004000000d03e0000000092
590000001201000005170000001004000000d03e0000000092
590000001201000005170000001004000000d03e0000000092
590000001201000005170000001004000000d03e0000000092
-
{e=>5,n=>6,a=>-3,m=>-1,d=>0,j=>'SE1',l=>1,c=>0,k=>72,h=>1,b=>3,g=>4,f=>'UE2',o=>92,i=>2}
fdffffff03000000052200000011010000004839060000005c
fdffffff03000000052200000011010000004839060000005c
fdffffff03000000052200000011010000004839060000005c
fdffffff03000000052200000011010000004839060000005c
-
{e=>3,n=>5,a=>-96,m=>-4,d=>3,j=>'SE1',l=>5,c=>-4,k=>-39,h=>0,b=>3,g=>3,f=>'UE4',o=>240,i=>-2}
a0ffffffe3000000031c0000003001000000d92505000000f0
a0ffffffe3000000031c0000003001000000d92505000000f0
a0ffffffe3000000031c0000003001000000d92505000000f0
a0ffffffe3000000031c0000003001000000d92505000000f0
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
};
-
{a=>3}
03000000
03000000
03000000
03000000
-
{a=>4}
04000000
04000000
04000000
04000000
-
{a=>0}
00000000
00000000
00000000
00000000
-
{a=>2}
02000000
02000000
02000000
02000000
-
{a=>0}
00000000
00000000
00000000
00000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
};
-
{a=>5,b=>2}
15000000
15000000
15000000
15000000
-
{a=>6,b=>-2}
36000000
36000000
36000000
36000000
-
{a=>6,b=>3}
1e000000
1e000000
1e000000
1e000000
-
{a=>7,b=>3}
1f000000
1f000000
1f000000
1f000000
-
{a=>1,b=>0}
01000000
01000000
01000000
01000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
};
-
{c=>-4,a=>2,b=>-1}
3a010000
3a010000
3a010000
3a010000
-
{c=>2,a=>0,b=>2}
90000000
90000000
90000000
90000000
-
{c=>-3,a=>7,b=>-4}
67010000
67010000
67010000
67010000
-
{c=>2,a=>3,b=>1}
8b000000
8b000000
8b000000
8b000000
-
{c=>-4,a=>0,b=>-3}
28010000
28010000
28010000
28010000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
};
-
{c=>2,a=>4,b=>0,d=>3}
840000000300
840000000300
840000000300
840000000300
-
{c=>-4,a=>2,b=>2,d=>5}
120100000500
120100000500
120100000500
120100000500
-
{c=>-3,a=>2,b=>-3,d=>7}
6a0100000700
6a0100000700
6a0100000700
6a0100000700
-
{c=>1,a=>7,b=>-4,d=>1}
670000000100
670000000100
670000000100
670000000100
-
{c=>-2,a=>2,b=>3,d=>3}
9a0100000300
9a0100000300
9a0100000300
9a0100000300
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
};
-
{e=>'UE6',c=>-4,a=>5,b=>-3,d=>1}
2d010000010006000000
2d010000010006000000
2d010000010006000000
2d010000010006000000
-
{e=>'UE5',c=>1,a=>6,b=>2,d=>4}
56000000040005000000
56000000040005000000
56000000040005000000
56000000040005000000
-
{e=>'UE6',c=>-1,a=>0,b=>-4,d=>7}
e0010000070006000000
e0010000070006000000
e0010000070006000000
e0010000070006000000
-
{e=>'UE1',c=>-4,a=>4,b=>-3,d=>4}
2c010000040001000000
2c010000040001000000
2c010000040001000000
2c010000040001000000
-
{e=>'UE1',c=>-2,a=>2,b=>2,d=>4}
92010000040001000000
92010000040001000000
92010000040001000000
92010000040001000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
};
-
{e=>'UE1',c=>-4,a=>4,b=>-1,d=>3,f=>3}
3c010000030019000000
3c010000030019000000
3c010000030019000000
3c010000030019000000
-
{e=>'UE3',c=>-4,a=>2,b=>-3,d=>0,f=>0}
2a010000000003000000
2a010000000003000000
2a010000000003000000
2a010000000003000000
-
{e=>'UE0',c=>0,a=>3,b=>-3,d=>5,f=>0}
2b000000050000000000
2b000000050000000000
2b000000050000000000
2b000000050000000000
-
{e=>'UE7',c=>1,a=>3,b=>-3,d=>3,f=>4}
6b000000030027000000
6b000000030027000000
6b000000030027000000
6b000000030027000000
-
{e=>'UE7',c=>-2,a=>2,b=>3,d=>6,f=>5}
9a01000006002f000000
9a01000006002f000000
9a01000006002f000000
9a01000006002f000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
};
-
{e=>'UE4',c=>2,a=>1,b=>-4,d=>1,f=>3}
a100000001001c000000
a100000001001c000000
a100000001001c000000
a100000001001c000000
-
{e=>'UE7',c=>0,a=>6,b=>-4,d=>2,f=>7}
2600000002003f000000
2600000002003f000000
2600000002003f000000
2600000002003f000000
-
{e=>'UE6',c=>3,a=>4,b=>-2,d=>5,f=>2}
f4000000050016000000
f4000000050016000000
f4000000050016000000
f4000000050016000000
-
{e=>'UE0',c=>-3,a=>5,b=>-2,d=>5,f=>3}
75010000050018000000
75010000050018000000
75010000050018000000
75010000050018000000
-
{e=>'UE1',c=>0,a=>6,b=>0,d=>3,f=>4}
06000000030021000000
06000000030021000000
06000000030021000000
06000000030021000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
};
-
{e=>'UE4',c=>-2,a=>3,g=>3,b=>-4,d=>7,f=>5}
a301000007002c0000000300
a301000007002c0000000300
a301000007002c0000000300
a301000007002c0000000300
-
{e=>'UE2',c=>0,a=>1,g=>7,b=>0,d=>6,f=>2}
010000000600120000000700
010000000600120000000700
010000000600120000000700
010000000600120000000700
-
{e=>'UE2',c=>-1,a=>3,g=>7,b=>3,d=>4,f=>2}
db0100000400120000000700
db0100000400120000000700
db0100000400120000000700
db0100000400120000000700
-
{e=>'UE0',c=>-1,a=>4,g=>1,b=>2,d=>0,f=>0}
d40100000000000000000100
d40100000000000000000100
d40100000000000000000100
d40100000000000000000100
-
{e=>'UE1',c=>-2,a=>7,g=>4,b=>-2,d=>3,f=>6}
b70100000300310000000400
b70100000300310000000400
b70100000300310000000400
b70100000300310000000400
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
};
-
{e=>'UE4',a=>1,d=>4,c=>-4,h=>-1,b=>2,g=>3,f=>1}
1101000004000c0000003b00
1101000004000c0000003b00
1101000004000c0000003b00
1101000004000c0000003b00
-
{e=>'UE3',a=>3,d=>3,c=>2,h=>1,b=>-3,g=>5,f=>2}
ab0000000300130000000d00
ab0000000300130000000d00
ab0000000300130000000d00
ab0000000300130000000d00
-
{e=>'UE2',a=>0,d=>4,c=>-3,h=>2,b=>1,g=>2,f=>7}
4801000004003a0000001200
4801000004003a0000001200
4801000004003a0000001200
4801000004003a0000001200
-
{e=>'UE4',a=>2,d=>3,c=>0,h=>-1,b=>-1,g=>2,f=>4}
3a0000000300240000003a00
3a0000000300240000003a00
3a0000000300240000003a00
3a0000000300240000003a00
-
{e=>'UE5',a=>5,d=>7,c=>0,h=>-1,b=>3,g=>1,f=>1}
1d00000007000d0000003900
1d00000007000d0000003900
1d00000007000d0000003900
1d00000007000d0000003900
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
};
-
{e=>'UE4',a=>1,d=>7,c=>-3,h=>0,b=>-4,g=>4,f=>3,i=>'SEM2'}
6101000007001c000000040006000000
6101000007001c000000040006000000
6101000007001c000000040006000000
6101000007001c000000040006000000
-
{e=>'UE0',a=>0,d=>3,c=>1,h=>0,b=>-3,g=>6,f=>6,i=>'SE3'}
68000000030030000000060003000000
68000000030030000000060003000000
68000000030030000000060003000000
68000000030030000000060003000000
-
{e=>'UE5',a=>0,d=>1,c=>-2,h=>2,b=>0,g=>6,f=>0,i=>'SE3'}
80010000010005000000160003000000
80010000010005000000160003000000
80010000010005000000160003000000
80010000010005000000160003000000
-
{e=>'UE7',a=>5,d=>4,c=>-3,h=>-1,b=>2,g=>5,f=>6,i=>'SE2'}
550100000400370000003d0002000000
550100000400370000003d0002000000
550100000400370000003d0002000000
550100000400370000003d0002000000
-
{e=>'UE4',a=>6,d=>1,c=>-1,h=>2,b=>-3,g=>5,f=>1,i=>'SEM4'}
ee01000001000c000000150004000000
ee01000001000c000000150004000000
ee01000001000c000000150004000000
ee01000001000c000000150004000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
  char          j;
};
-
{e=>'UE2',a=>3,d=>3,j=>79,c=>-1,h=>-3,b=>2,g=>4,f=>1,i=>'SE3'}
d301000003000a0000002c00030000004f00
d301000003000a0000002c00030000004f00
d301000003000a0000002c00030000004f00
d301000003000a0000002c00030000004f00
-
{e=>'UE3',a=>4,d=>5,j=>33,c=>-2,h=>-4,b=>-1,g=>7,f=>7,i=>'SEM3'}
bc01000005003b0000002700050000002100
bc01000005003b0000002700050000002100
bc01000005003b0000002700050000002100
bc01000005003b0000002700050000002100
-
{e=>'UE3',a=>2,d=>6,j=>127,c=>-1,h=>1,b=>0,g=>1,f=>5,i=>'SEM1'}
c201000006002b0000000900070000007f00
c201000006002b0000000900070000007f00
c201000006002b0000000900070000007f00
c201000006002b0000000900070000007f00
-
{e=>'UE7',a=>4,d=>1,j=>84,c=>2,h=>-3,b=>3,g=>7,f=>0,i=>'SEM1'}
9c0000000100070000002f00070000005400
9c0000000100070000002f00070000005400
9c0000000100070000002f00070000005400
9c0000000100070000002f00070000005400
-
{e=>'UE6',a=>1,d=>7,j=>37,c=>2,h=>-2,b=>0,g=>3,f=>5,i=>'SE3'}
8100000007002e0000003300030000002500
8100000007002e0000003300030000002500
8100000007002e0000003300030000002500
8100000007002e0000003300030000002500
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
  char          j;
  unsigned char k:3;
};
-
{e=>'UE0',a=>7,d=>4,j=>-44,c=>0,k=>0,h=>0,b=>2,g=>5,f=>1,i=>'SEM4'}
17000000040008000000050004000000d400
17000000040008000000050004000000d400
17000000040008000000050004000000d400
17000000040008000000050004000000d400
-
{e=>'UE6',a=>0,d=>4,j=>-58,c=>2,k=>1,h=>1,b=>-2,g=>2,f=>3,i=>'SEM3'}
b000000004001e0000000a0005000000c601
b000000004001e0000000a0005000000c601
b000000004001e0000000a0005000000c601
b000000004001e0000000a0005000000c601
-
{e=>'UE7',a=>0,d=>4,j=>-25,c=>-4,k=>2,h=>-4,b=>1,g=>6,f=>3,i=>'SEM1'}
0801000004001f000000260007000000e702
0801000004001f000000260007000000e702
0801000004001f000000260007000000e702
0801000004001f000000260007000000e702
-
{e=>'UE0',a=>0,d=>5,j=>87,c=>2,k=>4,h=>1,b=>2,g=>5,f=>4,i=>'SEM2'}
900000000500200000000d00060000005704
900000000500200000000d00060000005704
900000000500200000000d00060000005704
900000000500200000000d00060000005704
-
{e=>'UE3',a=>6,d=>5,j=>-127,c=>0,k=>4,h=>2,b=>-3,g=>7,f=>6,i=>'SE0'}
2e0000000500330000001700000000008104
2e0000000500330000001700000000008104
2e0000000500330000001700000000008104
2e0000000500330000001700000000008104
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
};
-
{e=>'UE1',a=>5,d=>7,j=>116,l=>-1,c=>2,k=>3,h=>-4,b=>0,g=>0,f=>1,i=>'SE3'}
85000000070009000000200003000000743b
85000000070009000000200003000000743b
85000000070009000000200003000000743b
85000000070009000000200003000000743b
-
{e=>'UE0',a=>3,d=>5,j=>-63,l=>3,c=>-4,k=>7,h=>2,b=>0,g=>1,f=>1,i=>'SEM2'}
03010000050008000000110006000000c11f
03010000050008000000110006000000c11f
03010000050008000000110006000000c11f
03010000050008000000110006000000c11f
-
{e=>'UE1',a=>6,d=>3,j=>-79,l=>1,c=>2,k=>1,h=>-2,b=>-4,g=>5,f=>0,i=>'SE0'}
a6000000030001000000350000000000b109
a6000000030001000000350000000000b109
a6000000030001000000350000000000b109
a6000000030001000000350000000000b109
-
{e=>'UE1',a=>4,d=>5,j=>7,l=>2,c=>-2,k=>4,h=>-4,b=>-2,g=>3,f=>7,i=>'SE1'}
b40100000500390000002300010000000714
b40100000500390000002300010000000714
b40100000500390000002300010000000714
b40100000500390000002300010000000714
-
{e=>'UE2',a=>5,d=>0,j=>41,l=>-2,c=>-4,k=>4,h=>-1,b=>3,g=>5,f=>4,i=>'SEM2'}
1d0100000000220000003d00060000002934
1d0100000000220000003d00060000002934
1d0100000000220000003d00060000002934
1d0100000000220000003d00060000002934
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
  unsigned int  m:3;
};
-
{e=>'UE1',a=>1,m=>3,d=>5,j=>80,l=>-4,c=>-4,k=>7,h=>-2,b=>1,g=>5,f=>1,i=>'SEM4'}
09010000050009000000350004000000502703000000
09010000050009000000350004000000502703000000
09010000050009000000350004000000502703000000
09010000050009000000350004000000502703000000
-
{e=>'UE0',a=>3,m=>1,d=>7,j=>-49,l=>-4,c=>-3,k=>5,h=>0,b=>-1,g=>3,f=>5,i=>'SEM4'}
7b010000070028000000030004000000cf2501000000
7b010000070028000000030004000000cf2501000000
7b010000070028000000030004000000cf2501000000
7b010000070028000000030004000000cf2501000000
-
{e=>'UE5',a=>3,m=>7,d=>7,j=>100,l=>-4,c=>1,k=>4,h=>0,b=>-3,g=>1,f=>7,i=>'SE3'}
6b00000007003d000000010003000000642407000000
6b00000007003d000000010003000000642407000000
6b00000007003d000000010003000000642407000000
6b00000007003d000000010003000000642407000000
-
{e=>'UE5',a=>7,m=>2,d=>0,j=>-111,l=>1,c=>2,k=>6,h=>0,b=>0,g=>4,f=>7,i=>'SEM3'}
8700000000003d000000040005000000910e02000000
8700000000003d000000040005000000910e02000000
8700000000003d000000040005000000910e02000000
8700000000003d000000040005000000910e02000000
-
{e=>'UE1',a=>6,m=>1,d=>3,j=>78,l=>-2,c=>-2,k=>1,h=>-3,b=>3,g=>4,f=>5,i=>'SE0'}
9e0100000300290000002c00000000004e3101000000
9e0100000300290000002c00000000004e3101000000
9e0100000300290000002c00000000004e3101000000
9e0100000300290000002c00000000004e3101000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  unsigned int  a:3;
  signed   int  b:3;
  foo           c:3;
  unsigned char d:3;
  enum en_u     e:3;
  unsigned int  f:3;
  int            :0;
  unsigned char g:3;
  signed   char h:3;
  enum en_s     i:3;
  char          j;
  unsigned char k:3;
  signed   char l:3;
  unsigned int  m:3;
  unsigned char n;
};
-
{e=>'UE0',n=>164,a=>0,m=>3,d=>1,j=>-21,l=>-4,c=>2,k=>3,h=>-4,b=>1,g=>0,f=>5,i=>'SE2'}
88000000010028000000200002000000eb2303000000a400
88000000010028000000200002000000eb2303000000a400
88000000010028000000200002000000eb2303000000a400
88000000010028000000200002000000eb2303000000a400
-
{e=>'UE6',n=>235,a=>5,m=>3,d=>0,j=>122,l=>0,c=>-2,k=>5,h=>3,b=>-2,g=>6,f=>1,i=>'SEM3'}
b501000000000e0000001e00050000007a0503000000eb00
b501000000000e0000001e00050000007a0503000000eb00
b501000000000e0000001e00050000007a0503000000eb00
b501000000000e0000001e00050000007a0503000000eb00
-
{e=>'UE2',n=>226,a=>5,m=>6,d=>1,j=>0,l=>0,c=>-4,k=>4,h=>3,b=>-2,g=>1,f=>5,i=>'SEM3'}
3501000001002a000000190005000000000406000000e200
3501000001002a000000190005000000000406000000e200
3501000001002a000000190005000000000406000000e200
3501000001002a000000190005000000000406000000e200
-
{e=>'UE4',n=>153,a=>0,m=>7,d=>6,j=>106,l=>-2,c=>1,k=>6,h=>2,b=>2,g=>2,f=>2,i=>'SE3'}
500000000600140000001200030000006a36070000009900
500000000600140000001200030000006a36070000009900
500000000600140000001200030000006a36070000009900
500000000600140000001200030000006a36070000009900
-
{e=>'UE5',n=>143,a=>3,m=>3,d=>4,j=>112,l=>3,c=>1,k=>5,h=>-4,b=>-1,g=>3,f=>7,i=>'SEM4'}
7b00000004003d000000230004000000701d030000008f00
7b00000004003d000000230004000000701d030000008f00
7b00000004003d000000230004000000701d030000008f00
7b00000004003d000000230004000000701d030000008f00
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
};
-
{a=>35,b=>4}
230004000000
230004000000
230004000000
230004000000
-
{a=>-103,b=>7}
990007000000
990007000000
990007000000
990007000000
-
{a=>-90,b=>6}
a60006000000
a60006000000
a60006000000
a60006000000
-
{a=>-77,b=>1}
b30001000000
b30001000000
b30001000000
b30001000000
-
{a=>73,b=>6}
490006000000
490006000000
490006000000
490006000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>-4,a=>8,b=>7}
080027000000
080027000000
080027000000
080027000000
-
{c=>-4,a=>110,b=>2}
6e0022000000
6e0022000000
6e0022000000
6e0022000000
-
{c=>0,a=>-68,b=>0}
bc0000000000
bc0000000000
bc0000000000
bc0000000000
-
{c=>0,a=>7,b=>7}
070007000000
070007000000
070007000000
070007000000
-
{c=>1,a=>-91,b=>5}
a5000d000000
a5000d000000
a5000d000000
a5000d000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-2,a=>-105,b=>7,d=>1}
970077000000
970077000000
970077000000
970077000000
-
{c=>0,a=>68,b=>2,d=>-1}
4400c2010000
4400c2010000
4400c2010000
4400c2010000
-
{c=>3,a=>66,b=>2,d=>-4}
42001a010000
42001a010000
42001a010000
42001a010000
-
{c=>-2,a=>-3,b=>5,d=>2}
fd00b5000000
fd00b5000000
fd00b5000000
fd00b5000000
-
{c=>2,a=>-69,b=>0,d=>2}
bb0090000000
bb0090000000
bb0090000000
bb0090000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>5,c=>-4,a=>-27,b=>0,d=>2}
e500a00000000500
e500a00000000500
e500a00000000500
e500a00000000500
-
{e=>6,c=>-1,a=>67,b=>7,d=>-4}
43003f0100000600
43003f0100000600
43003f0100000600
43003f0100000600
-
{e=>5,c=>-3,a=>-14,b=>5,d=>0}
f2002d0000000500
f2002d0000000500
f2002d0000000500
f2002d0000000500
-
{e=>7,c=>-3,a=>-84,b=>6,d=>0}
ac002e0000000700
ac002e0000000700
ac002e0000000700
ac002e0000000700
-
{e=>4,c=>-1,a=>49,b=>2,d=>-1}
3100fa0100000400
3100fa0100000400
3100fa0100000400
3100fa0100000400
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
};
-
{e=>1,c=>2,a=>83,b=>0,d=>1,f=>'UE5'}
530050000000010005000000
530050000000010005000000
530050000000010005000000
530050000000010005000000
-
{e=>2,c=>-2,a=>-120,b=>2,d=>-3,f=>'UE1'}
880072010000020001000000
880072010000020001000000
880072010000020001000000
880072010000020001000000
-
{e=>7,c=>2,a=>-63,b=>6,d=>-1,f=>'UE4'}
c100d6010000070004000000
c100d6010000070004000000
c100d6010000070004000000
c100d6010000070004000000
-
{e=>3,c=>2,a=>-5,b=>1,d=>-1,f=>'UE3'}
fb00d1010000030003000000
fb00d1010000030003000000
fb00d1010000030003000000
fb00d1010000030003000000
-
{e=>3,c=>-1,a=>107,b=>5,d=>-1,f=>'UE2'}
6b00fd010000030002000000
6b00fd010000030002000000
6b00fd010000030002000000
6b00fd010000030002000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
};
-
{e=>3,c=>-2,a=>0,g=>4,b=>0,d=>2,f=>'UE6'}
0000b0000000030026000000
0000b0000000030026000000
0000b0000000030026000000
0000b0000000030026000000
-
{e=>1,c=>1,a=>30,g=>6,b=>2,d=>-2,f=>'UE4'}
1e008a010000010034000000
1e008a010000010034000000
1e008a010000010034000000
1e008a010000010034000000
-
{e=>6,c=>3,a=>4,g=>1,b=>4,d=>0,f=>'UE7'}
04001c00000006000f000000
04001c00000006000f000000
04001c00000006000f000000
04001c00000006000f000000
-
{e=>7,c=>-1,a=>-95,g=>6,b=>5,d=>1,f=>'UE6'}
a1007d000000070036000000
a1007d000000070036000000
a1007d000000070036000000
a1007d000000070036000000
-
{e=>7,c=>2,a=>-102,g=>2,b=>3,d=>2,f=>'UE3'}
9a0093000000070013000000
9a0093000000070013000000
9a0093000000070013000000
9a0093000000070013000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>2,c=>-3,a=>17,g=>0,b=>7,d=>-4,f=>'UE0'}
11002f010000020000000000
11002f010000020000000000
11002f010000020000000000
11002f010000020000000000
-
{e=>5,c=>1,a=>-35,g=>5,b=>3,d=>0,f=>'UE7'}
dd000b00000005002f000000
dd000b00000005002f000000
dd000b00000005002f000000
dd000b00000005002f000000
-
{e=>3,c=>1,a=>-16,g=>3,b=>3,d=>-4,f=>'UE1'}
f0000b010000030019000000
f0000b010000030019000000
f0000b010000030019000000
f0000b010000030019000000
-
{e=>6,c=>3,a=>-120,g=>6,b=>3,d=>-2,f=>'UE6'}
88009b010000060036000000
88009b010000060036000000
88009b010000060036000000
88009b010000060036000000
-
{e=>6,c=>1,a=>-121,g=>1,b=>7,d=>-4,f=>'UE3'}
87000f01000006000b000000
87000f01000006000b000000
87000f01000006000b000000
87000f01000006000b000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>5,a=>72,d=>-1,c=>-3,h=>1,b=>0,g=>2,f=>'UE5'}
4800e80100000500150000000100
4800e80100000500150000000100
4800e80100000500150000000100
4800e80100000500150000000100
-
{e=>3,a=>-54,d=>1,c=>-4,h=>3,b=>0,g=>2,f=>'UE3'}
ca00600000000300130000000300
ca00600000000300130000000300
ca00600000000300130000000300
ca00600000000300130000000300
-
{e=>0,a=>-29,d=>3,c=>1,h=>1,b=>2,g=>7,f=>'UE1'}
e300ca0000000000390000000100
e300ca0000000000390000000100
e300ca0000000000390000000100
e300ca0000000000390000000100
-
{e=>5,a=>60,d=>-4,c=>3,h=>1,b=>5,g=>1,f=>'UE4'}
3c001d01000005000c0000000100
3c001d01000005000c0000000100
3c001d01000005000c0000000100
3c001d01000005000c0000000100
-
{e=>3,a=>21,d=>1,c=>0,h=>7,b=>2,g=>2,f=>'UE7'}
1500420000000300170000000700
1500420000000300170000000700
1500420000000300170000000700
1500420000000300170000000700
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>3,a=>31,d=>-2,c=>0,h=>4,b=>1,g=>4,f=>'UE7',i=>-3}
1f00810100000300270000002c00
1f00810100000300270000002c00
1f00810100000300270000002c00
1f00810100000300270000002c00
-
{e=>7,a=>-56,d=>-4,c=>0,h=>3,b=>0,g=>6,f=>'UE0',i=>1}
c800000100000700300000000b00
c800000100000700300000000b00
c800000100000700300000000b00
c800000100000700300000000b00
-
{e=>4,a=>-92,d=>3,c=>3,h=>0,b=>7,g=>7,f=>'UE0',i=>-2}
a400df0000000400380000003000
a400df0000000400380000003000
a400df0000000400380000003000
a400df0000000400380000003000
-
{e=>7,a=>27,d=>1,c=>-4,h=>7,b=>6,g=>4,f=>'UE1',i=>1}
1b00660000000700210000000f00
1b00660000000700210000000f00
1b00660000000700210000000f00
1b00660000000700210000000f00
-
{e=>0,a=>-28,d=>1,c=>1,h=>1,b=>2,g=>5,f=>'UE1',i=>2}
e4004a0000000000290000001100
e4004a0000000000290000001100
e4004a0000000000290000001100
e4004a0000000000290000001100
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
};
-
{e=>5,a=>43,d=>-4,j=>'SEM1',c=>-2,h=>5,b=>1,g=>0,f=>'UE6',i=>0}
2b0031010000050006000000050007000000
2b0031010000050006000000050007000000
2b0031010000050006000000050007000000
2b0031010000050006000000050007000000
-
{e=>1,a=>-116,d=>-3,j=>'SE2',c=>-3,h=>4,b=>4,g=>3,f=>'UE6',i=>1}
8c006c01000001001e0000000c0002000000
8c006c01000001001e0000000c0002000000
8c006c01000001001e0000000c0002000000
8c006c01000001001e0000000c0002000000
-
{e=>5,a=>-97,d=>-4,j=>'SE2',c=>0,h=>6,b=>6,g=>2,f=>'UE0',i=>2}
9f0006010000050010000000160002000000
9f0006010000050010000000160002000000
9f0006010000050010000000160002000000
9f0006010000050010000000160002000000
-
{e=>3,a=>-10,d=>0,j=>'SE1',c=>-4,h=>1,b=>4,g=>4,f=>'UE7',i=>-3}
f60024000000030027000000290001000000
f60024000000030027000000290001000000
f60024000000030027000000290001000000
f60024000000030027000000290001000000
-
{e=>0,a=>-83,d=>3,j=>'SEM4',c=>-1,h=>3,b=>7,g=>0,f=>'UE0',i=>2}
ad00ff000000000000000000130004000000
ad00ff000000000000000000130004000000
ad00ff000000000000000000130004000000
ad00ff000000000000000000130004000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
};
-
{e=>4,a=>-72,d=>1,j=>'SEM4',c=>-2,k=>-69,h=>2,b=>2,g=>4,f=>'UE6',i=>-3}
b800720000000400260000002a0004000000bb00
b800720000000400260000002a0004000000bb00
b800720000000400260000002a0004000000bb00
b800720000000400260000002a0004000000bb00
-
{e=>3,a=>-74,d=>3,j=>'SE1',c=>1,k=>-22,h=>7,b=>7,g=>1,f=>'UE4',i=>1}
b600cf00000003000c0000000f0001000000ea00
b600cf00000003000c0000000f0001000000ea00
b600cf00000003000c0000000f0001000000ea00
b600cf00000003000c0000000f0001000000ea00
-
{e=>2,a=>-35,d=>3,j=>'SE0',c=>-3,k=>-17,h=>4,b=>5,g=>0,f=>'UE7',i=>-1}
dd00ed0000000200070000003c0000000000ef00
dd00ed0000000200070000003c0000000000ef00
dd00ed0000000200070000003c0000000000ef00
dd00ed0000000200070000003c0000000000ef00
-
{e=>6,a=>36,d=>-4,j=>'SEM2',c=>-4,k=>-49,h=>0,b=>3,g=>4,f=>'UE3',i=>-2}
240023010000060023000000300006000000cf00
240023010000060023000000300006000000cf00
240023010000060023000000300006000000cf00
240023010000060023000000300006000000cf00
-
{e=>0,a=>34,d=>-3,j=>'SEM2',c=>0,k=>9,h=>2,b=>6,g=>4,f=>'UE3',i=>-1}
2200460100000000230000003a00060000000900
2200460100000000230000003a00060000000900
2200460100000000230000003a00060000000900
2200460100000000230000003a00060000000900
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>7,a=>-52,d=>0,j=>'SE0',l=>6,c=>0,k=>67,h=>4,b=>1,g=>4,f=>'UE1',i=>3}
cc00010000000700210000001c00000000004306
cc00010000000700210000001c00000000004306
cc00010000000700210000001c00000000004306
cc00010000000700210000001c00000000004306
-
{e=>0,a=>104,d=>-4,j=>'SE3',l=>4,c=>1,k=>-98,h=>7,b=>1,g=>2,f=>'UE1',i=>-1}
6800090100000000110000003f00030000009e04
6800090100000000110000003f00030000009e04
6800090100000000110000003f00030000009e04
6800090100000000110000003f00030000009e04
-
{e=>1,a=>88,d=>-1,j=>'SE2',l=>4,c=>-2,k=>51,h=>4,b=>2,g=>4,f=>'UE2',i=>-2}
5800f20100000100220000003400020000003304
5800f20100000100220000003400020000003304
5800f20100000100220000003400020000003304
5800f20100000100220000003400020000003304
-
{e=>2,a=>-81,d=>2,j=>'SE0',l=>2,c=>0,k=>87,h=>1,b=>1,g=>6,f=>'UE4',i=>0}
af00810000000200340000000100000000005702
af00810000000200340000000100000000005702
af00810000000200340000000100000000005702
af00810000000200340000000100000000005702
-
{e=>5,a=>-126,d=>2,j=>'SE3',l=>6,c=>-3,k=>79,h=>0,b=>3,g=>4,f=>'UE4',i=>1}
8200ab0000000500240000000800030000004f06
8200ab0000000500240000000800030000004f06
8200ab0000000500240000000800030000004f06
8200ab0000000500240000000800030000004f06
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>4,a=>-69,m=>2,d=>2,j=>'SE1',l=>1,c=>2,k=>35,h=>6,b=>4,g=>4,f=>'UE5',i=>3}
bb00940000000400250000001e00010000002311
bb00940000000400250000001e00010000002311
bb00940000000400250000001e00010000002311
bb00940000000400250000001e00010000002311
-
{e=>7,a=>87,m=>-2,d=>-4,j=>'SEM4',l=>1,c=>-1,k=>1,h=>7,b=>6,g=>4,f=>'UE4',i=>2}
57003e0100000700240000001700040000000131
57003e0100000700240000001700040000000131
57003e0100000700240000001700040000000131
57003e0100000700240000001700040000000131
-
{e=>6,a=>-102,m=>1,d=>3,j=>'SEM4',l=>2,c=>-4,k=>78,h=>5,b=>7,g=>6,f=>'UE3',i=>-3}
9a00e70000000600330000002d00040000004e0a
9a00e70000000600330000002d00040000004e0a
9a00e70000000600330000002d00040000004e0a
9a00e70000000600330000002d00040000004e0a
-
{e=>0,a=>122,m=>2,d=>-1,j=>'SEM2',l=>4,c=>-1,k=>-59,h=>6,b=>4,g=>0,f=>'UE1',i=>-3}
7a00fc0100000000010000002e0006000000c514
7a00fc0100000000010000002e0006000000c514
7a00fc0100000000010000002e0006000000c514
7a00fc0100000000010000002e0006000000c514
-
{e=>2,a=>91,m=>2,d=>2,j=>'SEM4',l=>2,c=>0,k=>-51,h=>2,b=>4,g=>3,f=>'UE2',i=>3}
5b008400000002001a0000001a0004000000cd12
5b008400000002001a0000001a0004000000cd12
5b008400000002001a0000001a0004000000cd12
5b008400000002001a0000001a0004000000cd12
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>6,n=>0,a=>40,m=>0,d=>-2,j=>'SEM1',l=>4,c=>-3,k=>69,h=>7,b=>4,g=>3,f=>'UE0',i=>-1}
2800ac0100000600180000003f0007000000450400000000
2800ac0100000600180000003f0007000000450400000000
2800ac0100000600180000003f0007000000450400000000
2800ac0100000600180000003f0007000000450400000000
-
{e=>4,n=>6,a=>30,m=>1,d=>3,j=>'SEM1',l=>0,c=>-2,k=>-11,h=>4,b=>6,g=>7,f=>'UE3',i=>-1}
1e00f600000004003b0000003c0007000000f50806000000
1e00f600000004003b0000003c0007000000f50806000000
1e00f600000004003b0000003c0007000000f50806000000
1e00f600000004003b0000003c0007000000f50806000000
-
{e=>7,n=>3,a=>-38,m=>3,d=>2,j=>'SEM4',l=>2,c=>-2,k=>-84,h=>7,b=>7,g=>3,f=>'UE2',i=>3}
da00b700000007001a0000001f0004000000ac1a03000000
da00b700000007001a0000001f0004000000ac1a03000000
da00b700000007001a0000001f0004000000ac1a03000000
da00b700000007001a0000001f0004000000ac1a03000000
-
{e=>0,n=>3,a=>39,m=>0,d=>1,j=>'SEM3',l=>7,c=>3,k=>-120,h=>5,b=>2,g=>6,f=>'UE2',i=>3}
27005a0000000000320000001d0005000000880703000000
27005a0000000000320000001d0005000000880703000000
27005a0000000000320000001d0005000000880703000000
27005a0000000000320000001d0005000000880703000000
-
{e=>5,n=>5,a=>-10,m=>-4,d=>-1,j=>'SEM3',l=>5,c=>0,k=>23,h=>7,b=>0,g=>7,f=>'UE7',i=>0}
f600c001000005003f000000070005000000172505000000
f600c001000005003f000000070005000000172505000000
f600c001000005003f000000070005000000172505000000
f600c001000005003f000000070005000000172505000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  char a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>2,n=>4,a=>-49,m=>-4,d=>-2,j=>'SE3',l=>1,c=>0,k=>-90,h=>0,b=>3,g=>1,f=>'UE1',o=>232,i=>1}
cf0083010000020009000000080003000000a62104000000e800
cf0083010000020009000000080003000000a62104000000e800
cf0083010000020009000000080003000000a62104000000e800
cf0083010000020009000000080003000000a62104000000e800
-
{e=>6,n=>2,a=>4,m=>1,d=>3,j=>'SEM2',l=>1,c=>1,k=>-19,h=>7,b=>4,g=>3,f=>'UE0',o=>88,i=>1}
0400cc0000000600180000000f0006000000ed09020000005800
0400cc0000000600180000000f0006000000ed09020000005800
0400cc0000000600180000000f0006000000ed09020000005800
0400cc0000000600180000000f0006000000ed09020000005800
-
{e=>4,n=>7,a=>61,m=>0,d=>2,j=>'SE1',l=>6,c=>-1,k=>113,h=>2,b=>6,g=>5,f=>'UE6',o=>234,i=>2}
3d00be00000004002e000000120001000000710607000000ea00
3d00be00000004002e000000120001000000710607000000ea00
3d00be00000004002e000000120001000000710607000000ea00
3d00be00000004002e000000120001000000710607000000ea00
-
{e=>1,n=>0,a=>-69,m=>-2,d=>2,j=>'SE0',l=>0,c=>0,k=>38,h=>4,b=>5,g=>1,f=>'UE6',o=>145,i=>-2}
bb008500000001000e0000003400000000002630000000009100
bb008500000001000e0000003400000000002630000000009100
bb008500000001000e0000003400000000002630000000009100
bb008500000001000e0000003400000000002630000000009100
-
{e=>3,n=>2,a=>-1,m=>-1,d=>2,j=>'SEM3',l=>1,c=>1,k=>-52,h=>3,b=>1,g=>2,f=>'UE1',o=>195,i=>-3}
ff00890000000300110000002b0005000000cc3902000000c300
ff00890000000300110000002b0005000000cc3902000000c300
ff00890000000300110000002b0005000000cc3902000000c300
ff00890000000300110000002b0005000000cc3902000000c300
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
};
-
{a=>-117,b=>5}
8bff05000000
8bff05000000
8bff05000000
8bff05000000
-
{a=>72,b=>7}
480007000000
480007000000
480007000000
480007000000
-
{a=>10,b=>5}
0a0005000000
0a0005000000
0a0005000000
0a0005000000
-
{a=>-60,b=>2}
c4ff02000000
c4ff02000000
c4ff02000000
c4ff02000000
-
{a=>-76,b=>6}
b4ff06000000
b4ff06000000
b4ff06000000
b4ff06000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>-4,a=>-67,b=>0}
bdff20000000
bdff20000000
bdff20000000
bdff20000000
-
{c=>-3,a=>-101,b=>6}
9bff2e000000
9bff2e000000
9bff2e000000
9bff2e000000
-
{c=>2,a=>-19,b=>7}
edff17000000
edff17000000
edff17000000
edff17000000
-
{c=>-2,a=>92,b=>7}
5c0037000000
5c0037000000
5c0037000000
5c0037000000
-
{c=>3,a=>46,b=>7}
2e001f000000
2e001f000000
2e001f000000
2e001f000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-4,a=>79,b=>0,d=>0}
4f0020000000
4f0020000000
4f0020000000
4f0020000000
-
{c=>-3,a=>93,b=>4,d=>0}
5d002c000000
5d002c000000
5d002c000000
5d002c000000
-
{c=>-3,a=>-14,b=>5,d=>-1}
f2ffed010000
f2ffed010000
f2ffed010000
f2ffed010000
-
{c=>0,a=>-47,b=>4,d=>-4}
d1ff04010000
d1ff04010000
d1ff04010000
d1ff04010000
-
{c=>2,a=>-7,b=>5,d=>2}
f9ff95000000
f9ff95000000
f9ff95000000
f9ff95000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>6,c=>-1,a=>-71,b=>2,d=>0}
b9ff3a0000000600
b9ff3a0000000600
b9ff3a0000000600
b9ff3a0000000600
-
{e=>0,c=>-1,a=>-25,b=>1,d=>3}
e7fff90000000000
e7fff90000000000
e7fff90000000000
e7fff90000000000
-
{e=>0,c=>0,a=>-15,b=>4,d=>-4}
f1ff040100000000
f1ff040100000000
f1ff040100000000
f1ff040100000000
-
{e=>6,c=>-1,a=>26,b=>6,d=>-3}
1a007e0100000600
1a007e0100000600
1a007e0100000600
1a007e0100000600
-
{e=>7,c=>3,a=>-24,b=>1,d=>2}
e8ff990000000700
e8ff990000000700
e8ff990000000700
e8ff990000000700
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
};
-
{e=>2,c=>-3,a=>-20,b=>5,d=>3,f=>'UE1'}
ecffed000000020001000000
ecffed000000020001000000
ecffed000000020001000000
ecffed000000020001000000
-
{e=>1,c=>2,a=>47,b=>6,d=>2,f=>'UE3'}
2f0096000000010003000000
2f0096000000010003000000
2f0096000000010003000000
2f0096000000010003000000
-
{e=>6,c=>1,a=>16,b=>5,d=>0,f=>'UE7'}
10000d000000060007000000
10000d000000060007000000
10000d000000060007000000
10000d000000060007000000
-
{e=>6,c=>-2,a=>102,b=>5,d=>2,f=>'UE1'}
6600b5000000060001000000
6600b5000000060001000000
6600b5000000060001000000
6600b5000000060001000000
-
{e=>3,c=>-3,a=>-74,b=>2,d=>-4,f=>'UE7'}
b6ff2a010000030007000000
b6ff2a010000030007000000
b6ff2a010000030007000000
b6ff2a010000030007000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
};
-
{e=>5,c=>3,a=>65,g=>2,b=>7,d=>0,f=>'UE3'}
41001f000000050013000000
41001f000000050013000000
41001f000000050013000000
41001f000000050013000000
-
{e=>1,c=>-1,a=>17,g=>4,b=>3,d=>3,f=>'UE4'}
1100fb000000010024000000
1100fb000000010024000000
1100fb000000010024000000
1100fb000000010024000000
-
{e=>0,c=>1,a=>100,g=>1,b=>1,d=>1,f=>'UE5'}
64004900000000000d000000
64004900000000000d000000
64004900000000000d000000
64004900000000000d000000
-
{e=>5,c=>1,a=>90,g=>5,b=>1,d=>3,f=>'UE4'}
5a00c900000005002c000000
5a00c900000005002c000000
5a00c900000005002c000000
5a00c900000005002c000000
-
{e=>5,c=>3,a=>-34,g=>1,b=>7,d=>1,f=>'UE7'}
deff5f00000005000f000000
deff5f00000005000f000000
deff5f00000005000f000000
deff5f00000005000f000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>6,c=>-1,a=>-29,g=>4,b=>0,d=>0,f=>'UE0'}
e3ff38000000060020000000
e3ff38000000060020000000
e3ff38000000060020000000
e3ff38000000060020000000
-
{e=>4,c=>1,a=>-112,g=>5,b=>1,d=>-4,f=>'UE6'}
90ff0901000004002e000000
90ff0901000004002e000000
90ff0901000004002e000000
90ff0901000004002e000000
-
{e=>4,c=>-1,a=>-66,g=>1,b=>4,d=>2,f=>'UE0'}
beffbc000000040008000000
beffbc000000040008000000
beffbc000000040008000000
beffbc000000040008000000
-
{e=>7,c=>-3,a=>-106,g=>5,b=>5,d=>-1,f=>'UE2'}
96ffed01000007002a000000
96ffed01000007002a000000
96ffed01000007002a000000
96ffed01000007002a000000
-
{e=>7,c=>3,a=>-85,g=>4,b=>5,d=>-1,f=>'UE5'}
abffdd010000070025000000
abffdd010000070025000000
abffdd010000070025000000
abffdd010000070025000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>1,a=>-70,d=>3,c=>-2,h=>1,b=>7,g=>0,f=>'UE6'}
bafff70000000100060000000100
bafff70000000100060000000100
bafff70000000100060000000100
bafff70000000100060000000100
-
{e=>3,a=>16,d=>-2,c=>1,h=>1,b=>3,g=>7,f=>'UE2'}
10008b01000003003a0000000100
10008b01000003003a0000000100
10008b01000003003a0000000100
10008b01000003003a0000000100
-
{e=>7,a=>34,d=>-3,c=>-1,h=>3,b=>1,g=>4,f=>'UE6'}
2200790100000700260000000300
2200790100000700260000000300
2200790100000700260000000300
2200790100000700260000000300
-
{e=>1,a=>15,d=>-3,c=>-1,h=>6,b=>7,g=>7,f=>'UE0'}
0f007f0100000100380000000600
0f007f0100000100380000000600
0f007f0100000100380000000600
0f007f0100000100380000000600
-
{e=>5,a=>120,d=>0,c=>3,h=>7,b=>7,g=>0,f=>'UE4'}
78001f0000000500040000000700
78001f0000000500040000000700
78001f0000000500040000000700
78001f0000000500040000000700
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>7,a=>110,d=>1,c=>0,h=>3,b=>1,g=>7,f=>'UE3',i=>-3}
6e004100000007003b0000002b00
6e004100000007003b0000002b00
6e004100000007003b0000002b00
6e004100000007003b0000002b00
-
{e=>4,a=>-31,d=>-2,c=>-4,h=>0,b=>7,g=>7,f=>'UE7',i=>-2}
e1ffa701000004003f0000003000
e1ffa701000004003f0000003000
e1ffa701000004003f0000003000
e1ffa701000004003f0000003000
-
{e=>6,a=>64,d=>2,c=>-1,h=>4,b=>3,g=>5,f=>'UE5',i=>-3}
4000bb00000006002d0000002c00
4000bb00000006002d0000002c00
4000bb00000006002d0000002c00
4000bb00000006002d0000002c00
-
{e=>5,a=>100,d=>1,c=>3,h=>5,b=>4,g=>4,f=>'UE2',i=>-1}
64005c0000000500220000003d00
64005c0000000500220000003d00
64005c0000000500220000003d00
64005c0000000500220000003d00
-
{e=>5,a=>-124,d=>-4,c=>-2,h=>6,b=>1,g=>4,f=>'UE4',i=>2}
84ff310100000500240000001600
84ff310100000500240000001600
84ff310100000500240000001600
84ff310100000500240000001600
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
};
-
{e=>6,a=>-89,d=>2,j=>'SE2',c=>0,h=>7,b=>2,g=>7,f=>'UE6',i=>-4}
a7ff8200000006003e000000270002000000
a7ff8200000006003e000000270002000000
a7ff8200000006003e000000270002000000
a7ff8200000006003e000000270002000000
-
{e=>6,a=>63,d=>-2,j=>'SEM1',c=>-4,h=>2,b=>6,g=>6,f=>'UE0',i=>-1}
3f00a60100000600300000003a0007000000
3f00a60100000600300000003a0007000000
3f00a60100000600300000003a0007000000
3f00a60100000600300000003a0007000000
-
{e=>4,a=>93,d=>-4,j=>'SE2',c=>3,h=>7,b=>5,g=>7,f=>'UE7',i=>-1}
5d001d01000004003f0000003f0002000000
5d001d01000004003f0000003f0002000000
5d001d01000004003f0000003f0002000000
5d001d01000004003f0000003f0002000000
-
{e=>4,a=>-43,d=>0,j=>'SE3',c=>-2,h=>1,b=>7,g=>6,f=>'UE6',i=>-1}
d5ff37000000040036000000390003000000
d5ff37000000040036000000390003000000
d5ff37000000040036000000390003000000
d5ff37000000040036000000390003000000
-
{e=>1,a=>21,d=>2,j=>'SEM3',c=>-3,h=>0,b=>6,g=>4,f=>'UE4',i=>-2}
1500ae000000010024000000300005000000
1500ae000000010024000000300005000000
1500ae000000010024000000300005000000
1500ae000000010024000000300005000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
};
-
{e=>4,a=>124,d=>-1,j=>'SE2',c=>2,k=>-23,h=>7,b=>1,g=>2,f=>'UE4',i=>0}
7c00d1010000040014000000070002000000e900
7c00d1010000040014000000070002000000e900
7c00d1010000040014000000070002000000e900
7c00d1010000040014000000070002000000e900
-
{e=>6,a=>-50,d=>-3,j=>'SE2',c=>-3,k=>-66,h=>3,b=>5,g=>2,f=>'UE5',i=>1}
ceff6d0100000600150000000b0002000000be00
ceff6d0100000600150000000b0002000000be00
ceff6d0100000600150000000b0002000000be00
ceff6d0100000600150000000b0002000000be00
-
{e=>4,a=>31,d=>2,j=>'SEM1',c=>-4,k=>-117,h=>1,b=>4,g=>3,f=>'UE5',i=>0}
1f00a400000004001d0000000100070000008b00
1f00a400000004001d0000000100070000008b00
1f00a400000004001d0000000100070000008b00
1f00a400000004001d0000000100070000008b00
-
{e=>0,a=>-107,d=>0,j=>'SEM4',c=>-3,k=>8,h=>7,b=>7,g=>5,f=>'UE5',i=>-1}
95ff2f00000000002d0000003f00040000000800
95ff2f00000000002d0000003f00040000000800
95ff2f00000000002d0000003f00040000000800
95ff2f00000000002d0000003f00040000000800
-
{e=>7,a=>-5,d=>1,j=>'SEM4',c=>1,k=>71,h=>4,b=>2,g=>6,f=>'UE1',i=>2}
fbff4a0000000700310000001400040000004700
fbff4a0000000700310000001400040000004700
fbff4a0000000700310000001400040000004700
fbff4a0000000700310000001400040000004700
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>2,a=>-31,d=>2,j=>'SE1',l=>0,c=>2,k=>75,h=>7,b=>1,g=>0,f=>'UE1',i=>2}
e1ff910000000200010000001700010000004b00
e1ff910000000200010000001700010000004b00
e1ff910000000200010000001700010000004b00
e1ff910000000200010000001700010000004b00
-
{e=>2,a=>-101,d=>-3,j=>'SEM4',l=>4,c=>-4,k=>-56,h=>0,b=>2,g=>1,f=>'UE0',i=>-3}
9bff62010000020008000000280004000000c804
9bff62010000020008000000280004000000c804
9bff62010000020008000000280004000000c804
9bff62010000020008000000280004000000c804
-
{e=>7,a=>79,d=>1,j=>'SE2',l=>0,c=>-4,k=>87,h=>0,b=>7,g=>2,f=>'UE6',i=>-1}
4f00670000000700160000003800020000005700
4f00670000000700160000003800020000005700
4f00670000000700160000003800020000005700
4f00670000000700160000003800020000005700
-
{e=>1,a=>44,d=>1,j=>'SE0',l=>3,c=>2,k=>97,h=>7,b=>5,g=>3,f=>'UE5',i=>3}
2c005500000001001d0000001f00000000006103
2c005500000001001d0000001f00000000006103
2c005500000001001d0000001f00000000006103
2c005500000001001d0000001f00000000006103
-
{e=>3,a=>59,d=>2,j=>'SEM3',l=>5,c=>2,k=>-17,h=>0,b=>4,g=>3,f=>'UE4',i=>1}
3b009400000003001c000000080005000000ef05
3b009400000003001c000000080005000000ef05
3b009400000003001c000000080005000000ef05
3b009400000003001c000000080005000000ef05
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>0,a=>54,m=>-4,d=>2,j=>'SE2',l=>1,c=>1,k=>91,h=>0,b=>5,g=>5,f=>'UE5',i=>2}
36008d00000000002d0000001000020000005b21
36008d00000000002d0000001000020000005b21
36008d00000000002d0000001000020000005b21
36008d00000000002d0000001000020000005b21
-
{e=>6,a=>-109,m=>-4,d=>1,j=>'SEM1',l=>4,c=>-2,k=>111,h=>7,b=>7,g=>7,f=>'UE7',i=>0}
93ff7700000006003f0000000700070000006f24
93ff7700000006003f0000000700070000006f24
93ff7700000006003f0000000700070000006f24
93ff7700000006003f0000000700070000006f24
-
{e=>4,a=>-18,m=>-1,d=>-2,j=>'SEM4',l=>7,c=>3,k=>-106,h=>2,b=>6,g=>7,f=>'UE1',i=>-4}
eeff9e010000040039000000220004000000963f
eeff9e010000040039000000220004000000963f
eeff9e010000040039000000220004000000963f
eeff9e010000040039000000220004000000963f
-
{e=>5,a=>77,m=>1,d=>1,j=>'SE2',l=>6,c=>-2,k=>-38,h=>5,b=>1,g=>6,f=>'UE2',i=>3}
4d00710000000500320000001d0002000000da0e
4d00710000000500320000001d0002000000da0e
4d00710000000500320000001d0002000000da0e
4d00710000000500320000001d0002000000da0e
-
{e=>2,a=>63,m=>2,d=>0,j=>'SEM4',l=>4,c=>-3,k=>-13,h=>0,b=>2,g=>5,f=>'UE6',i=>2}
3f002a00000002002e000000100004000000f314
3f002a00000002002e000000100004000000f314
3f002a00000002002e000000100004000000f314
3f002a00000002002e000000100004000000f314
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>7,n=>1,a=>6,m=>2,d=>-1,j=>'SEM1',l=>4,c=>3,k=>-96,h=>7,b=>7,g=>2,f=>'UE0',i=>-2}
0600df010000070010000000370007000000a01401000000
0600df010000070010000000370007000000a01401000000
0600df010000070010000000370007000000a01401000000
0600df010000070010000000370007000000a01401000000
-
{e=>1,n=>3,a=>-28,m=>0,d=>1,j=>'SEM4',l=>5,c=>-2,k=>118,h=>2,b=>1,g=>1,f=>'UE1',i=>-2}
e4ff71000000010009000000320004000000760503000000
e4ff71000000010009000000320004000000760503000000
e4ff71000000010009000000320004000000760503000000
e4ff71000000010009000000320004000000760503000000
-
{e=>6,n=>5,a=>125,m=>-4,d=>1,j=>'SEM1',l=>3,c=>-1,k=>1,h=>5,b=>7,g=>6,f=>'UE6',i=>-1}
7d007f0000000600360000003d0007000000012305000000
7d007f0000000600360000003d0007000000012305000000
7d007f0000000600360000003d0007000000012305000000
7d007f0000000600360000003d0007000000012305000000
-
{e=>3,n=>1,a=>4,m=>-4,d=>-3,j=>'SE1',l=>5,c=>-4,k=>82,h=>7,b=>3,g=>0,f=>'UE5',i=>-4}
040063010000030005000000270001000000522501000000
040063010000030005000000270001000000522501000000
040063010000030005000000270001000000522501000000
040063010000030005000000270001000000522501000000
-
{e=>4,n=>7,a=>98,m=>1,d=>1,j=>'SE2',l=>5,c=>-3,k=>-32,h=>6,b=>2,g=>3,f=>'UE5',i=>1}
62006a00000004001d0000000e0002000000e00d07000000
62006a00000004001d0000000e0002000000e00d07000000
62006a00000004001d0000000e0002000000e00d07000000
62006a00000004001d0000000e0002000000e00d07000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  short a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>5,n=>6,a=>-72,m=>-2,d=>-3,j=>'SEM1',l=>0,c=>1,k=>95,h=>2,b=>5,g=>7,f=>'UE0',o=>120,i=>-3}
b8ff4d0100000500380000002a00070000005f30060000007800
b8ff4d0100000500380000002a00070000005f30060000007800
b8ff4d0100000500380000002a00070000005f30060000007800
b8ff4d0100000500380000002a00070000005f30060000007800
-
{e=>2,n=>0,a=>-69,m=>-1,d=>0,j=>'SE0',l=>0,c=>1,k=>-105,h=>7,b=>6,g=>0,f=>'UE1',o=>44,i=>2}
bbff0e0000000200010000001700000000009738000000002c00
bbff0e0000000200010000001700000000009738000000002c00
bbff0e0000000200010000001700000000009738000000002c00
bbff0e0000000200010000001700000000009738000000002c00
-
{e=>0,n=>5,a=>94,m=>-3,d=>-2,j=>'SEM3',l=>4,c=>-1,k=>53,h=>7,b=>4,g=>7,f=>'UE3',o=>232,i=>3}
5e00bc01000000003b0000001f0005000000352c05000000e800
5e00bc01000000003b0000001f0005000000352c05000000e800
5e00bc01000000003b0000001f0005000000352c05000000e800
5e00bc01000000003b0000001f0005000000352c05000000e800
-
{e=>1,n=>0,a=>112,m=>-1,d=>-3,j=>'SE3',l=>4,c=>-2,k=>50,h=>1,b=>4,g=>7,f=>'UE6',o=>103,i=>1}
70007401000001003e000000090003000000323c000000006700
70007401000001003e000000090003000000323c000000006700
70007401000001003e000000090003000000323c000000006700
70007401000001003e000000090003000000323c000000006700
-
{e=>7,n=>6,a=>-116,m=>1,d=>3,j=>'SEM1',l=>3,c=>0,k=>117,h=>5,b=>5,g=>7,f=>'UE0',o=>207,i=>-1}
8cffc50000000700380000003d0007000000750b06000000cf00
8cffc50000000700380000003d0007000000750b06000000cf00
8cffc50000000700380000003d0007000000750b06000000cf00
8cffc50000000700380000003d0007000000750b06000000cf00
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
};
-
{a=>59,b=>6}
3b00000006000000
3b00000006000000
3b00000006000000
3b00000006000000
-
{a=>-72,b=>6}
b8ffffff06000000
b8ffffff06000000
b8ffffff06000000
b8ffffff06000000
-
{a=>-11,b=>2}
f5ffffff02000000
f5ffffff02000000
f5ffffff02000000
f5ffffff02000000
-
{a=>-120,b=>5}
88ffffff05000000
88ffffff05000000
88ffffff05000000
88ffffff05000000
-
{a=>16,b=>4}
1000000004000000
1000000004000000
1000000004000000
1000000004000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>-4,a=>-6,b=>5}
faffffff25000000
faffffff25000000
faffffff25000000
faffffff25000000
-
{c=>2,a=>-12,b=>0}
f4ffffff10000000
f4ffffff10000000
f4ffffff10000000
f4ffffff10000000
-
{c=>-1,a=>-6,b=>7}
faffffff3f000000
faffffff3f000000
faffffff3f000000
faffffff3f000000
-
{c=>-3,a=>126,b=>1}
7e00000029000000
7e00000029000000
7e00000029000000
7e00000029000000
-
{c=>-2,a=>3,b=>2}
0300000032000000
0300000032000000
0300000032000000
0300000032000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-3,a=>6,b=>4,d=>1}
060000006c000000
060000006c000000
060000006c000000
060000006c000000
-
{c=>2,a=>-111,b=>6,d=>-3}
91ffffff56010000
91ffffff56010000
91ffffff56010000
91ffffff56010000
-
{c=>1,a=>-80,b=>4,d=>-3}
b0ffffff4c010000
b0ffffff4c010000
b0ffffff4c010000
b0ffffff4c010000
-
{c=>3,a=>54,b=>4,d=>0}
360000001c000000
360000001c000000
360000001c000000
360000001c000000
-
{c=>-1,a=>-73,b=>5,d=>-4}
b7ffffff3d010000
b7ffffff3d010000
b7ffffff3d010000
b7ffffff3d010000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>1,c=>-2,a=>59,b=>4,d=>1}
3b000000740000000100
3b000000740000000100
3b000000740000000100
3b000000740000000100
-
{e=>4,c=>3,a=>-20,b=>1,d=>-3}
ecffffff590100000400
ecffffff590100000400
ecffffff590100000400
ecffffff590100000400
-
{e=>3,c=>-4,a=>59,b=>0,d=>-2}
3b000000a00100000300
3b000000a00100000300
3b000000a00100000300
3b000000a00100000300
-
{e=>5,c=>-4,a=>-67,b=>2,d=>2}
bdffffffa20000000500
bdffffffa20000000500
bdffffffa20000000500
bdffffffa20000000500
-
{e=>7,c=>1,a=>-13,b=>2,d=>2}
f3ffffff8a0000000700
f3ffffff8a0000000700
f3ffffff8a0000000700
f3ffffff8a0000000700
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
};
-
{e=>4,c=>3,a=>-90,b=>0,d=>-4,f=>'UE5'}
a6ffffff18010000040005000000
a6ffffff18010000040005000000
a6ffffff18010000040005000000
a6ffffff18010000040005000000
-
{e=>4,c=>-3,a=>-120,b=>6,d=>-4,f=>'UE3'}
88ffffff2e010000040003000000
88ffffff2e010000040003000000
88ffffff2e010000040003000000
88ffffff2e010000040003000000
-
{e=>2,c=>2,a=>94,b=>0,d=>-1,f=>'UE7'}
5e000000d0010000020007000000
5e000000d0010000020007000000
5e000000d0010000020007000000
5e000000d0010000020007000000
-
{e=>7,c=>2,a=>51,b=>2,d=>0,f=>'UE3'}
3300000012000000070003000000
3300000012000000070003000000
3300000012000000070003000000
3300000012000000070003000000
-
{e=>1,c=>-1,a=>74,b=>1,d=>1,f=>'UE6'}
4a00000079000000010006000000
4a00000079000000010006000000
4a00000079000000010006000000
4a00000079000000010006000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
};
-
{e=>2,c=>3,a=>-102,g=>2,b=>7,d=>2,f=>'UE1'}
9affffff9f000000020011000000
9affffff9f000000020011000000
9affffff9f000000020011000000
9affffff9f000000020011000000
-
{e=>5,c=>0,a=>55,g=>0,b=>3,d=>1,f=>'UE1'}
3700000043000000050001000000
3700000043000000050001000000
3700000043000000050001000000
3700000043000000050001000000
-
{e=>7,c=>0,a=>-113,g=>0,b=>6,d=>-2,f=>'UE1'}
8fffffff86010000070001000000
8fffffff86010000070001000000
8fffffff86010000070001000000
8fffffff86010000070001000000
-
{e=>3,c=>3,a=>56,g=>5,b=>5,d=>-1,f=>'UE3'}
38000000dd01000003002b000000
38000000dd01000003002b000000
38000000dd01000003002b000000
38000000dd01000003002b000000
-
{e=>4,c=>-2,a=>-74,g=>2,b=>3,d=>-1,f=>'UE4'}
b6fffffff3010000040014000000
b6fffffff3010000040014000000
b6fffffff3010000040014000000
b6fffffff3010000040014000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>1,c=>-4,a=>98,g=>3,b=>6,d=>-4,f=>'UE7'}
620000002601000001001f000000
620000002601000001001f000000
620000002601000001001f000000
620000002601000001001f000000
-
{e=>6,c=>-1,a=>-100,g=>6,b=>1,d=>-2,f=>'UE2'}
9cffffffb9010000060032000000
9cffffffb9010000060032000000
9cffffffb9010000060032000000
9cffffffb9010000060032000000
-
{e=>3,c=>0,a=>-41,g=>4,b=>6,d=>1,f=>'UE2'}
d7ffffff46000000030022000000
d7ffffff46000000030022000000
d7ffffff46000000030022000000
d7ffffff46000000030022000000
-
{e=>3,c=>-4,a=>74,g=>2,b=>2,d=>-3,f=>'UE4'}
4a00000062010000030014000000
4a00000062010000030014000000
4a00000062010000030014000000
4a00000062010000030014000000
-
{e=>2,c=>2,a=>-78,g=>4,b=>4,d=>-2,f=>'UE7'}
b2ffffff94010000020027000000
b2ffffff94010000020027000000
b2ffffff94010000020027000000
b2ffffff94010000020027000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>1,a=>14,d=>-2,c=>-3,h=>7,b=>3,g=>7,f=>'UE6'}
0e000000ab01000001003e0000000700
0e000000ab01000001003e0000000700
0e000000ab01000001003e0000000700
0e000000ab01000001003e0000000700
-
{e=>5,a=>-111,d=>-2,c=>-2,h=>7,b=>0,g=>5,f=>'UE0'}
91ffffffb00100000500280000000700
91ffffffb00100000500280000000700
91ffffffb00100000500280000000700
91ffffffb00100000500280000000700
-
{e=>6,a=>68,d=>-3,c=>1,h=>7,b=>2,g=>1,f=>'UE2'}
440000004a01000006000a0000000700
440000004a01000006000a0000000700
440000004a01000006000a0000000700
440000004a01000006000a0000000700
-
{e=>5,a=>-108,d=>1,c=>-3,h=>7,b=>1,g=>4,f=>'UE3'}
94ffffff690000000500230000000700
94ffffff690000000500230000000700
94ffffff690000000500230000000700
94ffffff690000000500230000000700
-
{e=>3,a=>114,d=>-2,c=>-1,h=>6,b=>1,g=>2,f=>'UE5'}
72000000b90100000300150000000600
72000000b90100000300150000000600
72000000b90100000300150000000600
72000000b90100000300150000000600
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>2,a=>-51,d=>-4,c=>2,h=>0,b=>1,g=>7,f=>'UE3',i=>-4}
cdffffff1101000002003b0000002000
cdffffff1101000002003b0000002000
cdffffff1101000002003b0000002000
cdffffff1101000002003b0000002000
-
{e=>2,a=>-42,d=>2,c=>3,h=>7,b=>3,g=>2,f=>'UE5',i=>1}
d6ffffff9b0000000200150000000f00
d6ffffff9b0000000200150000000f00
d6ffffff9b0000000200150000000f00
d6ffffff9b0000000200150000000f00
-
{e=>1,a=>47,d=>3,c=>3,h=>1,b=>0,g=>4,f=>'UE0',i=>-4}
2f000000d80000000100200000002100
2f000000d80000000100200000002100
2f000000d80000000100200000002100
2f000000d80000000100200000002100
-
{e=>0,a=>-80,d=>-1,c=>-4,h=>5,b=>2,g=>4,f=>'UE7',i=>0}
b0ffffffe20100000000270000000500
b0ffffffe20100000000270000000500
b0ffffffe20100000000270000000500
b0ffffffe20100000000270000000500
-
{e=>2,a=>-76,d=>-1,c=>1,h=>5,b=>6,g=>3,f=>'UE6',i=>2}
b4ffffffce01000002001e0000001500
b4ffffffce01000002001e0000001500
b4ffffffce01000002001e0000001500
b4ffffffce01000002001e0000001500
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
};
-
{e=>5,a=>-74,d=>2,j=>'SEM1',c=>0,h=>7,b=>0,g=>2,f=>'UE7',i=>-3}
b6ffffff800000000500170000002f0007000000
b6ffffff800000000500170000002f0007000000
b6ffffff800000000500170000002f0007000000
b6ffffff800000000500170000002f0007000000
-
{e=>5,a=>94,d=>-1,j=>'SEM4',c=>3,h=>3,b=>5,g=>2,f=>'UE6',i=>-3}
5e000000dd0100000500160000002b0004000000
5e000000dd0100000500160000002b0004000000
5e000000dd0100000500160000002b0004000000
5e000000dd0100000500160000002b0004000000
-
{e=>6,a=>-63,d=>-3,j=>'SE2',c=>3,h=>3,b=>5,g=>1,f=>'UE1',i=>2}
c1ffffff5d010000060009000000130002000000
c1ffffff5d010000060009000000130002000000
c1ffffff5d010000060009000000130002000000
c1ffffff5d010000060009000000130002000000
-
{e=>2,a=>15,d=>3,j=>'SEM3',c=>0,h=>2,b=>4,g=>5,f=>'UE7',i=>-4}
0f000000c400000002002f000000220005000000
0f000000c400000002002f000000220005000000
0f000000c400000002002f000000220005000000
0f000000c400000002002f000000220005000000
-
{e=>4,a=>-16,d=>-4,j=>'SEM4',c=>-3,h=>4,b=>7,g=>2,f=>'UE3',i=>1}
f0ffffff2f0100000400130000000c0004000000
f0ffffff2f0100000400130000000c0004000000
f0ffffff2f0100000400130000000c0004000000
f0ffffff2f0100000400130000000c0004000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
};
-
{e=>7,a=>-113,d=>0,j=>'SE3',c=>2,k=>96,h=>4,b=>7,g=>5,f=>'UE3',i=>0}
8fffffff1700000007002b0000000400030000006000
8fffffff1700000007002b0000000400030000006000
8fffffff1700000007002b0000000400030000006000
8fffffff1700000007002b0000000400030000006000
-
{e=>2,a=>-5,d=>-4,j=>'SEM4',c=>-1,k=>28,h=>2,b=>4,g=>0,f=>'UE0',i=>1}
fbffffff3c0100000200000000000a00040000001c00
fbffffff3c0100000200000000000a00040000001c00
fbffffff3c0100000200000000000a00040000001c00
fbffffff3c0100000200000000000a00040000001c00
-
{e=>5,a=>52,d=>-3,j=>'SE3',c=>-3,k=>-1,h=>2,b=>6,g=>1,f=>'UE6',i=>1}
340000006e01000005000e0000000a0003000000ff00
340000006e01000005000e0000000a0003000000ff00
340000006e01000005000e0000000a0003000000ff00
340000006e01000005000e0000000a0003000000ff00
-
{e=>4,a=>-47,d=>-3,j=>'SE2',c=>2,k=>112,h=>6,b=>3,g=>2,f=>'UE3',i=>1}
d1ffffff530100000400130000000e00020000007000
d1ffffff530100000400130000000e00020000007000
d1ffffff530100000400130000000e00020000007000
d1ffffff530100000400130000000e00020000007000
-
{e=>4,a=>-78,d=>2,j=>'SE3',c=>2,k=>55,h=>1,b=>0,g=>5,f=>'UE2',i=>1}
b2ffffff9000000004002a0000000900030000003700
b2ffffff9000000004002a0000000900030000003700
b2ffffff9000000004002a0000000900030000003700
b2ffffff9000000004002a0000000900030000003700
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>0,a=>-33,d=>-4,j=>'SEM1',l=>0,c=>-2,k=>46,h=>6,b=>0,g=>3,f=>'UE7',i=>-2}
dfffffff3001000000001f0000003600070000002e00
dfffffff3001000000001f0000003600070000002e00
dfffffff3001000000001f0000003600070000002e00
dfffffff3001000000001f0000003600070000002e00
-
{e=>3,a=>78,d=>-4,j=>'SE3',l=>1,c=>-1,k=>-21,h=>5,b=>3,g=>5,f=>'UE2',i=>-3}
4e0000003b01000003002a0000002d0003000000eb01
4e0000003b01000003002a0000002d0003000000eb01
4e0000003b01000003002a0000002d0003000000eb01
4e0000003b01000003002a0000002d0003000000eb01
-
{e=>3,a=>-6,d=>0,j=>'SE0',l=>2,c=>-1,k=>54,h=>1,b=>1,g=>0,f=>'UE6',i=>2}
faffffff390000000300060000001100000000003602
faffffff390000000300060000001100000000003602
faffffff390000000300060000001100000000003602
faffffff390000000300060000001100000000003602
-
{e=>3,a=>-92,d=>2,j=>'SEM2',l=>3,c=>-3,k=>28,h=>0,b=>5,g=>6,f=>'UE1',i=>0}
a4ffffffad0000000300310000000000060000001c03
a4ffffffad0000000300310000000000060000001c03
a4ffffffad0000000300310000000000060000001c03
a4ffffffad0000000300310000000000060000001c03
-
{e=>0,a=>109,d=>3,j=>'SE1',l=>7,c=>-1,k=>116,h=>4,b=>4,g=>6,f=>'UE3',i=>-3}
6d000000fc0000000000330000002c00010000007407
6d000000fc0000000000330000002c00010000007407
6d000000fc0000000000330000002c00010000007407
6d000000fc0000000000330000002c00010000007407
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>1,a=>61,m=>0,d=>3,j=>'SEM3',l=>5,c=>-4,k=>-68,h=>1,b=>6,g=>5,f=>'UE4',i=>0}
3d000000e600000001002c000000010005000000bc05
3d000000e600000001002c000000010005000000bc05
3d000000e600000001002c000000010005000000bc05
3d000000e600000001002c000000010005000000bc05
-
{e=>2,a=>-25,m=>-1,d=>2,j=>'SE2',l=>3,c=>-2,k=>-89,h=>3,b=>3,g=>4,f=>'UE1',i=>0}
e7ffffffb3000000020021000000030002000000a73b
e7ffffffb3000000020021000000030002000000a73b
e7ffffffb3000000020021000000030002000000a73b
e7ffffffb3000000020021000000030002000000a73b
-
{e=>2,a=>14,m=>0,d=>3,j=>'SEM3',l=>7,c=>1,k=>75,h=>6,b=>7,g=>6,f=>'UE5',i=>0}
0e000000cf0000000200350000000600050000004b07
0e000000cf0000000200350000000600050000004b07
0e000000cf0000000200350000000600050000004b07
0e000000cf0000000200350000000600050000004b07
-
{e=>6,a=>-81,m=>-2,d=>3,j=>'SEM1',l=>1,c=>3,k=>45,h=>1,b=>0,g=>2,f=>'UE7',i=>-4}
afffffffd80000000600170000002100070000002d31
afffffffd80000000600170000002100070000002d31
afffffffd80000000600170000002100070000002d31
afffffffd80000000600170000002100070000002d31
-
{e=>0,a=>-15,m=>-2,d=>2,j=>'SEM1',l=>6,c=>-4,k=>52,h=>4,b=>4,g=>4,f=>'UE1',i=>2}
f1ffffffa40000000000210000001400070000003436
f1ffffffa40000000000210000001400070000003436
f1ffffffa40000000000210000001400070000003436
f1ffffffa40000000000210000001400070000003436
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>7,n=>3,a=>-25,m=>2,d=>0,j=>'SE0',l=>5,c=>3,k=>-128,h=>6,b=>7,g=>1,f=>'UE4',i=>2}
e7ffffff1f00000007000c000000160000000000801503000000
e7ffffff1f00000007000c000000160000000000801503000000
e7ffffff1f00000007000c000000160000000000801503000000
e7ffffff1f00000007000c000000160000000000801503000000
-
{e=>4,n=>1,a=>31,m=>2,d=>-1,j=>'SE2',l=>0,c=>-1,k=>-106,h=>3,b=>0,g=>2,f=>'UE7',i=>0}
1f000000f8010000040017000000030002000000961001000000
1f000000f8010000040017000000030002000000961001000000
1f000000f8010000040017000000030002000000961001000000
1f000000f8010000040017000000030002000000961001000000
-
{e=>7,n=>5,a=>42,m=>-4,d=>-4,j=>'SEM2',l=>3,c=>-4,k=>82,h=>1,b=>6,g=>7,f=>'UE0',i=>-1}
2a00000026010000070038000000390006000000522305000000
2a00000026010000070038000000390006000000522305000000
2a00000026010000070038000000390006000000522305000000
2a00000026010000070038000000390006000000522305000000
-
{e=>3,n=>5,a=>51,m=>-4,d=>2,j=>'SEM4',l=>7,c=>3,k=>-87,h=>1,b=>2,g=>0,f=>'UE5',i=>0}
330000009a000000030005000000010004000000a92705000000
330000009a000000030005000000010004000000a92705000000
330000009a000000030005000000010004000000a92705000000
330000009a000000030005000000010004000000a92705000000
-
{e=>0,n=>7,a=>31,m=>-3,d=>2,j=>'SE1',l=>2,c=>2,k=>-41,h=>5,b=>4,g=>6,f=>'UE1',i=>2}
1f00000094000000000031000000150001000000d72a07000000
1f00000094000000000031000000150001000000d72a07000000
1f00000094000000000031000000150001000000d72a07000000
1f00000094000000000031000000150001000000d72a07000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  int a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>0,n=>6,a=>-128,m=>-1,d=>0,j=>'SE2',l=>1,c=>0,k=>-95,h=>3,b=>5,g=>7,f=>'UE6',o=>62,i=>2}
80ffffff0500000000003e000000130002000000a139060000003e00
80ffffff0500000000003e000000130002000000a139060000003e00
80ffffff0500000000003e000000130002000000a139060000003e00
80ffffff0500000000003e000000130002000000a139060000003e00
-
{e=>3,n=>5,a=>-9,m=>-4,d=>1,j=>'SEM1',l=>3,c=>3,k=>-61,h=>2,b=>6,g=>0,f=>'UE5',o=>76,i=>1}
f7ffffff5e0000000300050000000a0007000000c323050000004c00
f7ffffff5e0000000300050000000a0007000000c323050000004c00
f7ffffff5e0000000300050000000a0007000000c323050000004c00
f7ffffff5e0000000300050000000a0007000000c323050000004c00
-
{e=>4,n=>7,a=>15,m=>1,d=>-2,j=>'SEM2',l=>6,c=>2,k=>-46,h=>3,b=>5,g=>4,f=>'UE0',o=>51,i=>-1}
0f000000950100000400200000003b0006000000d20e070000003300
0f000000950100000400200000003b0006000000d20e070000003300
0f000000950100000400200000003b0006000000d20e070000003300
0f000000950100000400200000003b0006000000d20e070000003300
-
{e=>7,n=>2,a=>-103,m=>2,d=>2,j=>'SEM3',l=>3,c=>-2,k=>75,h=>4,b=>7,g=>4,f=>'UE2',o=>76,i=>-1}
99ffffffb70000000700220000003c00050000004b13020000004c00
99ffffffb70000000700220000003c00050000004b13020000004c00
99ffffffb70000000700220000003c00050000004b13020000004c00
99ffffffb70000000700220000003c00050000004b13020000004c00
-
{e=>6,n=>2,a=>-114,m=>-3,d=>-4,j=>'SEM1',l=>5,c=>-2,k=>88,h=>6,b=>0,g=>5,f=>'UE3',o=>44,i=>-3}
8effffff3001000006002b0000002e0007000000582d020000002c00
8effffff3001000006002b0000002e0007000000582d020000002c00
8effffff3001000006002b0000002e0007000000582d020000002c00
8effffff3001000006002b0000002e0007000000582d020000002c00
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
};
-
{a=>20,b=>5}
1400000005000000
1400000005000000
1400000005000000
1400000005000000
-
{a=>-55,b=>5}
c9ffffff05000000
c9ffffff05000000
c9ffffff05000000
c9ffffff05000000
-
{a=>98,b=>5}
6200000005000000
6200000005000000
6200000005000000
6200000005000000
-
{a=>-119,b=>4}
89ffffff04000000
89ffffff04000000
89ffffff04000000
89ffffff04000000
-
{a=>-90,b=>0}
a6ffffff00000000
a6ffffff00000000
a6ffffff00000000
a6ffffff00000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
};
-
{c=>-3,a=>-84,b=>3}
acffffff2b000000
acffffff2b000000
acffffff2b000000
acffffff2b000000
-
{c=>-4,a=>5,b=>3}
0500000023000000
0500000023000000
0500000023000000
0500000023000000
-
{c=>0,a=>-27,b=>6}
e5ffffff06000000
e5ffffff06000000
e5ffffff06000000
e5ffffff06000000
-
{c=>1,a=>41,b=>1}
2900000009000000
2900000009000000
2900000009000000
2900000009000000
-
{c=>2,a=>-56,b=>5}
c8ffffff15000000
c8ffffff15000000
c8ffffff15000000
c8ffffff15000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
};
-
{c=>-3,a=>38,b=>5,d=>-1}
26000000ed010000
26000000ed010000
26000000ed010000
26000000ed010000
-
{c=>-4,a=>-66,b=>1,d=>2}
beffffffa1000000
beffffffa1000000
beffffffa1000000
beffffffa1000000
-
{c=>-2,a=>-17,b=>2,d=>0}
efffffff32000000
efffffff32000000
efffffff32000000
efffffff32000000
-
{c=>-3,a=>-93,b=>4,d=>3}
a3ffffffec000000
a3ffffffec000000
a3ffffffec000000
a3ffffffec000000
-
{c=>3,a=>83,b=>6,d=>0}
530000001e000000
530000001e000000
530000001e000000
530000001e000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
};
-
{e=>3,c=>-2,a=>79,b=>7,d=>-1}
4f000000f70100000300
4f000000f70100000300
4f000000f70100000300
4f000000f70100000300
-
{e=>0,c=>2,a=>118,b=>4,d=>-4}
76000000140100000000
76000000140100000000
76000000140100000000
76000000140100000000
-
{e=>6,c=>0,a=>-24,b=>0,d=>3}
e8ffffffc00000000600
e8ffffffc00000000600
e8ffffffc00000000600
e8ffffffc00000000600
-
{e=>4,c=>-1,a=>-90,b=>3,d=>-3}
a6ffffff7b0100000400
a6ffffff7b0100000400
a6ffffff7b0100000400
a6ffffff7b0100000400
-
{e=>3,c=>1,a=>80,b=>3,d=>2}
500000008b0000000300
500000008b0000000300
500000008b0000000300
500000008b0000000300
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
};
-
{e=>0,c=>-3,a=>-26,b=>6,d=>-1,f=>'UE1'}
e6ffffffee010000000001000000
e6ffffffee010000000001000000
e6ffffffee010000000001000000
e6ffffffee010000000001000000
-
{e=>4,c=>2,a=>124,b=>4,d=>-4,f=>'UE2'}
7c00000014010000040002000000
7c00000014010000040002000000
7c00000014010000040002000000
7c00000014010000040002000000
-
{e=>7,c=>-2,a=>-9,b=>1,d=>3,f=>'UE2'}
f7fffffff1000000070002000000
f7fffffff1000000070002000000
f7fffffff1000000070002000000
f7fffffff1000000070002000000
-
{e=>7,c=>0,a=>122,b=>4,d=>2,f=>'UE5'}
7a00000084000000070005000000
7a00000084000000070005000000
7a00000084000000070005000000
7a00000084000000070005000000
-
{e=>1,c=>-4,a=>-12,b=>6,d=>-4,f=>'UE4'}
f4ffffff26010000010004000000
f4ffffff26010000010004000000
f4ffffff26010000010004000000
f4ffffff26010000010004000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
};
-
{e=>7,c=>-4,a=>-80,g=>7,b=>2,d=>3,f=>'UE2'}
b0ffffffe200000007003a000000
b0ffffffe200000007003a000000
b0ffffffe200000007003a000000
b0ffffffe200000007003a000000
-
{e=>1,c=>2,a=>93,g=>2,b=>1,d=>3,f=>'UE0'}
5d000000d1000000010010000000
5d000000d1000000010010000000
5d000000d1000000010010000000
5d000000d1000000010010000000
-
{e=>0,c=>0,a=>-46,g=>2,b=>3,d=>-3,f=>'UE6'}
d2ffffff43010000000016000000
d2ffffff43010000000016000000
d2ffffff43010000000016000000
d2ffffff43010000000016000000
-
{e=>4,c=>1,a=>120,g=>0,b=>2,d=>1,f=>'UE6'}
780000004a000000040006000000
780000004a000000040006000000
780000004a000000040006000000
780000004a000000040006000000
-
{e=>3,c=>0,a=>19,g=>6,b=>7,d=>-4,f=>'UE0'}
1300000007010000030030000000
1300000007010000030030000000
1300000007010000030030000000
1300000007010000030030000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
};
-
{e=>6,c=>-2,a=>-99,g=>4,b=>1,d=>0,f=>'UE0'}
9dffffff31000000060020000000
9dffffff31000000060020000000
9dffffff31000000060020000000
9dffffff31000000060020000000
-
{e=>0,c=>0,a=>-111,g=>1,b=>4,d=>-1,f=>'UE6'}
91ffffffc401000000000e000000
91ffffffc401000000000e000000
91ffffffc401000000000e000000
91ffffffc401000000000e000000
-
{e=>0,c=>1,a=>106,g=>1,b=>3,d=>3,f=>'UE0'}
6a000000cb000000000008000000
6a000000cb000000000008000000
6a000000cb000000000008000000
6a000000cb000000000008000000
-
{e=>4,c=>-3,a=>94,g=>0,b=>2,d=>1,f=>'UE6'}
5e0000006a000000040006000000
5e0000006a000000040006000000
5e0000006a000000040006000000
5e0000006a000000040006000000
-
{e=>7,c=>-4,a=>-48,g=>2,b=>3,d=>2,f=>'UE6'}
d0ffffffa3000000070016000000
d0ffffffa3000000070016000000
d0ffffffa3000000070016000000
d0ffffffa3000000070016000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
};
-
{e=>4,a=>-127,d=>2,c=>-2,h=>0,b=>1,g=>6,f=>'UE0'}
81ffffffb10000000400300000000000
81ffffffb10000000400300000000000
81ffffffb10000000400300000000000
81ffffffb10000000400300000000000
-
{e=>0,a=>16,d=>-2,c=>-1,h=>5,b=>0,g=>2,f=>'UE6'}
10000000b80100000000160000000500
10000000b80100000000160000000500
10000000b80100000000160000000500
10000000b80100000000160000000500
-
{e=>7,a=>-107,d=>2,c=>0,h=>1,b=>6,g=>7,f=>'UE5'}
95ffffff8600000007003d0000000100
95ffffff8600000007003d0000000100
95ffffff8600000007003d0000000100
95ffffff8600000007003d0000000100
-
{e=>3,a=>53,d=>-2,c=>0,h=>0,b=>0,g=>5,f=>'UE0'}
35000000800100000300280000000000
35000000800100000300280000000000
35000000800100000300280000000000
35000000800100000300280000000000
-
{e=>5,a=>33,d=>3,c=>0,h=>6,b=>7,g=>3,f=>'UE7'}
21000000c700000005001f0000000600
21000000c700000005001f0000000600
21000000c700000005001f0000000600
21000000c700000005001f0000000600
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
};
-
{e=>1,a=>3,d=>0,c=>1,h=>4,b=>3,g=>2,f=>'UE0',i=>-2}
030000000b0000000100100000003400
030000000b0000000100100000003400
030000000b0000000100100000003400
030000000b0000000100100000003400
-
{e=>1,a=>-126,d=>0,c=>0,h=>1,b=>1,g=>7,f=>'UE7',i=>-4}
82ffffff0100000001003f0000002100
82ffffff0100000001003f0000002100
82ffffff0100000001003f0000002100
82ffffff0100000001003f0000002100
-
{e=>2,a=>58,d=>2,c=>-2,h=>1,b=>2,g=>4,f=>'UE4',i=>0}
3a000000b20000000200240000000100
3a000000b20000000200240000000100
3a000000b20000000200240000000100
3a000000b20000000200240000000100
-
{e=>4,a=>66,d=>-4,c=>-3,h=>7,b=>2,g=>5,f=>'UE4',i=>-4}
420000002a01000004002c0000002700
420000002a01000004002c0000002700
420000002a01000004002c0000002700
420000002a01000004002c0000002700
-
{e=>5,a=>9,d=>-1,c=>3,h=>4,b=>3,g=>3,f=>'UE3',i=>3}
09000000db01000005001b0000001c00
09000000db01000005001b0000001c00
09000000db01000005001b0000001c00
09000000db01000005001b0000001c00
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
};
-
{e=>6,a=>73,d=>2,j=>'SEM3',c=>-1,h=>3,b=>0,g=>6,f=>'UE4',i=>0}
49000000b8000000060034000000030005000000
49000000b8000000060034000000030005000000
49000000b8000000060034000000030005000000
49000000b8000000060034000000030005000000
-
{e=>1,a=>24,d=>0,j=>'SEM2',c=>-3,h=>7,b=>5,g=>1,f=>'UE3',i=>3}
180000002d00000001000b0000001f0006000000
180000002d00000001000b0000001f0006000000
180000002d00000001000b0000001f0006000000
180000002d00000001000b0000001f0006000000
-
{e=>0,a=>-128,d=>0,j=>'SEM3',c=>1,h=>4,b=>7,g=>1,f=>'UE0',i=>-1}
80ffffff0f0000000000080000003c0005000000
80ffffff0f0000000000080000003c0005000000
80ffffff0f0000000000080000003c0005000000
80ffffff0f0000000000080000003c0005000000
-
{e=>5,a=>-96,d=>1,j=>'SE1',c=>-2,h=>4,b=>4,g=>7,f=>'UE3',i=>-2}
a0ffffff7400000005003b000000340001000000
a0ffffff7400000005003b000000340001000000
a0ffffff7400000005003b000000340001000000
a0ffffff7400000005003b000000340001000000
-
{e=>0,a=>54,d=>-1,j=>'SEM1',c=>-3,h=>3,b=>5,g=>0,f=>'UE7',i=>3}
36000000ed0100000000070000001b0007000000
36000000ed0100000000070000001b0007000000
36000000ed0100000000070000001b0007000000
36000000ed0100000000070000001b0007000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
};
-
{e=>3,a=>-71,d=>-2,j=>'SEM2',c=>-3,k=>-37,h=>1,b=>1,g=>2,f=>'UE1',i=>1}
b9ffffffa9010000030011000000090006000000db00
b9ffffffa9010000030011000000090006000000db00
b9ffffffa9010000030011000000090006000000db00
b9ffffffa9010000030011000000090006000000db00
-
{e=>6,a=>14,d=>1,j=>'SE2',c=>-3,k=>-10,h=>2,b=>0,g=>7,f=>'UE1',i=>1}
0e000000680000000600390000000a0002000000f600
0e000000680000000600390000000a0002000000f600
0e000000680000000600390000000a0002000000f600
0e000000680000000600390000000a0002000000f600
-
{e=>1,a=>-4,d=>-4,j=>'SE1',c=>0,k=>-70,h=>2,b=>0,g=>7,f=>'UE0',i=>-2}
fcffffff00010000010038000000320001000000ba00
fcffffff00010000010038000000320001000000ba00
fcffffff00010000010038000000320001000000ba00
fcffffff00010000010038000000320001000000ba00
-
{e=>0,a=>-105,d=>0,j=>'SEM1',c=>3,k=>-94,h=>3,b=>4,g=>4,f=>'UE1',i=>1}
97ffffff1c0000000000210000000b0007000000a200
97ffffff1c0000000000210000000b0007000000a200
97ffffff1c0000000000210000000b0007000000a200
97ffffff1c0000000000210000000b0007000000a200
-
{e=>0,a=>-18,d=>3,j=>'SEM4',c=>0,k=>76,h=>6,b=>7,g=>7,f=>'UE1',i=>-3}
eeffffffc70000000000390000002e00040000004c00
eeffffffc70000000000390000002e00040000004c00
eeffffffc70000000000390000002e00040000004c00
eeffffffc70000000000390000002e00040000004c00
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
};
-
{e=>0,a=>-72,d=>1,j=>'SE1',l=>1,c=>2,k=>-123,h=>6,b=>0,g=>0,f=>'UE0',i=>2}
b8ffffff500000000000000000001600010000008501
b8ffffff500000000000000000001600010000008501
b8ffffff500000000000000000001600010000008501
b8ffffff500000000000000000001600010000008501
-
{e=>4,a=>38,d=>0,j=>'SE3',l=>3,c=>-3,k=>109,h=>0,b=>0,g=>6,f=>'UE4',i=>-2}
26000000280000000400340000003000030000006d03
26000000280000000400340000003000030000006d03
26000000280000000400340000003000030000006d03
26000000280000000400340000003000030000006d03
-
{e=>1,a=>-38,d=>0,j=>'SEM4',l=>7,c=>1,k=>88,h=>4,b=>5,g=>1,f=>'UE2',i=>0}
daffffff0d00000001000a0000000400040000005807
daffffff0d00000001000a0000000400040000005807
daffffff0d00000001000a0000000400040000005807
daffffff0d00000001000a0000000400040000005807
-
{e=>3,a=>-30,d=>-3,j=>'SEM3',l=>1,c=>0,k=>47,h=>7,b=>3,g=>4,f=>'UE1',i=>1}
e2ffffff430100000300210000000f00050000002f01
e2ffffff430100000300210000000f00050000002f01
e2ffffff430100000300210000000f00050000002f01
e2ffffff430100000300210000000f00050000002f01
-
{e=>2,a=>49,d=>-4,j=>'SEM3',l=>5,c=>2,k=>101,h=>0,b=>0,g=>1,f=>'UE5',i=>-4}
310000001001000002000d0000002000050000006505
310000001001000002000d0000002000050000006505
310000001001000002000d0000002000050000006505
310000001001000002000d0000002000050000006505
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
};
-
{e=>2,a=>72,m=>-1,d=>-1,j=>'SE1',l=>2,c=>-3,k=>28,h=>7,b=>0,g=>6,f=>'UE7',i=>0}
48000000e80100000200370000000700010000001c3a
48000000e80100000200370000000700010000001c3a
48000000e80100000200370000000700010000001c3a
48000000e80100000200370000000700010000001c3a
-
{e=>5,a=>-114,m=>3,d=>3,j=>'SE0',l=>7,c=>-3,k=>-79,h=>1,b=>2,g=>6,f=>'UE1',i=>2}
8effffffea000000050031000000110000000000b11f
8effffffea000000050031000000110000000000b11f
8effffffea000000050031000000110000000000b11f
8effffffea000000050031000000110000000000b11f
-
{e=>6,a=>-48,m=>1,d=>-3,j=>'SE2',l=>2,c=>-3,k=>78,h=>0,b=>5,g=>1,f=>'UE7',i=>-4}
d0ffffff6d01000006000f0000002000020000004e0a
d0ffffff6d01000006000f0000002000020000004e0a
d0ffffff6d01000006000f0000002000020000004e0a
d0ffffff6d01000006000f0000002000020000004e0a
-
{e=>5,a=>101,m=>-2,d=>3,j=>'SE3',l=>3,c=>-3,k=>-125,h=>5,b=>4,g=>0,f=>'UE1',i=>-3}
65000000ec0000000500010000002d00030000008333
65000000ec0000000500010000002d00030000008333
65000000ec0000000500010000002d00030000008333
65000000ec0000000500010000002d00030000008333
-
{e=>4,a=>-7,m=>2,d=>1,j=>'SE1',l=>7,c=>-2,k=>8,h=>4,b=>7,g=>5,f=>'UE1',i=>-2}
f9ffffff770000000400290000003400010000000817
f9ffffff770000000400290000003400010000000817
f9ffffff770000000400290000003400010000000817
f9ffffff770000000400290000003400010000000817
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
};
-
{e=>3,n=>2,a=>-110,m=>-1,d=>3,j=>'SEM1',l=>6,c=>-3,k=>119,h=>0,b=>3,g=>3,f=>'UE4',i=>0}
92ffffffeb00000003001c000000000007000000773e02000000
92ffffffeb00000003001c000000000007000000773e02000000
92ffffffeb00000003001c000000000007000000773e02000000
92ffffffeb00000003001c000000000007000000773e02000000
-
{e=>4,n=>0,a=>-68,m=>3,d=>-1,j=>'SEM4',l=>7,c=>0,k=>57,h=>0,b=>3,g=>7,f=>'UE7',i=>-2}
bcffffffc301000004003f000000300004000000391f00000000
bcffffffc301000004003f000000300004000000391f00000000
bcffffffc301000004003f000000300004000000391f00000000
bcffffffc301000004003f000000300004000000391f00000000
-
{e=>4,n=>6,a=>-6,m=>-2,d=>-1,j=>'SE1',l=>3,c=>3,k=>127,h=>3,b=>6,g=>5,f=>'UE3',i=>2}
faffffffde01000004002b0000001300010000007f3306000000
faffffffde01000004002b0000001300010000007f3306000000
faffffffde01000004002b0000001300010000007f3306000000
faffffffde01000004002b0000001300010000007f3306000000
-
{e=>1,n=>0,a=>-116,m=>-2,d=>1,j=>'SE1',l=>7,c=>-2,k=>-82,h=>7,b=>1,g=>4,f=>'UE7',i=>3}
8cffffff710000000100270000001f0001000000ae3700000000
8cffffff710000000100270000001f0001000000ae3700000000
8cffffff710000000100270000001f0001000000ae3700000000
8cffffff710000000100270000001f0001000000ae3700000000
-
{e=>5,n=>5,a=>122,m=>-3,d=>3,j=>'SEM2',l=>2,c=>-2,k=>31,h=>3,b=>1,g=>5,f=>'UE0',i=>1}
7a000000f10000000500280000000b00060000001f2a05000000
7a000000f10000000500280000000b00060000001f2a05000000
7a000000f10000000500280000000b00060000001f2a05000000
7a000000f10000000500280000000b00060000001f2a05000000
=
typedef int foo;
enum en_u { UE0, UE1, UE2, UE3, UE4, UE5, UE6, UE7 };
enum en_s { SEM4=-4, SEM3, SEM2, SEM1, SE0, SE1, SE2, SE3 };

#if defined PACK_PAREN
#pragma pack( 2 )
#elif defined PACK_NO_PAREN
#pragma pack 2
#endif
struct enum_pack_2 {
  long a;
  unsigned int  b:3;
  signed   int  c:3;
  foo           d:3;
  unsigned char e:3;
  enum en_u     f:3;
  unsigned int  g:3;
  int            :0;
  unsigned char h:3;
  signed   char i:3;
  enum en_s     j:3;
  char          k;
  unsigned char l:3;
  signed   char m:3;
  unsigned int  n:3;
  unsigned char o;
};
-
{e=>5,n=>1,a=>-10,m=>1,d=>-1,j=>'SE2',l=>2,c=>0,k=>99,h=>6,b=>3,g=>7,f=>'UE6',o=>213,i=>-2}
f6ffffffc301000005003e000000360002000000630a01000000d500
f6ffffffc301000005003e000000360002000000630a01000000d500
f6ffffffc301000005003e000000360002000000630a01000000d500
f6ffffffc301000005003e000000360002000000630a01000000d500
-
{e=>0,n=>3,a=>53,m=>-2,d=>-1,j=>'SE1',l=>7,c=>1,k=>25,h=>3,b=>2,g=>5,f=>'UE3',o=>128,i=>3}
35000000ca01000000002b0000001b00010000001937030000008000
35000000ca01000000002b0000001b00010000001937030000008000
35000000ca01000000002b0000001b00010000001937030000008000
35000000ca01000000002b0000001b00010000001937030000008000
-
{e=>5,n=>2,a=>23,m=>1,d=>-2,j=>'SEM2',l=>3,c=>-3,k=>-114,h=>1,b=>1,g=>2,f=>'UE6',o=>170,i=>-4}
17000000a90100000500160000002100060000008e0b02000000aa00
17000000a90100000500160000002100060000008e0b02000000aa00
17000000a90100000500160000002100060000008e0b02000000aa00
17000000a90100000500160000002100060000008e0b02000000aa00
-
{e=>7,n=>7,a=>-19,m=>-1,d=>-1,j=>'SE3',l=>2,c=>0,k=>-61,h=>3,b=>3,g=>7,f=>'UE6',o=>181,i=>-1}
edffffffc301000007003e0000003b0003000000c33a07000000b500
edffffffc301000007003e0000003b0003000000c33a07000000b500
edffffffc301000007003e0000003b0003000000c33a07000000b500
edffffffc301000007003e0000003b0003000000c33a07000000b500
-
{e=>5,n=>5,a=>-62,m=>0,d=>-4,j=>'SEM4',l=>6,c=>-2,k=>-114,h=>3,b=>4,g=>6,f=>'UE0',o=>248,i=>3}
c2ffffff340100000500300000001b00040000008e0605000000f800
c2ffffff340100000500300000001b00040000008e0605000000f800
c2ffffff340100000500300000001b00040000008e0605000000f800
c2ffffff340100000500300000001b00040000008e0605000000f800
=
struct toobig {
  unsigned char  a:2;
};
-
{a=>0}
00
00
00
00
-
{a=>0}
00
00
00
00
-
{a=>2}
02
02
02
02
-
{a=>1}
01
01
01
01
-
{a=>1}
01
01
01
01
=
struct toobig {
  unsigned char  a:2;
  unsigned char  b:7;
};
-
{a=>0,b=>93}
005d
005d
005d
005d
-
{a=>3,b=>125}
037d
037d
037d
037d
-
{a=>1,b=>103}
0167
0167
0167
0167
-
{a=>0,b=>44}
002c
002c
002c
002c
-
{a=>2,b=>56}
0238
0238
0238
0238
=
struct toobig {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
};
-
{a=>1,b=>105}
0169
0169
0169
0169
-
{a=>1,b=>69}
0145
0145
0145
0145
-
{a=>0,b=>100}
0064
0064
0064
0064
-
{a=>1,b=>64}
0140
0140
0140
0140
-
{a=>1,b=>29}
011d
011d
011d
011d
=
struct toobig {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
};
-
{c=>2,a=>1,b=>120}
01780200
01780200
01780200
01780200
-
{c=>3,a=>3,b=>117}
03750300
03750300
03750300
03750300
-
{c=>2,a=>3,b=>66}
03420200
03420200
03420200
03420200
-
{c=>2,a=>3,b=>40}
03280200
03280200
03280200
03280200
-
{c=>3,a=>1,b=>78}
014e0300
014e0300
014e0300
014e0300
=
struct toobig {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
  unsigned short d:15;
};
-
{c=>1,a=>0,b=>40,d=>29011}
002801005371
002801005371
002801005371
002801005371
-
{c=>1,a=>1,b=>52,d=>7870}
01340100be1e
01340100be1e
01340100be1e
01340100be1e
-
{c=>3,a=>0,b=>127,d=>24484}
007f0300a45f
007f0300a45f
007f0300a45f
007f0300a45f
-
{c=>0,a=>1,b=>117,d=>2770}
01750000d20a
01750000d20a
01750000d20a
01750000d20a
-
{c=>0,a=>2,b=>117,d=>21525}
027500001554
027500001554
027500001554
027500001554
=
struct toobig {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
  unsigned short d:15;
  int             :0;
};
-
{c=>0,a=>2,b=>47,d=>5532}
022f00009c15
022f00009c15
022f00009c150000
022f00009c150000
-
{c=>0,a=>2,b=>53,d=>17293}
023500008d43
023500008d43
023500008d430000
023500008d430000
-
{c=>0,a=>0,b=>42,d=>15065}
002a0000d93a
002a0000d93a
002a0000d93a0000
002a0000d93a0000
-
{c=>1,a=>2,b=>43,d=>26082}
022b0100e265
022b0100e265
022b0100e2650000
022b0100e2650000
-
{c=>2,a=>0,b=>3,d=>23011}
00030200e359
00030200e359
00030200e3590000
00030200e3590000
=
struct toobig {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
  unsigned short d:15;
  int             :0;
  unsigned int   e:2;
};
-
{e=>0,c=>2,a=>1,b=>107,d=>14008}
016b0200b83600000000
016b0200b83600000000
016b0200b836000000000000
016b0200b836000000000000
-
{e=>1,c=>1,a=>0,b=>109,d=>31882}
006d01008a7c01000000
006d01008a7c01000000
006d01008a7c000001000000
006d01008a7c000001000000
-
{e=>2,c=>1,a=>0,b=>83,d=>27991}
00530100576d02000000
00530100576d02000000
00530100576d000002000000
00530100576d000002000000
-
{e=>0,c=>3,a=>1,b=>74,d=>7214}
014a03002e1c00000000
014a03002e1c00000000
014a03002e1c000000000000
014a03002e1c000000000000
-
{e=>0,c=>1,a=>0,b=>93,d=>28404}
005d0100f46e00000000
005d0100f46e00000000
005d0100f46e000000000000
005d0100f46e000000000000
=
struct toobig {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
  unsigned short d:15;
  int             :0;
  unsigned int   e:2;
  unsigned int   f:31;
};
-
{e=>2,c=>3,a=>2,b=>66,d=>17839,f=>37720169}
02420300af450200000069903f02
02420300af450200000069903f02
02420300af4500000200000069903f02
02420300af4500000200000069903f02
-
{e=>2,c=>0,a=>2,b=>81,d=>29158,f=>19309962}
02510000e671020000008aa52601
02510000e671020000008aa52601
02510000e6710000020000008aa52601
02510000e6710000020000008aa52601
-
{e=>0,c=>1,a=>2,b=>98,d=>18169,f=>163308787}
02620100f94600000000f3e4bb09
02620100f94600000000f3e4bb09
02620100f946000000000000f3e4bb09
02620100f946000000000000f3e4bb09
-
{e=>0,c=>3,a=>3,b=>41,d=>24753,f=>707702915}
03290300b1600000000083b02e2a
03290300b1600000000083b02e2a
03290300b16000000000000083b02e2a
03290300b16000000000000083b02e2a
-
{e=>3,c=>0,a=>2,b=>18,d=>28569,f=>199312493}
02120000996f030000006d44e10b
02120000996f030000006d44e10b
02120000996f0000030000006d44e10b
02120000996f0000030000006d44e10b
=
struct toobig {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
  unsigned short d:15;
  int             :0;
  unsigned int   e:2;
  unsigned int   f:31;
  unsigned char  g;
};
-
{e=>3,c=>0,a=>3,g=>253,b=>73,d=>20290,f=>324422081}
03490000424f03000000c1495613fd
03490000424f03000000c1495613fd00
03490000424f000003000000c1495613fd000000
03490000424f000003000000c1495613fd000000
-
{e=>2,c=>1,a=>2,g=>98,b=>58,d=>14829,f=>1109100526}
023a0100ed3902000000ee871b4262
023a0100ed3902000000ee871b426200
023a0100ed39000002000000ee871b4262000000
023a0100ed39000002000000ee871b4262000000
-
{e=>1,c=>2,a=>3,g=>243,b=>82,d=>31588,f=>727978398}
03520200647b010000009e11642bf3
03520200647b010000009e11642bf300
03520200647b0000010000009e11642bf3000000
03520200647b0000010000009e11642bf3000000
-
{e=>1,c=>1,a=>1,g=>104,b=>26,d=>22162,f=>432784954}
011a01009256010000003ac6cb1968
011a01009256010000003ac6cb196800
011a010092560000010000003ac6cb1968000000
011a010092560000010000003ac6cb1968000000
-
{e=>0,c=>3,a=>3,g=>167,b=>62,d=>17539,f=>1939871904}
033e0300834400000000a018a073a7
033e0300834400000000a018a073a700
033e03008344000000000000a018a073a7000000
033e03008344000000000000a018a073a7000000
=
struct toobig {
  char a;
  unsigned char  b:2;
};
-
{a=>-24,b=>1}
e801
e801
e801
e801
-
{a=>61,b=>3}
3d03
3d03
3d03
3d03
-
{a=>-95,b=>1}
a101
a101
a101
a101
-
{a=>-2,b=>2}
fe02
fe02
fe02
fe02
-
{a=>-71,b=>3}
b903
b903
b903
b903
=
struct toobig {
  char a;
  unsigned char  b:2;
  unsigned char  c:7;
};
-
{c=>113,a=>-30,b=>1}
e20171
e20171
e20171
e20171
-
{c=>77,a=>93,b=>3}
5d034d
5d034d
5d034d
5d034d
-
{c=>76,a=>-105,b=>0}
97004c
97004c
97004c
97004c
-
{c=>113,a=>-106,b=>0}
960071
960071
960071
960071
-
{c=>111,a=>21,b=>3}
15036f
15036f
15036f
15036f
=
struct toobig {
  char a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
};
-
{c=>117,a=>4,b=>0}
040075
04007500
04007500
04007500
-
{c=>110,a=>92,b=>1}
5c016e
5c016e00
5c016e00
5c016e00
-
{c=>80,a=>1,b=>0}
010050
01005000
01005000
01005000
-
{c=>115,a=>49,b=>0}
310073
31007300
31007300
31007300
-
{c=>119,a=>-53,b=>1}
cb0177
cb017700
cb017700
cb017700
=
struct toobig {
  char a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
};
-
{c=>119,a=>99,b=>1,d=>2}
6301770200
630177000200
630177000200
630177000200
-
{c=>52,a=>-52,b=>2,d=>1}
cc02340100
cc0234000100
cc0234000100
cc0234000100
-
{c=>59,a=>2,b=>2,d=>0}
02023b0000
02023b000000
02023b000000
02023b000000
-
{c=>25,a=>59,b=>3,d=>1}
3b03190100
3b0319000100
3b0319000100
3b0319000100
-
{c=>52,a=>-19,b=>0,d=>0}
ed00340000
ed0034000000
ed0034000000
ed0034000000
=
struct toobig {
  char a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
};
-
{e=>10626,c=>62,a=>76,b=>3,d=>2}
4c033e02008229
4c033e0002008229
4c033e0002008229
4c033e0002008229
-
{e=>16013,c=>106,a=>-123,b=>2,d=>2}
85026a02008d3e
85026a0002008d3e
85026a0002008d3e
85026a0002008d3e
-
{e=>15778,c=>84,a=>-66,b=>1,d=>3}
be01540300a23d
be0154000300a23d
be0154000300a23d
be0154000300a23d
-
{e=>3225,c=>25,a=>-124,b=>1,d=>1}
8401190100990c
840119000100990c
840119000100990c
840119000100990c
-
{e=>27218,c=>32,a=>-118,b=>0,d=>2}
8a00200200526a
8a0020000200526a
8a0020000200526a
8a0020000200526a
=
struct toobig {
  char a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
};
-
{e=>21377,c=>115,a=>-29,b=>0,d=>3}
e3007303008153
e300730003008153
e300730003008153
e300730003008153
-
{e=>21700,c=>42,a=>-64,b=>3,d=>0}
c0032a0000c454
c0032a000000c454
c0032a000000c454
c0032a000000c454
-
{e=>20468,c=>93,a=>104,b=>0,d=>3}
68005d0300f44f
68005d000300f44f
68005d000300f44f
68005d000300f44f
-
{e=>31677,c=>22,a=>109,b=>2,d=>3}
6d02160300bd7b
6d0216000300bd7b
6d0216000300bd7b
6d0216000300bd7b
-
{e=>23636,c=>112,a=>-2,b=>1,d=>0}
fe01700000545c
fe0170000000545c
fe0170000000545c
fe0170000000545c
=
struct toobig {
  char a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
};
-
{e=>1537,c=>102,a=>-45,b=>3,d=>3,f=>0}
d303660300010600000000
d30366000300010600000000
d30366000300010600000000
d30366000300010600000000
-
{e=>22539,c=>10,a=>-66,b=>3,d=>1,f=>1}
be030a01000b5801000000
be030a0001000b5801000000
be030a0001000b5801000000
be030a0001000b5801000000
-
{e=>28767,c=>112,a=>28,b=>1,d=>1,f=>1}
1c017001005f7001000000
1c01700001005f7001000000
1c01700001005f7001000000
1c01700001005f7001000000
-
{e=>10945,c=>37,a=>-128,b=>0,d=>0,f=>1}
8000250000c12a01000000
800025000000c12a01000000
800025000000c12a01000000
800025000000c12a01000000
-
{e=>7837,c=>65,a=>-30,b=>2,d=>1,f=>2}
e2024101009d1e02000000
e202410001009d1e02000000
e202410001009d1e02000000
e202410001009d1e02000000
=
struct toobig {
  char a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
  unsigned int   g:31;
};
-
{e=>16952,c=>81,a=>-69,g=>1806494585,b=>0,d=>0,f=>1}
bb0051000038420100000079ebac6b
bb005100000038420100000079ebac6b
bb005100000038420100000079ebac6b
bb005100000038420100000079ebac6b
-
{e=>22905,c=>42,a=>28,g=>718498820,b=>3,d=>3,f=>0}
1c032a0300795900000000046cd32a
1c032a000300795900000000046cd32a
1c032a000300795900000000046cd32a
1c032a000300795900000000046cd32a
-
{e=>25314,c=>59,a=>-52,g=>851143488,b=>3,d=>3,f=>0}
cc033b0300e26200000000406bbb32
cc033b000300e26200000000406bbb32
cc033b000300e26200000000406bbb32
cc033b000300e26200000000406bbb32
-
{e=>9562,c=>91,a=>-56,g=>17470223,b=>0,d=>1,f=>0}
c8005b01005a25000000000f930a01
c8005b0001005a25000000000f930a01
c8005b0001005a25000000000f930a01
c8005b0001005a25000000000f930a01
-
{e=>19455,c=>19,a=>7,g=>1006255369,b=>0,d=>2,f=>3}
0700130200ff4b03000000093dfa3b
070013000200ff4b03000000093dfa3b
070013000200ff4b03000000093dfa3b
070013000200ff4b03000000093dfa3b
=
struct toobig {
  char a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
  unsigned int   g:31;
  unsigned char  h;
};
-
{e=>19431,a=>126,d=>3,c=>84,h=>119,b=>2,g=>10182399,f=>1}
7e02540300e74b01000000ff5e9b0077
7e0254000300e74b01000000ff5e9b007700
7e0254000300e74b01000000ff5e9b0077000000
7e0254000300e74b01000000ff5e9b0077000000
-
{e=>1236,a=>51,d=>0,c=>82,h=>240,b=>2,g=>1480777427,f=>1}
3302520000d40401000000d3de4258f0
330252000000d40401000000d3de4258f000
330252000000d40401000000d3de4258f0000000
330252000000d40401000000d3de4258f0000000
-
{e=>30136,a=>-73,d=>2,c=>69,h=>69,b=>0,g=>579636421,f=>2}
b700450200b87502000000c58c8c2245
b70045000200b87502000000c58c8c224500
b70045000200b87502000000c58c8c2245000000
b70045000200b87502000000c58c8c2245000000
-
{e=>25530,a=>-39,d=>2,c=>73,h=>143,b=>3,g=>1327623552,f=>3}
d903490200ba630300000080ed214f8f
d90349000200ba630300000080ed214f8f00
d90349000200ba630300000080ed214f8f000000
d90349000200ba630300000080ed214f8f000000
-
{e=>29715,a=>81,d=>0,c=>33,h=>85,b=>0,g=>909633605,f=>1}
510021000013740100000045e8373655
51002100000013740100000045e837365500
51002100000013740100000045e8373655000000
51002100000013740100000045e8373655000000
=
struct toobig {
  short a;
  unsigned char  b:2;
};
-
{a=>-69,b=>3}
bbff03
bbff0300
bbff0300
bbff0300
-
{a=>-109,b=>1}
93ff01
93ff0100
93ff0100
93ff0100
-
{a=>68,b=>2}
440002
44000200
44000200
44000200
-
{a=>-46,b=>1}
d2ff01
d2ff0100
d2ff0100
d2ff0100
-
{a=>109,b=>0}
6d0000
6d000000
6d000000
6d000000
=
struct toobig {
  short a;
  unsigned char  b:2;
  unsigned char  c:7;
};
-
{c=>54,a=>-126,b=>1}
82ff0136
82ff0136
82ff0136
82ff0136
-
{c=>117,a=>49,b=>0}
31000075
31000075
31000075
31000075
-
{c=>60,a=>-49,b=>3}
cfff033c
cfff033c
cfff033c
cfff033c
-
{c=>21,a=>117,b=>0}
75000015
75000015
75000015
75000015
-
{c=>6,a=>-91,b=>2}
a5ff0206
a5ff0206
a5ff0206
a5ff0206
=
struct toobig {
  short a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
};
-
{c=>126,a=>87,b=>0}
5700007e
5700007e
5700007e
5700007e
-
{c=>27,a=>-45,b=>1}
d3ff011b
d3ff011b
d3ff011b
d3ff011b
-
{c=>6,a=>-11,b=>2}
f5ff0206
f5ff0206
f5ff0206
f5ff0206
-
{c=>55,a=>63,b=>0}
3f000037
3f000037
3f000037
3f000037
-
{c=>121,a=>81,b=>0}
51000079
51000079
51000079
51000079
=
struct toobig {
  short a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
};
-
{c=>11,a=>-34,b=>0,d=>1}
deff000b0100
deff000b0100
deff000b0100
deff000b0100
-
{c=>109,a=>-11,b=>2,d=>1}
f5ff026d0100
f5ff026d0100
f5ff026d0100
f5ff026d0100
-
{c=>79,a=>-9,b=>1,d=>2}
f7ff014f0200
f7ff014f0200
f7ff014f0200
f7ff014f0200
-
{c=>12,a=>121,b=>3,d=>3}
7900030c0300
7900030c0300
7900030c0300
7900030c0300
-
{c=>3,a=>-105,b=>1,d=>0}
97ff01030000
97ff01030000
97ff01030000
97ff01030000
=
struct toobig {
  short a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
};
-
{e=>16815,c=>31,a=>-103,b=>3,d=>0}
99ff031f0000af41
99ff031f0000af41
99ff031f0000af41
99ff031f0000af41
-
{e=>30240,c=>36,a=>-51,b=>1,d=>2}
cdff012402002076
cdff012402002076
cdff012402002076
cdff012402002076
-
{e=>7916,c=>40,a=>47,b=>3,d=>1}
2f0003280100ec1e
2f0003280100ec1e
2f0003280100ec1e
2f0003280100ec1e
-
{e=>18293,c=>39,a=>19,b=>3,d=>2}
1300032702007547
1300032702007547
1300032702007547
1300032702007547
-
{e=>20458,c=>127,a=>-47,b=>1,d=>3}
d1ff017f0300ea4f
d1ff017f0300ea4f
d1ff017f0300ea4f
d1ff017f0300ea4f
=
struct toobig {
  short a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
};
-
{e=>4625,c=>71,a=>-47,b=>0,d=>0}
d1ff004700001112
d1ff004700001112
d1ff004700001112
d1ff004700001112
-
{e=>32168,c=>81,a=>26,b=>2,d=>1}
1a0002510100a87d
1a0002510100a87d
1a0002510100a87d
1a0002510100a87d
-
{e=>16938,c=>8,a=>95,b=>0,d=>2}
5f00000802002a42
5f00000802002a42
5f00000802002a42
5f00000802002a42
-
{e=>7085,c=>73,a=>-59,b=>0,d=>1}
c5ff00490100ad1b
c5ff00490100ad1b
c5ff00490100ad1b
c5ff00490100ad1b
-
{e=>22949,c=>98,a=>-95,b=>2,d=>0}
a1ff02620000a559
a1ff02620000a559
a1ff02620000a559
a1ff02620000a559
=
struct toobig {
  short a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
};
-
{e=>15082,c=>111,a=>-95,b=>0,d=>0,f=>2}
a1ff006f0000ea3a02000000
a1ff006f0000ea3a02000000
a1ff006f0000ea3a02000000
a1ff006f0000ea3a02000000
-
{e=>2765,c=>57,a=>35,b=>3,d=>0,f=>3}
230003390000cd0a03000000
230003390000cd0a03000000
230003390000cd0a03000000
230003390000cd0a03000000
-
{e=>10395,c=>112,a=>-21,b=>2,d=>3,f=>1}
ebff027003009b2801000000
ebff027003009b2801000000
ebff027003009b2801000000
ebff027003009b2801000000
-
{e=>27935,c=>81,a=>-93,b=>3,d=>1,f=>3}
a3ff035101001f6d03000000
a3ff035101001f6d03000000
a3ff035101001f6d03000000
a3ff035101001f6d03000000
-
{e=>9978,c=>10,a=>-112,b=>2,d=>1,f=>0}
90ff020a0100fa2600000000
90ff020a0100fa2600000000
90ff020a0100fa2600000000
90ff020a0100fa2600000000
=
struct toobig {
  short a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
  unsigned int   g:31;
};
-
{e=>7540,c=>19,a=>-11,g=>1471494247,b=>0,d=>2,f=>2}
f5ff00130200741d020000006738b557
f5ff00130200741d020000006738b557
f5ff00130200741d020000006738b557
f5ff00130200741d020000006738b557
-
{e=>21082,c=>15,a=>-52,g=>380642011,b=>2,d=>3,f=>0}
ccff020f03005a5200000000db22b016
ccff020f03005a5200000000db22b016
ccff020f03005a5200000000db22b016
ccff020f03005a5200000000db22b016
-
{e=>20626,c=>108,a=>-96,g=>1260212640,b=>2,d=>1,f=>2}
a0ff026c0100925002000000a0511d4b
a0ff026c0100925002000000a0511d4b
a0ff026c0100925002000000a0511d4b
a0ff026c0100925002000000a0511d4b
-
{e=>9472,c=>8,a=>-4,g=>1691591019,b=>2,d=>1,f=>2}
fcff020801000025020000006ba1d364
fcff020801000025020000006ba1d364
fcff020801000025020000006ba1d364
fcff020801000025020000006ba1d364
-
{e=>9356,c=>8,a=>78,g=>959851153,b=>3,d=>3,f=>2}
4e00030803008c2402000000912a3639
4e00030803008c2402000000912a3639
4e00030803008c2402000000912a3639
4e00030803008c2402000000912a3639
=
struct toobig {
  short a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
  unsigned int   g:31;
  unsigned char  h;
};
-
{e=>15569,a=>49,d=>0,c=>98,h=>100,b=>2,g=>783521155,f=>1}
310002620000d13c010000008395b32e64
310002620000d13c010000008395b32e6400
310002620000d13c010000008395b32e64000000
310002620000d13c010000008395b32e64000000
-
{e=>16972,a=>63,d=>1,c=>69,h=>90,b=>2,g=>609013294,f=>3}
3f00024501004c42030000002ece4c245a
3f00024501004c42030000002ece4c245a00
3f00024501004c42030000002ece4c245a000000
3f00024501004c42030000002ece4c245a000000
-
{e=>28524,a=>82,d=>1,c=>98,h=>95,b=>0,g=>948610449,f=>0}
5200006201006c6f0000000091a58a385f
5200006201006c6f0000000091a58a385f00
5200006201006c6f0000000091a58a385f000000
5200006201006c6f0000000091a58a385f000000
-
{e=>15555,a=>-7,d=>0,c=>124,h=>184,b=>1,g=>1579365922,f=>3}
f9ff017c0000c33c030000002236235eb8
f9ff017c0000c33c030000002236235eb800
f9ff017c0000c33c030000002236235eb8000000
f9ff017c0000c33c030000002236235eb8000000
-
{e=>30807,a=>89,d=>3,c=>74,h=>1,b=>3,g=>681792943,f=>3}
5900034a0300577803000000af55a32801
5900034a0300577803000000af55a3280100
5900034a0300577803000000af55a32801000000
5900034a0300577803000000af55a32801000000
=
struct toobig {
  int a;
  unsigned char  b:2;
};
-
{a=>95,b=>2}
5f00000002
5f0000000200
5f00000002000000
5f00000002000000
-
{a=>81,b=>1}
5100000001
510000000100
5100000001000000
5100000001000000
-
{a=>-17,b=>1}
efffffff01
efffffff0100
efffffff01000000
efffffff01000000
-
{a=>-1,b=>2}
ffffffff02
ffffffff0200
ffffffff02000000
ffffffff02000000
-
{a=>117,b=>2}
7500000002
750000000200
7500000002000000
7500000002000000
=
struct toobig {
  int a;
  unsigned char  b:2;
  unsigned char  c:7;
};
-
{c=>67,a=>69,b=>0}
450000000043
450000000043
4500000000430000
4500000000430000
-
{c=>61,a=>-71,b=>3}
b9ffffff033d
b9ffffff033d
b9ffffff033d0000
b9ffffff033d0000
-
{c=>36,a=>-65,b=>0}
bfffffff0024
bfffffff0024
bfffffff00240000
bfffffff00240000
-
{c=>115,a=>-65,b=>2}
bfffffff0273
bfffffff0273
bfffffff02730000
bfffffff02730000
-
{c=>98,a=>-9,b=>1}
f7ffffff0162
f7ffffff0162
f7ffffff01620000
f7ffffff01620000
=
struct toobig {
  int a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
};
-
{c=>110,a=>-90,b=>2}
a6ffffff026e
a6ffffff026e
a6ffffff026e0000
a6ffffff026e0000
-
{c=>89,a=>109,b=>3}
6d0000000359
6d0000000359
6d00000003590000
6d00000003590000
-
{c=>119,a=>55,b=>2}
370000000277
370000000277
3700000002770000
3700000002770000
-
{c=>78,a=>-95,b=>2}
a1ffffff024e
a1ffffff024e
a1ffffff024e0000
a1ffffff024e0000
-
{c=>108,a=>-76,b=>2}
b4ffffff026c
b4ffffff026c
b4ffffff026c0000
b4ffffff026c0000
=
struct toobig {
  int a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
};
-
{c=>67,a=>-11,b=>2,d=>2}
f5ffffff02430200
f5ffffff02430200
f5ffffff02430200
f5ffffff02430200
-
{c=>94,a=>-43,b=>2,d=>0}
d5ffffff025e0000
d5ffffff025e0000
d5ffffff025e0000
d5ffffff025e0000
-
{c=>13,a=>12,b=>0,d=>3}
0c000000000d0300
0c000000000d0300
0c000000000d0300
0c000000000d0300
-
{c=>20,a=>75,b=>1,d=>3}
4b00000001140300
4b00000001140300
4b00000001140300
4b00000001140300
-
{c=>16,a=>99,b=>2,d=>0}
6300000002100000
6300000002100000
6300000002100000
6300000002100000
=
struct toobig {
  int a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
};
-
{e=>15944,c=>81,a=>-88,b=>1,d=>1}
a8ffffff01510100483e
a8ffffff01510100483e
a8ffffff01510100483e0000
a8ffffff01510100483e0000
-
{e=>28784,c=>113,a=>-26,b=>3,d=>2}
e6ffffff037102007070
e6ffffff037102007070
e6ffffff0371020070700000
e6ffffff0371020070700000
-
{e=>25323,c=>4,a=>3,b=>2,d=>3}
0300000002040300eb62
0300000002040300eb62
0300000002040300eb620000
0300000002040300eb620000
-
{e=>5631,c=>25,a=>126,b=>2,d=>2}
7e00000002190200ff15
7e00000002190200ff15
7e00000002190200ff150000
7e00000002190200ff150000
-
{e=>30242,c=>81,a=>43,b=>1,d=>2}
2b000000015102002276
2b000000015102002276
2b0000000151020022760000
2b0000000151020022760000
=
struct toobig {
  int a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
};
-
{e=>26399,c=>49,a=>-62,b=>2,d=>1}
c2ffffff023101001f67
c2ffffff023101001f67
c2ffffff023101001f670000
c2ffffff023101001f670000
-
{e=>29626,c=>6,a=>-98,b=>2,d=>1}
9effffff02060100ba73
9effffff02060100ba73
9effffff02060100ba730000
9effffff02060100ba730000
-
{e=>10198,c=>108,a=>64,b=>2,d=>1}
40000000026c0100d627
40000000026c0100d627
40000000026c0100d6270000
40000000026c0100d6270000
-
{e=>10521,c=>124,a=>34,b=>0,d=>3}
22000000007c03001929
22000000007c03001929
22000000007c030019290000
22000000007c030019290000
-
{e=>25536,c=>37,a=>88,b=>3,d=>3}
5800000003250300c063
5800000003250300c063
5800000003250300c0630000
5800000003250300c0630000
=
struct toobig {
  int a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
};
-
{e=>22897,c=>65,a=>-113,b=>1,d=>3,f=>2}
8fffffff01410300715902000000
8fffffff01410300715902000000
8fffffff014103007159000002000000
8fffffff014103007159000002000000
-
{e=>28655,c=>21,a=>107,b=>1,d=>3,f=>0}
6b00000001150300ef6f00000000
6b00000001150300ef6f00000000
6b00000001150300ef6f000000000000
6b00000001150300ef6f000000000000
-
{e=>11486,c=>82,a=>27,b=>0,d=>2,f=>1}
1b00000000520200de2c01000000
1b00000000520200de2c01000000
1b00000000520200de2c000001000000
1b00000000520200de2c000001000000
-
{e=>8829,c=>47,a=>-44,b=>2,d=>1,f=>3}
d4ffffff022f01007d2203000000
d4ffffff022f01007d2203000000
d4ffffff022f01007d22000003000000
d4ffffff022f01007d22000003000000
-
{e=>24395,c=>33,a=>-122,b=>1,d=>0,f=>0}
86ffffff012100004b5f00000000
86ffffff012100004b5f00000000
86ffffff012100004b5f000000000000
86ffffff012100004b5f000000000000
=
struct toobig {
  int a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
  unsigned int   g:31;
};
-
{e=>21026,c=>66,a=>92,g=>1659281310,b=>0,d=>2,f=>1}
5c000000004202002252010000009e9fe662
5c000000004202002252010000009e9fe662
5c0000000042020022520000010000009e9fe662
5c0000000042020022520000010000009e9fe662
-
{e=>12920,c=>104,a=>10,g=>2107984876,b=>2,d=>2,f=>2}
0a00000002680200783202000000ec4ba57d
0a00000002680200783202000000ec4ba57d
0a000000026802007832000002000000ec4ba57d
0a000000026802007832000002000000ec4ba57d
-
{e=>3821,c=>93,a=>-11,g=>664990743,b=>1,d=>0,f=>0}
f5ffffff015d0000ed0e0000000017f4a227
f5ffffff015d0000ed0e0000000017f4a227
f5ffffff015d0000ed0e00000000000017f4a227
f5ffffff015d0000ed0e00000000000017f4a227
-
{e=>5353,c=>99,a=>-47,g=>171749847,b=>0,d=>1,f=>1}
d1ffffff00630100e91401000000d7b13c0a
d1ffffff00630100e91401000000d7b13c0a
d1ffffff00630100e914000001000000d7b13c0a
d1ffffff00630100e914000001000000d7b13c0a
-
{e=>3580,c=>89,a=>24,g=>668072177,b=>3,d=>3,f=>0}
1800000003590300fc0d00000000f1f8d127
1800000003590300fc0d00000000f1f8d127
1800000003590300fc0d000000000000f1f8d127
1800000003590300fc0d000000000000f1f8d127
=
struct toobig {
  int a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
  unsigned int   g:31;
  unsigned char  h;
};
-
{e=>26214,a=>3,d=>3,c=>2,h=>13,b=>0,g=>1018602210,f=>1}
0300000000020300666601000000e2a2b63c0d
0300000000020300666601000000e2a2b63c0d00
03000000000203006666000001000000e2a2b63c0d000000
03000000000203006666000001000000e2a2b63c0d000000
-
{e=>1638,a=>90,d=>0,c=>29,h=>15,b=>0,g=>1932291266,f=>2}
5a000000001d0000660602000000c26c2c730f
5a000000001d0000660602000000c26c2c730f00
5a000000001d00006606000002000000c26c2c730f000000
5a000000001d00006606000002000000c26c2c730f000000
-
{e=>19392,a=>98,d=>2,c=>117,h=>142,b=>2,g=>1646528382,f=>3}
6200000002750200c04b030000007e0724628e
6200000002750200c04b030000007e0724628e00
6200000002750200c04b0000030000007e0724628e000000
6200000002750200c04b0000030000007e0724628e000000
-
{e=>9394,a=>18,d=>2,c=>23,h=>96,b=>0,g=>1695469510,f=>0}
1200000000170200b22400000000c6cf0e6560
1200000000170200b22400000000c6cf0e656000
1200000000170200b224000000000000c6cf0e6560000000
1200000000170200b224000000000000c6cf0e6560000000
-
{e=>21676,a=>69,d=>2,c=>106,h=>240,b=>1,g=>2126836617,f=>2}
45000000016a0200ac540200000089f3c47ef0
45000000016a0200ac540200000089f3c47ef000
45000000016a0200ac5400000200000089f3c47ef0000000
45000000016a0200ac5400000200000089f3c47ef0000000
=
struct toobig {
  long a;
  unsigned char  b:2;
};
-
{a=>-12,b=>2}
f4ffffff02
f4ffffff0200
f4ffffff02000000
f4ffffff02000000
-
{a=>0,b=>1}
0000000001
000000000100
0000000001000000
0000000001000000
-
{a=>60,b=>2}
3c00000002
3c0000000200
3c00000002000000
3c00000002000000
-
{a=>61,b=>3}
3d00000003
3d0000000300
3d00000003000000
3d00000003000000
-
{a=>122,b=>1}
7a00000001
7a0000000100
7a00000001000000
7a00000001000000
=
struct toobig {
  long a;
  unsigned char  b:2;
  unsigned char  c:7;
};
-
{c=>127,a=>-21,b=>2}
ebffffff027f
ebffffff027f
ebffffff027f0000
ebffffff027f0000
-
{c=>6,a=>-60,b=>0}
c4ffffff0006
c4ffffff0006
c4ffffff00060000
c4ffffff00060000
-
{c=>118,a=>-112,b=>2}
90ffffff0276
90ffffff0276
90ffffff02760000
90ffffff02760000
-
{c=>100,a=>-92,b=>3}
a4ffffff0364
a4ffffff0364
a4ffffff03640000
a4ffffff03640000
-
{c=>11,a=>123,b=>1}
7b000000010b
7b000000010b
7b000000010b0000
7b000000010b0000
=
struct toobig {
  long a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
};
-
{c=>82,a=>18,b=>3}
120000000352
120000000352
1200000003520000
1200000003520000
-
{c=>34,a=>45,b=>2}
2d0000000222
2d0000000222
2d00000002220000
2d00000002220000
-
{c=>18,a=>-66,b=>2}
beffffff0212
beffffff0212
beffffff02120000
beffffff02120000
-
{c=>41,a=>53,b=>1}
350000000129
350000000129
3500000001290000
3500000001290000
-
{c=>97,a=>60,b=>0}
3c0000000061
3c0000000061
3c00000000610000
3c00000000610000
=
struct toobig {
  long a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
};
-
{c=>124,a=>18,b=>1,d=>1}
12000000017c0100
12000000017c0100
12000000017c0100
12000000017c0100
-
{c=>4,a=>-25,b=>3,d=>0}
e7ffffff03040000
e7ffffff03040000
e7ffffff03040000
e7ffffff03040000
-
{c=>9,a=>8,b=>0,d=>2}
0800000000090200
0800000000090200
0800000000090200
0800000000090200
-
{c=>74,a=>-10,b=>2,d=>3}
f6ffffff024a0300
f6ffffff024a0300
f6ffffff024a0300
f6ffffff024a0300
-
{c=>20,a=>-100,b=>0,d=>3}
9cffffff00140300
9cffffff00140300
9cffffff00140300
9cffffff00140300
=
struct toobig {
  long a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
};
-
{e=>8288,c=>27,a=>27,b=>1,d=>0}
1b000000011b00006020
1b000000011b00006020
1b000000011b000060200000
1b000000011b000060200000
-
{e=>31476,c=>62,a=>15,b=>2,d=>0}
0f000000023e0000f47a
0f000000023e0000f47a
0f000000023e0000f47a0000
0f000000023e0000f47a0000
-
{e=>28645,c=>102,a=>-2,b=>0,d=>3}
feffffff00660300e56f
feffffff00660300e56f
feffffff00660300e56f0000
feffffff00660300e56f0000
-
{e=>5175,c=>47,a=>123,b=>3,d=>3}
7b000000032f03003714
7b000000032f03003714
7b000000032f030037140000
7b000000032f030037140000
-
{e=>3986,c=>9,a=>92,b=>2,d=>2}
5c00000002090200920f
5c00000002090200920f
5c00000002090200920f0000
5c00000002090200920f0000
=
struct toobig {
  long a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
};
-
{e=>26564,c=>47,a=>75,b=>2,d=>1}
4b000000022f0100c467
4b000000022f0100c467
4b000000022f0100c4670000
4b000000022f0100c4670000
-
{e=>13162,c=>83,a=>-7,b=>3,d=>2}
f9ffffff035302006a33
f9ffffff035302006a33
f9ffffff035302006a330000
f9ffffff035302006a330000
-
{e=>21769,c=>111,a=>-87,b=>3,d=>2}
a9ffffff036f02000955
a9ffffff036f02000955
a9ffffff036f020009550000
a9ffffff036f020009550000
-
{e=>5436,c=>68,a=>-101,b=>3,d=>0}
9bffffff034400003c15
9bffffff034400003c15
9bffffff034400003c150000
9bffffff034400003c150000
-
{e=>13380,c=>90,a=>86,b=>2,d=>0}
56000000025a00004434
56000000025a00004434
56000000025a000044340000
56000000025a000044340000
=
struct toobig {
  long a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
};
-
{e=>23505,c=>0,a=>-30,b=>2,d=>3,f=>3}
e2ffffff02000300d15b03000000
e2ffffff02000300d15b03000000
e2ffffff02000300d15b000003000000
e2ffffff02000300d15b000003000000
-
{e=>29524,c=>34,a=>72,b=>2,d=>2,f=>0}
4800000002220200547300000000
4800000002220200547300000000
48000000022202005473000000000000
48000000022202005473000000000000
-
{e=>8502,c=>60,a=>85,b=>1,d=>1,f=>1}
55000000013c0100362101000000
55000000013c0100362101000000
55000000013c01003621000001000000
55000000013c01003621000001000000
-
{e=>3686,c=>42,a=>-13,b=>2,d=>0,f=>1}
f3ffffff022a0000660e01000000
f3ffffff022a0000660e01000000
f3ffffff022a0000660e000001000000
f3ffffff022a0000660e000001000000
-
{e=>26261,c=>48,a=>-62,b=>1,d=>0,f=>1}
c2ffffff01300000956601000000
c2ffffff01300000956601000000
c2ffffff013000009566000001000000
c2ffffff013000009566000001000000
=
struct toobig {
  long a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
  unsigned int   g:31;
};
-
{e=>25271,c=>5,a=>23,g=>1549434592,b=>0,d=>0,f=>3}
1700000000050000b76203000000e07e5a5c
1700000000050000b76203000000e07e5a5c
1700000000050000b762000003000000e07e5a5c
1700000000050000b762000003000000e07e5a5c
-
{e=>29769,c=>70,a=>53,g=>485498167,b=>3,d=>3,f=>3}
3500000003460300497403000000371df01c
3500000003460300497403000000371df01c
35000000034603004974000003000000371df01c
35000000034603004974000003000000371df01c
-
{e=>4324,c=>68,a=>105,g=>554750747,b=>0,d=>0,f=>1}
6900000000440000e410010000001bd31021
6900000000440000e410010000001bd31021
6900000000440000e4100000010000001bd31021
6900000000440000e4100000010000001bd31021
-
{e=>17511,c=>94,a=>58,g=>250165519,b=>2,d=>2,f=>3}
3a000000025e02006744030000000f39e90e
3a000000025e02006744030000000f39e90e
3a000000025e020067440000030000000f39e90e
3a000000025e020067440000030000000f39e90e
-
{e=>14283,c=>79,a=>-97,g=>1714885120,b=>1,d=>2,f=>1}
9fffffff014f0200cb370100000000123766
9fffffff014f0200cb370100000000123766
9fffffff014f0200cb3700000100000000123766
9fffffff014f0200cb3700000100000000123766
=
struct toobig {
  long a;
  unsigned char  b:2;
  unsigned char  c:7;
  short           :0;
  unsigned short d:2;
  unsigned short e:15;
  int             :0;
  unsigned int   f:2;
  unsigned int   g:31;
  unsigned char  h;
};
-
{e=>22593,a=>-105,d=>2,c=>125,h=>86,b=>2,g=>490502662,f=>2}
97ffffff027d0200415802000000067a3c1d56
97ffffff027d0200415802000000067a3c1d5600
97ffffff027d02004158000002000000067a3c1d56000000
97ffffff027d02004158000002000000067a3c1d56000000
-
{e=>22467,a=>-25,d=>0,c=>60,h=>208,b=>0,g=>371229021,f=>0}
e7ffffff003c0000c357000000005d812016d0
e7ffffff003c0000c357000000005d812016d000
e7ffffff003c0000c3570000000000005d812016d0000000
e7ffffff003c0000c3570000000000005d812016d0000000
-
{e=>31600,a=>-7,d=>2,c=>78,h=>234,b=>0,g=>1056003073,f=>2}
f9ffffff004e0200707b020000000154f13eea
f9ffffff004e0200707b020000000154f13eea00
f9ffffff004e0200707b0000020000000154f13eea000000
f9ffffff004e0200707b0000020000000154f13eea000000
-
{e=>12252,a=>38,d=>2,c=>1,h=>15,b=>1,g=>1441179725,f=>2}
2600000001010200dc2f020000004da8e6550f
2600000001010200dc2f020000004da8e6550f00
2600000001010200dc2f0000020000004da8e6550f000000
2600000001010200dc2f0000020000004da8e6550f000000
-
{e=>29268,a=>28,d=>0,c=>18,h=>157,b=>1,g=>2064430442,f=>1}
1c000000011200005472010000006ab50c7b9d
1c000000011200005472010000006ab50c7b9d00
1c0000000112000054720000010000006ab50c7b9d000000
1c0000000112000054720000010000006ab50c7b9d000000
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct toobig_pack_1 {
  unsigned char  a:2;
};
-
{a=>2}
02
02
02
02
-
{a=>3}
03
03
03
03
-
{a=>0}
00
00
00
00
-
{a=>3}
03
03
03
03
-
{a=>1}
01
01
01
01
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct toobig_pack_1 {
  unsigned char  a:2;
  unsigned char  b:7;
};
-
{a=>3,b=>122}
037a
037a
037a
037a
-
{a=>0,b=>7}
0007
0007
0007
0007
-
{a=>3,b=>2}
0302
0302
0302
0302
-
{a=>1,b=>102}
0166
0166
0166
0166
-
{a=>1,b=>57}
0139
0139
0139
0139
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct toobig_pack_1 {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
};
-
{a=>3,b=>86}
0356
0356
0356
0356
-
{a=>2,b=>116}
0274
0274
0274
0274
-
{a=>2,b=>29}
021d
021d
021d
021d
-
{a=>3,b=>95}
035f
035f
035f
035f
-
{a=>1,b=>22}
0116
0116
0116
0116
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct toobig_pack_1 {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
};
-
{c=>0,a=>1,b=>74}
014a0000
014a0000
014a0000
014a0000
-
{c=>0,a=>2,b=>114}
02720000
02720000
02720000
02720000
-
{c=>2,a=>3,b=>123}
037b0200
037b0200
037b0200
037b0200
-
{c=>1,a=>2,b=>78}
024e0100
024e0100
024e0100
024e0100
-
{c=>1,a=>2,b=>67}
02430100
02430100
02430100
02430100
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct toobig_pack_1 {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
  unsigned short d:15;
};
-
{c=>0,a=>2,b=>89,d=>17148}
02590000fc42
02590000fc42
02590000fc42
02590000fc42
-
{c=>3,a=>3,b=>1,d=>7923}
03010300f31e
03010300f31e
03010300f31e
03010300f31e
-
{c=>3,a=>3,b=>36,d=>24620}
032403002c60
032403002c60
032403002c60
032403002c60
-
{c=>1,a=>1,b=>110,d=>27219}
016e0100536a
016e0100536a
016e0100536a
016e0100536a
-
{c=>1,a=>2,b=>119,d=>25127}
027701002762
027701002762
027701002762
027701002762
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct toobig_pack_1 {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
  unsigned short d:15;
  int             :0;
};
-
{c=>2,a=>1,b=>55,d=>24370}
01370200325f
01370200325f
01370200325f
01370200325f
-
{c=>3,a=>1,b=>76,d=>484}
014c0300e401
014c0300e401
014c0300e401
014c0300e401
-
{c=>3,a=>0,b=>72,d=>28441}
00480300196f
00480300196f
00480300196f
00480300196f
-
{c=>0,a=>1,b=>4,d=>20335}
010400006f4f
010400006f4f
010400006f4f
010400006f4f
-
{c=>1,a=>3,b=>108,d=>25748}
036c01009464
036c01009464
036c01009464
036c01009464
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct toobig_pack_1 {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
  unsigned short d:15;
  int             :0;
  unsigned int   e:2;
};
-
{e=>2,c=>1,a=>3,b=>25,d=>14129}
03190100313702000000
03190100313702000000
03190100313702000000
03190100313702000000
-
{e=>2,c=>1,a=>0,b=>43,d=>29105}
002b0100b17102000000
002b0100b17102000000
002b0100b17102000000
002b0100b17102000000
-
{e=>2,c=>0,a=>2,b=>27,d=>17807}
021b00008f4502000000
021b00008f4502000000
021b00008f4502000000
021b00008f4502000000
-
{e=>3,c=>0,a=>0,b=>93,d=>809}
005d0000290303000000
005d0000290303000000
005d0000290303000000
005d0000290303000000
-
{e=>0,c=>3,a=>1,b=>44,d=>30562}
012c0300627700000000
012c0300627700000000
012c0300627700000000
012c0300627700000000
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct toobig_pack_1 {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
  unsigned short d:15;
  int             :0;
  unsigned int   e:2;
  unsigned int   f:31;
};
-
{e=>3,c=>2,a=>2,b=>10,d=>5501,f=>1254374167}
020a02007d1503000000173bc44a
020a02007d1503000000173bc44a
020a02007d1503000000173bc44a
020a02007d1503000000173bc44a
-
{e=>0,c=>3,a=>3,b=>108,d=>4783,f=>549387562}
036c0300af12000000002afdbe20
036c0300af12000000002afdbe20
036c0300af12000000002afdbe20
036c0300af12000000002afdbe20
-
{e=>2,c=>1,a=>1,b=>71,d=>5216,f=>457981324}
014701006014020000008c3d4c1b
014701006014020000008c3d4c1b
014701006014020000008c3d4c1b
014701006014020000008c3d4c1b
-
{e=>0,c=>1,a=>0,b=>108,d=>3389,f=>260729659}
006c01003d0d000000003b6b8a0f
006c01003d0d000000003b6b8a0f
006c01003d0d000000003b6b8a0f
006c01003d0d000000003b6b8a0f
-
{e=>2,c=>3,a=>3,b=>78,d=>9795,f=>22588338}
034e0300432602000000b2ab5801
034e0300432602000000b2ab5801
034e0300432602000000b2ab5801
034e0300432602000000b2ab5801
=
#if defined PACK_PAREN
#pragma pack( 1 )
#elif defined PACK_NO_PAREN
#pragma pack 1
#endif
struct toobig_pack_1 {
  unsigned char  a:2;
  unsigned char  b:7;
  short           :0;
  unsigned short c:2;
  unsigned short d:15;
  int             :0;
  unsigned int   e:2;
  unsigned int   f:31;
  unsigned char  g;
};
-
{e=>0,c=>0,a=>3,g=>96,b=>9,d=>3499,f=>226878349}
03090000ab0d000000008de3850d60
03090000ab0d000000008de3850d60
03090000ab0d000000008de3850d60
03090000ab0d000000008de3850d60
-
{e=>2,c=>0,a=>0,g=>93,b=>30,d=>5449,f=>524944825}
001e0000491502000000b9054a1f5d
