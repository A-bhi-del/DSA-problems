class Solution {
public:
    long long dp[100001][2][2]; 
    int n;

    long long solve(int idx, int is_start, int take, vector<vector<int>>& meet){
        if(idx >= n){
            if(take) return -1e18;   
            return 0;
        }

        if(dp[idx][is_start][take] != -1){
            return dp[idx][is_start][take];
        } 

        long long skip = solve(idx + 1, is_start, take, meet);

        if(take && is_start && idx < n - 1){
            skip += (meet[idx+1][0] - meet[idx][0]); 
        }

        int x = -1;
        int l = idx + 1;
        int h = n - 1;

        while(l <= h){
            int mid = l + (h - l) / 2;
            if(meet[mid][0] >= meet[idx][1]){ 
                x = mid; 
                h = mid - 1; 
            }
            else{
                l = mid + 1;
            } 
        }

        long long take_val = 0;

        if(x != -1){
            take_val = max(take_val, meet[idx][2] + (meet[x][0] - meet[idx][1]) + solve(x, 1, 1, meet));
        }

        take_val = max(take_val, meet[idx][2] + solve(x == -1 ? n : x, 1, 0, meet));

        return dp[idx][is_start][take] = max(take_val, skip);
    }

    long long maxEarnings(vector<vector<int>>& meetings) {
        memset(dp, -1, sizeof(dp));
        n = meetings.size();
        
        sort(meetings.begin(), meetings.end());
        return solve(0, 0, 0, meetings);
    }
};