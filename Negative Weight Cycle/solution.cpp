class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>dis(V, 0);

        for(int i = 0; i < V; i++){
            bool updated = false; 
            for(auto& edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(dis[u] + w < dis[v]){
                    updated = true;
                    dis[v] = dis[u] + w;
                }
            }
            
            if(!updated) break;
        }
        
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(dis[u] + w < dis[v]){
                return true;
            }
        }
        
        return false;
    }
};