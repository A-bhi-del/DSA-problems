//Problem statement
// A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
// Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        stack<int>st;
        for(int i = 0; i < n; i++){
            if(st.empty() || nums[st.top()] > nums[i]){
                st.push(i);
            }
        }

        int max_width = 0;
        for(int i = n-1; i >= 0; i--){
            if(!st.empty() && (st.top() < i)){
                while(!st.empty() && nums[st.top()] <= nums[i]){
                    max_width = max(max_width, i-st.top());
                    st.pop();
                }
            }else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }

        return max_width;
    }
};

