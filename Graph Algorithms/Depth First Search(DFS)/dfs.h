/*
* ========================================================================================================================================
*
*       Filename:  dfs.h
*
*    Description:  Arquivo que contem as funções ultilizadas na operação de busca em profundidade(DFS)
*				   
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =========================================================================================================================================
*/

#ifndef DFS_H
#define DFS_H

#include "mgrafo.h"

void visitar(M_GRAFO* g, char* cor, int* pred, int* d, int* f, int* time, int i);
void dfs(M_GRAFO* g, int origem, int destino);

#endif