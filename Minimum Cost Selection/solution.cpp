class Solution {
  public:
    int dp[4][100001];
    int solve(int prev, int row, vector<vector<int>>& mat){
        if(row >= mat.size()){
            return 0;
        }
        
        if(dp[prev+1][row] != -1){
            return dp[prev+1][row];
        }
        int take = INT_MAX;
        
        for(int i = 0; i < 3; i++){
            if(prev == -1 || prev != i){
                take = min(take, mat[row][i] + solve(i, row+1, mat));
            }
        }
        
        return dp[prev+1][row] = take;
    }
    
    
    int minCost(vector<vector<int>>& mat) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(-1, 0, mat);
    }
};