#include <stdio.h>
#include <math.h>

   int main ()
  {
     int a,b,c;
     scanf("%d %d %d",&a,&b,&c);

    if(a>b&&a>c, pow(a,2) == pow(b,2) + pow(c,2)){
        printf("SIM");
    }
    else if(b>a&&b>c,pow(b,2) == pow(a,2) + pow(c,2)){
        printf("SIM");
    }
    else if (c>b&&c>a,pow(c,2) == pow(b,2) + pow(a,2) ){
        printf("SIM");
    }
    else
        printf("NAO");


    return(0);



  }
