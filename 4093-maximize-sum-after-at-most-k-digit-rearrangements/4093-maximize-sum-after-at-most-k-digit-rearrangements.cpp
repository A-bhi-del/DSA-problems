class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;

        vector<pair<int,int>>rev_nums;

        for(int val : nums){
            string str = to_string(val);
            sort(str.begin(), str.end(), greater<char>());
            long long res = 0;

            for(int i = 0; i < str.length(); i++){
                res = (res * 10) + (str[i] - '0');
            }

            rev_nums.push_back({val, res});
        }

        sort(rev_nums.begin(), rev_nums.end(), [](pair<int,int>& p1, pair<int,int>& p2){
            return abs(p1.second - p1.first) > abs(p2.second - p2.first);
        });

        int i = 0;

        while(i < n){
            if(k > 0 && rev_nums[i].first < rev_nums[i].second){
                ans += rev_nums[i].second;
                k--;
            }else{
                ans += rev_nums[i].first;
            }
            i++;
        }

        return ans;
    }
};
