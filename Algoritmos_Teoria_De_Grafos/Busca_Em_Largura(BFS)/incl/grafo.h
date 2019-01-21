/*
* =====================================================================================================================
*
*       Filename:  grafo.h
*
*    Description:  Arquivo que contem a descrição das funções e elementos do TAD_grafo
*				   
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =====================================================================================================================
*/

#ifndef GRAFO_H
#define GRAFO_H

#include "grafo.h"

typedef struct grafo GRAFO;

struct grafo {
	int n;
	int **matriz;
};

GRAFO *criar_grafo(int);
void inserir_aresta(GRAFO *, int, int);
void liberar_matriz(GRAFO **);

#endif
