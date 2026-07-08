class Solution {
  public:
    vector<int>op_r = {-1,1,0,0};
    vector<int>op_c = {0,0,-1,1};
    
    void BFS(queue<pair<int,int>>& q, vector<vector<int>>& vis, vector<vector<int>>& mat){
        while(!q.empty()){
            auto node = q.front();
            int r = node.first;
            int c = node.second;
            
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nr = r + op_r[i];
                int nc = c + op_c[i];
                
                if(nr < 0 || nr >= mat.size() || nc < 0 || nc >= mat[0].size() || vis[nr][nc] != 0) continue;
                
                if(mat[r][c] <= mat[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    
    int countCoordinates(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>>staQ;
        queue<pair<int,int>>staP;
        
        vector<vector<int>>visP(n, vector<int>(m, 0));
        vector<vector<int>>visQ(n, vector<int>(m, 0));
        
        for(int c = 0; c < m; c++){
            staP.push({0, c});
            visP[0][c] = 1;
            
            staQ.push({n-1, c});
            visQ[n-1][c] = 1;
        }
        
        for(int r = 0; r < n; r++){
            staP.push({r, 0});
            visP[r][0] = 1;
            
            staQ.push({r, m-1});
            visQ[r][m-1] = 1;
        }
        
        BFS(staP, visP, mat);
        BFS(staQ, visQ, mat);
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visP[i][j] == 1 && visQ[i][j] == 1){
                    count++;
                }
            }
        }
        
        return count;
    }
};