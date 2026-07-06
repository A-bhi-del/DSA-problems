class Solution {
public:
    struct Array_ka_rolling {
        long long mod = 1e9 + 7;
        long long base = 438785;
        vector<long long> power;
        vector<long long> pref;

        Array_ka_rolling(const vector<int>& num) {
            int n = num.size();
            power.resize(n + 1, 1);
            pref.resize(n + 1, 0);

            for (int i = 0; i < n; i++) {
                pref[i + 1] = (pref[i] * base + num[i]) % mod;
                power[i + 1] = (power[i] * base) % mod;
            }
        }

        long long hash_laa(int l, int r) {
            long long ans = pref[r + 1] - (pref[l] * power[r - l + 1]) % mod;

            if (ans < 0) {
                ans += mod;
            }

            return ans;
        }
    };

    long long
    getSum(vector<int>& nums) {
        int n = nums.size();
        Array_ka_rolling forword = Array_ka_rolling(nums);
        reverse(nums.begin(), nums.end());
        Array_ka_rolling backword = Array_ka_rolling(nums);
        reverse(nums.begin(), nums.end());

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (long long)nums[i];
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int lo = 0;
            int hi = min(i, n - i - 1);

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                int l = i - mid;
                int r = mid + i;

                long long forwordHash = forword.hash_laa(l, r);
                long long backwordHash =
                    backword.hash_laa(n - r - 1, n - l - 1);

                if (forwordHash == backwordHash) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }

            }
            long long sum = prefix[i + lo] - prefix[i - lo + 1];
            ans = max(ans, sum);
        }

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                int lo = 1;
                int hi = min(i + 1, n - i - 1);

                while (lo <= hi) {
                    int mid = lo + (hi - lo) / 2;

                    int l = i - mid + 1;
                    int r = mid + i;

                    long long forwordHash = forword.hash_laa(l, r);
                    long long backwordHash =
                        backword.hash_laa(n - r - 1, n - l - 1);

                    if (forwordHash == backwordHash) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }

                }
                long long sum = prefix[i + lo] - prefix[i - lo + 2];
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};