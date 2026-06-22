class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int n = nums.size();
        while(i < n && nums[i] > target) ++i;
        if(i == n) return false;
        while(i < n){
            if (nums[i] == target) return true;
            if(nums[i] > target) return false;
            ++i;
        }
        return false;
    }
};