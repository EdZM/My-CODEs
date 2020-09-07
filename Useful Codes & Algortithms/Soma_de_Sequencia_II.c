#include <stdio.h>
#include <math.h>

int main(int argc , char *argv[]){


  int n;
  float total1,total2,total,i;

  scanf("%d",&n);

  total1=0;
  total2=0;

  for (i=1;i<=n;i++){

       if (fmod(i,2)== 0){
        total1 += 1/i;
       }
       else
        total2 += 1/i;


  }

  total=total2 -total1;

  printf("%.4f",total);



return 0;
}
