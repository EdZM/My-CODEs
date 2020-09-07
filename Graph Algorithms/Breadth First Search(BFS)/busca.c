/*
* =====================================================================================================================
*
*       Filename:  busca.c
*
*    Description:  Arquivo que contem a implementação da unica função do arquivo busca.h
*				   
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =====================================================================================================================
*/

#include <stdlib.h>
#include <stdio.h>

#include "grafo.h"
#include "fila.h"

//função que de fato executa a busca em largura(BFS)
void bfs(GRAFO *g, int origem, int destino) { 
	FILA *fila;
	char *cor = NULL;
	int i, atual, antecessor, c = 0, existeCaminho = 1;
	int *predecessor = NULL, *caminho = NULL;
	
	fila = criar_fila();

	cor = (char *) calloc (g->n, sizeof(char));
	for (i = 0; i < g->n; i++) cor[i] = 'w'; 			// todos os nodes sao pintados de branco
	predecessor = (int *) calloc (g->n, sizeof(int));
	for (i = 0; i < g->n; i++) predecessor[i] = -1; 	//vetor de predecessores


	cor[origem] = 'g'; 				// o node de partida eh visitado
	enfileirar(fila, origem);
	
	do {
	
		atual = frente(fila); 									// obter o node do inicio da fila
		for (i = 0; i < g->n; i++) { 							// para cada node adjacente a link...
			if (g->matriz[atual][i] != -1 && cor[i] == 'w') { 	// se o node adjacente nao foi visitado
				cor[i] = 'g'; 									// ele eh processado
				predecessor[i] = atual; 						// seu antecessor eh marcado
				enfileirar(fila, i); 							// o node adjacente é posto na fila
			}
		}

		desenfileirar(fila);
		cor[atual] = 'b';	// o node foi pintado de preto, o que indica que ele está processado
	
	} while (!vazia(fila));	

	
	// construindo o menor caminho, que sera impresso ao final da execução
	caminho = (int *) realloc (caminho, sizeof(int) * (c+1));
	antecessor = destino;
	caminho[c++] = antecessor;
	
	while (antecessor != origem) { 
		antecessor = predecessor[caminho[c-1]];
		if (antecessor == -1) {
			existeCaminho = 0;
			break;
		}

		caminho = (int *) realloc (caminho, sizeof(int) * (c+1));
		caminho[c] = antecessor;
		c++;
	}

	// imprimindo o menor caminho
	// a impressao deve ser feita em ordem inversa
	for (i = c -1 ; i >= 0 && existeCaminho; i--) printf("%d ", caminho[i]);
	
	liberar_fila(&fila);
	free(cor);
	free(predecessor);
	free(caminho);
}
