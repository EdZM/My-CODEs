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

	NODE** node = &(*arvore)->raiz; //node aponta para a raiz da arvore inicialmente
	
	while ( (*node) != NULL ){ // percorro a arvore até achar a posição ideal para o nó a ser inserido
		if ((*node)->elemento > chave){
			node = &(*node)->esquerda;
		
		} else if ((*node)->elemento < chave){
			node = &(*node)->direita;


		} else if ((*node)->elemento == chave){
			printf("Chave repetida\n");
			return; // retornando para a main , em caso de chave repetida . O return garante que eu paro por aqui e nao continuo a função

		}

	}

	*node = (NODE*)malloc(sizeof(NODE)); //o endereço apontado por *node receberá um novo nó
	(*node)->esquerda = NULL;
	(*node)->direita = NULL;
	(*node)->elemento = chave;

}


int busca(ARVORE* arvore, int chave){

	NODE* node = arvore->raiz;

	while(node != NULL ){
		
		if (node->elemento > chave){
			node = node->esquerda;
		
		} else if (node->elemento < chave){
			node = node->direita;

		} else if (node->elemento == chave){		
			return 1; // retornando para a main , em caso de chave repetida . O return garante que eu paro por aqui e nao continuo a função

		}


	}

	return -1;
}






void remover(ARVORE** arvore, int chave){

	
	NODE** rem = &(*arvore)->raiz ; // OBS.: dessa forma se eu der free estarei liberando a regiao certa da memoria
 	NODE** aux; 
 	NODE** pai; 


	//BUSCAR PELA CHAVE ANTES DE TENTAR A REMOÇÃO.    FAÇA ISSO NA MAIN
	
		
	while((*rem) != NULL){
		if ((*rem)->elemento > chave){
			pai = rem; 				// com isso garanto que o node2 vai parar no nó pai de node
			rem = &(*rem)->esquerda; 	// node deve para exatamente no nó que desejo retirar

		
		} else if ((*rem)->elemento < chave){
			pai = rem;
			rem = &(*rem)->direita;

		} else {

			printf("nó que quero remover:%d\n", (*rem)->elemento);
				printf("nó:%d\n", (*pai)->elemento);

			if((*rem)->esquerda == NULL){
				//aux = rem;
				//*rem = (*rem)->direita;		//melhorar isso
				//free(*aux);

				
			}else if((*rem)->direita == NULL ){
				rem = aux;
				*pai = (*rem)->esquerda;	//melhorar isso
				free(*aux);

			}else {

				aux = &(*rem)->esquerda;
				while((*aux)->direita != NULL){
					aux = &(*aux)->direita;

				}	
				
				printf("nó que quero remover:%d\n", (*rem)->elemento);
				printf("maior nó a esquerda:%d\n", (*aux)->elemento);


				//RESTO DA REMOÇÃO: TO DO

				break;
			}

		}

	}


}










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

