/*******************************************************************************
*
* HEADER: cterror.h
*
********************************************************************************
*
* DESCRIPTION: Error reporting for the ctlib
*
********************************************************************************
*
* $Project: /Convert-Binary-C $
* $Author: mhx $
* $Date: 2003/11/21 13:50:37 +0100 $
* $Revision: 9 $
* $Snapshot: /Convert-Binary-C/0.49 $
* $Source: /ctlib/cterror.h $
*
********************************************************************************
*
* Copyright (c) 2002-2003 Marcus Holland-Moritz. All rights reserved.
* This program is free software; you can redistribute it and/or modify
* it under the same terms as Perl itself.
*
*******************************************************************************/

#ifndef _CTLIB_CPPERR_H
#define _CTLIB_CPPERR_H

/*===== GLOBAL INCLUDES ======================================================*/

/*===== LOCAL INCLUDES =======================================================*/

#include "ctparse.h"

/*===== DEFINES ==============================================================*/

/*===== TYPEDEFS =============================================================*/

typedef struct {
  void *       (*newstr)( void );
  void         (*destroy)( void * );
  void         (*scatf)( void *, const char *, ... );
  void         (*vscatf)( void *, const char *, va_list * );
  const char * (*cstring)( void *, size_t * );
  void         (*fatal)( void * );
} PrintFunctions;

enum CTErrorSeverity {
  CTES_INFORMATION,
  CTES_WARNING,
  CTES_ERROR
};

typedef struct {
  enum CTErrorSeverity severity;
  char *string;
} CTLibError;

/*===== FUNCTION PROTOTYPES ==================================================*/

#define set_print_functions CTlib_set_print_functions
void set_print_functions( PrintFunctions *pPF );

#define pop_all_errors CTlib_pop_all_errors
void pop_all_errors( CParseInfo *pCPI );

#define push_error CTlib_push_error
void push_error( CParseInfo *pCPI, const char *fmt, ... );

#define push_warning CTlib_push_warning
void push_warning( CParseInfo *pCPI, const char *fmt, ... );

#define fatal_error CTlib_fatal_error
void fatal_error( const char *fmt, ... );

#endif
