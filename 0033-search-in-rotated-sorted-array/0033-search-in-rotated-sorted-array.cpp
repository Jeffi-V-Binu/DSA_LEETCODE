class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int n = nums.size();
        while(i < n && nums[i] > target) ++i;
        if(i ==  n) return -1;
        while(i < n && nums[i] <= target){
            if(nums[i] == target) return i;
            ++i;
        }
        return -1;
    }
};