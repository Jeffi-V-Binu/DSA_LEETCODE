class Solution {
public:
    long long minCost(vector<int>& nums) {
        long long result = 0;
        result += nums[0];
        int n = nums.size();
        result += nums[n - 1];
        sort(nums.begin() + 1 , nums.end()-1);
        for(int i = 1 ; i < n - 1 ; ++i){
            int temp = nums[i];
            if(i != n - 2){
                temp += nums[i + 1];
                ++i;
            }
            else temp = 0;
            if(temp < 0) result += temp;
        }

        return result;
    }
};