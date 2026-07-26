class Solution {
public:
    using ll = long long;
    using state = array<ll, 4>;
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<ll>>>vis(m, vector<vector<ll>>(n, vector<ll>(2, LLONG_MAX)));
        priority_queue<state, vector<state>, greater<state>>min_heap;

        min_heap.push({1, 0, 0, 1});
        vector<pair<int,int>>op_RD = {{0,1},{1,0}};

        while(!min_heap.empty()){
            auto [c, i, j, p] = min_heap.top();
            min_heap.pop();

            if(vis[i][j][p] <= c) continue;

            vis[i][j][p] = c;

            if(i == m-1 && j == n-1){
                return c;
            }

            if(p == 1){
                for(int k = 0; k < 2; k++){
                    int ni = i + op_RD[k].first;
                    int nj = j + op_RD[k].second;
                    
                    if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;

                    ll nc = c + (ni + 1) * (nj + 1);

                    if(vis[ni][nj][!p] <= nc) continue;

                    min_heap.push({nc, ni, nj, !p});
                }
            }else{
                ll nc = c + waitCost[i][j];

                if(vis[i][j][!p] <= nc) continue;

                min_heap.push({nc, i, j, !p});
            }
        }

        return -1;
    }
};