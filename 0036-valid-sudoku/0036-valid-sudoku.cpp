class Solution {
public:
    unsigned short mask[27];
    bool isValidSudoku(vector<vector<char>>& board) {
        unsigned short bit;
        for(char i = 0 ; i < 27 ; ++i) mask[i] = 0;
        for(char r = 0 ; r < 9 ; ++r){
            unsigned short rb = 18 + ((r/3)*3);
            for(char c = 0 ; c < 9 ; ++c){
                if(board[r][c] != '.'){
                    bit = 1 << (board[r][c] - '1');
                    if(mask[r] & bit || mask[9 + c] & bit || mask[rb+(c/3)] & bit) return false;
                    mask[r] |= bit;
                    mask[9 + c] |= bit;
                    mask[18+((r/3)*3)+(c/3)] |= bit ;
                }
            }
        }
        return true;
    }
};