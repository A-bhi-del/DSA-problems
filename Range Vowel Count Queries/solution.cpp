class Solution {
  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        // code here
        int n = s.length();
        
        vector<int>pre(n, 0);
        
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u'){
            pre[0] = 1;
        }
        
        for(int i = 1; i < n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                pre[i] = pre[i-1] + 1;
            }else{
                pre[i] = pre[i-1];
            }
        }
        
        vector<int>ans(queries.size(), 0);
        
        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            
            if(l-1 < 0){
                ans[i] = pre[r];
            }else{
                ans[i] = pre[r] - pre[l-1];
            }
        }
        
        return ans;
    }
};