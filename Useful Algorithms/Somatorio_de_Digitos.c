#include <stdio.h>
#include <stdlib.h>

int main() {
	char s[100];
	int i, soma, n;

	fgets(s, 100, stdin);//scanf("%s",s) tamb�m tem o mesmo efeito

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




/* ANOTA��ES
--o n = s[i]-'0';  s[i] � uma string ,logo se nela houver o numero 4 em uma das posi��es ele estar� como 52 ,
                                     pois esse � seu valor correspondente na ASCII. Isso faz com que n=52-48 => n=4,que seria
                                        o 4 como sendo inteiro.
-- o scanf e fgets fazem a mesma coisa ,mas o ultimo analisa tudo aquilo que est� dentro da
do vetor string declarado que o usu�rio digitou no teclado(stdin).

-- += equivale a usar um contador do tipo soma =soma + n ,nesse caso.

-- as instru��es dentro do while indicam que o s[i] deve ser diferente de /0 ,pois esse representa sempre o ultimo caracter da
string declarada e diferente tamb�m de /n (tem algo a ver com o apertar enter para trocar de linha)
*/
