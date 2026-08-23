class Solution {
  public:
    vector<int>op_r = {1, -1, 0, 0};
    vector<int>op_c = {0, 0, 1, -1};
    
    // void DFS(int r, int c, int u, int d, vector<vector<char>>& mat, vector<vector<int>>& vis, int& Free_cells){
    //     int n = mat.size();
    //     int m = mat[0].size();
    //     vis[r][c] = 1;
    //     Free_cells++;
        
    //     for(int i = 0; i < 4; i++){
    //         int nr = r + op_r[i];
    //         int nc = c + op_c[i];
            
    //         if(nr < 0 || nr >= n || nc < 0 || nc >= m || mat[nr][nc] == '#') continue;
            
    //         if(i == 0){
    //             if(d > 0 && vis[nr][nc] == 0){
    //                 DFS(nr, nc, u, d-1, mat, vis, Free_cells);
    //             }
    //         }else if(i == 1){
    //             if(u > 0 && vis[nr][nc] == 0){
    //                 DFS(nr, nc, u-1, d, mat, vis, Free_cells);
    //             }
    //         }else{
    //             if(vis[nr][nc] == 0){
    //                 DFS(nr, nc, u, d, mat, vis, Free_cells);
    //             }
    //         }
    //     }
    // }
    
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        if(mat[r][c] == '#'){
            return 0;
        }
        
        int Free_cells = 1;
        
        vector<vector<int>> bestUp(n, vector<int>(m, -1));
        vector<vector<int>> bestDown(n, vector<int>(m, -1));
    
        queue<vector<int>>q;
    
        q.push({r, c, u, d});
        bestUp[r][c] = u;
        bestDown[r][c] = d;

        vector<int>op_r = {1, -1, 0, 0};
        vector<int>op_c = {0, 0, 1, -1};
    
        while(!q.empty()){
            auto node = q.front();
            int row = node[0];
            int col = node[1];
            int up = node[2];
            int down = node[3];
    
            q.pop();
    
            for(int i = 0; i < 4; i++){
                int nr = row + op_r[i];
                int nc = col + op_c[i];
    
                if(nr < 0 || nr >= n || nc < 0 || nc >= m || mat[nr][nc] == '#') continue;
    
                int nup = up, ndown = down;
    
                if(i == 0){
                    if(down <= 0) continue;
                    ndown = down - 1;
                } else if(i == 1){
                    if(up <= 0) continue;
                    nup = up - 1;
                }
    
                if(bestUp[nr][nc] >= nup && bestDown[nr][nc] >= ndown) continue;
    
                bool firstTime = (bestUp[nr][nc] == -1); 
                if(firstTime) Free_cells++;
    
                bestUp[nr][nc] = max(bestUp[nr][nc], nup);
                bestDown[nr][nc] = max(bestDown[nr][nc], ndown);
                q.push({nr, nc, nup, ndown});
            }
        }
        return Free_cells;
    }
};




        // queue<vector<int>>q;
        
        // q.push({r, c, u, d});
        // vis[r][c] = 1;
        
        // vector<int>op_r = {1, -1, 0, 0};
        // vector<int>op_c = {0, 0, 1, -1};
        
        // while(!q.empty()){
        //     auto node = q.front();
        //     int row = node[0];
        //     int col = node[1];
        //     int up = node[2];
        //     int down = node[3];
        //     Free_cells++;
            
        //     q.pop();
            
        //     for(int i = 0; i < 4; i++){
        //         int nr = row + op_r[i];
        //         int nc = col + op_c[i];
                
        //         if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] == 1 || mat[nr][nc] == '#') continue;
                
        //         if(i == 0){
        //             if(down > 0){
        //                 q.push({nr, nc, up, down-1});
        //                 vis[nr][nc] = 1;
        //             }
        //         }else if(i == 1){
        //             if(up > 0){
        //                 q.push({nr, nc, up-1, down});
        //                 vis[nr][nc] = 1;
        //             }
        //         }else{
        //             q.push({nr, nc, up, down});
        //             vis[nr][nc] = 1;
        //         }
                
        //     }
        // }