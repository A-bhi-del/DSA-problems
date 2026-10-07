/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
public:
    int max_path_sum = INT_MIN;
    
    int solve(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(root->left && root->right){
            max_path_sum = max(max_path_sum, left + root->data + right);
        }
        
        // int temp = INT_MIN;
        
        if(!root->right){
            return root->data + left;
        }else if(!root->left){
            return root->data + right;
        }
        
        return max(root->data + left, root->data + right);
    }
    
    int maxPathSum(Node *root) {
        // code here
        // if(!root->left || !root->right){
        //     return -1;
        // }
        
        int ans = solve(root);
        
        return max_path_sum == INT_MIN ? -1 : max_path_sum;
    }
};