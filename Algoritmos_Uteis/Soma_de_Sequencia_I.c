#include <stdio.h>
#include <math.h>

int main(int argc , char *argv[]){

 int i;
 float soma,n;


   scanf ("%f",&n);

   soma=0;
   for (i=1;i<=n;i++){

      soma += i/(n-i+1);


   }
   printf("%.4f",soma);


   return 0;
   }
