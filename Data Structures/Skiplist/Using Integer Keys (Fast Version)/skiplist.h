#ifndef SKIPLIST_H
#define SKIPLIST_H

#define MAXLVL 10
typedef struct node t_node;
typedef struct list skiplist;


struct node{
  int key; // retirar isso após finalização
  char entry[50];       // contem o verbete
  char definition[140]; // contem uma definição para o verbete
  t_node** next;        // aponta para um vetor que contem os ponteiros desse nó nos próximos níveis
  
};

struct list{
  t_node* header;  // é possível que a skiplist seja um vetor dinamico de listas ligadas, onde cada posição seja um ponteiro para uma sublista 
  int levels;     // numero de niveis atuais
  float p;        // probabilidade dos ponteiros de nível i também terem ponteiros de nível i+1
                  // ou seja, é a chance de os valores de um dado nível também estarem num nível logo acima                
  int maxlevel;
};



//OPs:
skiplist* create();
int total_levels(skiplist *s);
//void insertion(skiplist *s, char *ent, char *def);
int insertion(skiplist *s, int key);
t_node* search(skiplist *s, int key);
int removal(skiplist* s, int key);
int alteration(skiplist* s, int key);
void print_list(skiplist*s);


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