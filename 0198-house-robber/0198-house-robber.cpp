class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        else if(n == 2) return max(nums[1] , nums[0]);
        vector<int> dp(n , 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1] , nums[0]);
        for(int i = 2 ; i < n ; ++i){
            int l = dp[i - 1];
            int r = nums[i] + dp[i - 2];
            dp[i] = max(l , r);
        }
        return dp[n - 1];
    }
};