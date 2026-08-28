class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int>freq(26, 0);
        vector<int>freq1(26, 0);

        for(char ch : s){
            freq[ch - 'a']++;
            freq1[ch - 'a']++;
        }

        sort(freq.begin(), freq.end());

        // for(int i = 0; i < 26; i++){
        //     cout<<freq[i]<<" ";
        // }
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
            if(freq1[i] % 2 == 1){
                oddd = i + 'a';
                freq1[i]--;
            }

            if(freq1[i] % 2 == 0){
                freq1[i] = freq1[i]/2;
            }
        }

        string left_part = "";

        for(int i = 0; i < 26; i++){
            freq[i] = freq1[i];
        }

        // for(int i = 0; i < 26; i++){
        //     cout<<freq[i]<<" ";
        // }

        for(int i = 0; i < 26; i++){
            while(freq1[i] > 0){
                left_part += i + 'a';
                freq1[i]--;
            }
        }

        if(oddd != '#'){
            string left = left_part;
            reverse(left_part.begin(), left_part.end());
            string right = left_part;

            string ans = left + oddd + right;

            // cout<<left<<" "<<oddd<<" "<<right<<endl;

            if(ans > target){
                return ans;
            }

            string str = "";

            for(int i = 0; i < target.length(); i++){
                if(freq[target[i] - 'a'] > 0){
                    str += target[i];
                    freq[target[i] - 'a']--;
                }else{
                    break;
                }
            }

            // cout<<str<<endl;

            string rem = "";
            for(int i = 0; i < 26; i++){
                while(freq[i] > 0){
                    rem += i + 'a';
                    freq[i]--;
                }
            }

            // cout<<"rem :"<<" "<<rem<<endl;

            string l = str + rem;

            string dup = str + rem;

            reverse(dup.begin(), dup.end());

            string r = dup;

            string a = l + oddd + r;

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

                        string res = le + oddd + re;

                        return res;
                    }
                }

            }
        }else{
            string left = left_part;
            reverse(left_part.begin(), left_part.end());
            string right = left_part;

            // cout<<left<<" "<<right<<endl;

            string ans = left + right;

            if(ans > target){
                return ans;
            }

            string str = "";

            for(int i = 0; i < target.length(); i++){
                if(freq[target[i] - 'a'] > 0){
                    str += target[i];
                    freq[target[i] - 'a']--;
                }else{
                    break;
                }
            }
            
            // cout<<"str :"<<" "<<str<<endl;
            string rem = "";
            for(int i = 0; i < 26; i++){
                while(freq[i] > 0){
                    rem += i + 'a';
                    freq[i]--;
                }
            }

            // cout<<rem<<endl;

            string l = str + rem;

            string dup = str + rem;

            reverse(dup.begin(), dup.end());

            string r = dup;

            string a = l + r;

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

                // cout<<ch<<endl;

                for(char c = ch + 1; c <= 'z'; c++){
                    if(temp[c - 'a'] > 0){
                        str += c;
                        temp[c-'a']--;

                        // cout<<c<<endl;

                        for(int i = 0; i < 26; i++){
                            while(temp[i] > 0){
                                str += i + 'a';
                                temp[i]--;
                            }
                        }

                        string le = str;
                        reverse(str.begin(), str.end());
                        string re = str;

                        // cout<<le<<" "<<re<<endl;

                        string res = le + re;

                        return res;
                    }
                }

            }
        }

        return "";
    }
};