/*
* ========================================================================================================================================
*
*       Filename:  main.c
*
*    Description:  Programa que realiza a operação de busca em profundidade(DFS) em um par de vertices de um grafo, gerado a partir de uma
*				   matriz de adjacencia (O TAD_grafo implementado no lab anterior(LAB.1) foi MANTIDO aqui)
*			       OBS.: O algoritmo usado para a DFS foi totalmente baseado no algoritmo contido no livro do Cormen
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
	int ini, fim;
	M_GRAFO* graf = NULL;


	scanf("%d %d", &vert, &arest); //recolhendo o numero de VERTICES e ARESTAS
	graf = cria_mat_graf(vert);


	for (int i = 0; i < arest; i++)	{ //recolhendo cada aresta,formada por um par de vertices adjacentes, e inserindo-a na matriz de adjacencia
		scanf("%d %d", &x, &y);
		inserir_aresta_m(graf, x, y);

	}
	
	while (scanf("%d %d", &ini, &fim) != EOF) { // a cada linha será recolhido um par de vertices de origem e destino, respectivamente.
		dfs(graf, ini, fim);
		printf("\n");
	}

	//desalocando a matriz de adjacencia
	free_mat_graf(&graf);


return 0;	
}