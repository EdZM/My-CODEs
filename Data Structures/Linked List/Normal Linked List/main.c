#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){

  t_list* l = NULL;

  l = create();
  insertion(l, 5);
  insertion(l, 2);
  insertion(l, 3);
  insertion(l, 7);
  insertion(l, 8);
  
  printList(l);
  
  invertList(l);
  printList(l);
  
  removal(l,8); // remove inicio da lista invertida
  printList(l);

  removal(l,3); // remove meio da lista invertida
  printList(l);

  removal(l,5); // remove fim da lista invertida
  printList(l);
  



  
  freeList(l);

  return 0;
}