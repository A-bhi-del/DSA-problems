class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>arr;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int>index;

        for(int i = 0; i < n; i++){
            index.push_back(arr[i].second);
        }

        vector<int>seg_idx;
        seg_idx.push_back(0);

        for(int i = 1; i < n; i++){
            int c_val = arr[i].first;
            int p_val = arr[i-1].first;

            if(c_val - p_val > limit){
                seg_idx.push_back(i-1);
                seg_idx.push_back(i);
            }
        }

        seg_idx.push_back(n-1);

        for(int i = 0; i < seg_idx.size(); i+=2){
            int s = seg_idx[i];
            int e = seg_idx[i+1];

            sort(index.begin() + s, index.begin() + e + 1);
        }

        for(int i = 0; i < n; i++){
            int idx = index[i];
            int val = arr[i].first;
            nums[idx] = val;
        }

        return nums;
    }
};

// 1 1 2 6 7 18  
// 0 2 3 4 5 5