class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        
        
        int maxi = arr[0];
        for(int i = 1; i < n; i++){
            maxi = max(maxi, arr[i]);
            arr[i] = arr[i] + arr[i-1];
        }
        
        if(m == 1){
            return maxi;
        }
        if(n <= m){
            return arr[n-1];
        }
        
        int ans = INT_MIN;
        
        for(int i = m-2; i >= 0; i--){
            int sum = arr[i];
            int rem_idx = n - (m - (i + 1));
            int rem_sum = arr[n-1] - arr[rem_idx-1];
            // cout<<sum+rem_sum<<endl;
            ans = max(ans, sum + rem_sum);
        }

        for(int i = min(m-1, n-1); i < n; i++){
            int val = arr[i];
            if(i-m >= 0){
                val -= arr[i-m];
            }
            ans = max(ans, val);
        }
        
        return ans;
    }
};