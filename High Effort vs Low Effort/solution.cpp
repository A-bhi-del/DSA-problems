class Solution {
  public:
    int dp[100001][2];
    int solve(int idx, vector<int>& h, vector<int>& l, bool taken){
        if(idx >= h.size()){
            return 0;
        }
        
        if(dp[idx][taken] != -1) return dp[idx][taken];
        
        int take = 0;
        
        take = l[idx] + solve(idx + 1, h, l, true);
        
        if(taken == false || idx == 0){
            take = max(take, h[idx] + solve(idx + 1, h, l, true));
        }
        
        int not_take = solve(idx + 1, h, l, false);
        
        return dp[idx][taken] = max(take, not_take);
    }
    
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(0, h, l, false);
    }
};