#include <stdio.h>
#include <math.h>

int main(int argc , char *argv[]){


  float soma,i,n;

        scanf("%f",&n);


            for (i=0;i<n;i++){

                soma += (1+2*i)/(n-i);

            }

        printf("%.4f",soma);


return 0;
}
