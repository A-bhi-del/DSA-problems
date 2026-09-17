class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // code here  
        vector<vector<pair<int,int>>>adj_LS(n + 1);
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj_LS[u].push_back({v,0});
            adj_LS[v].push_back({u,1});
        }
        
        vector<int>dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        
        q.push({0, src});
        dist[src] = 0;
        
        while(!q.empty()){
            auto node = q.top();
            q.pop();
            
            int cost = node.first;
            int next = node.second;
            
            if(cost > dist[next]){
                continue;
            }
            
            if(next == dst){
                return cost;
            }
            
            for(auto it : adj_LS[next]){
                int ncost = cost + it.second;
                int nnext = it.first;
                
                if(dist[nnext] > ncost){
                    dist[nnext] = ncost;
                    q.push({ncost, nnext});
                }
            }
        }
        
        return -1;
    }
};