#ifndef B_LIST
#define B_LIST

typedef int elem;
typedef struct node t_node;
typedef struct list b_list;

b_list* create();
int insertion(b_list *b, elem x, int j, int* time);
int removal(b_list *b, elem x, int *time);
void free_list(b_list* b);
void print_list(b_list* b);

#endif