class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        if(arr[0] >= 0){
            return arr[0];
        }
        
        int nege = 0;
        int mul = 1;
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                mul *= arr[i];
            }else if(arr[i] < 0){
                nege++;
            }
        }
        
        if(nege % 2 == 0){
            nege -= 1;
        }
        
        for(int i = 0; i < nege; i++){
            mul *= arr[i];
        }
        
        return mul;
    }
};