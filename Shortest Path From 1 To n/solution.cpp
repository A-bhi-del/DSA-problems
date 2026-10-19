class Solution {
public:
    int minimumStep(int n) {
        // code here
        int len = 0;
        
        while(n > 1){
            if(n % 3 != 0){
                n = n-1;
            }else{
                n = n / 3;
            }
            len++;
        }
        
        return len;
    }
};