class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1e3){
            return 0;
        }

        if(n < 1e6){
            return 1*(n - 1e3 + 1);
        }

        if(n < 1e9){
            return 1e6 - 1e3 + 2*(n - 1e6 + 1);
        }

        if(n < 1e12){
            return 1e6 - 1e3 + 2*(1e9 - 1e6) + 3*(n - 1e9 + 1);
        }

        if(n < 1e15){
            return 1e6 - 1e3 + 2*(1e9 - 1e6) + 3*(1e12 - 1e9) + 4*(n - 1e12 + 1);
        }

        return 1e6 - 1e3 + 2*(1e9 - 1e6) + 3*(1e12 - 1e9) + 4*(1e15 - 1e12) + 5;
    }
};