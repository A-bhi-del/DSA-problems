class Solution {
  public:
    int mod = 1e9+7;

    int compute(int colors, int parts){
        long long ans = 1;
        for(int i = 0; i < parts; i++){
            ans = ans * (colors - i) % mod;
        }
        return ans;
    }
    
    int palindromicStrings(int n, int k) {
        // code here
        
        vector<vector<int>>dp(k+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= k; i++){
            dp[i][1] = i; 
        }
        
        for(int i = 1; i <= k; i++){
            for(int j = 2; j <= n; j++){
                if(i >= (j+1)/2){
                    dp[i][j] = (dp[i][j-1] + compute(i, (j+1)/2)) % mod;
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        
        return dp[k][n];
    }
};

/*
1 2 3 4 5 6 7 8 9 
2 4 6 8 8 8 8 8 8
3 6 12 18 
*/