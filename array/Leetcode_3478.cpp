// You are given two integer arrays, nums1 and nums2, both of length n, along with a positive integer k.
// For each index i from 0 to n - 1, perform the following:
// Find all indices j where nums1[j] is less than nums1[i].
// Choose at most k values of nums2[j] at these indices to maximize the total sum.
// Return an array answer of size n, where answer[i] represents the result for the corresponding index i.

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<long long>>map;
        vector<long long>ans(n, 0);

        for(int i = 0; i < n; i++){
            map.push_back({nums1[i], nums2[i], i});
        }

        sort(map.begin(), map.end());

        // for(int i = 0; i < n; i++){
        //     cout<<map[i][0]<<" "<<map[i][1]<<" "<<map[i][2]<<endl;
        // }

        if(map[0][0] == map[n-1][0]){
            return ans;
        }

        long long total = 0;
        priority_queue<long long, vector<long long>, greater<long long>>min_pq;
        long long min_total = 0;

        for(int i = 0; i < n; i++){
            if(i > k){
                while(min_pq.size() > k){
                    min_total += min_pq.top();
                    min_pq.pop();
                }
                ans[map[i][2]] = total - min_total;
            }else{
                ans[map[i][2]] = total;
            }

            long long idx = i;

            while((i < n-1) && (map[i+1][0] == map[idx][0])){
                ans[map[i+1][2]] = ans[map[idx][2]];
                total += map[i+1][1];
                min_pq.push(map[i+1][1]);
                i++;
            }

            min_pq.push(map[idx][1]);
            total += map[idx][1];
        }

        return ans;
    }
};