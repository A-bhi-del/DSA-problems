class Solution {
  public:
    string lexiString(string &s) {
        // code here
        string t = s + s;
        int n = s.length();
        
        int i = 0;
        int j = 1;
        int k = 0;
        
        while(i < n && j < n && k < n){
            if(t[i+k] == t[j+k]){
                k++;
                continue;
            }
            
            if(t[i+k] < t[j+k]){
                j = j + k + 1;
            }else if(t[i+k] > t[j+k]){
                i = i + k + 1;
            }
            
            
            if(i == j){
                j++;
            }
            
            k = 0;
        }
        
        
        int min_idx = min(i, j);
        
        return t.substr(min_idx, n);
    }
};