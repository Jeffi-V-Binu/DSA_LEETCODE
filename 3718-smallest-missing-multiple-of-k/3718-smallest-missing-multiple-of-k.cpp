class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> mult(101 , false);
        for(int& i:nums){
            if(i  % k == 0){
                mult[(i / k) - 1] = true;
            }
        }
        int i;
        for(i = 0 ; i < 100 ; i++){
        if(!mult[i]) break; 
        }
        return k*(i + 1);
    }
};