class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int count = 0;
        int LP = 0;
        int RP = 0;

        int i = 0;

        while(i < n){
            if(s[i] == '('){
                LP++;
                i++;
            }else if(s[i] == ')'){
                if(LP > 0 && (i+1 < n && s[i+1] == ')')){
                    LP--;
                    i+=2;
                }else{
                    if(LP <= 0){
                        LP++;
                        count++;
                    }
                    if(i + 1 >= n || s[i+1] != ')'){
                        LP--;
                        count++;
                        i++;
                    }
                }
            }
        }


        while(LP > 0){
            count += 2;
            LP--;
        }

        return count;
    }
};