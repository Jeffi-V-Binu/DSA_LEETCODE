class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> pos(3 , -1);
        int n = s.size();
        int result = 0;
        if(n < 3) return 0;
        int j = 0;
        while(j < n){
            pos[s[j] - 'a'] = j;
            int minind = min({pos[0] , pos[1] , pos[2]});
            if(minind >= 0){
                result += (minind + 1);
            }
            ++j;
        }
        return result;
    }
};