#include <stdio.h>
#include <math.h>



int main (int argc , char * argv[]){

   int a,b;
   double numero,c,i;
   double parte1=0.0,parte2=0.0;


   for(i=1000;i<=9999;i++){
       numero=i;
       parte2 = modf(i/100, &parte1)*100;

       a=parte1;
       b=parte2;
       c=sqrt(i);

        if (c==a + b){

           printf("%.0f\n",i);
           }


   }




return 0;

}
