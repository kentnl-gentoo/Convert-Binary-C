################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2008/04/15 15:37:46 +0200 $
# $Revision: 4 $
# $Source: /xsubs/clone.xs $
#
################################################################################
#
# Copyright (c) 2002-2008 Marcus Holland-Moritz. All rights reserved.
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
#
################################################################################


################################################################################
#
#   METHOD: clone
#
#   WRITTEN BY: Marcus Holland-Moritz             ON: Oct 2002
#   CHANGED BY:                                   ON:
#
################################################################################

void
CBC::clone()
  PREINIT:
    CBC_METHOD(clone);
    CBC *clone;
    const char *class;

  PPCODE:
    CT_DEBUG_METHOD;

    CHECK_VOID_CONTEXT;

    class = HvNAME(SvSTASH(SvRV(ST(0))));
    clone = cbc_clone(aTHX_ THIS);

    ST(0) = sv_2mortal(cbc_bless(aTHX_ clone, class));

    XSRETURN(1);

