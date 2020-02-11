#include <stdio.h>
#include <stdlib.h>
//#include <omp.h>
#include <mpi.h>
#include <time.h>
#include "matrix.h"

#define T_NUM 4

int main(int argc, char* argv[]){



    int regions, cities, students, seed;
    int** matrix;

    scanf("%d",&regions);
    scanf("%d",&cities);
    scanf("%d",&students);
    scanf("%d",&seed);

    matrix_create(&matrix, regions*cities, students);
    generate_matrix(matrix, regions*cities, students, seed);
    print_matrix(matrix, regions*cities, students);


    printf("\n\n\n");

    //TESTE
    int thread_num, num_threads;
    int a = 1;
    srand(time(NULL));

    // inicio da regiao paralela
    #pragma omp parallel num_threads(T_NUM) private(thread_num) firstprivate(a) // private indica que haverá uma copia da variavel para cada uma das threads, sem uma inicialização
        {                                                                   // firstprivate ja copia a variavel com um valor anteriormente inicializado
            thread_num = omp_get_thread_num(); //obtem o valor de uma determinada thread
            num_threads = omp_get_num_threads(); //obtem a quantidade de threads que estão sendo usadas agora
            a = rand()%100; // o valor de a que cada thread armazena é um numero entre 0 e 99

            printf("Hello from thread: %d which contains the a value: %d number of threads beign used: %d\n", thread_num, a, num_threads);
            // LEMBRE-SE que a ordem de impressão dos valores das Threads NÃO indica a ordem em que elas executaram !!
        }


return 0;    
}