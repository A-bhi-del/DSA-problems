class Solution {
public:
    int dp[51][51];
    bool solve(int r, int c, int n, vector<vector<int>>& mat, vector<vector<int>>& ans) {
        if (r == n - 1 && c == n - 1) {
            ans[r][c] = 1;
            return true;
        }
        
        if(dp[r][c] != -1){
            return dp[r][c];
        }

        ans[r][c] = 1;

        for (int jump = 1; jump <= mat[r][c]; jump++) {
            int nc = c + jump;
            int nr = r + jump;

            if (nc < n && mat[r][nc] != 0) {
                if (solve(r, nc, n, mat, ans)){
                    return dp[r][c] = true;
                }
            }
            
            if (nr < n && mat[nr][c] != 0) {
                if (solve(nr, c, n, mat, ans)){
                    return dp[r][c] = true;
                }
            }
        }

        ans[r][c] = 0;
        
        return dp[r][c] = false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        memset(dp, -1, sizeof(dp));
        int n = mat.size();

        if (mat[0][0] == 0)
            return {{-1}};

        vector<vector<int>> ans(n, vector<int>(n, 0));

        if (solve(0, 0, n, mat, ans)){
            return ans;
        }

        return {{-1}};
    }
};