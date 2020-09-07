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

#define max_size 10000
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
	rearranjar(fila,0,fila->fila_top - 1);
	
}

no* extrair_primeiro(FILA_P* fila){

	no* aux = NULL;
	aux = (no*)malloc(sizeof(no));

	*aux = fila->fp[0];

	for (int i = 0; i < fila->fila_top-1; i++)	{
		fila->fp[i] = fila->fp[i+1];
	}
	fila->fila_top--;


return aux;
}



void rearranjar(FILA_P* fila, int inicio, int fim){
	//if(fila->fila_top > 1){

		int i = inicio;
		int j = fim;
		int pivo;
		int piv_pos = (i+j)/2;

		pivo = fila->fp[piv_pos].prioridade;
		
		while(j > i){
			while(fila->fp[i].prioridade < pivo) i++;
			while(fila->fp[j].prioridade > pivo) j--;

			if(i <= j){ 

				no* aux = NULL;
				aux = (no*)malloc(sizeof(no));

				*aux = fila->fp[i];
				fila->fp[i] = fila->fp[j];
				fila->fp[j] = *aux;	

				free(aux);
				
				i++;
				j--;

			}

		}

		if(inicio < j) rearranjar(fila, inicio, j);
		if(i < fim) rearranjar(fila, i, fim);
		
	}

	/*


	*/

//}

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

void liberar_fila(FILA_P** fila){

	free(*fila);
	*fila = NULL;

}