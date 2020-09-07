/*
* ========================================================================================================================================
*
*       Filename:  fila_prioridade.h
*
*    Description:  Arquivo com a descrição das funções do TAD da fila de prioridade
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =========================================================================================================================================
*/

#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#define max_size 10000

typedef struct no{
	int vertice;
	int prioridade; //a prioridade pode ser vista como o custo 

}no;

typedef struct fila_p{

	int fila_top;
	struct no fp[max_size];

}FILA_P;



FILA_P* inicializar();
void insert(FILA_P* fila, int vert, int prior );
no* extrair_primeiro(FILA_P* fila);
int busca(FILA_P* fila, int vert);
void rearranjar(FILA_P* fila, int inicio, int fim);

int fila_p_vazia(FILA_P* fila);
void imprimir_fila(FILA_P* fila);
void liberar_fila(FILA_P** fila);



#endif


