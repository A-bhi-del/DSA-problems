class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        unordered_map<char, int>mp;
        int n = s.length();
        int max_gap = -1;
        
        for(int i = 0; i < n; i++){
            if(mp.count(s[i])){
                max_gap = max(max_gap, i - mp[s[i]] - 1);
            }else{
                mp[s[i]] = i;
            }
        }
        
        return max_gap;
    }
};