class Solution {
public:
    vector<int> original;
    vector<int> shuffleV;
    Solution(vector<int> nums) {
        original = nums;
        shuffleV = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = original.size() - 1; i >=0; i--){
            int pos = rand() % (i + 1);
            swap(shuffleV[pos], shuffleV[i]);
        }
        return shuffleV;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
