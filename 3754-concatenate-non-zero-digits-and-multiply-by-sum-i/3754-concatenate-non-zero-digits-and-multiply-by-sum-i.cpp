class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        int sum = 0 ;
        int m = 1;
        while(n){
            int a = n % 10;
           if(a){
            x += (a * m);
            sum += a;
            m *= 10;
           }
           n /= 10;
        }
        return x * sum;
    }
};