class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {

        long long n1 = 1;
        long long n2 = 1;
        
        long long next = 1;
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
