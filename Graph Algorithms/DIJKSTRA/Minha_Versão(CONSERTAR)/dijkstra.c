#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dijkstra.h"
#include "fila_prioridade.h"



int busca_S(int* S, int vertice, int size){

	for (int i = 0; i < size; i++){
		if(S[i] == vertice){
			return 1;
			break;
		}
	}
	return 0;

}

int* dijkstra(M_GRAFO* graf, int origem, int destino ){
	
	
	int pos;
	int u;
	int j = 0;  //indice para o vetor S auxiliar
	int* S;		//vetor auxiliar para guardar nós já processados
	int* p;		//vetor de predecessores
	int* d;		//vetor de distancias 
	int* path;	//vetor com o caminho minimo
	FILA_P* Q;	//fila de prioridades
	no* aux;	//nó auxiliar usado em cada extração da fila de prioridades

	aux = (no*) malloc(sizeof(no));
	S = (int*) malloc(sizeof(int)*graf->ordem); 
	p = (int*) malloc(sizeof(int)*graf->ordem);
	d = (int*) malloc(sizeof(int)*graf->ordem);
	path = (int*)malloc(sizeof(int)*graf->ordem) ;
	

	Q = inicializar();

	insert(Q, origem, INT_MAX);
	for (int i = 0; i < graf->ordem ; i++)	{
		
		if(i != origem) insert(Q, i, INT_MAX);
		d[i] = INT_MAX;
		p[i] = -1;
		S[i] = -1;
		path[i] = -1;
	
	}

	d[origem] = 0;

	while( !fila_p_vazia(Q) ){
		

		aux = extrair_primeiro(Q); // como é uma fila de prioridade(no caso uma min_heap) o primeiro que extraio é o de menor prioridade
		u = aux->vertice;
		S[j++] = u; 

		for (int i = 0; i < graf->ordem ; i++)	{

			if ( graf->adj_mat[u][i] != -1 && !(busca_S(S, i, graf->ordem)) ){
				
				if ( d[i] > d[u] + graf->adj_mat[u][i] ){
					d[i] = d[u] + graf->adj_mat[u][i];
					p[i] = u;
					
					pos = busca(Q, i); 	// caso a posição já exista na fila de prioridade é só atualizá-la com a nova prioridade e rearranjá-la
					if(pos >= 0) {		// caso contrario uma nova inserção é necessária
						Q->fp[pos].prioridade = d[i];
						rearranjar(Q, 0, Q->fila_top - 2);
					}
					else { 			
						insert(Q, i, d[i]);

					}
				
				}
			
			}

		}
		
	}

	if( d[destino] != INT_MAX ){
		
		int counter = 0;
		
		path[counter] = destino;
		pos = destino;
		
		while (pos != origem){
			path[++counter] = p[pos];
			pos = p[pos];

		}

		for (int i = graf->ordem - 1 ; i >= 0  ; i--){
			if(path[i] != -1) printf("%d ", path[i]);
		
		}
		
	}

free(path);
free(p);
free(d);
free(aux);
free(S);




}
