class Solution {
public:
    vector<int>op_r = {1,-1,0,0};
    vector<int>op_c = {0,0,-1,1};
    
    int findPerimeter(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int peri = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0) continue;
                
                for(int k = 0; k < 4; k++){
                    int ni = i + op_r[k];
                    int nj = j + op_c[k];
                    
                    if(ni < 0 || ni >= n || nj < 0 || nj >= m){
                        peri++;
                        continue;
                    }
                    
                    if(mat[ni][nj] == 0){
                        peri++;
                    }
                }
            }
        }
        
        return peri;
    }
};