#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct stack{
  int top;
  element items[stack_size];
};

stack_t *create(){
  stack_t* p=(stack_t*)malloc(sizeof(stack_t));
  assert(p != NULL); // veriica se uma condição é true ou false. Se for true ele finaliza o programa com uma msg de erro

  p->top = -1; // indica que a pilha esta vazia

  return p;
}

void destroy(stack_t* p){
  if(p != NULL){
    free(p);
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

int top(stack_t *p, element* x){
  assert(p != NULL);
  if(isEmpty(p) == 1){
    return -1;
  }

  *x = p->items[p->top];
  return 1;
}

int push(stack_t* p, element x){
  assert(p != NULL);

  if(isFull(p) == 1){
    return -1;
  
  }

  p->top++;
  p->items[p->top] = x;
  return 1;

}

int pop(stack_t *p, element* x){ // retorna o codigo de erro e o elemento que esta no topo da pilha
  assert(p != NULL);
  if(isEmpty(p) == 1){
    return -1;
  }

  *x = p->items[p->top];
  p->top--;
  return 1;
}