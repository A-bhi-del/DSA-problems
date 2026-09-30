class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string ans = "";

        int n = sentence.length();
        int i = 0;

        while(i < n){
            if(sentence[i] != '$'){
                ans += sentence[i];
                i++;
            }else if(i-1 >= 0 && sentence[i-1] != ' ' && sentence[i] == '$'){
                ans += '$';
                i++;
            }else{
                string res = "$";
                long long num = 0;
                
                int j = i+1;
                // cout<<j<<endl;

                if(j < n && sentence[j] != ' '){
                    bool is_check = false;
                    while(j < n && sentence[j] != ' '){
                        if(sentence[j] >= '0' && sentence[j] <= '9'){
                            if(!is_check){                                  
                                num = num * 10 + (sentence[j] - '0');
                            }
                        }else{
                            is_check = true;
                        }
                        res += sentence[j];
                        j++;
                    }

                    if(is_check){
                        ans += res;
                    }else{
                        long long cents = num * (100 - discount);   
                        long long dollars = cents / 100;
                        int rem = cents % 100;

                        string frac = to_string(rem);
                        if(rem < 10) frac = "0" + frac;   

                        ans += "$" + to_string(dollars) + "." + frac;
                    }
                }else{
                    ans += '$';
                }
                i = j;
            }
        }

        return ans;
    }
};