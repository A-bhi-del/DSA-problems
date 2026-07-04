class Solution {
  public:
    bool check(long long pages, vector<int>& arr, int parts){
        int groups = 1;
        
        long long sum = 0;

        for(int val : arr){
            if(sum + val <= pages){
                sum += val;
            }else{
                groups++;
                sum = val;
            }
        }
        
        return (groups <= parts) ? true : false;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n < k || k <= 0){
            return -1;
        }
        
        long long sum = 0;

        for(int val : arr){
            sum += val;
        }
        
        long long l = *max_element(arr.begin(), arr.end());
        long long h = sum;
        long long ans = -1;
        
        while(l <= h){
            long long mid = l + (h - l)/2;
            
            if(check(mid, arr, k)){
                h = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return (int)ans;
    }
};