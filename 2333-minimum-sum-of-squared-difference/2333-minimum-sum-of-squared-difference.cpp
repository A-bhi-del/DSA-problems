class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> abs_diff(n, 0);
        long long total = 0;
        int maxi = 0;

        for(int i = 0; i < n; i++){
            abs_diff[i] = abs(nums1[i] - nums2[i]);
            total += abs_diff[i];
            maxi = max(maxi, abs_diff[i]);
        }

        if(total <= k) return 0;

        int l = 0;
        int h = maxi;

        while(l <= h){
            int mid = l + (h - l) / 2;

            long long cost = 0;
            for(int i = 0; i < n; i++){
                if(abs_diff[i] > mid){
                    cost += abs_diff[i] - mid;
                }
            }

            if(cost <= k) {
                h = mid - 1;
            }else{
                l = mid + 1;
            } 
        }

        long long cost = 0;
        long long cnt = 0;   
        long long ans = 0;

        for(int i = 0; i < n; i++){
            if(abs_diff[i] > l){
                cost += abs_diff[i] - l;
            }
            if(abs_diff[i] >= l){
                cnt++;
            }else{
                ans += (long long)abs_diff[i] * abs_diff[i];
            }
        }

        long long rem = k - cost;

        ans += rem * (l - 1) * (l - 1);
        ans += (cnt - rem) * l * l;

        return ans;
    }
};