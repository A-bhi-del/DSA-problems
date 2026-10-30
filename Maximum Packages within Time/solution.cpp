class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        int n = arr.size();
        int max_package = INT_MIN;
        
        int sum = 0;
        int l = 0;
        
        for(int r = 0; r < n; r++){
            sum += arr[r];
            
            if(r - l + 1 > totalTime){
                sum -= arr[l];
                l++;
            }
            
            max_package = max(max_package, sum);
        }
        
        return max_package;
    }
};