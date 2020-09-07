#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"


void create_stack(STACK_PTR* ptr){
  if((*ptr) == NULL){
    (*ptr) = (STACK*)malloc(sizeof(STACK));
    (*ptr)->start = NULL;
    (*ptr)->size = 0;
  
  }
}

void create_node(NODE** node, t_item el){
  if((*node) == NULL){
    (*node) = (NODE *)malloc(sizeof(NODE));
    (*node)->next = NULL;
    (*node)->element = el;
  }
}

int isEmpty(STACK_PTR ptr){
  return ( ptr->size > 0 )? 0 : 1;

}

t_item top(STACK_PTR ptr){
  return ptr->start->element;
}

int size(STACK_PTR ptr){
  return ptr->size;
}

void push(STACK_PTR ptr, t_item el){

  if ((ptr)->start == NULL){
    create_node(&(ptr)->start, el);
    
  } else {
    NODE* aux = NULL;
    
    create_node(&aux, el);
    aux->next = ptr->start;    
    (ptr)->start = aux;

  }

  ptr->size++;

}

t_item pop(STACK_PTR ptr){
  NODE* aux = ptr->start;
  t_item value;

  value = aux->element;
  ptr->start = ptr->start->next;
  free(aux);

  ptr->size--;
  return value;

}

void printStack(STACK_PTR ptr){
  NODE* aux = ptr->start; 
  
  if(!isEmpty(ptr)){
    printf("STACK: top ==> %c <- ",top(ptr));
    aux = aux->next;

    while(aux != NULL){
      printf("%c <- ", aux->element);
      aux = aux->next;
    }
    printf("\n");
  
  } else{
    printf("Stack Empty\n");


  }
}

void free_stack(STACK_PTR ptr){

  if(!isEmpty(ptr)){
    while(ptr->start != NULL){
      pop(ptr);
    }
  }
  free(ptr);
  ptr = NULL;


}
