class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> fcount(26 , 0);
        int m = tasks.size();
        int minidle;
        priority_queue<int> maxheap;
        for(char a: tasks){
            fcount[a - 'A']++;
        }
        for(int i : fcount) if(i != 0) maxheap.push(i);
        int time = 0;
        queue<pair<int , int>> cd;
        while(!maxheap.empty() || !cd.empty()){
            ++time;

            if(!maxheap.empty()){
                int count = maxheap.top() - 1;
                maxheap.pop();
                if(count > 0) cd.push({count , time + n});
            }

            if(!cd.empty() && cd.front().second == time){
                maxheap.push(cd.front().first);
                cd.pop();
            }
        }
        return time;
    }
};