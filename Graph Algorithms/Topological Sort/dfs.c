/*
* ========================================================================================================================================
*
*       Filename:  dfs.c
*
*    Description:  Arquivo que contem a implementação das funções ultilizadas pelo arquivo dfs.h, alteradas para icluir a ordenação
*				   topológica.
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =========================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>

#include "dfs.h"
#include "tad_fila.h"


/*função que visita recursivamente cada vertice que é adjacente a um vertice fornecido por parametro
	parametros:
		M_GRAFO* g: grafo a ser processado/percorrido
		char* cor:  Vetor de caracteres que guarda a cor de cada vertice
		int* pred:  Vetor de predecessores
		int* d:     Vetor que marca o instante em que um vértice se tornou cinza
		int* f:		vetor que marca o instante em que um vértice se tornou preto
		int i:		vertice fornecido por parametros
		FILA* fila: fila que armazena os vertices durante a ordenação topológica	
		int *time:  
*/
void visitar(M_GRAFO* g, char* cor, int* pred, int* d, int* f, int *time, int i, FILA* fila){
	
	cor[i] = 'g'; 		// g == cinza, indicando um caminho visitado, mas não totalmente processado
	(*time)++;
	d[i] = *time;

	for (int j = 0; j < g->ordem; j++)	{
		if (cor[j] == 'w' && g->adj_mat[i][j] != -1){
			pred[j] = i;
			visitar(g, cor, pred, d, f, time, j, fila);
		}

	}
	
	cor[i] = 'b'; 		// marcando a posição atual com a cor PRETA(BLACK), o que indica que está processado
	(*time)++;
	f[i] = (*time);	
	
	enfileirar(fila, i); // após um determinado vertice ser totalmente processado ele é armazenado na fila


}


/*função que processa o grafo fornecido via parametro e gera a ordenação topológica armazenada em um vetor 
	parametros:
		M_GRAFO* g:  Grafo analisado/percorrido
	retorno:
		int* : 	ponteiro para um vetor que contem a ordenação topológica

*/
int* dfs(M_GRAFO* g){

	char* cor = NULL;		//vetor cujas posições marcam a cor de cada vértice num dado instante
	int* pred = NULL;		//vetor cujas posições marcam os predecessores de cada vertice
	int* d = NULL; 			//vetor que marca o instante em que um vértice se tornou cinza
	int* f = NULL; 			//vetor que marca o instante em que um vértice se tornou preto
	int* caminho = NULL;	//vetor que armazenará a ordenação topológica
	int c = 0;				//determina o quanto o vetor "caminho" cresce
	int time = 0;			// variável util para a busca em profundidade

	FILA* fila = criar_fila();

	cor = (char*)malloc( g->ordem * sizeof(char) );
	pred = (int*)malloc( g->ordem * sizeof(int) );
	d = (int*)malloc( g->ordem * sizeof(int) );
	f = (int*)malloc( g->ordem * sizeof(int) );	

	// w == branco(não visitado), g == cinza(visitado), b == preto(processado)
	//todos os vertices são marcados com 'w' , com a cor BRANCA
	//inicializando os vetores que serão usados durante a ordenação
	for (int i = 0; i < g->ordem; i++)	{
		cor[i] = 'w'; 
		pred[i] = -1;
		d[i] = -1; 
		f[i] = -1; 
	}


	for (int i = 0; i < g->ordem; i++)	{
		for (int j = 0; j < g->ordem; j++)	{
			if (g->adj_mat[i][j] != -1 && cor[i] == 'w')
				visitar(g, cor, pred, d, f, &time, i, fila);
				
		}
	}

	//salvando o conteudo da fila no vetor "caminho" 
	while(fila->inicio != NULL){
		caminho = (int *) realloc (caminho, sizeof(int) * (c+1));
		caminho[c++] = primeiro(fila);
		desenfileirar(fila);
	}

	//liberando tudo o que foi alocado, exceto o vetor que contem a ordenação topológica
	free(cor);
	free(d);
	free(f);
	free(pred);
	free_fila(&fila);

return caminho;
}
