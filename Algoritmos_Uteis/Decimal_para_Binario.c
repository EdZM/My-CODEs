#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main (int argc ,char* argv[]){

    int i,n,aux;
    int *resto;

    scanf("%d",&n);

    resto=(int*)calloc(32,sizeof(int));// o tamanho de resto é de 32bits.

    for(i=0;i<32;i++){

        resto[i]=fmod(n,2);//cada posição do vetor resto  recebe o resto da divisão de n por 2

        aux=(n-resto[i])/2;// quando n assumir valor 1 ,o valor de aux será 0,5, mas como aux é variavel inteira
                           // a ele será atribuído o valor 0 .
        n=aux;// essa linha serve para dar continuidade ao processo de conversão já que altera o valor de n,dando
              // sequencia as divisões.


    }

    for(i=31;i>=0;i--){  //esse for imprime o vetor resto de tras para frente ,de tal forma a ficar de acordo com o exercício

      printf("%d",resto[i]);//lembrar que,nesse caso, quando dentro do printf há somente a mascara da variavel,os numeros
                            //impressos estarão um do lado do outro.


    }


return 0 ;
}
