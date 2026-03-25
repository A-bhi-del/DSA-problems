// You are given an integer array nums and an integer target.
// You may remove any number of elements from nums (possibly zero).
// Return the minimum number of removals required so that the bitwise XOR of the remaining elements equals target. If it is impossible to achieve target, return -1.
// The bitwise XOR of an empty array is 0.

class Solution {
public:
    int dp[41][16384];
    int solve(int idx, vector<int>& nums, int tar){
        if(idx >= nums.size()){
            if(tar == 0){
                return 0;
            }
            return -1e9;
        }

        if(dp[idx][tar] != -1){
            return dp[idx][tar];
        }

        int take = 1 + solve(idx + 1, nums, tar ^ nums[idx]);
        int not_take = solve(idx + 1, nums, tar);

        return dp[idx][tar] = max(take, not_take);
    }

    int minRemovals(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();

        if(solve(0, nums, target) < 0){
            return -1;
        }

        return n - solve(0, nums, target);

    }
};
       