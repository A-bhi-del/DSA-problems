class Solution {
public:
    int mod = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int one = 0;
        int zero = 0;
        int sum = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum % 2 == 1){
                one++;
            }else{
                zero++;
            }

            int type = sum % 2;

            if(type == 1){
                ans = (ans + zero + 1) % mod;
            }else{
                ans = (ans + one) % mod;
            }
        }

        return ans;
    }
};