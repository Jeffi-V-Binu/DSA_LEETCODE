class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        vector<int> gcds(n , 0);
        int maxv = nums[0];
        for(int i = 0 ; i < n ; ++i){
            if(maxv <= nums[i]){
                maxv = nums[i];
                gcds[i] = maxv;
            }
            else gcds[i] = gcd(maxv , nums[i]);
        }
        sort(gcds.begin(), gcds.end());
        int i = 0;
        int j = n - 1;
        while(i < j){
            result += gcd(gcds[i] , gcds[j]);
            ++i;
            --j;
        }
        return result;
    }
};