#include <stdio.h>
#include <math.h>

int main (int argc , char*argv[]){ // o problema foi resolvido usando o crivo de eratostenes

    int n;

    printf("Type a number:  ");
    scanf("%d",&n);
    
    int list[n], raiz = sqrt(n);    // A variavel "raiz" recebe a parte inteira da raiz quadrada do numero N digitado
                                    //Exemplo: se N=30 ,raiz=5
                                    //a variavel "raiz" serve para delimitar quais os multiplos que ser�o eliminados(nesse caso zerados) do vetor list

    if(n >= 2 && n <= 1000){       // o N deve estar entre 2 e 1000
        for (int i = 2; i <= n; i++){
            list[i] = i;            
            for (int j = 2; j <= raiz; j++){
                if (list[i] % j == 0 && list[i] != j)  // se a posi��o da list tiver um multiplo de j E for um numero diferente de j a posi��o da list
                    list[i] = 0;                       // ser� zerada
            }
        }
        for (int i = 2; i <= n; i++){
            if(list[i] != 0)
                printf("%d Is Prime\n",list[i]);
        }
    
    } else
        printf("Invalid number!"); 

return 0;
}
