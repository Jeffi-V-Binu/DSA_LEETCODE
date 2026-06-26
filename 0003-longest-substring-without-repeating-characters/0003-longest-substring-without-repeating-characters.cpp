class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mask(255 , -1);
        int len = 0;
        int maxlen = 0;
        int left = 0;
        mask[s[0]] = 0;
        int right = 1;
        int n = s.size();
        if(n <= 1) return n;
        while(right < n){
            char a = s[right];
            if(mask[a] >= left) left = mask[a] + 1;
            mask[a] = right;
            maxlen = max(maxlen , (right - left + 1));
            ++right;
        }
        return maxlen;
    }
};