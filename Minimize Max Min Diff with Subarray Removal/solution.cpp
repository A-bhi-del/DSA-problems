class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<pair<int,int>>prefix(n, {0,0});
        
        prefix[0] = {arr[0], arr[0]};
        
        for(int i = 1; i < n; i++){
            prefix[i].first = min(prefix[i-1].first, arr[i]);
            prefix[i].second = max(prefix[i-1].second, arr[i]);
        }
        
        vector<pair<int,int>>suffix(n, {0,0});
        
        suffix[n-1] = {arr[n-1], arr[n-1]};
        
        for(int i = n-2; i >= 0; i--){
            suffix[i].first = min(suffix[i+1].first, arr[i]);
            suffix[i].second = max(suffix[i+1].second, arr[i]);
        }
        
        
        int ans = INT_MAX;
        
        for(int i = k-1; i < n; i++){
            int lidx = i - k;
            int ridx = i + 1;
            
            int lmin = INT_MAX;
            int lmax = INT_MIN;
            int rmin = INT_MAX;
            int rmax = INT_MIN;
            
            if(lidx >= 0){
                lmin = prefix[lidx].first;
                lmax = prefix[lidx].second;
            }
            
            if(ridx < n){
                rmin = suffix[ridx].first;
                rmax = suffix[ridx].second;
            }
            
            lmin = min(lmin, rmin);
            lmax = max(lmax, rmax);
            
            ans = min(ans, lmax - lmin);
        }
        
        return ans;
    }
};
