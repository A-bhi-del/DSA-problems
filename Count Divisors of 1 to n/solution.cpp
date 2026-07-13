class Solution {
  public:
    int divCountSum(int n) {
        // code here
        int ans = 0;
        
        for(int i = 1; i <= n; i++){
            ans += (n/i);
        }
        
        return ans;
    }
};