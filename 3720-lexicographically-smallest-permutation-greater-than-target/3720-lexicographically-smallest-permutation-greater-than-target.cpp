class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();

        if(n == 1){
            return s > target ? s : "";
        }

        string dup = s;
        sort(dup.begin(), dup.end(), greater<char>());
        if(dup <= target){
            return "";
        }

        vector<int>mp(26, 0);
        for(char ch : s){
            mp[ch - 'a']++;
        }
        
        string ans = "";
        for(char ch : target){
            if(mp[ch - 'a'] > 0){
                ans += ch;
                mp[ch - 'a']--;
            }else{
                break;
            }
        }

        string rem = "";
        for(int i = 0; i < 26; i++){
            while(mp[i] > 0){
                rem += i + 'a';
                mp[i]--;
            }
        }

        string finall = ans + rem;

        if(finall > target){
            return finall;
        }

        int is_there_idx = -1;

        for(int i = 0; i < rem.length(); i++){
            if(rem[i] > target[ans.size()]){
                is_there_idx = i;
                break;
            }
        }

        if(is_there_idx != -1){
            ans += rem[is_there_idx];

            for(int i = 0; i < rem.length(); i++){
                if(i != is_there_idx){
                    ans += rem[i];
                }
            }

            return ans;
        }

        for(char ch : rem) mp[ch - 'a']++;
        rem.clear();

        for(int p = ans.size() - 1; p >= 0; p--){
            mp[ans[p] - 'a']++;
            ans.pop_back();

            int bump = -1;
            for(int c = target[p] - 'a' + 1; c < 26; c++){
                if(mp[c] > 0){ 
                    bump = c; 
                    break; 
                }
            }

            if(bump != -1){
                ans += bump + 'a';
                mp[bump]--;
                for(int c = 0; c < 26; c++){
                    while(mp[c] > 0){
                        ans += c + 'a';
                        mp[c]--;
                    }
                }
                return ans;
            }
        }

        return "";
    }
};