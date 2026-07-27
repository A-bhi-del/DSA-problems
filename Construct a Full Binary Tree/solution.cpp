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
    unordered_map<int,int>mp;
    Node* solve(vector<int>& pre, vector<int>& preMirror, int s, int e, int& preidx){
        if(preidx >= pre.size() || s > e){
            return NULL;
        }
        
        Node* root = new Node(pre[preidx++]);
        
        int split = mp[pre[preidx]];
        
        if(s == e){
            return root;
        }
        
        if(split >= s && split <= e){
            root->left = solve(pre, preMirror, split,e, preidx);
            root->right = solve(pre, preMirror, s+1, split, preidx);
        }
        
        return root;
    }
    
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        // code here
        int n = pre.size();
        
        for(int i = 0; i < n; i++){
            mp[preMirror[i]] = i;
        }
        
        int preidx = 0;
        
        return solve(pre, preMirror,0, n-1, preidx);
    }
};