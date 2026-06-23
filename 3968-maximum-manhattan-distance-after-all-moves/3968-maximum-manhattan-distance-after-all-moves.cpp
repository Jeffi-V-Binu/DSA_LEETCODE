class Solution {
public:
    int maxDistance(string moves) {
        int n = moves.size();   
        int lc = 0;
        int rc = 0;
        int uc = 0;
        int dc = 0;
        int wc = 0;
        for(const char a : moves){
            if(a == 'U') ++uc;
            else if(a == 'D') ++dc;
            else if(a == 'R') ++rc;
            else if(a == 'L') ++lc;
            else ++wc;
        }
        return abs(uc - dc) + abs(lc - rc) + wc;
    }
};