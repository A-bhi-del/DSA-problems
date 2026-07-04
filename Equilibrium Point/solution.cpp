class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        
        for(int val : arr){
            sum += val;
        }
        
        int half = 0;
        int i = 0;
        for(; i < n; i++){
            sum -= arr[i];
            if(half == sum){
                return i;
            }
            half += arr[i];
        }
        
        return -1;
    }
};