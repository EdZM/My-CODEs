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



void inserir(ARVORE* arvore, int chave){

	NODE* aux = arvore->raiz;
	
	if(arvore->raiz->elemento == -1 ){
			arvore->raiz->elemento = chave;

			printf("asad\n");

	}else {

	
		while ( aux != NULL ){//rever isso
			if (aux->elemento > chave){
				aux = aux->esquerda;
			
			} else if (aux->elemento < chave){
				aux = aux->direita;

			} else if (aux->elemento == chave){
				printf("Chave repetida\n");
				break;

			}


		}

		printf("asad3\n");
		NODE* aux2 = (NODE*)malloc(sizeof(NODE)); 
		aux2->esquerda = NULL;
		aux2->direita = NULL;
		aux2->elemento = chave;

		aux = aux2;



	}	

}



void remover(ARVORE* arvore, int chave){};
void free_tree(ARVORE** arvore){};

