class Solution {
public:
    vector<int>op_r = {0, 0, 1, -1};
    vector<int>op_c = {1, -1, 0, 0};

    bool check(vector<vector<int>>& grid, vector<vector<int>>& visited, long long minute){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));

        queue<vector<long long>>q;
        q.push({0, 0, minute});
        vis[0][0] = 1;

        while(!q.empty()){
            auto node = q.front();
            long long i = node[0];
            long long j = node[1];
            long long min = node[2];
            q.pop();

            if(i == n-1 && j == m-1){
                return true;
            }

            for(long long k = 0; k < 4; k++){
                long long ni = i + op_r[k];
                long long nj = j + op_c[k];

                if(ni >= 0 && ni < n && nj >= 0 && nj < m && vis[ni][nj] == 0 && grid[ni][nj] == 0){
                    if(ni == n-1 && nj == m-1 && visited[ni][nj] == min + 1){
                        q.push({ni, nj, min + 1});
                        vis[ni][nj] = 1;
                    }
                    if((min + 1 < visited[ni][nj] || visited[ni][nj] == -1)){
                        q.push({ni, nj, min + 1});
                        vis[ni][nj] = 1;
                    }
                }
            }
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, -1));
        queue<pair<int,int>>q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int ni = i + op_r[k];
                int nj = j + op_c[k];

                if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 0){
                    if(vis[ni][nj] != -1){
                        vis[ni][nj] = min(vis[ni][nj], vis[i][j] + 1);
                    }else{
                        vis[ni][nj] = vis[i][j] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        long long l = 0;
        long long h = 1e9;
        int ans = -1;

        while(l <= h){
            long long mid = l + (h - l)/2;

            if(check(grid, vis, mid)){
                ans = mid;
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }

        return ans;
    }
};

/*
0 2 0 0 1
0 2 0 2 2
0 2 0 0 0
0 0 2 2 0
0 0 0 0 0

*/