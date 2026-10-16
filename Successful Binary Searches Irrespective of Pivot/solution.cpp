class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>prefix(n, 0);
        vector<int>suffix(n, 0);
        
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];
        
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i-1], arr[i]);
        }
        
        for(int i = n-2; i >= 0; i--){
            suffix[i] = min(suffix[i+1], arr[i]);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int vall = -1;
            
            if(i-1 >= 0){
                vall = prefix[i-1];
            }
            int valr = INT_MAX;
            
            if(i+1 < n){
                valr = suffix[i+1];
            }
            
            if(vall < arr[i] && arr[i] < valr){
                ans++;
            }
        }
        
        return ans;
    }
};