class Solution {
public:
    vector<int>rank;
    vector<int>parent;

    int find(int n){
        if(parent[n] == n){
            return n;
        }

        return parent[n] = find(parent[n]);
    }

    void Ranking(int a, int b){
        int parent_a = find(a);
        int parent_b = find(b);

        if(parent_a == 1){
            parent[parent_b] = 1;
            return;
        }
        if(parent_b == 1){
            parent[parent_a] = 1;
            return;
        }
        
        if(rank[parent_a] < rank[parent_b]){
            parent[parent_b] = parent_a;
        }else if(rank[parent_a] < rank[parent_b]){
            parent[parent_a] = parent_b;
        }else{
            parent[parent_b] = parent_a;
            rank[parent_a]++;
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);

        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        int ans = INT_MAX;

        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int dis = road[2];
            Ranking(u, v);
        }
        
        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int dis = road[2];
            
            if(find(u) == 1 || find(v) == 1){
                ans = min(ans, dis);
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     int minScore(int n, vector<vector<int>>& roads) {
//         int edges = roads.size();

//         vector<vector<pair<int,int>>>adj_LS(n+1);

//         for(auto road : roads){
//             int u = road[0];
//             int v = road[1];
//             int dis = road[2];

//             adj_LS[u].push_back({v, dis});
//         }
//         vector<int>vis(n+1, 0);

//         queue<int>q;
//         q.push(1);
//         vis[1] = 1;
//         bool is_reachable = false;
//         int ans = INT_MAX;

//         while(!q.empty()){
//             int node = q.front();
//             q.pop();

//             if(node == n){
//                 is_reachable = true;
//             }

//             for(auto it : adj_LS[node]){
//                 int n_node = it.first;
//                 int n_dis = it.second;

//                 ans = min(ans, n_dis);

//                 if(vis[n_node] == 0){
//                     vis[n_node] = 1;
//                     q.push(n_node);
//                 }

//             }
//         }


//         return ans;
//     }
// };