class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = nums[0];
        int n = nums.size();
        int i = 0;
        while(i <= maxi && i < n){
            if(nums[i]) maxi = max(maxi , i + nums[i]);
            ++i;
        }
        if (maxi >= (n - 1)) return true;
        return false;
    }
};