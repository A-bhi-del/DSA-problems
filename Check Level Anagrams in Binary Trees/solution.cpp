/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // code here
        unordered_map<int, int>mp1;
        unordered_map<int,int>mp2;
        queue<Node*>q1;
        queue<Node*>q2;
        
        if(root1->data != root2->data){
            return false;
        }
        
        q1.push(root1);
        q2.push(root2);
        
        while(!q1.empty() || !q2.empty()){
            int s1 = q1.size();
            int s2 = q2.size();
            
            for(int i = 0; i < s1; i++){
                Node* temp = q1.front();
                q1.pop();
                
                mp1[temp->data]++;
                
                if(temp->left){
                    q1.push(temp->left);
                }
                if(temp->right){
                    q1.push(temp->right);
                }
            }
            
            for(int i = 0; i < s2; i++){
                Node* temp = q2.front();
                q2.pop();
                
                mp2[temp->data]++;
                
                if(temp->left){
                    q2.push(temp->left);
                }
                if(temp->right){
                    q2.push(temp->right);
                }
            }
            
            if(mp1.size() != mp2.size()){
                return false;
            }
            
            for(auto it : mp1){
                if(!mp2.count(it.first)){
                    return false;
                }else if(it.second != mp2[it.first]){
                    return false;
                }
            }
        }
        
        return true;
    }
};
