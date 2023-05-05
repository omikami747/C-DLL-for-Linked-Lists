/*------------------------------------------------------------------------------
  (C) Aditya V. Nebhrajani 2020
  File: libll.h
  Description: Header for generic linked list library.

---------------------------------RCS/CVS----------------------------------------
  $Id: libll.h,v 1.2 2020/05/27 04:17:40 aditya Exp $
  $Author: aditya $
  $Source: /auto/common/.cvsroot/libll/src/libll.h,v $
  $Revision: 1.2 $
  $Date: 2020/05/27 04:17:40 $
  $Log: libll.h,v $
  Revision 1.2  2020/05/27 04:17:40  aditya
  Added function prototypes for llsort, llappend.

  Revision 1.1  2020/05/25 09:34:43  aditya
  Initial version.

------------------------------------------------------------------------------*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
  Linked list data structure.
------------------------------------------------------------------------------*/
typedef struct llnode {
  void *_data;
  struct llnode *_next;
} ll;

/*------------------------------------------------------------------------------
  Function prototypes.
------------------------------------------------------------------------------*/
extern ll *_llcreate(void);

extern ll *lladd(ll *, void *);

extern void llprint(ll *, char *(*)(void *));

extern ll *llsearch(ll *, void * , int (*)(void *,void *)) ;

extern ll *lldelete(ll *, void * , int (*)(void *,void *) , void (*)(void *)) ;

extern ll *llappend(ll *, ll *);

extern ll *llsort(ll *, int (*)(void *, void *));

