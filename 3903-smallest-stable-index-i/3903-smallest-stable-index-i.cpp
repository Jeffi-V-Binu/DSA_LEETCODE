class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int min = nums[n - 1];
        vector<int> minvals (n , min);
        for(int i = n - 1 ; i >= 0 ; --i){
            if(nums[i] < min){
                min = nums[i];
            }
            minvals[i] = min;
        }
        int max = INT_MIN;
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] > max) max = nums[i];
            if(max - minvals[i] <= k)return i;
        }
        return -1;
    }
};