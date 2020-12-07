#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct node t_node;

struct node {
  elem info;
  t_node* next;

};

struct list{
  t_node* sentinel; // não aponta para o início, mas sim para um nó qualquer
                   // aponta para o "último" nó da lista
                   // permite a varredura única de um elemento da lista
  elem total;
};


t_list *create(){
  t_list* l = (t_list*)malloc(sizeof(t_list));
  assert(l != NULL);

  l->sentinel = NULL;
  l->total = 0; //existem 0 elementos , consequentemente, 0 posições
  return l;

}

void freeList(t_list *l){
  assert(l != NULL);
  // to do

}

int listSize(t_list *l){
  assert(l != NULL);
  return l->total;

}



int insertion(t_list *l, elem x){
  assert(l != NULL);

  
  t_node* p = (t_node*)malloc(sizeof(t_node));
  p->info = x;
  
  if(l->sentinel == NULL){ // lista está vazia
    l->sentinel = p;
    l->sentinel->next = p;
    
  } else { // lista com pelo menos um elemento. Aqui os elementos serão colocados ao final dela

    p->next = l->sentinel->next;
    l->sentinel->next = p;
    l->sentinel = p;
    
    
  }


  l->total++;
  return 1;  
}

int removal(t_list *l, elem x){

  t_node* aux = l->sentinel;
  t_node* prev = NULL;

  do {
    prev = aux;
    aux = aux->next;
  
  } while(aux != l->sentinel && aux->info != x);


  if ( aux->info == x ) {
    prev->next = aux->next;
    
    if (x == l->sentinel->info){
      l->sentinel = prev;

    }
    l->total--;
    free(aux);
    return 1;
  
  } else {
    return 0;

  }
}
int search(t_list *l, elem x){
  t_node* aux = l->sentinel;

  do {
    aux = aux->next;
  
  } while(aux != l->sentinel && aux->info != x);

  if ( aux->info == x ) {
    return 1; 
  
  } else {
    return 0;
  }

}



void printList(t_list *l){

  assert(l != NULL);

  t_node* p = l->sentinel->next;
  

  do {
    printf("%d ", p->info);
    p = p->next;
  
  } while (p != l->sentinel->next);
    

  
  printf("\n");
  

}