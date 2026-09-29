class Solution {
public:
    vector<int>op_r = {0,1};
    vector<int>op_c = {1,0};

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>>q;
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(n + m, 0)));

        if(grid[0][0] == ')'){
            return false;
        }

        q.push({0, 0, 1});
        vis[0][0][1] = 1;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int i = node[0];
            int j = node[1];
            int open = node[2];

            if(i == n-1 && j == m-1 && open == 0){
                return true;
            }

            for(int k = 0; k < 2; k++){
                int ni = i + op_r[k];
                int nj = j + op_c[k];

                if(ni >= n || nj >= m) continue;

                int nopen;
                if(grid[ni][nj] == '(') nopen = open + 1;
                else nopen = open - 1;

                if(nopen < 0 || vis[ni][nj][nopen] == 1) continue;

                vis[ni][nj][nopen] = 1;
                q.push({ni, nj, nopen});
            }
        }

        return false;
    }
};

// [["(","(","(","(","("]
//  ["(","(",")",")",")"]
//  [")","(",")",")","("]
//  ["(","(",")",")",")"]]