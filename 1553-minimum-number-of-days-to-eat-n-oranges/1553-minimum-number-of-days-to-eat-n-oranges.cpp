class Solution {
public:
    unordered_map<int, long long>mp;

    long long solve(int n){
        if(n <= 0){
            return n;
        }

        if(mp.count(n)){
            return mp[n];
        }

        long long f = INT_MAX;
        long long s = INT_MAX;

        long long cntf = 0;
        long long cnts = 0;
        
        int n1 = n;
        int n2 = n;
        while(n1 % 2 != 0){
            n1--;
            cntf++;
        }

        while(n2 % 3 != 0){
            n2--;
            cnts++;
        }

        f = cntf + solve(n1/2);
        s = cnts + solve(n2/3);

        return mp[n] = 1 + min({f, s});
    }
    
    int minDays(int n) {
        return solve(n) - 1;
    }
};

