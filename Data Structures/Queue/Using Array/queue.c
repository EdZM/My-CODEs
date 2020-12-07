#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define N 10 //number of elements in the array


int isFull(QUEUE* queue){
  return (queue->size == N)? 1: 0;
}

int isEmpty(QUEUE* queue){
  //return (queue->read == queue->write) ? 1 : 0; 
   return (queue->size <=0)? 1: 0;
}

void create_queue(QUEUE** queue){

  (*queue) = (QUEUE*)malloc(sizeof(QUEUE));

  if((*queue) != NULL){
    (*queue)->elements = (t_item*)malloc(sizeof(t_item) * N);
    (*queue)->size = 0;
    (*queue)->read = 0;
    (*queue)->write = 0;
  }

}


void enqueue(QUEUE* queue, t_item el){
  if(queue != NULL){
    if(!isFull(queue)){
      queue->elements[queue->write++] = el;
      queue->size++;

    } else {
      printf("Queue overflow !\n");
    }
  }
    
}

t_item dequeue(QUEUE *queue){
  if(queue != NULL){
    if (!isEmpty(queue)){
      t_item value = queue->elements[queue->read];
      queue->elements[queue->read] = 0;
      queue->read++;
      queue->size--;
      return value;


    } else {
      printf("Queue is empty!\n");
      return -1;
    
    }
  } 
}

void printQueue(QUEUE* queue){
  printf("QUEUE: ");
  for (int i = queue->read; i < queue->write; i++){
    printf("%d -> ", queue->elements[i]);
  }
  
  printf("\n");

}

void freeQueue(QUEUE** queue){
  if((*queue)!=NULL){
    free((*queue)->elements);
    free((*queue));
    (*queue) = NULL;
  }
}

/*

enqueue operation using a circular array implementation

void enqueue(QUEUE* queue, t_item el){
  if(queue != NULL){
    if(!isFull(queue)){
      queue->elements[queue->write++] = el;
      if(queue->write >= N && queue->read != 0){
        queue->write = 0;
      }
      queue->size++;

    } else {
      printf("Queue overflow !\n");
    }
  }
    
}







*/