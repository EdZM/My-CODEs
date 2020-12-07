#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct node t_node;

struct node{
  elem info;
  t_node *next;
};

struct list{
  t_node *start, *end;
  int size;
};

t_list *create(){
  t_list* l;

  l = (t_list*)malloc(sizeof(t_list));

  assert(l != NULL);

  l->start = NULL;
  l->end = NULL;
  l->size = 0;

  return l;
}


void freeList(t_list *l){
  if(l != NULL){
    t_node* p = l->start;
    while(p != NULL){
      l->start = p->next; // muda a referencia para o no inicial e o antigo no inicial é desalocado
      free(p);
      p = l->start;

    }
    free(l);
  }
}

int listSize(t_list *l){
  assert(l != NULL);
  return l->size;
}

void printList(t_list *l){
  assert(l != NULL);
  
  t_node* p = l->start;
  while (p != NULL){
    printf(" %d ->",  p->info);  
    p = p->next;
  }
  printf(" <NULL>\n");
}


int isInList(t_list *l, elem x){
  assert(l != NULL);
  t_node* p = l->start;

  while (p!=NULL){
    if(p->info == x) return 1;
    p = p->next;
  }
  
  return 0;

}


int insertion(t_list *l, elem x){
  assert(l != NULL);
  if(isInList(l,x) == 1) return 0; // garante que a lista tem so numeros distintos
  
  t_node* p = (t_node*)malloc(sizeof(t_node));
  
  if(p == NULL) return 0;
  
  p->info = x;
  p->next = NULL;

  if(l->start == NULL){ // lista está vazia
    l->start = p;
    
  } else { // lista com pelo menos um elemento. Aqui os elementos serão colocados ao final dela
    l->end->next = p;
     
  }
  
  l->end = p;
  l->size++;
  return 1;

}

int removal(t_list *l, elem x){
  assert(l != NULL);
  t_node *p = l->start;
  t_node *anterior = NULL;

  while(p != NULL) {
    if(p->info == x){ // 3 casos de remoção: start, meio e end
      
      // caso 1: remover do start
      if(p == l->start) {// ou if(anterior == NULL)
        l->start = l->start->next; // incrementa o start da lista
        free(p);
    
      } else if(p == l->end){ // caso 2: remover do end da lista
        l->end = anterior;
        l->end->next = NULL;
        free(p);

      } else { // caso 3: remover do meio da lista
        anterior->next = p->next;
        free(p);
      
      }
      l->size--;
      return 1;

    } else {
      anterior = p;
      p = p->next;
    
    }
  }

  return 0; // caso 4: ninguem foi removido pq o numero nao foi encontrado na lista

}



void invertList(t_list *l){
  assert(l != NULL);
  t_node *current = NULL;
  t_node *prev = NULL;
  t_node *next = NULL;
  
  current = l->start;
  while (current != NULL){
    next = current->next;
    current->next = prev;

    prev = current;
    current = next;
  }
  l->start = prev;

}