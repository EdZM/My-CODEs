#ifndef LIST_H
#define LIST_H

typedef int elem;


typedef struct list t_list;

t_list *create();
void freeList(t_list* l);
int insertion(t_list* l, elem x);
int removal(t_list *l, elem x);
int search(t_list *l, elem x);
void printList(t_list *l);
int printInverseList(t_list *l);


#endif