Given a string s of lowercase English letters, you can swap all occurrences of any two distinct characters at most once. Return the lexicographically smallest string after this operation.

TC - O(n + 26 + n)
SC - O(26)

class Solution {
  public:
    string chooseSwap(string &s) {
        // code here
        vector<int>freq(26,0);
        
        for(char ch : s){
            freq[ch - 'a']++;
        }
        
        char st = 'a';
        char ch1 = '#';
        char ch2 = '#';
        
        bool if_find = false;
        for(char ch : s){
            if(freq[ch - 'a'] == -1){
                continue;
            }
            while(ch != st){
                if(freq[st - 'a'] > 0){
                    ch1 = ch;
                    ch2 = st;
                    if_find = true;
                    break;
                }
                st = st + 1;
            }
            
            if(if_find){
                break;
            }
            
            freq[st - 'a'] = -1;
        }
        
       // cout<<ch1<<" "<<ch2<<endl;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ch1){
                s[i] = ch2;
            }else if(s[i] == ch2){
                s[i] = ch1;
            }
        }
        return s;
    }
};
