class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        int n = arr.size();
        sort(temp.begin() , temp.end());
        unordered_map<int , int> aap;
        int count = 0;
        int prev = INT_MAX;
        for(int& i : temp){
            if(i != prev){
                prev = i;
                ++count;
                aap[i] = count;
            }
        }
        for(int i = 0 ; i < n ; ++i){
            arr[i] = aap[arr[i]];
        }
        return arr;
    }
};