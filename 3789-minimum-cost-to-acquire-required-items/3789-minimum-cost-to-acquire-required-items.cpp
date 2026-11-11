class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;

        if(need1 > need2){
            ans = min(cost1 * 1LL * (need1 - need2), costBoth * 1LL * (need1 - need2));
        }else if(need1 < need2){
            ans = min(cost2 * 1LL * (need2 - need1), costBoth * 1LL * (need2 - need1));
        }

        long long f = 1LL * (cost1 + cost2) * min(need1, need2);

        long long s = 1LL * costBoth * min(need1, need2);

        ans += min(f, s);

        return ans;
    }
};