class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0] == 1;
        }

        int ans = gcd(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            ans = gcd(ans, nums[i]);
        }

        return ans == 1;
    }
};