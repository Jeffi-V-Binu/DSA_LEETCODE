class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n , 0);
        for(int i = 0 ; i < n ; ++i){
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        sort(diff.begin(), diff.end());
        int sub = k1+k2;
        int flag = 0;
        if(diff[n-1] == 0) return 0;
        long long maxv = diff[n-1];
        int end = n - 1;
        long long result = 0;
        while(maxv != 0 && sub != 0){
            while(end > 0 && diff[end - 1] == maxv) --end;
            int leng = n - end;
            if(leng > sub){
                result += (sub * ((maxv - 1) * (maxv - 1))) + ((leng - sub) * (maxv * maxv));
                flag = 1;
                break;
            }
            sub -= leng;
            maxv--;
        }
        if(flag == 0){
           result += ((n - end)*(maxv * maxv));
        }
        for(int i = 0 ; i < end ; ++i){
            result += ((long long)diff[i] * diff[i]);
        }
        return result;
    }
};