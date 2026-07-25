class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(num);

        if (num >= 0) {
            sort(s.begin(), s.end());
            long long idx = -1;

            for (int i = 0; i < s.length(); i++) {
                if (s[i] != '0') {
                    idx = i;
                    break;
                }
            }

            if (idx == -1) {
                return stol(s);
            }

            swap(s[idx], s[0]);
            return stol(s);
        }

        sort(s.begin() + 1, s.end(), greater<char>());

        string dup_s = s.substr(1, s.length()-1);

        return -stol(dup_s);
    }
};