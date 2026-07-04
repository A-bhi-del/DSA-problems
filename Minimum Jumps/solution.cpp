class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = 0;
        int jumps = 1;
        
        while(i + arr[i] < n-1){
            int idx = -1;
            int maxi = INT_MIN;
            for(int j = i+1; j <= i + arr[i]; j++){
                if(maxi <= j + arr[j]){
                    maxi = j + arr[j];
                    idx = j;
                }
            }
            jumps++;
            if(idx == -1){
                return -1;
            }
            i = idx;
        }
        
        return jumps;
    }
};
