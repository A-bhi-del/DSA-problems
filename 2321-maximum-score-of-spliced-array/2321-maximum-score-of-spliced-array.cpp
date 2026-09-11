class Solution {
public:
    vector<int> pre1;
    vector<int> pre2;

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        pre1.resize(n, 0);
        pre2.resize(n, 0);

        pre1[0] = nums1[0];
        pre2[0] = nums2[0];

        for (int i = 1; i < n; i++) {
            pre1[i] = nums1[i] + pre1[i - 1];
            pre2[i] = nums2[i] + pre2[i - 1];
        }

        vector<int>diff1(n, 0);
        vector<int>diff2(n, 0);

        for(int i = 0; i < n; i++){
            diff1[i] = nums2[i] - nums1[i];
            diff2[i] = nums1[i] - nums2[i];
        }

        int l = INT_MAX;
        int e = -1;
        int sum = 0;
        int max_sum = INT_MIN;
        int start = 0;

        for(int r = 0; r < n; r++){
            sum += diff1[r];

            if(max_sum < sum){
                max_sum = sum;
                l = start;
                e = r;
            }

            if(sum < 0){
                sum = 0;
                start = r + 1;
            }
        }

        if(l == INT_MAX){
            return max(pre1[n-1], pre2[n-1]);
        }

        int l2 = INT_MAX;
        int e2 = -1;
        int sum2 = 0;
        int max_sum2 = INT_MIN;
        int start2 = 0;

        for(int r = 0; r < n; r++){
            sum2 += diff2[r];

            if(max_sum2 < sum2){
                max_sum2 = sum2;
                l2 = start2;
                e2 = r;
            }

            if(sum2 < 0){
                sum2 = 0;
                start2 = r + 1;
            }
        }

        if(l2 == INT_MAX){
            return max(pre1[n-1], pre2[n-1]);
        }

        int prev1 = 0;
        int prev2 = 0;

        if (l - 1 >= 0) {
            prev1 = pre1[l - 1];
            prev2 = pre2[l - 1];
        }

        int prev11 = 0;
        int prev22 = 0;

        if(l2 - 1 >= 0){
            prev11 = pre1[l2-1];
            prev22 = pre2[l2-1];
        }

        return max(prev1 + pre2[e] - prev2 + pre1[n-1] - pre1[e], prev22 + pre1[e2] - prev11 + pre2[n-1] - pre2[e2]);
    }
};