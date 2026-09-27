class Solution {
public:
    int dp[50001];
    int n;

    int solve(int idx, vector<vector<int>>& tr){
        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        int x = n;
        int l = idx + 1;
        int h = n - 1;

        while(l <= h){
            int mid = l + (h - l) / 2;
            if(tr[mid][0] >= tr[idx][1]){ 
                x = mid; 
                h = mid - 1; 
            }
            else{
                l = mid + 1;
            } 
        }

        int take = tr[idx][2] + solve(x, tr);
        int skip = solve(idx + 1, tr);

        return dp[idx] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        n = startTime.size();

        vector<vector<int>>triple;

        for(int i = 0; i < n; i++){
            triple.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(triple.begin(), triple.end());

        return solve(0, triple);
    }
};