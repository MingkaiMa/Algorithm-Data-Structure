//https://blog.csdn.net/adfsss/article/details/51951658

class Solution {
public:
    int getMoneyAmount(int n) {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        return core(dp, 1, n);
    }
    
    int core(vector<vector<int>>& a, int start, int end){
        int res = INT_MAX;
        if(start >= end)
            return 0;
        
        if(a[start][end] != 0){
            return a[start][end];
        }
        for(int i = start; i < end + 1; i++){
            int temp = i + max(core(a, start, i - 1), core(a, i + 1, end));
            if(temp < res)
                res = temp;
        }
        a[start][end] = res;
        return res;
    }
};
