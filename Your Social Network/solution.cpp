class Solution {
  public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        // code here
        int n = arr.size();
        int total_users = n + 2;
        
        vector<vector<int>>ans;
        
        for(int i = 2; i < total_users; i++){
            int curr = i;
            
            vector<int>path;
            
            while(curr != 1){
                curr = arr[curr-2];
                path.push_back(curr);
            }
            
            int len = path.size();
            
            for(int j = len - 1; j >= 0; j--){
                ans.push_back({i, path[j], j+1});
            }
        }
        
        return ans;
    }
};

