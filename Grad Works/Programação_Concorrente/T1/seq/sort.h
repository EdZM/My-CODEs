/*
 * =====================================================================================
 *
 *       Filename:  sort.h
 *
 *    Description:  sort file header
 *
 *        Version:  1.0
 *        Created:  08/11/2019 23:33:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Paulo Bodnarchuki, paulo.henrique.cruz@usp.br
 *         Nº USP:  9790944
 *
 * =====================================================================================
 */

#ifndef SORT_H
#define SORT_H

void quicksort(int *arr, int low, int high, int C);

// intercal k lists of n size into a single vector v, of k*n size
void intercal(int **matrix, int *v, int k, int n);

#endif
