class Solution {
public:
    int dp[501][501];
    int mod = 1e9+7;

    pair<int,int>check(int row, int col, vector<vector<int>>& grid, int dir){
        while(row < grid.size() && col < grid[0].size() && grid[row][col] == 1){
            if(dir == -1){
                col++;
                dir = 1;
            }else if(dir == 1){
                row++;
                dir = -1;
            }
        }

        if(row >= grid.size() || col >= grid[0].size()){
            return {-1, -1};
        }

        return {row, col};
    }

    int solve(int i, int j, vector<vector<int>>& grid){
        if(i >= grid.size() || j >= grid[0].size()){
            return 0;
        }

        if(i == grid.size()-1 && j == grid[0].size()-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;

        if(i+1 < grid.size() && grid[i+1][j] == 1){
            auto [r, c] = check(i+1, j, grid, -1);

            if(r != -1 && c != -1){
                ans = (ans + solve(r, c, grid)) % mod;
            }
        }else if(i+1 < grid.size() && grid[i+1][j] == 0){
            ans = (ans + solve(i+1, j, grid)) % mod;
        }

        if(j+1 < grid[0].size() && grid[i][j+1] == 1){
            auto [r, c] = check(i, j+1, grid, 1);

            if(r != -1 && c != -1){
                ans = (ans + solve(r, c, grid)) % mod;
            }
        }else if(j+1 < grid[0].size() && grid[i][j+1] == 0){
            ans = (ans + solve(i, j+1, grid)) % mod;
        }

        return dp[i][j] = ans % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();

        return solve(0,0,grid);
    }
};