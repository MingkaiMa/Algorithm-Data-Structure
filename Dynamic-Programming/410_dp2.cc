#include <iostream>
#include <vector>

using namespace std;

int splitArray(vector<int>& nums, int m) {

    
    int n = nums.size();
    vector<int> sums(n + 1, 0);
    for(int i = 0; i < n; ++i)
        sums[i + 1] = sums[i] + nums[i];


    for(auto& nn: nums)
        cout << nn << ", ";
    cout << endl;

    for(auto& ss: sums)
        cout << ss << ", ";
    cout << endl;


    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i)
        dp[i] = sums[n] - sums[i];

    for(auto& d: dp)
        cout << d << ", ";
    cout << endl;

    for(int s = 1; s < m; ++s){
        for(int i = 0; i < n - s; ++i){
            dp[i] = INT_MAX;
            for(int j = i + 1; j <= n - s; ++j){
                cout << "s: " << s << " i: " << i << " j: " << j << endl;
                int t = max(dp[j], sums[j] - sums[i]);
                if(t <= dp[i])
                    dp[i] = t;
                else
                    break;
            }
        }
    }


    return dp[0];
}

int main(){
    vector<int> nums = {7,2,5,10,8};
    int m = 2;

    cout << splitArray(nums, m) << endl;
}