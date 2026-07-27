class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        unordered_map<int, int> mp;
        for (int b : balls){
            mp[b]++;
        }

        int min_freq = INT_MAX;
        for (auto& it : mp){
            min_freq = min(min_freq, it.second);
        }

        for (int x = min_freq; x >= 1; x--) {
            int count = 0;
            bool ok = true;
            for (auto& it : mp) {
                int f = it.second;
                int a = f / (x + 1);
                int b = f % (x + 1);
                if (b == 0) {
                    count += a;
                } else if (x - b <= a) {
                    count += a + 1;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok)
                return count;
        }
        return -1;
    }
};