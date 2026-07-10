class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int count = 0;
        int i = 0;
        int j = 0;
        int n = players.size();
        int m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        while(i < n && j < m){
            if(players[i] <= trainers[j]){
                ++i;
                ++j;
                ++count;
            }
            else ++j;
        }
        return count;
    }
};