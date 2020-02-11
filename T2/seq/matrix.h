/*
 * =====================================================================================
 *
 *       Filename:  matrix.h
 *
 *    Description:  Matrix manipulation lib
 *
 *        Version:  1.0
 *        Created:  10/11/2019 00:02:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Paulo Bodnarchuki, paulo.henrique.cruz@usp.br
 *         Nº USP:  9790944
 *
 * =====================================================================================
 */
#ifndef MATRIX_H
#define MATRIX_H

void create_int_matrix(int ***matrix, int row, int col);
void print_int_matrix(int **matrix, int row, int col);
void free_matrix(int ***matrix, int row);

#endif
