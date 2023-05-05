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

#include "libll.h"


//--------------------------------------------------------------------
// Non-User function to create nodes
//--------------------------------------------------------------------


ll *_ll_create()
{
  ll *new_node ;
  new_node = malloc(sizeof(ll)) ;
  if (new_node == NULL){
    printf("error , couldnt assign memory\n") ;
    exit(1024);
  }
  return new_node;

}


//--------------------------------------------------------------------
// User function to add nodes to the end of the linked list
//--------------------------------------------------------------------


ll *lladd(ll *head_node,void *new_data)
{
  ll *new_node = _ll_create() ;
  (new_node -> _data) = new_data ;
  if (head_node == NULL)
    {
      return new_node ;
    }
  ll *temp_node = head_node;
  for (;temp_node->_next!= NULL;temp_node = temp_node -> _next)
    {}
  temp_node -> _next = new_node ;
  return head_node;
}


//--------------------------------------------------------------------
// User function to print all the nodes occuring after the starting
// node
//--------------------------------------------------------------------


void llprint(ll *start_node, char *(*comp)(void *))
{
  for (ll * temp_node = start_node ;temp_node != NULL;
       temp_node = temp_node -> _next)
    {
      char *c = comp(temp_node -> _data);
      printf("%s\n",c);
    }
}


//--------------------------------------------------------------------
// User function to search for the payload data in the linked list
//--------------------------------------------------------------------


ll *llsearch(ll *head_node, void *missing, int (*comp)(void *,void *))
{
  for (ll * temp_node = head_node ; temp_node != NULL ;
       temp_node = temp_node -> _next)
    {
      if (comp((temp_node -> _data),missing) == 0)
	{
	  return temp_node;
	}
    }
  return NULL ;
}


//--------------------------------------------------------------------
// User function to delete first node with matching data as given by the
// user
//--------------------------------------------------------------------


ll *lldelete(ll *head_node, void *delete_data,
	     int (*comp)(void *,void *) , void (*del_data)(void *))
{
  if (head_node == NULL)
    {
      return NULL;
    }
  /* if ((head_node -> _next == NULL) && 
     (comp((head_node -> _data),delete_data)==0)) */
  /*   { */
  /*     del_data((head_node->_data)); */
  /*     free(head_node); */
  /*     return NULL; */
  /*   } */
  /* ll * temp_node_1 = NULL      ; */
  /* ll * temp_node_2 = head_node ; */
  /* for (; temp_node_2 != NULL ; temp_node1 = temp_node_2 ,
     temp_node_2 = temp_node_2 -> _next) */
  /*   { */
  /*     if (comp((temp_node_2 -> _data),delete_data) == 0) */
  /* 	{ */
  /* 	  temp; */
  /* 	} */
  /*   } */

  if ((comp((head_node -> _data),delete_data)==0)) 
    {
      ll *return_next = head_node -> _next ;
      del_data((head_node->_data));
      free(head_node);
      return return_next;
    }
  ll * temp_node_1 = NULL      ;
  ll * temp_node_2 = head_node ;
  for (; temp_node_2 != NULL ; temp_node_1 = temp_node_2 ,
	 temp_node_2 = temp_node_2 -> _next)
    {
      if (comp((temp_node_2 -> _data),delete_data) == 0)
	{
	  temp_node_1 -> _next = temp_node_2 -> _next   ;
	  del_data((temp_node_2->_data));
	  free(temp_node_2);
	  return head_node;
	}
    }
  
  return NULL ;
}


//--------------------------------------------------------------------
// User function to append linked list 2 to the end of linked list 1
//--------------------------------------------------------------------


ll *llappend(ll *head_node_1, ll *head_node_2)
{
  if (head_node_1 == NULL)
    {
      return NULL ;
    }
  ll *temp_node = head_node_1;
  for (; temp_node->_next != NULL ; temp_node = temp_node -> _next)
    {
      ;
    }
  
  temp_node -> _next = head_node_2;
  return head_node_1;
}


//--------------------------------------------------------------------
//
//--------------------------------------------------------------------


void swap (void *a, void *b)
{
  void * temp ;
  temp = a;
  a = b;
  b = temp ;
}

ll *llsort(ll *head_node, int (*comp)(void *, void *))
{
  if (head_node == NULL)
    {
      return NULL ; 
    }
  ll *temp_node = head_node;
  int length = 0;
  for (; temp_node->_next != NULL ; temp_node = temp_node -> _next)
    {
      length++;
    }
  ll *temp_node_1 = head_node ;
  ll *temp_node_2 ;
  for (int i = 1; i < length ; i++)
    {
      temp_node_1 = head_node;
      temp_node_2 = head_node -> _next;
      for (int j = 1; j <= length - i ; j++,temp_node_1=temp_node_1->_next,
	     temp_node_2=temp_node_2->_next)
	{
	  if (comp((temp_node_1 -> _data),((temp_node_2 -> _data))))
	    {
	      swap((temp_node_1 -> _data),(temp_node_2 -> _data));		   
	    }		
	}
    }
  return head_node;
}
