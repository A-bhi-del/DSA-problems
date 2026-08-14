class Solution {
public:
    int dp[10][2][2][2];

    int solve(int idx, int tight, string& num, int count, int d, int started) {
        if (idx == num.length()) {
            return count == 0 ? 1 : 0;
        }

        if (dp[idx][tight][count][started] != -1){
            return dp[idx][tight][count][started];
        }

        int end = tight ? num[idx] - '0' : 9;
        int ans = 0;

        for(int digit = 0; digit <= end; digit++){
            int n_tight = tight && (digit == num[idx] - '0');
            int n_started = started || (digit != 0);
            int n_count = count;

            if (n_started && digit == d){
                n_count = 1;
            }

            ans += solve(idx + 1, n_tight, num, n_count, d, n_started);
        }

        return dp[idx][tight][count][started] = ans;
    }

    int countWithout(int n, int d) {
        memset(dp, -1, sizeof(dp));

        string num = to_string(n);

        int ans = solve(0, 1, num, 0, d, 0);

        return ans-1;
    }
};