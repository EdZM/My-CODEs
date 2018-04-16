#include <stdio.h>
#include <stdlib.h>
#include "tad_arvore_abb.h"


ARVORE* criar_arvore(){

	ARVORE* arv = NULL;

	arv = (ARVORE*)malloc(sizeof(ARVORE));

	if (arv != NULL){
		arv->raiz = NULL;	
	}


return arv;
}



void inserir(ARVORE** arvore, int chave){// deve receber o endereço da raiz para que eu mude a arvore de fato

	NODE** aux = &(*arvore)->raiz; //aux aponta para a raiz da arvore inicialmente
	
	while ( (*aux) != NULL ){ // percorro a arvore até achar a posição ideal para o nó a ser inserido
		if ((*aux)->elemento > chave){
			aux = &(*aux)->esquerda;
		
		} else if ((*aux)->elemento < chave){
			aux = &(*aux)->direita;


		} else if ((*aux)->elemento == chave){
			printf("Chave repetida\n");
			return; // retornando para a main , em caso de chave repetida . O return garante que eu paro por aqui e nao continuo a função

		}

	}

	*aux = (NODE*)malloc(sizeof(NODE)); //o endereço apontado por *aux receberá um novo nó
	(*aux)->esquerda = NULL;
	(*aux)->direita = NULL;
	(*aux)->elemento = chave;

}


void busca(ARVORE* arvore, int chave){

	NODE* aux = arvore->raiz;


	while(aux != NULL ){
		

		if (aux->elemento > chave){
			aux = aux->esquerda;
		
		} else if (aux->elemento < chave){
			aux = aux->direita;


		} else if (aux->elemento == chave){
			printf("Chave encontrada: %d\n", aux->elemento);
			return; // retornando para a main , em caso de chave repetida . O return garante que eu paro por aqui e nao continuo a função

		}


	}

	printf("Chave não encontrada\n");



}






void remover(ARVORE** arvore, int chave){};







void visita(NODE* node){
	printf("chave: %d\n", node->elemento );
	
}


void impressao_em_ordem(NODE* node){

	if (node != NULL){
		impressao_em_ordem(node->esquerda);
		visita(node);
		impressao_em_ordem(node->direita);


	}

}


void impressao_pre_ordem(NODE* node){

	if (node != NULL){
		visita(node);
		impressao_em_ordem(node->esquerda);
		impressao_em_ordem(node->direita);


	}

}

void impressao_pos_ordem(NODE* node){

	if (node != NULL){
		impressao_em_ordem(node->esquerda);
		impressao_em_ordem(node->direita);
		visita(node);

	}

}






void free_tree(ARVORE** arvore){};

