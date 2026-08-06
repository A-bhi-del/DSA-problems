class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
        vector<int>dp(n+1, 0);
        
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + (i - 1)*dp[i-2];
        }
        
        return dp[n];
    }
};

// n = 4
// 1 2 3 4 -> 1, 2, 3, 4 -> 1
// 12 3 4, 13 2 4, 14 2 3, 1 23 4, 1 3 24, 1 2 34, 12 34, 13 24, 14 23 
// 
// 1 2 4 10 26