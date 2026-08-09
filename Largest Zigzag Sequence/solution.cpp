class Solution {
  public:
    int dp[101][102];
    int solve(int r, int c, vector<vector<int>>& mat){
        if(r >= mat.size()){
            return 0;
        }
        
        if(dp[r][c+1] != -1) return dp[r][c+1];
        
        int temp = 1;
        if(c == -1) temp = 0;
        
        int ans = 0;
        int bound = mat.size() - 1 - c;
        for(int move = temp; move <= max(bound, c); move++){
            int prev = c - move;
            int aft = c + move;
            
            if(prev >= 0){
                ans = max(ans, mat[r][prev] + solve(r+1, prev, mat));
            }
            if(aft < mat[0].size()){
                ans = max(ans, mat[r][aft] + solve(r+1, aft, mat));
            }
        }
        
        return dp[r][c+1] = ans;
    }
    
    int zigzagSequence(vector<vector<int>>& mat) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(0,-1,mat);
    }
};