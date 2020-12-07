#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include "skiplist.h"

#define tails 0
#define heads 1
#define MIN(a, b) (((a) < (b)) ? (a) : (b))


double randInRange(double min, double max){
  return min + (double) (rand() / (double) ((unsigned)RAND_MAX + 1) * (max - min + 1));
}


int flip_a_coin(){
  int coin = (int)rand()%100;
  return (coin % 2 == 0)? heads:tails;
}


int random_level(){
  int level = 0;
 
  double r = randInRange(0, 1);

  while(r < 0.5){
    level++;
    r = randInRange(0, 1);
  }
  
  return MIN(level, MAXLVL);

}

int total_levels(skiplist* s){
  return s->levels;

}


t_node* create_node(int value, int levels){

  t_node* p = (t_node*)malloc(sizeof(t_node));
  p->next = (t_node**)malloc(sizeof(t_node*)*(levels+1));   
  p->key = value;
  
  // setando todos os nós próximos dos níveis para NULL
  for (int i = 0; i < levels+1; i++) {
      p->next[i] = NULL;
  }

  return p;
}

skiplist* create(){
  skiplist* s = (skiplist*)malloc(sizeof(skiplist));

  s->levels = 0; // o nível 0 contem TODOS os verbetes inseridos até o momento
  s->header = NULL;
  s->header = create_node(-1, MAXLVL); // o nó inicial está em todos os níveis possíveis
  s->maxlevel = MAXLVL;
  
  return s;
}


//void insertion(skiplist* s, char* ent, char* def);
int insertion(skiplist* s, int key){

  t_node* aux = s->header; // aux será usado para percorrer a skip list
  //t_node* update[MAXLVL+1];         // armazena o percurso através dos níveis até o nível mais baixo, na posição onde o nó deverá ser inserido
                          // isso é útil para atualizar a skip list e fazer ajustes necessários entre os nós após a inserção
  
  t_node* update[s->maxlevel+1]; 
  // update = create_node(-1, MAXLVL);

  // inicialização de update 
  for (int i = 0; i < MAXLVL+1; i++) {
    update[i] = create_node(-1, MAXLVL);
  }

  // busca pela posição adequada do novo nó, iniciando pelo nível mais alto
  for (int i = s->levels; i >= 0; i--) { 
    while (aux->next[i] != NULL && aux->next[i]->key < key) {
      aux = aux->next[i];
    }

    //printf("aux: %d i:%d\n", aux->key, i);
    update[i] = aux;
  }
  //printf("value: %d\n", aux->key);
  

  aux = aux->next[0]; // aux aponta para o próximo nó do nível mais baixo

  if(aux == NULL || aux->key != key){
    int new_level = random_level(); // geração aleatória da quantidade de níveis que o novo nó deverá ter
                                    // sendo que é possível que esse seu nível seja superior a quantidade atual
    if(new_level > s->levels){
      for (int i = s->levels + 1; i < new_level + 1; i++){
        update[i] = s->header;
      }
        
      // Update the list current level
      s->levels = new_level;
    }

    t_node* new_node = create_node(key, new_level);
    
    for (int i = 0; i <= new_level; i++) {
      new_node->next[i] = update[i]->next[i];
      update[i]->next[i] = new_node;
    }

    // desalocação de update: To do
    // for (int i = 0; i < MAXLVL; i++) {
    //   for (int j = 0; j < MAXLVL+1; j++ ) {
    //     free(update[i]->next[j]);
    //   }
    //   free(update[i]);
    // }
    return 1;
  
  } else if(aux->key == key){
    return 0;


  }
}

t_node* search(skiplist *s, int key){
  t_node* aux = s->header;

  for (int i = s->levels; i >= 0; i--) {
    while(aux->next[i] != NULL && aux->next[i]->key < key){
      aux = aux->next[i];
    }
    if(aux->next[i] != NULL && aux->next[i]->key == key){
      return aux->next[i];

    } else if(i == 0){
      return NULL;
    }


  }

}

int removal(skiplist* s, int key){

  t_node *aux = s->header;
  t_node *update[s->maxlevel + 1];

  // inicialização de update 
  for (int i = 0; i < MAXLVL+1; i++) {
    update[i] = create_node(-1, MAXLVL);
  }

  // busca pela posição adequada do novo nó, iniciando pelo nível mais alto
  for (int i = s->levels; i >= 0; i--) { 
    while (aux->next[i] != NULL && aux->next[i]->key < key) {
      aux = aux->next[i];
    }

    //printf("aux: %d i:%d\n", aux->key, i);
    update[i] = aux;
  }
  //printf("value: %d\n", aux->key);
  

  aux = aux->next[0]; 

  if(aux != NULL && aux->key == key){

    for (int i = 0; i <= s->levels; i++) {
      if(update[i]->next[i] != aux) break;
      update[i]->next[i] = aux->next[i];

    }

    // se após a remoção alguma lista dos níveis superiores ficar vazia ela será desconsiderada
    while (s->levels > 0 && s->header->next[s->levels] == NULL) {
      s->levels--;
    }

    return 1;

  } else if(aux->key != key){
    return 0;

  }


}

void print_list(skiplist* s){

  t_node* aux;
  int i = s->levels;

  while(i >= 0){
    printf("list: ");

    aux = s->header;
    while (aux != NULL) {
      printf(" %d ->", aux->key);
      aux = aux->next[i];
    }
    printf("\n");
    i--;

  }
}