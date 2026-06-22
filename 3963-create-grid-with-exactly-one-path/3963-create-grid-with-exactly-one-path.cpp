class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> our_grid;
        string ourstr = "";
        for(int i = 0 ; i < n ; ++i){
            ourstr += "#";
        }
        for(int i = 0 ; i < m ; ++i){
            our_grid.push_back(ourstr);
        }
        for(int i = 0 ; i < n ; ++i){
            our_grid[0][i] = '.';
        }
        for(int i = 1 ; i < m ; ++i){
            our_grid[i][n - 1] = '.';
        }
        return our_grid;
    }
};