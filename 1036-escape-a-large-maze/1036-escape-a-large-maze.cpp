class Solution {
public:
    vector<int>op_r = {0,0,-1,1};
    vector<int>op_c = {1,-1,0,0};

    bool bfs(unordered_set<long long>& mat, vector<int>& source, vector<int>& target){
        unordered_set<long long> vis;
        queue<vector<int>> q;

        vis.insert(source[0] * 1000000LL + source[1]);
        q.push({source[0], source[1]});

        while(!q.empty()){
            auto node = q.front();
            q.pop();                         
            int u = node[0];
            int v = node[1];

            if(u == target[0] && v == target[1]){
                return true;
            }

            if(vis.size() > 20000){ 
                return true;
            }    

            for(int k = 0; k < 4; k++){
                int ni = u + op_r[k];
                int nj = v + op_c[k];

                if(ni < 0 || ni >= 1000000 || nj < 0 || nj >= 1000000) continue;   

                long long key = ni * 1000000LL + nj;
                if(mat.count(key) || vis.count(key)) continue;

                q.push({ni, nj});
                vis.insert(key);
            }
        }

        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> mat;   

        for(auto block : blocked){
            mat.insert(block[0] * 1000000LL + block[1]);
        }

        return bfs(mat, source, target) && bfs(mat, target, source);   
    }
};