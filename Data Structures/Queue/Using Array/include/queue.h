#ifndef QUEUE_H
#define QUEUE_H

typedef int t_item;

typedef struct queue{
  int size;
  int read; // start index of the queue
  int write; // (end + 1) index of the queue
  t_item* elements;

}QUEUE;

// functions
void create_queue(QUEUE** queue);
void enqueue(QUEUE *queue, t_item el);
t_item dequeue(QUEUE *queue);
int isFull(QUEUE* queue);
int isEmpty(QUEUE* queue);
void printQueue(QUEUE *queue);
void freeQueue(QUEUE **queue);

#endif