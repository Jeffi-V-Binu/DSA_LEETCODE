class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.size();
        if(numRows >= n) return s;
        string result = s;
        int ind = 0;
        int start = -1;
        int count = numRows + (numRows - 2);
        while(ind < n){
            if(ind >= n) break;
            ++start;
            result[start] = s[ind];
            ind += count;
        }
        int indxadd = count;
        for(int i = 1 ; i < numRows - 1 ; ++i ){
            ind = i;
            indxadd -= 2;
            int indxvar = indxadd;
            while(ind < n){
                ++start;
                result[start] = s[ind];
                ind += indxvar;
                indxvar = count - indxvar;
            }
        }
        ind = numRows - 1;
        while(ind < n){
            if(ind >= n) break;
            ++start;
            result[start] = s[ind];
            ind += count;
        }
        return result;
    }
};