/*
* =========================================================================================================================================================
*       T2 - Programação Concorrente
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
#include <mpi.h>
#include <time.h>
#include <math.h>
#include "matrix.h"
#include "sort.h"
#include "metrics.h"
#include <stdbool.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    
    int regions_qtd, cities_qtd, students_qtd, seed, my_range, regions_cols;
    


     // variáveis úteis para o cálculo do minimo e maximo de cada cidade/regiao ou país.
    int my_rank;
    int num_procs;
    MPI_Request request;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); // obtem o rank do processo atual
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs); // obtem o número de processos em execução

    
    if(my_rank == 0){

        int regions_qtd, cities_qtd, students_qtd, seed, my_range;
        int** matrix; // ponteiro que apontará para a matriz que armazena todas as notas.
        double time1, time2;
        float sum_of_means = 0; 
        int minimum = 1000, maximum = -1;

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
        int *regions_smallest = (int*) malloc (sizeof(int) * regions_qtd);
        int *regions_biggest = (int*) malloc (sizeof(int) * regions_qtd);

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

        time1 = MPI_Wtime();

        int total_cities = regions_qtd*cities_qtd;
        MPI_Bcast(&total_cities, 1, MPI_INT, 0, MPI_COMM_WORLD);

        my_range = floor( (cities_qtd * regions_qtd )/(num_procs * 1.0));
        // se não for possivel dividir as amostras em partições iguais, aumente a quantidade de colunas nas C primeiras partições para compensar
        int module = (cities_qtd * regions_qtd)%num_procs;

        if (my_rank < module)
            my_range++;

        
        int tag = 0;
        
        for(int i = 1; i < cities_qtd * regions_qtd; i++){
            int range = floor( (cities_qtd * regions_qtd) /(num_procs * 1.0)); 
            if (i < module)
                range++;
            
            if( i % num_procs != 0){    
                if( i < num_procs ) { // garante que vai mandar só uma vez por processo 
                    MPI_Isend( &range, 1, MPI_INT, i%num_procs, 0, MPI_COMM_WORLD, &request); // envia a quantidade de colunas da partição
                    MPI_Isend( &students_qtd, 1, MPI_INT, i%num_procs, 0, MPI_COMM_WORLD, &request ); // envia a quantidade de linhas da partição
                }
            //    printf("envio para o processo: %d -- tag: %d\n", i%num_procs, i/num_procs);
                
                MPI_Isend(matrix[i], students_qtd, MPI_INT, i%num_procs, i/num_procs, MPI_COMM_WORLD, &request);
                //printf("enviou i = %d\n", i);
            }
            
            
        }
        //print_matrix(matrix, cities_qtd * regions_qtd , students_qtd);
        MPI_Bcast(&regions_qtd, 1, MPI_INT, 0, MPI_COMM_WORLD);
        //printf("my range: %d\n", my_range);    
        for (int i = 0; i < my_range; i++){
            int gap = ceil(i * num_procs);
            //printf("gap = ceil([%d * %d * %d] / %d) = %d\n", i, cities_qtd, regions_qtd, my_range, gap);
            
            cities_mean[gap] = calculate_mean(matrix[gap], students_qtd);
            cities_median[gap] = calculate_median(matrix[gap], students_qtd, true );
            cities_standard_deviation[gap] = calculate_standard_deviation(matrix[gap], students_qtd, cities_mean[0]);
            cities_smallest[gap] = matrix[gap][0];
            cities_biggest[gap] = matrix[gap][students_qtd-1];        
        }
        
        for (int i = 0; i < cities_qtd * regions_qtd; i++){
            
            int range = floor( (cities_qtd * regions_qtd) /(num_procs * 1.0)); 
            int module = (cities_qtd * regions_qtd)%num_procs;
            if (i < module)
                range++;
            //printf("range")
            if( /*(range > 1 && i != 0) && (my_range != 1 &&*/ i%num_procs != 0 ){   
                //printf("entrante para i = %d -- range = %d\n", i, my_range) ;
              //  printf("%d mod %d = %d\n", i, my_range, i%my_range);
                //printf("src - %d flag - %d\n ", i%num_procs, ceil(i/range));
               // sleep(10);
               //printf("i/proc %d\n", i/num_procs);
                MPI_Recv(&cities_mean[i], 1, MPI_FLOAT, i%num_procs, i/num_procs, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
                //printf("MEAN recebida do filho %f - tagged %d - source %d\n", cities_mean[i], i/num_procs, i%num_procs);                
                MPI_Recv(&cities_median[i], 1, MPI_FLOAT, i%num_procs, i/num_procs, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
                //printf("median: %.2lf\n ", cities_median[i]);
                //printf("MEDIAN recebida do filho %lf - tagged %d - source %d\n", cities_median[i], i/num_procs, i%num_procs);                
                MPI_Recv(&cities_standard_deviation[i], 1, MPI_FLOAT, i%num_procs, i/num_procs, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
                //printf("standard_deviation: %.2lf\n ", cities_standard_deviation[i]);
                //printf("SD recebida do filho %lf - tagged %d - source %d\n", cities_standard_deviation[i], i/num_procs, i%num_procs);                
                MPI_Recv(&cities_smallest[i], 1, MPI_INT, i%num_procs, i/num_procs, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
                //printf("smallest: %.2lf\n ", cities_smallest[i]);
                //printf("SMALL recebida do filho %d - tagged %d - source %d\n", cities_smallest[i], i/num_procs, i%num_procs);                
                MPI_Recv(&cities_biggest[i], 1, MPI_INT, i%num_procs, i/num_procs, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
                //printf("biggest: %.2lf\n ", cities_biggest[i]);
                //printf("BIG recebida do filho %d - tagged %d - source %d\n", cities_biggest[i], i/num_procs, i%num_procs);                
        
                MPI_Recv(matrix[i], students_qtd, MPI_INT, i%num_procs, i/num_procs, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        
                // for(int j = 0; j < students_qtd ; j ++){
                //     printf("%d " ,matrix[i][j]);    
                // }
                // printf("\n");
            }

        }
        // for (int j = 0; j < cities_qtd * regions_qtd; j++){
        //     printf("%.2lf ", cities_mean[j]);
        // }
        // printf("\n\n\n\n\n\n");

        matrix_create(&regions, regions_qtd, students_qtd*cities_qtd);
       

        for(int i = 0; i < regions_qtd; i++) {
            for(int j = i*cities_qtd; j < (i+1)*cities_qtd; j++) {
                cities_aux[j%cities_qtd] = matrix[j];
            }
            // junção de vetores ordenados de cidades em um vetor maior e ordenado de região.
            intercal(cities_aux, regions[i], cities_qtd, students_qtd);
        }
        
        free_matrix(&cities_aux, cities_qtd);
        //print_matrix(cities_aux, cities_qtd, students_qtd*cities_qtd);
        
        int reg_procs = (regions_qtd < num_procs) ? regions_qtd : num_procs;
        my_range = floor( (regions_qtd ) / (reg_procs * 1.0) );
        module = ( regions_qtd ) % reg_procs;

        if (my_rank < module)
            my_range++;

        int j, aux = my_range;
        regions_cols = students_qtd*cities_qtd;

        print_matrix(regions, regions_qtd, students_qtd*cities_qtd);

        for(int i = 1; i < reg_procs; i++){
            int range = floor( regions_qtd /(reg_procs * 1.0)); 
            if (i < module)
                range++;
            
            MPI_Isend( &range, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &request); 
            MPI_Isend( &regions_cols, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &request ); 

            for ( j = aux; j < aux + range; j++ ){
                
                MPI_Isend(regions[j], cities_qtd*students_qtd, MPI_INT, i, j%range, MPI_COMM_WORLD, &request);

            }
            aux = j;
            //printf("enviei tudo para o processo i == %d\n", i );
            
        }
        
        
        for (int i = 0; i < my_range; i++){
            // int gap = ceil(i * num_procs);
            //printf("gap = ceil([%d * %d * %d] / %d) = %d\n", i, cities_qtd, regions_qtd, my_range, gap);
            //printf("media %.2f\n ", regions_mean[i]);
            
            regions_mean[i] = calculate_mean(regions[i], cities_qtd * students_qtd);
            regions_median[i] = calculate_median(regions[i], cities_qtd * students_qtd, false );
            regions_standard_deviation[i] = calculate_standard_deviation(regions[i], cities_qtd * students_qtd, regions_mean[0]);
            regions_smallest[i] = regions[i][0];
            regions_biggest[i] = regions[i][(cities_qtd*students_qtd)-1];        
        }
        
        //printf("recebendo dos filhos ... \n");

        aux = my_range;
        for(int i = 1; i < reg_procs; i++) {
            int range = floor( regions_qtd /(reg_procs * 1.0)); 
            if (i < module)
                range++;

            float* regions_mean_aux = (float*) malloc (sizeof(float) * range);
            float* regions_median_aux = (float*) malloc (sizeof(float) * range);
            float* regions_standard_deviation_aux = (float*) malloc (sizeof(float) * range);
            int* regions_smallests_aux = (int*) malloc (sizeof(int) * range);
            int* regions_biggests_aux = (int*) malloc (sizeof(int) * range);
            

            MPI_Recv(regions_mean_aux, range, MPI_FLOAT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
            MPI_Recv(regions_median_aux, range, MPI_FLOAT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
            MPI_Recv(regions_standard_deviation_aux, range, MPI_FLOAT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );            
            MPI_Recv(regions_smallests_aux, range, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );            
            MPI_Recv(regions_biggests_aux, range, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );


            int j = 0;
            int k;
            for(j = aux, k = 0 ; j < aux + range; j++, k++){
                regions_mean[j] = regions_mean_aux[k];
                regions_median[j] = regions_median_aux[k];
                regions_standard_deviation[j] = regions_standard_deviation_aux[k];
                regions_smallest[j] = regions_smallests_aux[k];
                regions_biggest[j] = regions_biggests_aux[k];
                
            }
            aux = j;

            free(regions_mean_aux);
            free(regions_median_aux);
            free(regions_standard_deviation_aux);
            free(regions_smallests_aux);
            free(regions_biggests_aux);
        
            regions_mean_aux = NULL;
            regions_median_aux = NULL;
            regions_standard_deviation_aux = NULL;
            regions_smallests_aux = NULL;
            regions_biggests_aux = NULL;

        }
        
        
        //free_matrix(&matrix, students_qtd);

        intercal(regions, country,  regions_qtd, cities_qtd*students_qtd);

        int country_grades = regions_qtd * cities_qtd * students_qtd;

        // printf("pais: ");
        // for (int i = 0; i < country_grades ; i++){
        //     printf("%d ", country[i]);
        // }
        // printf("\n");
    
        country_mean = calculate_mean(country, country_grades );
        country_median = calculate_median(country, country_grades, false);
        country_standart_deviation = calculate_standard_deviation(country, country_grades, country_mean);
        country_smallest = country[0];
        country_biggest = country[country_grades-1];

        // Busca da melhor região e melhor cidade (aquela que tem a melhor média).
   
        for (int i = 0; i < regions_qtd*cities_qtd; ++i) {
            if (city_biggest_mean < cities_mean[i]) {
                city_biggest_mean = cities_mean[i];
                best_city_c = i%cities_qtd; best_city_r = i/cities_qtd;
            }
        }

        //#pragma omp parallel for schedule(static)
        for (int i = 0; i < regions_qtd; ++i)
            if (region_biggest_mean < regions_mean[i]) {
                region_biggest_mean = regions_mean[i];
                best_region = i;
            }




        time2 = MPI_Wtime();

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

        printf("Tempo de resposta sem considerar E/S, em segundos: %.6lfs\n", time2-time1);




    } else {
        
        int total_cities;
        MPI_Bcast(&total_cities, 1, MPI_INT, 0, MPI_COMM_WORLD);
        if ((total_cities < num_procs) && (my_rank >=total_cities)) {
        
            MPI_Finalize();
            exit(0);
        }

        MPI_Recv(&my_range, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        MPI_Recv(&students_qtd, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        int* cities_grades = NULL, test;
        cities_grades = (int*)malloc(students_qtd*sizeof(int));

       
        
        for(int i = 0; i < my_range; i++){
        
            float mean;
            float median;
            float standard_deviation;
            int smallest;
            int biggest;
            
        
            MPI_Recv(cities_grades, students_qtd, MPI_INT, 0, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            mean = calculate_mean(cities_grades, students_qtd);
            //printf("média %f\n", mean);
            MPI_Isend(&mean, 1, MPI_FLOAT, 0, i, MPI_COMM_WORLD, &request);
            
        
            median = calculate_median(cities_grades, students_qtd, true);
            MPI_Isend(&median, 1, MPI_FLOAT, 0, i, MPI_COMM_WORLD, &request);
            
            standard_deviation = calculate_standard_deviation(cities_grades, students_qtd, mean);
            MPI_Isend(&standard_deviation, 1, MPI_FLOAT, 0, i, MPI_COMM_WORLD, &request);

            smallest = cities_grades[0];
            MPI_Isend(&smallest, 1, MPI_INT, 0, i, MPI_COMM_WORLD, &request);
            biggest = cities_grades[students_qtd-1];
            MPI_Isend(&biggest, 1, MPI_INT, 0, i, MPI_COMM_WORLD, &request);    
            
            MPI_Send(cities_grades, students_qtd, MPI_INT, 0, i, MPI_COMM_WORLD);
            
        }

        // Recebendo os dados das regioes para o calculo de suas metricas.
        MPI_Bcast(&regions_qtd, 1, MPI_INT, 0, MPI_COMM_WORLD);
        if ((regions_qtd < num_procs) && (my_rank >=regions_qtd)) {
            
            MPI_Finalize();
            exit(0);
        }

        MPI_Recv(&my_range, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        MPI_Recv(&regions_cols, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        int** region_grades;
        matrix_create(&region_grades, my_range, regions_cols);

        for(int i = 0; i < my_range; i++ ){
            MPI_Recv(region_grades[i], regions_cols, MPI_INT, 0, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        float *regions_mean_child = (float*) malloc (sizeof(float) * my_range);
        float *regions_median_child = (float*) malloc (sizeof(float) * my_range);
        float *regions_standard_deviation_child = (float*) malloc (sizeof(float) * my_range);
        int *regions_smallest_child = (int*) malloc (sizeof(int)* my_range);
        int *regions_biggest_child = (int*) malloc (sizeof(int)* my_range);

        for(int i = 0; i < my_range; i++ ){
            regions_mean_child[i] = calculate_mean(region_grades[i], regions_cols);
            regions_median_child[i] = calculate_median(region_grades[i], regions_cols, false);
            regions_standard_deviation_child[i] = calculate_standard_deviation(region_grades[i], regions_cols, regions_mean_child[i]);
            regions_smallest_child[i] = region_grades[i][0];
            regions_biggest_child[i] = region_grades[i][regions_cols-1];

        }

        //print_matrix(region_grades, my_range, regions_cols);
        
        MPI_Isend(regions_mean_child, my_range, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &request);
        MPI_Isend(regions_median_child, my_range, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &request);
        MPI_Isend(regions_standard_deviation_child, my_range, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, &request);
        MPI_Isend(regions_smallest_child, my_range, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
        MPI_Isend(regions_biggest_child, my_range, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
        
        free(regions_mean_child);
        free(regions_median_child);
        free(regions_standard_deviation_child);
        free(regions_smallest_child);
        free(regions_biggest_child);
        free_matrix(&region_grades, my_range);
        free(cities_grades);
        
        //exit(0);
    }



MPI_Finalize();

return 0;    
}