//You are given an array arr[] of positive integers. Your task is to find the maximum value that can be obtained by performing a bitwise AND operation on any two different elements in the array.
// Note: AND refers to the bitwise '&' operator.

class Solution {
  public:
    int findMaxAnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        int maxi = INT_MIN;
        
        int ans = 0;

        for(int i = 31; i >= 0; i--){
            int candidate = ans | (1 << i);
            int count = 0;
        
            for(int j = 0; j < n; j++){
                if((arr[j] & candidate) == candidate)
                    count++;
            }
        
            if(count >= 2)
                ans = candidate;
        }
        
        return ans;
    }
};