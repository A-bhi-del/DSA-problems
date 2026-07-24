class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>prime_sieve(101, 1);
        
        prime_sieve[0] = 0;
        prime_sieve[1] = 0;

        for(int i = 2; i * i <= 101; i++){
            if(prime_sieve[i] == 1){
                for(int j = i * i; j < 101; j+=i){
                    prime_sieve[j] = 0;
                }
            }
        }

        int min_prime_idx = 30002;
        int max_prime_idx = -1;

        for(int i = 0; i < n; i++){
            if(prime_sieve[nums[i]] == 1){
                min_prime_idx = min(min_prime_idx, i);
                max_prime_idx = max(max_prime_idx, i);
            }
        }

        return max_prime_idx - min_prime_idx;
    }
};