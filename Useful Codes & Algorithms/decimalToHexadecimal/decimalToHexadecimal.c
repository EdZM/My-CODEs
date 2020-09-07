#include <stdio.h>
#include <math.h>

int main (int argc , char* argv[]){

    int j, quoc, aux;
    long int n;
    int rest[100];

    scanf("%ld",&n);

    if ( n >= 10 && n <= 15 ){                       // essa � uma primeira an�lise para verificar se n � uma das 6 letras da base hexadecimal
        n += 55;                                  // ou um numero entre 0 e 9
        printf("%c",(char)n);

    } else if ( n >= 0 && n <= 9 ){
        printf("%ld",n);
    
    } else {
            j = 1;                                //esse j serve para controlar as divis�es que ser�o feitas at� que o if seja satisfeito e o for possa ser interrompido
            for (int i = 0; i < j ;i++){

                rest[i] = n % 16;
                quoc = ( n - rest[i] )/16;
                if( quoc < 16 ){   //quando o quoc atingir um valor menor que 16 as divis�es devem ser interrompidas
                                        // e o valor desse quoc guardado em aux.
                    aux = quoc;
                    break;
                }
                n = quoc;  //feita a divis�o o n recebe o ultimo quociente obtido
                j++;
            }


            if  (aux <= 15 && aux >= 10){    //esse if � para o caso de o aux ser um numero que corresponda a uma das 6 letras
                                             // da base hexadecimal
                    printf("%c", aux + 55);     //o "+55" garante que letras maiusculas sejam impressas
            } else
                    printf("%d", aux);        // caso o if acima nao seja satisfeito imprima apenas o numero inteiro contido em resto[i]

            j--;
            
            for (j; j >= 0; j--){                   // para que a impress�o saia corretamente ,deve -se imprimir o aux antes de tudo.Feito isso,o vetor
                                                // resto deve ser impresso de tras para frente.
                if (rest[j] <= 15 && rest[j] >= 10){
                    printf("%c",rest[j] + 55);
                } else
                    printf("%d",rest[j]);
            }


    }
    printf("\n");
return 0;
}
