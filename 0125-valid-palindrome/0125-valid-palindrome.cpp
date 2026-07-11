class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while(i < j){
            if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) ++i;
            else if(!((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))) --j;
            else{
                if(tolower(s[i]) == tolower(s[j])){
                    ++i;
                    --j;
                }
                else return false;
            }
        }
        return true;
    }
};