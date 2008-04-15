################################################################################
#
# $Project: /Convert-Binary-C $
# $Author: mhx $
# $Date: 2008/04/15 15:37:46 +0200 $
# $Revision: 3 $
# $Source: /xsubs/defined.xs $
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
#   METHOD: defined
#
#   WRITTEN BY: Marcus Holland-Moritz             ON: Feb 2006
#   CHANGED BY:                                   ON:
#
################################################################################

bool
CBC::defined(name)
  const char *name

  PREINIT:
    CBC_METHOD(defined);

  CODE:
    CT_DEBUG_METHOD;

    /* TODO: probably we can do without parse data (would require special handling of the pp object) */
    CHECK_PARSE_DATA;
    CHECK_VOID_CONTEXT;

    RETVAL = macro_is_defined(&THIS->cpi, name);

  OUTPUT:
    RETVAL

