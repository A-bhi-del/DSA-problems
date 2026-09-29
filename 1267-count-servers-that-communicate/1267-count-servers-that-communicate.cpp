class Solution {
public:
    vector<int>op_r = {1,-1,0,0};
    vector<int>op_c = {0,0,-1,1};
    vector<int>parent;
    vector<int>rank;

    int find_parent(int a){
        if(parent[a] == a){
            return parent[a];
        }

        return parent[a] = find_parent(parent[a]);
    }

    void unite(int a, int b){
        int pa = find_parent(a);
        int pb = find_parent(b);

        if(pa == pb){
            return;
        }

        if(rank[pa] < rank[pb]){
            parent[pa] = pb;
            rank[pb] += rank[pa]; 
        }else{
            parent[pb] = pa;
            rank[pa] += rank[pb];
        }
    }

    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        parent.resize(n*m, 0);

        for(int i = 0; i < n*m; i++){
            parent[i] = i;
        }

        rank.resize(n*m, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 0) continue;

                for(int k = 0; k < m; k++){
                    if(k == j) continue;

                    if(grid[i][k] == 1){
                        unite(i*m + j, i*m + k);
                    }
                }

                for(int k = 0; k < n; k++){
                    if(k == i) continue;

                    if(grid[k][j] == 1){
                        unite(i*m + j, k*m + j);
                    }
                }
            }
        }

        unordered_set<int>st;
        int sum = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int parent = find_parent((i * m) + j);
                    if(!st.count(parent)){
                        if(rank[parent] > 1){
                            sum += rank[parent];
                        }
                        st.insert(parent);
                    }
                }
            }
        }

        return sum;
    }
};

// 