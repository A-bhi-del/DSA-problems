class Solution {
public:
    int mod = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(32, 0);

        for(int num : nums) {
            for(int bit = 0; bit < 32; bit++) {
                if(num & (1 << bit)) {
                    cnt[bit]++; 
                }
            }
        }

        long long result = 0;

        while(k--) {
            long long c = 0;

            for(int bit = 0; bit < 32; bit++) {
                if(cnt[bit] > 0) {
                    cnt[bit]--;
                    c = (c | (1 << bit));
                }
            }

            result = (result + (c*c)) % mod;
        }

        return result;
    }
};
