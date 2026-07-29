class Solution {
public:
    long long total_permu(vector<int>& freq, long long cap) {
        long long result = 1;
        long long used = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= freq[i]; j++) {
                used++;
                result = result * used / j;
                if (result > cap) return cap + 1;   
            }
        }
        return result;
    }

    string smallestPalindrome(string s, long long k) {
        int n = s.length();
        int len = n / 2;
        vector<int> freq(26, 0);

        for (int i = 0; i < len; i++) {
            freq[s[i] - 'a']++;
        }

        char mid = (n % 2) ? s[len] : 0;

        string ans = "";
        long long remaining = k;

        for (int i = 0; i < len; i++) {
            bool placed = false;
            for (int ch = 0; ch < 26; ch++) {
                if (freq[ch] == 0) continue;
                freq[ch]--;   
                long long count = total_permu(freq, remaining + 1);

                if (count >= remaining) {
                    ans += char('a' + ch);
                    placed = true;
                    break;
                } else {
                    remaining -= count;    
                    freq[ch]++;            
                }
            }
            if (!placed) return "";        
        }

        string res = ans;
        if (mid) res += mid;
        string rev = ans;
        reverse(rev.begin(), rev.end());
        res += rev;
        return res;
    }
};