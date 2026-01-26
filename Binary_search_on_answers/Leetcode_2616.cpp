//You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.
// Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.
// Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

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
