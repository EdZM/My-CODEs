#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "matrix.h"
#include "sort.h"

#define T_NUM 8
void fill_matrix(int **matrix, int row, int col, int seed) {
    srand(seed);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            matrix[i][j] = rand() % 50;
        }
    }
}

float calculate_mean(int *vec, int n) {
    float media = 0;
    
    for(int i = 0; i < n; i++) {
        media += vec[i];
    }
    

    return media/n;
}

float calculate_median(int *vec, int n) {
    float median = 0;
    
    quicksort(vec, 0, n-1, 1);

    // if number of elements are even
    if(n%2 == 0)
        median = (vec[(n-1)/2] + vec[n/2])/2.0;
    // if number of elements are odd
    else
        median = vec[n/2];

    return median;
}

float calculate_standard_deviation(int *vec, int n, float media) {
    float deviation = 0;
  
    for(int i = 0; i < n; i++) {
        deviation += pow(((float)vec[i] - media), 2);
    }
    
    return sqrt(deviation/n);
}
