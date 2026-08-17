class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int last = n * n;
        
        unordered_map<int,int>mp;
        for(int i = 0; i < lad.size(); i += 2){
            mp[lad[i]] = lad[i + 1];
        }

        for(int i = 0; i < sn.size(); i += 2){
            mp[sn[i]] = sn[i + 1];
        }

        vector<bool> vis(last + 1, false);
        queue<pair<int, int>> q;

        q.push({1, 0});
        vis[1] = true;

        while (!q.empty()) {
            auto [pos, t] = q.front();
            q.pop();

            if (pos == last) {
                return t;
            }

            for (int dice = 1; dice <= 6; dice++) {
                int n_pos = pos + dice;

                if (n_pos > last) {
                    continue;
                }

                if (mp.count(n_pos) != 0) {
                    n_pos = mp[n_pos];
                }

                if (!vis[n_pos]) {
                    vis[n_pos] = true;
                    q.push({n_pos, t + 1});
                }
            }
        }

        return -1;
    }
};