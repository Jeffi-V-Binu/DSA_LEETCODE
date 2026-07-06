class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> st;
        int top = -1;
        int maxh = 0;
        heights.push_back(0);
        int n = heights.size();
        for(int i = 0 ; i < n ; ++i){
            while(top != -1 && heights[st[top]] > heights[i]){
                if(top == 0) maxh = max(maxh , (i * heights[st[top]]));
                else maxh = max(maxh , ((i - st[top - 1] - 1) * heights[st[top]]));
                --top;
                st.pop_back();
            }
            while(top != -1 && heights[st[top]] == heights[i]){
                --top;
                st.pop_back();
            }
            ++top;
            st.push_back(i);
        }
        return maxh;
    }
};