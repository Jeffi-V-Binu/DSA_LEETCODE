class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> map(n , vector<int>(m , 0));
        int result = 0;
        for(int i = 0; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(i == 0 || j == 0){
                    if(matrix[i][j] == '1'){
                        result = max(result , 1);
                        map[i][j] = 1;
                    }
                }
                else{
                    if(matrix[i][j] == '1'){
                        map[i][j] = min(map[i][j - 1] , min( map[ i - 1][j] , map[i - 1][ j - 1])) + 1;
                        result = max(result , map[i][j]);
                    }
                }
            }
        }
        return result * result;
    }
};