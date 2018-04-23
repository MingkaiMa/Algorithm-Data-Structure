#include <iostream>
#include <vector>
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
        cout << lis[i] << ", ";
        if(max < lis[i])
            max = lis[i];
    }

    cout << "\n";

    return max;
}


// NlogN

int CeilIndex(vector<int>& v, int l, int r, int key)
{
    while(r - l > 1)
    {
        int m = l + (r - l) / 2;
        if(v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int LIS(vector<int>& v)
{
    if(v.size() == 0)
        return 0;

    vector<int> tail(v.size(), 0);
    int length = 1;

    tail[0] = v[0];

    for(size_t i = 1; i < v.size(); i++)
    {
        if(v[i] < tail[0])
            tail[0] = v[i];

        else if(v[i] > tail[length - 1])
            tail[length++] = v[i];
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];


        cout << "length: " << length << endl;

        cout << "v[i]: " << v[i] << endl;
        for(int i = 0; i < tail.size(); i++)
            cout << tail[i] << ", ";
        cout << endl;

    }

    return length;
}




int main()
{
//    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    cout << DP_LIS(arr, n) << endl;


    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    cout << LIS(arr) << endl;
}