################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2005/02/21 10:18:43 +0100 $
# $Revision: 2 $
# $Source: /xsubs/initializer.xs $
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
#   METHOD: initializer
#
#   WRITTEN BY: Marcus Holland-Moritz             ON: Jun 2003
#   CHANGED BY:                                   ON:
#
################################################################################

SV *
CBC::initializer(type, init = &PL_sv_undef)
  const char *type
  SV *init

  PREINIT:
    CBC_METHOD(initializer);
    MemberInfo mi;

  CODE:
    CT_DEBUG_METHOD1("'%s'", type);

    CHECK_VOID_CONTEXT;

    if (!get_member_info(aTHX_ THIS, type, &mi))
      Perl_croak(aTHX_ "Cannot find '%s'", type);

    SvGETMAGIC(init);

    RETVAL = get_initializer_string(aTHX_ THIS, &mi, init, type);

  OUTPUT:
    RETVAL

