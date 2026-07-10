class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n, -1);

        int count = 0;
        int i = 0;
        while (i < n) {
            if (comp[i] != -1)
                continue;
            comp[i] = count;
            int j = i;
            while (j + 1 < n && nums[j + 1] - nums[j] <= maxDiff) {
                comp[j + 1] = count;
                j++;
            }
            i = j + 1;
            count++;
        }

        int qn = queries.size();
        vector<bool> ans(qn);
        for (int j = 0; j < qn; j++) {
            ans[j] = comp[queries[j][0]] == comp[queries[j][1]];
        }
        return ans;
    }
};