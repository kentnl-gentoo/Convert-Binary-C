################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2003/02/27 19:27:43 +0100 $
# $Revision: 5 $
# $Snapshot: /Convert-Binary-C/0.12 $
# $Source: /t/109_sourcify.t $
#
################################################################################
# 
# Copyright (c) 2002-2003 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
# 
################################################################################

use Test;
use Convert::Binary::C @ARGV;

$^W = 1;

BEGIN { plan tests => 54 }

eval {
  $orig  = new Convert::Binary::C Include => ['t/include/perlinc',
                                              't/include/include'];
  @clone = map { new Convert::Binary::C } 1 .. 2;
};
ok($@,'',"failed to create Convert::Binary::C objects");

eval {
  $orig->parse_file( 't/include/include.c' );
  $orig->parse( <<ENDPARSE );
  enum __foobar__;
  enum __undefined__;
ENDPARSE
};
ok($@,'',"failed to parse C-file");

eval {
  $dump1 = $orig->sourcify;
  $dump2 = $orig->sourcify;
  $dump3 = $orig->sourcify;
};
ok($@,'',"failed to dump definitions");

ok( $dump1, $dump2, "dumps 1+2 differ" );
ok( $dump2, $dump3, "dumps 2+3 differ" );

eval {
  $clone[0]->parse( $orig->sourcify );
};
ok($@,'',"failed to parse clone data (0)");

eval {
  $clone[1]->parse( $clone[0]->sourcify );
};
ok($@,'',"failed to parse clone data (1)");

for my $meth ( qw( enum compound struct union typedef ) ) {
  my $meth_names = $meth.'_names';
  my @orig_names = sort $orig->$meth_names();

  print "# checking if any names exist\n";
  ok( @orig_names > 0 );

  for my $c ( 0 .. $#clone ) {
    print "# checking counts for \$clone[$c]->$meth_names\n";
    ok(scalar $orig->$_(), scalar $clone[$c]->$_(), "count mismatch in $_ ($c)")
        for $meth, $meth_names;

    print "# checking parsed names for \$clone[$c]->$meth_names\n";
    ok(join( ',', @orig_names ),
       join( ',', sort $clone[$c]->$meth_names() ),
       "parsed names differ in $meth_names ($c)" );

    ok( scalar grep $_, map {
          print "# checking \$clone[$c]->$meth( \"$_\" )\n";
          reccmp($orig->$meth($_), $clone[$c]->$meth($_))
        } @orig_names );
  }
}

eval {
  $orig->clean->parse( <<ENDC );
typedef struct { struct B *x; } A;
typedef struct B { A *x; } B;
ENDC
};

ok($@,'',"failed to parse C code");

eval {
  $clone[0]->parse( $orig->sourcify );
};
ok($@,'',"failed to parse sourcified code");


sub reccmp
{
  my($ref, $val) = @_;

  ref $ref or return $ref eq $val;

  if( ref $ref eq 'ARRAY' ) {
    @$ref == @$val or return 0;
    for( 0..$#$ref ) {
      reccmp( $ref->[$_], $val->[$_] ) or return 0;
    }
  }
  elsif( ref $ref eq 'HASH' ) {
    @{[keys %$ref]} == @{[keys %$val]} or return 0;
    for( keys %$ref ) {
      reccmp( $ref->{$_}, $val->{$_} ) or return 0;
    }
  }
  else { return 0 }

  return 1;
}
