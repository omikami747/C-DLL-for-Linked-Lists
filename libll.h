/*----------------------------------------------------------------------------*/

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

extern ll *llsearch(ll *, void *) ;

extern ll *lldelete(ll *, void *);

extern ll *llappend(ll *, ll *);

extern ll *llsort(ll *, int (*)(void *, void *));

