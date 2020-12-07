#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "treap.h"
#include "queue.h"


/* Função para criar a treap propriamente dita
  - parâmetros:
      sem parâmetros

  - retorno:
      t_tree*: ponteiro para a treap recém criada
*/
t_tree *create(){
  t_tree* t = (t_tree*)malloc(sizeof(t_tree));
  assert(t != NULL);
  t->root = NULL;
  return t;
}


/* Função para criar um nó para ser colocado na treap
  - parâmetros:
      int info: chave do nó 
      int prio: prioridade do nó

  - retorno:
      t_node*: ponteiro para o nó recém criado
*/
t_node* create_node(int info, int prio){
  t_node *p = (t_node *)malloc(sizeof(t_node));
  assert(p != NULL);
  p->info = info;
  p->prio = prio;
  p->left = NULL;
  p->right = NULL;

  return p;
}

/* Função para desalocar a treap
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


/* Função para realizar uma rotação simples para a esquerda
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore que sofrerá a rotação

  - retorno:
      t_node*: ponteiro para a árvore/sub árvore alterada
*/
t_node* leftRotate(t_node* root){
  t_node *aux;

  // ajustes necessários para rotação a esquerda
  aux = root->right;
  root->right = aux->left;
  aux->left = root;

  return aux;
}


/* Função para realizar uma rotação simples para a direita
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore que sofrerá a rotação

  - retorno:
      t_node*: ponteiro para a árvore/sub árvore alterada
*/
t_node* rightRotate(t_node* root){
  t_node* aux;

  // ajustes necessários para rotação a direita
  aux = root->left;
  root->left = aux->right;
  aux->right = root;

  return aux;
}


/* Função para inserir recursivamente os nós na treap, de modo que respeite a ordem de uma árvore binária de busca(abb) e de uma árvore heap
  -> complexidade de tempo da operação: O(log(n))
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore que sofrerá a inserção
      int info: chave a ser inserida
      int prio: prioridade da chave a ser inserida

  - retorno:
      t_node*: ponteiro para a árvore/sub árvore alterada
*/
t_node* treapInsertion(t_node* root, int info, int prio){ // o ponteiro será alterado dentro dessa função.
  if(root != NULL){    
    if (info < (root)->info){
      // inserção na sub árvore esquerda respeitando a ordem de uma árvore binária de busca
      root->left = treapInsertion(root->left, info, prio);
      
      // ajuste da prioridade para respeitar a estrutura/ordem da heap
      if(root->left->prio > root->prio){ // se o filho esquerdo tiver prioridade maior que seu pai, o pai é rotacionado para a direita
        root = rightRotate(root); 
      }

    } else if(info > (root)->info){
      // inserção na sub árvore direita respeitando a ordem de uma árvore binária de busca
      root->right = treapInsertion(root->right, info, prio);

      // ajuste da prioridade para respeitar a estrutura/ordem da heap
      if(root->right->prio > root->prio){ // se o filho direito tiver prioridade maior que seu pai, o pai é rotacionado para a esquerda
        root = leftRotate(root);
      }

    } else { // caso a chave a ser inserida seja igual a chave do nó atual, apenas uma mensagem é impressa indicando que a chave já existe
      printf("Elemento ja existente\n");    
      
    }      
    
  } else { // nesse ponto foi encontrada a posição mais adequada para o novo nó
    // alocação do nó a ser inserido na treap
    root = create_node(info, prio);
    
  }
  
  return root; // retorno do ponteiro para a sub árvore resultante dessa operação
}


/* Função para chamar a operação de inserção realizada partindo do nó raiz da árvore
  - parâmetros:
      t_tree* t: ponteiro para a árvore treap, que será alterada na operação
      int info: chave a ser inserida
      int prio: prioridade da chave

  - retorno:
     sem retorno
*/
void insertion(t_tree* t, int info, int prio){
  t->root = treapInsertion(t->root, info, prio); // as inserções da treap podem acabar mudando a raiz várias vezes
}


/* Função para buscar recursivamente chaves na treap
  -> complexidade de tempo da operação: O(log(n))
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore que sofrerá a inserção
      int key: chave a ser pesquisada

  - retorno:
      int: 
        0 --> a chave não foi encontrada
        1 --> a chave foi encontrada
*/
int search(t_node *root, int key){
  if(root == NULL){    
    return 0;
  
  } else if(root->info == key){
    return 1;
  
  } else if(key < root->info){
    return search(root->left, key);
  
  } else {
    return search(root->right, key);
  }
}


/* Função para remover recursivamente os nós na treap, mantendo suas propriedades
  -> complexidade de tempo da operação: O(log(n))
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore que sofrerá a remoção
      int key: chave a ser removida

  - retorno:
      t_node*: ponteiro para a árvore/sub árvore alterada
*/
t_node* treapRemoval(t_node* root, int key){
  if(root != NULL){
    if(key < root->info){
      root->left = treapRemoval(root->left, key);

    } else if (key > root->info){
      root->right = treapRemoval(root->right, key);

    } else { // a chave a ser removida foi encontrada 
      if(root->left == NULL && root->right == NULL){ // caso o nó seja folha ele é simplesmente deletado
        free(root);
        root = NULL;

      } else if(root->left != NULL && root->right == NULL){ // caso possua somente filho esquerdo, o nó é considerado como semifolha,
        t_node *aux = root->left;                           // então é realizado apenas um ajuste nos ponteiros, de modo que seu pai
                                                            // aponta para o filho esquerdo desse nó a ser removido
        free(root);
        root = aux;

      } else { // caso o nó tenha dois filhos, ele será rotacionado sempre para a esquerda para cair em um dos dois casos acima
        root = leftRotate(root);
        root->left = treapRemoval(root->left, key); // a função recursiva é chamada novamente para fazer com que o nó se torne folha ou semifolha
    
      }
    }

  } else { // caso tenha percorrido toda a treap e nenhuma de suas chaves bata com aquela passada por parametro uma mensagem é impressa
    printf("Chave nao localizada\n");
  }
  
  return root; // retorno do ponteiro para a sub árvore remanescente da operação de remoção
}



/* Função para chamar a operação de remoção realizada partindo do nó raiz da árvore
  - parâmetros:
      t_tree* t: ponteiro para a árvore treap, cuja estrutura será alterada na operação
      int info: chave a ser removida

  - retorno:
     sem retorno
*/
void removal(t_tree *t, int key){
  t->root = treapRemoval(t->root, key); // como acontecia na inserção, a remoção também pode mudar várias vezes a raiz da árvore
}



// Abaixo estão as implementações dos diferentes tipos de impressão

/* Função realizar a impressão em largura ou por níveis da treap usando  
  -> complexidade de tempo da operação: O(n)
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore, a partir da qual a impressão se inicia

  - retorno:
      sem retorno
*/
void breadthPrint(t_node* root){
  
  // para essa impressão será usada uma estrutura de fila, cujos elementos são nós da treap
  queue_t* q = queueCreate(); 
  t_node* aux = root; // ponteiro auxiliar que aponta para a raiz da árvore/ sub árvore
  
  while(aux != NULL){ // a impressão ocorre até que não haja mais nós na árvore, ou seja, aux aponte para NULL 
    printf("(%d, %d) ", aux->info, aux->prio);

    // a cada iteração do while, até dois nós de nível inferior ao atual são colocados na fila
    // isso garante a impressão por níveis
    if(aux->left != NULL) enqueue(q, aux->left);
    if(aux->right != NULL) enqueue(q, aux->right);
    aux = dequeue(q); // retirada do nó que está mais a frente na fila para imprimí-lo na iteração seguinte
                      
  }
  printf("\n");

}


/* Função realizar a impressão em pré ordem da treap
  -> complexidade de tempo da operação: O(n)
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore, a partir da qual a impressão se inicia

  - retorno:
      sem retorno
*/
void preOrder(t_node *root){
  if(root != NULL){
    printf("(%d, %d) ", root->info, root->prio);
    preOrder(root->left);
    preOrder(root->right);
  }

}


/* Função realizar a impressão em ordem da treap
  -> complexidade de tempo da operação: O(n)
  - parâmetros:
      t_node* root: ponteiro para a raiz da árvore/sub árvore, a partir da qual a impressão se inicia

  - retorno:
      sem retorno
*/
void inOrder(t_node *root){
  if(root != NULL){
    inOrder(root->left);
    printf("(%d, %d) ", root->info, root->prio);
    inOrder(root->right);
  }
}


/* Função realizar a impressão em pós ordem da treap
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
    printf("(%d, %d) ", root->info, root->prio);
  }
}