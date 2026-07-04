class Solution {
  public:
    int dp[100001];
    
    int solve(int idx, vector<int>& arr){
        if(idx >= arr.size()){
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int take = arr[idx] + solve(idx + 2, arr);
        int not_take = solve(idx+1, arr);
        
        return dp[idx] = max(take, not_take);
    }
    
    int findMaxSum(vector<int>& arr) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(0, arr);
    }
};