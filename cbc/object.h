/*******************************************************************************
*
* HEADER: object.h
*
********************************************************************************
*
* DESCRIPTION: C::B::C object
*
********************************************************************************
*
* $Project: /Convert-Binary-C $
* $Author: mhx $
* $Date: 2011/04/10 12:32:15 +0200 $
* $Revision: 6 $
* $Source: /cbc/object.h $
*
********************************************************************************
*
* Copyright (c) 2002-2011 Marcus Holland-Moritz. All rights reserved.
* This program is free software; you can redistribute it and/or modify
* it under the same terms as Perl itself.
*
*******************************************************************************/

#ifndef _CBC_OBJECT_H
#define _CBC_OBJECT_H

/*===== GLOBAL INCLUDES ======================================================*/


/*===== LOCAL INCLUDES =======================================================*/

#include "cbc/cbc.h"


/*===== DEFINES ==============================================================*/

/*===== TYPEDEFS =============================================================*/

/*===== FUNCTION PROTOTYPES ==================================================*/

#define cbc_new CBC_cbc_new
CBC *cbc_new(pTHX);

#define cbc_delete CBC_cbc_delete
void cbc_delete(pTHX_ CBC *THIS);

#define cbc_clone CBC_cbc_clone
CBC *cbc_clone(pTHX_ const CBC *THIS);

#define cbc_bless CBC_cbc_bless
SV *cbc_bless(pTHX_ CBC *THIS, const char *CLASS);

#endif
