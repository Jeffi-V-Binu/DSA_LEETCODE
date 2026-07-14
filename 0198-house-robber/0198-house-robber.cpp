class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        else if(n == 2) return max(nums[1] , nums[0]);
        int odd = nums[0];
        int even = max(nums[1] , nums[0]);
        for(int i = 2 ; i < n ; ++i){
            int l = even;
            int r = nums[i] + odd;
            odd = even;
            even = max(l , r);
        }
        return even;
    }
};