class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();

        for(int i = 0; i < n; i++){
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());
        
        long long half_idx = n/2;
        long long i = 0;
        long long pos_sum = 0;
        long long nege_sum = 0;

        while(i < half_idx){
            nege_sum += nums[i] * nums[i];
            i++;
        }

        while(i < n){
            pos_sum += nums[i] * nums[i];
            i++;
        }

        return pos_sum - nege_sum;
    }
};