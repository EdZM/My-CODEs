#include <stdlib.h> // deve ser inclu�da no caso de eu querer alocar memoria heap.
#include <stdio.h>
#include <time.h>

int compare(const void * a, const void * b){ // necessario � fun��o qsort()
    return ( *(int*)a - *(int*)b );
}


int main (int argc,char *argv){

    int n;
    int *counter = NULL;
    float *num = NULL;// se eu mudar o tipo de vari�vel para double por exemplo a ordena��o de qsort nao sai certa.
    srand(time(NULL));

        scanf("%d",&n);

        num = (float *)malloc(sizeof(float)*n); //nao esquecer que (double*) � um CAST e que nao � necess�rio inser�-lo.
        counter = (int *)malloc(sizeof(int)*n);  //as vezes pode ocorrer de o codeblocks emitir um warning sobre esse CAST.

            for (int i = 0; i < n; i++){
                num[i] = rand() % 100; // gera uma lista com n numeros aleatorios entre 0 e 99
                
            }

            qsort (num, n, sizeof(float), compare);

            for (int i = 0; i < n; i++){

                counter[i] = 0;
            }

            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){                    
                    if ( num[i] == num[j] ){

                        counter[i] += 1;
                    }
                }

            }

            printf ("\n");

            for (int i = 0; i < n; i++){
               
               if ( num[i] != num[i+1] )
               printf ("%.1f %d \n", num[i], counter[i]);
            }


free(num);

return 0;
}



// para esse algoritmo ser� necessario ordenar os numeros contidos em *num.
// para contar as ocorrencias de cada numero ,tente usar um ponteiro de contadores
// cada posi��o do vetor apontado por esse ponteiro armazena o numero de vezes em que os numeros dados no inicio,
// agora ordenados,se repetem.
// depois de ordenado o vetor ,compare o primeiro com o segundo e assim sucessivamente,ateh que todos tenham sido comparados
// como o vetor esta ordenado ,fica mais facil a compara��o.
//depois de ordenar e efetuar a contagem , deve-se ,na hora de imprimir o resultado,eliminar as repeti��es.
