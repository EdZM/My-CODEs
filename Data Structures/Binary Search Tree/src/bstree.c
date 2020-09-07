#include <stdio.h>
#include <stdlib.h>
#include "../include/bstree.h"

void create_tree(BSTREE_PTR* bst_ptr){ // ptr === BSTREE*
  (*bst_ptr) = (BSTREE*) malloc(sizeof(BSTREE)); // criação da struct BSTREE, que tem um NODE* root (que ainda nao foi usado para criar o nó raiz)
  
}

void create_node(NODE** node, int key){ 
  if((*node) == NULL){
    (*node) = (NODE *)malloc(sizeof(NODE));
    (*node)->right = NULL;
    (*node)->left = NULL;
    (*node)->key = key;
  }

}

void insertion(BSTREE_PTR bst_ptr, int key){ 

  // lembre-se: aux guarda um ponteiro
  NODE** aux = &(bst_ptr->root); // aux tem o endereço do ponteiro que aponta para a raiz da arvore => lembrando que (bst_ptr->root) == NODE*
                                 // mudanças nesse endereço ou nos que estiverem ligados a ele alteram permanentemente a arvore

  while( (*aux) != NULL ){ // (*aux) == NODE*, (*aux) apenas aponta para nós da árvore
    if(key < (*aux)->key){ 
      aux = &(*aux)->left; // aux deve receber o endereço do ponteiro que aponta para o nó esquerdo ao nó atual
  
    } else if(key > (*aux)->key){
      aux = &(*aux)->right;
    
    } else {
      printf("the key %d is already on the tree\n ", key);
      return;
    }

  }

  create_node(aux, key);
}


void print(NODE* aux){
  if(aux != NULL){
    print(aux->left);
    printf("%d ", aux->key);
    print(aux->right);    
  }

}

void printInOrder(BSTREE_PTR bst_ptr){
  printf("BSTree nodes in order: ");
  print(bst_ptr->root);
  printf("\n");
}


void search(BSTREE_PTR bst_ptr, int key){

  NODE* aux = bst_ptr->root; // aux só aponta para o mesmo lugar que root

  while( aux != NULL ){ 
    if(key < aux->key){ 
      aux = aux->left; 
  
    } else if(key > aux->key){
      aux = aux->right;
    
    } else {
      printf("Key %d Found\n",aux->key);
      return;
    }

  }
  printf("Not found it\n");

}


NODE* findMin(NODE* node){
  while (node->left != NULL){
    node = node->left;
  }

  return node;
}

void deletion(BSTREE_PTR bst_ptr, int key){

  NODE* aux = (bst_ptr->root);
  NODE* prev = (bst_ptr->root);
  
  while ( (aux) != NULL ){ 
    if (key < (aux)->key){
      prev = aux;
      aux = aux->left;

    } else if (key > (aux)->key){
      prev = aux;
      aux = aux->right;
    
    } else {
      // para remover um nó é necessario verificar em qual dos tres casos da remoção o nó a ser removido pertence:
      if ((aux)->left == NULL && (aux)->right == NULL){ // caso1: é nó folha?
        if((prev)->left == (aux)){
          free((aux));
          (prev)->left = NULL;
        
        } else {
          free((aux));
          (prev)->right = NULL;
        }      
      
      } else if ((aux)->left != NULL && (aux)->right == NULL ){  // caso 2: tem apenas UM filho a esquerda?
        (prev)->left = (aux)->left;
        free(aux);
        
      } else if ((aux)->left == NULL && (aux)->right != NULL){ // variação do caso 2: tem apenas UM filho a direita?
        (prev)->left = (aux)->right;
        free(aux);

      } else { // caso 3: tem exatamente DOIS filhos? Nesse caso, encontre o valor minimo a direita do nó atual e troque-o com o nó atual
        
        prev = aux;
        aux = findMin(aux->right); // encontra o menor valor da sub arvore direita ao nó atual

        int cur_key = aux->key; 

        deletion(bst_ptr, aux->key); // deleta o nó que cuja chave é a menor da sub arvore direita do nó atual

        prev->key = cur_key; // atualiza a chave do nó 'removido' com a chave atual

      }

      return;
    }
  }
  

  printf("Key not found\n ");
  return;
}



void free_nodes(NODE** aux){
  if((*aux) != NULL){
    free_nodes(&(*aux)->left);
    free_nodes(&(*aux)->right);
    free((*aux));
  }
}

void free_bstree(BSTREE_PTR bst_ptr){
  free_nodes(&(bst_ptr)->root);
  free(bst_ptr);
}
