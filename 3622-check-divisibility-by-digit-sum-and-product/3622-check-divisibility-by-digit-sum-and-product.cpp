class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int dup_n = n;

        while(n > 0){
            int num = n % 10;
            sum += num;
            prod *= num;
            n = n / 10;
        }

        return dup_n % (sum + prod) == 0;
    }
};