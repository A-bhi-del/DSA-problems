class Solution {
public:
    unordered_map<string, bool>dp;

    bool solve(string s1, string s2){
        if(s1 == s2){
            return true;
        }

        if(s1.length() != s2.length()){
            return false;
        }

        string key = s1 + '#' + s2;

        if(dp.count(key)){
            return dp[key];
        }

        bool result = false;
        int n = s1.length();

        for(int i = 1; i < n; i++){
            bool un_swap = solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n-i), s2.substr(i, n-i));

            bool swap = solve(s1.substr(i, n-i), s2.substr(0, n-i)) && solve(s1.substr(0, i), s2.substr(n-i, i));

            if(un_swap || swap){
                result = true;
                break;
            }
        } 

        return dp[key] = result;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};

// ab cde
// ba c de
// ba c ed
// cba ed
// edcba

// 2