class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answers(n , "");
        for(int i = 0 ; i < n ; ++i){
            int a = (i+1)%3;
            int b = (i+1)%5;
            if(a && b){
                answers[i] = to_string(i+1);
            }
            else{
                if(!a && b){
                    answers[i] = "Fizz";
                }
                else if(!b && a){
                    answers[i] = "Buzz";
                }
                else{
                    answers[i] = "FizzBuzz";
                }
            }
        }
        return answers;
    }
};