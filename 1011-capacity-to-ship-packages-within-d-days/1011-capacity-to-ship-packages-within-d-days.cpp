class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minw = -10000;
        int maxw = 0;
        for(const int i : weights){
            minw = max(minw , i);
            maxw += i;
        }
        int mid;
        while(minw < maxw){
            mid = minw + (maxw - minw) / 2;
            int mind = 1;
            int total = 0;
            for(const int& i : weights){
                if(total + i > mid){
                    total = i;
                    ++mind;
                }
                else{
                    total += i;
                }
            }
            if(mind > days){
                minw = mid + 1;
            }
            else{
                maxw = mid;
            }
        }
        return maxw;
    }
};