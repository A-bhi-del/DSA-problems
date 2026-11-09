class Solution {
  public:
    int getCount(string &s, int k) {
        // code here
        int n = s.length();
        vector<int>freq(26, 0);
        
        for(int i = 0; i < n-1; i++){
            if(s[i] != s[i+1]){
                freq[s[i] - 'a']++;
            }
        }
        
        freq[s[n-1] - 'a']++;
        
        int ans = 0;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] == k){
                ans++;
            }
        }
        
        return ans;
    }
};