class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        stack<pair<int,int>>st;
        int s_i = 10001;
        int e_i = -1;

        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first > nums[i]){
                s_i = min({s_i, st.top().second});
                st.pop();
            }

            st.push({nums[i], i});
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top().first < nums[i]){
                e_i = max(e_i, st.top().second);
                st.pop();
            }

            st.push({nums[i], i});
        }

        if(s_i == 10001 || e_i == -1){
            return 0;
        }

        return e_i - s_i + 1;
    }
};

// 2 6 4 8 10 9 15
// 2,0 4,2 8,3 9,5 15,6 