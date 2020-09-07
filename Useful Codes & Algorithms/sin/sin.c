#include <stdio.h>
#include <math.h>

float fatorial (int n){
    return ( n == 1 || n == 0 )? 1 : n * fatorial(n-1);

}

int main (int argc,char* argv[]){

    float seno, seno1 = 0, seno2 = 0, x;
    float grad;

    scanf("%f", &grad);

    x = grad * (float)( (3.141592) / 180 ); // conversao para radianos

    seno1 = x;
    for (int i = 0; i <= 299; i++){ //300 itera��es

        if ( i % 2 != 0 ){
            seno1 += pow(x,(1 + (4 * i))) / fatorial(1 + (4 * i));

        } else
            seno2 += pow(x,(3 + (2 * i))) / fatorial(3 + (2 * i));

    }

    seno = seno1 - seno2;
    printf("sen(%.0f):%.6f\n",grad ,seno);


return 0;       
}
