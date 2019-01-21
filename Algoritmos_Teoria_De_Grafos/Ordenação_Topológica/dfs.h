/*
* ========================================================================================================================================
*
*       Filename:  dfs.h
*
*    Description:  Arquivo que contem as funções ultilizadas na operação de busca em profundidade(DFS), modificadas para incluir a 
*				   ordenação topológica
*
*         Nome:  Eduardo Zaboto Mirolli 
*         Nº USP:  9778501
*
* =========================================================================================================================================
*/

#ifndef DFS_H
#define DFS_H

#include "mgrafo.h"
#include "tad_fila.h"

void visitar(M_GRAFO* g, char* cor, int* pred, int* d, int* f, int* time, int i, FILA* fila);
int* dfs(M_GRAFO* g);

#endif