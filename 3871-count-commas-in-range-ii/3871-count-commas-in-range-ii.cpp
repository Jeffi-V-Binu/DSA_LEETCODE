class Solution {
public:
    long long countCommas(long long n) {
        long long dup = n;
        long long commas = 0;
        int count = 0;
        if(n < 1000) return 0;
        else{
            while(dup >= 1000){
                long long m = 999;
                int l = count;
                while(l > 0) {
                    m *= 1000;
                    --l;
                }
                commas += count * m;
                dup /= 1000;
                ++count;
            }
            long long k = 1;
            int c = count;
            while(c > 0){
            k *= 1000;
            --c;
            }
            commas += count * (n + 1  - k);
        }
        return commas;
    }
};