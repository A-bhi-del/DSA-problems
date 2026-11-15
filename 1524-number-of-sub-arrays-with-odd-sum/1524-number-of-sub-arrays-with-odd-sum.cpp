class Solution {
public:
    int mod = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        int sum = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++){
            sum += arr[i];
            mp[sum % 2]++;

            int type = sum % 2;

            if(type == 1){
                if(mp.count(0)){
                    ans = (ans + mp[0]) % mod;
                }
                ans = (ans + 1) % mod;
            }else{
                if(mp.count(1)){
                    ans = (ans + mp[1]) % mod;
                }
            }
        }

        return ans;
    }
};