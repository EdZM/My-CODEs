#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]){

    int n;

    scanf("%d",&n);

    double media, desvio_padrao, soma1, soma2;
    double *elementos = NULL;

    elementos = (double*)malloc(sizeof(double) * n);

    srand(time(NULL));

    soma1 = 0;

    for (int i = 0; i < n; i++){
        elementos[i] = rand()%100;
        soma1 += elementos[i];
    }
    
    media = soma1 / n;
    
    soma2 = 0;

    for (int i = 0; i < n ; i++){
        soma2 += pow ((elementos[i] - media), 2);

    }

    soma2 = soma2 / (n);
    desvio_padrao = sqrt(soma2);

    printf("Amostra: ");
    for (int i = 0; i < n ; i++){
        printf("%.4lf ",elementos[i]);
    }

    printf("\nMedia: %.4lf\n", media);
    printf("Desvio Padrao: %.4lf\n", desvio_padrao);

free(elementos);

return 0;
}
