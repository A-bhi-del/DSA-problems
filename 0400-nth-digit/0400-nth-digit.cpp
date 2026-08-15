class Solution {
public:
    int findNthDigit(int n) {
        long long rem = 0;
        long long res = 0;
        long long count = 0;
        long long num = 0;
        long long end = 1;
        long long add = 9;
        bool flip = true;
        if(n <= 9){
            return n;
        }
        
        while(count <= n){
             for(long long i = 0; i < end; i++){       
                 count += add;
                 if(count < n){
                     rem = count;
                     num++;
                     flip = !flip;
                 } else {
                     break;                              
                 }
             }
            if(count <= n){
                res = add;
            }
            if(add == 9) add += 1;
            add = add + 10;
            if(end == 1) end = 9;                       
            else end = 10 * end;
        }
        
        string str = to_string(num);
        long long len = str.length() + 1;

        long long m = (n - rem - 1) / len;               
        long long ch = (n - rem - 1) % len;               

        long long val;
        val = m;                                      
        str += (char)(val + '0');
        return str[ch] - '0';
    }
};