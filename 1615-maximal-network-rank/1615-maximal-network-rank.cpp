class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj_LS(n);
        unordered_set<int>st;

        for(auto road : roads){
            int a = road[0];
            int b = road[1];

            adj_LS[a].push_back(b);
            adj_LS[b].push_back(a);
            st.insert(a*100+b);
            st.insert(b*100 + a);
        }

        int ans = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;

                if(st.count(i*100 + j)){
                    int rank = adj_LS[i].size() + adj_LS[j].size()-1;
                    ans = max(ans, rank);
                }else{
                    int rank = adj_LS[i].size() + adj_LS[j].size();
                    ans = max(ans, rank);
                }
            }
        }

        return ans;
    }
};

// 0 -> 1
// 1 -> 2, 0
// 2 -> 1, 3, 4
// 3 -> 2
// 5 -> 6, 7
// 7 -> 5
// 6 -> 5
// 4 -> 2