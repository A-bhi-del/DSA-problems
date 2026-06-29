class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string, int>mp;
        int n = word.length();
        int count = 0;
        unordered_set<string>mil_gyi;

        for(string str : patterns){
            mp[str]++;
        }

        for(int i = 0; i < n; i++){
            string str = "";
            for(int j = i; j < n; j++){
                str += word[j];

                if(mp.count(str) && !mil_gyi.count(str)){
                    count += mp[str];
                    mil_gyi.insert(str);
                }
            }
        }
        return count;
    }
};