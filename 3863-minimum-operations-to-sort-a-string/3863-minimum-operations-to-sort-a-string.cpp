class Solution {
public:
    bool is_inc(string& s){
        int n = s.length();

        for(int i = 1; i < n; i++){
            if(s[i] < s[i-1]){
                return false;
            }
        }

        return true;
    }

    int minOperations(string s) {
        int n = s.length();

        if(n == 2){
            if(s[1] < s[0]){
                return -1;
            }
        }

        if(is_inc(s)){
            return 0;
        }

        string temp1 = s;

        sort(temp1.begin(), temp1.begin() + n-1);
        sort(s.begin() + 1, s.end());

        if(is_inc(temp1) || is_inc(s)){
            return 1;
        }

        sort(s.begin(), s.begin() + n-1);
        sort(temp1.begin() + 1, temp1.end());
        if(is_inc(s) || is_inc(temp1)){
            return 2;
        }

        return 3;
    }
};