#include <stdio.h>


int horner_rule(int* A, int x, int n){

    int result = 0;

    for(int j = n - 1; j >= 0; --j) {
        result = result * x + A[j];
    }
    return result;
}

int main(){

    //calculate 1 + 2 * (x) + 3 * (x ** 2) + 4 * (x ** 3) + 5 * (x ** 4) + 6 * (x ** 5)
    //x = 2, n = 6
    //time complexity: O(n)
    //naive time complexity: O(n2)

    int A[6] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    int result = horner_rule(A, 2, n);
    printf("%d\n", result);
}