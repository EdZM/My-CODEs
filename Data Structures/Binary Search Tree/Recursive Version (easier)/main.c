#include <stdio.h>
#include "bstree.h"

int main(){

  t_tree *bstree = create();

  insertion(&(bstree)->root, 5);
  insertion(&(bstree)->root, 3);
  insertion(&(bstree)->root, 7);
  insertion(&(bstree)->root, 9);
  insertion(&(bstree)->root, 8);
  insertion(&(bstree)->root, 2);

  printTree(bstree->root);
  printf("\n");
  
  removal(&(bstree)->root, 5);

  printTree(bstree->root);
  printf("\n");

  

  return 0;
}

