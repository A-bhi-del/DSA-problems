class Solution {
public:
    long long dp[100001][6];

    long long solve(int idx, int mul, vector<int>& nums, int k, int r){
        if(idx >= nums.size()){
            return 0;
        }

        if(dp[idx][mul] != -1){
            return dp[idx][mul];
        }

        long long skip = 0;
        long long take = 0;
        long long n_mul;

        if(mul == k){
            n_mul = nums[idx];
        }else{
            n_mul = (mul * nums[idx]) % k;
        }

        if(n_mul == r){
            take += 1;
        }

        take += solve(idx + 1, n_mul, nums, k, r);

        if(mul == k){
            skip = solve(idx + 1, k, nums, k, r);
        }

        return dp[idx][mul] = take + skip;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>ans(k, 0);

        for(int i = 0; i < n; i++){
            nums[i] = nums[i] % k;
        }

        for(int i = 0; i < k; i++){
            memset(dp, -1, sizeof(dp));
            ans[i] = solve(0, k, nums, k, i);
        }

        return ans;
    }
};

// 1 2 0 1 2 