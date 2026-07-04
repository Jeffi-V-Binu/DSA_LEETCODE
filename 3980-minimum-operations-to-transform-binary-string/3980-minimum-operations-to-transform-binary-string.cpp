class Solution {
public:
    int minOperations(string& s1, string& s2) {
        int count = 0;
        int n = s1.size();
        if(n == 1 && s1[0] == '1' && s2[0] == '0') return -1;
        for(int i = 0 ; i < n  ; ++i){
            if(s1[i] != s2[i]){
                if(s1[i] == '0'){
                    ++count;
                    continue;
                    }
                if(i < n - 1 && s2[i + 1] == '0'){
                        if(s1[i + 1] == '1'){
                            --count;
                        }
                        count +=2;
                        ++i;
                    }
                    else{
                        count += 2;}
                }}
        return count;
    }
};