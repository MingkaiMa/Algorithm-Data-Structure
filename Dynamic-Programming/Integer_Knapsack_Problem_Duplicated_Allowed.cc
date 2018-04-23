#include <iostream>

using namespace std;

int DP(int value[], int weight[], int n, int C, vector<int>& backtrack)
{
    int* M = new int[C + 1];
    M[0] = 0;
    int i, j, tmp, pos;
    for(i = 1; i <= C; i++)
    {
        temp = INT_MIN;
        
        M[i] = M[i - 1];
        pos = i - 1;
        for(j = 0; j < n; j++)
        {
            if(i >= weight[j])
                tmp = M[i - weight[j]] + value[j];
            if(tmp > M[i])
            {
                M[i] = temp;
                pos = i - weight[j];
            }

        }

        backtrack.push_back(pos);

    }
    int res = M[C];
    delete[] M;
    return res;
}