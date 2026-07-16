class Solution {
  public:
    int dp[10][82];
    int solve(int len, int n, int sum, int target){
        if(len == n){
            if(sum == target){
                return 1;
            }
            return 0;
        }
        
        if(dp[len][sum] != -1){
            return dp[len][sum];
        }
        
        int end = target <= 9 ? target : 9;
        
        int start = (len == 0) ? 1 : 0;
        
        int ans = 0;
        
        for(int k = start; k <= end; k++){
            ans += solve(len+1, n, sum + k, target);
        }
        
        return dp[len][sum] = ans;
    }
    
    int countWays(int n, int sum) {
        // code here
        memset(dp, -1, sizeof(dp));
        int res = solve(0, n, 0, sum);
        return res == 0 ? -1 : res;
    }
};