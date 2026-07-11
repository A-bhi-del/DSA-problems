class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find_parent(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = find_parent(parent[node]);
    }

    void concatenate(int u, int v){
        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }else{
            parent[parent_u] = parent_v;
            rank[parent_v]++; 
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        parent.resize(n, 0);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto edge : edges){
            concatenate(edge[0], edge[1]);
        }
        
        unordered_map<int, unordered_set<int>>cmpt;
        unordered_map<int,int>cmpt_edges;

        for(int i = 0; i < n; i++){
            int parent = find_parent(i);

            cmpt[parent].insert(i);
        }

        for(auto edge : edges){
            int parent = find_parent(edge[0]);

            cmpt_edges[parent]++;
        }

        int total_compo = 0;

        for(auto it : cmpt){
            int node = it.first;
            int total_nodes = it.second.size();

            int expected_edges = (total_nodes * (total_nodes - 1))/2;

            if(cmpt_edges[node] == expected_edges){
                total_compo++;
            }
        }

        return total_compo;
    }
};