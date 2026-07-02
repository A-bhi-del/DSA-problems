class Solution {
public:
    int base = 131;
    long long mod = 1e9+7;
    bool check(vector<int>& nums, int len){
        int n = nums.size();
        unordered_map<long long, int>mp;
        long long high_power = 1;

        for(int i = 1; i <= len; i++){
            high_power = (high_power * base) % mod;
        }

        int l = 0;
        long long sum = 0;

        for(int r = 0; r < n; r++){
            sum = (sum * base + nums[r]) % mod;

            if(r - l + 1 > len){
                sum = (sum - 1LL * high_power * nums[l]) % mod;
                if(sum < 0){
                    sum += mod;
                } 
                l++;
            }

            if(r-l+1 == len){
                mp[sum]++;
            } 
        }

        for(auto it : mp){
            if(it.second == 1){
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int l = 1;
        int h = nums.size();
        int ans = -1;

        while(l <= h){
            int mid = l + (h - l)/2;

            if(check(nums, mid)){
                h = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};