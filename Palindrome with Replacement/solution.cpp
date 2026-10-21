class Solution {
  public:
    int minimumSum(string &s) {
        // code here
        int n = s.length();
        
        int i = 0;
        int j = n-1;
        
        bool is_palin = true;
        
        while(i <= j){
            if(s[i] == s[j] || s[i] == '?' || s[j] == '?'){
                if(s[i] == '?' && s[j] != '?'){
                    s[i] = s[j];
                }else if(s[i] != '?' && s[j] == '?'){
                    s[j] = s[i];
                }
                i++;
                j--;
            }else{
                is_palin = false;
                break;
            }
        }
        
        if(!is_palin){
            return -1;
        }
        
        int ans = 0;
        
        vector<int>index;
        
        for(int i = 0; i < n; i++){
            if(s[i] != '?'){
                index.push_back(i);
            }
        }
        
        for(int i = 1; i < index.size(); i++){
            ans += abs(s[index[i]] - s[index[i-1]]);
        }
        
        return ans;
    }
};