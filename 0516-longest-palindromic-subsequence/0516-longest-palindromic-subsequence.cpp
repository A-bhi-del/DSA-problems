class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string actual_s = s;
        reverse(s.begin(), s.end());
        vector<vector<int>>dp(s.length()+1, vector<int>(s.length()+1, 0));

        for(int i = 1; i < s.length()+1; i++){
            for(int j = 1; j < s.length()+1; j++){
                if(actual_s[i-1] == s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }


        return dp[s.length()][s.length()];
    }
};