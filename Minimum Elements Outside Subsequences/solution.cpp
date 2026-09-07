class Solution {
public:
    int dp[101][102][102];
	int solve(int idx, int inc, int dec, vector<int> &arr){
		if (idx == arr.size()){
			return 0;
		}
		
		if (dp[idx][inc + 1][dec + 1] != -1){
			return dp[idx][inc + 1][dec + 1];
		}
		
		int ans = INT_MAX;
		
		
		if (inc == -1 || arr[idx] > arr[inc]){
			ans = min(ans, solve(idx + 1, idx, dec, arr));
		}
		
		if (dec == -1 || arr[idx] < arr[dec]){
			ans = min(ans, solve(idx + 1, inc, idx, arr));
		}
		
		ans = min(ans, 1 + solve(idx + 1, inc, dec, arr));
		
		return dp[idx][inc + 1][dec + 1] = ans;
	}
	
	int minCount(vector<int> &arr){
	    memset(dp, -1, sizeof(dp));
		int n = arr.size();
		
		return solve(0, -1, -1, arr);
	}
	
};
