class Solution {
public:
    int dp[700];
    int solve(int prev, vector<vector<int>>& all_dime, int min_dime){
        if(prev != -1 && (all_dime[prev][1] <= min_dime || all_dime[prev][2] <= min_dime)){
            return 0;
        }
        
        if(dp[prev+1] != -1){
            return dp[prev+1];
        }
        
        int take = 0;
        
        for(int i = 0; i < all_dime.size(); i++){
            if(prev == -1 || (all_dime[i][1] < all_dime[prev][1] && all_dime[i][2] < all_dime[prev][2])){
                take = max({take, all_dime[i][0] + solve(i, all_dime, min_dime)});
            }
        }
        
        return dp[prev+1] = take;
    }
    
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // code here
        memset(dp, -1, sizeof(dp));
        
        int n = height.size();
        vector<vector<int>>all_dime;
        
        int min_dime = INT_MAX;
        
        for(int i = 0; i < n; i++){
            all_dime.push_back({height[i], width[i], length[i]});
            all_dime.push_back({width[i], height[i], length[i]});
            all_dime.push_back({width[i], length[i], height[i]});
            all_dime.push_back({height[i], length[i], width[i]});
            all_dime.push_back({length[i], height[i], width[i]});
            all_dime.push_back({length[i], width[i], height[i]});
            
            min_dime = min({min_dime, width[i], height[i], length[i]});
        }
        
        return solve(-1, all_dime, min_dime);
    }
};