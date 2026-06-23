class Solution {
public:
    int maxDistance(string moves) {  
        int lc = 0 ,rc = 0, uc = 0 , dc = 0 , wc = 0;
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