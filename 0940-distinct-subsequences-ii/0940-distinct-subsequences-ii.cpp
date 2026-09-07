class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        vector<int> dp(n + 1 , 0);
        dp[0] = 1;
        vector<int> last_pos(26 , -1);

        for(int i = 1 ; i <= n ; ++i){
            char c = s[i - 1];
            int charind = c - 'a';

            dp[i] = (2 * dp[i - 1]) % mod;

            if(last_pos[charind] != -1){
                int prevind = last_pos[charind];
                dp[i] = (dp[i] - dp[prevind - 1] + mod) % mod;
            }

            last_pos[charind] = i;
        }
        return ((dp[n] - 1 + mod) % mod);
    }
};