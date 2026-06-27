class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int , int> frequency ;
        long long track;
        int length = 0;
        int maxlen = 1;
        int n = nums.size();
        for(int i = 0 ; i < n ; ++i){
            frequency[nums[i]] ++;
        }
        if(frequency.find(1) != frequency.end()){
            length = frequency[1];
            if(length % 2 == 0){
                --length;
            }
            maxlen = max(maxlen , length);
            length = 0;
        }
        for(const auto& [base , count] : frequency){
            track = base;
            if(track == 1) continue;
            while(frequency.find(track) != frequency.end() && frequency[track] >= 2 && track < 1000000000){
                    track *= track;
                    length += 2;
                }
            if(frequency.find(track) != frequency.end() && frequency[track] == 1) ++length;
            else --length;
            maxlen = max(maxlen , length);
            length = 0;
        }
        return maxlen;
    }
};