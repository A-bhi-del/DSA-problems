class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        int ans = 0;
        
        while(max(n, m) % min(n, m) != 0){
            int a = max(n, m);
            int b = min(n, m);
            
            ans += a / b;
            int c = a % b;
            
            n = b;
            m = c;
        }
        
        int a = max(n, m);
        int b = min(n, m);
        ans += a/b;    
        
        return ans;
    }
};

// n = 11, m = 13