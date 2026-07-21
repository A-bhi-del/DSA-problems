class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int ans = 0;      
        int pre = INT_MIN; 
        int maxi = 0;         
        int i = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) j++;
            int len = j - i;

            if (s[i] == '1') {
                ans += len;
            } else {
                maxi = max(maxi, (pre == INT_MIN ? INT_MIN : pre + len));
                pre = len;
            }
            i = j;
        }

        return ans + max(maxi, 0);
    }
};

// 1 1 0 0 0 1 0 0 1 
// 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 0 1 1

// 1 0 1 0 1 0 1

// 1 0 1 0 1 0 0 1 0 0 0 1 0 0 0 0 0 1

// 1 0 1 0 1 0 1