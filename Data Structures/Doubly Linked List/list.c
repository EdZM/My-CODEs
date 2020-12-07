#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"


typedef struct node t_node;

struct node{
  elem info; 
  t_node* next;
  t_node* prev;

};

struct list{
  t_node* start;
  t_node* end;

};


t_list *create(){
  t_list* p;
  p = (t_list*)malloc(sizeof(t_list));
  assert(p != NULL);
  p->start = NULL;
  p->end = NULL;

  return p;

}

void freeList(t_list *l){
  if (l != NULL){
    t_node* aux = l->start;
    
    while (aux != NULL){
      l->start = l->start->next;
      free(aux);
      aux = l->start;
    }
    
    free(l);

  }
}

// A inserção ocorre de forma a já ordenar os elementos
// OBS.: Nao permite que insira elementos repetidos
// pensar em formas de permitir isso
int insertion(t_list *l, elem x){
  assert(l != NULL);

  // criando o no já no start (resta associá-lo a lista)
  t_node* p = (t_node*)malloc(sizeof(t_node));
  p->info = x;
  p->next = NULL;
  p->prev = NULL;

  // 4 casos para inserção :(há variacoes na manipulação dos ponteiros)
  // 1-> lista vazia
  // 2-> inserir no start
  // 3-> inserir no meio
  // 4-> inserir no end

  t_node* aux = l->start;  
  t_node* prev = NULL; // melhora legibilidade

  while (aux != NULL && x > aux->info){
    prev = aux;
    aux = aux->next;
  }

  // até aqui aux aponta para NULL ou para x já existente na lista

  // caso onde x já existe na lista
  if (aux != NULL && x == aux->info){ // evita elementos repetidos
    free(p);
    return 0; 
  }

  // caso 1 e 2: lista vazia ou start
  if (prev == NULL){
    
    p->next = l->start; // p->next recebe o start atual da lista
    if (l->start != NULL) l->start->prev = p; //if caso 2 else caso 1
    l->start = p; // p passa a ser o novo start da lista
  
  } else { // casos 3 e 4: meio ou end da lista
    
    p->next = prev->next; 
    prev->next = p; // aponta para p    
    if (p->next != NULL) p->next->prev = p; // if caso 3 else caso 4
    else l->end = p;
    p->prev = prev;

  }
  return 1;

}


int removal(t_list *l, elem x){
  assert(l != NULL);

  t_node *p = l->start;
  t_node *prev = NULL;

  while (p != NULL && x > p->info){
    prev = p;
    p = p->next;
  }
  
  // até aqui p aponta para NULL ou para x a ser removido
  if (p == NULL){
    return 0;
  }
  
  // remoção no start
  if (prev == NULL){
    l->start = l->start->next;
    if ( l->start != NULL ) l->start->prev = NULL; 
    else l->end = NULL;    
      
  } else { // remoção no end ou no meio
    if ( p->next == NULL ) { // remove do end da lista
      l->end = p->prev;
      prev->next = NULL;      
      
    } else { //remove do meio da lista
      prev->next = p->next;
      p->next->prev = prev;      
    }
  }
  free(p);
  return 1;

}

int search(t_list* l, elem x){
  assert(l != NULL);

  t_node* aux = l->start;
  while (aux != NULL) {
    if (aux->info == x) {
      return 1; 
    } else {
      aux = aux->next;
    }
  }

  return 0;

}

void printList(t_list *l){
  assert(l != NULL);
  t_node* p = l->start;
  
  while (p != NULL){
    printf("%d ", p->info);
    p = p->next;
  }
  printf("\n");

}


int printInverseList(t_list *l){
  assert(l != NULL);
  t_node* p = l->end;
  
  while (p != NULL){
    printf("%d ", p->info);
    p = p->prev;
  }
  printf("\n");

  
}