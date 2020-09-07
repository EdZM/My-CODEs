#ifndef BSTREE_H
#define BSTREE_H

#include <stdbool.h>

typedef struct node NODE; // struct node passa a ser resumido a NODE apenas ==> struct node === NODE

typedef struct node{
  NODE* right;
  NODE* left;
  int key;

} NODE;

typedef struct bstree {
  NODE *root; // a raiz sendo um nó como qualquer outro precisa de um ponteiro pra ela para que ela seja criada dinamicamente

}BSTREE;

typedef BSTREE* BSTREE_PTR; // BSTREE_PTR aponta para a arvore representada por BSTREE. Inicialmente BSTREE contem só o no raiz

//functions
void create_tree(BSTREE_PTR* bst_ptr);
void insertion(BSTREE_PTR bst_ptr, int key);
void search(BSTREE_PTR bst_ptr, int key);
void deletion(BSTREE_PTR bst_ptr, int key);
void printInOrder(BSTREE_PTR bst_ptr);
void free_bstree(BSTREE_PTR bst_ptr);




#endif