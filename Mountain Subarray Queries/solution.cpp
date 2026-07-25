class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        vector<bool>ans;
        
        vector<int>prefix(n, 0);
        prefix[0] = 0;
        
        for(int i = 1; i < n; i++){
            if(arr[i] <= arr[i-1]){
                prefix[i] = prefix[i-1];
            }else{
                prefix[i] = i;
            }
        }
        
        vector<int>suffix(n, 0);
        suffix[n-1] = n-1;
        
        for(int i = n-2; i >= 0; i--){
            if(arr[i] <= arr[i+1]){
                suffix[i] = suffix[i+1];
            }else{
                suffix[i] = i;
            }
        }
        
        for(auto query : queries){
            int l = query[0];
            int r = query[1];
            
            if(suffix[l] >= prefix[r]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};

/*
2 3 2 4 4 6 3 2
I I D I D I D D

pre[j]=
*/