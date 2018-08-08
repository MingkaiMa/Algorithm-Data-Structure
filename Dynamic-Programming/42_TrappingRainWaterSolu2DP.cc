class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() <= 2)
            return 0;
        
        int res = 0;
        int size = height.size();

        vector<int> left_max(size, 0);
        vector<int> right_max(size, 0);
        
        left_max[0] = height[0];
        
        for(int i = 1; i < size; ++i)
            left_max[i] = max(height[i], left_max[i - 1]);
        
        right_max[size - 1] = height[size - 1];
        
        for(int i = size - 2; i >= 0; --i)
            right_max[i] = max(height[i], right_max[i + 1]);
        
        for(int i = 1; i < size - 1; ++i)
            res += min(left_max[i], right_max[i]) - height[i];
        
        return res;
    }
};
