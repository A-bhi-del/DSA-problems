class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(int val : nums){
            mp[val]++;
        }

        vector<int>ans;

        for(int val : nums){
            if(mp[val] == 1 && !mp.count(val + 1) && !mp.count(val - 1)){
                ans.push_back(val);
            }
        }

        return ans;
    }
};