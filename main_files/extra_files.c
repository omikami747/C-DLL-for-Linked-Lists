
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
