class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        // code here
        int n = s.length();
        int sz = d.size();
        
        vector<vector<int>>mp(26);
        
        for(int i = 0; i < n; i++){
            mp[s[i]-'a'].push_back(i);
        }
        
        string res = "";
        
        for(int i = 0; i < sz; i++){
            string str = d[i];
            int prev_idx = -1;
            bool is_valid = true;
            
            for(int j = 0; j < str.length(); j++){
                int val = str[j]-'a';
                if(mp[val].size() == 0){
                    is_valid = false;
                    break;
                }
                
                int l = 0;
                int h = mp[val].size() - 1;
                int idx = -1;
                
                while(l <= h){
                    int mid = l + (h - l)/2;
                    
                    if(mp[val][mid] > prev_idx){
                        idx = mp[val][mid];
                        h = mid - 1;
                    }else{
                        l = mid + 1;
                    }
                }
                
                if(idx == -1){
                    is_valid = false;
                    break;
                }
                
                prev_idx = idx;
            }
            
            if(is_valid){
                if(res.size() < d[i].size()){
                    res = d[i];
                }else if(res.size() == d[i].size()){
                    if(res > d[i]){
                        res = d[i];
                    }
                }
            }
        }
        
        return res;
    }
};