class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int len = s.length();

        sort(s.begin(), s.end());

        return (s[len-1] - '0') * (s[len-2] - '0');
    }
};