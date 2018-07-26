class Solution {
public:
    void core(vector<int>& nums, int start, vector<vector<int>>& L) {
        if(start == nums.size() - 1){
            L.push_back(nums);
            return;
        }
        
        for(int i = start; i < nums.size(); i++){
            swap(nums[i], nums[start]);
            core(nums, start + 1, L);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() <= 0)
            return {};
        
        vector<vector<int>> L;
        core(nums, 0, L);
        return L;
    }
};
