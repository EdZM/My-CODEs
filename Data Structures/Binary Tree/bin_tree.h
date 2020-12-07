#ifndef BIN_TREE_H
#define BIN_TREE_H

typedef int elem;
typedef struct node t_node;

typedef struct tree{ // a ideia de definir a struct aqui, é pq a implementação será recursiva
  t_node* root;  
}t_tree;


t_tree *create();
int isEmpty(t_tree *t);
void freeTree(t_node *root);
void printTree(t_node *root);
int height(t_node *root);
t_node* search(t_node* root, elem x);
t_node* parent_search(t_node* root, elem x);
int leftInsertion(t_tree *t, elem x, elem parent); // perceba a passagem da arvore e não só um nó raiz
int rightInsertion(t_tree *t, elem x, elem parent);
int removal(t_tree* t, elem x);

#endif