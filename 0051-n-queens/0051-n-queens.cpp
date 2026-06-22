class Solution {
public:
    void solvedNList(vector<vector<int>>& solvedList , vector<int>& solvedSubList , int rowCount , vector<vector<int>>& spaceValidity , int n)
    // to get a list that holds all valid possibilities , with its index being the row and value the column...
    { 
        if(rowCount == n ){
            solvedList.push_back(solvedSubList);

            return ;
        }
        for(int i = 0 ; i < n ; ++i){
            if(spaceValidity[rowCount][i] == 0){
                solvedSubList.push_back(i);
                updateValidity(spaceValidity , 1 , i , rowCount , n);
                solvedNList(solvedList , solvedSubList , rowCount + 1 , spaceValidity , n);
                solvedSubList.pop_back();
                updateValidity(spaceValidity , -1 , i , rowCount , n);
            }
        }
    }
    void updateValidity(vector<vector<int>>& spaceValidity , int a , int colm , int row , int n)
    // to update the space validity matrix , by adding 1 or by reducing 1... 
    {
        int k = 0;
        for(int i = row ; i < n ; ++i) spaceValidity[i][colm] += a;
        for(int j = row + 1 ; j < n ; ++j){
            ++k;
            if(colm + k < n) spaceValidity[j][colm + k] += a;
            if(colm - k >= 0) spaceValidity[j][colm - k] += a;
        }
    }
    void solvedSList(vector<vector<int>>& solvedList , int n , vector<vector<string>>& solvedString) 
    // to convert the numerical positioning to a string to indicate the positioning...
    {
        for(auto& row : solvedList){
            vector<string> subStrings;
            for(auto& colm : row){
                string temp = "";
                for(int i = 0 ; i < colm ; ++i) temp += ".";
                temp += "Q";
                for(int i = colm + 1 ; i < n ; ++i) temp += ".";
                subStrings.push_back(temp);
            }
            solvedString.push_back(subStrings);
       }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> solvedList;
        vector<int> solvedSubList;
        vector<vector<int>> spaceValidity(n , vector<int>(n , 0));
        solvedNList(solvedList , solvedSubList , 0 , spaceValidity , n);
        vector<vector<string>> solvedString ;
        solvedSList(solvedList , n , solvedString);
        return solvedString;
    }
};