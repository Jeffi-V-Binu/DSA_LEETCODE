class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> bars(m , 0);
        int maxr = 0;
        for(int i = 0 ; i < n ; ++i){
            vector<int> st;
            int top = -1;
            for(int j = 0 ; j < m ; ++j){
                if(matrix[i][j] == '1') ++bars[j];
                else bars[j] = 0;
            }
            for(int j = 0 ; j <= m ; ++j){
                int a = j == m ? 0 : bars[j]; 
                while(top != -1 && bars[st[top]] > a){
                    int l = top == 0 ? -1 : st[top - 1];
                    maxr = max(maxr , ((j - l  - 1) * bars[st[top]]));
                    --top;
                    st.pop_back();
                }
                if(top != -1 && bars[st[top]] == a){
                    st.pop_back();
                    --top;
                }
                st.push_back(j);
                ++top;
            }
        }
        return maxr;
    }
};