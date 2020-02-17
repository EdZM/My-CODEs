/*
* =========================================================================================================================================================
*       T1 - Programação Concorrente
*       Nome do arquivo:  studentspar.c
*
*       Descrição:  
*                   
*
*       Nome:  Eduardo Zaboto Mirolli 
*       Nº USP:  9778501
*
*       Nome:  Paulo Henrique Bodanrchuki da Cruz
*       Nº USP:  9790944
*       
*       Nome: Gabriel Romualdo Silveira Pupo 
*       Nº USP : 9896250
*
*       Nome: Luiz Henrique Lourenção
*       Nº USP: 10284862
*
* =========================================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <math.h>
#include "matrix.h"
#include "sort.h"
#include "metrics.h"

int main(int argc, char* argv[]){
    
    int regions_qtd, cities_qtd, students_qtd, seed;
    int** matrix; // ponteiro que apontará para a matriz que armazena todas as notas.
    double wtime; // armazenará o tempo de resposta sem considerar operações de E/S
    float sum_of_means = 0; 
    int minimum = 1000, maximum = -1; // variáveis úteis para o cálculo do minimo e maximo de cada cidade/regiao ou país.

    scanf("%d",&regions_qtd);
    scanf("%d",&cities_qtd);
    scanf("%d",&students_qtd);
    scanf("%d",&seed);

    // Criação e geração aleatória da matriz que armazenará todas as notas.
    matrix_create(&matrix, regions_qtd*cities_qtd, students_qtd);
    generate_matrix(matrix, regions_qtd*cities_qtd, students_qtd, seed);

    // Variáveis associadas as cidades e suas métricas.
    float* cities_mean = (float*)malloc( sizeof(float)*regions_qtd*cities_qtd );
    float* cities_median = (float*)malloc( sizeof(float)*regions_qtd*cities_qtd );
    float* cities_standard_deviation = (float*)malloc( sizeof(float)*regions_qtd*cities_qtd );
    int* cities_smallest = (int*)malloc( sizeof(int)*regions_qtd*cities_qtd );
    int* cities_biggest = (int*)malloc( sizeof(int)*regions_qtd*cities_qtd );
    int **cities_aux = (int **) malloc (cities_qtd*sizeof(int *)); 

    // Variáveis associadas as regiões e suas métricas.
    int **regions; // matriz de regiões 
    float *regions_mean = (float*) malloc (sizeof(float) * regions_qtd);
    float *regions_median = (float*) malloc (sizeof(float) * regions_qtd);
    float *regions_standard_deviation = (float*) malloc (sizeof(float) * regions_qtd);
    int *regions_smallest = (int*) malloc (sizeof(int)*regions_qtd);
    int *regions_biggest = (int*) malloc (sizeof(int)*regions_qtd);

    // Variáveis associadas ao país e suas métricas.
    int* country = (int*)malloc(sizeof(int)* regions_qtd * cities_qtd * students_qtd);
    float country_mean;
    float country_median;
    float country_standart_deviation;
    int country_smallest;
    int country_biggest;

    // Variáveis associadas a busca pela melhor região e a melhor cidade dessa região.
    int best_city_c, best_city_r;
    int city_biggest_mean = -1;
    int best_region;
    int region_biggest_mean = -1;


    // salvamento do instante do programa que é imediatamente anterior ao cálculo de todas as métricas.
    wtime = omp_get_wtime(); 

    //#pragma omp parallel for schedule(static)
    for (int i = 0; i < regions_qtd*cities_qtd; i++)    
    {
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                cities_mean[i] = calculate_mean(matrix[i], students_qtd);
            }
            #pragma omp section
            {
                cities_median[i] = calculate_median(matrix[i], students_qtd );
            }
            #pragma omp section
            {
                cities_standard_deviation[i] = calculate_standard_deviation(matrix[i], students_qtd, cities_mean[i]);
            }
        }
        cities_smallest[i] = matrix[i][0];
        cities_biggest[i] = matrix[i][students_qtd-1];        

    }


    // Cálculo das métricas por região.
    matrix_create(&regions, regions_qtd, cities_qtd*students_qtd);
        
    for(int i = 0; i < regions_qtd; i++) {
        for(int j = i*cities_qtd; j < (i+1)*cities_qtd; j++) {
            cities_aux[j%cities_qtd] = matrix[j];
        }
        // junção de vetores ordenados de cidades em um vetor maior e ordenado de região.
        intercal(cities_aux, regions[i], cities_qtd, students_qtd);
    }
    free(cities_aux);
    

    
    for (int i = 0; i < regions_qtd; i++) 
    {
        sum_of_means = 0;
        minimum = 1000, maximum = -1;
        #pragma omp parallel for schedule(static) reduction(+:sum_of_means) reduction(max: maximum) reduction(min: minimum)
        for (int j = 0; j < cities_qtd; j++) {
            int current_city = (i*cities_qtd) + j;
            sum_of_means += cities_mean[current_city];
            if (cities_smallest[current_city] < minimum) minimum = cities_smallest[current_city];
            if (cities_biggest[current_city] > maximum) maximum = cities_biggest[current_city];
        }  
        regions_mean[i] = sum_of_means / cities_qtd;
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                regions_median[i] = calculate_median(regions[i], students_qtd*cities_qtd);
            }
            #pragma omp section
            {
                regions_standard_deviation[i] = calculate_standard_deviation(regions[i], students_qtd*cities_qtd, regions_mean[i]);
            }
        }
        regions_smallest[i] = minimum;
        regions_biggest[i] = maximum;
    }
    
    
    // Cálculo das métricas para o país.    
    
    for(int i = 0, j = 0; i < regions_qtd * cities_qtd; i++){
        for(int k = 0; k < students_qtd ; k++, ++j){
            country[j] = matrix[i][k]; 
        }
    }

    sum_of_means = 0;
    minimum = 1000, maximum = -1;
    
    #pragma omp parallel for schedule(static) reduction(+:sum_of_means) reduction(max: maximum) reduction(min: minimum)
    for(int i = 0; i < regions_qtd; i++ )
    {
        sum_of_means += regions_mean[i];
        if (regions_smallest[i] < minimum) minimum = regions_smallest[i];
        if (regions_biggest[i] > maximum) maximum = regions_biggest[i];

    }
    
    country_mean = sum_of_means / regions_qtd; 
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            country_median = calculate_median(country, regions_qtd * cities_qtd * students_qtd );
        }
        #pragma omp section
        {
            country_standart_deviation = calculate_standard_deviation(country, regions_qtd * cities_qtd * students_qtd, country_mean );
        }
    }
    country_smallest = minimum;
    country_biggest = maximum;

    // Busca da melhor região e melhor cidade (aquela que tem a melhor média).
   
    for (int i = 0; i < regions_qtd*cities_qtd; ++i) {
        if (city_biggest_mean < cities_mean[i]) {
            city_biggest_mean = cities_mean[i];
            best_city_c = i%cities_qtd; best_city_r = i/cities_qtd;
        }
    }

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < regions_qtd; ++i)
        if (region_biggest_mean < regions_mean[i]) {
            region_biggest_mean = regions_mean[i];
            best_region = i;
        }

    wtime = omp_get_wtime() - wtime; // calcula o tempo decorrido, através da diferença entre tempo atual e o instante inicial.

    // Impressão dos dados por cidade, por região e do país.
    for (int i = 0; i < regions_qtd; ++i) {
        for (int j = 0; j < cities_qtd; ++j)  {
            int current_city = (i*cities_qtd) + j;
            printf("Reg %d - Cid %d: menor: %d, maior: %d, mediana: %.2f, média: %.2f e DP: %.2f \n", i, j, cities_smallest[current_city], cities_biggest[current_city], cities_median[current_city], cities_mean[current_city], cities_standard_deviation[current_city]);
        }
        printf("\n");
    }
    for (int i = 0; i < regions_qtd; ++i) {
        printf("Reg %d: menor: %d, maior: %d, mediana: %.2f, média: %.2f, DP: %.2f\n", i, regions_smallest[i], regions_biggest[i], regions_median[i], regions_mean[i], regions_standard_deviation[i]);
    }
    printf("\n");


    printf("Brasil: menor: %d, maior: %d, mediana: %.2f, média: %.2f, DP: %.2f\n", country_smallest, country_biggest, country_median, country_mean, country_standart_deviation);

    printf("\nMelhor região: Região %d\n", best_region);
    printf("Melhor cidade: Região %d, Cidade %d\n\n", best_city_r, best_city_c);

    printf("Tempo de resposta sem considerar E/S, em segundos: %.3lfs\n", wtime);


    free_matrix(&matrix, regions_qtd*cities_qtd);
    free_matrix(&regions, regions_qtd);
    free(cities_mean);
    free(cities_median);
    free(cities_standard_deviation);
    free(cities_smallest);
    free(cities_biggest);
    free(regions_mean);
    free(regions_median);
    free(regions_standard_deviation);
    free(regions_smallest);
    free(regions_biggest);
    free(country);
    
return 0;    
}