class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt_tar = 0;
        int cnt_less_than_tar = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                cnt_tar++;
            }else if(nums[i] < target){
                cnt_less_than_tar++;
            }
        }

        vector<int>ans;

        while(cnt_tar > 0){
            ans.push_back(cnt_less_than_tar);
            cnt_less_than_tar++;
            cnt_tar--;
        }

        return ans;
    }
};