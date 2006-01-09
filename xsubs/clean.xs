################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2006/01/01 10:38:27 +0100 $
# $Revision: 2 $
# $Source: /xsubs/clean.xs $
#
################################################################################
#
# Copyright (c) 2002-2006 Marcus Holland-Moritz. All rights reserved.
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

