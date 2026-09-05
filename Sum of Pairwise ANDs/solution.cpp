class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        
        long long ans = 0;
        
        for(long long bit = 0; bit < 32; bit++){
            long long one = 0;
            for(long long val : arr){
                if((val & (1 << bit))){
                    one++;
                }
            }
            
            long long temp = pow(2, bit);
            ans += temp * ((one * (one - 1))/2);
        }
        
        return ans;
    }
};

// 0 1 0 1
// 1 0 1 0
// 1 1 1 1

// 0 0 1 0 1 0
// 0 1 0 1 0 0
// 0 1 1 1 1 0
// 1 0 1 0 0 0

// 0 16 + 24 + 4 + 2

// 1 0 1 1 1 0

// 10 & (20 || 30 || 40)