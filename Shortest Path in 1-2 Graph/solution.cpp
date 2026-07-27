class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>>adj_LS(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj_LS[u].push_back({v, w});
            adj_LS[v].push_back({u, w});
        }
        
        vector<int>vis(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>min_heap;
        min_heap.push({0, src});
        
        while(!min_heap.empty()){
            auto [c, node] = min_heap.top();
            min_heap.pop();
            
            if(node == dest) return c;
            
            if(vis[node] <= c) continue;
            
            vis[node] = c;
            
            
            for(auto it : adj_LS[node]){
                int nnode = it.first;
                int nc = it.second;
                if(vis[nnode] < c + nc){
                    continue;
                }
                min_heap.push({c + nc, nnode});
            }
        }
        
        return -1;
    }
};