// You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.
// Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.
// The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.
// Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        
        unordered_map<int, vector<pair<int,int>>>adj_LS;

        for(int i = 0; i < m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj_LS[u].push_back({v,w});
            adj_LS[v].push_back({u,2*w});
        }

        vector<int>result(n, INT_MAX);
        result[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == n-1){
                return result[node];
            }

            for(auto& it : adj_LS[node]){
                int nd = it.first;
                int n_dist = it.second;

                if(dist + n_dist < result[nd]){
                    result[nd] = dist + n_dist;
                    pq.push({dist+n_dist, nd});
                }
            }
        }

        return -1;
    }
};