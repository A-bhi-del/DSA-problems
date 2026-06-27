class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int>mp;
        unordered_map<int,int>freq;

        for(int num : nums){
            freq[num]++;
        }

        int one = -1;

        if(freq.count(1)){
            one = freq[1];
        }

        sort(nums.begin(), nums.end(), greater<int>());

        for(int num : nums){
            long long val = 0;
            if(num <= 100000){
                val = 1LL * num * num;
            }

            if(mp.count(val) && !mp.count(num) && freq[num] >= 2){
                mp[num] += mp[val];
            }

            mp[num]++;

            if(freq[num] > 2){
                mp[num]--;
                freq[num]--;
            }
        }

        int ans = INT_MIN;

        for(auto it : mp){
            ans = max(ans, it.second);
        }

        ans = max(ans, one);

        return (ans % 2 == 0) ? ans - 1 : ans;
    }
};

// 1 1 2 2 4 4 5 5 8 8 16 16 