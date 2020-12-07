#include <stdio.h>
#include "avl_tree.h"

int main(){

  t_tree *avltree = create();

  insertion(avltree, 1);
  insertion(avltree, 2);
  insertion(avltree, 3);
  insertion(avltree, 5);
  insertion(avltree, 7);
  insertion(avltree, 4);

  printTree(avltree->root);
  printf("\n");
  
  //removal(&(avltree)->root, 5);
  

  return 0;
}

