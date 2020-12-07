#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

struct stack{
  int top;
  void **items; // vetor de ponteiros void
  int sizeElem; // tamanho de cada elemento
};

stack_t *create(int sizeElem){
  stack_t* p=(stack_t*)malloc(sizeof(stack_t));
  assert(p != NULL); // veriica se uma condição é true ou false. Se for true ele finaliza o programa com uma msg de erro

  p->items = (void**)malloc(sizeof(void*)*stack_size);
  assert(p->items != NULL);

  p->top = -1; // indica que a pilha esta vazia
  p->sizeElem = sizeElem;

  return p;
}

void destroy(stack_t* p){
  
  while(p->top >= 0){ // desaloca os void* para o caso quando o user chamar essa função quando tiver elementos na pilha
    free(p->items[p->top]);
    p->top--;
  }
  
  if(p->items !=NULL){ // desaloca o void**
    free(p->items);
  }
  
  if(p != NULL){ 
    free(p); //desaloca p
  }
  
  p = NULL;
}

int isEmpty(stack_t *p){
  assert(p != NULL);
  if(p->top == -1)
    return 1;
  else
    return 0;

}

int isFull(stack_t *p){
  assert(p != NULL);
  if (p->top == stack_size -1)
    return 1;
  else
    return 0;
}

int top(stack_t *p, void* x){
  assert(p != NULL);

  if(isEmpty(p) == 1){
    return -1;
  }
  
  memcpy(x, p->items[p->top], p->sizeElem);

  return 1;
}


int push(stack_t* p, void* x){
  assert(p != NULL);

  if(isFull(p) == 1){
    return -1;
  
  }

  p->top++;
  p->items[p->top] = (void*)malloc(p->sizeElem);
  assert(p->items[p->top] != NULL);

  memcpy(p->items[p->top], x, p->sizeElem); //copia o conteudo de x para dentro do ponteiro p->items[p->top]
  return 1;

}

int pop(stack_t *p, void* x){ // retorna o codigo de erro e o elemento que esta no topo da pilha
  assert(p != NULL);

  if(isEmpty(p) == 1){
    return -1;
  }
  
  memcpy(x, p->items[p->top], p->sizeElem);
  free(p->items[p->top]);
  p->top--;
  return 1;
}