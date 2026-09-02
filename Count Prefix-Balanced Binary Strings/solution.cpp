class Solution {
  public:
    int mod = 1e9+7;
    int dp[2001][1000];
    int solve(int count, int idx, int size){
        if(idx >= size){
            if(count == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[count][idx] != -1){
            return dp[count][idx];
        }
        
        int take = 0;
        
        if(count == 0){
            take = (take + solve(count+1, idx+1, size)) % mod;
        }else if(count > 0){
            take = ((take + solve(count-1, idx+1, size)) % mod + solve(count+1, idx+1, size)) % mod;
        }
        
        return dp[count][idx] = take;
    }
    
    int prefixStrings(int n) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 2*n);
    }
};