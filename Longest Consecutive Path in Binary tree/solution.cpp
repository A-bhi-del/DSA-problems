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
    int solve(Node* root, int prev, int len){
        if(root == NULL){
            return 0;
        }
        
        if(prev == -1 || root->data == prev+1){
            len++;
        }else if(root->data != prev+1){
            len = 1;
        }
        
        int left = solve(root->left, root->data, len);
        int right = solve(root->right, root->data, len);
        
        return max({len, left, right});
    }
    
    int longestConsecutive(Node* root) {
        // code here
        return solve(root, -1, 0) == 1 ? -1 : solve(root, -1, 0);
    }
};