/*
* ========================================================================================================================================
*
*       Filename:  main.c
*
*    Description:  Programa que constroi uma Arvore Geradora Mínima(MST) de um grafo, partindo de uma matriz de adjacencia.
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
#include "prim.h"

int main (){

	int vert;
	int arest;
	int x, y, weight;
	M_GRAFO* graf = NULL;
	
	scanf("%d %d", &vert , &arest); //recolhendo numero de vertices e arestas
	graf = cria_mat_graf(vert); 	// criando o grafo com base nos numeros fornecidos acima

	for (int i = 0; i < arest; i++)	{ //preenchendo a matriz de adjacencia com as arestas e os pesos  desejados
		scanf("%d %d %d", &x, &y , &weight);
		inserir_aresta_m(graf, x, y, weight);
	}

	MST_PRIM(graf, 0); //Executa o algoritmo de Prim no grafo

	free_mat_graf(&graf);
	
return 0;	
}