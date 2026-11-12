/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int min_dis = INT_MAX;
    
    void solve(Node* root, int k){
        if(root == NULL){
            return ;
        }
        
        solve(root->left, k);
        solve(root->right, k);
        
        min_dis = min(min_dis, abs(root->data - k));
    }
    
    int minDiff(Node *root, int k) {
        // code here
        solve(root, k);
        return min_dis;
    }
};
