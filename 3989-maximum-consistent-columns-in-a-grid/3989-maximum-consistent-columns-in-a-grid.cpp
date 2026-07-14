class Solution {
public:
    int dp[251][251];
    bool isvalid(int prev, int curr, vector<vector<int>>& grid, int limit) {
        int m = grid.size();
        for (int i = 0; i < m; i++) {
            if (abs(grid[i][curr] - grid[i][prev]) > limit) {
                return false;
            }
        }
        return true;
    }

    int solve(vector<vector<int>>& grid, int prev, int curr, int limit) {
        int m = grid.size();
        int n = grid[0].size();

        if (curr == n) {
            return 0;
        }

        if (dp[prev + 1][curr] != -1) {
            return dp[prev + 1][curr];
        }

        int not_take = solve(grid, prev, curr + 1, limit);

        int take = 0;

        if (prev == -1 || isvalid(prev, curr, grid, limit)) {
            take = 1 + solve(grid, curr, curr + 1, limit);
        }

        return dp[prev + 1][curr] = max(take, not_take);
    }

    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        memset(dp, -1, sizeof(dp));

        int m = grid.size();
        int n = grid[0].size();

        return solve(grid, -1, 0, limit);
    }
};