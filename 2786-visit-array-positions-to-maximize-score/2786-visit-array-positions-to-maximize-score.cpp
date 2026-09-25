class Solution {
public:
    long long dp[100001][2];
    long long solve(int idx, vector<int>& nums, int x, int parties){
        if(idx >= nums.size()){
            return 0;
        }

        if(dp[idx][parties] != -1){
            return dp[idx][parties];
        }

        long long take = 0;
        long long skip = 0;

        if(nums[idx] % 2 == parties){
            take = nums[idx] + solve(idx+1, nums, x, parties);
        }else{
            take = nums[idx] - x + solve(idx+1, nums, x, !parties);
        }

        if(idx != 0){
            skip = solve(idx + 1, nums, x, parties);
        }

        return dp[idx][parties] = max(take, skip);
    }

    long long maxScore(vector<int>& nums, int x) {
        memset(dp, -1, sizeof(dp));
        int parties = 0; // even

        if(nums[0] % 2 == 1){
            parties = 1; // odd
        }

        return solve(0, nums, x, parties);
    }
};