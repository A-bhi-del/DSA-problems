class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return true;
        }

        int pos = 0;
        int nege = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] < 0){
                nege++;
            }else if(nums[i] - nums[i-1] > 0){
                pos++;
            }
        }

        if(nege > 0 && pos > 0){
            return false;
        }

        return true;
    }
};