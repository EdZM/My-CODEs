#include <stdio.h>
#include <stdlib.h>

int **cria_matriz(int n){

    int **m,i;

    m=(int**)calloc(n,sizeof(int*));

        for (i=0;i<n;i++){

            m[i]=(int*)calloc(n,sizeof(int));

        }

return m;
}

void le_matriz(int **m,int n){

    int i,j;

         for (i=0;i<n;i++){

            for (j=0;j<n;j++){

                scanf("%d",&m[i][j]);

            }
         }

}

int main (int argc, char* argv[]){

    int i,j,ord;
    int magic_counter=0;
    int *rows_sum=NULL;
    int *cols_sum=NULL;
    int **mat;

        scanf ("%d",&ord);

            mat = cria_matriz(ord);
            le_matriz(mat,ord);

            int diagp_sum = 0;
            int diags_sum = 0;
            rows_sum =(int *) calloc(ord,sizeof(int *));
            cols_sum =(int *) calloc(ord,sizeof(int *));

            for(i = 0;i < ord; ++i){

                diagp_sum += mat[i][i];
                diags_sum += mat[ord-1-i][i];

                for(j = 0;j < ord; ++j){

                    rows_sum[i] += mat[i][j];
                    cols_sum[j] += mat[j][i];

                }

            }

            for(i = 0;i < ord; ++i){

                if ( diagp_sum==diags_sum && diagp_sum==rows_sum[i] && diagp_sum==cols_sum[i] ){

                    magic_counter++;

                }

            }

            if ( magic_counter==ord ){

                printf("SIM");

            }else

                printf("NAO NAO NAO GULOSO");



return 0;
}

