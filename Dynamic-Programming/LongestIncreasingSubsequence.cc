#include <iostream>
using namespace std;

// recursion

int _lis(int arr[], int n, int* max_ref)
{
    if(n == 1)
        return 1;

    int res, max_ending_here = 1;

    for(int i = 1; i < n; i++)
    {
        res = _lis(arr, i, max_ref);
        if(arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }

    if(*max_ref < max_ending_here)
        *max_ref = max_ending_here;

    return max_ending_here;
}

int lis(int arr[], int n)
{
    int max = 1;
    _lis(arr, n, &max);
    return max;
}

// Dynamic Programming
int DP_LIS(int arr[], int n)
{
    int *lis, i, j, max = 0;
    lis = new int[n];

    for(int i = 0; i < n; i++)
        lis[i] = 1;

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(max < lis[i])
            max = lis[i];
    }

    return max;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << DP_LIS(arr, n) << endl;
}