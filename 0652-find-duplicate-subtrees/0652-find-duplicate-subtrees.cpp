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
    unordered_map<string,int>mp;
    vector<TreeNode*>ans;

    string solve(TreeNode* root){
        if(root == NULL){
            return "";
        }

        string left = solve(root->left);
        string right = solve(root->right);
        string num = to_string(root->val);
        string res = num + "," + left + "," + right;

        if(mp[res] == 1){
            ans.push_back(root);
        }
        mp[res]++;

        return res;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};