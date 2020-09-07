#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/bstree.h"

int main (int argc, char* argv[]){

  BSTREE_PTR bst_ptr = NULL; // bst_ptr aponta o nó raiz da arvore
  create_tree(&bst_ptr);

  for (int i = 0; i < 11; i++){
    int num;
    if(scanf("%d\n", &num)){
      insertion(bst_ptr, num);
    }
    
  }

  printf("ROOT node:%d\n", bst_ptr->root->key);
  
  search(bst_ptr, 10);

  printInOrder(bst_ptr);

  deletion(bst_ptr, 50);

  printf("new root: %d\n", bst_ptr->root->key);

  printInOrder(bst_ptr);

  free_bstree(bst_ptr);
  

return 0;  
}
