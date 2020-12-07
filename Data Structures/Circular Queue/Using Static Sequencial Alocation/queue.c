#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

struct queue{
  int start; // indice de onde o elemento deve sair(primeiro elemento)
  int end; // indice de onde o elemento deve entrar
  int num_els; // util para manipular a fila circular
  element items[queue_size];

};


queue_t* create(){
  queue_t* p = (queue_t*)malloc(sizeof(queue_t));
  assert(p != NULL);

  p->start = 0;
  p->end = 0;
  p->num_els = 0;

  return p;
}

int isEmpty(queue_t* p){
  assert(p != NULL);
  return ( p->num_els == 0 )? 1: 0;

}

int isFull(queue_t* p){
  assert(p != NULL);
  return ( p->num_els == queue_size ) ? 1: 0;

}

int insertion(queue_t* p, element x){
  assert(p != NULL);

  if(isFull(p) == 1) return -1;

  p->items[p->end] = x; // insere de forma circular ==> mais rápido e tem maior reaproveitamento de espaço
  p->end = (p->end + 1) % queue_size; // faz a curva, caso precise
  p->num_els++;

  return 1;
}


int removal(queue_t* p, element* x){
  assert(p != NULL);

  if(isEmpty(p) == 1) return -1;
  
  *x = p->items[p->start];
  p->start = (p->start + 1) % queue_size; // faz a curva, caso precise
  p->num_els--;

  return 1;
}


void destroy(queue_t* p){
  assert(p == NULL);
  free(p);
  p = NULL;

}
