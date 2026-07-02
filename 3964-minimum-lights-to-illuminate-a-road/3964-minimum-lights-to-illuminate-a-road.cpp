class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        if(n == 1 && lights[0]) return 0;
        vector<int> flags(n , 0);
        for(int i = 0 ; i < n ; ++i){
            if(lights[i] > 0){
                flags[max(0 , i - lights[i])]++;
                flags[min(i + lights[i] , n - 1)]--;
            }   
        }
        int total = 0;
        int count = 0;
        int sum = 0;
        for(int i = 0 ; i < n ; ++i){
            if(sum != 0 && sum+flags[i] == 0 ) --count;
            sum += flags[i];
            if(sum == 0) ++count;
            else{
                while(count != 0){
                    ++total;
                    count = max(0 , count - 3);
                }
            }
        }
        while(count != 0){
            ++total;
            count = max(0 , count - 3);
        }
        return total;
    }
};