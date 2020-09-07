/*
* ========================================================================================================================================
*
*       Filename:  main.c
*
*    Description:  Programa que realiza a operação de ordenação topológica em um grafo , criado a partir de uma matriz de adjacencia
*			       Nesse código também foi usada a busca em profundidade(DFS).
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =========================================================================================================================================
*/



#include <stdio.h>
#include <stdlib.h>

#include "mgrafo.h"
#include "dfs.h"


int main(int argc, char* argv[]){

	int vert, arest, x, y;
	int* ord_topologica = NULL;

	M_GRAFO* graf = NULL;

	//recolhendo o numero de VERTICES e ARESTAS
	scanf("%d %d", &vert, &arest); 
	graf = cria_mat_graf(vert);


	//recolhendo cada aresta,formada por um par de vertices adjacentes, e inserindo-a na matriz de adjacencia
	for (int i = 0; i < arest; i++)	{ 
		scanf("%d %d", &x, &y);
		inserir_aresta_m(graf, x, y);

	}
	
	ord_topologica = dfs(graf); 

	//impressao da ordenação topológica
	for (int i = graf->ordem - 1 ; i >= 0 ; i--){
		 printf("%d ", ord_topologica[i]);
	}
	
	printf("\n");
		

	//desalocando a matriz de adjacencia e o ponteiro que aponta para o vetor que contem a ordenação
	free_mat_graf(&graf);
	free(ord_topologica);

return 0;	
}