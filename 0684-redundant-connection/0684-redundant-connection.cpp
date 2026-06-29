class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unite(int node1, int node2){
        int parent_x = find(node1);
        int parent_y = find(node2);

        if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }else if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1, 0);
        rank.resize(n+1,0);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(find(u) == find(v)){
                return {u, v};
            }

            unite(u, v);
        }

        return {};
    }
};