class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> sums;
        sums.reserve(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            auto cmp = sums.find(target  - nums[i]);
            if(cmp != sums.end()){
                return {cmp -> second,i};
            }
            sums[nums[i]] = i;
        }
        return {}; 
    }
};