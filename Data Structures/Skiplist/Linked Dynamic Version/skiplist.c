#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "skiplist.h"


#define tails 0
#define heads 1
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define FLIP() (rand() % 2 == 0)? heads: tails

double randInRange(double min, double max){
  return min + (double) (rand() / (double) ((unsigned)RAND_MAX + 1) * (max - min + 1));
}

int flip_a_coin(){
  int coin = rand();
  return (coin % 2 == 0)? heads:tails;
}

int random_level(){  
  int level = 0;
  //int coin = FLIP();
  //int coin = flip_a_coin();

  
  // float r = (float)rand()/RAND_MAX; 
  // float prob = 0.5; 
  // while (r < prob && level <= MAXLVL) { 
  //   level++; 
  //   r = (float)rand()/RAND_MAX; 
  // } 
  // return level; 

  // while (rand() < (int)RAND_MAX/2 && level < MAXLVL)
  //     level++;
  // return level;

  // while ((FLIP() == 1)){ 
  //   level++;
  //   //coin = FLIP();
  // }

  double r = randInRange(0, 1);

  while(r < 0.5){
    level++;
    r = randInRange(0, 1);
  }
  //printf("level: %d\n", level);
  

  return MIN(level, MAXLVL);
  //return level;
}

int empty_list(skiplist *s){
  return (s->upleft->next == NULL)? 1: 0;
}

int total_levels(skiplist* s){
  return s->levels;

}

int numberOfNodes(skiplist *s){
  return s->nodes_total;

}

t_node* create_node(char* entry, char* definition, int level, t_node* next, t_node* down){

  t_node* p = (t_node*)malloc(sizeof(t_node));
  assert(p != NULL);
  p->next = next;
  p->down = down;
  p->level = level;
  
  strcpy(p->entry, entry);
  if(definition != NULL) strcpy(p->definition, definition);

  return p;
}

skiplist* create(){
  skiplist* s = (skiplist*)malloc(sizeof(skiplist));
  
  assert(s != NULL);

  s->levels = 0; // o nível 0 contem TODOS os verbetes inseridos até o momento
  s->nodes_total = 0;
  //s->upleft = create_node("@\0", NULL, s->levels, NULL, NULL);

  for (int i = 0; i < MAXLVL; i++) {
    s->left_nodes[i] = create_node("@\0", NULL, i, NULL, NULL);
    s->nodes_total++;
    if(i > 0) s->left_nodes[i]->down = s->left_nodes[i-1];
  }
  
  s->upleft = s->left_nodes[0];
  s->maxLevel = MAXLVL;

  return s;
}

t_node* search(skiplist *s, char* entry){
  t_node* aux = s->upleft;
  
  if(empty_list(s) == 1) return NULL;

  //busca em todos os níveis da skip list partindo do mais alto
  while(aux->level >= 0){
    while(aux->next != NULL && strcmp(aux->next->entry, entry) < 0){
      aux = aux->next;
    }

    if(aux->next != NULL && strcmp(aux->next->entry, entry) == 0){
      return aux->next; // retorna a primeira ocorrencia do nó(pode ser nos níveis superiores ou no mais baixo)
    
    } else if(aux->level == 0){
      return NULL;
    }
      
    aux = aux->down;
  }

  // // busca no nível 0 da skip list
  // while (aux->next != NULL && strcmp(aux->next->entry, entry) < 0){
  //   aux = aux->next;
  // }

  // // até aqui o aux aponta para um nó imediatamente anterior ao pesquisado
  // if (aux->next != NULL && strcmp(aux->next->entry, entry) == 0) {
  //   return aux->next;
    
  // } else {
  //   return NULL;
  
  // }


  // if(aux->next != NULL && strcmp(aux->next->entry, entry) != 0) {
  //   return NULL;
  // } else if(strcmp(aux->next->entry, entry) == 0){
  //   return aux->next;
  // }

}

int insertion(skiplist* s, char* entry, char* definition){

  // if(search(s, entry) != NULL){
  //   return 0;
  // }

  t_node* aux = s->upleft;      // aux aponta para o nó superior esquerdo da skip list
  t_node* updates[s->maxLevel]; // salva todos os nós imediatamente anteriores aquele que deseja-se inserir em todos os niveis
  t_node* new_node;             // aponta para onovo nó criado
  t_node* new_upleft;           // aponta para o novo nó superior esquerdo em caso de a inserção gerar novos níveis

  //int new_lvl = 1;
  int new_lvl = random_level(); // geração do número de níveis que o nó a ser inserido terá
  
  while(aux->level != 0){
    while(aux->next != NULL && strcmp(aux->next->entry, entry) < 0){
      aux = aux->next;
    }
    if(aux->next != NULL && strcmp(aux->next->entry, entry) == 0) return 0;  
    
    updates[aux->level] = aux;
    aux = aux->down;
  }

  while(aux->next != NULL && strcmp(aux->next->entry, entry) < 0){
    aux = aux->next;
  }
  
  // checagem para analisar se o verbete já existe na skiplist
  if(aux->next != NULL && strcmp(aux->next->entry, entry) == 0){
    //printf("%s ja existe\n", aux->next->entry);
    
    return 0;
  }

  updates[aux->level] = aux;

  int curr_level = 0;
  while(curr_level <= s->levels){
    new_node = create_node(entry, definition, curr_level, NULL, NULL);
    s->nodes_total++;
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
    new_node = create_node(entry, definition, i, NULL, updates[i - 1]->next);
    s->nodes_total++;
    //new_upleft = create_node("@\0", NULL, i, new_node, s->upleft); 
    //s->upleft = new_upleft;
    //updates[i] = new_upleft;
    
    //s->left_nodes[i]->down = s->upleft;
    s->left_nodes[i]->next = new_node;
    s->upleft = s->left_nodes[i];
    updates[i] = s->left_nodes[i];
  }
  
  if(s->levels < new_lvl) s->levels = new_lvl;
  
  return 1;

}


int removal(skiplist*s, char* entry){
  
  // if(search(s, entry) == NULL){
  //   return 0;
  // }

  t_node* aux = s->upleft;
  t_node* updates[s->maxLevel];
  t_node* rem_node = NULL;

  while(aux->level != 0){
    while(aux->next != NULL && strcmp(aux->next->entry, entry) < 0){
      aux = aux->next;
    }
    updates[aux->level] = aux;
    aux = aux->down;
  }

  while(aux->next != NULL && strcmp(aux->next->entry, entry) < 0){
    aux = aux->next;
  }


  if(aux->next != NULL && strcmp(aux->next->entry, entry) != 0) {
    //printf("palavra inexistente\n");
    return 0;
  }

  //printf("palavra: %s\n", aux->entry);
  //printf("palavra a ser removida: %s\n", aux->next->entry);

  updates[aux->level] = aux;

  int curr_level = 0;
  while(curr_level <= s->levels){
    if(updates[curr_level]->next != NULL && strcmp(updates[curr_level]->next->entry, entry) == 0){
      rem_node = updates[curr_level]->next;
      updates[curr_level]->next = rem_node->next;
      free(rem_node);
    }
    curr_level++;
  }

  while (s->upleft->next == NULL) {
    rem_node = s->upleft;
    s->upleft = s->upleft->down;
    s->levels--;
    free(rem_node);
  }
  
  return 1;
}


int alteration(skiplist *s, char *entry, char *new_definition){

  t_node* aux = search(s, entry);

  if(aux != NULL){
    if(new_definition != NULL) {
      // alteração do nó em todos os níveis 
      while (aux != NULL) {
        strcpy(aux->definition, new_definition);
        //printf("o nível %d tem a nova definição de %s: %s\n", aux->level, aux->entry, aux->definition);
        aux = aux->down;
      }
      
    }
    return 1;
  
  } else {
    return 0;
  
  }
}

int print_list(skiplist* s, char* ch){

  int ch_occurences = 0;
  t_node *aux = s->upleft;
  t_node *aux0;

  aux0 = s->upleft;

  while (aux->down != NULL) {
    aux = aux->down;
  }

  aux = aux->next;
  
  while (aux != NULL ) {
    //printf("%s\n", aux->entry);
    if(aux->entry[0] == ch[0]){
      printf("%s %s\n", aux->entry, aux->definition);
      ch_occurences++;
    }
    //if(aux->next != NULL && aux->next->entry[0] != ch) return 1;  
    aux = aux->next;

  }
  
  if(ch_occurences == 0) {
    return 0;
    
  } else {  
    return 1;
  }

  

  // while(aux0 != NULL){
  //   printf("list: ");    
    
  //   aux = aux0;
  //   while (aux != NULL) {
  //     printf(" %s ->", aux->entry);
  //     aux = aux->next;
  //   }
  //   printf("\n");
  //   aux0 = aux0->down;

  // }

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