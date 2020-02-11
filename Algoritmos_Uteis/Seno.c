#include <stdio.h>
#include <math.h>

float fatorial (int n){

    int j;
    float fat=1;

        for (j=1;j<=n;j++){

            fat*=j;
       }


return fat;
}


int main (int argc,char* argv[]){

    int i;
    float seno,seno1=0,seno2=0,x;

    scanf("%f",&x);


        seno1=x;
        for (i=0;i<=299;i++){ //300 iterações

            if ( i%2!=0 ){

                seno1+=pow(x,(1+4*i))/fatorial(1+4*i);

            }else

                seno2+=pow(x,(3+2*i))/fatorial(3+2*i);

        }

        seno=seno1-seno2;
        printf("%.6f",seno);


return 0;       //0.785398
}
