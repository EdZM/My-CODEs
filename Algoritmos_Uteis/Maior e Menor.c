#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){

    int n,maior,menor;


    scanf("%d",&n);

    int i=0 ,conjunto[n];

    for(i=0; i<n; i++){

        scanf(" %d",&conjunto[i]);
    }

    maior = conjunto[0];
    menor = conjunto[0];

    for (i=0; i<n; i++) {
        //printf("\n%d", conjunto[i]);
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
