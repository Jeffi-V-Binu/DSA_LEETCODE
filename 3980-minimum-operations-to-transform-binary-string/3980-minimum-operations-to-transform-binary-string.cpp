class Solution {
public:
    int minOperations(string s1, string s2) {
        int count = 0;
        int n = s1.size();
        if(n == 1 && s1[0] == '1' && s2[0] == '0') return -1;
        for(int i = 0 ; i < n - 1 ; ++i){
            if(s1[i] != s2[i]){
                char a = s1[i];
                char b = s2[i];
                if(a == '0'){
                    ++count;}
                else{
                    if(s1[i + 1] == '1'){
                        ++count;
                        s1[i+1] = '0';
                    }
                    else{
                        count += 2;}}}}
        char c = s1[n - 1];
        char d = s2[n - 1];
        if(c != d){
            if(c == '0'){
                ++count;
            }
            else{
                count += 2;
            }
        }
        return count;
    }
};