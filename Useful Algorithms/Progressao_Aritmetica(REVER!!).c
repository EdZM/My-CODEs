#include <stdio.h>
#include <math.h>

int main(int argc , char *argv[]){

 int a1,r,n;
 double an,sn;

 scanf("%d %d %d",&a1,&r,&n);

 an = a1 + r*(n-1);

 sn = (an + a1)*n/2;


 printf("%.0lf",an);
 printf("\n%.0lf",sn);



 return 0;
 }
