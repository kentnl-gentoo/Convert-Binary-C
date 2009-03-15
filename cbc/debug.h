/*******************************************************************************
*
* HEADER: debug.h
*
********************************************************************************
*
* DESCRIPTION: C::B::C debugging stuff
*
********************************************************************************
*
* $Project: /Convert-Binary-C $
* $Author: mhx $
* $Date: 2009/03/15 04:10:52 +0100 $
* $Revision: 6 $
* $Source: /cbc/debug.h $
*
********************************************************************************
*
* Copyright (c) 2002-2009 Marcus Holland-Moritz. All rights reserved.
* This program is free software; you can redistribute it and/or modify
* it under the same terms as Perl itself.
*
*******************************************************************************/

#ifndef _CBC_DEBUG_H
#define _CBC_DEBUG_H

#ifdef CBC_DEBUGGING

/*===== GLOBAL INCLUDES ======================================================*/


/*===== LOCAL INCLUDES =======================================================*/


/*===== DEFINES ==============================================================*/


/*===== TYPEDEFS =============================================================*/


/*===== FUNCTION PROTOTYPES ==================================================*/

#define set_debug_options CBC_set_debug_options
void set_debug_options(pTHX_ const char *dbopts);

#define set_debug_file CBC_set_debug_file
void set_debug_file(pTHX_ const char *dbfile);

#define init_debugging CBC_init_debugging
void init_debugging(pTHX);

#endif

#endif
