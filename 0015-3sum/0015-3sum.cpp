class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int j ;
        int k ;
        int sum;
        int tempi;
        vector<vector<int>> sums;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n - 2 ; ++i){
            tempi =  nums[i];
            if(tempi > 0 ) break;
            if(i > 0 && tempi == nums[i-1]) continue;
            j = i + 1;
            k = n - 1;
            while(j < k){
                sum = nums[j] + nums[k];
                if(sum > -tempi) --k;
                else if(sum < -tempi) ++j;
                else{
                    sums.push_back({tempi,nums[j],nums[k]});
                    while(j < k && nums[j] == nums[j+1])++j;
                    while(j < k && k < n && nums[k] == nums[k-1])--k;
                    --k;
                    ++j;
                }
            }
        }
        return sums;
    }
};