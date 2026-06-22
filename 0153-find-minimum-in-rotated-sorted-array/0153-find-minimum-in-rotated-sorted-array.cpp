class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int j = n-1;
        int mid =(( i + j )/ 2);
        while(j != mid){
            if(nums[i] > nums[mid]) j = mid;
            else if(nums[i] <= nums[mid] && nums[i] > nums[j]) i = mid+1;
            else j = mid;
            mid = ((i + j)/2) ;
        }
        return nums[mid];
    }
};