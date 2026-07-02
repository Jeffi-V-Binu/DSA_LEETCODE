class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end() ,[](const auto& a , const auto& b){return a[1] < b[1];});
        int right_limit = points[0][1];
        int arr = 1;
        for(const auto& i: points){
            if(i[0] > right_limit){
                ++arr;
                right_limit = i[1];
            }
        }
        return arr;
    }
};