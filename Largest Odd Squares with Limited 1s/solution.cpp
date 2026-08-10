class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries,
                              int k) {
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
                mat[i][j] = mat[i][j] + mat[i-1][j];
            }
        }
        
        vector<int>ans;
        
        for(auto query : queries){
            int cr = query[0];
            int cc = query[1];
            
            int one_side_len = min(min(cr, n - 1 - cr), min(cc, m - 1 - cc));
            int max_size_mat = 2*one_side_len + 1;
            bool is_possi = false;
            
            for(int size = max_size_mat; size > 0; size -= 2){
                int one_side = size/2;
                int p_r = cr - one_side - 1;
                int p_c = cc - one_side - 1;
                int a_r = cr + one_side;
                int a_c = cc + one_side;
                
                int L_B = 0;
                int T_R = 0;
                int dia = 0;
                if(p_c >= 0){
                    L_B = mat[a_r][p_c];
                }
                
                if(p_r >= 0){
                    T_R = mat[p_r][a_c];
                }
                
                if(p_c >= 0 && p_r >= 0){
                    dia = mat[p_r][p_c];
                }
                
                int num_of_ones = mat[a_r][a_c] - L_B - T_R + dia;
                
                if(num_of_ones <= k){
                    ans.push_back(size);
                    is_possi = true;
                    break;
                }
            }
            
            if(is_possi == false){
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};