#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


void matrix_create(int*** matrix, int row, int col){

    (*matrix) = (int**) malloc(sizeof(int*)*row);
    for(int i = 0; i < row; i++)(*matrix)[i] = (int*) malloc(sizeof(int)*col);
    
}

void generate_matrix(int** matrix, int row, int col, int seed){
    
    // gera a matriz de notas de cada aluno.
    srand(seed);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            matrix[i][j] = rand() % 101; // gera valores entre 0 e 100.
        }
    }

}

void print_matrix(int** matrix, int row, int col){

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}

void free_matrix(int ***matrix, int row) {
    for(int i = 0; i < row; i++) {
        free((*matrix)[i]);
    }
    free(*matrix);
    *matrix = NULL;
}