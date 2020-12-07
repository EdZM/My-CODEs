#include <stdio.h>
#include <stdlib.h>
#include "bin_tree.h"


int main(){
  t_tree* tree = create();

  leftInsertion(tree, 1, -1);
  leftInsertion(tree, 2, 1);
  rightInsertion(tree, 3, 1);
  leftInsertion(tree, 4, 3);
  rightInsertion(tree, 5, 3);
  leftInsertion(tree, 6, 4);

  printTree(tree->root);
  printf("\n");
  
  return 0; 
}