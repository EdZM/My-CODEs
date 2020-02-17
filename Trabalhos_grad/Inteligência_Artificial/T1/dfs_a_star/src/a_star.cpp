#include <iostream>
#include <limits.h>
#include <math.h>
#include "matrix.hpp"
#include "a_star.hpp"

#define ANSI_COLOR_RED "\x1b[31m"

using namespace std;

typedef struct PATH {
	int lin;
	int col;
	double euclidian;
	struct PATH* next;
} PATH;

PATH* create_path(PATH* head, int lin, int col, int end[2]){
	if(head == NULL){
		head = (PATH*)calloc(1, sizeof(PATH));
	}
	else{
		while(head->next != NULL) head=head->next;
		
		head->next = (PATH*)calloc(1, sizeof(PATH));
		head = head->next;
	}
	
	head->lin = lin;
	head->col = col;
	head->euclidian = pow((lin-end[0]), 2) + pow((col-end[1]), 2);
	head->euclidian = sqrt(head->euclidian);
	head->next = NULL;

	return head;
}


void print_path(PATH* path){

    int current_lin;
    int current_col;

    float cost = 0;
    float n_els = 0; // numero de elementos que formam o caminho ate o destino
	while(path != NULL){
        n_els++;
        current_lin = path->lin;
        current_col = path->col;

        /* PARA IMPRIMIR O CAMINHO GERADO DESCOMENTE A LINHA ABAIXO*/
        //cout << "(" << path->lin << "," << path->col << ") " ;
        path = path->next;

        if (path != NULL){
            if (current_lin == path->lin || current_col == path->col) cost++;            
            else cost += 1.4;
            
        }
    }
    
    //cout << cost << endl;
    //cout << n_els << endl;
    cout << "Custo: " << cost << endl;
    cout << "Quantidade de elementos que formam o caminho até o destino: " << n_els;

	//printf("\033[22;31mHello, world!\033[0m"); // shows a blue hello world

	return;
}



int euclidian(char**matrix, int lin, int col, int end[2], PATH* path){

    //i+1 j-1, i+1 j, i+1 j+1
    //i j-1, i j, i j+1
    //i-1 j-1, i-1 j,  i-1 j+1
	int rw,cl;
	double sch;

	int cnt = 0;

	while(path->next != NULL) path = path->next;
	double min = INT_MAX;

	rw = path->lin;
	cl = path->col;

	for(int i=((path->lin)-1); i<((path->lin)+2) ; i++){ //percorre linhas
		for(int j=((path->col)-1); j < ((path->col)+2) ; j++){ //percorre colunas
			if(i<lin && i>=0 && j<col && j>=0){ // checa se posicao e valida
				//printf("matrix[%d][%d]=%c\n", i, j, matrix[i][j]);
				if(matrix[i][j] == 'F' || matrix[i][j] == '_' ){
					sch=pow((i-end[0]),2) + pow((j-end[1]), 2);
					sch=sqrt(sch);
					if(sch<min){
						min=sch;
						rw=i;
						cl=j;
					}
				}
			}			
		}		
	}
	
	create_path(path, rw, cl, end);
	matrix[rw][cl] = 'o';
	return min;
}


void destroy(PATH*path){

	if(path->next!=NULL){
		PATH* aux = path;
		path = path->next;
		free(aux);
	}

}


void a_star_search(char **lab, int row, int col){

	int end[2], bg[2];
    float aux;
    char** matrix;
	PATH* path = NULL;

    for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(lab[i][j] == 'F'){
				end[0] = i;
				end[1] = j;	
			} 
			if (lab[i][j] == 'I'){
				bg[0] = i;
				bg[1] = j;	
			
			} 
		}
	}

	path = create_path(path, bg[0], bg[1], end);

    

	while(path->euclidian != 0){
        aux = euclidian(lab, row, col, end, path);
		if(aux == 0) break;
 	}

	cout << endl;
	cout << "Após aplicar a busca: ";
	
	/* PARA IMPRIMIR O LABIRINTO JÁ PROCESSADO DESCOMENTE AS LINHAS ABAIXO*/
	lab[end[0]][end[1]] = 'F';
	print_char_matrix(lab,row,col);

	print_path(path);
	cout << endl;

    

	destroy(path);


}