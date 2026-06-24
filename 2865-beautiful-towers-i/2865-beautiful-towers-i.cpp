class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
       int n = heights.size();
       vector<int> st;
       int top = 0;
       vector<long long> ls(n , 0);
       vector<long long> rs(n , 0);
       long long maxh = 0;
       for(int i = 0 ; i < n ; ++i){
            long long j = heights[i];
            while(top != 0 && heights[st.back()] >= j){
                st.pop_back();
                --top;
            }
            if(top == 0){
                ls[i] = (i + 1) * j;
            }
            else{
                ls[i] = ls[st.back()] + ((i - st.back()) * j);
            }
            st.push_back(i);
            ++top;
       }
       while(top != 0){
            st.pop_back();
            --top;
       }
       for(int i = n - 1 ; i >= 0 ; --i){
            long long j = heights[i];
            while(top != 0 && heights[st.back()] >= j){
                st.pop_back();
                --top;
            }
            if(top == 0){
                rs[i] = (n - i) * j;
            }
            else{
                rs[i] = rs[st.back()] + ((st.back() - i) * j);
            }
            st.push_back(i);
            ++top;
       }
       for(int i = 0 ; i < n ; ++i){
            maxh = max(maxh , (rs[i]+ls[i]) - heights[i]);
       }
       return maxh;
    }
};