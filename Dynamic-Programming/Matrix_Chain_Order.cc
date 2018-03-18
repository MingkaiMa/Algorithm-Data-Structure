#include <iostream>
#define  MAX 300000

using namespace std;

int** Matrix_Chain_Order(int *p, int length){

    int n = length - 1;
    int **m = new int*[n];
    for(int i = 0; i < n; i++){
        m[i] = new int[n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m[i][j] = 0;
        }
    }

    int **s = new int*[n];
    for(int i = 0; i < n; i++){
        s[i] = new int[n];
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            s[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        m[i][i] = 0;
    }

    int j, q;

    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
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



    for(int i = 0; i < n; i++){
        for(int jj = 0; jj < n; jj++){
            cout << m[i][jj] << " ";
        }
        cout << endl;
    }


    for(int i = 0; i < n; i++){
        for(int jj = 0; jj < n; jj++){
            cout << s[i][jj] << " ";
        }
        cout << endl;
    }

    return s;

}



void print_optimal_parens(int **s, int i, int j){
    if(i == j){
        cout << "Matrix " << i;
    }
    else{
        cout << "(";
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        cout << ")";


    }

}

int main(){

    int p[7] = {30, 35, 15, 5, 10, 20, 25};
    int **s = Matrix_Chain_Order(p, 7);
    print_optimal_parens(s, 0, 5);

}