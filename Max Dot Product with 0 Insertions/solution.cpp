class Solution {
  public:
    int solve(int i, int j, vector<int>& a, vector<int>& b, vector<vector<int>>& dp){
        if(j >= b.size()){
            return 0;
        }
            
        if(i >= a.size()){
            return INT_MIN;
        }
        
        if(dp[i][j] != INT_MIN){
            return dp[i][j];
        }
        
        int take = 1LL* a[i] * b[j] + solve(i+1, j+1, a, b,dp);
        int not_take = solve(i+1, j, a, b,dp);
        
        return dp[i][j] = max(take, not_take);
    }
    
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int an = a.size();
        int bn = b.size();
        
        vector<vector<int>>dp(an, vector<int>(bn, INT_MIN));
        
        return solve(0,0,a,b, dp);
    }
};

        // int an = a.size();
        // int bn = b.size();
        
        // int ele_req = an - bn;
        
        // vector<pair<int,int>>mp;
        
        // for(int i = 0; i < an; i++){
        //     mp.push_back({a[i],i});
        // }
        
        // sort(mp.begin(), mp.end());
        
        // unordered_set<int>st;
        // int k = 0;
        
        // for(int i = 0; i < min(an, ele_req); i++){
        //     st.insert(mp[i].second);
        //     // cout<<mp[i].second<<endl;
        // }
        
        // long long ans = 0;
        
        // int i = 0;
        // int j = 0;
        
        // while(i < an && j < bn){
        //     if(st.count(i)){
        //         i++;
        //     }else{
        //         ans += a[i]*b[j];
        //         i++;
        //         j++;
        //     }
        // }
        
        // return (int)ans;