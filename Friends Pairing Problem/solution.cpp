class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
        vector<int>dp(n+1, 0);
        
        int prev = 1;
        int curr = 2;
        
        for(int i = 3; i <= n; i++){
            int next = curr + (i - 1)*prev;
            prev = curr;
            curr = next;
        }
        
        if(n == 1) return 1;
        
        return curr;
    }
};

// n = 4
// 1 2 3 4 -> 1, 2, 3, 4 -> 1
// 12 3 4, 13 2 4, 14 2 3, 1 23 4, 1 3 24, 1 2 34, 12 34, 13 24, 14 23 
// 
// 1 2 4 10 26