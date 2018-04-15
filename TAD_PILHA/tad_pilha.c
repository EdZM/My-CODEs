#include <stdio.h>
#include <stdlib.h>
#include "tad_pilha.h"

PILHA* criar_pilha(){

	PILHA* pilha = NULL;

	pilha = (PILHA*)malloc(sizeof(PILHA));

	if (pilha != NULL){
		pilha->size = 0;
		pilha->inicio = NULL;
		pilha->fim = NULL;


	}


return pilha;
}



void push(PILHA* pilha, int val){

	NODE* aux2 = pilha->inicio; // como é só um ponteiro, nao preciso alocar nada pra isso


	NODE* aux = NULL; // armazenará informações
	aux = (NODE*)malloc(sizeof(NODE));
	aux->element = val;		//preenchendo o nó criado com dados
	aux->proximo = NULL;



	if (pilha != NULL){ // se a pilha nao estiver vazia
		
		if (aux2 == NULL){ // se o inicio da pilha existente estiver vazio
			pilha->inicio = aux;

		}else{

			while (aux2->proximo != NULL){ //paro no nó anterior ao ultimo nó da pilha 
				aux2 = aux2->proximo;

			}	
			aux2->proximo = aux;
			pilha->fim = aux2->proximo;
			
		
		}
		pilha->size++;
	}




}

NODE* pop(PILHA* pilha){ //da pra fazer de dois jeitos : retornando o inteiro do nó retirado ou retornando o nó retirado

	NODE* aux = pilha->inicio; //aponta para algum nó, no caso o inicio da pilha 
	NODE* topo = pilha->fim;


	while (aux->proximo != pilha->fim){ //paro no nó anterior ao ultimo nó da pilha 
		aux = aux->proximo;

	}


	pilha->fim = aux;				// a partir daqui a unica forma de acessar o nó retirado da pilha é via "topo"
	pilha->fim->proximo = NULL;
	pilha->size--;


return topo;
}
