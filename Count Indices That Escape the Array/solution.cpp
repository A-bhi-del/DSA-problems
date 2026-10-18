class Solution {
  public:
    int goodIndices(vector<int> &arr) {
        int n = arr.size();
        int cnt_good_idx = 0;

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis[i] != 0) continue;

            vector<int> path;
            int idx = i;
            bool is_good = false;

            while (true) {
                if (idx < 0 || idx >= n) {   
                    is_good = true;
                    break;
                }
                if (vis[idx] == 2) {
                    is_good = true;
                    break;
                }
                if (vis[idx] == 3 || vis[idx] == 1) {  
                    is_good = false;
                    break;
                }
                vis[idx] = 1;
                path.push_back(idx);
                idx = idx + arr[idx];
            }

            for (int node : path) {
                vis[node] = is_good ? 2 : 3;
            }
            
            if (is_good) cnt_good_idx += path.size();
        }

        return cnt_good_idx;
    }
};