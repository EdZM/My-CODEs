#ifndef STACK_H
#define STACK_H

#define stack_size 100
typedef int element;

typedef struct stack stack_t;

// operations

stack_t* create();
void destroy(stack_t *p);
int isFull(stack_t *p);
int isEmpty(stack_t *p);
int push(stack_t* p, element x);
int pop(stack_t *p, element* x);
int top(stack_t *p, element *x);

#endif