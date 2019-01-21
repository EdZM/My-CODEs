/*
 * =============================================================================================
 *
 *       Filename:  mgrafo.c
 *
 *    Description:  Arquivo que contem todas as operações feitas em cima da matriz de adjacencia
 *
 *         Nome:  Eduardo Zaboto Mirolli 
 *         Nº USP:  9778501
 *
 * =============================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "mgrafo.h"


//função que retorna uma struct grafo, que conterá uma matriz de adjacencia(alocada dinamicamente) e sua ordem(tamanho)
M_GRAFO* cria_mat_graf(int n){ 

	M_GRAFO* graf = NULL;
	int** mat = NULL;

	graf = (M_GRAFO*)malloc(sizeof(M_GRAFO));
	mat = (int**)malloc(sizeof(int*)*n);

	for (int i = 0; i < n; i++){
		mat[i] = (int*)malloc(sizeof(int)*n);
	}

	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++){
			mat[i][j] = -1;
		}
	}

graf->adj_mat = mat;
graf->ordem = n;

return graf;
}

//função para inserir uma aresta no grafo a partir de atribuições na matriz de adjacencia, que irão variar se o grafo for digrafo
void inserir_aresta_m(M_GRAFO *grafo, int row, int col) {
	grafo->adj_mat[row][col] = 1;	
}


//função para remover uma aresta do grafo, tambem a partir de atribuições na matriz de adjacencia
void remover_aresta_m(M_GRAFO* graf, int row, int col){

	if (graf->digraf == 1) { 
		graf->adj_mat[row][col] = -1; //o -1 é um indicador de ausencia de aresta ligando dois vertices do grafo
	
	}else{ 
		graf->adj_mat[row][col] = -1;
		graf->adj_mat[col][row] = -1; 
	}
}


//função para imprimir os vertices adjacentes a um vertice da matriz de adjacencia
void verts_adjac_m(M_GRAFO* graf, int d, int vertice){

	graf->digraf = d;

	if (graf->digraf != 1) {
		for (int i = 0; i < graf->ordem; i++)
			if (graf->adj_mat[i][vertice] != -1) printf("%d ", i);
	
	} else {
	
		for (int i = 0; i < graf->ordem; i++)
			if (graf->adj_mat[vertice][i] != -1) printf("%d ", i);
	}
	printf("\n");


}

//função para imprimir todo o grafo. As posições não existentes são marcadas com um "."
void imprime_graf_mat(M_GRAFO* graf){

	for (int i = 0; i < graf->ordem; i++)	{
		for (int j = 0; j < graf->ordem; j++){
			if (graf->adj_mat[i][j] != -1) printf("%d ", graf->adj_mat[i][j] );
			else printf(". ");
		}
		printf("\n");
	}


}

//função que retorna a ordem da matriz de adjacencia(não será usada para as operações principais)
int total_vertices_m(M_GRAFO* graf){
	return graf->ordem;

}

//função para a impressao da matriz transposta de adjacencia
void transposed_m_graf(M_GRAFO* graf){

	if(graf->digraf != 1) return;
	
	for (int i = 0; i < graf->ordem; i++){
		for (int j = 0; j < graf->ordem; j++){
			if (graf->adj_mat[j][i] != -1) printf("%d ", graf->adj_mat[j][i] ); //se o elemento da matriz existir imprima-o
			else printf(". ");													//caso contrario imprima um "."
		}
		printf("\n");	
	
	}

	


}

//Função para a impressao da aresta de menor peso, juntamente com os vertices ligados por ela
void encontra_min_val(M_GRAFO* graf){

	int min = INT_MAX; //min receberá o maior inteiro representável
	int x_min, y_min;

	for (int i = 0; i < graf->ordem; i++)	{
		for (int j = 0; j < graf->ordem; j++){
			if(graf->adj_mat[i][j] < min && graf->adj_mat[i][j] != -1) { // se o elemento da matriz existe ( != -1) e for menor que a variavel 'min'
				min = graf->adj_mat[i][j];								 // atribua esse elemento a 'min' e sua posição às coordanadas x e y
				x_min = i;
				y_min = j;
			}
		}
	}

	if (graf->digraf != 1) { //avaliando se o grafo é digrafo(interfere ativamente no tipo de impressao)
		if (x_min > y_min) printf("%d %d \n", y_min, x_min);
		else printf("%d %d \n", x_min, y_min);
	} else printf("%d %d \n", x_min, y_min);


}

//função para liberar as eventuais matrizes de adjacencia alocadas dinamicamente durante a execução do programa
void free_mat_graf(M_GRAFO** graf){

	if (*graf != NULL) {
		for (int i = 0; i < (*graf)->ordem; i++) 
			free((*graf)->adj_mat[i]);
			free((*graf)->adj_mat);
			free(*graf);
			*graf = NULL;
	}

}