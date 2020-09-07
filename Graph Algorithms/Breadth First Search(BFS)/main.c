/*
* =====================================================================================================================
*
*       Filename:  main.c
*
*    Description:  Programa que realiza a operação de busca em largura(BFS) em um par de vertices de um grafo, gerado a partir de uma
*				   matriz de adjacencia (O TAD_grafo implementado no lab anterior foi alterado aqui)	
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =====================================================================================================================
*/

#include <stdlib.h>
#include <stdio.h>

#include "grafo.h"
#include "busca.h"

int main(void) {
	int vert, arest, x, y, ini, fim, i;
	GRAFO *grafo;

	scanf("%d %d", &vert, &arest); //recolhendo o numero de vertices e arestas
	grafo = criar_grafo(vert);

	for (i = 0; i < arest; i++) {	//recolhendo TODAS as arestas, para que assim o a matriz de adjacencia que compoe o grafo possa ser criada
		scanf("%d %d", &x, &y);
		inserir_aresta(grafo, x, y);
	}

	while (scanf("%d %d", &ini, &fim) != EOF) { //para cada linha é recolhido um par de valores que correspondem, respectivamente ao vertice de origem e o de destino
		bfs(grafo, ini, fim); 					// A busca em largura é feita sobre cada par fornecido e assim o menor caminho entre esse par é impresso
		printf("\n");
	}

	liberar_matriz(&grafo);
	return 0;
}
