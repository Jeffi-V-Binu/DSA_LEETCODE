class Solution {
public:
    void subsetSol(vector<vector<int>>& allsubset,vector<int>& nums, int count , vector<int>& subsets ){
        if(count == nums.size()){
            allsubset.push_back(subsets);
            return;
        }
        subsets.push_back(nums[count]);
        subsetSol(allsubset , nums , count + 1 , subsets);
        subsets.pop_back();
        subsetSol(allsubset , nums , count + 1, subsets);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubset;
        allsubset.reserve(1 << nums.size());
        vector<int> subsets = {};
        int count = 0;
        subsetSol(allsubset , nums , count , subsets);
        return allsubset;
    }
};