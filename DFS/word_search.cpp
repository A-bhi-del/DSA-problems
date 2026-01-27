// You are given a matrix mat[][] of size n*m containing english alphabets
// and a string word. Check if the word exists on the mat[][] or not.
// The word can be constructed by using letters from adjacent cells, 
// either horizontally or vertically. The same cell cannot be used more than once.

class Solution {
  public:
    vector<int>op_r = {1,0,-1,0};
    vector<int>op_c = {0,1,0,-1};
    
    bool DFS(int i, int j, int idx, string& word, vector<vector<char>>& mat, vector<vector<int>>& vis){
        int n = mat.size();
        int m = mat[0].size();
        
        // if idx becomes the size than it is confirm that string is matched
        if(idx == word.size()){
            return true;
        }
        
        // if i is beyond the boundries than return false because we do not find the string
        if(i >= n || i < 0 || j >= m || j < 0){
            return false;
        }
        
        // is a char in mat is visited than we visited it before or char in mat is not equal to char in word 
        if(vis[i][j] == 1 || mat[i][j] != word[idx]){
            return false;
        }
        
        // mark it is as visited
        vis[i][j] = 1;
        
        // than we traverse aroud that char in matrix
        for(int k = 0; k < 4; k++){
            if(DFS(i + op_r[k], j + op_c[k], idx+1, word, mat, vis)){
                return true;
            }
        }
        
        // backtrack and make it not visited again
        vis[i][j] = 0;
        
        // otherwise return false;
        return false;
        
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(DFS(i,j,0, word, mat,vis)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

// we can not do this question using BFS because we have to go to deep first and BFS traverse many paths in one time