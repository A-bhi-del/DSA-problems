class Solution {
  public:
    void solve(int e, vector<int>& ans, int digit, int len, int prev_digit){
        if(len == e){
            ans.push_back(digit);
            return ;
        }

        for(int i = 1; i <= 9; i++){
            if(i > prev_digit){
               int n_digit = digit * 10 + i;
               int n_len = len + 1;
               solve(e, ans, n_digit, n_len, i); 
            }
        }
    }
    
    vector<int> increasingNumbers(int n) {
        // code here
        if(n > 9){
            return {};
        }
        vector<int>ans;
        
        if(n == 1){
            ans.push_back(0);
        }
        
        solve(n, ans, 0, 0, -1);
        
        return ans;
    }
};