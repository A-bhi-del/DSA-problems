class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s = nums[0];
        int j = 0;
        vector<int>ans;

        while(j < n){
            if(s < nums[j]){
                ans.push_back(s);
                s++;
            }else{
                s++;
                j++;
            }
        }

        return ans;
    }
};