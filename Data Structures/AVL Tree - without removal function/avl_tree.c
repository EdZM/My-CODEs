#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "avl_tree.h"

#define MAX(a,b)(((a) > (b)) ? (a) : (b))

struct node{
  int info;
  int fb; // fator de balanceamento
  t_node *left;
  t_node *right;
};

t_tree *create(){
  t_tree* t = (t_tree*)malloc(sizeof(t_tree));
  assert(t != NULL);
  t->root = NULL;
  return t;
}

t_node* create_node(int info){
  t_node *p = (t_node *)malloc(sizeof(t_node));
  assert(p != NULL);
  p->left = NULL;
  p->right = NULL;
  p->info = info;
  p->fb = 0;
 
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


t_node* EERotate(t_node* desb){ // basicamente faz uma rotação simples para a esquerda
  t_node *aux = desb->right;    // desb é a subárvore desbalanceada
  desb->right = aux->left;
  aux->left = desb;
  return aux;

}

t_node* DDRotate(t_node* desb){ // basicamente faz uma rotação simples para a direita
  t_node* aux = desb->left;
  desb->left = aux->right;
  aux->right = desb;
  return aux;
}

t_node* EDRotate(t_node* desb){ // basicamente faz uma rotação dupla: primeiro para a esquerda depois para a direita
  desb->left = EERotate(desb->left); // rotação para a esquerda
  desb = DDRotate(desb); //rotação para a direita
  return desb;
}

t_node* DERotate(t_node* desb){ // basicamente faz uma rotação dupla: primeiro para a direita depois para a esquerda
  desb->right = DDRotate(desb->right); // rotação para a direita
  desb = EERotate(desb); //rotação para a esquerda
  return desb;
}


t_node* avlInsertion(t_node* root, int info, int* flag){ 
  if(root != NULL){    
    if (info < (root)->info){
      // inserção na sub árvore esquerda respeitando a ordem de uma árvore binária de busca
      root->left = avlInsertion(root->left, info, flag);
      
      if(*flag == 1){
        switch(root->fb){
          case -1: // a sub árvore da direita está maior que a da esquerda em uma unidade
            root->fb = 0; // como foi feita uma inserção a esquerda o fator de balanceamento ficou 0, e as duas subarvores tem o mesmo tamanho
            *flag = 0;
            break;
          
          case 0: // ambas as subárvores tem mesmo tamanho antes da inserção
            root->fb = 1;
            *flag = 1; // avisa os níveis acima da recursão que é necessário realizar novas verificações nos nós ancestrais
            break;

          case 1: // é onde esta o desbalanceamento e as rotações (simples e/ou duplas são necessárias)
                  // lembrando que: fb > 0 ==> rotação simples, caso contrario, dupla
            
            if(root->left->fb == 1){
              root = DDRotate(root);
              root->right->fb = 0;
              root->fb = 0;

            } else { // rotação dupla é necessária => rotação ED ou DE
              root = EDRotate(root);
              
              if(root->fb == -1){
                root->left->fb = 1;
                root->right->fb = 0;
                root->fb = 0;

              } else if(root->fb == 1){
                root->left->fb = 0;
                root->right->fb = -1;
                root->fb = 0;

              } else { //root->fb == 0 
                root->left->fb = 0;
                root->right->fb = 0;
                root->fb = 0;
              }              
            }
            *flag = 0;
            break;
        }
      }

            
    } else if(info > (root)->info){
      // inserção na sub árvore direita respeitando a ordem de uma árvore binária de busca
      root->right = avlInsertion(root->right, info, flag);

      if(*flag == 1){
        switch(root->fb){
          case 1: // a sub árvore da esquerda está maior que a da direita em uma unidada
            root->fb = 0; // como foi feita uma inserção a direita o fator de balanceamento ficou 0, e as duas subarvores tem o mesmo tamanho
            *flag = 0;
            break;
          
          case 0: // ambas as subárvores tem mesmo tamanho antes da inserção
            root->fb = -1;
            *flag = 1; // avisa os níveis acima da recursão que é necessário realizar novas verificações nos nós ancestrais
            break;

          case -1:// é onde esta o desbalanceamento e as rotações (simples e/ou duplas são necessárias)
                  // lembrando que: fb > 0 ==> rotação simples, caso contrario, dupla
            
            if(root->right->fb == -1){ // sinais iguais
              root = EERotate(root);
              root->left->fb = 0;
              root->fb = 0;

            } else { // rotação dupla é necessária => rotação ED ou DE
                     // sinais diferentes
              root = DERotate(root);
              
              if(root->fb == -1){ // s
                root->left->fb = 1;
                root->right->fb = 0;
                root->fb = 0;

              } else if(root->fb == 1){
                root->left->fb = 0;
                root->right->fb = -1;
                root->fb = 0;

              } else { //root->fb == 0 
                root->left->fb = 0;
                root->right->fb = 0;
                root->fb = 0;
              }              
            }
            *flag = 0;
            break;

        }


      }

    } else { // caso a chave a ser inserida seja igual a chave do nó atual, apenas uma mensagem é impressa indicando que a chave já einfoiste
      printf("Elemento ja existente\n");    
      
    }      
    
  } else { // nesse ponto foi encontrada a posição mais adequada para o novo nó
    // alocação do nó a ser inserido na treap
    root = create_node(info);
    *flag = 1;
  }
  
  return root; // retorno do ponteiro para a sub árvore resultante dessa operação
}

void insertion(t_tree* t, int info){
  int flag = 0; // indica se é necessário verificar o fator de balanceamento
  t->root = avlInsertion(t->root, info, &flag); // as inserções da avl podem acabar mudando a raiz várias vezes
}


t_node *search(t_node *root, int info){
  if(root == NULL){
    return NULL;
  } else if(root->info == info){
    return root;
  } else if(info < root->info){
    return search(root->left, info);
  } else {
    return search(root->right, info);
  }
}


int removal(t_node **root, int info){
  if(*root == NULL){ // caso 1(de 4): árvore vazia ou intento nao encontrado
    return 0;
  
  } else if(info < (*root)->info){
    return removal(&(*root)->left, info);
  
  } else if(info > (*root)->info){
    return removal(&(*root)->right, info);
  
  } else {
    // demais casos:
    if((*root)->left == NULL && (*root)->left == NULL){ // caso 2: nó é folha
      free(*root);
      (*root) = NULL;
      return 1;
    
    // caso 3: o nó tem só um 1 filho
    } else if((*root)->left == NULL){ // caso 3.1: nó tem só o filho a direita
      t_node* auinfo = *root;
      (*root) = (*root)->right;
      free(auinfo);      
      return 1;

    } else if((*root)->right == NULL){ // caso 3.2: nó tem só o filho a esquerda
      t_node* auinfo = *root;
      (*root) = (*root)->left;
      free(auinfo);      
      return 1;

    } else { // caso 4: o nó tem 2 filhos
      // 2 estratégias: encontrar o menor dos maiores da subárvore da esquerda ou o maior dos menores da subárvore da direita
      
      // usarei a primeira estratégia
      t_node *auinfo = (*root)->left;
      while(auinfo->right != NULL){
        auinfo = auinfo->right;
      }

      // auinfo->right aqui é NULO e até aqui pode ser que auinfo->left seja diferente de nulo
      (*root)->info = auinfo->info;
      return removal(&(*root)->left, auinfo->info); // resolve o problema do comentário acima


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