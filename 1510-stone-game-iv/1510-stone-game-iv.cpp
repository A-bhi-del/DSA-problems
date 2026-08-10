class Solution {
public:
    int dp[100001];
    int solve(int n){
        if(n <= 0) return 0;

        if(dp[n] != -1){
            return dp[n];
        }

        int take = 0;

        for(int i = 1; i*i <= n; i++){
            int val = sqrt(n - i*i);
            if(val * val != (n - i*i) || (n - i*i) == 0){
                take = max(take, 1 - solve(n - i*i));
            }
        }

        return dp[n] = take;
    }

    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(n);
        cout<<ans<<endl;
        if(ans % 2 == 1) return true;
        return false;
    }
};