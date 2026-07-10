class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long tm = mass;
        sort(asteroids.begin() , asteroids.end());
        for(const int& i : asteroids){
            if(i > tm) return false;
            tm += i;
        }
        return true;
    }
};