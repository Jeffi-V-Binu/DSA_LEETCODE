class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bitset<102> mult;
        for(int i:nums){
            if(i % k == 0){
                mult[i / k] = true;
            }
        }
        int i = 1;
        while(mult[i]){
            ++i;
        }
        return k*i;
    }
};