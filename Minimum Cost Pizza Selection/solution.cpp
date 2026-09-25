class Solution {
  public:
    int dp[1000];
    int solve(vector<pair<int,int>>& pizza, int x){
        if(x <= 0){
            return 0;
        }
        
        if(dp[x] != -1){
            return dp[x];
        }
        
        int take = INT_MAX;
        
        for(int i = 0; i < pizza.size(); i++){
            take = min({take, pizza[i].second + solve(pizza, x - pizza[i].first)});
        }
        
        return dp[x] = take;
    }
    
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // code here
        memset(dp, -1, sizeof(dp));
        vector<pair<int, int>>pizza;
        
        pizza.push_back({s, cs});
        pizza.push_back({m, cm});
        pizza.push_back({l, cl});
        
        return solve(pizza, x);
    }
};