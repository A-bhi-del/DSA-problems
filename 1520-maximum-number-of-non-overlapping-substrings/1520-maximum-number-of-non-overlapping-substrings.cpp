class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int,int>>mp(26, {-1,-1});
        vector<int>freq(26, 0);

        int n = s.length();

        for(int i = 0; i < n; i++){
            if(mp[s[i] - 'a'].first == -1){
                mp[s[i] - 'a'].first = i;
            }
            mp[s[i] - 'a'].second = i;
            freq[s[i] - 'a']++;
        }

        vector<pair<int,int>>inter;
        
        for(auto& it : mp){
            int ss = it.first;
            if(ss == -1) continue;

            for(auto& it2 : mp){
                int e = it2.second;
                if(e < ss || e == -1) continue;
                vector<bool>seen(26, false);

                int sum = 0;

                for(int i = ss; i <= e; i++){
                    if(!seen[s[i] - 'a']){
                        sum += freq[s[i] - 'a'];
                        seen[s[i] - 'a'] = true;
                    }
                }

                if(sum == e - ss + 1){
                    inter.push_back({ss, e});
                }
            }
        }

        sort(inter.begin(), inter.end(), [](pair<int, int>& a, pair<int,int>& b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        vector<pair<int,int>>refine_inter;
        refine_inter.push_back({inter[0].first, inter[0].second});

        for(int i = 1; i < inter.size(); i++){
            int l = inter[i].first;
            int r = inter[i].second;

            if(refine_inter.back().second >= l){
                refine_inter.pop_back();
            }
            refine_inter.push_back({l, r});
        }

        vector<string>ans;

        for(auto in : refine_inter){
            int i = in.first;
            int j = in.second;

            string str = "";

            for(int k = i; k <= j; k++){
                str += s[k];
            }

            ans.push_back(str);
        }

        return ans;
    }
};
