class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int>count(n+1, 0);
        
        for(int i = 0; i < n; i++){
            if(count[arr[i] - 1] != 0){
                count[arr[i]] += 1 + count[arr[i] - 1];
            }else{
                count[arr[i]] = 1;
            }
        }
        
        int LCS = 0;
        
        for(int i = 0; i <= n; i++){
            LCS = max(LCS, count[i]);
        }
        
        return n - LCS;
    }
};