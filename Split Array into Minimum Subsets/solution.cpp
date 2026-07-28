class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here

        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int count = 1;

        for(int i = 1; i < n; i++){
            if(arr[i] != arr[i-1] + 1){
                count++;
            }
        }

        return count;
    }
};
