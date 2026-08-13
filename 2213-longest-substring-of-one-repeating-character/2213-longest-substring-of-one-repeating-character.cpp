class Solution {
public:
    struct Node{
        int max_len = 0;
        int pre_len = 0;
        int suff_len = 0;
        char pre = 0;
        char suff = 0;
    };

    vector<Node>segTree;

    Node Concate(Node& left, Node& right, int left_len, int right_len){
        Node result;

        result.pre = left.pre;
        result.suff = right.suff;

        result.pre_len = left.pre_len;
        if(left_len == left.pre_len && left.suff == right.pre){
            result.pre_len = left.pre_len + right.pre_len;
        }

        result.suff_len = right.suff_len;
        if(right_len == right.suff_len && right.pre == left.suff){
            result.suff_len = right.suff_len + left.suff_len;
        }

        result.max_len = max(left.max_len, right.max_len);
        if(left.suff == right.pre){
            result.max_len = max(result.max_len, left.suff_len + right.pre_len);
        }

        return result;
    }

    void build_segTree(int i, int s, int e, string& st){
        if(s == e){
            segTree[i] = {1, 1, 1, st[s], st[s]};
            return;
        }

        int mid = s + (e - s)/2;

        build_segTree(2*i+1, s, mid, st);
        build_segTree(2*i+2, mid+1, e, st);

        segTree[i] = Concate(segTree[2*i+1], segTree[2*i+2], mid - s + 1, e - (mid + 1) + 1);
    }

    void update_segTree(int i, int s, int e, int pos, char ch){
        if(s == e){
            segTree[i] = {1, 1, 1, ch, ch};
            return;
        }

        int mid = s + (e - s)/2;

        if(pos <= mid){
            update_segTree(2*i+1, s, mid, pos, ch);
        }else{
            update_segTree(2*i+2, mid+1, e, pos, ch);
        }

        segTree[i] = Concate(segTree[2*i+1], segTree[2*i+2], mid - s + 1, e - (mid + 1) + 1);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        segTree.resize(4*n, Node());
        int q_size = queryIndices.size();

        build_segTree(0, 0, n-1, s);

        vector<int>ans(q_size, 0);

        for(int i = 0; i < q_size; i++){
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update_segTree(0, 0, n-1, pos, ch);

            ans[i] = segTree[0].max_len;
        }

        return ans;
    }
};