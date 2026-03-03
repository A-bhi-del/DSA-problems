// not optimal space = O(2n) , time = O(n);

class Solution {
  public:
    int maxWater(vector<int> &arr) {
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
            suffix[i] = max(suffix[i+1], arr[i]);
        }
        
        int water = 0;
        
        for(int i = 0; i < n; i++){
            water += min(prefix[i], suffix[i]) - arr[i];
        }
        
        return water;
    }
};
