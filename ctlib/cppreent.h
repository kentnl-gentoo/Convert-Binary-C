/*******************************************************************************
*
* HEADER: cppreent.h
*
********************************************************************************
*
* DESCRIPTION: Some macros to help with ucpp reentrancy
*
********************************************************************************
*
* $Project: /Convert-Binary-C $
* $Author: mhx $
* $Date: 2006/02/24 22:05:09 +0100 $
* $Revision: 8 $
* $Source: /ctlib/cppreent.h $
*
********************************************************************************
*
* Copyright (c) 2002-2006 Marcus Holland-Moritz. All rights reserved.
* This program is free software; you can redistribute it and/or modify
* it under the same terms as Perl itself.
*
*******************************************************************************/

#ifndef _CTLIB_CPPREENT_H
#define _CTLIB_CPPREENT_H

/*===== GLOBAL INCLUDES ======================================================*/

/*===== LOCAL INCLUDES =======================================================*/

#include "util/ccattr.h"

/*===== DEFINES ==============================================================*/

#ifdef pUCPP
# undef pUCPP
#endif

#ifdef pUCPP_
# undef pUCPP_
#endif

#ifdef aUCPP
# undef aUCPP
#endif

#ifdef aUCPP_
# undef aUCPP_
#endif

#ifdef dUCPP
# undef dUCPP
#endif

# define pUCPP     struct CPP *pp __attribute__((unused))
# define pUCPP_    pUCPP,
# define aUCPP     pp
# define aUCPP_    aUCPP,
# define dUCPP(a)  pUCPP = (struct CPP *)a

/* ucpp global variables */
# define r_no_special_macros   ((struct CPP *) pp)->no_special_macros
# define r_emit_defines        ((struct CPP *) pp)->emit_defines
# define r_emit_assertions     ((struct CPP *) pp)->emit_assertions
# define r_emit_dependencies   ((struct CPP *) pp)->emit_dependencies
# define r_current_filename    ((struct CPP *) pp)->current_filename
# define r_callback_arg        ((struct CPP *) pp)->callback_arg

/*===== TYPEDEFS =============================================================*/

struct CPP;

/*===== FUNCTION PROTOTYPES ==================================================*/

#endif
