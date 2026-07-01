class Solution {
public:
    int uniquePaths(int m, int n) {
        short total = m + n - 2;
        char mind = min(m - 1 , n - 1);
        long long result = 1;
        for(int i = 1 ; i <= mind ; ++i){
            result = result * (total - mind + i) / i ;
        }
        return (int)result;
    }
};