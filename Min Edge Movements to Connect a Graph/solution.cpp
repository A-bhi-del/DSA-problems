class Solution {
  public:
    vector<int>parent;
    vector<int>rank;
    
    int find(int node){
        if(node == parent[node]){
            return node;
        }
        
        return parent[node] = find(parent[node]);
    }
    
    void unite_nodes(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);
        
        if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }else{
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }
    
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        if(n-1 > edges.size()) return -1;
        parent.resize(n, 0);
        rank.resize(n, 0);
        
        for(int i = 0; i < n; i++) parent[i] = i;
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            unite_nodes(u, v);
        }
        
        unordered_set<int>st;
        
        for(int i = 0; i < n; i++) st.insert(find(i));
        
        // for(int i = 0; i < n; i++) cout<<parent[i]<<endl;
        
        int components = st.size();
        
        // cout<<components<<endl;
        
        return components - 1;
    }
};