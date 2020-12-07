#ifndef QUEUE_H
#define QUEUE_H

#define queue_size 10

typedef int element;
typedef struct queue queue_t; // a declaração struct fica contida no arquivo .c, escondida do usuario(+ encapsulamento)


// Operações
queue_t *create();
int isEmpty(queue_t *p);
int isFull(queue_t *p);
int insertion(queue_t *p, element x);
int removal(queue_t *p, element *x);
void destroy(queue_t *p);

#endif