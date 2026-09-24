class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        // if(n < 3){
        //     return -1;
        // }
        
        vector<int>left_max(n, 0);
        vector<int>right_max(n, 0);
        
        left_max[0] = 1;
        right_max[n-1] = 1;
        
        for(int i = 1; i < n; i++){
            left_max[i] = min(left_max[i-1] + 1, arr[i]);
        }
        
        for(int i = n-2; i >= 0; i--){
            right_max[i] = min(right_max[i+1] + 1, arr[i]);
        }
        
        int sum = 0;
        int max_h = INT_MIN;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
            
            max_h = max({max_h, min(left_max[i], right_max[i])});
        }
        
        // cout<<sum<<endl;
        // cout<<max_h<<endl;
        
        return sum - pow(max_h, 2);
    }
};

// 1 2 3 4 2 1
// 1 2 3 4 2 1
// 1 2 3 3 2 1

