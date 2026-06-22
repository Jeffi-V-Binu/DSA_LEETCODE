class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> dupnums;
        int l = INT_MIN;
        int lcount = 0;
        int m = INT_MIN;
        int n = nums.size();
        int mcount = 0;
        for(int i = 0; i < n; ++i){
            int temp = nums[i];
            if(temp == l){
                ++lcount;
            }
            else if(temp == m){
                ++mcount;
            }
            else if(lcount == 0 ){ l = temp; lcount = 1;}
            else if(mcount == 0 ){ m = temp; mcount = 1;}
            else{
                --lcount;
                --mcount;
            }
        }
        lcount=0;
        mcount=0;
        for(int j = 0; j < n; ++j){
            if(nums[j] == l){
                ++lcount;
            }
            else if(nums[j] == m){
                ++mcount;
            }
        }
        if(lcount >= n/3 + 1) dupnums.push_back(l);
        if(mcount >= n/3 + 1) dupnums.push_back(m);
        return dupnums;
    }
};