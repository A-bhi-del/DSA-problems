class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> maxEndHere(n);

        maxEndHere[0] = arr[0];
        for (int i = 1; i < n; i++) {
            maxEndHere[i] = max(arr[i], arr[i] + maxEndHere[i - 1]);
        }

        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int ans = windowSum;

        for (int i = k; i < n; i++) {
            windowSum += arr[i];
            windowSum -= arr[i - k];

            ans = max(ans, windowSum + max(0, maxEndHere[i - k]));
        }

        return ans;
    }
};