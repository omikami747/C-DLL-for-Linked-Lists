#include "libll.h"
#include <string.h>

char *prs(void *s) 
{
  return (char *)s;
}

int cmp(void *s1, void *s2)
{
  return strcmp((char *)s1, (char *)s2);
}

void sdel(void *s) 
{
  free(s);
}


void test_llsearch(ll *l, char *s)
{
  ll *search_result;

  if (search_result = llsearch(l, s, cmp)) {
    printf("Search for '%s' returned node with key '%s'\n",
           s, (char *)search_result->_data);
  }
  else {
    printf("Search for '%s' returned no match.\n", s);
  }
}

int main(void) 
{
  ll *mylist = NULL;

  //----------------------------------------------------------------------
  // Test creating and adding to list
  //----------------------------------------------------------------------
  mylist = lladd(mylist, strdup("Hello!"));
  mylist = lladd(mylist, strdup("This"));
  mylist = lladd(mylist, strdup("is"));
  mylist = lladd(mylist, strdup("a"));
  mylist = lladd(mylist, strdup("test"));
  mylist = lladd(mylist, strdup("of"));
  mylist = lladd(mylist, strdup("Omkar's"));
  mylist = lladd(mylist, strdup("linked"));
  mylist = lladd(mylist, strdup("list"));
  mylist = lladd(mylist, strdup("library."));  
  mylist = lladd(mylist, strdup("It"));  
  mylist = lladd(mylist, strdup("is"));  
  mylist = lladd(mylist, strdup("a"));  
  mylist = lladd(mylist, strdup("cool"));  
  mylist = lladd(mylist, strdup("library."));  

  llprint(mylist, prs);

  //----------------------------------------------------------------------
  // Test llsearch
  //----------------------------------------------------------------------
  test_llsearch(mylist, "test");
  test_llsearch(mylist, "Notting");

  //----------------------------------------------------------------------
  // Test lldelete
  //----------------------------------------------------------------------
  lldelete(mylist, "library.", cmp, sdel);
  llprint(mylist, prs);  
  
  exit(123);
  
}

