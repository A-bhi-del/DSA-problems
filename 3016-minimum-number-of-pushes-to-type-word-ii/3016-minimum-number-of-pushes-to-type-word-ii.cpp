class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26, 0);

        for(char ch : word){
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end());

        int n = 0;
        int l = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 25; i >= 0; i--){
            if(freq[i] != 0){
                sum += freq[i];
                n++;
                if(n == 8){
                    ans += (sum * l);
                    sum = 0;
                    n = 0;
                    l++;
                }
            }else if(freq[i] == 0){
                break;
            }
        }

        ans += (sum * l);

        return ans;
    }
};

// a -> 2
// b -> 2
// c -> 2
// d -> 2
// e -> 2
// f -> 2
// g -> 2
// h -> 2
// i -> 6