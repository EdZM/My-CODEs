#ifndef SKIPLIST_H
#define SKIPLIST_H

#define MAXLVL 32

typedef struct node t_node;
typedef struct list skiplist;

struct node{
  int level;            // nível do nó
  char entry[50];       // contem o verbete
  char definition[140]; // contem uma definição para o verbete
  t_node* next;         // ponteiro para o próximo nó de mesmo nível
  t_node* down;         // ponteiro para o nó de nível abaixo
};

struct list{
  //t_node** headers;  
  t_node* left_nodes[MAXLVL];       // ponteiro para o nó superior esquerdo
  t_node* upleft;
  int levels;           // número atual de níveis
  int maxLevel;         // número máximo possível de níveis
  int nodes_total;                
                  
};


//OPs:
skiplist* create();
int empty_list(skiplist* s);
int total_levels(skiplist *s);
int print_list(skiplist *s, char* ch);
int insertion(skiplist *s, char *entry, char *definition);
int removal(skiplist*s, char* entry);
int alteration(skiplist *s, char *entry, char *new_definition);
t_node* search(skiplist *s, char* entry);

int numberOfNodes(skiplist* s);

/*
free_list

*/




#endif