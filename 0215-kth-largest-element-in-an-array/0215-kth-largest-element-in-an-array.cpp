class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int target = n - k;

        while(low <= high){
            int randind = rand()%(high - low + 1) + low;
            int pivot = nums[randind];

            int i = low;
            int j = high;

            while(i <= j){
                while(i <= j && nums[i] < pivot) ++i;
                while(i <= j && nums[j] > pivot) --j;

                if(i<= j){
                    swap(nums[i], nums[j]);
                    ++i;
                    --j;
                }
            }
            if(i <= target){
                low = i;
            }
            else if(j >= target){
                high = j;
            }
            else return nums[target];
        }
        return nums[target];
    }
};