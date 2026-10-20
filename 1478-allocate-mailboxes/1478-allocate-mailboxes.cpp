class Solution {
private:
    vector<vector<int>> cost;
    vector<vector<int>> dp;

    int support(int index , int k){
        if(index < 0) return 0;
        if(k == 0) return 1e9;
        if(dp[index][k] != -1) return dp[index][k];
        int mincost = 1e9;
        for(int i = 0 ; i <= index ; ++i){
            mincost = min(mincost , (support(i - 1 ,k - 1) + cost[i][index]));
        }
        dp[index][k] = mincost;
        return mincost;
    }
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin() , houses.end());
        cost.assign(n , vector<int>(n , 0));
        dp.assign(n , vector<int>(k + 1 , -1));
        for(int i = 1 ; i < n ; ++i){
            for(int j = 0 ; j < n - i ; ++j){
                cost[j][i + j] = (cost[j + 1][(i + j) - 1]) + (houses[i + j] - houses[j]);
            }
        }
        return support(n - 1 , k);
    }
};