class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int>dp(n+1, 0);
        
        for(int i = 0; i < n; i++){
            if(dp[arr[i] - 1] != 0){
                dp[arr[i]] += 1 + dp[arr[i] - 1];
            }else{
                dp[arr[i]] = 1;
            }
        }
        
        int LCS = 0;
        
        for(int i = 0; i <= n; i++){
            LCS = max(LCS, dp[i]);
        }
        
        return n - LCS;
    }
};