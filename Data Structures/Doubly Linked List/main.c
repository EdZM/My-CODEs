#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
  t_list* l = create();

  insertion(l, 5);
  insertion(l, 2);
  insertion(l, 7);
  insertion(l, 4);
  insertion(l, 1);
  insertion(l, 8);

  printList(l);
  printInverseList(l);

  removal(l, 1); // remove do inicio
  printList(l);
  removal(l, 8); // remove do fim
  printList(l);
  removal(l, 5); // remove do meio
  printList(l);


  if ( search(l, 4) == 1 ) {
    printf("found\n");
  
  } else {
    printf("not found\n");
    
  }


  freeList(l);
  return 0;
}
