class Solution {
public:
    long long LCM(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    void solve(long long idx, vector<int>& coins, long long turn, long long LCM_value, long long& count, long long& tar){
        if (idx >= coins.size()) {
            if (turn > 0) {
                long long val = tar / LCM_value;

                if (turn % 2 == 1){
                    count += val;
                }
                else {
                    count -= val;
                }
            }
            return;
        }

        long long newLCM = LCM(LCM_value, coins[idx]);

        if(newLCM <= tar){
            solve(idx + 1, coins, turn+1, newLCM, count, tar);
        }
        solve(idx + 1, coins, turn, LCM_value, count, tar);
    }
    
    bool check(vector<int>& coins, long long tar, long long k){
        long long count = 0;

        solve(0, coins, 0, 1, count, tar);

        if(count >= k){
            return true;
        }

        return false;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        vector<int>coins = {a, b, c};
        sort(coins.begin(), coins.end());
        long long maxi = coins[coins.size()-1];

        long long l = 1;
        long long h = 1LL * maxi * n;
        long long ans = h;

        while(l <= h){
            long long mid = l + (h - l)/2;

            if(check(coins, mid, n)){
                // cout<<"mid : "<<mid<<endl;
                ans = mid;
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return (int)ans;
    }
};

// 3 6 9, tar = 9
// 3 + 1 + 1
// 
