class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int count = 0;
        char curr;
        int total = 0;
        int delta = 0;
        int result = 0;
        int ptr = 0;
        int n = s.size();
        while(ptr != n){
            curr = s[ptr];
            total = 0;
            while(ptr != n && s[ptr] == curr){
                total += 1;
                ++ptr;
            }
            if(curr == '1'){
                count += total;
            }
            else{
                delta += total;
                if(delta > total){
                    result = max(result , delta);
                    delta = total;
                }
            }
        }
        return count + result;
    }
};