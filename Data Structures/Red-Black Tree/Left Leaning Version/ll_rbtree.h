
/*
* =====================================================================================================================================================================
*       Projeto 2 de Algoritmos e Estruturas de Dados I -> Árvores Balanceadas
*       Nome do arquivo: ll_rbtree.h -> contém a assinatura de todas as operações que podem realizadas na árvore rubro negra, bem a definição dos dados/valores a serem manipulados
*         
*       Nome:  Eduardo Zaboto Mirolli 
*       Nº USP:  9778501
*
* =====================================================================================================================================================================
*/

#ifndef LL_RBTREE_H
#define LL_RBTREE_H

typedef struct node t_node;

// representação das cores vermelho e preto através da definição de uma variável do tipo bool
typedef enum bool_{
  BLACK = 0,
  RED = 1
}bool;


// representação dos dados presentes em cada nó da árvore
typedef struct node{
  int key;
  t_node *left;
  t_node *right;
  bool color; // cor da aresta que vem do nó pai

} t_node;

typedef struct tree{ 
  t_node* root;  
}t_tree;


// Operações disponíveis
t_tree *create();
void freeTree(t_node *root);
void insertion(t_tree* t, int key);
int min(t_node *root);
int max(t_node *root);
void successor(t_node *root, t_node** suc, int key);
void predecessor(t_node *root, t_node** pred, int key);
void preOrder(t_node *root);
void inOrder(t_node *root);
void postOrder(t_node *root);

#endif