class Solution {
  public:
    int solve(int n, string s) {
        // code here
        int m = s.length();
        unordered_map<int, int>freq;
        unordered_set<int>st;
        
        int i = 0;
        while(i < m){
            if(n > 0 && !freq.count(s[i] - 'a') && !st.count(s[i] - 'a')){
                n--;
                freq[s[i] - 'a'] = 1;
            }else if(freq.count(s[i] - 'a')){
                n++;
                freq.erase(s[i] - 'a');
            }else{
                st.insert(s[i] - 'a');
            }
            i++;
        }
        
        return st.size();
    }
};
