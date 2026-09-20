class Solution {
public:
    long long dp[100001][2];

    long long solve(int idx, vector<int>& nums, vector<int>& colors, int kept){
        if(idx >= nums.size()){
            return 0;
        }

        if(dp[idx][kept] != -1){
            return dp[idx][kept];
        }

        long long take = 0;

        if(idx == 0 || (colors[idx] != colors[idx-1] && kept == 1) || kept == 0){
            take = nums[idx] + solve(idx + 1, nums, colors, 1);
        }

        long long skip = solve(idx + 1, nums, colors, 0);
        
        return dp[idx][kept] = max(take, skip);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, colors, 0);
    }
};