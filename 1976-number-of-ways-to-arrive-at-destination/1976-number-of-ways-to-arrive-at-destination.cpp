class Solution {
public:
    int mod = 1e9+7;
    using p = pair<long long, long long>;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<p>>adj_LS(n);

        for(auto road : roads){
            long long u = road[0];
            long long v = road[1];
            long long time = road[2];

            adj_LS[u].push_back({v, time});
            adj_LS[v].push_back({u, time});
        }

        priority_queue<p, vector<p>, greater<p>>min_heap;
        vector<long long>dis(n, LLONG_MAX);
        vector<long long>paths(n, 0);

        min_heap.push({0, 0});
        dis[0] = 0;
        paths[0] = 1;

        while(!min_heap.empty()){
            auto node = min_heap.top();
            long long time = node.first;
            long long ver = node.second;

            min_heap.pop();

            if(time > dis[ver]) continue;

            for(auto it : adj_LS[ver]){
                long long n_node = it.first;
                long long n_time = it.second;

                if(time + n_time < dis[n_node]){
                    dis[n_node] = time + n_time;
                    min_heap.push({time + n_time, n_node});
                    paths[n_node] = paths[ver];
                }else if(time + n_time == dis[n_node]){
                    dis[n_node] = time + n_time;
                    paths[n_node] = (paths[n_node] + paths[ver]) % mod;
                }
            }
        }

        return (int)paths[n-1];
    }
};