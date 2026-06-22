class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = size(landStartTime);
        int m = size(waterStartTime);
        int minlandt = INT_MAX;
        int minwatert = INT_MAX;
        for(int i = 0 ; i < n; ++i){
            minlandt = min(minlandt , landStartTime[i] + landDuration[i]);
        }
        for(int i = 0 ; i < m; ++i)
        {
            minwatert = min(minwatert , waterStartTime[i] + waterDuration[i]);
        }
        int mint= INT_MAX;
        int wex1;
        for(int i = 0 ; i < m; ++i)
        {
            int k = waterStartTime[i];
            if(minlandt > k) mint = min(mint , minlandt + waterDuration[i]);
            else mint = min(mint , k + waterDuration[i]);
        }
        for(int i = 0 ; i < n; ++i)
        {
            int k = landStartTime[i];
            if(minwatert > k ) mint = min(mint , minwatert + landDuration[i]);
            else mint = min(mint , k + landDuration[i]);
        }
        return mint;
    }
};