class Solution {
  public:
    vector<int>op_r = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<int>op_c = {1, 1, 0, -1, -1, -1, 0, 1};
    int dp[51][51][22][10];
    
    bool DFS(int i, int j, vector<vector<char>>& mat, string& word, int len, int dir){
        if(len >= word.length()){
            return true;
        }
        
        if(dp[i][j][len][dir+1] != -1){
            return dp[i][j][len][dir+1];
        }
        
        bool take = false;
        
        for(int k = 0; k < 8; k++){
            int ni = i + op_r[k];
            int nj = j + op_c[k];
            
            if(dir == -1){
                if(ni >= 0 && ni < mat.size() && nj >= 0 && nj < mat[0].size() && mat[ni][nj] == word[len]){
                    take = take || DFS(ni, nj, mat, word, len+1, k);
                }
            }else if(dir == k){
                if(ni >= 0 && ni < mat.size() && nj >= 0 && nj < mat[0].size() && mat[ni][nj] == word[len]){
                    take = take || DFS(ni, nj, mat, word, len+1, k);
                }
            }
        }
        
        return dp[i][j][len][dir+1] = take;
    }
    
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        memset(dp, -1, sizeof(dp));
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == word[0]){
                    if(DFS(i, j, mat, word, 1, -1)){
                        ans.push_back({i, j});
                    }
                }
            }
        }
        
        return ans;
    }
};