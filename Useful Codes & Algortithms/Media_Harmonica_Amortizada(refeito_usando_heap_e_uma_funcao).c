#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double denom (float* T, int N ){

    double soma = 0;

    for (int i=0; i < N; i++){
        
        soma += 1 / (T[i] + 1);
    }

return soma;
}



int main(int argc , char* argv[]){

    int N, counter = 0;
    float *T = NULL;

    srand(time(NULL));

    scanf("%d",&N);

    T = (float*)calloc (sizeof (float), N);

    for (int i = 0; i < N; i++){
         T[i] = rand()%10;

    }

    printf("Amostra: ");
    for (int i = 0; i < N ; i++){
       printf("%f ",T[i]);
    }

    printf("\nMedia Harmonica: %.2f\n",( N / denom(T,N) ) - 1);


free(T);
return 0;
}
