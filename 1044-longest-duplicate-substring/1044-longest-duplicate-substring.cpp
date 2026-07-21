class Solution {
public:
    long long mod1 = 1e9+7, base1 = 131;
    long long mod2 = 1e9+9, base2 = 137;   

    string check(string& s, int len){
        int n = s.length();
        unordered_map<long long, int> mp;   
        long long ans1 = 0, ans2 = 0;
        long long j = 0;

        long long pw1 = 1, pw2 = 1;
        for(int k = 0; k < len; k++){
            pw1 = (pw1 * base1) % mod1;
            pw2 = (pw2 * base2) % mod2;
        }

        for(int i = 0; i < n; i++){
            ans1 = (ans1 * base1 + (s[i]-'a'+1)) % mod1;
            ans2 = (ans2 * base2 + (s[i]-'a'+1)) % mod2;

            if(i - j + 1 > len){
                ans1 = ((ans1 - (s[j]-'a'+1) * pw1 % mod1) % mod1 + mod1) % mod1;
                ans2 = ((ans2 - (s[j]-'a'+1) * pw2 % mod2) % mod2 + mod2) % mod2;
                j++;
            }

            if(i - j + 1 == len){
                long long combined = ans1 * mod2 + ans2;  
                if(mp.count(combined)){
                    return s.substr(j, len);
                }
                mp[combined] = j;
            }
        }
        return "";
    }

    string longestDupSubstring(string s) {
        int n = s.length();
        int lo = 1, hi = n-1;
        string ans = "";

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            string res = check(s, mid);

            if(res != ""){
                ans = res;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};