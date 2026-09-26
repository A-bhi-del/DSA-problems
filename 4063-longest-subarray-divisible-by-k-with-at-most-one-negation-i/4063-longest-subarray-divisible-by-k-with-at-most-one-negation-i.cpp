class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;
        
        for(int i = 0; i < n; i++){
            nums[i] = ((nums[i] % k) + k) % k; 
        }

        for(int j = 0; j < n; j++){
            unordered_map<int,int>mp;
            mp[0] = 1;
            int sum = 0;
            
            for(int i = j; i < n; i++){
                sum += nums[i];

                int rem = ((sum % k) + k) % k; 

                int x = (((nums[i] * 2) % k) + k) % k;
                mp[x] = 1;

                if(mp.count(rem)){
                    max_len = max(max_len, i - j + 1);
                }
            }
        }
        
        return max_len;
    }
};