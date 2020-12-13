/*
* =========================================================================================================================================================
*       Projeto 2 de Algoritmos e Estruturas de Dados I -> Árvores Balanceadas
*       Nome do arquivo:  P2_Alg-I.c                   
*         
*       Nome:  Eduardo Zaboto Mirolli 
*       Nº USP:  9778501
*
* =========================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "ll_rbtree.h"

int main(){

  t_tree* ll_rbtree = create();
  int numOps;
  int opType;
  
  scanf("%d", &numOps);
  
  for (int i = 0; i< numOps; i++) {
    scanf("%d", &opType);
    if(opType < 4){
      int key;
      scanf("%d", &key);
      
      if(opType == 1) insertion(ll_rbtree, key);
      if(opType == 2) {
        t_node* suc = NULL;
        successor(ll_rbtree->root, &suc, key);

        if(suc != NULL) printf("%d\n", suc->key);
        else printf("erro\n");
        
      }
      
      if(opType == 3) {
        t_node* pred = NULL;
        predecessor(ll_rbtree->root, &pred, key);

        if(pred != NULL) printf("%d\n", pred->key);
        else printf("erro\n");
      }
      
    } else if(opType < 6){
      if(opType == 4) printf("%d\n", max(ll_rbtree->root));
      if(opType == 5) printf("%d\n", min(ll_rbtree->root));
      
    } else {
      if(opType == 6) preOrder(ll_rbtree->root);
      if(opType == 7) inOrder(ll_rbtree->root);
      if(opType == 8) postOrder(ll_rbtree->root);
      printf("\n"); 
    }
  }

  freeTree(ll_rbtree->root);  
  free(ll_rbtree);

  return 0;
}

