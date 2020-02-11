#include <stdio.h>
#include <math.h>

int MMC(int a,int b){

    int maior,i;

    maior=fmax(a,b);// necessario para delimitar o alcance do laço e para que a função nao fique sendo chamada infinitamente

    if (a == b && b == 1) {
		return 1;
	}

    for (i=2;i<=maior;i++){

        if (fmod(a,i)==0 && fmod(b,i)==0){//verificando se i é multiplo de a e b
            return MMC(a/i, b/i) * i;

        }else if (fmod(a,i) != 0 && fmod(b,i) == 0) {
			return MMC(a, b/i) * i;


		} else if (fmod(a,i) == 0 && fmod(b,i) != 0) {
			return MMC(a/i, b) * i;

		}

    }

}


int main(int argc,char*argv[]){

    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",MMC(a,b));

return 0;
}

