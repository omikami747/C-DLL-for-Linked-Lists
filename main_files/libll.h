//--------------------------------------------------------------------
//
// File         : Dll for Linked List
// Author       : Omkar Girish Kamath
// Date         : May 5, 2023
// Description  : Various Basic functions used in Linked list creation
//                ,deletion , print , adding nodes , append
// Error Codes  : (1) 1024 : Memory assignment failed due to
//                insufficient memory available
//--------------------------------------------------------------------


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*--------------------------------------------------------------------
  Linked list data structure
--------------------------------------------------------------------*/
typedef struct llnode {
  void *_data;
  struct llnode *_next;
} ll;

/*--------------------------------------------------------------------
  Function prototypes.
--------------------------------------------------------------------*/

extern ll *_llcreate(void);

extern ll *lladd(ll *, void *);

extern void llprint(ll *, char *(*)(void *));

extern ll *llsearch(ll *, void * , int (*)(void *,void *)) ;

extern ll *lldelete(ll *, void * , int (*)(void *,void *) , void (*)(void *)) ;

extern ll *llappend(ll *, ll *);

extern ll *llsort(ll *, int (*)(void *, void *));
