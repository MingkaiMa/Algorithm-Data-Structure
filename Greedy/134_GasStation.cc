class Solution {
public:
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<int> rem(gas.size());
        
        int totalrem = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            rem[i] = gas[i] - cost[i];
            totalrem += rem[i];
        }
        
        if(totalrem < 0)
            return -1;
        
        
        int l = 0;
        int sum = 0;
        
        for(int i = 0; i < rem.size(); i++)
        {
            sum += rem[i];
            if(sum < 0)
            {
                sum = 0;
                l = i + 1;
            }
        }
        
        return l;
    }
};
