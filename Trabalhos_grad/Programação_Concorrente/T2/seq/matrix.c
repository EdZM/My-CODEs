/*
 * =====================================================================================
 *
 *       Filename:  matrix.c
 *
 *    Description:  matrix manipulation lib
 *
 *        Version:  1.0
 *        Created:  09/11/2019 23:59:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Paulo Bodnarchuki, paulo.henrique.cruz@usp.br
 *         Nº USP:  9790944
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void create_int_matrix(int ***matrix, int row, int col) {
    (*matrix) = (int **) malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++) {
        (*matrix)[i] = (int *) malloc(col * sizeof(int));
    }
}

void print_int_matrix(int **matrix, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void free_matrix(int ***matrix, int row) {
    for(int i = 0; i < row; i++) {
        free((*matrix)[i]);
    }
    free(*matrix);
    *matrix = NULL;
}
