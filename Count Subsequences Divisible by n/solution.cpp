class Solution {
  public:
    int mod = 1e9+7;
    
    int solve(int idx, int num, int size, string& s, int n, vector<vector<int>>& dp){
        if(idx >= size){
            if(num % n == 0){
                return 1;
            }
            
            return 0;
        }
        
        if(dp[idx][num] != -1){
            return dp[idx][num];
        }
        
        int take = solve(idx+1, (num*10 + (s[idx] - '0')) % n, size,  s, n, dp);
        int not_take = solve(idx+1, num % n, size, s, n, dp);
        
        return dp[idx][num] = (take + not_take) % mod;
    }
    
    int countSubsequences(string& s, int n) {
        // code here
        int size = s.length();
        vector<vector<int>>dp(size, vector<int>(n+1, -1));
        return solve(0, 0, size, s, n, dp) - 1;
    }
};

/*
1 2 3 4
1 2
1 2 4
4
2 4


*/