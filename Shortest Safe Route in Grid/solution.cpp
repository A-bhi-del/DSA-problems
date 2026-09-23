class Solution {
  public:
    vector<int>op_r = {0,0,-1,1};
    vector<int>op_c = {-1,1,0,0};

    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp = mat;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    for(int k = 0; k < 4; k++){
                        int ni = i + op_r[k], nj = j + op_c[k];
                        if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                        temp[ni][nj] = 0;
                    }
                }
            }
        }

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            if(temp[i][0] == 1){
                dist[i][0] = 1;
                q.push({i, 0});
            }
        }

        while(!q.empty()){
            auto [r, c] = q.front(); 
            q.pop();
            
            if(c == m-1) return dist[r][c];

            for(int k = 0; k < 4; k++){
                int ni = r + op_r[k]; 
                int nj = c + op_c[k];
                
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && temp[ni][nj] == 1){
                    if(dist[ni][nj] > dist[r][c] + 1){
                        dist[ni][nj] = dist[r][c] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return -1;
    }
};