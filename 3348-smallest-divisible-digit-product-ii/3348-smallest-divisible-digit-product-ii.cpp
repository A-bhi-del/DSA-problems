class Solution {
public:
    string fill_free_slots(long long req, long long slots){
        string ans = "";

        for(long long digit = 9; digit > 1; digit--){
            while(req % digit == 0){
                ans += digit + '0';
                req = req / digit;
            }
        }

        while(ans.length() < slots){
            ans += '1';
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string smallestNumber(string num, long long t) {
        long long n = num.length();
        long long target = t;

        for(int val : {2, 3, 5, 7}){
            while(target % val == 0){
                target = target/val;
            }
        }

        if(target != 1){
            return "-1";
        }

        vector<long long>required(n+1, t);
        int idx = n-1;

        for(int i = 0; i < n; i++){
            long long curr_digit = num[i] - '0';

            if(curr_digit == 0){
                idx = i;
                break;
            }

            required[i+1] = required[i]/gcd(required[i], curr_digit);
        }

        if(required[n] == 1) return num;

        for(long long i = idx; i >= 0; i--){
            long long req = required[i];
            long long val = num[i] - '0';
            long long free_slots = n - i - 1;

            for(long long digit = val + 1; digit <= 9; digit++){
                long long new_req = req/gcd(req, digit);

                string res = fill_free_slots(new_req, free_slots);

                if(res.length() == free_slots){
                    return num.substr(0, i) + char(digit + '0') + res;
                }
            }
        }

        return fill_free_slots(t, n+1);
    }
};
