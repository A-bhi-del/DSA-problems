class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int l = 0;
        int h = n-1;
        int idx = -1;
        
        while(l <= h){
            int mid = l + (h - l)/2;
            int rem = arr[mid] - mid - 1;
            
            if(k > rem){
                idx = mid;
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }
        
        return k + idx + 1;
    }
};