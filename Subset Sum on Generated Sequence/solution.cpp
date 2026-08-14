class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        int n = arr.size();

        vector<long long>prefix(n+1, 0);
        prefix[0] = s;
        long long cum = s;
        int last_idx = n;
        
        for(int i = 1; i <= n; i++){
            prefix[i] = cum + arr[i-1];
            cum += prefix[i];
            
            if(prefix[i] > x){
                last_idx = i-1;
                break;
            }
        }
        
        long long tar = x;
        
        for(int i = last_idx; i >= 0; i--){
            if(prefix[i] <= tar){
                tar -= prefix[i];
            }
        }
        
        return (tar == 0);
    }
};

// for(int val : prefix){
//     cout<<val<<" ";
// }

// cout<<endl;
// a b c d e
// s + , s + s + , s + s + s + s +, 
// 1 , 1 + 1 + 1, 1 + 1 + 1 + 1 + 1 + 1 + 2

// s, s + a, (s + s + a + b), (s + s + s + s + a + a + b + c)




