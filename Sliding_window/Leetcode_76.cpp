// Minimum Window Substring

// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
// The testcases will be generated such that the answer is unique.

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int n = s.length();
        int req = t.length();
        int m = req;
        
        for(int i = 0; i < m; i++){
            mp[t[i]]++;
        }

        int l = 0;
        int min_len = INT_MAX;
        int s_idx = -1;
        int e_idx = -1;

        for(int r = 0; r < n; r++){
            mp[s[r]]--;
            if(mp[s[r]] >= 0){
                req--;
            }

            while(req == 0){
                int len = r-l+1;
                if(len < min_len){
                    min_len = len;
                    s_idx = l;
                    e_idx = r;
                }
                
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    req++;
                }
                l++;
            }
        }

        string ans = "";
        if(s_idx == -1) return "";
        for(int i = s_idx; i <= e_idx; i++){
            ans += s[i];
        }

        return ans;
    }
};