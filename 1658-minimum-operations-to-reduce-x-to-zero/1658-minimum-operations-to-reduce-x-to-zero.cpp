class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        if(nums[n-1] > x && nums[0] > x){
            return -1;
        }

        int total = 0;
        for(int i = 0; i < n; i++){
            total += nums[i];
        }

        if(total < x) return -1;

        vector<int>ans;

        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);
        }

        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);
        }
        
        int n2 = ans.size();

        int res = INT_MAX;

        int l = 0;
        int sum = 0;
        for(int r = 0; r < n2; r++){
            sum += ans[r];

            while(sum > x){
                sum -= ans[l];
                l++;
            }

            if(sum == x && !(l > 0 && r < n-1) && !(l > n && r < (2*n)-1)){
                res = min(res, r - l + 1);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};

// 3 2 20 1 1 3 3 2 20 1 1 3 