class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0;
        int sqSum = 0;
        int m = n;
        while(m != 0){
            int d = m % 10;
            m /= 10 ;
            digitSum += d;
            sqSum += (d*d);
        }
        if((sqSum - digitSum)>=50) return true;
        return false;
    }
};