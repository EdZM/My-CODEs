#ifndef TAD_FILA_H
#define TAD_FILA_H


typedef struct node{
	int elemento;
	struct node* proximo;


}NODE;


typedef struct fila{
	int size;
	NODE* inicio;
	NODE* fim;


}FILA;

//functions
FILA* criar_fila();
void enfileirar(FILA* fila, int el);
void desenfileirar(FILA* fila);
int primeiro(FILA* fila);
int ultimo(FILA* fila);
void free_fila(FILA** fila);


#endif