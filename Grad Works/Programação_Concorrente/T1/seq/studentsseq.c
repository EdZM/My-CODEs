/*
 * =====================================================================================
 *
 *       Filename:  seq.c
 *
 *    Description:  codigo sequencial para calculo de media, mediana, variancia e desvio das linhas de uma matriz
 *
 *        Version:  1.0
 *        Created:  08/11/2019 19:44:32
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
#include <math.h>
#include <limits.h>
#include <time.h>
#include "matrix.h"
#include "sort.h"

typedef struct METRICS {
    float *mean;
    float *median;
    float *standard_deviation;
    int *smallest;
    int *biggest;
} METRICS;


void fill_matrix(int **matrix, int row, int col, int seed) {
    srand(seed);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            matrix[i][j] = rand() % 101;
        }
    }
}

int print_float_vector(float *vec, int n) {
    for(int i = 0; i < n; i++) {
        printf("%lf ", vec[i]);
    }
    printf("\n");
}

int print_int_vector(int *vec, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
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

// Calculate mean, median, variation and min and max values of cities, regions and country
void metrics(int **matrix, int row, int col, METRICS *met) {

    for(int i = 0; i < row; i++) {
        met->mean[i] = calculate_mean(matrix[i], col);
        met->median[i] = calculate_median(matrix[i], col);
        met->standard_deviation[i] = calculate_standard_deviation(matrix[i], col, met->mean[i]);
        met->smallest[i] = matrix[i][0];
        met->biggest[i] = matrix[i][col-1];
    }

//    printf("Mean: ");
//    print_float_vector(met->mean, row);
//    printf("Median: ");
//    print_float_vector(met->median, row);
//    printf("Deviation: ");
//    print_float_vector(met->standard_deviation, row);
//    printf("Small: ");
//    print_int_vector(met->smallest, row);
//    printf("Big: ");
//    print_int_vector(met->biggest, row);
//    printf("\n");
    
}

void initialize_metrics_struct(METRICS **met, int row) {
    (*met) = (METRICS *) malloc (sizeof(METRICS));
    
    (*met)->mean = (float *) malloc (row * sizeof(float));
    (*met)->median = (float *) malloc (row * sizeof(float));
    (*met)->standard_deviation = (float *) malloc (row * sizeof(float));
    (*met)->smallest = (int *) malloc (row * sizeof(int));
    (*met)->biggest = (int *) malloc (row * sizeof(int));
}

void free_metrics(METRICS **met) {
    free((*met)->mean);
    free((*met)->median);
    free((*met)->standard_deviation);
    free((*met)->smallest);
    free((*met)->biggest);

    free((*met));
    *met = NULL;
}

// Function to calculate the index of maximum value of a vector
int max_index(float *vec, int n) {
    float max = -1;
    int index = -1;
    for(int i = 0; i < n; i++) {
        if(vec[i] > max) {
            max = vec[i];
            index = i;
        }
    }

    return index;
}

// Function to print metrics structs
void print_metrics(METRICS *cities, METRICS *regions, METRICS *country, int cities_qtd, int regions_qtd, double time_taken) {
    
    //printing cities metrics
    for (int i = 0; i < regions_qtd; ++i) {
        for(int j = 0; j < cities_qtd; j++) {
            int current_city = (i*cities_qtd) + j;
            printf("Reg %d - Cid %d: menor: %d, maior: %d, mediana: %.2f, média: %.2f, DP: %.2f\n", i, j, cities->smallest[current_city], cities->biggest[current_city], cities->median[current_city], cities->mean[current_city], cities->standard_deviation[current_city]);
        }
        printf("\n");
    }

    // printing regions metrics 
    for (int i = 0; i < regions_qtd; ++i) {
        printf("Reg %d: menor: %d, maior: %d, mediana: %.2f, média: %.2f, DP: %.2f\n", i, regions->smallest[i], regions->biggest[i], regions->median[i], regions->mean[i], regions->standard_deviation[i]);
    }
    printf("\n");

    //printing country metrics
    printf("Brasil: menor: %d, maior: %d, mediana: %.2f, média: %.2f, DP: %.2f\n", country->smallest[0], country->biggest[0], country->median[0], country->mean[0], country->standard_deviation[0]);
    printf("\n");

    int best_region = max_index(regions->mean, regions_qtd);
    printf("Melhor regiao: Regiao %d\n", best_region);

    int best_city = max_index(cities->mean, cities_qtd*regions_qtd);
    printf("Melhor cidade: Regiao %d, Cidade %d\n",
            (best_city / cities_qtd),
            (best_city % cities_qtd));
    printf("\n");


    //printing time
    printf("Tempo de resposta sem considerar E/S, em segundos: %.3fs\n", time_taken);
}

int main(int argc, char **argv[]) {
    int row, col, seed, regions_qtd, cities_qtd, students;
    int **cities;
    clock_t start, end;
    double cpu_time_used;

    scanf("%d", &regions_qtd);
    scanf("%d", &cities_qtd);
    scanf("%d", &students);
    scanf("%d", &seed);

    
    row = regions_qtd*cities_qtd;
    col = students;

    // struct for printing results
    METRICS *cities_met;
    initialize_metrics_struct(&cities_met, row);
    
    METRICS *regions_met;
    initialize_metrics_struct(&regions_met, regions_qtd);
   
    METRICS *country_met;
    initialize_metrics_struct(&country_met, 1);
  

    create_int_matrix(&cities, row, col);
    fill_matrix(cities, row, col, seed);

//    printf("CITIES: \n");
//    print_int_matrix(cities, row, col);
    

    start = clock();
    // cities metrics
//    printf("CITIES METRICS: \n");
    metrics(cities, row, col, cities_met);

    // regions metrics
//    printf("REGIONS: \n");
    int **regions;
    create_int_matrix(&regions, regions_qtd, cities_qtd*col);
    
    // cities_aux = matrix will save part of the matrix, the part that will be intercaled into a vector
    int **cities_aux = (int **) malloc (cities_qtd*sizeof(int *));
    for(int i = 0; i < regions_qtd; i++) {
        for(int j = i*cities_qtd; j < (i+1)*cities_qtd; j++) {
            cities_aux[j%cities_qtd] = cities[j];
        }
        // intercaling all cities vectors of a region into a single region vector 
        intercal(cities_aux, regions[i], cities_qtd, col);
    }
    free(cities_aux);
//    print_int_matrix(regions, regions_qtd, cities_qtd*col);
//    printf("REGIONS METRICS: \n");
    metrics(regions, regions_qtd, cities_qtd*col, regions_met);


    //country metrics
//    printf("COUNTRY: \n");
    int **country = (int **) malloc (1 * sizeof(int));
    country[0] = (int *) malloc(row*col * sizeof(int));
    
    // intercaling regions vector into a single country vector
    intercal(regions, country[0], regions_qtd, cities_qtd*col);
//    print_int_matrix(country, 1, row*col);
//    printf("COUNTRY METRICS: \n");
    metrics(country, 1, row*col, country_met);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    print_metrics(cities_met, regions_met, country_met, cities_qtd, regions_qtd, cpu_time_used);

    free_metrics(&cities_met);
    free_metrics(&regions_met);
    free_metrics(&country_met);
    free_matrix(&country, 1);
    free_matrix(&regions, regions_qtd);
    free_matrix(&cities, row);
}
