/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int ans = INT_MIN;
    
    int solve(Node* root){
        if(root == NULL){
            return INT_MAX;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        int minimum = min(left, right);
        
        if(minimum != INT_MAX){
            ans = max(ans, root->data - minimum);
        }
        
        return min(root->data, minimum);
    }
    
    int maxDiff(Node* root) {
        // code here
        int res = solve(root);
        return ans;
    }
};