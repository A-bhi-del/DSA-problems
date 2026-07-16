class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int>copy = nums2;
        int n = nums1.size();

        sort(copy.begin(), copy.end());
        sort(nums1.begin(), nums1.end());

        vector<int>used(n, 0);
        vector<int>unused;

        unordered_map<int, vector<int>>mp;

        int i = 0;
        int j = 0;

        while(i < n && j < n){
            if(nums1[i] > copy[j]){
                mp[copy[j]].push_back(nums1[i]);
                used[i] = 1;
                j++;
            }
            i++;
        }

        // for(auto it : mp){
        //     cout<<it.first<<" "<<it.second.back()<<endl;
        // }

        for(int k = 0; k < n; k++){
            if(used[k] == 0){
                // cout<<k<<endl;
                unused.push_back(nums1[k]);
            }
        }

        // cout<<"step 2"<<endl;
        vector<int>ans(n, -1);

        for(int k = 0; k < n; k++){
            if(!mp[nums2[k]].empty()){
                ans[k] = mp[nums2[k]].back();
                mp[nums2[k]].pop_back();

                if(mp[nums2[k]].size() == 0){
                    mp.erase(nums2[k]);
                }
            }
        }

        // cout<<"step 3"<<endl;

        for(int k = 0; k < n; k++){
            if(ans[k] == -1){
                if(unused.size() > 0){
                    ans[k] = unused.back();
                    unused.pop_back();
                }
            } 
        }


        return ans;
    }
};