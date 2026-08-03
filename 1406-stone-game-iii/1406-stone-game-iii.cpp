class Solution {
public:
    vector<int>prefix;
    unordered_map<int,int>mp;
    int solve(int idx, vector<int>& stoneValue, int size){
        if(idx >= size){
            return 0;
        }

        if(mp.count(idx)){
            return mp[idx];
        }

        int take = -1e7-1;

        for(int i = idx; i < idx+3; i++){
            if(i < size){
                int val = prefix[i];
                if(idx > 0){
                    val -= prefix[idx-1];
                }
                take = max(take, val - solve(i+1, stoneValue, size));
            }
        }

        return mp[idx] = take;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.resize(n, 0);

        for(int i = 0; i < n; i++){
            prefix[i] = stoneValue[i];
        }

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i] + prefix[i-1];
        }

        int ans = solve(0, stoneValue, n);
        
        if(ans < 0){
            return "Bob";
        }else if(ans > 0){
            return "Alice";
        }
        return "Tie";
    }
};