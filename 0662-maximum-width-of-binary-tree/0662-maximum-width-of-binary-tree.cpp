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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        deque<pair<TreeNode*, int>>q;
        q.push_back({root,0});

        int width = INT_MIN;
        while(!q.empty()){
            int size = q.size();

            width = max(width, q.back().second - q.front().second + 1);

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second;

                q.pop_front();

                if(node->left) q.push_back({node->left, 2*idx + 1});
                if(node->right) q.push_back({node->right, 2*idx + 2});
            }
        }

        return width;
    }
};