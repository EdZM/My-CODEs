#ifndef TAD_PILHA_H
#define TAD_PILHA_H

typedef struct node{
	int element;
	struct node* proximo;

}NODE;


typedef struct pilha{
	int size;
	NODE* inicio;	
	NODE* fim;


}PILHA;

//FUNCTIONS

PILHA* criar_pilha();
void push(PILHA* pilha, int val );
NODE* pop(PILHA* );
int vazia(PILHA*);
void free_pilha(PILHA**);


#endif