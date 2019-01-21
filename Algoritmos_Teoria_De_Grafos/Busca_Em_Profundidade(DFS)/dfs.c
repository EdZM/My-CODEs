/*
* ========================================================================================================================================
*
*       Filename:  dfs.c
*
*    Description:  Arquivo que contem a implementação das funções ultilizadas pelo arquivo dfs.h
*				   
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =========================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>

#include "dfs.h"

/*função que visita recursivamente cada vertice que é adjacente a um vertice fornecido por parametro
	parametros:
		M_GRAFO* g: grafo a ser processado/percorrido
		char* cor:  Vetor de caracteres que guarda a cor de cada vertice
		int* pred:  Vetor de predecessores
		int* d:     Vetor que marca o instante em que um nó se tornou cinza
		int* f:		vetor que marca o instante em que um nó se tornou preto
		int i:		vertice fornecido por parametros
		int *time:  
*/
void visitar(M_GRAFO* g, char* cor, int* pred, int* d, int* f, int *time, int i){
	
	cor[i] = 'g'; 		// g == cinza, indicando um caminho visitado, mas não totalmente processado
	(*time)++;
	d[i] = *time;

	for (int j = 0; j < g->ordem; j++)	{
		if (cor[j] == 'w' && g->adj_mat[i][j] != -1){
			pred[j] = i;
			visitar(g, cor, pred, d, f, time, j);
		}

	}
	
	cor[i] = 'b'; 		// marcando a posição atual com a cor PRETA(BLACK), o que indica que está processado
	(*time)++;
	f[i] = *time;	



}


/*função que processa o grafo fornecido via parametro e gera um caminho entre um par de vertices (origem/destino)
	parametros:
		M_GRAFO* g:  Grafo analisado/percorrido
		int origem:  vertice de origem 
		int destino: vertice de destino

*/
void dfs(M_GRAFO* g, int origem, int destino){
	

	char* cor = NULL;		//vetor cujas posições marcam a cor de cada nó num dado instante
	int* pred = NULL;		//vetor cujas posições marcam o nó predecessores
	int* d = NULL; 			//vetor que marca o instante em que um nó se tornou cinza
	int* f = NULL; 			//vetor que marca o instante em que um nó se tornou preto
	int* caminho = NULL;	//vetor que marca o menor caminho percorrido do vertice de origem até o de destino
	int antecessor;			//armazena o antecessor a um determinado nó
	int c = 0;				//determina o quanto o vetor de caminhos cresce
	int time = 0;



	cor = (char*)malloc( g->ordem * sizeof(char) );
	pred = (int*)malloc( g->ordem * sizeof(int) );
	d = (int*)malloc( g->ordem * sizeof(int) );
	f = (int*)malloc( g->ordem * sizeof(int) );	

	// w == branco(não visitado), g == cinza(visitado), b == preto(processado)
	//todos os vertices são marcados com 'w' , com a cor BRANCA
	for (int i = 0; i < g->ordem; i++)	{
		cor[i] = 'w'; 
	}

	for (int i = 0; i < g->ordem; i++)	{
		pred[i] = -1; 
	}

	for (int i = 0; i < g->ordem; i++)	{
		d[i] = -1; 
	}

	for (int i = 0; i < g->ordem; i++)	{
		f[i] = -1; 
	}


	for (int i = origem; i < g->ordem; i++)	{
		for (int j = 0; j < g->ordem; j++)	{
			if (g->adj_mat[i][j] != -1 && cor[i] == 'w')
				visitar(g, cor, pred, d, f, &time, i);
		}
	}


	//construindo o caminho percorrido
	caminho = (int *) realloc (caminho, sizeof(int) * (c+1));
	antecessor = destino;
	caminho[c++] = antecessor;
	
	while (antecessor != origem) {
		
		antecessor = pred[caminho[c-1]];

		caminho = (int *) realloc (caminho, sizeof(int) * (c+1)); //o vetor caminho cresce a medida que um antecessor valido vai sendo encontrado
		caminho[c] = antecessor;
		c++;

	}
	int existe = 1;
	for (int i = c-1; i >= 0 ; i--) if(i > 0 && caminho[i] == -1) existe = 0;


	//imprimindo o menor caminho 
	
	for (int i = c-1; i >= 0 ; i--){
		if (existe == 1)
		 	printf("%d ", caminho[i]);
	}
	



	free(cor);
	free(d);
	free(f);
	free(pred);
	free(caminho);

}
