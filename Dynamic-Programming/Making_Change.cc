#include <iostream>

using namespace std;


// Recursion

int minCoins(int coins[], int m, int V)
{
    if(V == 0)
        return 0;

    int res = INT_MAX;

    for(int i = 0; i < m; i++)
    {
        if(coins[i] <= V)
        {
            int sub_res = minCoins(coins, m, V - coins[i]);

            if(sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }

    return res;
}

// Dynamic Programming

int DP_minCoins(int coins[], int m, int V)
{
    int* table = new int[V + 1];

    table[0] = 0;

    for(int i = 1; i < V + 1; i++)
        table[i] = INT_MAX;

    for(int i = 1; i < V + 1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(coins[j] <= i)
            {
                int sub_res = table[i - coins[j]];
                if(sub_res != INT_MAX && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
        }
    }

    for(int i = 0; i < V + 1; i++)
        cout << table[i] << ", ";
    cout << endl;
    return table[V];
}

int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << DP_minCoins(coins, m, V) << endl;
}