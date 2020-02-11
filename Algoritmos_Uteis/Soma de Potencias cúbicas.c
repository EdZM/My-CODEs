#include <stdio.h>

int main(int argc, char *argv[]){

    int m,i,j,p,d;


    scanf("%d", &m);

    for(i = 1; i <= m; i++){ //cada vez que o for é executado ,ele imprime uma linha com os numeros correspondentes a ela
                            //O primeiro elemento é impresso pelo primeiro for .Os demais ,quando houverem,
        p = i*(i - 1)+1;    // sao impressos pelo 2º for (o que esta dentro do 1º).

        printf("%d",p);

        d = p + 2;//antes de d ser impresso ele é incrementado com o valor de p adicionado ao 2

        for(j = 1; j < i; j++){//quando i=1 esse for será ignorado e o d nao será impresso na tela
                                //o d só começará a ser impresso quando i>=2.

            printf(" %d",d);//o uso do espaço no printf é para que a saída fique igual ao que o exercício pede.
            d += 1;//Após ser impresso d é incrementado em 2 unidades.
        }
        if(i < m){ //ao final de cada for confira se o inteiro i é menor que o numero m digitado inicialmente
                   // em caso afirmativo ,pule uma linha(se nao fizer isso todos os numeros serão impressos na mesma linha
                   //nao importando qual seja o m.
            printf("\n");
        }


    }
return 0;
}
