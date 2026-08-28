class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int nt = target.length();
        int ns = s.length();

        vector<int>freq(26, 0);
        for(char ch : s){
            freq[ch - 'a']++;
        }

        int odd = 1;
        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 == 1 && odd == 1){
                odd--;
                continue;
            }else if(freq[i] % 2 == 1 && odd == 0){
                return "";
            }
        }

        char oddd = '#';

        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 == 1){
                oddd = i + 'a';
                freq[i]--;
            }

            if(freq[i] % 2 == 0){
                freq[i] = freq[i]/2;
            }
        }

        string left_part = "";

        for(int i = 0; i < 26; i++){
            int count = freq[i];
            while(count > 0){
                left_part += i + 'a';
                count--;
            }
        }

        string left = left_part;
        reverse(left_part.begin(), left_part.end());
        string right = left_part;

        string ans = "";

        if(oddd != '#'){
            ans = left + oddd + right;
        }else{
            ans = left + right;
        }

        if(ans > target){
            return ans;
        }

        string str = "";

        for(int i = 0; i < nt; i++){
            if(freq[target[i] - 'a'] > 0){
                str += target[i];
                freq[target[i] - 'a']--;
            }else{
                break;
            }
        }
        
        string rem = "";
        for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                rem += i + 'a';
                freq[i]--;
            }
        }

        string l = str + rem;
        string dup = str + rem;
        reverse(dup.begin(), dup.end());
        string r = dup;
        string a = "";

        if(oddd != '#'){
            a = l + oddd + r;
        }else{
            a = l + r;
        }

        if(a > target){
            return a;
        }

        vector<int>temp(26, 0);

        for(int i = 0; i < rem.length(); i++){
            temp[rem[i] - 'a']++;
        }

        int len = str.length();

        for(int i = len; i >= 0; i--){
            char ch = target[i];
            if(str.length() >= 0 && i < str.length()){
                temp[str[i] - 'a']++;
                str.pop_back();
            }

            for(char c = ch + 1; c <= 'z'; c++){
                if(temp[c - 'a'] > 0){
                    str += c;
                    temp[c-'a']--;

                    for(int i = 0; i < 26; i++){
                        while(temp[i] > 0){
                            str += i + 'a';
                            temp[i]--;
                        }
                    }

                    string le = str;
                    reverse(str.begin(), str.end());
                    string re = str;

                    string res = "";

                    if(oddd != '#'){
                        res = le + oddd + re;
                    }else{
                        res = le + re;
                    }

                    return res;
                }
            }
        }

        return "";
    }
};