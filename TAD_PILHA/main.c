#include <stdio.h>
#include <stdlib.h>

#include "tad_pilha.h"

int main(int argc, char const *argv[]){

	PILHA* p = NULL; // p irá apontar para a pilha alocada

	p = criar_pilha();
	
	push(p , 123);
	push(p , 5);
	push(p , 3);
	push(p , 4);
	push(p , 5);
	push(p , 6);

	NODE* aux2 = NULL;
	aux2 = (NODE*)malloc(sizeof(NODE));
	aux2->element = 0;		//preenchendo o nó criado com dados
	aux2->proximo = NULL;

	NODE* aux = p->inicio;


	while (aux != NULL){ //impressao antes da retirada de elementos

		printf("%d ", aux->element);

		aux = aux->proximo;

	}
	printf("\n");



	aux2 = pop(p);
	aux2 = pop(p);
	aux2 = pop(p);


	aux = p->inicio;


	while (aux != NULL){// impressao apos a retirada de alguns elementos da pilha

		printf("%d ", aux->element);

		aux = aux->proximo;

	}
	printf("\n");	


	return 0;
}