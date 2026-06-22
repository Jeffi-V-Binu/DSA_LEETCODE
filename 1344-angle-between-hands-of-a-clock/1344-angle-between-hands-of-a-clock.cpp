class Solution {
public:
    double angleClock(int hour, int minutes) {
        double result = abs(((hour %  12) * 30 ) - (minutes * 5.5));
        return min(result , 360.00 - result);
    }
};