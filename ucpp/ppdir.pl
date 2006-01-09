################################################################################
#
# PROGRAM: ppdir.pl
#
################################################################################
#
# DESCRIPTION: Generate tokenizer code for C preprocessor directives
#
################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2006/01/01 10:38:25 +0100 $
# $Revision: 2 $
# $Source: /ucpp/ppdir.pl $
#
################################################################################
#
# Copyright (c) 2004-2006 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
#
################################################################################

use Devel::Tokenizer::C;
use strict;

my @PP = qw(
  define
  undef
  if
  ifdef
  ifndef
  else
  elif
  endif
  include
  include_next
  pragma
  error
  line
  assert
  unassert
  ident
);

my $file = shift;
my $enums  = join "\n", map "  PPDIR_\U$_\E,", @PP;
my $switch = Devel::Tokenizer::C->new(TokenFunc => sub { "return PPDIR_\U$_[0]\E;\n" },
                                      TokenString => 'ppdir')
                                ->add_tokens(@PP)->generate;

open OUT, ">$file" or die $!;

print OUT <<END;
static enum {
$enums
  PPDIR_UNKNOWN
}
scan_pp_directive(const char *ppdir)
{
$switch
unknown:
  return PPDIR_UNKNOWN;
}
END

close OUT;

