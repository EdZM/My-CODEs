#ifndef TAD_FILA_H
#define TAD_FILA_H

typedef struct no{ //estrutura de um unico nó
	int elemento;
	struct no* proximo;

} NO;

typedef struct fila{ //estrutura da fila
	NO* inicio;
	NO* fim;
	int tamanho;

} FILA;

//funções

FILA* criar_fila();
void enfileirar(FILA* fila, int valor);	//insere um elemento no fim da fila
void desenfileirar(FILA* fila);			//retira o ultimo elemento da fila
int primeiro(FILA* fila); 				//retorna o elemento que está a frente de todos os outros
int ultimo(FILA* fila); 				//retorna o ultimo elemento da fila
int vazia(FILA* fila);					//retorna 1 se a fila estiver vazia e 0 se não estiver
void liberar_fila(FILA** fila);			//desaloca a fila


#endif