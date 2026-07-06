class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return 1;
        sort(intervals.begin(), intervals.end() , [](const auto& a , const auto& b){
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        int end = 0;
        int result = 0;
        for(const auto& i : intervals){
            if(i[1] > end){
                end = i[1];
                ++result;
            }
        }
        return result;
    }
};