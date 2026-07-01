class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minw = *max_element(weights.begin(), weights.end());
        int maxw = accumulate(weights.begin() , weights.end(), 0);
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