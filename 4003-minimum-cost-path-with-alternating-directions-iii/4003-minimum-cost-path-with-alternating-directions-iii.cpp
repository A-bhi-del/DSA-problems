class Solution {
public:
    using ll = long long;
    using State = array<ll, 4>;
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<vector<ll>>> vis(
            m, vector<vector<ll>>(n, vector<ll>(2, LLONG_MAX)));
        priority_queue<State, vector<State>, greater<State>>
            min_heap;

        min_heap.push({1, 0, 0, 1});
        vector<pair<int, int>> op_LU = {{-1, 0}, {0, -1}};
        vector<pair<int, int>> op_RD = {{0, 1}, {1, 0}};

        while (!min_heap.empty()) {
            auto node = min_heap.top();
            ll c = node[0];
            int i = node[1];
            int j = node[2];
            int p = node[3];

            min_heap.pop();

            if (vis[i][j][p] <= c) {
                continue;
            }

            vis[i][j][p] = c;

            if (i == m - 1 && j == n - 1) {
                return c;
            }

            for (int k = 0; k < 2; k++) {
                int ni = i + op_LU[k].first;
                int nj = j + op_LU[k].second;

                if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                    continue;
                ll nc = c + (ni + 1) * (nj + 1);

                if (p == 1) {
                    nc += penalty[i][j];
                }

                if (vis[ni][nj][!p] <= nc)
                    continue;

                min_heap.push({nc, ni, nj, !p});
            }

            for (int k = 0; k < 2; k++) {
                int ni = i + op_RD[k].first;
                int nj = j + op_RD[k].second;

                if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                    continue;
                ll nc = c + (ni + 1) * (nj + 1);

                if (p == 0) {
                    nc += penalty[i][j];
                }

                if (vis[ni][nj][!p] <= nc)
                    continue;

                min_heap.push({nc, ni, nj, !p});
            }

            if (vis[i][j][!p] <= c + penalty[i][j])
                continue;

            min_heap.push({c + penalty[i][j], i, j, !p});
        }

        return -1;
    }
};