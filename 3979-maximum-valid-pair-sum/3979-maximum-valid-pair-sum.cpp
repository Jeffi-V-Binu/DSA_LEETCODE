class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        int maxs = 0;
        for(int j = k ; j < n ; ++j){
            maxi = max(maxi , nums[j - k]);
            maxs = max(maxs , maxi + nums[j]);
        }
        return maxs;
    }
};