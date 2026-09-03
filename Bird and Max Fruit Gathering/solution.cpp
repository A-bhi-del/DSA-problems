class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            arr.push_back(arr[i]);
        }
        
        for(int i = 1; i < arr.size(); i++){
            arr[i] = arr[i] + arr[i-1];
        }
        
        int ans = INT_MIN;
        int nn = arr.size();
        
        for(int i = min(m-1, nn-1); i < nn; i++){
            int val = arr[i];
            if(i-m >= 0){
                val -= arr[i-m];
            }
            ans = max(ans, val);
        }
        
        return ans;
    }
};