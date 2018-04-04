class Solution {
public:

    vector<vector<string>> res;
    
    
    bool isPalidrome(string s)
    {
        if(s.size() == 0)
            return false;
        
        int emptyFlag = 0;
        
        for(auto& c: s)
        {
            if(c != ' ')
            {
                emptyFlag = 1;
                break;
            }
        }
        
        if(emptyFlag == 0)
            return true;
        
        int i = 0;
        int j = s.size() - 1;
        
        while(i <= j)
        {
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    
    void partitionCore(string s, int startIndex, vector<string>& r)
    {

         if(startIndex == s.size())
         {
             res.push_back(r);
             return;
         }

         for(int i = startIndex + 1; i <= s.size(); i++)
         {
            if(isPalidrome(s.substr(startIndex, i - startIndex)))
            {
                r.push_back(s.substr(startIndex, i - startIndex));
                partitionCore(s, i, r);
                r.pop_back();
            }



        }           
    }
    
    
    vector<vector<string>> partition(string s) {
        
        if(s.size() == 0)
            return {{}};
        
        vector<string> r;
        partitionCore(s, 0, r);
        return res;
    
    }
};
