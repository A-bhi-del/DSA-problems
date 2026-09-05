class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> dup;
        unordered_map<string, int> mp;
        vector<int> ans;

        int size = words[0].size(), complete = 0;
        int len = words.size();

        for(string word : words){
            mp[word]++;
            dup[word]++;
        }

        for (int i = 0; i < size; i++) {
            mp = dup;
            int l = i;
            int r = i;
            int complete = 0;

            while (r <= s.size()) {
                string word = s.substr(r, size);

                if(mp.count(word)){
                    mp[word]--;
                    complete++;

                    while(mp[word] < 0){
                        string temp = s.substr(l, size);
                        if(mp.count(temp)){
                            mp[temp]++;
                            complete--;
                        }
                        l += size;
                    }

                    if(complete == len){
                        ans.push_back(l);
                    }
                }else{
                    mp = dup;
                    complete = 0;
                    l = r + size;
                }
                r += size;
            }
        }

        return ans;
    }
};