class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int count = 0;
        char curr;
        int fzero = 0;
        int szero = 0;
        int result = 0;
        int ptr = 0;
        int n = s.size();
        while(ptr != n){
            int newp = ptr;
            curr = s[ptr];
            while(newp < n && curr == s[newp]) ++newp;
            if(curr == '1') count += (newp - ptr);
            else{
                szero = newp - ptr;
                if(fzero > 0)result = max(result , szero + fzero);
                fzero = szero;
            }
            ptr = newp;
        }
        return count + result;
    }
};