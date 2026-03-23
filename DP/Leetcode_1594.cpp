// You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
// Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
// Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.
// Notice that the modulo is performed after getting the maximum product.

class Solution {
public:
// *********--------******************
    // int mod = 1e9 + 7;
    // long long max_res = LLONG_MIN;
    // void solve(int i, int j,long long multi, vector<vector<int>>& grid){
    //     if(i >= grid.size() || j >= grid[0].size()){
    //         return ;
    //     }

    //     long long n_multi = multi * 1LL * grid[i][j];

    //     if((i >= grid.size() - 1) && (j >= grid[0].size() - 1)){
    //         max_res = max(max_res, n_multi);
    //     }

    //     solve(i+1, j, n_multi, grid);

    //     solve(i, j+1,n_multi, grid);
    // }

// ************---------***************
    // long long max_dp[16][16];
    // long long min_dp[16][16];
    // int mod = 1e9+7;
    // vector<long long> solve(int i, int j, vector<vector<int>>& grid){
    //     if(i == grid.size() - 1 && j == grid[0].size() - 1){
    //         return {grid[i][j], grid[i][j]};
    //     }

    //     if(max_dp[i][j] != -1 && min_dp[i][j] != -1){
    //         return {max_dp[i][j], min_dp[i][j]};
    //     }

    //     long long max_val = LLONG_MIN;
    //     long long min_val = LLONG_MAX;

    //     if(j+1 < grid[0].size())
    //     {
    //         auto right = solve(i, j+1, grid);
    //         max_val = max({max_val, (grid[i][j] * right[0]) , (grid[i][j] * right[1])});
    //         min_val = min({min_val, (grid[i][j] * right[0]) , (grid[i][j] * right[1])});
    //     }

    //     if(i+1 < grid.size())
    //     {           
    //         auto down = solve(i+1, j, grid);
    //         max_val = max({max_val, (grid[i][j] * down[0]) , (grid[i][j] * down[1])});
    //         min_val = min({min_val, (grid[i][j] * down[0]) , (grid[i][j] * down[1])});
    //     }

    //     max_dp[i][j] = max_val;
    //     min_dp[i][j] = min_val;

    //     return {max_val, min_val};
    // }
    int mod = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        // memset(max_dp, -1, sizeof(max_dp));
        // memset(min_dp, -1, sizeof(min_dp));
        // vector<long long>ans = solve(0,0,grid);
        // return (max(ans[0], ans[1]) % mod < 0) ? -1 : max(ans[0], ans[1]) % mod;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>>max_dp(n + 1, vector<long long>(m,1));
        vector<vector<long long>>min_dp(n + 1, vector<long long>(m,1));

        min_dp[n-1][m-1] = max_dp[n-1][m-1] = grid[n-1][m-1];
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                long long max_val = LLONG_MIN;
                long long min_val = LLONG_MAX;

                if(i == n-1 && j == m-1){
                    continue;
                }

                if(i+1 < n){
                    long long downMax = max_dp[i+1][j];
                    long long downMin = min_dp[i+1][j];
                    max_val = max({max_val, downMax * grid[i][j], downMin * grid[i][j]});
                    min_val = min({min_val, downMax * grid[i][j], downMin * grid[i][j]});
                }

                if(j+1 < m){
                    long long rightMax = max_dp[i][j+1];
                    long long rightMin = min_dp[i][j+1];
                    max_val = max({max_val, rightMax * grid[i][j], rightMin * grid[i][j]});
                    min_val = min({min_val, rightMax * grid[i][j], rightMin * grid[i][j]});
                }

                min_dp[i][j] = min_val;
                max_dp[i][j] = max_val;
            }
        }


        return (max(min_dp[0][0], max_dp[0][0]) < 0) ? -1 : max(min_dp[0][0], max_dp[0][0]) % mod;
    }
};