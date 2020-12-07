#ifndef QUEUE_H
#define QUEUE_H

typedef int t_item;

typedef struct node{
	t_item element;
	struct node* next;

} NODE;

typedef struct queue{
  int size;
	NODE* start; // head of the queue
	NODE* end; // tail of the queue

} QUEUE;

//functions
QUEUE* create_queue();
void enqueue(QUEUE* queue, t_item el);
t_item dequeue(QUEUE *queue);
int first(QUEUE* queue);
int last(QUEUE* queue);
int isEmpty(QUEUE *queue);
int size(QUEUE *queue);
void print_queue(QUEUE* queue);
void free_queue(QUEUE** queue);


#endif