class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int max_alt = 0;
        int curr_alt = 0;
        for(int i = 0 ; i < n ; ++i){
            curr_alt += gain[i];
            max_alt = max(max_alt ,  curr_alt);
        }
        return max_alt;
    }
};