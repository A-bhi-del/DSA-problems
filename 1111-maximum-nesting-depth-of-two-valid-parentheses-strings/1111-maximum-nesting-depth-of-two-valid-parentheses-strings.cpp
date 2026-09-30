class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int>res(n, 1);
        stack<pair<char, int>>st;

        int openA = 0;
        int openB = 0;

        for(int i = 0; i < n; i++){
            if(openA > openB){
                if(seq[i] == ')' && openA > 0){
                    openA--;
                    res[i] = 0;
                }else{
                    openB++;
                    res[i] = 1;
                }
            }else{
                if(seq[i] == ')' && openB > 0){
                    openB--;
                    res[i] = 1;
                }else{
                    openA++;
                    res[i] = 0;
                }
            }
        }

        return res;
    }
};