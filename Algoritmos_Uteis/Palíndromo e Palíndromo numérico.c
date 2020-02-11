#include <stdlib.h>
#include <string.h>
#include <stdio.h>



char *readLine(){


    char c;
	char *string = NULL; //se nao zerar ,dá segmentation fold
	int counter = 0;

    do{
      c = fgetc(stdin);
      string=(char*)realloc(string,sizeof(char)*(counter +1));
      string[counter++]=c;

    }while(c!= 10);
    string[counter - 1]='\0';

    return string;

}

int main (int argc , char* argv[]){

    int i,j;
    char *string;



   string = readLine ();
   i=0;
   j=strlen(string)-1;

   while (i<j){
      if (string[i]==string[j]){
      i++;
      j--;
      }

      else{
        printf("NAO");
        return 0;
      }
   }

     printf("SIM");
     free(string);






return 0 ;

}
