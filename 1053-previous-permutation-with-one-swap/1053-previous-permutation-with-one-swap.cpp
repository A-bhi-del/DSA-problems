class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& nums) {
        int n = nums.size();

        int j = n-1;

        for(int i = n-1; i > 0; i--){
            if(nums[i] < nums[i-1]){
                j = i - 1;
                break;
            }
        }

        // swap(nums[j], nums[n-1]);

        // cout<<j<<endl;

        int maxi = INT_MIN;
        int idx = -1;

        for(int i = j+1; i < n; i++){
            if(nums[i] < nums[j]){
                if(nums[i] > maxi){
                    maxi = nums[i];
                    idx = i;
                }
            }
        }

        // cout<<idx<<endl;

        if(idx != -1){
            swap(nums[j], nums[idx]);
        }

        return nums;
    }
};

// 3 2 1