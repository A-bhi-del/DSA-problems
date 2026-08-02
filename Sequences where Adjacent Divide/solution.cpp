class Solution {
  public:
    int dp[12][12];
    int solve(int size, int values, int len = 0, int prev = 0){
        if(dp[len][prev] != -1){
            return dp[len][prev];
        }
        
        if(len == size){
            return 1;
        }
        
        int take = 0;
        
        for(int i = 1; i <= values; i++){
            if(prev % i == 0 || i % prev == 0){
                take += solve(size, values, len+1, i);
            }
        }
        
        return dp[len][prev] = take;
    }
    
    int count(int n, int m) { 
       // code here 
        memset(dp, -1, sizeof(dp));
        return solve(n, m);
        // vector<vector<int>>dp(n+1, vector<int>(m+2, -1)); 
        
        // for(int i = 0; i < m+2; i++){ 
        //     dp[n][i] = 1; 
            
        // } 
        
        // for(int len = n-1; len >= 0; len--){ 
        //     for(int prev = -1; prev <= m; prev++){ 
                
        //         if(prev == 0) continue; int take = 0; 
                
        //         for(int i = 1; i <= m; i++){ 
        //             if(prev == -1 || prev % i == 0 || i % prev == 0){ 
        //                 take += dp[len+1][i+1]; 
        //             } 
        //         } 
                
        //         dp[len][prev+1] = take; 
        //     } 
        // }
        
        // return dp[0][0];
    }
};