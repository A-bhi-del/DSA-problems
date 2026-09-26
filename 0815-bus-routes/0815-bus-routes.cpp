class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < routes.size(); i++) {
            for (int route : routes[i]) {
                mp[route].push_back(i);
            }
        }
        if (source == target) {
            return 0;
        }

        if (!mp.count(source) || !mp.count(target)) {
            cout<<"i am"<<endl;
            return -1;
        }


        queue<int> q;
        unordered_set<int> busT;
        unordered_set<int> vis;
        int res = 0;

        q.push(source);

        while (!q.empty()) {
            res++;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                for (int it : mp[node]) {
                    if (busT.count(it)) {
                        continue;
                    }

                    busT.insert(it);

                    for (int nnode : routes[it]) {
                        if (vis.count(nnode)) {
                            continue;
                        }

                        if (nnode == target) {
                            return res;
                        }

                        q.push(nnode);
                        vis.insert(nnode);
                    }
                }
            }
        }

        return -1;
    }
};