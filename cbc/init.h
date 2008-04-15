/*******************************************************************************
*
* HEADER: init.h
*
********************************************************************************
*
* DESCRIPTION: C::B::C initializer
*
********************************************************************************
*
* $Project: /Convert-Binary-C $
* $Author: mhx $
* $Date: 2008/04/15 15:37:35 +0200 $
* $Revision: 5 $
* $Source: /cbc/init.h $
*
********************************************************************************
*
* Copyright (c) 2002-2008 Marcus Holland-Moritz. All rights reserved.
* This program is free software; you can redistribute it and/or modify
* it under the same terms as Perl itself.
*
*******************************************************************************/

#ifndef _CBC_INIT_H
#define _CBC_INIT_H

/*===== GLOBAL INCLUDES ======================================================*/


/*===== LOCAL INCLUDES =======================================================*/

#include "cbc/cbc.h"
#include "cbc/member.h"


/*===== DEFINES ==============================================================*/


/*===== TYPEDEFS =============================================================*/


/*===== FUNCTION PROTOTYPES ==================================================*/

#define get_initializer_string CBC_get_initializer_string
SV *get_initializer_string(pTHX_ CBC *THIS, MemberInfo *pMI, SV *init, const char *name);

#endif
