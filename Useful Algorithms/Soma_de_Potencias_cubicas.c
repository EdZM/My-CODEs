#include <stdio.h>

int main(int argc, char *argv[]){

    int m,i,j,p,d;


    scanf("%d", &m);

    for(i = 1; i <= m; i++){ //cada vez que o for � executado ,ele imprime uma linha com os numeros correspondentes a ela
                            //O primeiro elemento � impresso pelo primeiro for .Os demais ,quando houverem,
        p = i*(i - 1)+1;    // sao impressos pelo 2� for (o que esta dentro do 1�).

        printf("%d",p);

        d = p + 2;//antes de d ser impresso ele � incrementado com o valor de p adicionado ao 2

        for(j = 1; j < i; j++){//quando i=1 esse for ser� ignorado e o d nao ser� impresso na tela
                                //o d s� come�ar� a ser impresso quando i>=2.

            printf(" %d",d);//o uso do espa�o no printf � para que a sa�da fique igual ao que o exerc�cio pede.
            d += 1;//Ap�s ser impresso d � incrementado em 2 unidades.
        }
        if(i < m){ //ao final de cada for confira se o inteiro i � menor que o numero m digitado inicialmente
                   // em caso afirmativo ,pule uma linha(se nao fizer isso todos os numeros ser�o impressos na mesma linha
                   //nao importando qual seja o m.
            printf("\n");
        }


    }
return 0;
}
