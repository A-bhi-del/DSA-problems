class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        bool is_zero = false;
        for(int i = 0; i < n; i++){
            arr.push_back(arr[i]);
            
            if(arr[i] == 0){
                is_zero = true;
            }
        }
        
        __int128 mul = 1;
        int l = 0;
        int count_zero = 0;
        __int128 max_ans = -1e30;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != 0){
                mul = mul * arr[i];
            }else{
                count_zero++;
            }
            
            while(i - l + 1 - count_zero > k){
                if(arr[l] == 0){
                    count_zero--;
                }else{
                    mul = mul / arr[l];
                }
                l++;
            }
            
            if(i - l + 1 - count_zero == k){
                // cout<<i<<" "<<count_zero<<endl;
                max_ans = max(max_ans, mul);
            }
        }
        
        if(is_zero){
            __int128 val = 0;
            max_ans = max(max_ans, val);
        }
        
        return max_ans;
    }
};

// 1 2 -1 -3 -6 4, k = 4




// -4 -3 -2 -2 -1 -1 0 0 1 1 2 2 3 4 4 -4 -3 -2 -2 -1 -1 0 0 1 1 2 2 3 4 4 










