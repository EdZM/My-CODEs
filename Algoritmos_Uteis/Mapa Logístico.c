#include <stdio.h>


int main (){

       int k,t;
       float x[10000],r,y,c;


    scanf("%f %f %d" ,&c,&r,&k);
    x[0]=c;


        for(t=0;t<=k-1;t++){
            x[t+1]=r*x[t]*(1-x[t]);
            printf("%d %f\n",t+1,x[t+1]);
        }








return 0;

}
