// There is a country of n cities numbered from 0 to n - 1 where all the 
// cities are connected by bi-directional roads. The roads are represented
//  as a 2D integer array edges where edges[i] = [xi, yi, timei] denotes a
//  road between cities xi and yi that takes timei minutes to travel. 
// There may be multiple roads of differing travel times connecting the
//  same two cities, but no road connects a city to itself.
// Each time you pass through a city, you must pay a passing fee. This is
//  represented as a 0-indexed integer array passingFees of length n where
//  passingFees[j] is the amount of dollars you must pay when you pass 
// through city j.
// In the beginning, you are at city 0 and want to reach city n - 1 in 
// maxTime minutes or less. The cost of your journey is the summation of 
// passing fees for each city that you passed through at some moment of 
// your journey (including the source and destination cities).
// Given maxTime, edges, and passingFees, return the minimum cost to 
// complete your journey, or -1 if you cannot complete it within maxTime 
// minutes.
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        unordered_map<int, vector<pair<int,int>>> mp;

        for(auto edge : edges){
            int x = edge[0];
            int y = edge[1];
            int time = edge[2];

            mp[x].push_back({y,time});
            mp[y].push_back({x,time});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

        vector<vector<int>> fee(n, vector<int>(maxTime + 1, INT_MAX));

        fee[0][0] = passingFees[0];
        pq.push({passingFees[0],{0,0}});

        while(!pq.empty()){
            auto node = pq.top();
            int f = node.first;
            int val = node.second.second;
            int dist = node.second.first;
            pq.pop();

            if(val == n-1){
                return f;
            }

            for(auto it : mp[val]){
                int n_val = it.first;
                int n_dist = it.second;
                int n_fee = passingFees[n_val];

                if(dist + n_dist > maxTime) {
                    continue;
                }

                if(f + n_fee < fee[n_val][n_dist + dist]){
                    fee[n_val][n_dist + dist] = f + n_fee;
                    pq.push({f + n_fee, {dist + n_dist, n_val}});
                }
            }
        }

        return -1;
    }
};