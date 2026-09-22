class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();

        unordered_map<long long, unordered_map<int, int>>freq;
        unordered_map<long long, vector<int>>mp;

        long long sum = capacity[0];
        freq[capacity[0]][capacity[0]]++;
        mp[capacity[0]].push_back(0);

        long long ans = 0;

        for(int i = 2; i < n; i++){
            sum += capacity[i-1];
            int req = capacity[i];
            freq[sum][capacity[i-1]]++;
            mp[sum].push_back(i-1);

            if(freq.count(sum - req)){
                // cout<<sum-req<<" "<<req<<endl;
                long long val = freq[sum-req][req];
                // cout<<freq[sum-req][req]<<endl;
                ans += val;
                if(mp[sum-req].back() + 1 >= i && mp[sum-req].size() > 1){
                    if(capacity[mp[sum-req].back()] == req){
                        ans -= 1;
                    }
                }
                // cout<<ans<<endl;
            }
        }

        return ans;
    }
};