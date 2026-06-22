class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n , -1);
        stack<int> st;
        int ind = 0;
        int j = 0;
        int temp = INT_MIN;
        for(int i = 0 ; i < n ;++i){
            if(nums[i] > temp){
                temp = nums[i];
                ind = i;
            }
        }
        while(j < n){
            while((!st.empty()) && st.top() <= nums[ind]) st.pop();
            if(!st.empty()) result[ind] = st.top();
            st.push(nums[ind]);
            ++j;
            ind = ind == 0 ? n - 1 : ind -= 1;
        }
        return result;
    }
};