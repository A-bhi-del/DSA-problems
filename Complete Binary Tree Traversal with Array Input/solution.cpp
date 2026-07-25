class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>ans;
        
        int len = 1;
        int i = 0;
        vector<int>temp;
        
        while(i < n){
            temp.push_back(arr[i]);
            
            if(temp.size() == len){
                ans.push_back(temp);
                temp.clear();
                len = 2*len;
            }
            
            i++;
        }
        
        if(!temp.empty() && temp.size() < len){
            ans.push_back(temp);
        }
        
        for(auto& arr : ans){
            sort(arr.begin(), arr.end());
        }
        
        return ans;
    }
};
