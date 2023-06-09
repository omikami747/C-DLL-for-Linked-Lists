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
  new->_data = NULL;
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
  if ((head == NULL) || (key == NULL) || (comp == NULL)) {
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
// Arguments    : Head pointer of the list delete, node marked for
//                deletion and function pointer to delete payload data
//                from nodes.
// Returns      : NULL pointer if list has 0 elements or has 1 element
//                and user data matches with that node. Original head
//                for all other cases.
// Description  : User function to delete node and its payload data
//                which matches node marked for deletion.
//--------------------------------------------------------------------
ll *lldelete(ll *head, ll *node, void (*del_data)(void *))
{
  ll *temp_1 = NULL;
  ll *temp_2 = NULL;

  // CASE 1/4: if the head of the given list is NULL
  if (head == NULL) {
    return NULL;
  }
  
  // CASE 2/4: if the list contains only 1 element and it matches
  //           node marked for deletion
  else if ((head->_next == NULL) && (head == node)) {
    del_data((head->_data));
    free(head);

    return NULL;
  }
  
  // CASE 3/4: if the list contains 2 or more elements and head
  //           matches the node marked for deletion
  else if (head == node) {  
    // copy the data from head->_next to head,make the _next of head
    // point to the _next of _next of head and delete both the payload
    // and the second node
    del_data(head->_data);             // delete head payload        
    head->_data = head->_next->_data;  // head data -> 2nd node data
    temp_1 = head->_next;              // store second node pointer
    head->_next = head->_next->_next;  // head next -> to 3rd node
    free(temp_1);                      // delete second node
    
    return head;
  }
  
  // CASE 4/4: if the list contains 2 or more elements and head doesnt
  //           match the node marked for deletion
  else {
    // traverse the list and delete the payload and data of the node
    // which matches the node marked for deletion
    for (temp_2 = head; temp_2 != NULL;
	 temp_1 = temp_2, temp_2 = temp_2->_next) {
	// if node marked for deletion matches with current node,
	// delete the node and its payload data
	if (temp_2 == node) {
	  temp_1 -> _next = temp_2 -> _next;
	  del_data((temp_2->_data));
	  free(temp_2);
	  
	  return head;
	}
      }
    
    // when list length is 1 but head doesnt match
    // node marked for deletion
    return head; 
    
  }
}

//--------------------------------------------------------------------
// Function Name: llappend()
// Arguments    : A node pointer 1 and a node pointer 2.
// Returns      : head pointer formed afte appending list with
//                head node pointer 2 to tail of list formed by head
//                pointer 1.
// Description  : User function to append linked list 2 to the end of
//                linked list 1
//--------------------------------------------------------------------
ll *llappend(ll *head_1, ll *head_2)
{
  ll *temp = NULL;

  // NULL list + NULL list = NULL list
  if (!head_1 && !head_2) {
      return NULL ;
  }
  // NULL list + list 2 = list 2
  else if (!head_1 && head_2) {
    return head_2;
  }
  // list 1 + NULL list = list 1
  else if (head_1 && !head_2) {
    return head_1;
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
