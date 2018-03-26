class Solution {
public:
    int numDecodings(string s) {
        if(s.size() <= 0)
            return 0;
        
        if(s.size() == 1)
        {
            if(s[0] == '0')
                return 0;
            
            return 1;
        }
        
        
        int Len = s.size();
        
        int *array = new int[Len];
        
        for(int i = 0; i < Len; i++)
            array[i] = 0;
        
      
        for(int i = Len - 1; i >= 0; i--)
        {
            
            if(s[i] == '0')
            {
                array[i] = 0;
                continue;
            }
            
            int count = 0;
            
            
            if(i < Len - 1)
                count = array[i + 1];
            else
                count = 1;
            
            if(i < Len - 1)
            {
                int bit1 = s[i] - '0';
                int bit2 = s[i + 1] - '0';
                int compareNb = 10 * bit1 + bit2;
                
                if(compareNb >= 10 && compareNb <= 26)
                {
                    if(i < Len - 2)
                        count += array[i + 2];
                    else
                        count += 1;
                }
            }
            
            array[i] = count;
        }
        
        int res = array[0];
        delete[] array;
        return res;
        
    }
};
