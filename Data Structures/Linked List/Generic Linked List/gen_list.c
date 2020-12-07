#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gen_list.h"

void freeList(t_node* p){
  t_node* aux;

  while (p != NULL) {
    if ( p->type == 1 ) { // p aponta para uma sublist
      freeList(p->info.sublist);
    }
    aux = p;
    p = p->next;
    free(aux);
  }

}

t_node *atom(elem x){
  t_node* p = (t_node*)malloc(sizeof(t_node));
  p->type = 0;
  p->next = NULL;
  p->info.atom = x;
  return p;
}

t_node *sublist(t_node* sublist){
  t_node* p = (t_node*)malloc(sizeof(t_node));
  p->type = 1;
  p->next = NULL;
  p->info.sublist = sublist;
  return p;

}

t_node *concat(t_node* p, t_node* q ){
  assert(p != NULL);
  p->next = q;
  return p;
}

t_info head(t_node* p, int* type){
  assert(p != NULL);
  *type = p->type;
  return p->info;

}

t_node *rear(t_node* p){
  assert(p != NULL);
  return p->next;
}

void recPrint(t_node* p){ //recursiva
  if ( p == NULL ) {
    return; 
  }

  printf("( ");
  while (p != NULL) {
    if ( p->type == 0 ) {
      printf("%d", p->info.atom);
      
    } else {
      recPrint(p->info.sublist);
    
    }
    
    if (p->next != NULL){
      printf(", ");
    }
    p = p->next;
    
  }
  printf(" )");
  
}

void printList(t_node* p){
  recPrint(p);
  printf("\n");
  
}