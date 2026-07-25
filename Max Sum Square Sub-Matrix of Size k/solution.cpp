class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                mat[i][j] = mat[i][j-1] + mat[i][j];
            }
        }
        
        for(int j = 0; j < m; j++){
            for(int i = 1; i < n; i++){
                mat[i][j] = mat[i-1][j] + mat[i][j];
            }
        }
        
        int ans = INT_MIN;
        
        for(int i = k-1; i < n; i++){
            for(int j = k-1; j < n; j++){
                int val_r = 0;
                int val_c = 0;
                int common = 0;
                
                if(i-k >= 0){
                    val_r = mat[i-k][j];
                }
                
                if(val_c >= 0){
                    val_c = mat[i][j-k];
                }
                
                if(i-k >= 0 && j-k >= 0){
                    common = mat[i-k][j-k];
                }
                
                int res = mat[i][j] - (val_r + val_c) + common;
                
                ans = max(ans, res);
            }
        }
        
        
        return ans;
    }
};

/*
 1  3   2   6
-8 -11 -7  -5
 3  11  21  13
-4  -5  -4  3



*/