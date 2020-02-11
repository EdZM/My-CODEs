#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ENTER 10 //J� deixa definido que sempre que um 10 for "digitado" ou "percebido" o sistema o entender� como se fosse um ENTER pressionado

char *readLine() {
	char c;
	char *string = NULL;
	int counter = 0;//importante para determinar o tamanho do vetor string


	do {
		c = fgetc(stdin);//o caract�r digitado � proveniente do teclado

		string=(char *)realloc(string,sizeof(char)*(counter+1));//o vetor ser� alocado dinamicamente de acordo com o numero de caracteres digitados
		string[counter++] = c; // a posi��o atual do vetor ser� preenchida com o caract�r digitado.Em seguida o counter � incrementado
	
    } while (c != ENTER);// o vetor ser� preenchido at� que o usu�rio aperte o ENTER ("10" na ASCII )
	string[counter-1] = '\0';

	return string;
}
int main (int argc ,char*argv[]){

	char* string = NULL;
	char string2[10] = "shurables";

	FILE* arq = NULL;

	arq = fopen("arq.bin", "wb");
	string = readLine();	

	for(int i = 0; i < strlen(string); i++){
		fwrite(&string[i], sizeof(char), 1, arq);
	}

	//for (int i = 0; i < 10; i++){
		fwrite(&string2, sizeof(char), 10, arq);
	//}

	return 0;
}
