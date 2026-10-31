class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int>left(n, 0);
        vector<int>right(n, 0);
        
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            if(sum < 0){
                sum = 0;
            }
            
            left[i] = sum;
        }
        
        sum = 0;

        for(int i = n-1; i >= 0; i--){
            sum += arr[i];
            
            if(sum < 0){
                sum = 0;
            }
            
            right[i] = sum;
        }
        
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            int l = i-1;
            int r = i+1;
            
            int valL = 0;
            int valR = 0;
            
            if(l >= 0){
                valL = left[l];
            }
            
            if(r < n){
                valR = right[r];
            }
            
            int res = valL + arr[i]*arr[i] + valR;
            
            ans = max(ans, res);
        }
        
        return ans;
    }
};