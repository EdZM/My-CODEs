#include <stdio.h>
#include <math.h>

int mdc(int a, int b){ 
    return (b == 0)? a : mdc(b,fmod(a,b));
}

int main(int argc,char*argv[]){
    int a, b;
    
    scanf("%d %d", &a, &b);
    printf("%d\n",mdc(a,b));

return 0;
}
