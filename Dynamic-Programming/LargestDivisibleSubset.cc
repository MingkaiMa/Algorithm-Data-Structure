#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void LargestDivisible(vector<int>& nums) {

    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    vector<int> prev(n, -1);

    int max_end = 0;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(nums[i] % nums[j] == 0)
            {
                if(dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }

        if(dp[max_end] < dp[i])
            max_end = i;
    }

    for(int ii = 0; ii < n; ii++)
    {
        cout << prev[ii] << ", ";
    }
    cout << endl;

    int k = max_end;
    cout << "k is : " << k << endl;

    vector<int> res;

    while(k >= 0)
    {
        //cout << nums[k] << " ";
        res.push_back(nums[k]);
        k = prev[k];
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 17, 4, 8};
    LargestDivisible(arr);
}