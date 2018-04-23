#include <iostream>

using namespace std;


// Recursion
int count(int S[], int m, int n)
{
    if(n == 0)
        return 1;

    if(n < 0)
        return 0;


    if(m <= 0 && n >= 1)
        return 0;

    return count(S, m - 1, n) + count(S, m, n - S[m - 1]);
}

// Dynamic Programming

int DP_count(int S[], int m, int n)
{
    int i, j, x, y;

    int table[n + 1][m];

    for(i = 0; i < m; i++)
        table[0][i] = 1;

    for(i = 1; i < n + 1; i++)
    {
        for(j = 0; j < m; j++)
        {
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
            y = (j >= 1)? table[i][j-1]: 0;
            table[i][j] = x + y;
        }
    }

    return table[n][m - 1];
}


// DP2  1-D array

int DP_1D(int S[], int m, int n)
{
    int* table = new int[n + 1];

    for(int i = 0; i < n + 1; i++)
        table[i] = 0;


    table[0] = 1;

    for(int i = 0; i < m; i++)
    {
        for(int j = S[i]; j <= n; j++)
            table[j] += table[j - S[i]];

        cout << "i: " << i << " S[i]: "<< S[i] << endl;
        for(int ii = 0; ii < n + 1; ii++)
        {
            cout << table[ii] << ", ";
        }
        cout << endl;
    }
    return table[n];
}


int main()
{
    cout << "efe\n";
    int arr[] = {1, 2, 3};
    int m = sizeof(arr) / sizeof(arr[0]);
    cout << DP_1D(arr, m, 4) << endl;
}