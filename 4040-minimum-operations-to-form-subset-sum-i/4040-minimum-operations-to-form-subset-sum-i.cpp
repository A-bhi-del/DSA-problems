class Solution {
public:
    int INF = 1e9;
    int dp[101][5001];
    int solve(int idx, vector<int>& nums, int sum) {
        if (sum == 0){
            return 0;
        }

        if (idx >= nums.size()){
            return INF;
        }

        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }

        int ans = INF;
        ans = min(ans, solve(idx + 1, nums, sum));

        int ops = 0;

        for(long long temp = nums[idx]; temp <= sum; temp = 2 * temp) {
            ans = min(ans, ops + solve(idx + 1, nums, sum - temp));
            ops++;
        }

        ops = 0;

        for(long long temp = nums[idx]; temp > 0; temp = temp / 2) {
            if (temp <= sum && temp > 0) {
                ans = min(ans,  ops + solve(idx + 1, nums, sum - temp));
            }
            ops++;
        }

        return dp[idx][sum] = ans;
    }

    int minOperations(vector<int>& nums, int sum) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, nums, sum);

        return ans >= INF ? -1 : ans;
    }
};