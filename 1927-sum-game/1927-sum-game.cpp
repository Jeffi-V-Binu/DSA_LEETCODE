class Solution {
public:
    bool sumGame(string num) {
        int n = num.size() - 1;
        int Sumd = 0;
        int qd = 0;
        int j = n;
        int i = 0;
        for(int i = 0 ; i <= n /2; ++i){
            if(num[i] == '?') ++qd;
            else{
                Sumd += num[i] - '0';
            }
        }
        for(int j = n ; j > n / 2 ; --j){
            if(num[j] == '?') --qd;
            else{
                Sumd -= num[j] - '0';
            }
        }
        return Sumd != -1 * 4.5 * qd;
    }
};