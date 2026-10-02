class Solution {
public:
    void solve(int count_1, int count_0, string str,int n, vector<string>& ans){
        if(count_1 == count_0 && count_1 + count_0 == n*2){
            ans.push_back(str);
            return;
        }

        if(count_1 < n){
            solve(count_1+1, count_0, str+'(', n, ans);
        }
        if(count_0 < count_1){
            solve(count_1, count_0+1, str+')', n, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";

        solve(0,0, str,n, ans);


        return ans;
    }
};