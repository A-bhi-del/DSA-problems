class Solution {
  public:
    // struct TrieNode{
    //     bool isEndOf = false;
    //     TrieNode* child[26];
    // };
    
    // struct TrieNode* getNode(){
    //     TrieNode* newNode = new TrieNode();
    //     for(int i = 0; i < 26; i++){
    //         newNode->child[i] = NULL;
    //     }
        
    //     newNode->isEndOf = false;
        
    //     return newNode;
    // }
    
    // TrieNode* root = getNode();
    
    // void insert(string& word){
    //     int n = word.length();
        
    //     TrieNode* crowler = root;
        
    //     for(int i = 0; i < n; i++){
            
    //         int idx = word[i] - 'a';
            
    //         if(crowler->child[idx] == NULL){
    //             crowler->child[idx] = getNode();
    //         }
            
    //         crowler = crowler->child[idx];
    //     }
        
    //     crowler->isEndOf = true;
    // }
    
    
    
    
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        unordered_map<string, int>mp;
        
        for(string str : arr){
            string res = "";
            
            for(char ch : str){
                res += ch;
                mp[res]++;
            }
        }
        
        vector<string>ans;
        
        for(string str : arr){
            string res = "";
            
            for(char ch : str){
                res += ch;
                if(mp[res] == 1 || res == str){
                    ans.push_back(res);
                    break;
                }
            }
        }
        
        return ans;
    }
};