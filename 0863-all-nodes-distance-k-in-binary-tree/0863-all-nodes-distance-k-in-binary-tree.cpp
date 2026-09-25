/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>>mp;
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }

        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }

        solve(root->left);
        solve(root->right);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL){
            return {};
        }

        if(target == NULL){
            return {};
        }

        solve(root);

        queue<int>q;

        int level = 0;

        q.push(target->val);
        vector<int>ans;
        vector<int>vis(mp.size() + 2, 0);
        // cout<<mp.size()<<endl;
        int vall = target->val;
        vis[vall] = 1;

        // cout<<"i am fine"<<endl;
        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                int vall = q.front();
                q.pop();

                if(level == k){
                    ans.push_back(vall);
                }

                for(auto it : mp[vall]){
                    if(vis[it] == 0){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }

            if(level == k){
                return ans;
            }

            level++;
        }

        return {};
    }
};

// 