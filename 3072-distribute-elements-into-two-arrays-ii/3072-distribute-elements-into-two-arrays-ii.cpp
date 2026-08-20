class segTree {
    int n;
    vector<int>segment_tree;

public:
    segTree(int n){
        this->n = n;
        segment_tree.resize(4*n, 0);
    }

    void update_segTree(int i, int s, int e, int idx){
        if(s == e){
            segment_tree[i]++;
            return;
        }

        int m = s + (e - s)/2;

        if(idx <= m){
            update_segTree(2*i+1, s, m, idx);
        }else{
            update_segTree(2*i+2, m+1, e, idx);
        }

        segment_tree[i] = segment_tree[2*i+1] + segment_tree[2*i+2];
    }

    int search_query(int l, int r, int s, int e, int i){
        if(l > e || r < s){
            return 0;
        }

        if(l <= s && e <= r){
            return segment_tree[i];
        }

        int m = s + (e - s)/2;

        return search_query(l, r, s, m, 2*i+1) + search_query(l, r, m+1, e, 2*i+2);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr1;
        vector<int>arr2;

        vector<int>duplicate = nums;
        sort(duplicate.begin(), duplicate.end());

        unordered_map<int,int>mp;

        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(!mp.count(duplicate[i])){
                mp[duplicate[i]] = index;
                index++;
            }
        }
        segTree segTree1(n);
        segTree segTree2(n);

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        segTree1.update_segTree(0, 0, index-1, mp[nums[0]]);
        segTree2.update_segTree(0, 0, index-1, mp[nums[1]]);

        for(int i = 2; i < n; i++){
            int idx = mp[nums[i]];

            int GC_arr1 = segTree1.search_query(idx + 1, index-1, 0, index-1, 0);

            int GC_arr2 = segTree2.search_query(idx + 1, index-1, 0, index-1, 0);

            if(GC_arr1 > GC_arr2){
                arr1.push_back(nums[i]);
                segTree1.update_segTree(0, 0, index-1, idx);
            }else if(GC_arr1 < GC_arr2){
                arr2.push_back(nums[i]);
                segTree2.update_segTree(0, 0, index-1, idx);
            }else if(GC_arr1 == GC_arr2){
                if(arr1.size() <= arr2.size()){
                    arr1.push_back(nums[i]);
                    segTree1.update_segTree(0, 0, index-1, idx);
                }else{
                    arr2.push_back(nums[i]);
                    segTree2.update_segTree(0, 0, index-1, idx);
                }
            }
        }

        for(int i = 0; i < arr2.size(); i++){
            arr1.push_back(arr2[i]);
        }

        return arr1;
    }
};