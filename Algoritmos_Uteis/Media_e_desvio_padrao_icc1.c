#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){

    int n,i;

    scanf("%d",&n);

    double media,desvio_padrao,soma2;
    double *elementos=NULL,soma1;

    elementos=(double*)malloc(sizeof(double)*n);


      i=0;
      soma1=0;

     for (i=0;i<n;i++){
         scanf("%lf",&elementos[i]);
         soma1 += elementos[i];
     }
     media = soma1 / n;
     i=0;
     soma2=0;

     for (i=0;i<n ;i++){
        soma2 += pow ((elementos[i] - media),2);

        }

        soma2=soma2 / (n);

        desvio_padrao=sqrt(soma2);







printf("%.4lf\n",media);
printf("%.4lf",desvio_padrao);


return 0;

}
