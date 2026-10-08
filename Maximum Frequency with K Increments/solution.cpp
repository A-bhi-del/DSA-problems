class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        vector<int>prefix(n, 0);
        
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int l = 0;
            int h = i;
            
            int idx = 0;
            
            while(l <= h){
                int mid = l + (h-l)/2;
                int val = 0;
                if(mid - 1 >= 0){
                    val = prefix[mid-1];
                }
                
                int need = arr[i] * (i - mid + 1) - (prefix[i] - val);
                
                if(need > k){
                    l = mid + 1;
                }else{
                    h = mid - 1;
                    idx = mid;
                }
            }
            
            ans = max(ans, i - idx + 1);
        }
        
        return ans;
    }
};