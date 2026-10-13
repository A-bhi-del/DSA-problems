class Solution {
  public:
    vector<int> update(int n, vector<int>& updates) {
        // code here
        int nu = updates.size();
        
        vector<int>ans(n, 0);
        
        for(int val : updates){
            ans[val-1] += 1;
        }
        
        for(int i = 1; i < n; i++){
            ans[i] = ans[i] + ans[i-1];
        }
        
        return ans;
    }
};