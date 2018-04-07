class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string ret;
        vector<int> letterCount;
        int len = s.size();
        int i = 0, minLetterIndex = 0;
        char ch;
        
        while(len)
        {
            minLetterIndex = 0;
            letterCount.assign(26, 0);
            
            for(i = 0; i < len; i++)
                letterCount[s[i] - 'a']++;
            
            for(i = 0; i < len; i++)
            {
                if(s[i] < s[minLetterIndex])
                    minLetterIndex = i;
                
                letterCount[s[i] - 'a']--;
                
                if(letterCount[s[i] - 'a'] == 0)
                    break;
            }
            
            ret += s[minLetterIndex];
            ch = s[minLetterIndex];
            s = s.substr(minLetterIndex + 1);
            removeLetter(s, ch);
            cout << "s is: " << s << endl;
            len = s.size();
        }
        
        return ret;
    }
    
    void removeLetter(string& s, char ch)
    {
        int len = s.size();
        int i = 0, k = 0;
        
        for(i = 0; i < len; i++)
        {
            if(s[i] != ch)
                s[k++] = s[i];
        }
        s.erase(k, len - k);
    }
};
