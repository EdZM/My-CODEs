/*
* =========================================================================================================================================================
*       Projeto 2 de Algoritmos e Estruturas de Dados I -> Árvores Balanceadas
*       Nome do arquivo: ll_rbtree.c -> contém a implementação de todas as operações que podem realizadas na árvore rubro negra
*         
*       Nome:  Eduardo Zaboto Mirolli 
*       Nº USP:  9778501
*
* =========================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ll_rbtree.h"


/* Função para criar a árvore rubro negra propriamente dita
  -> complexidade de tempo da operação: O(1)
  - parâmetros:
      sem parâmetros

  - retorno:
      t_tree*: ponteiro para a árvore recém criada
*/
t_tree *create(){
  t_tree* t = (t_tree*)malloc(sizeof(t_tree));
  assert(t != NULL);
  t->root = NULL;
  return t;
}


/* Função para criar um nó para ser colocado na árvore
  -> complexidade de tempo da operação: O(1)
  - parâmetros:
      int key: chave do nó 
      bool color: cor da aresta que vem do nó pai do novo nó

  - retorno:
      t_node*: ponteiro para o nó recém criado
*/
t_node* create_node(int key, bool color){
  t_node *p = (t_node *)malloc(sizeof(t_node));
  assert(p != NULL);
  p->left = NULL;
  p->right = NULL;
  p->key = key;
  p->color = color;
  return p;
}


/* Função para checar se a aresta que vem do pai do nó passado como parâmetro é vermelha
  - parâmetros:
       t_node* root: ponteiro para a raiz da árvore/sub árvore

  - retorno:
      int:
        0 -> caso o nó seja nulo
        1 -> caso a aresta seja vermelha
*/
int isRed(t_node* root){
  if(root == NULL) return 0;
  return (root->color == RED);
}


/* Função para desalocar a árvore rubro negra
  -> complexidade de tempo da operação: O(n)
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore

  - retorno:
      sem retorno
*/
void freeTree(t_node *root){ 
  if(root != NULL){
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}


// As próximas três funções fazem os ajustes locais
// para tratar os três casos que podem ocorrer quando a inserção 
// é em nó com incidência vermelha 
/* Função para realizar uma rotação simples para a esquerda
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore que sofrerá a rotação

  - retorno:
      t_node*: ponteiro para a árvore/sub árvore alterada
*/
t_node* leftRotate(t_node* root){
  
  // ajustes dos links para fazer a rotação a esquerda
  t_node* aux = root->right;
  root->right = aux->left;
  aux->left = root;
  
  // ajuste das cores
  aux->color = root->color;
  root->color = RED;

  return aux;
}


/* Função para realizar uma rotação simples para a direita
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore que sofrerá a rotação

  - retorno:
      t_node*: ponteiro para a árvore/sub árvore alterada
*/
t_node* rightRotate(t_node* root){
  
  // ajustes necessários para rotação a direita
  t_node* aux = root->left;
  root->left = aux->right;
  aux->right = root;

  // ajuste das cores
  aux->color = root->color;
  root->color = RED;

  return aux;
}


/* Função para realizar a inversão das cores das arestas dos filhos e do pai de um nó passado como parâmetro
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore

  - retorno:
      sem retorno
*/
void flipColors(t_node* root){
  root->color = RED;
  root->left->color = BLACK;
  root->right->color = BLACK;
}


/* Função para inserir recursivamente os nós na árvore rubro negra
  -> complexidade de tempo da operação: O(log(n))
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore que sofrerá a inserção
      int key: chave a ser inserida

  - retorno:
      t_node*: ponteiro para a árvore/sub árvore alterada
*/
t_node* LLRBInsertion(t_node* root, int key){ // o ponteiro será alterado dentro dessa função.
  if(root != NULL){    
    if (key < (root)->key){
      // inserção na sub árvore esquerda respeitando a ordem de uma árvore binária de busca
      root->left = LLRBInsertion(root->left, key);
      
    } else if(key > (root)->key){
      // inserção na sub árvore direita respeitando a ordem de uma árvore binária de busca
      root->right = LLRBInsertion(root->right, key);

    }      
    
  } else { // nesse ponto foi encontrada a posição mais adequada para o novo nó
    // alocação do nó a ser inserido na árvore
    root = create_node(key, RED);
    
  }
  
  // após a inserção propriamente dita, são feitos os ajustes locais para respeitar as regras da árvore rubro negra
  if(!isRed(root->left) && isRed(root->right)) root = leftRotate(root);
  if(isRed(root->left) && isRed(root->left->left)) root = rightRotate(root);
  if(isRed(root->left) && isRed(root->right)) flipColors(root);

  return root; // retorno do ponteiro para a sub árvore resultante dessa operação
}


/* Função para chamar a operação de inserção realizada partindo do nó raiz da árvore
  - parâmetros:
      t_tree* t: ponteiro para a árvore rubro negra, que será alterada na operação
      int key: chave inteira a ser inserida

  - retorno:
     sem retorno
*/
void insertion(t_tree* t, int key){
  t->root = LLRBInsertion(t->root, key); // as inserções da rubro negra podem acabar mudando a raiz várias vezes
}


/* Função para encontrar o nó da árvore cuja chave é a menor de todas, sempre descendo para a esquerda na árvore
  -> complexidade de tempo da operação: O(log(n))
  - parâmetros:
       t_node* root: ponteiro para a raiz da árvore/sub árvore

  - retorno:
      int: valor da chave mínima
*/
int min(t_node *root){
  t_node *aux = root;
  while(aux->left != NULL){
    aux = aux->left;
  }

  return aux->key;
}

/* Função para encontrar o nó da árvore cuja chave é a maior de todas, sempre descendo para a direita na árvore
  -> complexidade de tempo da operação: O(log(n))
  - parâmetros:
       t_node* root: ponteiro para a raiz da árvore/sub árvore

  - retorno:
      int: valor da chave máxima
*/
int max(t_node *root){
  t_node *aux = root;
  while(aux->right != NULL){
    aux = aux->right;
  }

  return aux->key;
}


/* Função para encontrar recursivamente o nó sucessor a um nó passado como parâmetro
  -> complexidade de tempo da operação: O(log(n))
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore, a partir da qual a impressão se inicia
      t_node** pred: referência para o nó sucessor, que poderá ser atualizada durante a operação
      int key: chave do nó cujo sucessor será encontrado

  - retorno:
      sem retorno
*/
void successor(t_node *root, t_node** suc, int key){
  if(root == NULL){
    return; // o nó não possui sucessor

  } else if(key < root->key){
    (*suc) = root; // o nó atual é salvo como sucessor antes que a recursão vá para o filho esquerdo do nó atual
    return successor(root->left, suc, key);

  } else if(key > root->key){
    return successor(root->right, suc, key);
  
  } else { // a chave foi encontrada na árvore
    if(root->right != NULL){ // se o nó possuir filho a direita, seu sucessor será obtido indo para esse filho e depois decendo tudo para a esquerda
      t_node *aux = root->right;
      while(aux->left != NULL){
        aux = aux->left;
      }
      (*suc) = aux; // ao final do processo de travessia, o sucessor é encontrado
    } 
    return;
  
  }
}


/* Função para encontrar recursivamente o nó predecessor a um nó passado como parâmetro
  -> complexidade de tempo da operação: O(log(n))
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore, a partir da qual a impressão se inicia
      t_node** pred: referência para o nó predecessor, que poderá ser atualizada durante a operação
      int key: chave do nó cujo predecessor será encontrado

  - retorno:
      sem retorno
*/
void predecessor(t_node *root, t_node** pred, int key){
  if(root == NULL){
    return;
  
  } else if(key < root->key){
    return predecessor(root->left, pred, key);

  } else if(key > root->key){
    (*pred) = root; // o nó atual é salvo como predecessor antes que a recursão vá para o filho direito do nó atual
    return predecessor(root->right, pred, key);
  
  } else { // a chave foi encontrada na árvore
    if(root->left != NULL){ // se o nó possuir filho a esquerda, seu predecessor será obtido indo para esse filho e depois decendo tudo para a direita
                            // seguindo o processo inverso ao da operação que encontra o sucessor
      t_node *aux = root->left;
      while(aux->right != NULL){
        aux = aux->right;
      }
      (*pred) = aux; // ao final do processo de travessia, o predecessor é encontrado
    }
    return;
  }

}


/* Função para realizar a impressão em pré ordem da árvore rubro negra
  -> complexidade de tempo da operação: O(n)
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore, a partir da qual a impressão se inicia

  - retorno:
      sem retorno
*/
void preOrder(t_node *root){
  if(root != NULL){
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
  }

}


/* Função para realizar a impressão em ordem da árvore rubro negra
  -> complexidade de tempo da operação: O(n)
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore, a partir da qual a impressão se inicia

  - retorno:
      sem retorno
*/
void inOrder(t_node *root){
  if(root != NULL){
    inOrder(root->left);
    printf("%d ", root->key);
    inOrder(root->right);
  }
}


/* Função para realizar a impressão em pos ordem da árvore rubro negra
  -> complexidade de tempo da operação: O(n)
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore, a partir da qual a impressão se inicia

  - retorno:
      sem retorno
*/
void postOrder(t_node *root){
  if(root != NULL){
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->key);
  }
}
