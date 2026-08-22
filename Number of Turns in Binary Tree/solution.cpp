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
}; */

class Solution {
  public:
    Node* solve(Node* root, int p, int q){
        if(root == NULL || root->data == p || root->data == q){
            return root;
        }
        
        Node* left = solve(root->left, p, q);
        Node* right = solve(root->right, p, q);
        
        if(left != NULL && right != NULL){
            return root;
        }
        
        if(left != NULL){
            return left;
        }
        
        return right;
    }
    
    int calcu(Node* root, int tar, int side){
        if(root == NULL){
            return -1;
        }

        if(root->data == tar){
            return 0;
        }

        int left = calcu(root->left, tar, 0);
        int right = calcu(root->right, tar, 1);

        if(left != -1){
            return left + (side == 1 ? 1 : 0);
        }
        if(right != -1){
            return right + (side == 0 ? 1 : 0);
        }
        return -1;
    }

    int numberOfTurns(Node* root, int p, int q) {
        Node* anc_node = solve(root, p, q);

        int left_side = calcu(anc_node, p, -1);
        int right_side = calcu(anc_node, q, -1);

        if(anc_node->data == p || anc_node->data == q){
            return left_side + right_side == 0 ? -1 : left_side + right_side;
        }

        return left_side + right_side + 1;
    }
};