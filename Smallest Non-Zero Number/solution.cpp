class Solution {
  public:
    bool check(long long mid, vector<int>& arr, int maxval) {
        for (int val : arr) {
            mid = 2LL * mid - val;
            if(mid >= maxval){
                return true;
            }
    
            if (mid < 0)
                return false;
        }
        return true;
    }
    
    int find(vector<int>& arr) {
        // code here
        int l = 1;
        int h = INT_MIN;
        
        for(int num : arr){
            h = max(h, num);
        }
        
        int maxi = h;
        
        int ans = 0;
        
        while(l <= h){
            int mid = l + (h - l)/2;
            
            if(check(mid, arr, maxi)){
                h = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return ans;
    }
};