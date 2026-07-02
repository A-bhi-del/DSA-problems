class Solution {
  public:
    int dp[1001][2];
    bool solve(int idx, vector<int>& arr, int k, int sum, bool taken){
        if(idx >= arr.size()){
            if(taken && sum == 0){
                return true;
            }
            return false;
        }
        
        if(dp[sum][taken] != -1){
            return dp[sum][taken];
        }
        
        bool take = solve(idx + 1, arr, k, (sum + arr[idx]) % k, true);
        bool not_take = solve(idx + 1, arr, k, sum, taken);
        
        return dp[sum][taken] = take || not_take;
    }
    
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(0, arr, k, 0, false);
    }
};