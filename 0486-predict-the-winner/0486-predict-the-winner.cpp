class Solution {
public:
    int dp[21][21];

    int solve(int s, int e, vector<int>& nums){
        if(s > e) {
            return 0;
        }
        
        if(dp[s][e] != -1) {
            return dp[s][e];
        }

        int pick_s = nums[s] - solve(s+1, e, nums);
        int pick_e = nums[e] - solve(s, e-1, nums);

        return dp[s][e] = max(pick_s, pick_e);
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(0, n-1, nums) >= 0;
    }
};