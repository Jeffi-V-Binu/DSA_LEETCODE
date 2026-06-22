class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int i = 0; 
        int j = n-1;
        int mid = i +(j - i)/2;
        if(n == 1) return i;
        while(i < j){
            mid = i +(j - i)/2;
            int lend;
            if(mid == 0){lend = INT_MIN;}
            else{lend = nums[mid-1];}
            int rend;
            if(mid == n-1){rend = INT_MIN;}
            else{rend = nums[mid+1];}
            if(lend < nums[mid] && rend < nums[mid]){return mid;}
            else if(nums[mid]<=rend) i = mid+1;
            else j = mid -1;
            mid = i +(j - i)/2;
        }
        return mid;
    }
};