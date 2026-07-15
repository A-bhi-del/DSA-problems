class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        if(n == 1){
            return 1;
        }
        
        int s = 0;
        
        int max_len = 0;
        
        vector<int>pre(n, 1);
        vector<int>suf(n, 1);
        
        for(int i = 1; i < n; i++){
            if(arr[i-1] <= arr[i]){
                pre[i] = pre[i-1] + 1;
            }
        }
        
        for(int i = n-2; i >= 0; i--){
            if(arr[i+1] <= arr[i]){
                suf[i] = suf[i+1] + 1;
            }
        }
        
        for(int i = 0; i < n; i++){
            // cout<<pre[i]<<" "<<suf[i]<<endl;
            max_len = max(max_len, pre[i] + suf[i] - 1);
        }
        
        return max_len;
    }
};