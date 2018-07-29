class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long long nn = N;
        if(A == B || B % A == 0){
            long long res = A * nn;
            res = res % int(pow(10, 9) + 7);
            return res;
        }
        
        if(A % B == 0){
            long long res = B * nn;
            res = res % int(pow(10, 9) + 7);
            return res; 
        }
        
        int ggcd = gcd(A, B);
        int lcp = A * B / ggcd;
        
        //cout << lcp << endl;
        long long x = lcp;
        
        while(true){
            int index1 = x / A;
            int index2 = x / B;
            index1 -= 1;
            index2 -= 1;
            
            int index = index1 + index2 -((x / lcp) - 1) + 1;
            
            if(index > N)
                break;
            x = x + lcp;
        }
       // cout << x << endl;
        
        long long prevX = x - lcp;
        int prevIndex = prevX / A - 1 + prevX / B - 1 - (prevX / lcp -1) + 1;
        
        //cout << "prev X: " << prevX << " prevIndex " << prevIndex << endl;
        int n1 = prevX / A;
        int n2 = prevX / B;
        int startIndex = prevIndex;
        
        return Core(N, A, B, startIndex, n1, n2);
        
        
        
    }

    int gcd(int A, int B){
        int maxNb = max(A, B);
        int minNb = min(A, B);
        
        while(minNb){
            int temp = maxNb % minNb;
            maxNb = minNb;
            minNb = temp;
        }
        return maxNb;
    }
    
    int Core(int N, int A, int B, int startIndex, int nn1, int nn2) {

        long long n1 = nn1;
        long long n2 = nn2;
        
        long long next = startIndex;
        long long res = 0;
        
        while(next <= N){
            long long resA = A * n1;
            long long resB = B * n2;
            
            if(resA == resB){
                next++;
                n1++;
                n2++;
                res = resA;
            }
            else if(resA < resB){
                next++;
                n1++;
                res = resA;
            }
            else
            {
                next++;
                n2++;
                res = resB;
            }
        }
        
        res = res % int(pow(10, 9) + 7);
        return res;        
    }
};
