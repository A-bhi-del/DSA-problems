class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();

        stack<pair<long long, long long>>st;
        long long ans = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first > nums[i]){
                st.pop();
            }

            if(!st.empty() && nums[i] > st.top().first){
                ans += st.size();
                st.push({nums[i], st.size()});
            }else if(!st.empty() && nums[i] == st.top().first){
                ans += st.top().second;
                st.push({nums[i], st.top().second});
            }else{
                st.push({nums[i], 0});
            }

            // cout<<st.top().second<<" "<<ans<<endl;
        }

        return ans;
    }
};