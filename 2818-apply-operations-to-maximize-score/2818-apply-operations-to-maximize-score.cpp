class Solution {
public:
    long long powercal(long long base , long long exp){
        long long res = 1;
        base %= 1000000007;
        while(exp > 0 ){
            if(exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeCount (100001 , 0);
        long long score = 1;
        for(int i = 2; i < 100001; ++i){
            if(primeCount[i] == 0){
                for(int j = i ; j < 100001 ; j += i){
                    primeCount[j]++;
                }
            }
        }
        int n = nums.size();
        vector<vector<long long>> Counts(n , vector<long long>(3, 0));
        for(int i = 0 ; i < n ; ++i)
        {
            Counts[i][0] = primeCount[nums[i]];
            Counts[i][2] = nums[i];
        }
        vector<int>st;
        for(int i = 0 ; i < n ; ++i){
            while(!st.empty() && Counts[st.back()][0] < Counts[i][0]){
                st.pop_back();
            }
            if(!st.empty()) Counts[i][1] += (i - st.back()) ;
            else Counts[i][1] += (i + 1); 
            st.push_back(i);
        }
        st.clear();
        for(int i = n - 1 ; i >= 0 ; --i ){
            while(!st.empty() && Counts[st.back()][0] <= Counts[i][0]) st.pop_back();
            if(!st.empty()) Counts[i][1] *= (st.back() - i);
            else Counts[i][1] *= (n - i);
            st.push_back(i);
        }
        sort(Counts.begin() , Counts.end() , [](const vector<long long>&a , const vector<long long>&b){
            return a[2] > b[2];
        });
        for(int i = 0 ; i < n && k > 0 ; ++i){
            if(Counts[i][1] > k) {
                long long times = k;
                score = (score * powercal((long long)Counts[i][2] , times)) % 1000000007;
                k = 0;
            }
            else{
                long long times = Counts[i][1];
                score = (score * powercal((long long)Counts[i][2] , times)) % 1000000007;;
                k = k - Counts[i][1]; 
            }
        }
        score %= 1000000007;
        return score;
    }
};