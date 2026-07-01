class Solution {
	public:
	int maxSumSubarray(vector<int>& arr) {
		// code here
		int n = arr.size();
		
		int noDel = arr[0];
		int oneDel = 0;
		
		int ans = arr[0];
		
		for (int i = 1; i < n; i++){
			oneDel = max(noDel, arr[i] + oneDel);
			
			noDel = max(arr[i], arr[i] + noDel);
			
			ans = max(ans, max(noDel, oneDel));
		}
		
		return ans;
	}
};
