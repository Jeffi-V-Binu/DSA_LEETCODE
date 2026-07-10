class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long tm = mass;
        vector<int> count(100001 , 0);
        for(int& i : asteroids){
            ++count[i];
        }
        for(int i = 0 ; i < 100001 ; ++i){
            int k = count[i];
            if(k){
                if(tm < i) return false;
                for(int j = 0 ; j < k ; ++j) tm += i;
            }
        }
        return true;
    }
};