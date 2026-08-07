class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    void union_nodes(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);

        if(parent_u == parent_v) return;

        if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }else{
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }

        for(int z = threshold + 1; z <= n; z++){
            for(int m = 2*z; m <= n; m += z){
                union_nodes(z, m);
            }
        }

        vector<bool> ans(queries.size(), false);

        for(int i = 0; i < queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];

            if(find(u) == find(v)){
                ans[i] = true;
            }
        }

        return ans;
    }
};