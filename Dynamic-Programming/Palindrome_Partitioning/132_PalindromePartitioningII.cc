class Solution {
public:

    
    int minCut(string s) {
        
        int n = s.size();
        if(n == 0)
            return 0;
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> minArray(n + 1, -1);
        
        for(int i = 0; i < n; i++)
        {
            isPalindrome[i][i] = true;
        }
        
        for(int i = n - 1; i >= 0; i--)
        {
            minArray[i] = minArray[i + 1] + 1;
            for(int j = i + 1; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    if(j == i + 1 || isPalindrome[i + 1][j - 1] == true)
                    {
                        isPalindrome[i][j] = true;
                        if(j == n - 1)
                            minArray[i] = 0;
                        else if(minArray[i] > minArray[j + 1] + 1)
                            minArray[i] = minArray[j + 1] + 1;
                    }
                }
            }
            
        }
        return minArray[0];

    }
};
