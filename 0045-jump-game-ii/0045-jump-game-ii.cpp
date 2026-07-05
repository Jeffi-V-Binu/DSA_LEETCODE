class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int i = 0;
        int j = nums[0];
        int jumps = 1;
        while(j < n - 1){
            int k = j;
            while(i <= j){
                k = max(k, i + nums[i]);
                ++i;
            }
            j = k;
            ++jumps;
        }
        return jumps;
    }
};