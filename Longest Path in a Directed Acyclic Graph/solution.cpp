class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>>adj_LS(V);
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj_LS[u].push_back({v,w});
        }
        
        vector<int>max_len(V, INT_MIN);
        
        priority_queue<pair<int,int>>max_heap;
        max_heap.push({0, src});
        max_len[src] = 0;
        
        while(!max_heap.empty()){
            auto [weight, node] = max_heap.top();
            max_heap.pop();
            
            for(auto it : adj_LS[node]){
                int n_node = it.first;
                int n_w = it.second;
                
                if(max_len[n_node] < weight + n_w){
                    max_len[n_node] = weight + n_w;
                    max_heap.push({weight + n_w, n_node});
                }
            }
        }
        
        return max_len;
    }
};