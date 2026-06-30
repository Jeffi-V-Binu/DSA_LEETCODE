class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallnum = 1000000000;
        int oddc  = 0;
        for(const int& i: nums1){
            smallnum = min(smallnum , i);
            if(i%2 == 1) ++oddc;
        }
        if(smallnum % 2 == 0 && oddc) return false;
        return true;
    }
};