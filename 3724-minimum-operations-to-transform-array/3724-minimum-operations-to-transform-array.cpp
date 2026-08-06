class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long val1 = LLONG_MIN;
        long long val2 = LLONG_MAX;
        int n = nums1.size();
        long long count = 1;

        for(int i = 0; i < n; i++){
            long long val = nums1[i];

            if(val <= nums2[n] && val <= nums2[i]){
                long long temp = min(nums2[i], nums2[n]);
                val1 = max(val1, temp);
            }else if(val > nums2[n] && val > nums2[i]){
                long long temp = max(nums2[i], nums2[n]);
                val2 = min(val2, temp);
            }else if(val <= nums2[n] && val >= nums2[i]){
                val1 = max(val1, val);
            }else if(val > nums2[n] && val <= nums2[i]){
                val2 = min(val2, val);
            }
        }
        
        if(val1 == LLONG_MIN){
            nums1.push_back(val2);
        }else if(val2 == LLONG_MIN){
            nums1.push_back(val1);
        }else if(abs(val1 - nums2[n]) <= abs(val2 - nums2[n])){
            nums1.push_back(val1);
        }else{
            nums1.push_back(val2);
        }

        for(int i = 0; i <= n; i++){
            count += abs(nums2[i] - nums1[i]);
        }

        return count;
    }
};

// 1 2 3 , 1 2 3 4
// 1 2 3 3 , 1 2 3 4 

// 3 2 1 

// 2 8
// 1 -5