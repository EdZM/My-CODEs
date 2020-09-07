/*
* ========================================================================================================================================
*
*       Filename:  fila_prioridade.c
*
*    Description:  Arquivo com a implementação das funções do TAD da fila de prioridade
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =========================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "fila_prioridade.h"

#define max_size 100
#define INF INT_MAX 




FILA_P* inicializar(){

	FILA_P* fila = NULL;

	fila = (FILA_P*)malloc(sizeof(FILA_P));

	fila->fila_top = 0;
	
	for (int i = 0; i < max_size; i++)	{
		fila->fp[i].vertice = -1;
		fila->fp[i].prioridade = INF; 
	}

return fila;
}


void insert(FILA_P* fila, int vert, int prior ){
	
	fila->fp[fila->fila_top].vertice = vert;
	fila->fp[fila->fila_top].prioridade = prior;
	fila->fila_top++;
	rearranjar(fila);
	
}

int extrair_primeiro(FILA_P* fila){

	no* aux = NULL;
	aux = (no*)malloc(sizeof(no));

	*aux = fila->fp[0];

	for (int i = 0; i < fila->fila_top-1; i++)	{
		fila->fp[i] = fila->fp[i+1];
	}
	fila->fila_top--;


return aux->vertice;
}


void rearranjar(FILA_P* fila){
	if(fila->fila_top > 1){

		no* aux = NULL;
		aux = (no*)malloc(sizeof(no));

		for (int i = 1; i < fila->fila_top; i++){
			for (int j = 0; j < fila->fila_top - 1; j++){
				if(fila->fp[j].prioridade > fila->fp[j+1].prioridade){
					*aux = fila->fp[j];
					fila->fp[j] = fila->fp[j+1];
					fila->fp[j+1] = *aux; 

				}
			}
		}

		free(aux);
	}

}

int busca(FILA_P* fila, int vert){

	for (int i = 0; i < fila->fila_top; i++){
		if(fila->fp[i].vertice == vert){
			return i;
			break;
		}
	}
	return -1;


}

void imprimir_fila(FILA_P* fila){
	for (int i = 0; i < fila->fila_top; i++)	{
		printf("vertice: %d prioridade: %d\n",fila->fp[i].vertice , fila->fp[i].prioridade  );
	}
	printf("\n");

}


int fila_p_vazia(FILA_P* fila){
	if(fila->fila_top == 0 ) return 1;
	else return 0;

}

void liberar_fila(FILA_P** fila, int tam){

	free(*fila);
	*fila = NULL;

}