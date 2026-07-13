class Solution {
  public:
    long long mod = 1e9+7;
    
    long long power_with_mod(int x, int y) {
        long long res = 1;
    
        while (y) {
            if (y & 1){
                res = (res * x) % mod;
            }
    
            x = (1LL * x * x) % mod;
            y >>= 1;
        }
    
        return res;
    }
    
    int minOperations(vector<int> &b) {
        // code here
        int n = b.size();
        
        vector<int>cycle_len;
        
        vector<int>vis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int curr = i;
                int len = 0;
                
                while(!vis[curr]){
                    vis[curr] = 1;
                    
                    curr = b[curr]-1;
                    
                    len++;
                }
                cycle_len.push_back(len);
            }
        }
        
        unordered_map<int,int>maxi;
        
        vector<int>PF(n+1, 0);
        
        for(int i = 0; i <= n; i++){
            PF[i] = i;
        }
        
        for(int i = 2; i <= n; i++){
            if(PF[i] == i){
                for(int j = i*i; j <= n; j+=i){
                    if(PF[j] == j){
                        PF[j] = i;
                    }
                }
            }
        }
        
        for(int length : cycle_len){
            unordered_map<int,int>freq;
            
            
            while(length > 1){
                int prime = PF[length];
                int count = 0;
                
                while(length % prime == 0){
                    length /= prime;
                    count++;
                }
                
                freq[prime] = count;
            }
            
            for(auto it : freq){
                maxi[it.first] = max(maxi[it.first], it.second);
            }
        }
        
        long long ans = 1;
        
        for(auto it : maxi){
            ans = (ans * power_with_mod(it.first, it.second)) % mod;
        }
        
        
        return (int)ans;
    }
};

// 1 2 3 4 5
// 3 1 2 5 4
// 2 3 1 4 5
// 