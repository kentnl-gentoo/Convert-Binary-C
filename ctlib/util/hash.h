/*******************************************************************************
*
* HEADER: hash
*
********************************************************************************
*
* DESCRIPTION: Generic hash table routines
*
********************************************************************************
*
* $Project: Convert-Binary-C $
* $Author: mhx $
* $Date: 2002/11/25 12:54:01 +0100 $
* $Revision: 7 $
* $Snapshot: /Convert-Binary-C/0.04 $
* $Source: /ctlib/util/hash.h $
*
********************************************************************************
*
* Copyright (c) 2002 Marcus Holland-Moritz. All rights reserved.
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of either the Artistic License or the
* GNU General Public License as published by the Free Software
* Foundation; either version 2 of the License, or (at your option)
* any later version.
*
* THIS PROGRAM IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
* WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*******************************************************************************/

/**
 *  \file hash.h
 *  \brief Generic implementation of Hash Tables
 */
#ifndef _HASH_H
#define _HASH_H


/**
 *  Maximum allowed hash size
 *
 *  This controls the maximum number of hash buckets,
 *  currently 2^16 = 65536.
 */
#define MAX_HASH_TABLE_SIZE 16

/**
 *  Compute hash sum and string length
 *
 *  The HASH_STR_LEN() macro computes the hash sum and
 *  string length of a zero terminated string.
 *
 *  \param hash		Variable that will receive the
 *                      hash sum.
 *
 *  \param str		Pointer to the zero terminated
 *                      string.
 *
 *  \param len		Variable that will receive the
 *                      string length.
 *
 *  \see HASH_STRING() and HASH_DATA()
 *  \hideinitializer
 */
#define HASH_STR_LEN( hash, str, len )         \
        do {                                   \
	  register int         _len = 0;       \
	  register const char *_str = str;     \
	  register HashSum     _hash = 0;      \
                                               \
	  while( *_str ) {                     \
            _len++;                            \
	    _hash += *_str++;                  \
	    _hash += (_hash << 10);            \
	    _hash ^= (_hash >> 6);             \
	  }                                    \
                                               \
	  _hash += (_hash << 3);               \
	  _hash ^= (_hash >> 11);              \
	  (hash) = (_hash + (_hash << 15));    \
	  (len)  = _len;                       \
        } while(0)

/**
 *  Compute hash sum
 *
 *  The HASH_STRING() macro computes the hash sum
 *  of a zero terminated string.
 *
 *  \param hash		Variable that will receive the
 *                      hash sum.
 *
 *  \param str		Pointer to the zero terminated
 *                      string.
 *
 *  \see HASH_STR_LEN() and HASH_DATA()
 *  \hideinitializer
 */
#define HASH_STRING( hash, str )               \
        do {                                   \
	  register const char *_str = str;     \
	  register HashSum     _hash = 0;      \
                                               \
	  while( *_str ) {                     \
	    _hash += *_str++;                  \
	    _hash += (_hash << 10);            \
	    _hash ^= (_hash >> 6);             \
	  }                                    \
                                               \
	  _hash += (_hash << 3);               \
	  _hash ^= (_hash >> 11);              \
	  (hash) = (_hash + (_hash << 15));    \
        } while(0)

/**
 *  Compute hash sum of arbitrary data
 *
 *  The HASH_DATA() macro computes the hash sum
 *  of a an arbitrary data memory block.
 *
 *  \param hash		Variable that will receive the
 *                      hash sum.
 *
 *  \param len		Length of the data block.
 *
 *  \param data		Pointer to the data block.
 *
 *  \see HASH_STR_LEN() and HASH_STRING()
 *  \hideinitializer
 */
#define HASH_DATA( hash, len, data )           \
        do {                                   \
	  register const char *_data = data;   \
	  register int         _len  = len;    \
	  register HashSum     _hash = 0;      \
                                               \
	  while( _len-- ) {                    \
	    _hash += *_data++;                 \
	    _hash += (_hash << 10);            \
	    _hash ^= (_hash >> 6);             \
	  }                                    \
                                               \
	  _hash += (_hash << 3);               \
	  _hash ^= (_hash >> 11);              \
	  (hash) = (_hash + (_hash << 15));    \
        } while(0)

/**
 *  Hash Table Handle
 */
typedef struct _HashTable * HashTable;

/**
 *  Hash Sum
 */
typedef unsigned long HashSum;

/**
 *  Hash Node
 */
typedef struct _HashNode *HashNode;

struct _HashNode {
  HashNode    next;
  void       *pObj;
  HashSum     hash;
  int         keylen;
  char        key[1];
};

/**
 *  Destructor Function Pointer
 */
typedef void (* HTDestroyFunc)(void *);

/**
 *  Cloning Function Pointer
 */
typedef void * (* HTCloneFunc)(const void *);

HashTable  HT_new( int size );
HashTable  HT_new_ex( int size, unsigned long flags );
void       HT_delete( HashTable table );
void       HT_flush( HashTable table, HTDestroyFunc destroy );
void       HT_destroy( HashTable table, HTDestroyFunc destroy );
HashTable  HT_clone( HashTable table, HTCloneFunc func );

int        HT_resize( HashTable table, int size );
int        HT_size( const HashTable table );
int        HT_count( const HashTable table );

HashNode   HN_new( const char *key, int keylen, HashSum hash );
void       HN_delete( HashNode node );

int        HT_storenode( const HashTable table, HashNode node, void *pObj );
void *     HT_fetchnode( const HashTable table, HashNode node );
void *     HT_rmnode( const HashTable table, HashNode node );

int        HT_store( const HashTable table, const char *key, int keylen, HashSum hash, void *pObj );
void *     HT_fetch( const HashTable table, const char *key, int keylen, HashSum hash );
void *     HT_get( const HashTable table, const char *key, int keylen, HashSum hash );
int        HT_exists( const HashTable table, const char *key, int keylen, HashSum hash );

void       HT_reset( const HashTable table );
int        HT_next( const HashTable table, char **pKey, int *pKeylen, void **ppObj );

/* hash table flags */
#define HT_AUTOGROW            0x00000001
#define HT_AUTOSHRINK          0x00000002
#define HT_AUTOSIZE            (HT_AUTOGROW|HT_AUTOSHRINK)

/* debug flags */
#define DB_HASH_MAIN           0x00000001

#ifdef DEBUG_HASH
void HT_dump( const HashTable table );
int  SetDebugHash( void (*dbfunc)(char *, ...), unsigned long dbflags );
#else
#define SetDebugHash( func, flags ) 0
#endif

/**
 *  Loop over all hash elements.
 *
 *  The HT_foreach() macro is actually only a shortcut for the
 *  following loop:
 *
 *  \code
 *  for( HT_reset(table); HT_next(table, (char **)&(pKey), NULL, (void **)&(pObj)); ) {
 *    // do something with pKey and pObj
 *  }
 *  \endcode
 *
 *  It is safe to use HT_foreach() even if \a hash table handle is NULL.
 *  In that case, the loop won't be executed.
 *
 *  \param pKey		Variable that will receive a pointer
 *                      to the current hash key string.
 *
 *  \param pObj		Variable that will receive a pointer
 *                      to the current object.
 *
 *  \param table	Handle to an existing hash table.
 *
 *  \see HT_reset() and HT_next()
 *  \hideinitializer
 */
#define HT_foreach( pKey, pObj, table ) \
          for( HT_reset(table); HT_next(table, (char **)&(pKey), NULL, (void **)&(pObj)); )

/**
 *  Loop over all hash keys.
 *
 *  Like HT_foreach(), just that the value parameter isn't used.
 *
 *  It is safe to use HT_foreach_keys() even if \a hash table handle is NULL.
 *  In that case, the loop won't be executed.
 *
 *  \param pKey		Variable that will receive a pointer
 *                      to the current hash key string.
 *
 *  \param table	Handle to an existing hash table.
 *
 *  \see HT_foreach() and HT_foreach_values()
 *  \hideinitializer
 */
#define HT_foreach_keys( pKey, table ) \
          for( HT_reset(table); HT_next(table, (char **)&(pKey), NULL, NULL); )

/**
 *  Loop over all hash values.
 *
 *  Like HT_foreach(), just that the key parameter isn't used.
 *
 *  It is safe to use HT_foreach_values() even if \a hash table handle is NULL.
 *  In that case, the loop won't be executed.
 *
 *  \param pObj		Variable that will receive a pointer
 *                      to the current object.
 *
 *  \param table	Handle to an existing hash table.
 *
 *  \see HT_foreach() and HT_foreach_keys()
 *  \hideinitializer
 */
#define HT_foreach_values( pObj, table ) \
          for( HT_reset(table); HT_next(table, NULL, NULL, (void **)&(pObj)); )

#endif
