class Solution {
    public:
    int mod = 1e9+7;
    pair<int,int>solve(int i, int j, vector<vector<int>>& grid, vector<vector<pair<int,int>>>& dp){
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return {1,grid[i][j]};
        }
        
        if(i >= grid.size() || j >= grid[0].size()){
            return {0,0};
        }
        
        if(dp[i][j].first != -1 || dp[i][j].second != -1){
            return {dp[i][j].first, dp[i][j].second};
        }
        
        pair<int,int>right = solve(i, j+1, grid, dp);
        pair<int,int>down = solve(i+1, j, grid, dp);
        
        if(grid[i][j] == 1){
            return dp[i][j] = {right.first , (right.second + grid[i][j]) % mod};
        }else if(grid[i][j] == 2){
            return dp[i][j] = {down.first , (down.second + grid[i][j]) % mod};
        }
        
        int best = -1;

        if(right.first > 0){
            best = max(best, right.second);
        }
        
        if(down.first > 0){
            best = max(best, down.second);
        }
        
        return dp[i][j] = {(right.first + down.first) % mod, (best + grid[i][j]) % mod};
    }
    
    vector<int> findWays(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        vector<vector<pair<int,int>>>dp(n+1, vector<pair<int,int>>(n+1, {-1,-1}));
        pair<int,int>ans = solve(0,0,grid,dp);
        int f = ans.first;
        int s = ans.second;
        
        if(f == 0){
            s = 0;
        }
        
        return {f, s};
    }
};