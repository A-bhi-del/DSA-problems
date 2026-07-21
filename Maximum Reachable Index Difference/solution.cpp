class Solution {
  public:
    int maxIndexDifference(string &s) {
        // code here
        int n = s.length();
        
        vector<bool>dp(26, false);
        
        int is_a = -1;
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                is_a = i;
                break;
            }
        }
        
        if(is_a == -1) return -1;
        
        dp[0] = true;
        int st = is_a;
        int e = is_a;
        
        int i = is_a;
        
        while(i < n){
            if(s[i] == 'a'){
                i++;
                continue;
            }
            if(dp[s[i] - 'a' - 1]){
                e = i;
                dp[s[i]-'a']=1;
            }
            i++;
        }
        
        return e - st;
    }
};

// class Solution {
// 	public:
// 	int dp[100001];
// 	int solve(int i, string &s) {
// 		if (dp[i] != -1){
// 			return dp[i];
// 		}
		
// 		int farthest = i;
		
// 		for (int j = i + 1; j < s.length(); j++) {
// 			if (s[j] == s[i] + 1){
// 				farthest = max(farthest, solve(j, s));
// 			}
// 		}
		
// 		return dp[i] = farthest;
// 	}
	
// 	int maxIndexDifference(string &s) {
// 	    memset(dp, -1, sizeof(dp));
// 		int n = s.length();
// 		int is_a = -1;
		
// 		for(int i = 0; i < n; i++){
// 		    if(s[i] == 'a'){
// 		        is_a = i;
// 		        break;
// 		    }
// 		}
		
// 		if(is_a == -1) return -1;
		
// 		int ans = solve(is_a, s);
		
// 		return ans - is_a;
// 	}
// };

// class Solution {
//   public:
//     int maxIndexDifference(string &s) {
//         // code here
//         vector<pair<int,int>>freq(26);

//         for(int i = 0; i < 26; i++){
//             freq[i] = {INT_MAX, INT_MIN};
//         }

//         int is_a = -1;

//         for(int i = 0; i < s.length(); i++){
//             if(s[i] == 'a'){
//                 is_a = i;
//                 break;
//             }
//         }

//         if(is_a == -1) return -1;

//         for(int i = is_a; i < s.length(); i++){
//             int idx = s[i] - 'a';
//             freq[idx].first = min(freq[idx].first, i);
//             freq[idx].second = max(freq[idx].second, i);
//         }

//         int ans = 0;
//         int max_idx = is_a;
//         for(int i = 0; i < 25; i++){
//             if(freq[i].first == INT_MAX || freq[i].second == INT_MIN || freq[i+1].first == INT_MAX || freq[i+1].second == INT_MIN || freq[i].second < max_idx){
//                 break;
//             }

//             int i1 = freq[i].first;
//             int j1 = freq[i].second;
//             int i2 = freq[i+1].first;
//             int j2 = freq[i+1].second;
//             max_idx = max(max_idx, j2);
//             // cout<<j2<<endl;

//             // if(i1 > i2){

//             // }

//             ans = max(ans, j2-is_a);
//         }

//         return ans;
//     }
// };
