class Solution {
public:
    bool sumGame(string num) {
        int n = num.size() - 1;
        int ls = 0;
        int rs = 0;
        int lq = 0;
        int rq = 0;
        int j = n;
        int i = 0;
        while(i < j){
            if(num[i] == '?') ++lq;
            else{
                int temp = num[i] - '0';
                ls += temp;
            }
            ++i;
            if(num[j] == '?') ++rq;
            else{
                int temp = num[j] - '0';
                rs += temp;
            }
            --j;
        }
        if(rs == ls && rq == lq){
            return false;
        }
        else{
            if((ls > rs && lq >= rq) || (rs > ls && rq >= lq)) return true;
            else{
                int sumd = abs(rs - ls);
                int qd = abs(lq - rq);
                int bm = qd / 2;
                int am = (qd+1) / 2;
                if(sumd == (bm * 9) && bm == am) return false;
            }
        }
        return true;
    }
};