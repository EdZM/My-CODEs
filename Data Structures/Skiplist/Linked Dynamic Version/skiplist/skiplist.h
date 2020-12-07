#ifndef SKIPLIST_H
#define SKIPLIST_H

typedef struct node t_node;
typedef struct list skiplist;

//OPs:
skiplist* create();
int total_levels(skiplist *s);
//void insertion(skiplist *s, char *ent, char *def);
void print_list(skiplist *s);
void insertion(skiplist *s, int value);
int search(skiplist* s, int value);

int flip_a_coin();
int random_level();

/*
free_list
insertion
removal 
search
change
print_list

etc.
*/




#endif