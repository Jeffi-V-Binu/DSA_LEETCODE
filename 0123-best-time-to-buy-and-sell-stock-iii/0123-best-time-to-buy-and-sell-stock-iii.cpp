class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s2 = 0;
        int s1 = 0;
        int b2 = INT_MIN;
        int b1 = INT_MIN;
        int n = prices.size();
        for(int i = 0 ; i < n ; ++i){
            s2 = max(s2 , b2 + prices[i]);
            b2 = max(b2 , s1 - prices[i]);
            s1 = max(s1 , b1 + prices[i]);
            b1 = max(b1 , 0 - prices[i]);
        }
        return max(s2 , s1);
    }
};