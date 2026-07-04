class Solution {
public:
    void dfs(vector<vector<pair<int , int>>>& edges , int& minsc ,vector<bool>& visit , int& n , int node){
        visit[node] = 1;
        for(const auto& a : edges[node]){
            minsc = min(minsc , a.second);
            if(!visit[a.first]) dfs(edges , minsc , visit , n , a.first);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int , int>>> edges(n);
        for(const auto& a: roads){
            edges[a[0] - 1].push_back({a[1] - 1 , a[2]});
            edges[a[1] - 1].push_back({a[0] - 1 , a[2]});
        }
        int minsc = INT_MAX;
        vector<bool> visit (n , false);
        dfs(edges , minsc ,visit, n , 0);
        return minsc;
    }
};