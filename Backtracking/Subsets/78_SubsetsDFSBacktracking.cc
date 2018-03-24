class Solution {
public:
    
    void DFS_Backtracking(vector<int>& nums, int pos, vector<int>& path, vector<vector<int>>& res)
    {
        if(pos == nums.size())
            return;
        
        for(int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            res.push_back(path);
            DFS_Backtracking(nums, i + 1, path, res);
            path.pop_back();
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        vector<int> path;
        
        res.push_back(path);
        DFS_Backtracking(nums, 0, path, res);
        
        return res;
    }
};
