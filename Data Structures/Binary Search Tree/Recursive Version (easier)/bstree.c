#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bstree.h"

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


int insertion(t_node** root, elem x){ // o ponteiro será alterado dentro dessa função
  if(*root == NULL){
    *root = (t_node*)malloc(sizeof(t_node));
    (*root)->info = x;
    (*root)->left = NULL;
    (*root)->right = NULL;  
    return 1;

  } else if (x == (*root)->info){
    return 0;
  
  } else if(x < (*root)->info){
    return insertion(&(*root)->left, x); //passa o endereço do ponteiro para o nó esquerdo 
  
  } else {
    return insertion(&(*root)->right, x); //passa o endereço do ponteiro para o nó direito
  
  }

}


t_node *search(t_node *root, elem x){
  if(root == NULL){
    return NULL;
  } else if(root->info == x){
    return root;
  } else if(x < root->info){
    return search(root->left, x);
  } else {
    return search(root->right, x);
  }
}


int removal(t_node **root, elem x){
  if(*root == NULL){ // caso 1(de 4): árvore vazia ou elemento nao encontrado
    return 0;
  
  } else if(x < (*root)->info){
    return removal(&(*root)->left, x);
  
  } else if(x > (*root)->info){
    return removal(&(*root)->right, x);
  
  } else {
    // demais casos:
    if((*root)->left == NULL && (*root)->left == NULL){ // caso 2: nó é folha
      free(*root);
      (*root) = NULL;
      return 1;
    
    // caso 3: o nó tem só um 1 filho
    } else if((*root)->left == NULL){ // caso 3.1: nó tem só o filho a direita
      t_node* aux = *root;
      (*root) = (*root)->right;
      free(aux);      
      return 1;

    } else if((*root)->right == NULL){ // caso 3.2: nó tem só o filho a esquerda
      t_node* aux = *root;
      (*root) = (*root)->left;
      free(aux);      
      return 1;

    } else { // caso 4: o nó tem 2 filhos
      // 2 estratégias: encontrar o menor dos maiores da subárvore da esquerda ou o maior dos menores da subárvore da direita
      
      // usarei a primeira estratégia
      t_node *aux = (*root)->left;
      while(aux->right != NULL){
        aux = aux->right;
      }

      // aux->right aqui é NULO e até aqui pode ser que aux->left seja diferente de nulo
      (*root)->info = aux->info;
      return removal(&(*root)->left, aux->info); // resolve o problema do comentário acima


    }
  }
}

void preOrder(t_node *root){
  if(root != NULL){
    printf("%d ", root->info);
    preOrder(root->left);
    preOrder(root->right);
  }

}

void inOrder(t_node *root){
  if(root != NULL){
    inOrder(root->left);
    printf("%d ", root->info);
    inOrder(root->right);
  }
}

void postOrder(t_node *root){
  if(root != NULL){
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->info);
  }
}