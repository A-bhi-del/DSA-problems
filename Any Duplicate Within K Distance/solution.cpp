class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mp;
        
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            if(mp.count(arr[i])){
                if(i - mp[arr[i]] <= k){
                    return true;
                }
            }
            mp[arr[i]] = i;
        }
        
        return false;
    }
};