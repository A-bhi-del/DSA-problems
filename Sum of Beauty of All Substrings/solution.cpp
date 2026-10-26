class Solution {
  public:
    int beautySum(string &s) {
        // code here
        int n = s.length();
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            vector<int>mp(26, 0);
            
            for(int j = i; j < n; j++){
                mp[s[j] - 'a']++;
                
                int min_freq = INT_MAX;
                int max_freq = INT_MIN;
                
                for(auto it : mp){
                    if(it == 0) continue;
                    min_freq = min(min_freq, it);
                    max_freq = max(max_freq, it);
                }
                
                ans += max_freq - min_freq;
            }
        }
        
        return ans;
    }
};