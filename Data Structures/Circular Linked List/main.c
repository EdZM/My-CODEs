#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){

  t_list* l = create();
  
  insertion(l, 1);
  insertion(l, 2);
  insertion(l, 3);
  insertion(l, 4);
  insertion(l, 5);

  printList(l);
  removal(l, 3);
  
  freeList(l);
  
  return 0;
}
