class Solution {
public:
    vector<int>mp;
    bool check(int val){
        for(int i = 1; i <= val/2; i++){
            int a = i;
            int b = val - i;

            if(a == b){
                if(mp[a] >= 2) return true;
            }else{
                if(mp[a] > 0 && mp[b] > 0) return true;
            }
        }

        for(int i = 1; i + val < 501; i++){
            int a = val;
            int b = val + i;

            if(mp[b] > 0 && mp[i] > 0) return true;
        }

        return false;
    }
    
    int maxSubarray(vector<int>& nums) {
        mp.resize(501, 0);
        int n = nums.size();

        int l = 0;

        int ans = 1;

        for(int r = 0; r < n; r++){
            int val = nums[r];

            while(l < n && check(val)){
                mp[nums[l]]--;
                l++;
            }

            mp[val]++;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};