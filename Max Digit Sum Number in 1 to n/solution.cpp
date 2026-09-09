class Solution {
  public:
    int findMax(int n) {
        // code Here
        
        string num = "";
        int temp = n;
        
        while(temp > 0){
            int digit = temp % 10;
            num += digit + '0';
            temp = temp / 10;
        }
        
        reverse(num.begin(), num.end());
        
        vector<int>add(num.length(), 0);
        add[0] = num[0] - '0';
        for(int i = 1; i < num.length(); i++){
            add[i] = (num[i] - '0') + add[i-1];
        }
        
        int maxi = add[num.length()-1];
        string ans = num;
        // cout<<maxi<<endl;
        
        
        for(int i = num.length() - 2; i >= 0; i--){
            if(num[i] - '0' > 0){
                int val = add[i] - 1 + (9 * (num.length() - 1 - i));
            // cout<<ans<<" "<<val<<endl;
                if(maxi <= val){
                    string str = "";
                    for(int j = 0; j < i; j++){
                        str += num[j];
                    }
                    
                    str += ((num[i] - '0') - 1) + '0';
                    
                    for(int j = i + 1; j < num.length(); j++){
                        str += '9';
                    }
                    

                    if(ans < str && maxi == val){
                        ans = str;
                    }else if(maxi < val){
                        ans = str;
                    }
                    maxi = val;
                }
            }
        }
        
        int target = 0;
        
        for(int i = 0; i < num.length(); i++){
            target = target * 10 + (ans[i] - '0');
        }
        
        return target;
    }
};

// 4889
// 4