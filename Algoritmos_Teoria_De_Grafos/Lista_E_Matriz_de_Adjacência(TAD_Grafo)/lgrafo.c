/*
 * =============================================================================================
 *
 *       Filename:  lgrafo.c
 *
 *    Description:  Arquivo que contem todas as operações feitas em cima da lista de adjacencia
 *
 *         Nome:  Eduardo Zaboto Mirolli 
 *         Nº USP:  9778501
 *
 * =============================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lgrafo.h"

#define SENTINEL(I,J) (I)->vetor[(J)]->sentinel //essa notação facilitará o entendimento do deslocamento do nó sentinela pela lista de adjacencia


//função que retorna uma struct, que conterá uma matriz de nós( **vetor ) que representará a lista de adjacencia a ser usada
L_GRAFO *cria_list_graf(int n){

	L_GRAFO *lgraf = (L_GRAFO *) malloc (sizeof(L_GRAFO));
	NODE **vector = (NODE **) malloc (n * sizeof(NODE *));
	
	
	if (lgraf != NULL && vector != NULL) {
		for (int i = 0; i < n; i++) {
			vector[i] = (NODE *) malloc (sizeof(NODE));
			vector[i]->n_aresta = i;
			
			ARCO *sent = (ARCO *) malloc (sizeof(ARCO));
			
			sent->peso = -1;
			sent->adj = -1;
			
			if (sent != NULL) {
				vector[i]->sentinel = sent;
				vector[i]->fim = sent; 
				vector[i]->fim->prox = vector[i]->sentinel;
			}
		}
	}

	lgraf->vetor = vector;
	lgraf->n = n;

return lgraf;

}

//função para inserir uma aresta no grafo, partindo da procura da posição correta na lista de adjacencia
void inserir_aresta_l(L_GRAFO *lgraf , int d, int x, int y , int peso){

	ARCO *novo = (ARCO *) malloc (sizeof(ARCO));
	ARCO *aux = SENTINEL(lgraf, x);

	if (novo != NULL && aux != NULL) {
		novo->peso = peso;
		novo->adj = y;

		//percorrendo a lista até encontrar a posição adequada para a inserção
		while (aux->prox != SENTINEL(lgraf, x) && novo->adj > aux->prox->adj){ 
			aux = aux->prox;
		}

		novo->prox = aux->prox;
		aux->prox = novo;
			
		if (d != 1 && x != y) { // avaliando se o grafo é digrafo e se as coordenadas x e y fornecidas por parametro são diferentes
			ARCO *novo_sim = (ARCO *) malloc (sizeof(ARCO));
			ARCO *aux_sim = SENTINEL(lgraf, y);

			if (novo_sim != NULL && aux_sim != NULL) {
				novo_sim->peso = peso;
				novo_sim->adj = x;

				while (aux_sim->prox != SENTINEL(lgraf,y) && novo_sim->adj > aux_sim->prox->adj){
					aux_sim = aux_sim->prox;
				}
			
				novo_sim->prox = aux_sim->prox;
				aux_sim->prox = novo_sim;
			
			}
		}
	}


}

//função que apenas remove um arco entre dois vertices
void apagar_arco(ARCO **arco) {
	if (*arco != NULL) {
		free(*arco);
		*arco = NULL;
	}
}

//função para remover uma aresta do grafo, tambem a partir da procura pela posição se ser removida
void remover_aresta_l(L_GRAFO *lgraf, int d, int x,  int y){
	ARCO *aux = SENTINEL(lgraf, x); //arco auxiliar usado para percorrer a lista
	ARCO *rem = NULL; 				//armazenará arco a ser removido

	if (aux != NULL) { //as operações de remoção só poderão ser feitas em cima de arcos/arestas que existam
		
		//percorrendo a lista até encontrar a posição adequada para a remoção
		while (aux->prox != SENTINEL(lgraf, x) && aux->prox->adj != y){
			aux = aux->prox;
		}
		
		if (aux->prox != SENTINEL(lgraf, x)) {
			rem = aux->prox;
			aux->prox = rem->prox;
			apagar_arco(&rem);
		}

		if (d != 1) { //se o grafo não for digrafo, é necessario repetir a operação acima mas agora para o vertice que tem o vertice a ser removido como adjacente
			aux = SENTINEL(lgraf,y);
			rem = NULL;

			while (aux->prox != SENTINEL(lgraf, y) && aux->prox->adj != x){
				aux = aux->prox;
			}

			if (aux->prox != SENTINEL(lgraf, y)) {
				rem = aux->prox;
				aux->prox = rem->prox;
				apagar_arco(&rem);
			}
		}
	}


}
//Função para a impressao da aresta de menor peso, juntamente com os vertices ligados por ela. Segue o mesmo principio na matriz de adjacencia
void encontra_min_val_l(L_GRAFO * lgraf, int d){
	int min = INT_MAX; //min, x_min, y_min reunem informações necessarias sobre a aresta de menor peso
	int x_min, y_min;
	
	for (int i = 0; i < lgraf->n; i++) {
		
		ARCO *aux = SENTINEL(lgraf, i); //arco auxiliar usado para percorrer a lista
		if (aux != NULL) {
			while (aux->prox != SENTINEL(lgraf, i)) { //percorrendo a lista em busca do arco/aresta de menor peso
				if (aux->prox->peso < min) {
					min = aux->prox->peso;
					x_min = i;
					y_min = aux->prox->adj;
				}
				aux = aux->prox;
			}
		}
	}	
	
	if (d != 1) { //se for digrafo, muda o esquema de impressão
        if (x_min > y_min) printf("%d %d\n", y_min,x_min);
        else printf("%d %d\n", x_min, y_min);
  
   } else printf("%d %d\n", x_min, y_min);

}


//função para a impressao da lista de adjacencia transposta
void transposed_graf_l(L_GRAFO *lgraf, int d){
	
	if (d != 1) return; //avaliando se o grafo é digrafo

	int i;
	L_GRAFO *transp = cria_list_graf(lgraf->n); //será usado apenas para a impressão da lista transposta
		
	for (i = 0; i < lgraf->n; i++) {
		ARCO *aux = SENTINEL(lgraf,i);
		while (aux->prox != SENTINEL(lgraf,i)) {
			inserir_aresta_l(transp, 1, aux->prox->adj, i, aux->prox->peso);
			aux = aux->prox;
		}
	}	
	
	imprimir_grafo_l(transp); //imprimindo a lista de adjacencia transposta 
	free_list_graf(&transp); //liberando a lista de adjacencia transposta 

}

//função para a impressao de vertices adjacentes a um vertice fornecido por parametro
void imprimir_vert_adjacente_l(L_GRAFO* lgraf, int vert){
	ARCO *aux = SENTINEL(lgraf,vert);
	if (aux != NULL) {
		while (aux->prox != SENTINEL(lgraf, vert)) {
			printf("%d ", aux->prox->adj);
			aux = aux->prox;
		}
		printf("\n");
	}


}

//função para a impressao da lista de adjacencia
void imprimir_grafo_l(L_GRAFO *lgraf){

	int i;
	for (i = 0; i < lgraf->n; i++) {
		printf("%d. ", i);
		ARCO *aux = SENTINEL(lgraf, i);
		while (aux->prox != SENTINEL(lgraf, i)) {
			printf("%d(%d) ", aux->prox->adj, aux->prox->peso);
			aux = aux->prox;
		}
		printf("\n");
	}


}

//função para desalocar o que foi alocado dinamicamente durante a execução do programa
void free_list_graf(L_GRAFO **lgraf){
	int i;
	for (i = 0; i < (*lgraf)->n; i++) {
		ARCO *aux = SENTINEL((*lgraf),i);
		ARCO *excl = NULL;

		while (aux->prox != SENTINEL((*lgraf),i)) {
			excl = aux;
			aux = aux->prox;
			apagar_arco(&excl);
		}
		apagar_arco(&aux);
		free((*lgraf)->vetor[i]);
	}
	free((*lgraf)->vetor);
	free(*lgraf);
	*lgraf = NULL;



}