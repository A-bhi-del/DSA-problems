// Given two strings s and p. Find the smallest substring in s consisting of all the characters (including duplicates) of the string p. Return empty string in case no such substring is present.
// If there are multiple such substring of the same length found, return the one with the least starting index.

class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        unordered_map<char,int>mp;
        
        int n = s.length();
        int m = p.length();
        int req = m;
        
        for(int i = 0; i < m; i++){
            mp[p[i]]++;
        }
        
        int l = 0;
        int s_idx = -1;
        int e_idx = -1;
        int min_len = INT_MAX;
        
        for(int r = 0; r < n; r++){
            mp[s[r]]--;
            
            if(mp[s[r]] >= 0){
                req--;
            }
            
            while(req == 0){
                int len = r - l + 1;
                
                if(len < min_len){
                    s_idx = l;
                    e_idx = r;
                    min_len = len;
                }
                
                mp[s[l]]++;
                
                if(mp[s[l]] > 0){
                    req++;
                }
                l++;
            }
        }
        
        string ans = "";
        
        for(int i = s_idx; i <= e_idx; i++){
            ans += s[i];
        }
        
        return (s_idx == -1 || e_idx == -1) ? "" : ans;
    }
};


// Note = for O(1) space solution you can replace unordered_map with a 26 size freq array according to problem constraints