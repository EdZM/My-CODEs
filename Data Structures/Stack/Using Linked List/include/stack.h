#ifndef STACK_H
#define STACK_H

typedef char t_item;
typedef struct node NODE;

typedef struct node {
  t_item element;
  NODE* next;


}NODE;

typedef struct stack{
  int size;
  NODE* start;

}STACK;

typedef STACK* STACK_PTR;

// functions
void create_stack(STACK_PTR* ptr);
void push(STACK_PTR ptr, t_item el);
t_item pop(STACK_PTR ptr);
t_item top(STACK_PTR ptr);
int isEmpty(STACK_PTR ptr);
int size(STACK_PTR ptr);
void printStack(STACK_PTR ptr);
void free_stack(STACK_PTR ptr);


#endif