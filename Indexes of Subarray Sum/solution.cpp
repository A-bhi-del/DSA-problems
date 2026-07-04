class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int l = 0;
        int sum = 0;
        int n = arr.size();
        
        for(int r = 0; r < n; r++){
            sum += arr[r];
            
            while(sum > target){
                sum -= arr[l];
                l++;
            }
            
            if(sum == target){
                return {l+1, r+1};
            }
        }
        
        return {-1};
    }
};