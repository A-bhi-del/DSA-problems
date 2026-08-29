class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int nl = l.size();
        int nr = r.size();
        int tr = rank.size();
        
        vector<int>diff(nl, 0);
        vector<int>ans;
        
        for(int i = 0; i < nl; i++){
            diff[i] = r[i] - l[i] + 1;
        }
        
        for(int i = 1; i < nl; i++){
            diff[i] = diff[i] + diff[i-1];
        }
        
        for(int i = 0; i < tr; i++){
            int val = rank[i];
            
            int s = 0;
            int e = nl-1;
            int idx = -1;
            
            while(s <= e){
                int mid = s + (e - s)/2;
                
                if(val <= diff[mid]){
                    idx = mid;
                    e = mid - 1;
                }else{
                    s = mid + 1;
                }
            }
            
            int to_sub = 0;
            if(idx - 1 >= 0){
                to_sub = diff[idx-1];
            }
            
            int req = val - to_sub;
            int le = l[idx];
            
            int corr_num = le + req - 1;
            
            ans.push_back(corr_num);
        }
        
        
        return ans;
    }
};