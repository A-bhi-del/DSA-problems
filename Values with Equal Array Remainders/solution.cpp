class Solution {
  public:
    int sameMod(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int gre = 0;
        
        for(int i = 1; i < n; i++){
            gre = __gcd(gre, abs(arr[i] - arr[0]));
        }
        
        if(gre == 0){
            return -1;
        }
        
        int count = 0;
        
        for(int i = 1; i * i <= gre; i++){
            if(gre % i == 0){
                count++;
                if(i != gre/i){
                    count++;
                }
            }
        }
        
        return count;
    }
};