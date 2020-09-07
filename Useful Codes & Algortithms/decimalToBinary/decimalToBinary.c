#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (int argc ,char* argv[]){

    int n, aux;
    int *rest;

    scanf("%d",&n);

    rest = (int*)calloc(32,sizeof(int)); // o tamanho de resto � de 32bits.

    for(int i = 0; i < 32; i++){
        rest[i] = fmod(n,2);   //cada posi��o do vetor resto  recebe o resto da divis�o de n por 2
        aux = ( n - rest[i] )/2;   // quando n assumir valor 1 ,o valor de aux ser� 0,5, mas como aux � variavel inteira
                                    // a ele ser� atribu�do o valor 0 .
        
        n = aux;    // essa linha serve para dar continuidade ao processo de convers�o j� que altera o valor de n,dando
                    // sequencia as divis�es.
    }

    for(int i = 31; i >= 0; i--){  //esse for imprime o vetor resto de tras para frente ,de tal forma a ficar de acordo com o exerc�cio
      printf("%d",rest[i]);//lembrar que,nesse caso, quando dentro do printf h� somente a mascara da variavel,os numeros
                            //impressos estar�o um do lado do outro.


    }
    printf("\n");

free(rest);

return 0 ;
}
