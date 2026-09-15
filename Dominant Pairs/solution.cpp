class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n = arr.size();
        
        for(int i = n/2; i < n; i++){
            arr[i] = 5 * arr[i];
        }
        
        sort(arr.begin() + n/2, arr.end());
        
        int pairs = 0;
        
        for(int i = 0; i < n/2; i++){
            int val = arr[i];
            
            int l = n/2;
            int h = n-1;
            
            while(l <= h){
                int mid = l + (h - l)/2;
                
                if(arr[mid] <= val){
                    l = mid + 1;
                }else{
                    h = mid - 1;
                }
            }
            
            pairs += (l - (n/2)) ;
        }
        
        
        return pairs;
    }
};



// 10 2 2 5 10 15











