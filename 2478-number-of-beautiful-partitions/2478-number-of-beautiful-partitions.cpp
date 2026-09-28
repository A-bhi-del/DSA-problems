class Solution {
public:
    int n;
    int mod = 1e9 + 7;

    int dp[1001][1001];

    bool is_prime(char ch){
        if(ch == '2' || ch == '3' || ch == '5' || ch == '7'){
            return true;
        }

        return false;
    }

    int solve(int idx, string& s, int k, int ml){
        if(k == 0){
            if(is_prime(s[idx]) && !is_prime(s[n-1]) && n - idx >= ml){
                return 1;
            }
        }
        if(idx >= n){
            return 0;
        }

        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        int take = 0;

        for(int i = idx; i < n; i++){
            if(i - idx + 1 >= ml && is_prime(s[idx]) && !is_prime(s[i]) && k > 0){
                take = (take + solve(i+1, s, k-1, ml)) % mod;
            }
        }

        return dp[idx][k] = take;
    }

    int beautifulPartitions(string s, int k, int minLength) {
        memset(dp, -1, sizeof(dp));
        n = s.length();

        return solve(0, s, k-1, minLength);
    }
};



//2170
//1187
//1250