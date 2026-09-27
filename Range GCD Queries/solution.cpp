class Solution {
public:
    int GCD(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void build(vector<int>& arr, vector<int>& st, int i, int s, int e) {
        if (s == e) {
            st[i] = arr[s];
            return;
        }

        int mid = s + (e - s) / 2;

        build(arr, st, 2 * i + 1, s, mid);
        build(arr, st, 2 * i + 2, mid + 1, e);

        st[i] = GCD(st[2 * i + 1], st[2 * i + 2]);
    }

    void update(vector<int>& st, int idx, int val, int i, int s, int e) {
        if (s == e) {
            st[i] = val;
            return;
        }

        int mid = s + (e - s) / 2;

        if (idx <= mid) {
            update(st, idx, val, 2 * i + 1, s, mid);
        } 
        else {
            update(st, idx, val, 2 * i + 2, mid + 1, e);
        }

        st[i] = GCD(st[2 * i + 1], st[2 * i + 2]);
    }

    int query(vector<int>& st, int L, int R, int i, int s, int e) {
        if (R < s || L > e) {
            return 0;
        }

        if (L <= s && e <= R) {
            return st[i];
        }

        int mid = s + (e - s) / 2;

        int left = query(st, L, R, 2 * i + 1, s, mid);
        int right = query(st, L, R, 2 * i + 2, mid + 1, e);

        return GCD(left, right);
    }

    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> st(4 * n);
        build(arr, st, 0, 0, n - 1);
        vector<int> ans;

        for(auto &q : queries){
            if (q[0] == 0){
                int l = q[1];
                int r = q[2];
                ans.push_back(query(st, l, r, 0, 0, n - 1));
            }else{
                int index = q[1];
                int value = q[2];

                update(st, index, value, 0, 0, n - 1);
            }
        }

        return ans;
    }
};