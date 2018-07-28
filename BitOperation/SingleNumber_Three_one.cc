class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> v(32, 0);
     
        for(int i = 0; i < nums.size(); i++){
            int bitMask = 1;
            for(int j = 31; j >= 0; j--){
                int bit = bitMask & nums[i];
                if(bit)
                    v[j] += 1;
                bitMask = bitMask << 1;
            }
        }
        

        
        int res = 0;

        for(int i = 0; i < 32; i++){
            res = res << 1;
            res += v[i] % 3;
            cout << v[i] << ", ";
        }
        
        return res;
    }
};
