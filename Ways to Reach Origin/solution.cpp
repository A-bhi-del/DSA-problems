class Solution {
public:
    int dp[501][501];
    int mod = 1e9+7;
    
    int solve(int r, int c){
        if(r < 0 || c < 0){
            return 0;
        }
        
        if(r == 0 && c == 0){
            return 1;
        }
        
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        
        int left = solve(r-1, c);

        int down = solve(r, c - 1);
        
        return dp[r][c] = (left + down) % mod;
    }
    
    int ways(int x, int y) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(x, y);
    }
};