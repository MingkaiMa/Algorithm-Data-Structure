#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void genshuf(int m, int n)
{
    int i, j;
    int* x = new int[n];
    for(int i = 0; i < n; i++)
        x[i] = i;

    for(i = 0; i < m; i++)
    {
        j = rand() % (n - 1 - i) + i;
        int t = x[i];
        x[i] = x[j];
        x[j] = t;
    }

    sort(x, x + m);
    for(i = 0; i < m; i++)
        cout << x[i] << ", ";
    cout << "\n";
}

int main()
{
    genshuf(20, 200);
}