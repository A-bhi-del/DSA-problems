class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int min_idx = -1;
        int max_idx = -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            if(mini > nums[i]){
                mini = nums[i];
                min_idx = i;
            }

            if(maxi < nums[i]){
                maxi = nums[i];
                max_idx = i;
            }
        }

        int first_combi = max(max_idx + 1, min_idx + 1);
        int second_combi = max(n - max_idx, n - min_idx);
        int third_combi = min(min_idx + 1, max_idx + 1) + min(n - max_idx, n - min_idx);

        return min({first_combi, second_combi, third_combi});
    }
};