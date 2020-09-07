#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]){

    int n, maior, menor;

    scanf("%d",&n);

    int conjunto[n];
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        conjunto[i] = rand()%100;
        
    }

    maior = conjunto[0];
    menor = conjunto[0];

    for (int i = 0; i < n; i++) {
        if(conjunto[i] > maior) {
            maior = conjunto[i];
        }
        if(conjunto[i] < menor) {
            menor = conjunto[i];
        }
    }

    printf("max: %d\nmin: %d\n", maior, menor);

    return(0);
}
