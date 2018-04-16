#include <stdio.h>
#include <stdlib.h>
#include "tad_arvore_abb.h"


ARVORE* criar_arvore(){

	ARVORE* arv = NULL;

	arv = (ARVORE*)malloc(sizeof(ARVORE));


	if (arv != NULL){
		arv->raiz = NULL;	
		arv->raiz = (NODE*) malloc(sizeof(NODE));
		arv->raiz->elemento = -1;
		arv->raiz->esquerda = NULL;
		arv->raiz->direita = NULL;
		
	}


return arv;
}



void inserir(ARVORE** arvore, int chave){// deve receber o endereço da raiz para que eu mude a arvore de fato

	NODE** aux = &(*arvore)->raiz; //aux aponta para a raiz da arvore
	
	if((*arvore)->raiz->elemento == -1 ){ //se isso for verdadeiro quer dizer que a chave a ser inserida é a chave da raiz
		(*arvore)->raiz->elemento = chave;

	} else {
	
		while ( (*aux) != NULL ){
			if ((*aux)->elemento > chave){
				aux = &(*aux)->esquerda;
			
			} else if ((*aux)->elemento < chave){
				aux = &(*aux)->direita;
				counter++;


			} else if ((*aux)->elemento == chave){
				printf("Chave repetida\n");
				break;

			}

		}

		*aux = (NODE*)malloc(sizeof(NODE)); //o endereço apontado por *aux receberá um novo nó
		(*aux)->esquerda = NULL;
		(*aux)->direita = NULL;
		(*aux)->elemento = chave;

	}	

}



void remover(ARVORE* arvore, int chave){};
void free_tree(ARVORE** arvore){};

