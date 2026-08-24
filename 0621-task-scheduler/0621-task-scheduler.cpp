class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> fcount(26 , 0);
        int m = tasks.size();
        int minidle;
        for(char a: tasks){
            fcount[a - 'A']++;
        }
        sort(fcount.begin(), fcount.end());
        int maxv = fcount[25];
        minidle = (maxv - 1) * n;
        for(int i = 24 ; i >= 0 ; --i){
            minidle -= min((maxv-1) , fcount[i]);
        }
        return max(m , (m + minidle));
    }
};