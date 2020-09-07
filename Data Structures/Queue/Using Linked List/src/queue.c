#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

int isEmpty(QUEUE *queue){
  return queue->size <= 0 ? 1: 0;
}

int size(QUEUE *queue){
  return queue->size;
}

int first(QUEUE* queue){
	return queue->start->element;

}

int last(QUEUE* queue){
	return queue->end->element;

}

void create_node(NODE** aux, t_item el){
  (*aux) = (NODE*) malloc(sizeof(NODE));
	(*aux)->next = NULL;
	(*aux)->element = el;

}

QUEUE *create_queue(){

  QUEUE* queue = NULL;

  queue = (QUEUE*)malloc(sizeof(QUEUE));

  if (queue != NULL){
		queue->start = NULL;//só aponta pro inicio da queue  --> OBS: lembre-se que cada -> que uso, estou fazendo uma derreferenciação		
		queue->end = NULL;
		queue->size = 0;

	}

  return queue;
}

void enqueue(QUEUE *queue, t_item el){

  NODE* aux = NULL;
  NODE* aux2 = queue->start; //aponta pro nó inicial da fila

  create_node(&aux, el);

	if (queue != NULL){ // as operações só são permitidas se a fila existir
		if (aux2 == NULL){
			queue->start = aux;
      queue->end = aux;

		} else {
      queue->end->next = aux;
      queue->end = aux;

		}
		
    queue->size++;
	}
}

t_item dequeue(QUEUE *queue){

  NODE* aux = queue->start;
  t_item value;
	
  if (queue->start != NULL && !isEmpty(queue)){
		
    value = queue->start->element;
		queue->start = queue->start->next;
		free(aux);
		queue->size--;
    return value;

	}

}





void print_queue(QUEUE* queue){

  NODE *aux = queue->start;

  printf("QUEUE: %d -> ", first(queue));
  
  aux = aux->next;
  while(aux != NULL){
		printf("%d -> ", aux->element);
		aux = aux->next;

	}


	printf("NULL \n");
}

void free_queue(QUEUE** queue){

	while((*queue)->size > 0 )dequeue(*queue);

	free(*queue);
	*queue = NULL;



}