class Solution {
  public:
    int dp[3][1001][1002];
    int mod = 1e9+7;
    
    int solve(int prev, int k, int n, int len){
        if(len >= n){
            
            if(k == 0){
                return 1;
            }
            
            return 0;
        }
        
        if(dp[prev+1][k][len] != -1){
            return dp[prev+1][k][len];
        }
        
        int ans = 0;
        
        for(int i = 0; i < 2; i++){
            if(prev == 1 && i == 1){
                ans = (ans + solve(i, k-1, n, len+1)) % mod;
            }else{
                ans = (ans + solve(i, k, n, len+1)) % mod;
            }
        }
        
        return dp[prev+1][k][len] = ans;
    }
    
    int countStrings(int n, int k) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(-1,k,n,0);
    }
};