class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        
        vector<int>dp(max(maxi+2, n+1), 0);
        
        for(int i = 0; i < n; i++){
            int val = arr[i];
            int left = dp[val-1];
            int right = dp[val+1];
            
            dp[val] = max(left, right) + 1;
        }
        
        int ans = 0;
        
        for(int val : dp){
            ans = max(ans, val);
        }
        
        return ans;
    }
};