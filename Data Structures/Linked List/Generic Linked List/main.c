#include <stdio.h>
#include <stdlib.h>
#include "gen_list.h"

int main(){
  t_node *l1 = concat(atom(3), atom(4));
  t_node *l2 = sublist(l1);
  t_node *l;
  l2 = concat(l2, atom(2));
  l = concat(atom(1), l2);

  printList(l);

  freeList(l);

  return 0;
}





