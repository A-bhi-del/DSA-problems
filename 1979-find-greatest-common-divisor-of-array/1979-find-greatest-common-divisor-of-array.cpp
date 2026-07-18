class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        while (maxi != 0) {
            int temp = maxi;
            maxi = mini % maxi;
            mini = temp;
        }

        return mini;
    }
};