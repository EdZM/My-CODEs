#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

struct queue{
  int start;                 // indice de onde o elemento deve sair(primeiro elemento)
  int end;                   // indice de onde o elemento deve entrar
  int num_els;               // util para manipular a fila circular
  t_node* nodes[queue_size]; // vetor que armazena nós da árvore treap

};



/* Função para criar fila propriamente dita
  - parâmetros:
      sem parâmetros

  - retorno:
      queue_t*: ponteiro para a fila recém criada
*/
queue_t* queueCreate(){
  queue_t* p = (queue_t*)malloc(sizeof(queue_t));
  assert(p != NULL);

  p->start = 0;
  p->end = 0;
  p->num_els = 0;

  return p;
}


/* Função para checar se a fila está vazia com base na quantidade de elementos presentes nela
  - parâmetros:
      queue_t* p: ponteiro para a fila que sofrerá a operação

  - retorno:
      int:
        0 --> a fila não está vazia
        1 --> a fila está vazia
*/
int queueIsEmpty(queue_t* p){
  assert(p != NULL);
  return ( p->num_els == 0 )? 1: 0;

}


/* Função para checar se a fila está cheia com base na quantidade máxima possível de elementos que a fila pode ter
  - parâmetros:
      queue_t* p: ponteiro para a fila que sofrerá a operação

  - retorno:
      int:
        0 --> a fila não está cheia
        1 --> a fila está cheia
*/
int queueIsFull(queue_t* p){
  assert(p != NULL);
  return ( p->num_els == queue_size ) ? 1: 0;

}


/* Função para inserir elementos na fila
  - parâmetros:
      queue_t* p: ponteiro para a fila que sofrerá a operação
      t_node* x: ponteiro para o nó da treap que será inserido na fila

  - retorno:
      int:
        -1 --> erro na operação
        1 --> a inserção ocorreu com sucesso
*/
int enqueue(queue_t* p, t_node *x){
  assert(p != NULL);

  if(queueIsFull(p) == 1) return -1;

  p->nodes[p->end] = x; // insere de forma circular ==> mais rápido e tem maior reaproveitamento de espaço
  p->end = (p->end + 1) % queue_size; // faz a curva, caso precise
  p->num_els++;

  return 1;
}


/* Função para remover elementos na fila
  - parâmetros:
      queue_t* p: ponteiro para a fila que sofrerá a operação

  - retorno:
      t_node*: ponteiro para o nó recém retirado da fila
*/
t_node* dequeue(queue_t* p){
  assert(p != NULL);
  if(queueIsEmpty(p) == 1) return NULL;
  
  t_node* x = p->nodes[p->start];
  p->start = (p->start + 1) % queue_size; // faz a curva, caso precise
  p->num_els--;

  return x;
}



/* Função para desalocar a fila
  - parâmetros:
      queue_t* p: ponteiro para a fila que sofrerá a operação

  - retorno:
      sem retorno
*/
void queueDestroy(queue_t* p){
  assert(p == NULL);
  free(p);
  p = NULL;

}
