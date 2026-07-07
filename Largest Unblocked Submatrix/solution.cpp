class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        // code here
        int k = arr.size();
        if(k == 0){
            return n*m;
        }
        sort(arr.begin(), arr.end());
        
        int max_row_gap = arr[0][0] - 1;
        
        for(int i = 1; i < k; i++){
            max_row_gap = max(max_row_gap, arr[i][0] - arr[i-1][0] - 1);
        }
        
        max_row_gap = max(max_row_gap, n - arr[k-1][0]);
        
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int max_col_gap = arr[0][1] - 1;
        
        for(int i = 1; i < k; i++){
            max_col_gap = max(max_col_gap, arr[i][1] - arr[i-1][1] - 1);
        }
        
        max_col_gap = max(max_col_gap, m - arr[k-1][1]);
        
        return max_row_gap * max_col_gap;
    }
};