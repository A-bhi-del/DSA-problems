class Solution {
public:
    // int dp[50001][51];
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // sort(edges.begin(), edges.end(), [](vector<int>& e1, vector<int>& e2){
        //     return e1[2] < e2[2];
        // });

        vector<vector<long long>>dp(n, vector<long long>(k+1, LLONG_MAX));

        vector<vector<pair<int, int>>> adj_LS(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj_LS[u].push_back({v, w});
        }

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>>
            min_heap;

        // vector<int> parent(n, 0);

        // for(int i = 0; i < n; i++){
        //     parent[i] = i;
        // }

        int src = 0;
        int dest = n - 1;
        dp[src][0] = 0;

        min_heap.push({0, src, k});

        while (!min_heap.empty()) {
            auto node = min_heap.top();
            min_heap.pop();

            long long weight = node[0];
            long long node_val = node[1];
            long long oper = node[2];

            if(dp[node_val][oper] < weight){
                continue;
            }

            for (auto& it : adj_LS[node_val]) {
                int n_node = it.first;
                long long n_weight = it.second;
                long long w = weight + n_weight;
                // cout << "i am runnig 2" << endl;
                
                if (labels[node_val] == labels[n_node] && oper > 1) {
                    // cout << "i am runnig 3" << " " << n_node << endl;
                    if(w < dp[n_node][oper-1]){
                        dp[n_node][oper-1] = w;
                        min_heap.push({w, n_node, oper - 1});
                    }
                } else if (labels[node_val] != labels[n_node]) {
                    // cout << "i am runnig 4" << " " << n_node << endl;
                    if(w < dp[n_node][k]){
                        dp[n_node][k] = w;
                        min_heap.push({w, n_node, k});
                    }
                }
            }
        }

        long long ans = LLONG_MAX;

        for(int i = 0; i <= k; i++){
            ans = min(ans, dp[n-1][i]);
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};