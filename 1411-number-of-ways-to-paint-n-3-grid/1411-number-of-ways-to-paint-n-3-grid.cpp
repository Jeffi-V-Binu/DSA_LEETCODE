class Solution {
public:
    int numOfWays(int n) {
        if(n == 1) return 12;
        int mod = 1000000007;
        int aba = 6;
        int abc= 6;
        for(int i = 1 ; i < n ; ++i){
            long temp1 = aba;
            long temp2 = abc;
            aba = (int)(((temp1 * 3) + (temp2 * 2)) % mod);
            abc = (int)(((temp1 * 2) + (temp2 * 2)) % mod);
        }
        return ((aba % mod) + (abc % mod)) % mod;
    }
};