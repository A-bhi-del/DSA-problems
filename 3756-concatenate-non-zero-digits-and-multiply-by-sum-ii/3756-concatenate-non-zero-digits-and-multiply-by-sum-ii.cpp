class Solution {
public:
    int mod = 1e9+7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<long long>prefix_sum(n+1, 0);
        vector<long long>prefix_num(n+1, 0);
        vector<long long>powers(n+1, 1);
        vector<long long>digit_count(n+1, 0);

        for(int i = 1; i <= n; i++){
            powers[i] = (powers[i-1] * 10) % mod;
        }

        for(int i = 0; i < n; i++){
            prefix_sum[i+1] = (prefix_sum[i] + (s[i] - '0')) % mod;
        }

        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                prefix_num[i+1] = prefix_num[i];
                digit_count[i+1] = digit_count[i];
            }else{
                prefix_num[i+1] = (prefix_num[i] * 10 + (s[i] - '0')) % mod;
                digit_count[i+1] = digit_count[i] + 1;
            }
        }

        vector<int>ans;

        for(auto query : queries){
            int l = query[0];
            int r = query[1];
            long long len_l = digit_count[l];
            long long len_r = digit_count[r+1]; 
            long long zeros = len_r - len_l;

            long long num = (prefix_num[r+1] - (prefix_num[l] * powers[zeros]) % mod + mod) % mod;

            long long digit_sum = (prefix_sum[r+1] - prefix_sum[l] + mod) % mod;
            long long res = (num * digit_sum) % mod;

            int final = (int)res;
            ans.push_back(final);
        }

        return ans;
    }
};