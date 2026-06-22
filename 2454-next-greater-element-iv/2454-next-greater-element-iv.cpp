class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        stack<int> st1;
        stack<int> st2;
        stack<int> st;
        vector<int> result(n ,-1);
        for(int i = 0 ; i < n ; ++i){
            while((!st2.empty()) && nums[st2.top()] < nums[i]) {
                result[st2.top()] = nums[i];
                st2.pop();
            }
            while((!st1.empty()) && nums[st1.top()] < nums[i]){
                st.push(st1.top());
                st1.pop();
            }
            while(!st.empty()){
                st2.push(st.top());
                st.pop();
            }
            st1.push(i);
        }
        return result;
    }
};