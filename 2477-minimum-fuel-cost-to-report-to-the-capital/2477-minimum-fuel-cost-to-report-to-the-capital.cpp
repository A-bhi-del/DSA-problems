class Solution {
public:
    int DFS(int node, unordered_map<int, vector<int>>& adj_LS, vector<int>& vis, int seats, long long& cost){
        vis[node] = 1;
        int size = 1;

        for(auto it : adj_LS[node]){
            if(vis[it] == 0){
                int childSize = DFS(it, adj_LS, vis, seats, cost);
                cost += (childSize + seats - 1) / seats;
                size += childSize;
            }
        }

        return size;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        unordered_map<int,vector<int>> adj_LS;

        for(auto road : roads){
            int a = road[0];
            int b = road[1];
            adj_LS[a].push_back(b);
            adj_LS[b].push_back(a);
        }

        vector<int> vis(n, 0);
        long long cost = 0;

        DFS(0, adj_LS, vis, seats, cost);

        return cost;
    }
};