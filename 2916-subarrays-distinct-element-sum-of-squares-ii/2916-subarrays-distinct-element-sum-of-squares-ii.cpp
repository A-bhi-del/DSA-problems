class Solution {
public:
    int MOD = 1e9+7;
    int n;

    vector<long long> sqSegTree;
    vector<long long> SegTree;
    vector<long long> lazyTree;

    void lazyAddition(int i, int l, int r, int val) {
        int len = (r-l+1);

        sqSegTree[i] += 2*val*SegTree[i] + len * val * val;
        SegTree[i] += (len * val);
    }

    void updateRange(int start, int end, int i, int l, int r, int val) {
        if(lazyTree[i] != 0) {
            lazyAddition(i, l, r, lazyTree[i]);

            if(l != r) {
                lazyTree[2*i+1] += lazyTree[i];
                lazyTree[2*i+2] += lazyTree[i];
            }

            lazyTree[i] = 0;
        }

        if(l > end || r < start || l > r) {
            return;
        }

        if(l >= start && r <= end) {
            lazyAddition(i, l, r, val);

            if(l != r) {
                lazyTree[2*i+1] += val;
                lazyTree[2*i+2] += val;
            }
            return;
        }

        int mid = l + (r-l)/2;
        updateRange(start, end, 2*i+1, l, mid, val);
        updateRange(start, end, 2*i+2, mid+1, r, val);

        SegTree[i]   = SegTree[2*i+1] + SegTree[2*i+2];
        sqSegTree[i] = sqSegTree[2*i+1] + sqSegTree[2*i+2];
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sqSegTree.resize(4*n, 0);
        SegTree.resize(4*n, 0);
        lazyTree.resize(4*n, 0);

        vector<int> lastSeenIdx(100001, -1);
        long long result = 0;

        for(int i = 0; i < n; i++) {
            int start = lastSeenIdx[nums[i]] + 1;
            int end   = i;

            updateRange(start, end, 0, 0, n-1, 1);

            result = (result + sqSegTree[0]) % MOD;

            lastSeenIdx[nums[i]] = i;
        }

        return result;
    }
};

// {1} -> 1 -> 1
// {1,2} -> 2, 1 -> 4 + 1
// {1,2,1} -> 2, 2, 1 -> 4 + 4 + 1
// 1 + 4 + 1 + 4 + 4 + 1 => 15

// {2} -> 1 -> 1
// {2,2} -> 1, 1 -> 1 + 1
// 1 + 1 + 1 => 3