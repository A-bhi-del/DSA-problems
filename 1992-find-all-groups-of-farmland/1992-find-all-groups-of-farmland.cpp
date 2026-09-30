class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        vector<vector<int>>ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i-1 >= 0 && land[i-1][j] == 1) || (j-1 >= 0 && land[i][j-1] == 1)){
                    continue;
                }

                if(land[i][j] == 0) continue;

                int r = -1;
                int d = -1;

                for(int k = j; k < m; k++){
                    if(land[i][k] == 1){
                        r++;
                    }else{
                        break;
                    }
                }

                for(int k = i; k < n; k++){
                    if(land[k][j] == 1){
                        d++;
                    }else{
                        break;
                    }
                }

                ans.push_back({i, j, i+d, j+r});
            }
        }

        return ans;
    }
};