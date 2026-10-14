class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        int n = roll.size();
        int m = s.length();
        
        vector<int>diff(m, 0);
        
        for(int i = 0; i < n; i++){
            diff[roll[i] - 1] += 1;
        }
        
        for(int i = m-2; i >= 0; i--){
            diff[i] = diff[i] + diff[i+1];
        }
        
        for(int i = 0; i < m; i++){
            s[i] = ((s[i] - 'a' + diff[i]) % 26) + 'a';
        }
        
        return s;
    }
};

// 1 0 0 1 0 0 0 0 0 0 1 0 1 0 1 0 0 0 2
// 2 2 2 2 3 3 4 4 5 5 5 5 5 5 5 6 6 6 7