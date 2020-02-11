#include <stdio.h>
#include <math.h>

int main (int argc , char*argv[]){ //o problema foi resolvido usando o crivo de eratostenes

int n,i,j;

    printf("Escolha um numero:  ");
    scanf("%d",&n);
    int lista[n],raiz=sqrt(n);  // A vari�vel "raiz" recebe a parte inteira da raiz quadrada do numero N digitado
                                //Exemplo: se N=30 ,raiz=5
                                //a vari�vel "raiz" serve para delimitar quais os multiplos que ser�o eliminados(nesse caso zerados) do vetor lista

     if(n>=2 && n<=1000){       // o N deve estar entre 2 e 1000

        for (i=2;i<=n;i++){
            lista[i]=i;         // preenche a lista com numeros consecutivos de 2 at� o N digitado pelo usu�rio

                for (j=2;j<=raiz;j++){
                    if (lista[i]%j==0 && lista[i]!=j) // se a posi��o da lista tiver um multiplo de j E for um numero diferente de j a posi��o da lista
                        lista[i]=0;                   // ser� zerada
                }
        }
        for (i=2;i<=n;i++){
                if(lista[i]!=0)
                    printf("%d Eh primo\n",lista[i]);          // S� ser�o impressas as posi��es da lista que n�o foram zeradas pelo processo acima
        }
     }
     else
        printf("Numero invalido"); // � o que ser� impresso na tela caso o N digitado seja maior que 1000 ou menor que 2

return 0;
}
