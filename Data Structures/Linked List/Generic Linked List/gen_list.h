#ifndef GEN_LIST_h
#define GEN_LIST_h

typedef int elem;
typedef struct node t_node;

typedef union { // usa espaço na memória que é referente a váriavel com maior tamanho
                // só posso usar um campo por vez(ex: info atomo = 2; info sublista = ponteiro, a variável "a" é sobrescrita)
                // tem só um dos campos abaixo
  elem atom;
  t_node* sublist;

} t_info;

struct node{
  int type; //especifica se é átomo ou sublista  
  t_info info;
  t_node* next;
};


void freeList(t_node* p);
t_node *atom(elem x);              // recebe x e cria um no armazenando x tipo 0 e ponteiro para NULL
t_node *sublist(t_node* sublist);   // cria um nó do tipo 1 
t_node *concat(t_node* p, t_node* q );  // concatena dois nós de quaisquer tipo
t_info head(t_node* p, int* type); // retorna a cabeca da lista passada por parametro
t_node *rear(t_node* p);             // retorna os elementos seguintes à cabeça
void printList(t_node* p);           // imprime a lista inteira seguindo uma representação de () ou []

#endif