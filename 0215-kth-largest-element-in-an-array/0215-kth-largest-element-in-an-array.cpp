class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        int res;
        for(int i = 1 ; i < k; ++i){
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        pop_heap(nums.begin(), nums.end());
        res = nums.back();
        return res;
    }
};