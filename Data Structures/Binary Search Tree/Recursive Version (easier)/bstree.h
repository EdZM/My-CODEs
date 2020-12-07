#ifndef BSTREE_H
#define BSTREE_H

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
int insertion(t_node **root, elem x);
t_node* search(t_node *root, elem x);
int removal(t_node **root, elem x);

void preOrder(t_node *root);
void inOrder(t_node *root);
void postOrder(t_node *root);



#endif