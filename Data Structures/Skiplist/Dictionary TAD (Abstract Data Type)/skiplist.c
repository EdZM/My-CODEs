#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <limits.h>
#include "skiplist.h"

#define MAXLVL 15
#define tails 0
#define heads 1

struct node{
  int value;            // (retirar isso após finalização)
  int level;            // nível do nó
  char entry[50];       // contem o verbete
  char definition[140]; // contem uma definição para o verbete
  t_node* next;         // ponteiro para o próximo nó de mesmo nível
  t_node* down;         // ponteiro para o nó de nível abaixo
};

struct list{
  //t_node** headers;  
  t_node* upleft;       // ponteiro para o nó superior esquerdo
  int levels;           // número atual de níveis
  int maxLevel;         // número máximo possível de níveis
                  
                  
};

int flip_a_coin(){
  int coin = rand();
  return (coin % 2 == 0)? heads:tails;
}

int random_level(){
  int level = 0;
  int coin = flip_a_coin();
  
  // float r = (float)rand()/RAND_MAX; 
  // float prob = 0.5; 
  // while (r < prob && level < MAXLVL) { 
  //   level++; 
  //   r = (float)rand()/RAND_MAX; 
  // } 
  // return level; 

  // while (rand() < (int)RAND_MAX/2 && level < MAXLVL)
  //     level++;
  // return level;

  while ((coin == heads) && level < MAXLVL){ 
    level++;
    coin = flip_a_coin();
  }

  return level;
}

int total_levels(skiplist* s){
  return s->levels;

}


t_node* create_node(int value, int level, t_node* next, t_node* down){

  t_node* p = (t_node*)malloc(sizeof(t_node));
  p->next = next;
  p->down = down;
  p->level = level;
  p->value = value;

  return p;
}

skiplist* create(){
  skiplist* s = (skiplist*)malloc(sizeof(skiplist));

  // s->headers = (t_node**)malloc(sizeof(t_node*) * (MAXLVL+1));
  // for (int i = 0; i < MAXLVL+1; i++) {
  //   s->headers[i] = create_node(-1);
  //   if(i > 0) s->headers[i]->down = s->headers[i-1];
  // }

  //s->upleft = s->headers[0];
  s->levels = 0; // o nível 0 contem TODOS os verbetes inseridos até o momento
  s->upleft = create_node(-1, s->levels, NULL, NULL);
  s->maxLevel = MAXLVL;

  return s;
}


//void insertion(skiplist* s, char* ent, char* def);
void insertion(skiplist* s, int value){

  t_node* aux = s->upleft;      // aux aponta para o nó superior esquerdo da skip list
  t_node* updates[s->maxLevel]; // salva todos os nós imediatamente anteriores aquele que deseja-se inserir em todos os niveis
  t_node* new_node;             // aponta para onovo nó criado
  t_node* new_upleft;           // aponta para o novo nó superior esquerdo em caso de a inserção gerar novos níveis

  //int new_lvl = 2;
  int new_lvl = random_level(); // geração do número de níveis que o nó a ser inserido terá
  
  //printf("check1\n");
  while(aux->level != 0){
    while(aux->next != NULL && aux->next->value < value){
      aux = aux->next;
    }
    updates[aux->level] = aux;
    aux = aux->down;
  }
  
  //printf("check2\n");

  while(aux->next != NULL && aux->next->value < value){
    aux = aux->next;
  }
  updates[aux->level] = aux;

  
  int curr_level = 0;
  while(curr_level <= s->levels){
    new_node = create_node(value, curr_level, NULL, NULL);
    if(curr_level == 0){
      new_node->next = updates[curr_level]->next;
      new_node->down = NULL;
    
    } else {
      new_node->next = updates[curr_level]->next;
      new_node->down = updates[curr_level-1]->next;

    }
    updates[curr_level]->next = new_node;
    curr_level++;
    
  }

  for(int i = s->levels + 1; i <= new_lvl; i++ ){
    new_node = create_node(value, i, NULL, updates[i-1]->next);
    new_upleft = create_node(-1, i, new_node, s->upleft);
    s->upleft = new_upleft;
    updates[i] = new_upleft;

  }
  
  if(s->levels < new_lvl) s->levels = new_lvl;

}

int search(skiplist *s, int value){
  t_node* aux = s->upleft;

  //printf("level inicial: %d\n", s->upleft->level);
  
  // busca nos níveis mais altos da skip list
  while(aux->level != 0){
    while(aux->next != NULL && aux->next->value < value){
      aux = aux->next;
    }
    if(aux->next != NULL && aux->next->value == value){
      printf("encontrado no nível: %d\n", aux->next->level);
      return 1;
    }
  
    aux = aux->down;
  }
  
  // busca no nível 0 da skip list
  while(aux->next != NULL && aux->next->value < value){
    aux = aux->next;
  }
  
  if(aux->next->value != value) {
    printf("nao encontrado\n");
    return 0;

  } else {
    printf("encontrado no nível: %d\n", aux->next->level);
    return 1;
  }

}

void print_list(skiplist* s){

  t_node *aux;
  t_node *aux0;
  
  aux0 = s->upleft;
  //printf("%d\n", total_levels(s));

  while(aux0 != NULL){
    printf("list: ");    
    
    aux = aux0;
    while (aux != NULL) {
      printf(" %d ->", aux->value);
      aux = aux->next;
    }
    printf("\n");
    aux0 = aux0->down;

  }

}

/*
  t_node* aux = s->upleft;
  t_node* update[s->maxLevel]; // salva todos os nós imediatamente anteriores aquele que deseja-se inserir em todos os niveis
  
  // for (int i = 0; i < MAXLVL+1; i++) {
  //   update[i] = NULL;

  // }

  // for (int i = s->levels; i >= 0; i--) {    
  //   while (aux->next != NULL && aux->next->value < value) {
  //     aux = aux->next;
  //   }

  //   update[i] = aux; // updates é preenchido de cima para baixo
  //   if(i > 0) aux = aux->down;
  // }

  // // atualização da skip list quando o nível gerado aleatoriamente é superior ao nível atual
  // if(new_lvl > s->levels){
  //   for (int i = s->levels + 1; i <= new_lvl; i++) {
  //     update[i] = s->headers[i]; // está mesmo recebendo o nó e não apenas a referencia pra ele? 
      
  //   }
  //   s->levels = new_lvl;
  //   s->upleft = s->headers[new_lvl]; // ao chegar no último nó ele passa a ser o novo upleft
  
  // }

  // t_node *new_nodes[new_lvl+1];
  // for (int i = 0; i < new_lvl+1; i++) {
  //   new_nodes[i] = create_node(value);
  // }

  // for (int i = 0; i <= new_lvl; i++) {
  //   new_nodes[i]->next = update[i]->next;

  //   if(i >= 1) {
  //     new_nodes[i]->down = update[i-1]->next;

  //   }
  //   update[i]->next = new_nodes[i];

  // }

  
  
  //aux = s->upleft;
  //updates[s->maxLevel];
  //int new_lvl = random_level();



*/