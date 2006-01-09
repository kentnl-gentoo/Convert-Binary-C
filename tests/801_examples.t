################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2006/01/01 10:38:22 +0100 $
# $Revision: 8 $
# $Source: /tests/801_examples.t $
#
################################################################################
#
# Copyright (c) 2002-2006 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
#
################################################################################

use Test;
use Convert::Binary::C @ARGV;

$^W = 1;

BEGIN {
  @files = <examples/*.pl>;
  plan tests => 1 + 3*@files;
}

ok( @files > 0 );

$perl  = "$^X -w " . join( ' ', map qq["-I$_"], @INC );

for my $ex ( @files ) {
  my $out = '';
  my $open;

  print "# checking '$ex'\n";

  if( $open = open FILE, "$perl $ex |" ) {
    $out = do { local $/; <FILE> };
    close FILE;
  }

  ok( $open );
  ok( length($out) > 0 );
  ok( $?, 0 );
}
