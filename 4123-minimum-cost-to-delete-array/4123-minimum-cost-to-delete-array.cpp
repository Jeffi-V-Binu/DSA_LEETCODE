class Solution {
public:
    long long minCost(vector<int>& nums) {
        long long result = 0;
        result += nums[0];
        int n = nums.size();
        result += nums[n - 1];
        int neg_count = 0;
        long long neg_sum = 0;
        int pos_min = INT_MAX;
        int neg_min = INT_MIN;
        for(int i = 1 ; i < n - 1 ; ++i){
            if(nums[i]  < 0 ){
                neg_count++;
                neg_sum += nums[i];
                neg_min = max(neg_min , nums[i]);
            }
            else pos_min = min(pos_min , nums[i]);
        }
        result += neg_sum;
        if(neg_count % 2 == 1){
            if(neg_count == n - 2 || (neg_min + pos_min) >= 0) result -= neg_min ;
            else result += pos_min;
        }
        return result;
    }
};