################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2004/03/22 20:38:05 +0100 $
# $Revision: 7 $
# $Snapshot: /Convert-Binary-C/0.53 $
# $Source: /t/806_env.t $
#
################################################################################
#
# Copyright (c) 2002-2004 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
#
################################################################################

use Test;

$^W = 1;

BEGIN { plan tests => 16 }

$ENV{CBC_DISABLE_PARSER} = 1;
$ENV{CBC_ORDER_MEMBERS} = 1;

eval { require Tie::Hash::Indexed };
$@ and eval { require Tie::IxHash };
$ixhash = $@ ? '' : 'indexed hash module is installed';

@warn = ();
$SIG{__WARN__} = sub { push @warn, $_[0] };
sub chkwarn {
  my $fail = 0;
  if( @warn != @_ ) {
    print "# wrong number of warnings (got ", scalar @warn,
                               ", expected ", scalar @_, ")\n";
    $fail++;
  }
  for my $ix ( 0 .. $#_ ) {
    my $e = $_[$ix];
    my $w = $warn[$ix];
    unless( $w =~ ref($e) ? $e : qr/\Q$e\E/ ) {
      print "# wrong warning, expected $e, got $w\n";
      $fail++;
    }
  }
  if( $fail ) { print "# $_" for @warn }
  ok( $fail, 0, "warnings check failed" );
  @warn = ();
}


eval { require Convert::Binary::C };
ok( $@, '', "could not require Convert::Binary::C" );
chkwarn();

@w= ( qr/^Convert::Binary::C parser is DISABLED/ );
$ixhash or push @w, qr/^Couldn't load a module for member ordering/;

$c = eval { new Convert::Binary::C };
ok( $@, '', "could not create Convert::Binary::C object" );
chkwarn( @w );
ok( $c->OrderMembers, 1 );
chkwarn();
$c->OrderMembers(0);
chkwarn();
ok( $c->OrderMembers, 0 );
chkwarn();

$c = eval { new Convert::Binary::C OrderMembers => 0 };
ok( $@, '', "could not create Convert::Binary::C object" );
chkwarn( $w[0] );
ok( $c->OrderMembers, 0 );
chkwarn();
$c->OrderMembers(1);
chkwarn( $ixhash ? () : $w[1] );
ok( $c->OrderMembers, 1 );
chkwarn();

