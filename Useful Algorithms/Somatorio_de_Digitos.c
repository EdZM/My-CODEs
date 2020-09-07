#include <stdio.h>
#include <stdlib.h>

int main() {
	char s[100];
	int i, soma, n;

	fgets(s, 100, stdin);//scanf("%s",s) também tem o mesmo efeito

	i=0;
	soma=0;

	while(s[i] != '\n' && s[i] != '\0') {
		n= s[i]-'0'; //converte um char pra int;
		soma += n;
		i++;
	}

	printf("%d\n", soma);

	return 0;
}




/* ANOTAÇÕES
--o n = s[i]-'0';  s[i] é uma string ,logo se nela houver o numero 4 em uma das posições ele estará como 52 ,
                                     pois esse é seu valor correspondente na ASCII. Isso faz com que n=52-48 => n=4,que seria
                                        o 4 como sendo inteiro.
-- o scanf e fgets fazem a mesma coisa ,mas o ultimo analisa tudo aquilo que está dentro da
do vetor string declarado que o usuário digitou no teclado(stdin).

-- += equivale a usar um contador do tipo soma =soma + n ,nesse caso.

-- as instruções dentro do while indicam que o s[i] deve ser diferente de /0 ,pois esse representa sempre o ultimo caracter da
string declarada e diferente também de /n (tem algo a ver com o apertar enter para trocar de linha)
*/
