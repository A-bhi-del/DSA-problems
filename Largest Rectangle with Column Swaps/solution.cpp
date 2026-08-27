class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        for(int j = 0; j < m; j++){
            for(int i = 1; i < n; i++){
                if(mat[i][j] == 1){
                    mat[i][j] = mat[i-1][j] + mat[i][j];
                }else{
                    mat[i][j] = 0;
                }
            }
        }
        
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int max_area = 0;
        
        for(int i = 0; i < n; i++){
            vector<int>arr = {mat[i].begin(), mat[i].end()};
            
            sort(arr.begin(), arr.end());
            
            for(int j = 0; j < arr.size(); j++){
                int area = arr[j] * (arr.size() - j);
                max_area = max(max_area, area);
            }
        }
        
        return max_area;
    }
};

/*
0 1 1 0 0
1 1 1 0 1
1 1 1 0 1
1 1 1 1 1 

0 1 0 1 0
0 1 0 1 1 
1 1 0 1 0
*/