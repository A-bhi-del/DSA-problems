class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();

        unordered_map<string, string>mp;

        for(auto know : knowledge){
            mp[know[0]] = know[1];
        }

        string ans = "";

        int i = 0;

        while(i < n){
            if(s[i] == '('){
                i++;
                string str = "";
                while(i < n && s[i] != ')'){
                    str += s[i];
                    i++;
                }

                if(mp.count(str)){
                    ans += mp[str];
                }else{
                    ans += "?";
                }
            }else{
                ans += s[i];
            }

            i++;
        }

        return ans;
    }
};