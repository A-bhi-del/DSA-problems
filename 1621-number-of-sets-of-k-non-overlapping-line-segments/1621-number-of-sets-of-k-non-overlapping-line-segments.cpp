class Solution {
public:
    int mod = 1e9+7;
    int dp[1005][1005];
    
    int solve(int idx, int k, int n){
        if(k == 0){
            return 1;
        }
        
        if(idx >= n-1){
            return 0;
        }

        if(dp[idx][k] != -1) return dp[idx][k];

        int take = 0;
        for(int i = idx+1; i < n; i++){
            if(k > 0){
                take = (take + solve(i, k-1, n)) % mod;
            }
        }

        int skip = solve(idx+1, k, n);

        return dp[idx][k] = (skip + take) % mod;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));

        return solve(0, k, n);
    }
};