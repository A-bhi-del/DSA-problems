class Solution {
public:
    int solve(unordered_map<string, int>& mp, int same) {
        long long total = same;
        long long mx = same;
        for (auto& it : mp) {
            total += it.second;
            mx = max(mx, (long long)it.second);
        }
        if (total == 0)
            return 0;
        return (int)min(total / 2, total - mx);
    }
    int score(vector<string>& cards, char x) {
        unordered_map<string, int> mp_1;
        unordered_map<string, int> mp_2;
        int g1 = 0;
        int g2 = 0;
        int same = 0;
        int ans = INT_MIN;

        for (auto card : cards) {
            if (card[0] == card[1] && card[0] == x) {
                same++;
            } else if (card[0] == x) {
                mp_1[card]++;
                g1++;
            } else if (card[1] == x) {
                mp_2[card]++;
                g2++;
            }
        }

        for (auto it : mp_2) {
            cout << it.second << endl;
        }

        // cout<<g1<<" "<<g2<<" "<<same<<endl;

        for (int i = 0; i <= same; i++) {
            // if(i == 4){
            //     cout<<solve(mp_1, i);
            //     cout<<endl;
            //     cout<<solve(mp_2, same-i);
            // }
            int res = solve(mp_1, i) + solve(mp_2, same - i);
            ans = max(ans, res);
        }

        return ans;
    }
};