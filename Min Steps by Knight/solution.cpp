class Solution {
  public:
    vector<int>op_r = {-2,-1,1,2,2,1,-1,-2};
    vector<int>op_c = {1,2,2,1,-1,-2,-2,-1};
    
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        queue<vector<int>>min_heap;
        
        min_heap.push({0,knightPos[0] - 1, knightPos[1] - 1});
        
        int ans = INT_MAX;
        
        while(!min_heap.empty()){
            auto node = min_heap.front();
            int m = node[0];
            int i = node[1];
            int j = node[2];
            
            min_heap.pop();
            
            if(i == targetPos[0] - 1 && j == targetPos[1] - 1){
                ans = min(ans, m);
            }
            
            // if(dp[i][j] < m){
            //     continue;
            // }
            
            // dp[i][j] = m;
            
            for(int k = 0; k < 8; k++){
                int ni = i + op_r[k];
                int nj = j + op_c[k];
                
                if(ni >= n || nj >= n || ni < 0 || nj < 0) continue;
                
                if(dp[ni][nj] == 0){
                    dp[ni][nj] = 1;
                    min_heap.push({m + 1, ni, nj});
                }
            }
        }
        
        return ans;
    }
};