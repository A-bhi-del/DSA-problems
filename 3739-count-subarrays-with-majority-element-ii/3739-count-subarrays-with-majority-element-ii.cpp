class Solution {
public:
    vector<long long>segTree;

    void update_segTree(int i, int s, int e, int pos){
        if(s == e){
            segTree[i] += 1;
            return; 
        }

        int mid = s + (e - s)/2;

        if(pos <= mid){
            update_segTree(2*i+1, s, mid, pos);
        }else{
            update_segTree(2*i+2, mid+1, e, pos);
        }


        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    int query(int i, int l, int r, int s, int e){
        if(r < s || l > e){
            return 0;
        }

        if(l <= s && e <= r){
            return segTree[i];
        }

        int mid = s + (e - s)/2;

        return query(2*i+1, l, r, s, mid) + query(2*i+2, l, r, mid + 1, e);
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<long long>pref(n+1, 0);
        vector<long long>comp;

        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                nums[i] = 1;
            }else{
                nums[i] = -1;
            }
        }

        for(int i = 1; i <= n; i++){
            pref[i] = pref[i-1] + nums[i-1];
        }

        comp = pref;

        sort(comp.begin(), comp.end());

        int idx = 1;
        unordered_map<long long, int>mp;

        for(int i = 0; i < comp.size(); i++){
            if(!mp.count(comp[i])){
                mp[comp[i]] = idx;
                idx++;
            }
        }

        segTree.resize(4*idx, 0);

        long long ans = 0;

        for(int i = 0; i < pref.size(); i++){
            int compressed_idx = mp[pref[i]];

            ans += query(0, 1, compressed_idx - 1, 1, idx-1);

            update_segTree(0, 1, idx-1, compressed_idx);
        }

        return ans;
    }
};

/*
1 2 2 2 1
2 1 2 1 2
1 1 2 2 2 
2 2 2 1 1

1 3 2 4 5 4 4 2 3 4 3 , t = 4
-1 -1 -1 1 -1 1 1 -1 -1 1 -1

0 -1 -2 -3 -2 -3 -2 -1 -2 -3 -2 -3
*/