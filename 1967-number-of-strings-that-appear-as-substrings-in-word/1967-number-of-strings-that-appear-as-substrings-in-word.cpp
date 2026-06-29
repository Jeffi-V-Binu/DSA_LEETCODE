class Solution {
public:
    int kmpsearch(string& s , string& patt){
        int c = s.size();
        int d = patt.size();
        if(d > c || d == 0) return 0;
        vector<int> lps(d , 0);
        int len = 0 ;
        int i = 1;
        while(i < d){
            if(patt[i] == patt[len]){
                ++len;
                lps[i] = len;
                ++i;
            }
            else{
                if(!len){
                    lps[i] = 0;
                    ++i;
                }
                else{
                    len = lps[len - 1];
                }
            }
        }
        int sind = 0 ;
        int pattind = 0;
        while(sind < c){
            if(s[sind] == patt[pattind]){
                ++sind;
                ++pattind;
                if(pattind == d){
                    return 1;
                }
            }
            else{
                if(!pattind){
                    ++sind;
                }
                else{
                    pattind = lps[pattind - 1];
                }
            }
        }
        return 0;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(string& a: patterns){
            count += kmpsearch(word , a);
        }
        return count;
    }
};