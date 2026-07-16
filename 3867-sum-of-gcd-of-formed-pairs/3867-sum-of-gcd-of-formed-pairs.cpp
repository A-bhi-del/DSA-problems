class Solution {
public:
    long long GCD(long long max_val, long long val){
        while(val != 0){
            long long rem = max_val % val;
            max_val = val;
            val = rem;
        }

        return max_val;
    }

    long long gcdSum(vector<int>& nums) {
        long long maxi = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            long long val = nums[i];
            maxi = max(val, maxi);
            nums[i] = GCD(maxi, nums[i]);
        }

        sort(nums.begin(), nums.end());

        long long sum = 0;

        int i = 0;
        int j = n-1;

        while(i < j){
            sum += GCD(nums[j], nums[i]);
            i++;
            j--;
        }

        return sum;
    }
};