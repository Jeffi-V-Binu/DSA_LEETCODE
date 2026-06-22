class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        sort(nums.begin(), nums.end());
        permutations.push_back(nums);
        int n = 1;
        for(int l = 1 ; l <= nums.size() ; ++l ){
            n = n * l;
        }
        for(int i = 1 ; i < n ; ++i){
            int j = nums.size() - 1;
            while(j > 1 && nums[j]<nums[j-1]){--j;}
            int m = 0;
            for(int k = j ; k < nums.size(); k++){
                if(nums[k]>nums[j-1]){m = k;}
            }
            int temp = nums[j-1];
            nums[j-1] = nums[m];
            nums[m] = temp;
            reverse(nums.begin() + j, nums.end());
            permutations.push_back(nums);
        }
        return permutations;
    }
};