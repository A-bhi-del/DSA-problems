class Solution {
public:
    vector<int> op_r = {1, 0, -1, 0};
    vector<int> op_c = {0, 1, 0, -1};
    int dp[76][76][80][5];
    int solve(int i, int j, vector<vector<int>>& grid, int k, int dir) {
        int n = grid.size();
        int m = grid[0].size();

        if(i == n - 1 && j == m - 1) {
            return grid[i][j];
        }

        if(dp[i][j][k][dir + 1] != -1) {
            return dp[i][j][k][dir + 1];
        }

        int ans = INT_MAX;

        for(int x = 0; x < 4; x++) {
            int ni = i + op_r[x];
            int nj = j + op_c[x];
            if(ni < 0 || nj < 0 || ni >= n || nj >= m) {
                continue;
            }

            int newK = k;

            if(dir == -1 || x == dir) {
                newK = k;
            }else if(x != dir) {
                if(k == 0) {
                    continue;
                }
                newK = k - 1;
            }

            int next = solve(ni, nj, grid, newK, x);

            if(next != INT_MAX) {
                ans = min(ans, grid[i][j] + next);
            }
        }

        return dp[i][j][k][dir + 1] = ans;
    }

    int minCost(vector<vector<int>>& grid, int k) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, grid, k, -1);

        if(ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};