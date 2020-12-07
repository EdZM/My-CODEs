#ifndef QUEUE_H
#define QUEUE_H

#include "treap.h"

#define queue_size 100

typedef struct queue queue_t; // a declaração struct ficará contida no arquivo .c, escondida do usuario para maior encapsulamento

// Funções principais da fila
queue_t *queueCreate();
int queueIsEmpty(queue_t *p);
int queueIsFull(queue_t *p);
int enqueue(queue_t *p, t_node *x);
t_node* dequeue(queue_t *p);
void queueDestroy(queue_t *p);

#endif