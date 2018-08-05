class Solution {
public:
    vector<int> a;
    Solution(vector<int> nums) {
        a = nums;
    }
    
    int pick(int target) {
        int index = -1;
        
        int cnt = 1;
        
        int i = 0;
        for(; i < a.size(); ++i){
            if(a[i] == target){
                if(rand() % cnt == 0)
                    index = i;
                ++cnt;
            }
        }
        
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
