// not optimal space = O(2n) , time = O(n);

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>prefix(n, 0);
        vector<int>suffix(n, 0);
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];
        
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i-1], arr[i]);
        }
        
        for(int i = n-2; i >= 0; i--){
            suffix[i] = max(suffix[i+1], arr[i]);
        }
        
        int water = 0;
        
        for(int i = 0; i < n; i++){
            water += min(prefix[i], suffix[i]) - arr[i];
        }
        
        return water;
    }
};

// O(1) space solution using two pointer approach 
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;
        int l = 0;
        int r = n-1;
        
        while(l <= r){
            if(arr[l] <= arr[r]){
                if(arr[l] >= leftMax){
                    leftMax = arr[l];
                }else{
                    water += leftMax - arr[l];
                }
                l++;
            }else{
                if(arr[r] >= rightMax){
                    rightMax = arr[r];
                }else{
                    water += rightMax - arr[r];
                }
                r--;
            }
        }
        
        return water;
    }
};