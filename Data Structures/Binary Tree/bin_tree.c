#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bin_tree.h"

#define MAX(a,b)(((a) > (b)) ? (a) : (b))

struct node{
  elem info;
  t_node *left;
  t_node *right;
};

t_tree *create(){
  t_tree* t = (t_tree*)malloc(sizeof(t_tree));
  assert(t != NULL);
  t->root = NULL;
  return t;
}

t_node* create_node(elem x){
  t_node *p = (t_node *)malloc(sizeof(t_node));
  assert(p != NULL);
  p->left = NULL;
  p->right = NULL;
  p->info = x;
  return p;
}


int isEmpty(t_tree *t){
  assert(t != NULL);
  if(t->root == NULL)
    return 1;  
  return 0;
}

void freeTree(t_node *root){ // root aqui é a raiz da arvore ou de uma subarvore
  if(root != NULL){
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}

// segue o padrao; <id_no>(<filho_esq>,<filho_dir>(<>,<>))...
void printTree(t_node *root){
  if(root != NULL){
    printf("%d(", root->info);
    printTree(root->left);
    printf(", ");
    printTree(root->right);
    printf(")");
    
  } else {
    printf("null");
    
  }
}

int height(t_node *root){
  if(root == NULL)
    return 0;

  int left_height = 1 + height(root->left); // altura da subarvore da esquerda
  int right_height = 1 + height(root->right); // altura da subarvore da direita

  return MAX(left_height, right_height);
}

t_node *search(t_node *root, elem x){
  if(root == NULL)
    return NULL;

  if(root->info == x)
    return root;
  
  t_node* aux = search(root->left, x);
  if(aux == NULL)
    aux = search(root->right, x);

  return aux;  
}

t_node *parent_search(t_node *root, elem x){
  if(root == NULL)
    return NULL;

  if(root->left != NULL && root->left->info == x)
    return root;

  if(root->right != NULL && root->right->info == x)
    return root;

  t_node* aux = parent_search(root->left, x);
  if(aux == NULL) // caso o nó não tenha sido achado do lado esquerdo tenta-se o lado direito
    aux = parent_search(root->left, x);

  return aux;

}

int leftInsertion(t_tree *t, elem x, elem parent){// perceba a passagem da arvore e não só um nó raiz
  t_node* p = create_node(x);

  if(parent == -1){
    if(t->root == NULL){
      t->root = p;    
    
    } else {
      free(p);
      return 0; // falha na inserção
    }

  } else {
    t_node* aux = search(t->root, parent);
    if(aux != NULL && aux->left == NULL){ // nó pai existe e há lugar para um filho esquerdo
      aux->left = p;
    
    } else {
      free(p);
      return 0;
    }
  }

  return 1;

} 

int rightInsertion(t_tree *t, elem x, elem parent){
  t_node* p = create_node(x);

  if(parent == -1){
    if(t->root == NULL){
      t->root = p;    
    
    } else {
      free(p);
      return 0; // falha na inserção
    }

  } else {
    t_node* aux = search(t->root, parent);
    if(aux != NULL && aux->right == NULL){ // nó pai existe e há lugar para um filho esquerdo
      aux->right = p;
    
    } else {
      free(p);
      return 0;
    }
  }

  return 1;
}

int removal(t_tree *t, elem x){

}