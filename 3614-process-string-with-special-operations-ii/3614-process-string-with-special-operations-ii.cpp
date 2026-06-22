static const int speedup = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long m = 0;
        for(int i = 0 ; i < n ; ++i){
            if(islower(s[i])){
                ++m;
            }
            else if(s[i] == '*' ){
                if(m > 0 ) --m;
            }
            else if(s[i] == '#'){
                m*=2;
            }
        }
        if(m <= k) return '.';
        for(int i = n - 1 ; i >= 0; --i){
            if(islower(s[i])){
                --m;
                if(m == k) return s[i];
            }
            else if(s[i] == '*'){
                ++m;
            }
            else if(s[i] == '#'){
                m = m / 2;
                k %= m;
            }
            else{
                k = (m - 1) - k;
            }
        }
        return '.';
    }
};