/*
 * =====================================================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Programa que cria dois grafos, usando matriz de adjacencia e lista de adjacencia
 *					e faz operações de inserção, remoção, transposição, verificação de arestas, impressao nesses grafos.
 *
 *         Nome:  Eduardo Zaboto Mirolli 
 *         Nº USP:  9778501
 *
 * =====================================================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mgrafo.h"
#include "lgrafo.h"

int main(int argc ,char* argv[]){

	char digr;		//caracter que indica se o grafo é digrafo ou não
	char graf_type; //especifica o tipo de grafo. Determina tambem quais operações serão usadas
	int vert;		//numero de vertices
	int arest; 		//numero de arestas
	int dig; 		//indicador inteiro de se um grafo é digrafo ou não(usado como parametro nas funções)
	int peso;		//indicador do peso de uma aresta
	int x_coord, y_coord; //uteis para saber quais vertices estao ligados ou nao por uma aresta
	char op[2];		//indicará as operações a serem feitas:IG, AA, VA, RA, IT, MP



	M_GRAFO* mat_graf = NULL;
	L_GRAFO* list_graf = NULL;


	scanf("%c %c %d %d", &digr, &graf_type, &vert, &arest);
	if(graf_type == 'M' ) {
		mat_graf = cria_mat_graf(vert);		
		
	}else if (graf_type == 'L'){
		list_graf = cria_list_graf(vert);
	}


	if(digr == 'D'){
		dig = 1;
	}else if (digr == 'G'){
		dig = 0;
	}
	

	for (int i = 0; i < arest; i++)	{ //coletando os vertices, arestas e pesos, que serão inseridos na matriz OU na lista de adjacencia
		scanf("%d %d %d",&x_coord, &y_coord, &peso );
		if(graf_type == 'M' ) inserir_aresta_m(mat_graf, dig, x_coord ,y_coord, peso);
		else if(graf_type == 'L' ) inserir_aresta_l(list_graf, dig, x_coord, y_coord, peso);
	
	}

	while( scanf("%s",op) != EOF ){ //operar sobre as listas até que o final do arquivo seja alcançado
		if (!strcmp(op, "IG")){
			if(graf_type == 'M' ) imprime_graf_mat(mat_graf);
			else if(graf_type == 'L' ) imprimir_grafo_l(list_graf);
			
		}
		if (!strcmp(op, "VA")){ //verifica basicamente se foi digitado um 'VA' . O mesmo padrão é usado para as demais operações
			scanf("%d", &vert);
			if(graf_type == 'M' ) verts_adjac_m(mat_graf, dig, vert);
			else if(graf_type == 'L' ) imprimir_vert_adjacente_l(list_graf, vert);

		}
		if (!strcmp(op, "AA")){
			scanf("%d %d %d", &x_coord, &y_coord, &peso);
			if(graf_type == 'M' ) inserir_aresta_m(mat_graf, dig, x_coord, y_coord, peso);
			else if(graf_type == 'L' ) inserir_aresta_l(list_graf, dig, x_coord, y_coord, peso);

		}
		if (!strcmp(op, "RA")){
			scanf("%d %d", &x_coord, &y_coord);
			if(graf_type == 'M' ) remover_aresta_m(mat_graf, x_coord, y_coord);
			else if(graf_type == 'L' ) remover_aresta_l(list_graf, dig, x_coord,  y_coord);

		}
		if (!strcmp(op, "IT")){
			if(graf_type == 'M' ) transposed_m_graf(mat_graf);
			else if(graf_type == 'L' ) transposed_graf_l(list_graf, dig);

		}
		if (!strcmp(op, "MP")){
			if(graf_type == 'M' ) encontra_min_val(mat_graf);
			else if(graf_type == 'L' ) encontra_min_val_l(list_graf, dig);

		}
	}

	if (graf_type == 'M') free_mat_graf(&mat_graf);
	else if (graf_type == 'L') free_list_graf(&list_graf);


return 0;
}