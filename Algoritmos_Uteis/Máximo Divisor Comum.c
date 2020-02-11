#include <stdio.h>
#include <math.h>

int mdc(int a,int b){

     if(b == 0)
        return a;
     else
        return mdc(b,fmod(a,b));

}

int main(int argc,char*argv[]){

 int a,b;
 scanf("%d %d",&a,&b);

 printf("%d",mdc(a,b));


return 0;
}
