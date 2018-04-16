/*
Nome : Eduardo Zaboto Mirolli  
NºUSP: 9778501

Algoritmos e Estruturas de Dados I- Trabalho 3 - Arvore Vermelho e Preto

---->Programa que realiza operações em uma arvore vermelho e preto
		operações:
				-1)Inserir: Insercao de elementos na arvore 
				-2)Sucessor: Encontrar o sucessor de uma chave escolhida 
				-3)Predecessor: Encontrar o antecessor de uma chave escolhida 
				-4)Maximo: Encontrar a chave da arvore de maior valor 
				-5)Minimo: Encontrar a chave da arvore de menor valor 
				-6)Pre-ordem: Impressao em pre-ordem das chaves existentes a arvore
				-7)Em-ordem: Impressao em ordem das chaves existentes a arvore
				-8)Pos-ordem: Impressao em pos ordem das chaves existentes a arvore
*/

#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"

int main(){

	t_rbtree raiz;
	int it, op;
	int chave;

	scanf("%d",&it);

	inicializar_arvore(&raiz);
	

	while(it > 0){
		
		scanf("%d",&op);

		if(op == 1){
			scanf(" %d",&chave);
			inserir(&raiz, chave);

		}
		
		if(op == 2){
			scanf(" %d",&chave);
			t_chave proximo;	

			proximo = sucessor(raiz , chave);
			if (proximo != -1)printf("%d\n", proximo); 
			else printf("erro\n");

		}
		if(op == 3){
			scanf(" %d",&chave);
			t_chave antecessor ;

			antecessor = predecessor(raiz, chave);

			if ( antecessor != -1 ) printf("%d\n",antecessor );
			else printf("erro\n");

		}
		if(op == 4){
			t_chave max;
			
			max = maximo(raiz);
			if ( raiz != NULL ) printf("%d\n", max);
			else printf("erro\n");

		}

		if(op == 5){
			t_chave min;
			min = minimo(raiz);
			if (raiz != NULL) printf("%d\n", min);
			else printf("erro\n");

		}
		
		if(op == 6){
			pre_ordem(raiz);
			printf("\n");
		}
		
		if(op == 7){
			em_ordem(raiz);
			printf("\n");
		}

		if(op == 8){
			pos_ordem(raiz);
			printf("\n");
		}

		it--;	

	}
	

libera_arvore(&raiz);
	
return 0;
}
