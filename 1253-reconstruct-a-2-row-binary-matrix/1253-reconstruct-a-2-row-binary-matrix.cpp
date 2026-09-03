class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<int>d(n, 0);
        vector<int>u(n, 0);

        for(int i = 0; i < n; i++){
            if(colsum[i] == 2 && lower > 0 && upper > 0){
                d[i] = 1;
                u[i] = 1;
                lower--;
                upper--;
                colsum[i] -= 2;
            }
        }

        for(int i = 0; i < n; i++){
            if(upper > 0 && colsum[i] == 1){
                colsum[i]--;
                upper--;
                u[i] = 1;
            }

            if(upper <= 0){
                break;
            }
        }

        for(int i = 0; i < n; i++){
            if(lower > 0 && colsum[i] == 1){
                colsum[i]--;
                lower--;
                d[i] = 1;
            }

            if(lower <= 0){
                break;
            }
        }

        // cout<<lower<<" "<<upper<<endl;
        
        for(int i = 0; i < n; i++){
            if(colsum[i] != 0){
                return {};
            }
        }

        if(lower != 0 || upper != 0){
            return {};
        }

        return {u,d};
    }
};
// 2 1 2 0 1 0 1 2 0 1 