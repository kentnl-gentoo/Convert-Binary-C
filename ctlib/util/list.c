/*******************************************************************************
*
* MODULE: list
*
********************************************************************************
*
* DESCRIPTION: Generic routines for a doubly linked ring list
*
********************************************************************************
*
* $Project: /Convert-Binary-C $
* $Author: mhx $
* $Date: 2003/09/28 22:08:54 +0200 $
* $Revision: 9 $
* $Snapshot: /Convert-Binary-C/0.49 $
* $Source: /ctlib/util/list.c $
*
********************************************************************************
*
* Copyright (c) 2002-2003 Marcus Holland-Moritz. All rights reserved.
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

#include <stdio.h>
#include <stdlib.h>

#include "ccattr.h"
#include "memalloc.h"
#include "list.h"

/*----------*/
/* Typedefs */
/*----------*/
typedef struct _link Link;

struct _link {
  void *pObj;
  Link *prev;
  Link *next;
};

struct _linkedList {
  Link  link;
  Link *cur;
  int   size;
};

/*------------------*/
/* Static Functions */
/*------------------*/
static inline Link *GetLink( const LinkedList list, int item );
static inline void *Extract( const LinkedList list, Link *pLink );
static inline Link *Insert( const LinkedList list, Link *pLink, void *pObj );
static void QuickSort( Link *l, Link *r, int size, LLCompareFunc cmp );


/************************************************************
*
*  S T A T I C   F U N C T I O N S
*
************************************************************/

/*
 *  GetLink
 *
 *  Get a link by item number.
 *
 *  0 <= item < list->size
 *    returns a pointer to the (item)th link
 *
 *  -(list->size) <= item < 0
 *    returns a pointer to the (list->size+item)th link
 *
 *  otherwise
 *    return NULL
 */

static inline Link *GetLink( const LinkedList list, int item )
{
  Link *pLink = &list->link;

  if( item < 0 ) {
    if( -item > list->size )  /* -1 is last item */
      return NULL;

    while( item++ < 0 )
      pLink = pLink->prev;
  }
  else { /* item > 0 */
    if( item >= list->size )  /* 0 is first item */
      return NULL;

    while( item-- >= 0 )
      pLink = pLink->next;
  }

  return pLink;
}

/*
 *  Extract
 *
 *  Extracts a link from its list, frees its
 *  resources and returns a pointer to the
 *  associated object.
 */

static inline void *Extract( const LinkedList list, Link *pLink )
{
  void *pObj = pLink->pObj;

  pLink->prev->next = pLink->next;
  pLink->next->prev = pLink->prev;

  list->size--;
  list->cur = &list->link;

  Free( pLink );

  return pObj;
}

/*
 *  Insert
 *
 *  Inserts a new link associated with pObj _before_
 *  the link pointed to by pLink and returns a pointer
 *  to the inserted link.
 */

static inline Link *Insert( const LinkedList list, Link *pLink, void *pObj )
{
  Link *pLinkNew;

  AllocF( Link *, pLinkNew, sizeof( Link ) );

  pLinkNew->pObj = pObj;

  pLinkNew->prev = pLink->prev;
  pLinkNew->next = pLink;

  pLink->prev->next = pLinkNew;
  pLink->prev       = pLinkNew;

  list->size++;

  list->cur = &list->link;

  return pLinkNew;
}

/*
 *  QuickSort
 *
 *  Adapted quick sort algorithm.
 */

static void QuickSort( Link *l, Link *r, int size, LLCompareFunc cmp )
{
  Link *i, *j;
  void *p, *t;
  int lp, rp;

  /* determine pivot */
  lp = size / 2;
  for( i=l; --lp > 0; i=i->next );
  p = i->pObj;

  /* initialize vars */
  i = l; j = r;
  lp = 0; rp = size-1;

  /* sort */
  for(;;) {
    while( cmp( i->pObj, p ) < 0 )
      i = i->next, lp++;
    if( lp > rp ) break;

    while( cmp( j->pObj, p ) > 0 )
      j = j->prev, rp--;
    if( lp > rp ) break;

    /* swap elements */
    t = i->pObj;
    i->pObj = j->pObj;
    j->pObj = t;

    i = i->next; lp++;
    j = j->prev; rp--;
  }

  if( rp+1 > 1 )
    QuickSort( l, j, rp+1, cmp );

  if( size-lp > 1 )
    QuickSort( i, r, size-lp, cmp );
}

/************************************************************
*
*  G L O B A L   F U N C T I O N S
*
************************************************************/

/**
 *  Constructor
 *
 *  Using the LL_new() function you create an empty linked
 *  list. If the term linked list scares you, just think of
 *  it as a flexible array, because the Linked List Library
 *  won't let you deal with links at all.
 *
 *  \return A handle to the newly created linked list.
 *
 *  \see LL_delete() and LL_destroy()
 */

LinkedList LL_new( void )
{
  LinkedList list;

  AllocF( LinkedList, list, sizeof( struct _linkedList ) );

  list->link.prev = list->link.next = list->cur = &list->link;
  list->link.pObj = NULL;
  list->size      = 0;

  return list;
}

/**
 *  Destructor
 *
 *  LL_delete() will free the resources occupied by a
 *  linked list. The function will fail silently if the
 *  associated list is not empty.
 *  You can also delete a list that is not empty by
 *  using the LL_destroy() function.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \see LL_new() and LL_destroy()
 */

void LL_delete( LinkedList list )
{
  if( list == NULL || list->size )
    return;

  Free( list );
}

/**
 *  Remove all elements from a list
 *
 *  LL_flush() will remove all elements from a linked list,
 *  optionally calling a destructor function. It will not
 *  free the resources occupied by the list itself.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \param destroy      Pointer to the destructor function
 *                      of the objects contained in the list.
 *                      You can pass NULL if you don't want
 *                      LL_flush() to call object destructors.
 *
 *  \see LL_destroy()
 */

void LL_flush( LinkedList list, LLDestroyFunc destroy )
{
  void *pObj;

  if( list == NULL )
    return;

  while( (pObj = LL_shift( list )) != NULL )
    if( destroy ) destroy( pObj );
}

/**
 *  Extended Destructor
 *
 *  LL_destroy() will, like LL_delete(), free the resources
 *  occupied by a linked list. However, it will empty the
 *  the list prior to deleting it, like LL_flush().
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \param destroy      Pointer to the destructor function
 *                      of the objects contained in the list.
 *                      You can pass NULL if you don't want
 *                      LL_destroy() to call object destructors.
 *
 *  \see LL_new(), LL_delete() and LL_flush()
 */

void LL_destroy( LinkedList list, LLDestroyFunc destroy )
{
  if( list == NULL )
    return;

  LL_flush( list, destroy );
  LL_delete( list );
}

/**
 *  Cloning a linked list
 *
 *  Using the LL_clone() function to create an exact copy
 *  of a linked list. If the objects stored in the list
 *  need to be cloned as well, you can pass a pointer to
 *  a function that clones each element.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \param func         Pointer to the cloning function of
 *                      the objects contained in the list.
 *                      If you pass NULL, the original
 *                      object is stored in the cloned list
 *                      instead of a cloned object.
 *
 *  \return A handle to the cloned linked list.
 *
 *  \see LL_new()
 */

LinkedList LL_clone( LinkedList list, LLCloneFunc func )
{
  LinkedList clone;
  void *pObj;

  if( list == NULL )
    return NULL;

  clone = LL_new();

  LL_foreach( pObj, list )
    LL_push( clone, func ? func( pObj ) : pObj );

  return clone;
}

/**
 *  Current size of a list
 *
 *  LL_count() will return the the number of objects that
 *  a linked list contains.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \return The size of the list or -1 if an invalid handle
 *          was passed.
 */

int LL_count( const LinkedList list )
{
  if( list == NULL )
    return -1;

  AssertValidPtr( list );

  return list->size;
}

/**
 *  Add element to the end of a list.
 *
 *  LL_push() will add a new element to the end of a list.
 *  If you think of the list as a stack, the function pushes
 *  a new element on top of the stack.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \param pObj         Pointer to an object associated with
 *                      the new list element. The function
 *                      will not add a new element if this
 *                      is NULL.
 *
 *  \see LL_pop()
 */

void LL_push( const LinkedList list, void *pObj )
{
  if( list == NULL || pObj == NULL )
    return;

  AssertValidPtr( list );

  (void) Insert( list, &list->link, pObj );
}

/**
 *  Remove element from the end of a list.
 *
 *  LL_pop() will remove the last element from a list.
 *  If you think of the list as a stack, the function pops
 *  an element of the stack.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \return Pointer to the object that was associated with
 *          the element removed from the list. If the list
 *          is empty, NULL will be returned.
 *
 *  \see LL_push()
 */

void *LL_pop( const LinkedList list )
{
  if( list == NULL || list->size == 0 )
    return NULL;

  AssertValidPtr( list );

  return Extract( list, list->link.prev );
}

/**
 *  Add element to the start of a list.
 *
 *  LL_unshift() will add a new element to the beginning of a
 *  list, right before the first element. For an empty list
 *  this is equivalent to calling LL_push().
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \param pObj         Pointer to an object associated with
 *                      the new list element. The function
 *                      will not add a new element if this
 *                      is NULL.
 *
 *  \see LL_shift()
 */

void LL_unshift( const LinkedList list, void *pObj )
{
  if( list == NULL || pObj == NULL )
    return;

  AssertValidPtr( list );

  (void) Insert( list, list->link.next, pObj );
}

/**
 *  Remove element from the start of a list.
 *
 *  LL_shift() will remove the first element from a list.
 *  If the list contains only a single element, this is
 *  equivalent to calling LL_pop().
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \return Pointer to the object that was associated with
 *          the element removed from the list. If the list
 *          is empty, NULL will be returned.
 *
 *  \see LL_unshift()
 */

void *LL_shift( const LinkedList list )
{
  if( list == NULL || list->size == 0 )
    return NULL;

  AssertValidPtr( list );

  return Extract( list, list->link.next );
}

/**
 *  Insert a new element into a list.
 *
 *  Using LL_insert(), you can insert a new element at an
 *  arbitrary position in the list.
 *  If \a item is out of the valid range, the element will
 *  not be added.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \param item         Position where the new element should
 *                      be inserted.\n
 *                      A value of 0 will insert
 *                      the new element at the start of the
 *                      list, like LL_unshift() would do. A
 *                      value of LL_count() would insert the
 *                      element at the end of the list, like
 *                      LL_push() would do. A negative value
 *                      will count backwards from the end of
 *                      the list. So a value of -1 would also
 *                      add the new element to the end of the
 *                      list.
 *
 *  \param pObj         Pointer to an object associated with
 *                      the new list element. The function
 *                      will not add a new element if this
 *                      is NULL.
 *
 *  \see LL_extract()
 */

void LL_insert( const LinkedList list, int item, void *pObj )
{
  Link *pLink;

  if( list == NULL || pObj == NULL )
    return;

  AssertValidPtr( list );

  /*
   * We have to do some faking here because adding to the end
   * of the list is a more natural result for item == -1 than
   * adding to the position _before_ the last element would be
   */
  if( item < 0 )
    pLink = item == -1 ? &list->link : GetLink( list, item+1 );
  else
    pLink = item == list->size ? &list->link : GetLink( list, item );

  if( pLink == NULL )
    return;

  (void) Insert( list, pLink, pObj );
}

/**
 *  Extract an element from a list.
 *
 *  LL_extract() will remove an arbitrary element from the
 *  list and return a pointer to the associated object.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \param item         Position of the element that should
 *                      be extracted.\n
 *                      A value of 0 will extract the first
 *                      element, like LL_shift(). A negative
 *                      value will count backwards from the
 *                      end of the list. So a value of -1
 *                      will extract the last element, which
 *                      will be equivalent to LL_pop().
 *
 *  \return Pointer to the object that was associated with
 *          the element removed from the list. If the list
 *          is empty or \a item is out of range, NULL will
 *          be returned.
 *
 *  \see LL_insert()
 */

void *LL_extract( const LinkedList list, int item )
{
  Link *pLink;

  if( list == NULL || list->size == 0 )
    return NULL;

  AssertValidPtr( list );

  pLink = GetLink( list, item );

  if( pLink == NULL )
    return NULL;

  return Extract( list, pLink );
}

/**
 *  Get the element of a list.
 *
 *  LL_get() will simply return a pointer to the object
 *  associated with a certain list element.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \param item         Position of the element. Negative
 *                      positions count backwards from the
 *                      end of the list, so -1 would refer
 *                      to the last element.
 *
 *  \return Pointer to the object that is associated with
 *          the element. If the list is empty or \a item
 *          is out of range, NULL will be returned.
 */

void *LL_get( const LinkedList list, int item )
{
  Link *pLink;

  if( list == NULL || list->size == 0 )
    return NULL;

  AssertValidPtr( list );

  pLink = GetLink( list, item );

  return pLink ? pLink->pObj : NULL;
}

/**
 *  Perform different list transformations.
 *
 *  LL_splice() can be used for a variety of list transformations
 *  and is similar to Perl's splice builtin. In brief,
 *  LL_splice() will extract \a length elements starting at
 *  \a offset from \a list, replace them by the elements in
 *  \a rlist and return a new list holding the extracted elements.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \param offset       Offset of the first element to extract.
 *                      If negative, counts backwards from the
 *                      end.
 *
 *  \param length       Length of the list to extract. If negative,
 *                      all remaining elements will be extracted.
 *                      If \a length is larger than the number of
 *                      remaining elements, only the remaining
 *                      elements will be extracted. If this is 0,
 *                      no elements will be extracted. However,
 *                      an empty list will still be returned.
 *
 *  \param rlist        List that will replace the extracted
 *                      elements. If no elements were extracted,
 *                      the elements of \a rlist will just be
 *                      inserted at \a offset. If \a rlist is
 *                      NULL, no replacement elements will be
 *                      inserted. The list will be automatically
 *                      destroyed after the elements have been
 *                      inserted into \a list.
 *
 *  \return Handle to a new list holding the extracted elements,
 *          if any. NULL if LL_splice() fails for some reason.
 */

LinkedList LL_splice( const LinkedList list, int offset, int length, LinkedList rlist )
{
  LinkedList nlist;
  Link *pLink, *pLast;

  if( list == NULL )
    return NULL;

  AssertValidPtr( list );

  pLink = offset == list->size ? &list->link : GetLink( list, offset );

  if( pLink == NULL )
    return NULL;

  nlist = LL_new();

  if( nlist == NULL )
    return NULL;

  if( length < 0 )
    length = offset < 0 ? -offset : list->size - offset;

  if( length > 0 ) {
    pLast = pLink;

    while( ++nlist->size < length && pLast->next->pObj )
      pLast = pLast->next;

    pLink->prev->next = pLast->next;
    pLast->next->prev = pLink->prev;

    nlist->link.next = pLink;
    nlist->link.prev = pLast;

    pLink->prev = &nlist->link;
    pLink       = pLast->next;
    pLast->next = &nlist->link;

    list->size -= nlist->size;
  }

  if( rlist ) {
    pLast = pLink;
    pLink = pLink->prev;

    rlist->link.next->prev = pLink;
    rlist->link.prev->next = pLast;

    pLink->next = rlist->link.next;
    pLast->prev = rlist->link.prev;

    list->size += rlist->size;

    Free( rlist );
  }

  list->cur = &list->link;

  return nlist;
}

/**
 *  Reset list iterator.
 *
 *  LL_reset() will reset the lists internal iterator.
 *  When using the lists iterator functionality, keep in
 *  mind that the iterator is reset whenever the list is
 *  modified.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \see LL_next() and LL_prev()
 */

void LL_reset( const LinkedList list )
{
  if( list == NULL )
    return;

  AssertValidPtr( list );

  list->cur = &list->link;
}

/**
 *  Get next list element.
 *
 *  LL_next() will advance to the next element and return a
 *  pointer to the object associated with that element.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \return Pointer to the object associated with the next
 *          list element.
 *
 *  \see LL_reset() and LL_prev()
 */

void *LL_next( const LinkedList list )
{
  if( list == NULL )
    return NULL;

  AssertValidPtr( list );

  list->cur = list->cur->next;

  return list->cur->pObj;
}

/**
 *  Get previous list element.
 *
 *  LL_prev() will go back to the previous element and return a
 *  pointer to the object associated with that element.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \return Pointer to the object associated with the previous
 *          list element.
 *
 *  \see LL_reset() and LL_next()
 */

void *LL_prev( const LinkedList list )
{
  if( list == NULL )
    return NULL;

  AssertValidPtr( list );

  list->cur = list->cur->prev;

  return list->cur->pObj;
}

/**
 *  Sort list elements.
 *
 *  LL_sort() will sort a list using a quicksort algorithm.
 *  The sorted list will be in ascending order.
 *
 *  \param list         Handle to an existing linked list.
 *
 *  \param cmp          Pointer to a comparison function.
 *                      This function is called with a pair
 *                      of pointers to objects in the list
 *                      and must return
 *                      - a negative value if the first
 *                        argument is less than the second
 *                      - a positive value if the first
 *                        argument is greater than the second
 *                      - zero if the first both arguments
 *                        are considered to be equal
 */

void LL_sort( const LinkedList list, LLCompareFunc cmp )
{
  if( list == NULL || list->size <= 1 )
    return;

  AssertValidPtr( list );

  QuickSort( list->link.next, list->link.prev, list->size, cmp );
}
