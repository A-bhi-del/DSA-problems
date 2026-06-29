class Solution {
public:
    vector<int>op_r = {-1,1,0,0};
    vector<int>op_c = {0,0,-1,1};
    int max_len = INT_MIN;

    void DFS(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& vis, int len){
        for(int d = 0; d < 4; d++){
            int next_i = i + op_r[d];
            int next_j = j + op_c[d];

            if(next_i >= mat.size() || next_i < 0 || next_j >= mat[0].size() || next_j < 0 || vis[next_i][next_j] >= len+1 || mat[i][j] >= mat[next_i][next_j]) continue;

            vis[next_i][next_j] = len+1;
            DFS(next_i, next_j, mat, vis, len+1);
        }
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                DFS(i, j, matrix, vis, 1);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                max_len = max(max_len, vis[i][j]);
            }
        }

        return max_len;
    }
};