#ifndef LIST_H
#define LIST_H

typedef int elem;
typedef struct list t_list;

// Operações
t_list* create();
void freeList(t_list* l);
int isInList(t_list *l, elem x);
int listSize(t_list *l);
void printList(t_list *l);
int insertion(t_list *l, elem x);
int removal(t_list *l, elem x);
void invertList(t_list *l);

#endif