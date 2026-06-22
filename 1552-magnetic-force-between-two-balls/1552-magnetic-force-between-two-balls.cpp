class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int i = 0;
        int n = position.size();
        int j =  (position[n-1] +(m-2))/ (m-1);
        int mid = i + ((j-i) >> 1);
        while(i <= j){
            int currval = position[0];
            int total = 1;
            for(int pos : position){
                if(pos - currval  >= mid){ 
                    currval = pos;
                    ++total;
                }
                if(total >= m) break;
            }
            if(total >= m) i = mid + 1;
            else j = mid - 1;
            mid = i + ((j-i) >> 1);
        }
        return j;
    }
};