#include <stdio.h>
#include <stdlib.h>
#define  MAX 300000

int** Matrix_Chain_Order(int *p, int length){
    int n = length - 1;
    printf("%d\n", n);
    int **m = malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        m[i] = malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m[i][j] = 0;
        }
    }

    int **s = malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        s[i] = malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            s[i][j] = -1;
        }
    }




    for(int i = 0; i < n; i++){
        m[i][i] = 0;
    }

    printf("*******1\n");

    int j, q;
    for(int l = 2; l <= n; l++){

        for(int i = 0; i <= n - l; i++){

            j = i + l - 1;
            m[i][j] = MAX;
            for(int k = i; k < j; k++){
                q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }

        }
    }

    printf("*******2\n");

    for(int i = 0; i < n; i++){
        for(int jj = 0; jj < n; jj++){
            printf("%d ", m[i][jj]);
        }
        printf("\n");
    }


    for(int i = 0; i < n; i++){
        for(int jj = 0; jj < n; jj++){
            printf("%d ", s[i][jj]);
        }
        printf("\n");
    }

    return s;
}

void print_optimal_parens(int **s, int i, int j){

    if(i == j){
        printf("Matrix %d", i);
    }
    else{
        printf("(");
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        printf(")");
    }

}

int main(){

    int p[7] = {30, 35, 15, 5, 10, 20, 25};
    int **s = Matrix_Chain_Order(p, 7);

    print_optimal_parens(s, 0, 5);

}