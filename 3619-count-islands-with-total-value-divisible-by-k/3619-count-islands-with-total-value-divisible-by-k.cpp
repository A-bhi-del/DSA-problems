class Solution {
public:
    static constexpr int op_r[] = {1, -1, 0, 0};
    static constexpr int op_c[] = {0, 0, 1, -1};

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 || vis[i][j] == 1) continue;

                queue<pair<int,int>>q;
                q.push({i, j});
                long long sum = 0;
                vis[i][j] = 1;

                while(!q.empty()){
                    auto node = q.front();
                    q.pop();

                    int iidx = node.first;
                    int jidx = node.second;

                    sum += grid[iidx][jidx];

                    for(int k = 0; k < 4; k++){
                        int ni = iidx + op_r[k];
                        int nj = jidx + op_c[k];

                        if(ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni][nj] == 1 || grid[ni][nj] == 0) continue;

                        q.push({ni, nj});
                        vis[ni][nj] = 1;
                    }
                }

                if(sum % k == 0){
                    ans++;
                }
            }
        }

        return ans;
    }
};