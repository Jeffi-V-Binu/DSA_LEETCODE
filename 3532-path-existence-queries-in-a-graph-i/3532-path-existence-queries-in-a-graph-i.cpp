class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> result;
        int m = queries.size();
        result.reserve(m);
        vector<int> partitions(n , 1);
        int count = 1;
        for(int i = 1 ; i < n ; ++i){
            if(nums[i - 1] + maxDiff < nums[i]) ++count;
            partitions[i] = count;
        }
        for(int i = 0 ; i < m ; ++i){
            if(partitions[queries[i][0]] == partitions[queries[i][1]]) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};