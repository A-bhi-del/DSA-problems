class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<int>arr(n, 0);
        int m = a.size();
        for(int i = 0; i < m; i++){
            int l = a[i];
            int r = b[i];
            
            arr[l] += k[i];
            if(r+1 < n){
                arr[r+1] -= k[i];
            }
        }
        
        int max_ele = arr[0];
        
        for(int i = 1; i < n; i++){
            arr[i] = arr[i] + arr[i-1];
            max_ele = max(max_ele, arr[i]);
        }
        
        return max_ele;
    }
};