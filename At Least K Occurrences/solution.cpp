class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>freq;
        unordered_map<int,int>pos;
        
        int n = arr.size();
        
        int ans = -1;
        
        for(int i = 0; i < n; i++){
            freq[arr[i]]++;
            // if(!pos.count(arr[i])){
            //     pos[arr[i]] = i;
            // }
            
            if(freq.count(arr[i])){
                if(freq[arr[i]] >= k){
                    return arr[i];
                }
            }
            
        }
        
        return ans;
    }
};