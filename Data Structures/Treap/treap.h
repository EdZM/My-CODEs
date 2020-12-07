#ifndef TREAP_H
#define TREAP_H

typedef struct node t_node;

typedef struct node{
  int info;
  int prio;
  t_node *left;
  t_node *right;

} t_node;


typedef struct tree{ 
  t_node* root;  

}t_tree;

// funções principais da treap
t_tree *create();
void freeTree(t_node *root);
void insertion(t_tree *t, int info, int prio);
void removal(t_tree *t, int key);
int search(t_node *root, int key);

// funções para os tipos de impressão
void preOrder(t_node *root);
void inOrder(t_node *root);
void postOrder(t_node *root);
void breadthPrint(t_node *root);


#endif