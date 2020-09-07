#include <stdio.h>
#include <stdlib.h>
#include "tad_fila.h"




FILA* criar_fila(){

	FILA* fila = NULL;

	fila = (FILA*)malloc(sizeof(FILA));

	if (fila != NULL){
		fila->inicio = NULL;//só aponta pro inicio da FILA  --> OBS: lembre-se que cada -> que uso, estou fazendo uma derreferenciação		
		fila->fim = NULL;
		fila->size = 0;

	}

return fila;
}



void enfileirar(FILA* fila, int el){


	NODE* aux2 = fila->inicio; //aponta pro nó inicial da fila
	NODE* aux = NULL; 
	aux = (NODE*) malloc(sizeof(NODE));
	aux->proximo = NULL;
	aux->elemento = el;


	if (fila != NULL){ // as operações só são permitidas se a fila existir
		if (aux2 == NULL){
			fila->inicio = aux;

		} else {

			while(aux2->proximo != NULL){ //percorre a fila até encontrar a ultima posição
				aux2 = aux2->proximo;

			}
			aux2->proximo = aux; // o elemento seguinte ao apontado por aux2 passa a ser aux
			fila->fim = aux2->proximo; // o ponteiro para o nó final da fila é alterado pra incluir o novo elemento


		}

		fila->size++;

	}

}


void desenfileirar(FILA* fila){

	NODE* aux;

	if (fila != NULL && fila->size > 0){
		
		aux = fila->inicio; //armazenando o nó que será retirado em aux. Isso será necessario na parte da liberação de memoria
		fila->inicio = fila->inicio->proximo;
		free(aux);
		fila->size--;

	}

}


int primeiro(FILA* fila){
	return fila->inicio->elemento;

}

int ultimo(FILA* fila){
	return fila->fim->elemento;


}


void print_fila(FILA* fila){

	NODE* aux = fila->inicio;
	while(aux != NULL){
		printf("%d ", aux->elemento);
		aux = aux->proximo;

	}
	printf("\n");

}


void free_fila(FILA** fila){

	while((*fila)->size > 0 )desenfileirar(*fila);

	free(*fila);
	*fila = NULL;

}