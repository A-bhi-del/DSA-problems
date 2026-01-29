//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n_s1 = s1.length();
        int n_s2 = s2.length();
        
        vector<int>mp(26, 0);
        vector<int>mp1(26, 0);

        if(n_s1 > n_s2){
            return false;
        }

        for(int i = 0; i < n_s1; i++){
            mp[s1[i] - 'a']++;
        }

        int l = 0;
        for(int r = 0; r < n_s2; r++){
            mp1[s2[r] - 'a']++;

            if(r-l+1 > n_s1){
                mp1[s2[l] - 'a']--;
                l++;
            }

            if(mp == mp1){
                return true;
            }
        }

        return false;
    }
};