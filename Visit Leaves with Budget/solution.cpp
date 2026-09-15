/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        // code here
        if(!root){
            return 0;
        }
        
        queue<Node*>q;
        q.push(root);
        int level = 1;
        int ans = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                Node* temp = q.front();
                
                q.pop();
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
                if(!temp->right && !temp->left){
                    if(level <= k){
                        k -= level;
                        ans++;
                    }
                }
            }
            
            level++;
        }
        
        return ans;
    }
};