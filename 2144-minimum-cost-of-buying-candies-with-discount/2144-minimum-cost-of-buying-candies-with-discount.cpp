class Solution {
public:
    int minimumCost(vector<int>& cost) {
        char n = cost.size();
        int sum = 0;
        sort(cost.begin(), cost.end(), greater<int>());
        for(char i = 0 ; i < n ; ++i){
            if(i % 3 == 2) continue;
            sum += cost[i];
        }
        return sum;
    }
};