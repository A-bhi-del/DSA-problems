class Solution {
public:
    const int NEG = -5000;

    unordered_map<long long, int>dp;
    long long change_key(int idx, int sum, int mul, bool taken, int parity){
        long long key = idx;

        key = key * 3602 + (sum + 1800);
        key = key * 5001 + mul;
        key = key * 2 + parity;
        key = key * 2 + taken;

        return key;
    }

    int solve(int idx, int sum, int mul, vector<int>& nums, int k, int limit,
              bool taken, int parity) {

        if (idx == nums.size()) {
            if (taken && sum == k && mul <= limit)
                return mul;
            return NEG;
        }

        long long key = change_key(idx, sum, mul, taken, parity);
        if (dp.count(key)){
                return dp[key];
        }

        int val = (parity == 0) ? nums[idx] : -nums[idx];

        int not_take = solve(idx + 1, sum, mul, nums, k, limit, taken, parity);

        long long nextMul = taken ? 1LL * mul * nums[idx] : nums[idx];

        nextMul = min(nextMul, 1LL * (limit + 1));

        int take = solve(idx + 1, sum + val, (int)nextMul, nums, k, limit, true, !parity);

        return dp[key] = max(take, not_take);
    }

    int maxProduct(vector<int>& nums, int k, int limit) {

        int total = 0;
        for (int x : nums)
            total += x;

        if (k > total || k < -total)
            return -1;

        dp.clear();

        int ans = solve(0, 0, 1, nums, k, limit, false, 0);

        return ans < 0 ? -1 : ans;
    }
};