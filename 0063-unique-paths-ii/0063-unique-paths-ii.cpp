class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<int> paths(n , 0);
        paths[0] = 1;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(obstacleGrid[i][j] == 1){
                    paths[j] = 0;
                }
                else{
                    int left = j == 0 ? 0 : paths[j - 1];
                    paths[j] += left; 
                }
            }
        }
        return paths[n - 1];
    }
};