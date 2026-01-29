// Minimum Cost to Convert String I

// You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].
// You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.
// Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.
// Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //floyed warshal approach

        int n = original.size();

        vector<vector<long long>>mat(26, vector<long long>(26, LLONG_MAX));

        for(int i = 0; i < n; i++){
            mat[original[i]-'a'][changed[i]-'a'] = min(mat[original[i]-'a'][changed[i]-'a'], (long long)cost[i]); // maine isko esliye use kyu kiya hai.. kyuki multiple cost ho skte hai.. 2 nodes ke beech me 
        }

        for(int i = 0; i < 26; i++){
            mat[i][i] = 0;
        }

        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                for(int k = 0; k < 26; k++){
                    if(j == k){
                        continue;
                    }

                    if(mat[j][i] != LLONG_MAX && mat[i][k] != LLONG_MAX && mat[j][i] + mat[i][k] < mat[j][k]){
                        mat[j][k] = mat[j][i] + mat[i][k];
                    }
                }
            }
        }

        long long ans = 0;

        for(int i = 0; i < source.size(); i++){
            if(source[i] != target[i]){
                if(mat[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX) return -1;
                ans += mat[source[i] - 'a'][target[i] - 'a'];
            }
        }

        return ans;
    }
};

       //This approach is using dijkstra algo but it gives TLE
        vector<vector<pair<int,int>>> mp(26);

        for(int i = 0; i < n; i++){
            mp[original[i]-'a'].push_back({changed[i]-'a', cost[i]});
        }

        long long ans = 0;
        int m = source.size();

        for(int i = 0; i < m; i++){
            if(source[i] == target[i]) continue;

            int sc = source[i]-'a';
            int dest = target[i]-'a';

            vector<int> dist(26, INT_MAX);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

            pq.push({0, sc});
            dist[sc] = 0;

            while(!pq.empty()){
                auto [c,u] = pq.top();
                pq.pop();

                if(u == dest) break;

                for(auto &[v,w] : mp[u]){
                    if(c + w < dist[v]){
                        dist[v] = c + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            if(dist[dest] == INT_MAX) return -1;

            ans += dist[dest];
        }

        return ans;