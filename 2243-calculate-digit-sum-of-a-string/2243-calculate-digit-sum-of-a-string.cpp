class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next = "";
            for (int j = 0; j < s.length(); j += k) {
                int groupSum = 0;
                for (int t = j; t < j + k && t < s.length(); t++) {
                    groupSum += s[t] - '0';
                }
                next += to_string(groupSum);
            }
            s = next;
        }
        return s;
    }
};