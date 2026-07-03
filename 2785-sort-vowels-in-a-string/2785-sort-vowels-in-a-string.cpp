class Solution {
public:
    string sortVowels(string s) {
        string a = "";
        int j = 0;
        string vow = "AEIOUaeiou";
        for(int i = 0 ; i < s.size(); ++i){
            for(const char k: vow){
                if(s[i] == k){
                    s[i] = '#';
                    a+= k;
                }
            }
        }
        sort(a.begin(), a.end());
        for(int i = 0 ; i < s.size(); ++i){
            if(s[i] == '#'){
                s[i] = a[j];
                ++j;
            }
        }
        return s;
    }
};