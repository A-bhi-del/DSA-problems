/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    int max_path = 0;
    void solve(Node* root, int prev, int len){
        if(root == NULL){
            return;
        }
        
        if(prev == -1 || root->data == prev+1){
            len++;
        }else{
            len = 1;
        }
        max_path = max(max_path, len);
        
        solve(root->left, root->data, len);
        solve(root->right, root->data, len);
    }
    
    int longestConsecutive(Node* root) {
        // code here
        solve(root, -1, 0);
        return (max_path == 1) ? -1 : max_path;
    }
};