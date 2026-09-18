class Solution {
  public:
    int dp[1001][1001];
    
    int solve(int i, int j, string& s1, string& s2){
        if(i >= s1.length() || j >= s2.length()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int take = 0;
        
        if(s1[i] == s2[j]){
            take = 1 + solve(i+1, j+1, s1, s2);
        }else{
            take = max({take, solve(i + 1, j, s1, s2), solve(i, j+1, s1, s2)});
        }
        
        return dp[i][j] = take;
    }
    
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        memset(dp, -1, sizeof(dp));
        
        int max_len = solve(0, 0, s1, s2);
        // cout<<max_len<<endl;
        
        return (s1.length() - max_len) * costS1 + (s2.length() - max_len) * costS2;
    }
};