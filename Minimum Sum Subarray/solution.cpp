class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int sum = arr[0];
        int min_sum = arr[0];
        
        for(int i = 1; i < n; i++){
            sum += arr[i];
            
            if(sum > arr[i]){
                sum = arr[i];
            }
            
            min_sum = min(min_sum, sum);
        }
        
        return min_sum;
    }
};