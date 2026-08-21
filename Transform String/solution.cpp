class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        vector<int>freq1(26, 0);
        vector<int>freq2(26, 0);
        vector<int>freq3(26, 0);
        vector<int>freq4(26, 0);
        
        for(int i = 0; i < s1.length(); i++){
            if('a' <= s1[i] &&  s1[i] <= 'z'){
                freq1[s1[i] - 'a']++;
            }else{
                freq3[s1[i] - 'A']++;
            }
        }
        
        for(int i = 0; i < s2.length(); i++){
            if('a' <= s2[i] && s2[i] <= 'z'){
                freq2[s2[i] - 'a']++;
            }else{
                freq4[s2[i] - 'A']++;
            }
        }
        
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i] || freq3[i] != freq4[i]){
                return -1;
            }
        }
        
        int i = s1.length()-1;
        int j = s2.length()-1;
        int ans = 0;
        
        while(i >= 0 && j >= 0){
            while(i >= 0 && s1[i] != s2[j]){
                i--;
                ans++;
            }
            i--;
            j--;
        }
        
        return ans;
    }
};
