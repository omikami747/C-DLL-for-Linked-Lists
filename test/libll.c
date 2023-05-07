//--------------------------------------------------------------------
//
// File         : Dll for Linked List
// Author       : Omkar Girish Kamath
// Date         : May 5, 2023
// Description  : Various Basic functions used in Linked list creation,
//                deletion, print, adding nodes, appending.
// 
//--------------------------------------------------------------------

#include "libll.h"

//--------------------------------------------------------------------
// Function Name: _ll_create()
// Arguments:     None.
// Returns:       Head pointer to new list (ll *) (!!ASK uncle (why not New pointer))
// Description:   Non-User function to create new lists or nodes.
//--------------------------------------------------------------------
ll *_ll_create()
{
  ll *new = NULL;

  // Allocate memory
  new = malloc(sizeof(ll)) ;

  // If memory allocation failed, fatal error, exit.
  if (new == NULL) {
    fprintf(stderr, "Error, could not allocate memory. Fatal.");
    exit(EXIT_MALLOC_FAILED);
  }

  // Initialize structure
  new->_data = NULL:
  new->_next = NULL;

  // return the new node pointer created
  return new;
}

//--------------------------------------------------------------------
// Function Name: lladd()
// Arguments:     Takes in a pointer to a list (or NULL if a new list
//                needs to be created) and a pointer to the data
//                payload that will be added to the newly created
//                node.
// Returns:       Head pointer to either a new list, or the same list
//                if the head argument is non-null (ll *).
// Description:   User function to create a new list or add nodes to
//                the end of given linked list.
//--------------------------------------------------------------------
ll *lladd(ll *head, void *data)
{
  ll *new = NULL ;
  ll *temp = NULL;
  
  // Create a new node and load it's data
  new = _ll_create();
  new->_data = data;
  
  // If this was a null list, simply return the newly created node
  if (head == NULL) {
    return new;
  }
  else {
    // Traverse to the end of list
    for (temp = head; temp->_next != NULL; temp = temp->_next) {
    }
    // Attach new node here and return the head pointer
    temp->_next = new;
    return head;
  }
}

//--------------------------------------------------------------------
// Function Name: llprint()
// Arguments    : A starting node from to start printing from and a
//                a function pointer which takes in payload data of a
//                node and returns the string that is to be printed.
// Returns      : None
// Description  : User function to print all the nodes occuring after
//                the starting node
//--------------------------------------------------------------------
void llprint(ll *start, char *(*comp)(void *))
{
  ll * temp = NULL; 

  // if start node or functin pointer provided is NULL
  if ((start == NULL) || (comp == NULL)) {
    return ;
  }
  
  // traverse to the end of the list, printing each elements payload
  // string
  temp = start;
  for (;temp != NULL; temp = temp->_next)
    {
      char *c = comp(temp->_data);
      printf("%s\n",c);
    }
  
  return ;
}

//--------------------------------------------------------------------
// Function Name: llsearch()
// Arguments    : A starting node pointer to begin searching from, a
//                key a function pointer which takes in payload data
//                of a node and returns the string that is to be
//                printed.
// Returns      : Pointer (ll *) containing payload data matching with
//                key.
// Description  : User function to search for the payload data in the
//                linked list
//--------------------------------------------------------------------
ll *llsearch(ll *head, void *key, int (*comp)(void *,void *))
{
  ll *temp = NULL;
  
  // if start node or functin pointer provided is NULL
  if ((head == NULL) || (key == NULL) || (com == NULL)) {
    return NULL;
  }
  
  // traverse to the end of the list searching for nodes
  // with payload = key
  for (temp = head; temp != NULL; temp = temp->_next)
    {
      if (comp(temp->_data,key) == 0) {
	return temp;
      }
    }
  
  // if key not found then return NULL pointer
  return NULL ;
}

//--------------------------------------------------------------------
// Function Name: lldelete()
// Arguments    : Head pointer of the list delete, user input data
//                pointer to be matched, a function pointer to compare
//                user input data with node payload data and function
//                pointer to delete payload data from nodes.
// Returns      : NULL pointer if list has 0 elements or has 1 element
//                and user data matches with that node. Original head
//                for all other cases.
// Description  : User function to delete node and its payload data
//                which match user input data.
//--------------------------------------------------------------------
ll *lldelete(ll *head, void *data,
	     int (*comp)(void *,void *) , void (*del_data)(void *))
{
  ll * temp_1 = NULL ;
  ll * temp_2 = NULL ;

  // if the head of the given list is NULL
  if (head == NULL) {
    return NULL;
  }
  // if the list contains only 1 element and it matches the data
  else if ((head->_next == NULL) && (!comp((head->_data),data))) {
    return NULL;
  }
  // if the list contains 2 or more elements and head matches the user
  // input data
  else if (!comp((head->_data),data)) {
    
    // copy the data from head->_next to head,make the _next of head
    // point to the _next of _next of head and delete both the payload
    // and the second node
    head->_data = (head->_next)->_data;
    head->_next = head->_next->_next;
    del_data((head->_data));
    free(head);
    
    return head;
  }
  else{
    // traverse the list and delete the payload and data of the node
    // which matches the user input data
    for (temp_2 = head ;; temp_2 != NULL ; temp_1 = temp_2 ,
	   temp_2 = temp_2 -> _next)
      {
	// if user data matches with current node payload, delete
	// the node and its payload data
	if (comp((temp_2 -> _data),data) == 0) {
	  temp_1 -> _next = temp_2 -> _next;
	  del_data((temp_2->_data));
	  free(temp_2);
	  
	  return head;
	}
      }
  }
}

//--------------------------------------------------------------------
// Function Name: llappend()
// Arguments    : A node pointer 1 and a node pointer 2.
// Returns      : The new head pointer formed afte appending list with
//                head node pointer 2 to tail of list formed by head
//                pointer 1.
// Description  : User function to append linked list 2 to the end of
//                linked list 1
//--------------------------------------------------------------------
ll *llappend(ll *head_1, ll *head_2)
{
  ll *temp = NULL;

  // if head of the first list is null then return NULL pointer
  if (head_1 == NULL) {
      return NULL ;
  }
  else{
  // traverse to the end of list 1 and get the last node pointer
    for (temp = head_1; temp->_next != NULL; temp = temp->_next)
    {
      ;
    }

  // next of last node in list 1 should point to head node of list 2
  temp->_next = head_2;

  // return head
  return head_1;
  
  }
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

ll *llsort(ll *head, int (*comp)(void *, void *))
{
  if (head == NULL)
    {
      return NULL ; 
    }
  ll *temp = head;
  int length = 0;
  for (; temp->_next != NULL ; temp = temp -> _next)
    {
      length++;
    }
  ll *temp_1 = head ;
  ll *temp_2 ;
  for (int i = 1; i < length ; i++)
    {
      temp_1 = head;
      temp_2 = head -> _next;
      for (int j = 1; j <= length - i ; j++,temp_1=temp_1->_next,
	     temp_2=temp_2->_next)
	{
	  if (comp((temp_1 -> _data),((temp_2 -> _data))))
	    {
	      swap((temp_1 -> _data),(temp_2 -> _data));		   
	    }		
	}
    }
  return head;
}
