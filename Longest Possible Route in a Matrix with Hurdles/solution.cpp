class Solution {
  public:
    vector<int>op_r = {-1,1,0,0};
    vector<int>op_c = {0,0,-1,1};
    
    int path_len = -1;
    
    void DFS(int xs, int ys, int xd, int yd, vector<vector<int>>& mat, vector<vector<int>>& vis, int& len){
        vis[xs][ys] = 1;
        
        if(xs == xd && ys == yd){
            path_len = max(path_len, len);
        }
        
        for(int i = 0; i < 4; i++){
            int nx = xs + op_r[i];
            int ny = ys + op_c[i];
            
            if(nx < 0 || nx >= mat.size() || ny < 0 || ny >= mat[0].size() || mat[nx][ny] == 0 || vis[nx][ny] == 1) continue;
            
            int n_len = len + 1;
            DFS(nx, ny, xd, yd, mat, vis, n_len);
        }
        
        vis[xs][ys] = 0;
    }
    
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        int len = 0;
        
        DFS(xs, ys, xd, yd, mat, vis, len);
        
        return path_len;
    }
};