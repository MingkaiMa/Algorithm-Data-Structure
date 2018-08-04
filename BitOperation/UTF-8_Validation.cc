class Solution {
public:
    
    bool isCheck(int& num){

        
        int n1 = num & 128;
        int n2 = num & 64;
        
        if(n1 == 128 && n2 == 0)
            return true;

        return false;
    }
    
    bool validUtf8(vector<int>& data) {
        if(data.size() == 0)
            return false;
        

        int i = 0;
        
        int bitMask = 128;
        
        int endIndex = data.size() - 1;
        
        while(i < data.size()){
            int infoNb = data[i];
            int nbBits = 0;
            bitMask = 128;
            while(infoNb & bitMask){
                nbBits++;
                bitMask = bitMask >> 1;
            }
            
            if(nbBits == 0)
            {
                ++i;
                continue;
            }
            
            
            if(nbBits == 1){
                return false;
            }
            
            if(nbBits > 4)
                return false;
            
            
            int start = i;
            int end = i + nbBits - 1;
            
            if(end > endIndex)
                return false;
            
            for(int j = i + 1; j <= end; j++){
                if(!isCheck(data[j]))
                    return false;
            }
            
            i = end + 1;
            
        }
        
        return true;
    }
};
