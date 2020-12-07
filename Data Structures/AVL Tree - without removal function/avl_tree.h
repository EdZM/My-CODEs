#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct node t_node;

typedef struct tree{ // a ideia de definir a struct aqui, é pq a implementação será recursiva
  t_node* root;  
}t_tree;


t_tree *create();
int isEmpty(t_tree *t);
void freeTree(t_node *root);
void printTree(t_node *root);
int height(t_node *root);
void insertion(t_tree *t, int info);
t_node* search(t_node *root, int info);
int removal(t_node **root, int info);

void preOrder(t_node *root);
void inOrder(t_node *root);
void postOrder(t_node *root);



#endif