class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        vector<int> result(m , 0);
        vector<int> psum(n + 1, 0);
        vector<long long> pnum(n + 1 , 0);
        vector<int> zcount(n + 1,  1);
        vector<long long> mult(n + 1 , 1);
        int mod = 1000000007;
        for(int i = 1 ; i <= n ; ++i){
            mult[i] = (mult[i - 1] * 10) % mod;
        }
        for(int i = 1 ; i <= n ; ++i){
            if(s[i - 1] != '0'){
                pnum[i] = ( (pnum[i - 1]*10LL) + (s[i - 1] - '0') ) % mod;
                psum[i] = (psum[i - 1] + (s[i - 1] - '0')) % mod;
                zcount[i] = zcount[i - 1] + 1;
            }
            else{
                pnum[i] = pnum[i - 1];
                psum[i] = psum[i - 1];
                zcount[i] = zcount[i - 1];
            }
        }
        for(int i = 0 ; i < m ; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            long long sh = (pnum[l] * mult[zcount[r + 1] - zcount[l]]) % mod;
            long long val = (pnum[r + 1] - sh + mod) % mod;
            long long sum = (psum[r + 1] - psum[l] + mod) % mod;
            long long res = (val * sum) % mod;
            result[i] = res;
        }
        return result;
    }
};