#include <stdio.h>
#include <stdlib.h>
#define Diag 1
#define Up 2
#define Left 3

int** LCS_Length(char *X, char *Y, int m, int n){

    int **c = malloc(sizeof(int *) * (m + 1));

    for(int i = 0; i <= m; i++){
        c[i] = malloc(sizeof(int) * (n + 1));
    }


    int **b = malloc(sizeof(int *) * (m + 1));

    for(int i = 0; i <= m; i++){
        b[i] = malloc(sizeof(int) * (n + 1));
    }

    for(int i = 0; i < m + 1; i++){
        for(int j = 0; j < n + 1; j++){
            c[i][j] = 0;
        }
    }



    for(int i = 0; i < m + 1; i++){
        for(int j = 0; j < n + 1; j++){
            b[i][j] = 0;
        }
    }




    for(int i = 1; i < m + 1; i++){

        for(int j = 1; j < n + 1; j++){
            if(X[i - 1] == Y[j - 1]){
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = Diag;
            }
            else if(c[i - 1][j] >= c[i][j - 1]){
                c[i][j] = c[i - 1][j];
                b[i][j] = Up;
            }
            else{
                c[i][j] = c[i][j - 1];
                b[i][j] = Left;
            }

        }


    }

    for(int i = 0; i < m + 1; i++){
        for(int j = 0; j < n + 1; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("**********\n");
    for(int i = 0; i < m + 1; i++){
        for(int j = 0; j < n + 1; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return b;

}

void PRINT_LCS(int **b, char *X, int i, int j){
    if(i == 0 || j == 0){
        return;
    }

    if(b[i][j] == Diag){
        PRINT_LCS(b, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if(b[i][j] == Up){
        PRINT_LCS(b, X, i - 1, j);
    }
    else{
        PRINT_LCS(b, X, i, j - 1);
    }

}



int main(){

    char X[7] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char Y[6] = {'B', 'D', 'C', 'A', 'B', 'A'};
    int **b = LCS_Length(X, Y, 7, 6);
    PRINT_LCS(b, X, 7, 6);

}