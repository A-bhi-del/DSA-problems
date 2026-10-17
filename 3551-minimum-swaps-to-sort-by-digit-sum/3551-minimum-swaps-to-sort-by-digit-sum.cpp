class Solution {
public:
    static int digit_sum(int val){
        int sum = 0;

        while(val > 0){
            sum += val % 10;
            val /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int>temp = nums;

        sort(nums.begin(), nums.end(), [](int& a, int& b){
            int x = digit_sum(a);
            int y = digit_sum(b);
            if(x == y){
                return a < b;
            }

            return x < y;
        });

        unordered_map<int,int>mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]] = i;
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(vis[i] || mp[temp[i]] == i) continue;

            int j = i;
            int len = 0;

            while(!vis[j]){
                vis[j] = true;
                j = mp[temp[j]];
                len++;
            }

            ans += len - 1;
        }

        return ans;
    }
};

// 9 7 7 7 