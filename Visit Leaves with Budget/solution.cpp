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
        vector<int>leafs_cost;
        int level = 1;
        
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
                    leafs_cost.push_back(level);
                }
            }
            
            level++;
        }
        
        int ans = 0;
        
        for(int i = 0; i < leafs_cost.size(); i++){
            if(leafs_cost[i] <= k){
                ans++;
                k = k - leafs_cost[i];
            }else{
                break;
            }
        }
        
        return ans;
    }
};