class Solution {
public:
    TreeNode* solve(TreeNode* root, int p, int q){
        if(root == NULL || root->val == p || root->val == q){
            return root;
        }

        TreeNode* left = solve(root->left, p, q);
        TreeNode* right = solve(root->right, p, q);

        if(left != NULL && right != NULL){
            return root;
        }

        if(left != NULL){
            return left;
        }

        return right;
    }

    int LEN(TreeNode* root, int p){
        if(root == NULL){
            return -1;
        }

        if(root->val == p){
            return 0;
        }

        int left = LEN(root->left, p);
        int right = LEN(root->right, p);

        if(left != -1){
            return left + 1;
        }
        
        if(right != -1){
            return right + 1;
        }

        return -1;
    }

    bool generate_path(TreeNode* root, int q, string& str){
        if(root == NULL){
            return false;
        }

        if(root->val == q){
            return true;
        }

        str.push_back('L');

        if(generate_path(root->left, q, str)){
            return true;
        }

        str.pop_back();

        str.push_back('R');

        if(generate_path(root->right, q, str)){
            return true;
        }

        str.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* anc_node = solve(root, startValue, destValue);

        int left_side_len = LEN(anc_node, startValue);

        string right_side = "";
        generate_path(anc_node, destValue, right_side);

        string ans = "";

        for(int i = 0; i < left_side_len; i++){
            ans += 'U';
        }

        ans += right_side;

        return ans;
    }
};