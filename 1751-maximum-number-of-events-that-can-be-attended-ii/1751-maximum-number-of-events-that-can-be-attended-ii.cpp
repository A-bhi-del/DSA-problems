class Solution {
public:
    int n;

    int solve(int idx, vector<vector<int>>& events, int k, vector<vector<int>>& dp){
        if(idx >= n){
            if(k >= 0){
                return 0;
            }
            return -1e9;
        }

        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        int x = n;
        int l = idx + 1;
        int h = n-1;

        while(l <= h){
            int mid = l + (h - l)/2;

            if(events[mid][0] > events[idx][1]){
                x = mid;
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        int take = 0;

        if(k > 0){
            take = events[idx][2] + solve(x, events, k-1, dp);
        }

        int skip = solve(idx + 1, events, k, dp);

        return dp[idx][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();

        sort(events.begin(), events.end());

        vector<vector<int>>dp(n, vector<int>(k+1, -1));

        return solve(0, events, k, dp);
    }
};