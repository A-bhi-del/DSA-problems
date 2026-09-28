class Solution {
public:
    int n1;
    int n2;
    int mod = 1e9+7;
    int dp[2001][2002][3];

    long long solve(int idx, int prev, vector<int>& arr1, vector<int>& arr2, int turn){
        if(idx >= n1){
            return 0;
        }

        if(dp[idx][prev+1][turn] != -1){
            return dp[idx][prev+1][turn];
        }

        int x = -1;

        if(prev == -1){
            if(arr2[0] < arr1[idx]){
                x = 0;
            }
        }else{
            int val = 0;
            if(turn == 1){
                val = arr1[prev];
            }else{
                val = arr2[prev];
            }
            
            int l = 0;
            int h = arr2.size()-1;

            while(l <= h){
                int mid = l + (h - l)/2;

                if(arr2[mid] > val){
                    x = mid;
                    h = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        }

        long long take = INT_MAX;
        long long not_take = INT_MAX;

        if(prev == -1){
            if(x != -1){
                take = min(take, (1 + solve(idx + 1, x, arr1, arr2, 2)) % mod);
            }

            not_take = solve(idx + 1, idx, arr1, arr2, 1);
        }else{
            if(x != -1){
                take = min(take, (1 + solve(idx + 1, x, arr1, arr2, 2)) % mod);
            }
            if(turn == 2 && arr1[idx] > arr2[prev]){
                not_take = solve(idx + 1, idx, arr1, arr2, 1);
            }else if(turn == 1 && arr1[idx] > arr1[prev]){
                not_take = solve(idx + 1, idx, arr1, arr2, 1);
            }
        }

        return dp[idx][prev+1][turn] = min(take, not_take);
    } 

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        memset(dp, -1, sizeof(dp));
        n1 = arr1.size();
        n2 = arr2.size();

        sort(arr2.begin(), arr2.end());
        int ans = solve(0, -1, arr1, arr2, 0);

        return ans >= 147483634 ? -1 : ans;
    }
};