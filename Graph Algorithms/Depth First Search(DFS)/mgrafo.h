/*
 * =====================================================================================================================
 *
 *       Filename:  mgrafo.h
 *
 *    Description:  Arquivo contendo as assinaturas de todas as funções que serão feitas em cima da matriz de adjacencia
 *
 *         Nome:  Eduardo Zaboto Mirolli 
 *         Nº USP:  9778501
 *
 * =====================================================================================================================
 */


#ifndef MGRAFO_H
#define MGRAFO_H

typedef struct mat_grafo M_GRAFO;


struct mat_grafo{
	int ordem;  	//indicador da ordem da matriz de adjacencia
	int **adj_mat;	//ponteiro para a matriz	 
	int digraf; 	//indica se o grafo é digrafo ou não

};



M_GRAFO* cria_mat_graf(int n);
void inserir_aresta_m(M_GRAFO* graf, int row, int col);
void remover_aresta_m(M_GRAFO* graf, int row, int col);
void verts_adjac_m(M_GRAFO* graf, int d, int vertice);
void imprime_graf_mat(M_GRAFO* graf);
int total_vertices_m(M_GRAFO* graf);
void transposed_m_graf(M_GRAFO* graf);
void encontra_min_val(M_GRAFO* graf);
void free_mat_graf(M_GRAFO** mat);

#endif