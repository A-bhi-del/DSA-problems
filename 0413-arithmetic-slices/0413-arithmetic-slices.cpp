class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }

        int ans = 0;
        int cnt = 2;
        int diff = nums[1] - nums[0];

        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i-1] == diff){
                cnt++;
            }else{
                if(cnt >= 3){
                    int num = cnt - 2;
                    ans += (num * (num + 1))/2;
                }
                cnt = 2;
                diff = nums[i] - nums[i-1];
            }
        }

        if(cnt >= 3){
            int num = cnt - 2;
            ans += (num * (num + 1))/2;
        }

        return ans;
    }
};