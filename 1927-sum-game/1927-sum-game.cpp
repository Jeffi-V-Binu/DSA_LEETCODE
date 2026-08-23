class Solution {
public:
    bool sumGame(string num) {
        int n = num.size() - 1;
        int Sumd = 0;
        int qd = 0;
        int j = n;
        int i = 0;
        while(i < j){
            if(num[i] == '?') ++qd;
            else{
                Sumd += num[i] - '0';
            }
            ++i;
            if(num[j] == '?') --qd;
            else{
                Sumd -= num[j] - '0';
            }
            --j;
        }
        return Sumd != -1 * 4.5 * qd;
    }
};