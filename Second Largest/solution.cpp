class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int count = 1;
        int n = arr.size();
        
        sort(arr.begin(), arr.end(), greater<int>());
        
        for(int i = 1; i < n; i++){
            if(arr[i] != arr[i-1]){
                count++;
                if(count == 2) return arr[i];
            }
        }
        
        return -1;
    }
};