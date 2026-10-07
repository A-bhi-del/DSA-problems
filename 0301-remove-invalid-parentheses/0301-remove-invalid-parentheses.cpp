class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;

    bool is_valid(string& str){
        int count = 0;
        for(char ch : str){
            if(ch == '(') {
                count++;
            }else if(ch == ')'){
                count--;
                if(count < 0) {
                    return false;
                }
            }
        }
        
        return count == 0;
    }

    void solve(int idx, string& s, string& str, int LP, int RP){
        if(idx >= s.length()){
            if(LP == 0 && RP == 0 && is_valid(str)){
                if(!st.count(str)){
                    st.insert(str);
                    ans.push_back(str);
                }
            }
            return;
        }

        str += s[idx];
        solve(idx+1, s, str, LP, RP);
        str.pop_back();

        if(s[idx] == '(' && LP > 0){
            solve(idx+1, s, str, LP-1, RP);
        }else if(s[idx] == ')' && RP > 0){
            solve(idx+1, s, str, LP, RP-1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int LP = 0;
        int RP = 0;

        for(char ch : s){
            if(ch == '('){ 
                LP++;
            }else if(ch == ')'){
                if(LP > 0){ 
                    LP--;
                }else {
                    RP++;
                }
            }
        }

        string str = "";
        solve(0, s, str, LP, RP);
        return ans;
    }
};