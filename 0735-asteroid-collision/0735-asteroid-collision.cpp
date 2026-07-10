class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int top = -1;
        for(const int& i : asteroids){
            if(i > 0 ){
                st.push_back(i);
                ++top;
                continue;
            }
            while(top != -1 && st[top] > 0 && abs(i) > abs(st[top])){
                st.pop_back();
                --top;
            }
            if(top == -1 || st[top] < 0){
                st.push_back(i);
                ++top;
                continue;
            }
            if(abs(i) == st[top]){
                st.pop_back();
                --top;
            }
        }
        return st;
    }
};