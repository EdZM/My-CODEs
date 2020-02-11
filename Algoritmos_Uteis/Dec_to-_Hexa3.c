#include <stdio.h>
#include <math.h>

int main (int argc , char* argv[]){

    int i,j,quociente,aux;
    long int n;
    int resto[100];

    scanf("%ld",&n);

    if (n>=10 && n<=15 ){                       // essa é uma primeira análise para verificar se n é uma das 6 letras da base hexadecimal
        n+=55;                                  // ou um numero entre 0 e 9
        printf("%c",(int)n);
    }else if (n>=0 && n<=9){

        printf("%ld",n);
    }else {
            j=1;                                //esse j serve para controlar as divisões que serão feitas até que o if seja satisfeito e o for possa ser interrompido
            for (i=0;i<j;i++){

                resto[i]= n % 16;
                quociente=(n-resto[i])/16;
                if(quociente<16){               //quando o quociente atingir um valor menor que 16 as divisões devem ser interrompidas
                                                // e o valor desse quociente guardado em aux.
                    aux =quociente;
                    break;
                }
                n=quociente;                     //feita a divisão o n recebe o ultimo quociente obtido
                j++;
            }


            if (aux<=15 && aux>=10){            //esse if é para o caso de o aux ser um numero que corresponda a uma das 6 letras
                                                // da base hexadecimal
                    printf("%c",aux+55);     //o "+55" garante que letras maiusculas sejam impressas
            }else
                    printf("%d",aux);        // caso o if acima nao seja satisfeito imprima apenas o numero inteiro contido em resto[i]

            j--;
            for (j;j>=0;j--){                   // para que a impressão saia corretamente ,deve -se imprimir o aux antes de tudo.Feito isso,o vetor
                                                // resto deve ser impresso de tras para frente.
                if (resto[j]<=15 && resto[j]>=10){
                    printf("%c",resto[j]+55);
                } else
                    printf("%d",resto[j]);
            }


    }
return 0;
}
