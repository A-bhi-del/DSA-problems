class Solution {
  public:
    int lcmOfArray(vector<int>& a) {
        // code here
        int n = a.size();
        
        vector<int>PF(21, 0);
        
        for(int i = 0; i <= 20; i++){
            PF[i] = i;
        }
        
        for(int i = 2; i <= 20; i++){
            if(PF[i] == i){
                for(int j = i * i; j <= 20; j+=i){
                    if(PF[j] == j){
                        PF[j] = i;
                    }
                }
            }
        }
        
        unordered_map<int,int>maxi;
        
        for(int i = 0; i < n; i++){
            unordered_map<int,int>freq;
            int num = a[i];
            
            while(num > 1){
                int prime = PF[num];
                int count = 0;
                
                while(num % prime == 0){
                    num /= prime;
                    count++;
                }
                
                freq[prime] = count;
            }
            
            for(auto it : freq){
                maxi[it.first] = max(maxi[it.first], it.second);
            }
        }
        
        long long res = 1;
        
        for(auto it : maxi){
            res = res * pow(it.first, it.second);
        }
        
        return res;
    }
};