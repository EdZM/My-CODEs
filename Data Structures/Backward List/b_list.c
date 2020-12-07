#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "b_list.h"

// especificação dos elementos que compõem um nó da lista e da struct que representa a lista backward em si
struct node{
  int time; // registro do momento em que foi o nó inserido/removido
  elem key; // chave/valor do nó
  t_node* back; // aponta para um nó qualquer que esteja posicionado antes do nó atual
  t_node* next; // aponta para o próximo nó da lista
  t_node* prev; // aponta para o nó que está imediatamente antes do atual
};

struct list{
  t_node* start;  // aponta para o inicio da lista
  t_node* end;    // aponta para o fim da lista
  int nodes_total;// quantidade total de nós da lista

};


/* Função para criar uma lista backward
  - retorno:
      b_list* : ponteiro para a lista backward recém criada

*/
b_list *create(){
  b_list* p = (b_list*)malloc(sizeof(b_list));

  assert(p != NULL);

  p->end = NULL;
  p->start = NULL;
  p->nodes_total = 0;

  return p;
}



/* Função para liberar a memória alocada para a lista backward
  - parametros:
      b_list* : ponteiro para a lista backward a ser desalocada

*/
void free_list(b_list *b){
  if (b != NULL){
    t_node* aux = b->start;
    
    while (aux != NULL){
      b->start = b->start->next;
      free(aux);
      aux = b->start;
    }
    
    free(b);

  }
}


/* Função para checar se a lista backward encontra-se vazia ou não
  - parâmetros:
      b_list* : ponteiro para a lista backward

  - retorno:
      0 => a lista não está vazia
      1 => a lista está vazia

*/
int is_empty(b_list* b){
  return b->nodes_total == 0? 1: 0;

}


/* Função para inserir nós na lista backward 
  - parâmetros:
      b_list* : ponteiro para a lista backward que receberá um novo nó
      elem: chave a ser inserida
      int: auxilia a definir o ponteiro back do nó a ser inserido, especificando quantas posições do nó atual encontra-se o seu nó back
      int*: endereço da variável discreta que contabiliza o tempo

  - retorno:
      1 => a inserção foi bem sucedida

*/
int insertion(b_list *b, elem x, int j, int* time){

  assert(b != NULL);

  int count = 0;          // auxiliar para contabilizar quantas passos para trás já foram dados na lista
  t_node* aux = b->start; // ponteiro auxiliar que aponta inicialmente para o começo da lista backward
  t_node* prev = NULL;    // ponteiro auxiliar que aponta para o nó imediatamente anterior a um nó atual
  t_node* p = (t_node*)malloc(sizeof(t_node));

  // setando os valores iniciais do nó p recém criado
  p->key = x;
  p->next = NULL;
  p->back = NULL;
  p->prev = NULL;
  p->time = *time;

  while (aux != NULL) {
    prev = aux; // à medida que o ponteiro aux avança, seu ponteiro anterior é armazenado
    aux = aux->next;
  }

  if ( prev == NULL ) { // caso em que a lista está vazia
    b->start = p;
    b->start->prev = NULL; // o anterior ao nó inicial é sempre NULL
    b->end = p;
    
  } else { // caso em que a inserção só precisa ser feita no fim da lista
    
    prev->next = p;
    p->prev = prev;
    
    // setando o ponteiro back do nó p, usando a variável j para retroceder na lista
    aux = p; // aux agora aponta para o nó recém p inserido
    if ( j <= b->nodes_total && j != 0) { // a atribuição do ponteiro back só ocorre se j != 0 e não ultrapassar a quantidade de nós da lista      
      while(count++ < j) aux = aux->prev; // volta j posições na lista 
      p->back = aux;
    
    }
    b->end = p;

  }

  b->nodes_total++;
  (*time)++;
  return 1;
}


/* Função auxiliar para anular os nós que tem como nó back o nó "initial", passado por parâmetro
  - parâmetros:
      t_node*: ponteiro a partir do qual se inicia a busca pelos nós que o tem como nó back

*/
void back_ptr_nullifier(t_node* initial){ 

  t_node* aux = initial->next;

  while(aux != NULL){
    if(aux->back == initial){ // caso o nó atual aux tenha como nó back nó o "initial", aux tem seu ponteiro setado para NULL
      aux->back = NULL;      
    }
    aux = aux->next;
  }
}



/* Função para remover nós da lista backward
  - parâmetros:
      b_list* : ponteiro para a lista backward que sofrerá a remoção
      elem: chave a ser retirada
      int*: endereço da variável discreta que contabiliza o tempo

  - retorno:
      0 => a remoção não foi bem sucedida
      1 => a remoção foi bem sucedida

*/
int removal(b_list *b, elem x, int *time){

  assert(b != NULL);

  t_node *p = b->start;
  t_node *prev = NULL;

  while (p != NULL && x != p->key){ // pára na primeira ocorrência de x
    prev = p;
    p = p->next;
  }

  if ( p == NULL ) { // elemento inexistente na lista
    return 0;
  }

  // ajuste dos ponteiros back antes de a remoção ocorrer de fato
  back_ptr_nullifier(p);

  // operação de remoção
  if (prev == NULL){ // remoção no inicio
    b->start = b->start->next;
    if ( b->start != NULL ) b->start->prev = NULL; 
    else b->end = NULL;
      
  } else { // remoção no fim ou no meio
    if ( p->next == NULL ) { // remove do fim da lista
      b->end = p->prev;
      prev->next = NULL;

    } else { //remove do meio da lista
      prev->next = p->next;
      p->next->prev = prev;

    }
  }
  
  free(p);
  b->nodes_total--;
  (*time)++;
  return 1;
}


/* Função para calcular a posição do nó back de um nó(current) passado por parâmetro
  - parâmetros:
      b_list*: ponteiro para a lista backward que sofrerá a operação
      t_node*: ponteiro para um nó da lista

  - retorno:
      int: valor da posição do nó back do nó passado por parâmetro

*/
int pos_calc(b_list* b, t_node* current){
  assert(b != NULL);

  t_node* aux = b->start;
  int pos = 0;

  while (current->back != aux){ // enquanto o nó atual não for o nó back de current, avançe na lista incrementando pos
    aux = aux->next;
    pos++;
  }

  return pos;

}


/* Função para realizar a impressão dos elementos presentes na lista backward 
  - parâmetros:
      b_list*: ponteiro para a lista backward que sofrerá a operação

*/
void print_list(b_list *b){
  assert(b != NULL);

  if(is_empty(b) == 1) { // caso a lista esteja vazia -1 é impresso
    printf("-1\n");
        
  } else {
    t_node* current = b->start;
    int pos = 0;

    while (current != NULL) {      // a impressão ocorre até que não haja mais nós a serem lidos
      if(current->back != NULL ) { // caso current possua um nó back, a posição do último é calculada e impressa, junto com as demais informações do nó atual
        // impressão do nó com as informações: chave, tempo e posição do nó back na lista
        int pos = pos_calc(b, current);
        printf("[%d,%d,%d] ",current->key, current->time, pos);
       
      } else { 
        // impressão do nó com as informações: chave, tempo (esse nó não tem nó back)
        printf("[%d,%d] ",current->key, current->time);
        
      }
      current = current->next;
    }
    
    printf("\n");
  }  
}