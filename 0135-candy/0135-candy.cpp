class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int t_candy = 1 ;
        int top = 0 , down = 0 , up = 0;
        for(int i = 1 ; i < n ; ++i){
            if(ratings[i] > ratings[i - 1]){
                ++up;
                down = 0;
                top = up;
                t_candy += (up + 1);
            }
            else if( ratings[i] == ratings[i - 1]){
                up = 0;
                down = 0;
                top = 0;
                ++t_candy;
            }
            else{
                up = 0;
                ++down;
                t_candy += down;
                if(down > top) ++t_candy;
            }
        }
        return t_candy;
    }
};