class Solution {
  public:
    int maxValue(int n) {
        // code here
        string binary = "";
        
        while(n > 0){
            int bit = n % 2;
            binary += bit + '0';
            n /= 2;
        }
        
        reverse(binary.begin(), binary.end());
        // cout<<binary<<endl;
        
        int cnt = 0;
        
        for(int i = 0; i < binary.length(); i++){
            while(cnt < 3 && binary[i] == '1'){
                // cout<<i<<endl;
                cnt++;
                i++;
            }
            
            if(cnt == 3){
                // cout<<i<<endl;
                binary[i-1] = '0';
                i = i - 1;
            }
            cnt = 0;
        }
        
        int res = 0;
        int power = 1;
        
        for(int i = binary.length()-1; i >= 0; i--){
            res += power * (binary[i] - '0');
            power *= 2;
        }
        
        return res;
    }
};

// 