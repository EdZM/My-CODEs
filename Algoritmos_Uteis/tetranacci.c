#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double tetranacci(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    if(n == 3)
        return 1;
    if(n >= 4)
        return tetranacci(n-4)+tetranacci(n-3)+tetranacci(n-2)+tetranacci(n-1);

return 0;
}


int main (int argc,char* argv[]){

    int n,i,j,opt;
    scanf("%d %d",&opt,&n);


if(opt==1){
    for (i=0;i<n;i++){
        if(i==n-1){//pula linha quando tiver calculado o ultimo termo(n)
            printf("%.1lf\n",tetranacci(i));
        }else
            printf("%.1lf ",tetranacci(i));
        }
}

if(opt==2){
    double quad=0;
    double media=0.0;

        for (i=0;i<n;i++){
            quad +=pow(tetranacci(i),2);
        }

    media=sqrt(quad/n);
    printf("%.4lf\n",media);
}

if(opt==3){
    double *p=NULL;
    double *q=NULL;
    double media2=0.0;
    int h=n/2;

    p=(double*)calloc(h,sizeof(double));
    q=(double*)calloc(h,sizeof(double));


    for (i=0;i<h;i++){//preenchendo p com a primeira metade da tetranacci
        p[i]=tetranacci(i);
       // printf("%.0lf ",p[i]);
    }

    //printf("\n\n");
    for (j=i;j<n;j++){//preenchendo q com a segunda metade da tetranacci
        q[j]=tetranacci(j);
        //printf("%.0lf ",q[j]);
    }

    for (i=0;i<n;i++){
        media2+=p[i]-q[i];
    }
    printf("%.4lf\n",fabs(media2));
}


return 0;
}
