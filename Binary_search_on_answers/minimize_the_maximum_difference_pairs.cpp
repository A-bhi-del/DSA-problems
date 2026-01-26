class Solution {
public:
    int pairs(vector<int>& nums, int target){
        int count = 0;

        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i+1] - nums[i] <= target){
                count++;
                i++;
            }
        }

        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums[n-1] - nums[0];
        int ans = 0;

        while(low <= high){
            
            int mid = low + (high - low)/2;

            if(pairs(nums, mid) < p){
                low = mid + 1;
            }else{
                ans = mid;
                high = mid - 1;
            }

        }

        return ans;
    }
};

// 1 1 2 3 7 10
// 0 , 9