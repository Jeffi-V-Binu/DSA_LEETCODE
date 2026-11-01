class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int min_Val = nums[0];
        int n = nums.size();
        int result = 0 ;
        for(int i = 0 ; i < n ; ++i){
            result += (nums[i] - min_Val);
        }
        return result;
    }
};