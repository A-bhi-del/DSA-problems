class Solution {
  public:
    int solve(vector<int>& arr, int target){
        int count = 0;
        
        int l = 0;
        int sum = 0;
        for(int r = 0; r < arr.size(); r++){
            sum += arr[r];
            
            while(l < arr.size() && sum > target){
                sum -= arr[l];
                l++;
            }
            
            count += (r - l + 1);
        }
        
        return count;
    }
    
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        int n = arr.size();
        
        return solve(arr, r) - solve(arr, l-1);
    }
};