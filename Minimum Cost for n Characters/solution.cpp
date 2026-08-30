class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        // code here
        if(n == 1){
            return i;
        }
        
        vector<int>dp(n+1, INT_MAX);
        dp[1] = i;
        
        for(int len = 2; len <= n; len++){
            int ans = 0;
            if(len % 2 == 0){
                ans = min(dp[len-1] + i, dp[len/2] + c);
            }else{
                ans = min(dp[len-1] + i, dp[(len + 1)/2] + c + d);
            }
            
            dp[len] = ans;
        }
        
        return dp[n];
    }
};






