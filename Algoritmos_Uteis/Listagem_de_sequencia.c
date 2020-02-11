#include <stdlib.h> // deve ser incluída no caso de eu querer alocar memoria heap.
#include <stdio.h>

int compare(const void * a, const void * b)// necessario à função qsort()
{
  return ( *(int*)a - *(int*)b );
}


int main (int argc,char *argv){

    int i,n,j;
    int *counter=NULL;
    float *num=NULL;// se eu mudar o tipo de variável para double por exemplo a ordenação de qsort nao sai certa.

        scanf("%d",&n);

        num=(float *)malloc(sizeof(float)*n); //nao esquecer que (double*) é um CAST e que nao é necessário inserí-lo.
        counter=(int *)malloc(sizeof(int)*n);  //as vezes pode ocorrer de o codeblocks emitir um warning sobre esse CAST.

            for (i=0;i<n;i++){

                scanf("%f",&num[i]);

            }

            qsort (num, n, sizeof(float), compare);

            for (i=0;i<n;i++){

                counter[i]=0;

            }

            for (i=0;i<n;i++){
                for (j=0;j<n;j++){

                    if ( num[i]==num[j] ){

                        counter[i]+=1;
                    }
                }

            }

            printf ("\n");

            for (i=0; i<n; i++){

               if ( num[i]!=num[i+1] )
               printf ("%.1f %d \n",num[i],counter[i]);
            }


free(num);

return 0;
}



// para esse algoritmo será necessario ordenar os numeros contidos em *num.
// para contar as ocorrencias de cada numero ,tente usar um ponteiro de contadores
// cada posição do vetor apontado por esse ponteiro armazena o numero de vezes em que os numeros dados no inicio,
// agora ordenados,se repetem.
// depois de ordenado o vetor ,compare o primeiro com o segundo e assim sucessivamente,ateh que todos tenham sido comparados
// como o vetor esta ordenado ,fica mais facil a comparação.
//depois de ordenar e efetuar a contagem , deve-se ,na hora de imprimir o resultado,eliminar as repetições.
