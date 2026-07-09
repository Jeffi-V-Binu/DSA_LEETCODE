class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> result;
        vector<int> partitions(n , 1);
        int count = 1;
        for(int i = 1 ; i < n ; ++i){
            if(nums[i - 1] + maxDiff < nums[i]) ++count;
            partitions[i] = count;
        }
        for(const auto& a: queries){
            if(partitions[a[0]] == partitions[a[1]]) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};