/*
* ========================================================================================================================================
*
*       Filename:  main.c
*
*    Description:  Programa que encontra o caminho minimo entre dois vertices de um grafo, construido a partir de uma matriz de adjacencia
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =========================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "mgrafo.h"
#include "fila_prioridade.h"
#include "dijkstra.h"

int main (){


	int vert, arest, x, y, peso;
	int destino, origem;
	M_GRAFO* graf = NULL;


	scanf("%d %d", &vert, &arest); //recolhendo o numero de VERTICES e ARESTAS
	graf = cria_mat_graf(vert);

	for (int i = 0; i < arest; i++)	{ //recolhendo cada aresta,formada por um par de vertices adjacentes, e inserindo-a na matriz de adjacencia
		scanf("%d %d %d", &x, &y, &peso);
		inserir_aresta_m(graf, x, y, peso);
	}

	while(scanf("%d %d", &origem, &destino)!= EOF){
		dijkstra(graf, origem, destino );
		printf("\n");
	}

	free_mat_graf(&graf);
	

return 0;	
}
