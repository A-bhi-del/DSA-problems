class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();

        stack<int>st;

        long long bowls = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top() < nums[i]){
                if(st.size() > 1){
                    bowls++;
                }
                st.pop();
            }

            st.push(nums[i]);
        }

        return bowls;
    }
};