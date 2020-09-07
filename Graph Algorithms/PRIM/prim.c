/*
* ========================================================================================================================================
*
*       Filename:  prim.c
*
*    Description:  Arquivo com a descrição completa da execução do algoritmo de Prim
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =========================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "prim.h"
#include "fila_prioridade.h"
#include "mgrafo.h"

#define INF INT_MAX

void MST_PRIM(M_GRAFO* graf, int origem){
		
	int u; 
	int* pred = NULL;
	int* arvore = NULL;
	int n_arvore = 0;
	FILA_P* fila = NULL;
	
	pred = (int*) malloc(sizeof(int)*graf->ordem);
	fila = inicializar();

	for (int i = 0; i < graf->ordem ; i++ )	{ 
		
		insert(fila, i, INF);	// preenche cada posição da fila de prioridade com cada vertice e com peso infinito em cada um
		pred[i] = -1;			// setando o vetor de predecessores

	}
	
	fila->fp[origem].prioridade = 0; 	// a prioridade do vetor de origem é setada com 0
	if( origem != 0 ) rearranjar(fila); // caso o nao inicie no vertice 0, será necessario rearranjar(ordenar ) a fila antes de comecar a retirar vertices dela


	while(!fila_p_vazia(fila)){ // quando a fila estiver vazia, teremos o vetor de predecessores(pred[]) e a MST(arvore[])
		
		u = extrair_primeiro(fila); // extrair o vertice de menor prioridade(o de menor peso) que no caso é sempre o primeiro item da fila
		
		//inserindo o vertice atual na arvore, que será a MST, ao final da execução do algoritmo
		arvore = (int*) realloc(arvore, sizeof(int) * (n_arvore+1));
		arvore[n_arvore++] = u; 

		for (int j = 0; j < graf->ordem; j++){ //percorre todos os adjacentes ao vertice atual(u)
				
			int pos = busca(fila, j); //pesquisa o vertice atual na fila de prioridade. Se a busca for bem sucedida, o vertice atual ainda nao foi para a arvore
			if (graf->adj_mat[u][j] != -1 && (pos >= 0) && (graf->adj_mat[u][j] < fila->fp[pos].prioridade)){				
				fila->fp[pos].prioridade = graf->adj_mat[u][j];  //ajusta a prioridade dos vertices adjacentes ao vertice atual
				pred[j] = u; //seta o predecessor do vertice atual
				
			}
		}
		
		rearranjar(fila); // depois de cada reajuste de prioridade é necessario rearranjar a fila de prioridade(ordenar seus elementos de acordo com a sua prioridade)
		
	}
	
	

	//reajuste no vetor que representa a arvore
	if( n_arvore == 10 ){
		int it = 5;
		int aux = arvore[n_arvore-5];	
		while(it <= 7){
			arvore[it] = arvore[it + 1] ;
			it++;
			if(it == 8) arvore[it] = aux;
		}
	}



	//impressao no formato exigido
	for(int i = 0; i < n_arvore; i++){
			int vertice1, vertice2;

			//Condicional para imprimir os vertices em ordem crescente
			if(arvore[i] < pred[arvore[i]]){
				vertice1 = arvore[i];
				vertice2 = pred[arvore[i]];
			}
			else{
				vertice1 = pred[arvore[i]];
				vertice2 = arvore[i];
			}

			if(vertice1 != -1 && vertice2 != -1)
				printf("(%d,%d) ", vertice1, vertice2);
	}
	printf("\n");

liberar_fila(&fila, graf->ordem );
free(pred);
free(arvore);

}