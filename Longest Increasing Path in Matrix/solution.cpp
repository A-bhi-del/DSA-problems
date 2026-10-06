class Solution {
public:
    vector<int>op_r = {1,-1,0,0};
    vector<int>op_c = {0,0,1,-1};

    int solve(int i, int j, vector<vector<int>>& mat, int n, int m, vector<vector<int>>& vis){
        if(vis[i][j] != 0){
            return vis[i][j];
        }

        int path = 1;

        for(int k = 0; k < 4; k++){
            int ni = i + op_r[k];
            int nj = j + op_c[k];

            if(ni < 0 || ni >= n || nj < 0 || nj >= m){
                continue;
            }

            if(mat[ni][nj] > mat[i][j]){
                path = max(path, 1 + solve(ni, nj, mat, n, m, vis));
            }
        }

        return vis[i][j] = path;
    }

    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        vector<vector<int>>vis(n, vector<int>(m, 0));

        int res = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res = max(res, solve(i, j, matrix, n, m, vis));
            }
        }

        return res;
    }
};