class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> freq(n, 0);

        for (auto edge : edges) {
            int v = edge[1];

            freq[v]++;
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (freq[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};