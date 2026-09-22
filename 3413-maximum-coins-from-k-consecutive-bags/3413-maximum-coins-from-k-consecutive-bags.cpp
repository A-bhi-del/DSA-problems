class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();

        sort(coins.begin(), coins.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        vector<long long> pre(n, 0);

        pre[0] = (long long)(coins[0][1] - coins[0][0] + 1) * coins[0][2];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }

        long long max_ans = 0;

        for (int j = 0; j < n; j++) {
            long long e = coins[j][1];
            long long st = e - k + 1;

            int l = 0;
            int h = j;
            int idxst = j;

            while (l <= h) {
                int mid = l + (h - l) / 2;

                if (coins[mid][1] >= st){
                    idxst = mid; 
                    h = mid - 1; 
                }
                else l = mid + 1;
            }

            long long before = (idxst > 0) ? pre[idxst - 1] : 0;

            long long partial = (long long)(coins[idxst][1] - max(st, (long long)coins[idxst][0]) + 1) * coins[idxst][2];

            long long right_ans = (pre[j] - before - ((long long)(coins[idxst][1]-coins[idxst][0]+1)*coins[idxst][2])) + partial;

            right_ans = (pre[j] - pre[idxst]) + partial;

            max_ans = max(max_ans, right_ans);

            long long s = coins[j][0];
            long long et = s + k - 1;

            l = j;
            h = n - 1;
            int idxet = j;

            while (l <= h) {
                int mid = l + (h - l) / 2;

                if (coins[mid][0] <= et){ 
                    idxet = mid; 
                    l = mid + 1; 
                }
                else h = mid - 1;
            }

            before = (j > 0) ? pre[j - 1] : 0;

            partial = (long long)(min(et, (long long)coins[idxet][1]) - coins[idxet][0] + 1) * coins[idxet][2];

            long long left_ans = ((idxet > 0) ? pre[idxet - 1] : 0) - before + partial;

            max_ans = max(max_ans, left_ans);
        }

        return max_ans;
    }
};