/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string res = "";
    void solve(TreeNode* root, string path){
        if(!root) return;

        path += char(root->val + 'a');

        if(!root->left && !root->right){
            reverse(path.begin(), path.end());
            if(res.empty() || path < res){
                res = path;
            }
        }

        solve(root->left, path);
        solve(root->right, path);
    }

    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        return res;
    }
};