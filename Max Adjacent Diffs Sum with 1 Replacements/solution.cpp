class Solution {
  public:
    int dp[100001][2];
    int solve(int idx, vector<int>& nums, int flip){
        if(idx >= nums.size()){
            return 0;
        }
        
        if(dp[idx][flip] != -1){
            return dp[idx][flip];
        }
        
        int take = 0;
        
        if(idx == 1){
            take = max({take, abs(nums[idx] - nums[idx-1]) + solve(idx+1, nums, 0), abs(nums[idx] - 1) + solve(idx+1, nums, 0), abs(nums[idx-1] - 1) + solve(idx+1, nums, 1)});
        }else if(flip == 0){
            take = max({take, abs(nums[idx] - nums[idx-1]) + solve(idx + 1, nums, flip), abs(nums[idx-1] - 1) + solve(idx+1, nums, !flip)});
        }else{
            take = max({take, abs(nums[idx] - 1) + solve(idx+1, nums, !flip), solve(idx + 1, nums, flip)});
        }
        
        return dp[idx][flip] = take;
    }
    
    int maxDiffSum(vector<int>& arr) {
        // code here
        memset(dp, -1, sizeof(dp));
        int n = arr.size();
        
        if(n == 1){
            return 0;
        }
        
        return solve(1, arr, 0);
    }
};

// 3 2 1 4 5