################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2005/02/06 16:57:06 +0100 $
# $Revision: 1 $
# $Source: /xsubs/clean.xs $
#
################################################################################
#
# Copyright (c) 2002-2005 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
#
################################################################################


################################################################################
#
#   METHOD: clean
#
#   WRITTEN BY: Marcus Holland-Moritz             ON: Oct 2002
#   CHANGED BY:                                   ON:
#
################################################################################

void
CBC::clean()
  PREINIT:
    CBC_METHOD(clean);

  CODE:
    CT_DEBUG_METHOD;

    free_parse_info(&THIS->cpi);

    if (GIMME_V != G_VOID)
      XSRETURN(1);

