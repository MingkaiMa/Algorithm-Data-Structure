#include <iostream>


void Recursive_Activity_Selector(int *s, int *f, int k, int n, vector<int>& Result)
{
    int m = k + 1;
    while(m <= n && s[m] < f[k])
    {
        m += 1;
    }

    if(m <= n)
    {
        Result.push_back(m);
        Recursive_Activity_Selector(s, f, m, n);
    }
}
void Greedy_Activity_Selector(int *s, int *f, vector<int>& Result, int n)
{
    //n = s.size()

    Result.push_back(0);

    for(int m = 1; m < n; m++)
    {
        if(s[m] >= f[k])
        {
            R.push_back(m);
            k = m;
        }
    }
}