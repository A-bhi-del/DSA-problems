// The distance of a pair of integers a and b is defined as the absolute difference between a and b.
// Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 
class Solution {
public:
    int BS_check(vector<int>& arr, int k){
        int n = arr.size();
        int left = 0;
        long long count = 0;

        for(int right = 0; right < n; right++) {
            while(arr[right] - arr[left] > k) {
                left++;
            }
            count += (right - left);
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums[n-1] - nums[0];
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(BS_check(nums, mid) < k){
                low = mid + 1;
            }else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};


// mid = 19/2 = 9
// 1 3 5 7 9 10 18 19 20 , k = 9
// count = 1 + 2 + 3 + 4 + 5 + 2 + 2 + 2 = 21