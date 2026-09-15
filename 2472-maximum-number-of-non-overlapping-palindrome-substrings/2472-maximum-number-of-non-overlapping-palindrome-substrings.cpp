class Solution {
public:
    // int dp[2001][2001];
    // bool is_palin(int s, int e, string& ss){
    //     while(s <= e){
    //         if(ss[s] != ss[e]){
    //             return false;
    //         }
    //         s++;
    //         e--;
    //     }
    //     return true;
    // }

    // int solve(int i, int j, string& s, int k){
    //     if(j >= s.length() || i >= s.length()){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int take = 0;

    //     if(is_palin(i, j, s)){
    //         take = 1 + solve(j+1, j+k, s, k);
    //     }

    //     int extend = solve(i, j+1, s, k);
    //     int skip = solve(i+1, j+1, s, k);

    //     return dp[i][j] = max({take, extend, skip});
    // }

    int maxPalindromes(string s, int k) {
        // memset(dp, -1, sizeof(dp));
        int n = s.length();

        vector<vector<bool>>substring(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++){
            substring[i][i] = true;
        }

        for(int len = 2; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                int j = i + len - 1;

                if(len == 2){
                    if(s[i] == s[j]){
                        substring[i][j] = true;
                    }
                }else{
                    if(s[i] == s[j] && substring[i+1][j-1] == true){
                        substring[i][j] = true;
                    }
                }
            }
        }

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= k-1; i--){
            for(int j = i - k + 1; j >= 0; j--){
                int take = 0;
                if(substring[j][i] && i-j+1 >= k){
                    take = (i+k <= n) ? 1 + dp[i+k][i+1] : 1;
                }
                int extend = dp[i+1][j];
                int skip = dp[i+1][j+1];

                dp[i][j] = max({take, extend, skip});
            }
        }

        return dp[k-1][0];
    }
};