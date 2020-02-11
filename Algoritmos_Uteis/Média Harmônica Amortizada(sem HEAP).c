#include <stdio.h>
#include <math.h>


int main(int argc , char* argv[]){

   int N,i,counter=0;
   float T[1000];
   float MAH,aux,x;

   scanf("%d",&N);


   for (i=0;i<N;i++){
      scanf("%f",&T[i]);
      aux += 1/(T[i]+1);
   }

    x=aux;

    MAH=(N/x) -1 ;

    printf("%.2f",MAH);





return 0;
}
