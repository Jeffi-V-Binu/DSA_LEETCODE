class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>map(m , 0);
        int result = 0;
        int temp = 0;
        for(int i = 0; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(i == 0 || j == 0){
                    if(matrix[i][j] == '1'){
                        result = max(result , 1);
                        temp = map[j];
                        map[j] = 1;
                    }
                    else{
                        temp = map[j];
                        map[j] = 0;
                    }
                }
                else{
                    if(matrix[i][j] == '1'){
                        int t = map[j];
                        map[j] = min(map[j - 1] , min( map[j] , temp)) + 1;
                        temp = t;
                        result = max(result , map[j]);
                    }
                    else{
                        temp = map[j];
                        map[j] = 0;
                    }
                }
            }
        }
        return result * result;
    }
};