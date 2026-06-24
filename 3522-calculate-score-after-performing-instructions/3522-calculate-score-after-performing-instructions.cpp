class Solution {
public:
    long long calculateScore(vector<string>& instruction, vector<int>& value) {
        int i = 0;
        long long score = 0;
        int n = value.size();

        while(i >= 0 && i < n){
            if(instruction[i] == "add" && value[i] != INT_MIN){
                int val = value[i];
                value[i] = INT_MIN;
                score += val;
                i++;
            }else if(instruction[i] == "jump" && value[i] != INT_MIN){
                // cout<<value[i]<<endl;
                int val = value[i];
                value[i] = INT_MIN;
                i = i + val;
            }else{
                break;
            }
        }

        return score;
    }
};