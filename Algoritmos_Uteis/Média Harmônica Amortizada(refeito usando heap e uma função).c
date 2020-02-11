#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double denom (float* T, int N ){

    int i;
    double soma=0;

        for (i=0;i<N;i++){

            soma += 1/(T[i]+1);

        }

return soma;
}



int main(int argc , char* argv[]){

   int N,i,counter=0;
   float *T=NULL;

    scanf("%d",&N);

        T=(float*)calloc (sizeof (float),N);

            for (i=0;i<N;i++){

              scanf("%f",&T[i]);

            }

            printf("%.2f",(N/denom(T,N)) -1);


free(T);
return 0;
}
