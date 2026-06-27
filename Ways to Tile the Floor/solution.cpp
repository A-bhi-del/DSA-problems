class Solution {
  public:
    int dp[100001];
    int mod = 1e9+7;
    int solve(int idx, int n, int m){
        if(idx == n){
            return 1;
        }
        if(idx > n){
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int one_step = solve(idx+1, n, m);
        int m_step = solve(idx+m, n, m);
        
        return dp[idx] = (one_step + m_step) % mod;
    }
    
    int countWays(int n, int m) {
        // code here.
        memset(dp, -1, sizeof(dp));
        return solve(0,n,m);
    }
};