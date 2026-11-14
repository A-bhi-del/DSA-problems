class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>ans;

        int n = s1.length();

        int i = 0;


        while(i < n){
            string str1 = "";
            string str2 = "";
            while(i < n && s1[i] != s2[i]){
                str1 += s1[i];
                str2 += s2[i];
                i++;
            }

            if(str1 != ""){
                ans.push_back({str1, str2});
            }
            i++;
        }

        return ans;
    }
};