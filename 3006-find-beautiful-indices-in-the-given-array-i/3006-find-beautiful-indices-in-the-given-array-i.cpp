class Solution {
public:
    vector<int> kmpsearch(string& s , string& patt){
        int c = s.size();
        int d = patt.size();
        vector<int> pattpos;
        if(d > c || d == 0) return pattpos;
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
                    pattpos.push_back(sind - pattind);
                    pattind = lps[pattind - 1];
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
        return pattpos;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> posi = kmpsearch(s , a);
        vector<int> posj = kmpsearch(s , b);
        vector<int> result;
        int n = s.size();
        int posiind = posi.size();
        int posjind = posj.size();
        if(!posiind || !posjind) return result;
        for(const int& i : posi){
            int lower = max(0 , i - k);
            int upper = min(n - 1 , i + k);
            auto it = lower_bound(posj.begin() , posj.end() , lower);
            if(it != posj.end() && *it <= upper)
                result.push_back(i);
        }
        return result;
    }
};