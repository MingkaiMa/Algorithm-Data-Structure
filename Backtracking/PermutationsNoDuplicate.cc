class Solution {
public:
    bool isSwap(vector<int>& nums, int left, int right)
    {
        for(int i = left; i < right; i++)
        {
            if(nums[i] == nums[right])
                return false;
        }
        
        return true;
    }
    
    void core(vector<int>& nums, int start, vector<vector<int>>& L){
        if(start == nums.size() - 1)
        {
            L.push_back(nums);
            return;
        }
        
        for(int i = start; i < nums.size(); i++){
            if(isSwap(nums, start, i)){
                swap(nums[i], nums[start]);
                core(nums, start + 1, L);
                swap(nums[i], nums[start]);
            }
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() <= 0)
            return {};
        
        vector<vector<int>> L;
        core(nums, 0, L);
        return L;
    }
};
