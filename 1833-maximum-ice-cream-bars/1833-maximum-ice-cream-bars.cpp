class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n= costs.size();
        vector<int> countingvec (100001 , 0);
        int m = 0;
        for(int i = 0 ; i < n ; ++i){
            countingvec[costs[i]] += 1;
            m = max(m , costs[i]);
        }
        int count = 0;
        int min_cost = 0;
        int i = 0;
        while(i <= m ){
            if(countingvec[i]){
                for(int j = 0 ; j < countingvec[i] ; ++j){
                    if(min_cost + i > coins){
                        break;
                    }
                    min_cost += i;
                    ++count;
                }
            }
            ++i;
        }
        return count;
    }
};